#include "MainFrame.h"
#include <wx/filedlg.h>
#include <wx/msgdlg.h>

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    // ファイルメニュー
    EVT_MENU(wxID_NEW, MainFrame::OnNew)
    EVT_MENU(wxID_OPEN, MainFrame::OnOpen)
    EVT_MENU(wxID_SAVE, MainFrame::OnSave)
    EVT_MENU(wxID_EXIT, MainFrame::OnExit)
    // 編集メニュー
    EVT_MENU(wxID_UNDO, MainFrame::OnUndo)
    EVT_MENU(wxID_REDO, MainFrame::OnRedo)
    EVT_MENU(wxID_CUT, MainFrame::OnCut)
    EVT_MENU(wxID_COPY, MainFrame::OnCopy)
    EVT_MENU(wxID_PASTE, MainFrame::OnPaste)
    EVT_MENU(wxID_SELECTALL, MainFrame::OnSelectAll)
wxEND_EVENT_TABLE()

MainFrame::MainFrame() 
    : wxFrame(nullptr, wxID_ANY, "Simple Text Editor", 
              wxDefaultPosition, wxSize(800, 600))
{
    // メニューバーの作成
    wxMenuBar *menuBar = new wxMenuBar();
    wxMenu *fileMenu = new wxMenu();
    fileMenu->Append(wxID_NEW, "&New\tCtrl+N");
    fileMenu->Append(wxID_OPEN, "&Open\tCtrl+O");
    fileMenu->Append(wxID_SAVE, "&Save\tCtrl+S");
    fileMenu->AppendSeparator();
    fileMenu->Append(wxID_EXIT, "E&xit\tAlt+F4");
    menuBar->Append(fileMenu, "&File");

    // 編集メニューの作成
    wxMenu *editMenu = new wxMenu();
    editMenu->Append(wxID_UNDO, "&Undo\tCtrl+Z");
    editMenu->Append(wxID_REDO, "&Redo\tCtrl+Y");
    editMenu->AppendSeparator();
    editMenu->Append(wxID_CUT, "Cu&t\tCtrl+X");
    editMenu->Append(wxID_COPY, "&Copy\tCtrl+C");
    editMenu->Append(wxID_PASTE, "&Paste\tCtrl+V");
    editMenu->AppendSeparator();
    editMenu->Append(wxID_SELECTALL, "Select &All\tCtrl+A");
    
    menuBar->Append(editMenu, "&Edit");
    SetMenuBar(menuBar);

    // テキストコントロールの作成
    textCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString,
                             wxDefaultPosition, wxDefaultSize,
                             wxTE_MULTILINE | wxTE_RICH);

    CreateStatusBar();
    SetStatusText("Ready");
}

void MainFrame::OnNew(wxCommandEvent& event)
{
    if (CheckSave())
    {
        textCtrl->Clear();
        currentFilePath.Clear();
        UpdateTitle();
        SetStatusText("New file created");
    }
}

void MainFrame::OnOpen(wxCommandEvent& event)
{
    if (!CheckSave()) return;

    wxFileDialog openFileDialog(this, "Open Text File", "", "",
                              "Text files (*.txt)|*.txt|All files (*.*)|*.*",
                              wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_CANCEL) return;

    if (LoadFile(openFileDialog.GetPath()))
    {
        currentFilePath = openFileDialog.GetPath();
        UpdateTitle();
        SetStatusText("File loaded successfully");
    }
}

void MainFrame::OnSave(wxCommandEvent& event)
{
    if (currentFilePath.empty())
    {
        wxFileDialog saveFileDialog(this, "Save Text File", "", "",
                                  "Text files (*.txt)|*.txt|All files (*.*)|*.*",
                                  wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

        if (saveFileDialog.ShowModal() == wxID_CANCEL) return;
        currentFilePath = saveFileDialog.GetPath();
    }

    if (SaveFile(currentFilePath))
    {
        UpdateTitle();
        SetStatusText("File saved successfully");
    }
}

void MainFrame::OnExit(wxCommandEvent& event)
{
    if (CheckSave())
    {
        Close(true);
    }
}

bool MainFrame::SaveFile(const wxString& filepath)
{
    if (!textCtrl->SaveFile(filepath))
    {
        wxMessageBox("Could not save file!", "Error",
                    wxICON_ERROR | wxOK);
        return false;
    }
    return true;
}

bool MainFrame::LoadFile(const wxString& filepath)
{
    if (!textCtrl->LoadFile(filepath))
    {
        wxMessageBox("Could not load file!", "Error",
                    wxICON_ERROR | wxOK);
        return false;
    }
    return true;
}

void MainFrame::UpdateTitle()
{
    wxString title = "Simple Text Editor";
    if (!currentFilePath.empty())
    {
        title += " - " + currentFilePath;
    }
    SetTitle(title);
}

bool MainFrame::CheckSave()
{
    if (textCtrl->IsModified())
    {
        wxMessageDialog dialog(this,
            "Do you want to save changes?",
            "Save Changes",
            wxYES_NO | wxCANCEL | wxICON_QUESTION);

        int result = dialog.ShowModal();
        if (result == wxID_YES)
        {
            wxCommandEvent dummy;
            OnSave(dummy);
            return !textCtrl->IsModified();
        }
        return result == wxID_NO;
    }
    return true;
}

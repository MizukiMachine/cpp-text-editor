#pragma once
#include <wx/wx.h>
#include <wx/stc/stc.h>
#include <string>

class MainFrame : public wxFrame
{
public:
    MainFrame();

private:
    // UIコンポーネント
    wxTextCtrl* textCtrl;
    wxString currentFilePath;

    // メニューイベントハンドラ
    void OnNew(wxCommandEvent& event);
    void OnOpen(wxCommandEvent& event);
    void OnSave(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    
    // 編集機能のイベントハンドラ
    void OnUndo(wxCommandEvent& event);
    void OnRedo(wxCommandEvent& event);
    void OnCut(wxCommandEvent& event);
    void OnCopy(wxCommandEvent& event);
    void OnPaste(wxCommandEvent& event);
    void OnSelectAll(wxCommandEvent& event);
    
    // ファイル操作メソッド
    bool SaveFile(const wxString& filepath);
    bool LoadFile(const wxString& filepath);
    
    // 補助メソッド
    void UpdateTitle();
    bool CheckSave();
    
    // イベントテーブルの宣言
    wxDECLARE_EVENT_TABLE();
};

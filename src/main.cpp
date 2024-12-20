#include <wx/wx.h>

// メインフレームクラスの定義
class MainFrame : public wxFrame
{
public:
    MainFrame() : wxFrame(nullptr, wxID_ANY, "Simple Text Editor", 
                         wxDefaultPosition, wxSize(800, 600))
    {
        // メインメニューバーの作成
        wxMenuBar *menuBar = new wxMenuBar();
        wxMenu *fileMenu = new wxMenu();
        fileMenu->Append(wxID_NEW, "&New\tCtrl+N");
        fileMenu->Append(wxID_OPEN, "&Open\tCtrl+O");
        fileMenu->Append(wxID_SAVE, "&Save\tCtrl+S");
        fileMenu->AppendSeparator();
        fileMenu->Append(wxID_EXIT, "E&xit\tAlt+F4");
        menuBar->Append(fileMenu, "&File");
        SetMenuBar(menuBar);

        // テキストコントロールの作成
        wxTextCtrl *textCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString,
                                            wxDefaultPosition, wxDefaultSize,
                                            wxTE_MULTILINE | wxTE_RICH);

        // ステータスバーの作成
        CreateStatusBar();
        SetStatusText("Ready");
    }
};

// アプリケーションクラスの定義
class TextEditorApp : public wxApp
{
public:
    bool OnInit() override
    {
        MainFrame *frame = new MainFrame();
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(TextEditorApp);

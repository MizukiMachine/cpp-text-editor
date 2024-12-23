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
    
    // ファイル操作メソッド
    bool SaveFile(const wxString& filepath);
    bool LoadFile(const wxString& filepath);
    
    // 補助メソッド
    void UpdateTitle();
    bool CheckSave();
    
    // イベントテーブルの宣言
    wxDECLARE_EVENT_TABLE();
};

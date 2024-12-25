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
    
    // 検索・置換機能のイベントハンドラ
    void OnFind(wxCommandEvent& event);
    void OnReplace(wxCommandEvent& event);
    void OnFindNext(wxCommandEvent& event);
    
    // 検索関連の補助メソッド
    bool DoFind(const wxString& text, bool forward = true, bool matchCase = false);
    bool DoReplace(const wxString& findText, const wxString& replaceText, 
                  bool matchCase = false);
    
    // メンバ変数
    wxString lastFindText;    // 最後に検索した文字列
    long lastFindPosition;    // 最後に検索した位置
    
    // ファイル操作メソッド
    bool SaveFile(const wxString& filepath);
    bool LoadFile(const wxString& filepath);
    
    // 補助メソッド
    void UpdateTitle();
    bool CheckSave();
    
    // イベントテーブルの宣言
    wxDECLARE_EVENT_TABLE();
};

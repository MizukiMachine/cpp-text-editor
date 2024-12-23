#include <wx/wx.h>
#include "MainFrame.h"

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

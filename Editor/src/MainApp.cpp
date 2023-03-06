#include "MainApp.h"
#include "MainFrame.h"
#include "Engine.h"

wxIMPLEMENT_APP_CONSOLE(MainApp);

bool MainApp::OnInit()
{
    MainFrame* frame = new MainFrame("2DEngine", wxPoint(50, 50), wxSize(1024, 720));
    Core::Engine::GetInstance()->Initialize();
    frame->Show(true);
    return true;
}

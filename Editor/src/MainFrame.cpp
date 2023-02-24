#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(wxID_EXIT,  MainFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxMenu*     menuFile;
    wxMenu*     menuHelp;
    wxMenuBar*  menuBar;
    
    menuFile = new wxMenu;
    menuHelp = new wxMenu;
    menuBar = new wxMenuBar;
    
    menuFile->Append(ID_NewProject, "&Create New Project...");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    menuHelp->Append(wxID_ABOUT);

    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    
    SetMenuBar(menuBar);
    CreateStatusBar();
    SetStatusText("2d Engine");
}

void MainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("2DEngine, TODO",
                "Add a cool name for the engine", wxOK | wxICON_INFORMATION);
}

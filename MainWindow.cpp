#include "MainWindow.h"

#include <Application.h>
#include <Menu.h>
#include <MenuItem.h>
#include <View.h>

MainWindow::MainWindow(void):	
BWindow(
	BRect(100,100,500,400),
	"Main Window",
	B_TITLED_WINDOW, 
	B_ASYNCHRONOUS_CONTROLS
) {
	BRect r(Bounds());
	r.bottom = 20;
	
	fMenuBar = new BMenuBar(r,"menubar");	
	fFileMenu = new BMenu("File");
	fQuit = new BMenuItem("Quit", new BMessage('nemq'));
	
	fMenuBar->AddItem(fFileMenu);
	fFileMenu->AddItem(fQuit);
	AddChild(fMenuBar);
	
	label = new BStringView(BRect(), NULL, "Waiting...");
	label->ResizeToPreferred();
	label->MoveTo(8, 36);
	AddChild(label);
}


void
MainWindow::MessageReceived(BMessage *msg)
{
	switch (msg->what)
	{
		case 'nemq':
		{
			QuitRequested();
			BWindow::MessageReceived(msg);
		}
		
		default:
		{
			BWindow::MessageReceived(msg);
			break;
		}
	}
}


bool
MainWindow::QuitRequested(void)
{
	be_app->PostMessage(B_QUIT_REQUESTED);
	return true;
}

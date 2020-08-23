#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <Window.h>
#include <MenuBar.h>
#include <Menu.h>
#include <MenuItem.h>
#include <StringView.h>

class MainWindow : public BWindow
{
	public:
		MainWindow(void);

		void MessageReceived(BMessage *msg);
		bool QuitRequested(void);

	private:
		BMenuBar *fMenuBar;
		BMenu *fFileMenu;
		BMenuItem *fQuit;
		BStringView *label;
};

#endif

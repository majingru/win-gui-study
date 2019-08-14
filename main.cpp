#include <Windows.h>
#include "widgets/BaseWindow.h"
#include "widgets/MainWindow.h"
#include "widgets/Gui.h"

using namespace one_client::ui;

int main(int argc, char * argv[])
{
    MainWindow win;

    if (!win.Create(L"WinGui"))
    {
        return 0;
    }

    ShowWindow(win.GetHWnd(), SW_SHOW);

    Gui::GetInstance()->launch();

    return 0;
}
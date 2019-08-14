/**
  * the main window.
  * author : majingru@oneapm.com
  * date :  2019-08-14 09:03:54 
  * version:  1.0
  * copyright (C) 2008-2019 oneapm.com. all rights reserved.
  */
#pragma once
#include "BaseWindow.h"
namespace one_client {
    namespace ui {
        class MainWindow : public BaseWindow<MainWindow>
        {
        public:
            PCWSTR  ClassName() const { return L"OneClientClass"; }
            LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
            {
                switch (uMsg)
                {
                case WM_DESTROY:
                    PostQuitMessage(0);
                    return 0;

                case WM_PAINT:
                    {
                        PAINTSTRUCT ps;
                        HDC hdc = BeginPaint(m_hwnd, &ps);
                        FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
                        EndPaint(m_hwnd, &ps);
                    }
                    return 0;

                default:
                    return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
                }
                return TRUE;
            }
        };
   } // namespace ui
} // namespace one_shell


/**
  * base window object.
  * author : majingru@oneapm.com
  * date :  2019-08-14 08:43:54 
  * version:  1.0
  * copyright (C) 2008-2019 oneapm.com. all rights reserved.
  */
#pragma once
#include <Windows.h>

namespace one_client {
    namespace ui {
        
        template <class DERIVED_TYPE> 
        class BaseWindow
        {
        public:
            BaseWindow(): m_hwnd(nullptr){}

            virtual ~BaseWindow() = default;

            static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
            {
                DERIVED_TYPE *pThis = NULL;

                if (uMsg == WM_NCCREATE)
                {
                    CREATESTRUCT* pCreate = (CREATESTRUCT*)lParam;
                    pThis = (DERIVED_TYPE*)pCreate->lpCreateParams;
                    SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pThis);

                    pThis->m_hwnd = hwnd;
                }
                else
                {
                    pThis = (DERIVED_TYPE*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
                }
                if (pThis)
                {
                    return pThis->HandleMessage(uMsg, wParam, lParam);
                }
                else
                {
                    return DefWindowProc(hwnd, uMsg, wParam, lParam);
                }
            }

            BOOL Create(
                PCWSTR lpWindowName,
                HWND hWndParent = 0,
                HMENU hMenu = 0,
                DWORD dwStyle = WS_OVERLAPPEDWINDOW,
                DWORD dwExStyle = 0,
                int x = CW_USEDEFAULT,
                int y = CW_USEDEFAULT,
                int nWidth = CW_USEDEFAULT,
                int nHeight = CW_USEDEFAULT                
                )
            {
                WNDCLASS wc = {0};

                wc.lpfnWndProc   = DERIVED_TYPE::WindowProc;
                wc.hInstance     = GetModuleHandle(NULL);
                wc.lpszClassName = ClassName();

                RegisterClass(&wc);

                m_hwnd = CreateWindowEx(dwExStyle, ClassName(), lpWindowName, dwStyle, x, y,nWidth, nHeight, hWndParent, hMenu, GetModuleHandle(NULL), this);

                return (m_hwnd ? true : false);
            }

            HWND GetHWnd() const { return m_hwnd; }
        protected:

            virtual PCWSTR  ClassName() const = 0;
            virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;

            HWND m_hwnd;
        };
   } // namespace ui
} // namespace one_shell







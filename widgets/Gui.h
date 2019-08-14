/**
  * Launch Gui Application.
  * author : majingru@oneapm.com
  * date :  2019-08-14 11:37:50 
  * version:  1.0
  * copyright (C) 2008-2019 oneapm.com. all rights reserved.
  */
#pragma once
#include <Windows.h>
#include "MainWindow.h"

namespace one_client {
    namespace ui {
        class Gui {
        private:
            Gui() = default;
            ~Gui() = default;

        public:
            static Gui * GetInstance()
            {
                static Gui gui;
                return &gui;
            }

            void launch()
            {
                MSG msg = { };
                while (GetMessage(&msg, NULL, 0, 0))
                {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }
            }
        };
   } // namespace ui
} // namespace one_shell

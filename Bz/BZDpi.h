#pragma once
#include <windows.h>

class CBZDpi
{
public:

  static int m_x;
  static int m_y;
  static BOOL  m_init;

  static void Init(HWND hWnd)
  {
    if(m_init)return;
    HDC hdc = GetDC(hWnd);
    m_x = GetDeviceCaps(hdc, LOGPIXELSX);
    m_y = GetDeviceCaps(hdc, LOGPIXELSY);
    m_init = TRUE;
    ReleaseDC(hWnd, hdc);
  }

  static int ScaleX(int _x)
  {
      return MulDiv(_x, m_x, USER_DEFAULT_SCREEN_DPI);
  }

  static int ScaleY(int _y)
  {
      return MulDiv(_y, m_y, USER_DEFAULT_SCREEN_DPI);
  }

  static int ScaleX96Dpi(int _x)
  {
    return MulDiv(_x, USER_DEFAULT_SCREEN_DPI, m_x);
  }

  static int ScaleY96Dpi(int _y)
  {
    return MulDiv(_y, USER_DEFAULT_SCREEN_DPI, m_y);
  }
};

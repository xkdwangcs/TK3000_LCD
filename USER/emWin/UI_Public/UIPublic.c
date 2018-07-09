#include "UIPublic.h"
#include  "DIALOG.h"



//设置相对于父窗体居中
void SetFormCenterPrent(WM_HWIN prentForm,WM_HWIN thisForm)
{
    int fW = WM_GetWindowSizeX(prentForm);
    int kW = WM_GetWindowSizeX(thisForm);
    int fH = WM_GetWindowSizeY(prentForm);
    int kH = WM_GetWindowSizeY(thisForm);
    int fx0=WM_GetWindowOrgX(prentForm);
    int fy0=WM_GetWindowOrgY(prentForm);
    int x0=(fW-kW)/2+fx0;
    int y0=(fH-kH)/2+fy0;
    WM_MoveTo(thisForm, x0, y0);
}


//设置相对于LCD居中
void SetFormCenterScreen(WM_HWIN thisForm)
{
    int fW = 800;//WM_GetWindowSizeX(prentForm);
    int kW = WM_GetWindowSizeX(thisForm);
    int fH = 480;//WM_GetWindowSizeY(prentForm);
    int kH = WM_GetWindowSizeY(thisForm);
    int x0=(fW-kW)/2;
    int y0=(fH-kH)/2;
    WM_MoveTo(thisForm, x0, y0);
}


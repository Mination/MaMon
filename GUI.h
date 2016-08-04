#ifndef __GUI_H__
#define __GUI_H__

#ifdef __cplusplus
    extern "C" {
#endif
#include "cvidef.h"

int GUIPanelHlidac,HelpPanelHlidac;

int trayIconHandle;
int GUIPanelHandle;
int HelpPanelHandle;
int CVICALLBACK TaskbarIconCB (int iconHandle, int event, int eventData);
int trayIconFunkce();
int GodEnder();
int  CVICALLBACK CmdIcon(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK HelpPanelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK PanelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
#ifdef __cplusplus
    }
#endif

#endif  

/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/* Copyright (c) National Instruments 2016. All Rights Reserved.          */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  GUIPanel                         1       /* callback function: PanelCB */
#define  GUIPanel_TABLE                   2       /* control type: table, callback function: (none) */
#define  GUIPanel_LED                     3       /* control type: LED, callback function: (none) */
#define  GUIPanel_DECORATION              4       /* control type: deco, callback function: (none) */
#define  GUIPanel_RING                    5       /* control type: ring, callback function: (none) */
#define  GUIPanel_Quit                    6       /* control type: command, callback function: QuitCB */
#define  GUIPanel_HideBtnCB               7       /* control type: command, callback function: HideBtnCB */
#define  GUIPanel_MERENITIME              8       /* control type: string, callback function: (none) */
#define  GUIPanel_MERENIBUTTON            9       /* control type: command, callback function: mereniButtonCB */
#define  GUIPanel_STRIPCHART              10      /* control type: strip, callback function: (none) */

#define  HelpPanel                        2       /* callback function: HelpPanelCB */
#define  HelpPanel_TEXTBOX                2       /* control type: textMsg, callback function: (none) */

#define  InfPanel                         3
#define  InfPanel_PICTURE                 2       /* control type: picture, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK HelpPanelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK HideBtnCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK mereniButtonCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK PanelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK QuitCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif

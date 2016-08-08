/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
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
#define  GUIPanel_CMD_RED                 2       /* control type: command, callback function: CmdIcon */
#define  GUIPanel_CMD_GREY                3       /* control type: command, callback function: CmdIcon */
#define  GUIPanel_CMD_GREEN               4       /* control type: command, callback function: CmdIcon */
#define  GUIPanel_TABLE                   5       /* control type: table, callback function: TableCB */
#define  GUIPanel_LED                     6       /* control type: LED, callback function: (none) */
#define  GUIPanel_DECORATION              7       /* control type: deco, callback function: (none) */
#define  GUIPanel_RING                    8       /* control type: ring, callback function: (none) */
#define  GUIPanel_TEXTMSG_2               9       /* control type: textMsg, callback function: (none) */
#define  GUIPanel_TEXTMSG                 10      /* control type: textMsg, callback function: (none) */

#define  HelpPanel                        2       /* callback function: HelpPanelCB */
#define  HelpPanel_TEXTBOX                2       /* control type: textMsg, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK CmdIcon(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK HelpPanelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK PanelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TableCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif

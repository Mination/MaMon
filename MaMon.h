
#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif


#define  GUIPanel                         1       /* callback function: PanelCB */
#define  GUIPanel_CMD_RED                 2       /* control type: command, callback function: CmdIcon */
#define  GUIPanel_CMD_GREY                3       /* control type: command, callback function: CmdIcon */
#define  GUIPanel_CMD_GREEN               4       /* control type: command, callback function: CmdIcon */
#define  GUIPanel_TABLE                   5       /* control type: table, callback function: (none) */
#define  GUIPanel_TEXTMSG                 6       /* control type: textMsg, callback function: (none) */
#define  GUIPanel_LED                     7       /* control type: LED, callback function: (none) */
#define  GUIPanel_RING                    8       /* control type: ring, callback function: (none) */
#define  GUIPanel_DECORATION              9       /* control type: deco, callback function: (none) */
#define  GUIPanel_TEXTMSG_2               10      /* control type: textMsg, callback function: (none) */

#define  HelpPanel                        2       /* callback function: HelpPanelCB */
#define  HelpPanel_TEXTBOX                2       /* control type: textMsg, callback function: (none) */


int GUIPanelHandle;
int HelpPanelHandle;
int trayIconHandle;


#ifdef __cplusplus
    }
#endif

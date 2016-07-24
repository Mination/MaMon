#include <userint.h>

/*---------------------------------------------------------------------------*/
/*                                                                           */
/* FILE:    MaMon.c                                                       */
/*                                                                           */
/* PURPOSE: This example illustrates how to use the WinTools instrument      */
/*          driver to install icons in the status area of the Windows shell  */
/*          taskbar, called the System Tray.  Your app can respond to events */
/*          on the icon via a simple callback mechanism.                     */
/*                                                                           */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Include files                                                             */
/*---------------------------------------------------------------------------*/
#include <ansi_c.h>
#include <cvirte.h>     
#include "MaMon.h"
#include "toolbox.h"

/*---------------------------------------------------------------------------*/
/* Module-globals                                                            */
/*---------------------------------------------------------------------------*/
static int GUIPanelHandle;
static int HelpPanelHandle;
static int trayIconHandle;
/*---------------------------------------------------------------------------*/
/* Internal function prototypes                                              */
/*---------------------------------------------------------------------------*/
int CVICALLBACK TaskbarIconCB (int iconHandle, int event, int eventData);

/*---------------------------------------------------------------------------*/
/* This is the application's entry-point.                                    */
/*---------------------------------------------------------------------------*/
//int __stdcall WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
//                       LPSTR lpszCmdLine, int nCmdShow)
int GUIPanelHlidac = 1;
int HelpPanelHlidac = 1;

int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                       LPSTR lpszCmdLine, int nCmdShow)
{
    
    int menuItemIndex;
        
    if (InitCVIRTE (hInstance, 0, 0) == 0)  
        return -1; 
    if ((GUIPanelHandle = LoadPanel (0, "MaMon.uir", GUIPanel)) < 0)
        {
        CloseCVIRTE ();
        return -1; 
        }
	
	HelpPanelHandle=LoadPanel (0, "MaMon.uir", HelpPanel);	
    
	SetPanelAttribute (GUIPanelHandle, ATTR_HAS_TASKBAR_BUTTON, 0);
    SetSystemAttribute (ATTR_TASKBAR_BUTTON_VISIBLE, 0);

    /* Add an icon to the taskbar System Tray */
    InstallSysTrayIcon ("StatusIcons/init.ico", "Inicializuji...",
                        TaskbarIconCB, &trayIconHandle);
    
    /* Create a right-click menu for the icon and add some items to it */
    AttachTrayIconMenu (trayIconHandle);
    InsertTrayIconMenuItem (trayIconHandle, "Quit", &menuItemIndex);  //1
	
	InsertTrayIconMenuItem (trayIconHandle, 0, &menuItemIndex);  //2
	
	InsertTrayIconMenuItem (trayIconHandle, "Help", &menuItemIndex); //3
    
	InsertTrayIconMenuItem (trayIconHandle,"Open GUI", &menuItemIndex); //4
    
    
    /* Set some attributes of the menu */
    SetTrayIconMenuAttr (trayIconHandle,ATTR_POPUP_DEFAULT_ITEM, 1);
	
    
	//SetTrayIconMenuItemAttr (trayIconHandle, 2, ATTR_DIMMED, 1);
    //SetTrayIconMenuItemAttr (trayIconHandle, 4, ATTR_CHECKED, 1); 

    /* Display the panel and run the GUI -- the app must process events in   */
    /* order to receive messages from the tray icon.                         */
    
    RunUserInterface();

    /* Discard the tray icon's menu and then the icon itself */
    DetachTrayIconMenu (trayIconHandle);
    RemoveSysTrayIcon (trayIconHandle);

    /* Clean up and return */
    
	//DiscardPanel(GUIPanelHandle);
	//DiscardPanel(HelpPanelHandle);
    CloseCVIRTE ();
    return 0;
}


/*---------------------------------------------------------------------------*/
/* This function responds to events from the system tray icon.  We will      */
/* simply look at the incoming event and display it in the TextBox on our    */
/* panel.                                                                    */ 
/*---------------------------------------------------------------------------*/
int CVICALLBACK TaskbarIconCB (int iconHandle, int event, int eventData)
{
    char eventName [70];
    
    switch (event)
        {
        case EVENT_LEFT_CLICK:
            strcpy (eventName, "Left button down\n");
            break;
        case EVENT_LEFT_MOUSE_UP:
            strcpy (eventName, "Left button up\n");
            break;
        case EVENT_RIGHT_CLICK:
            strcpy (eventName, "Right button down\n");
			break;
        case EVENT_RIGHT_MOUSE_UP:
            strcpy (eventName, "Right button up\n");
            break;
        case EVENT_LEFT_DOUBLE_CLICK:
            strcpy (eventName, "Left double-click\n");
            break;
        case EVENT_RIGHT_DOUBLE_CLICK:        
            strcpy (eventName, "Right double-click\n");
            break;
        case EVENT_MENU_ITEM:
            /*===============================================================================================================================================================*/
            /* With menu events, eventData contains the selected item's ID */
            if (eventData == 1){
				QuitUserInterface(0);	
				
			}
			if (eventData == 4){
				
				if (GUIPanelHlidac == 1){
					GUIPanelHandle = LoadPanel (0,"MaMon.uir", GUIPanel);
					DisplayPanel(GUIPanelHandle);
					GUIPanelHlidac = 2;
					
				}
			}	
					
			if (eventData == 3){
				if (HelpPanelHlidac == 1){
					HelpPanelHandle = LoadPanel (0, "MaMon.uir",HelpPanel);
					DisplayPanel(HelpPanelHandle);
					HelpPanelHlidac = 2;
					
					
				}
				
				
			}
			
			break;
        /*==========================================================================================================================================================*/
		
		default:
            eventName[0] = 0;
        }
    	
    /* Honor our popup menu -- return non-zero to prevent it from appearing */
    return 0;
}

int CVICALLBACK PanelCB (int panel, int event, void *callbackData,
                         int eventData1, int eventData2)
{
    
	if (event == EVENT_CLOSE){
		DiscardPanel(GUIPanelHandle);
		GUIPanelHlidac = 1;
		
	}
        
	
    return 0;
}

    

int CVICALLBACK QuitCallback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			QuitUserInterface (0);
			break;
		}
	return 0;
}

int CVICALLBACK CmdIcon (int panel, int control, int event,
						 void *callbackData, int eventData1, int eventData2)
{
	int menuItemIndex;
	switch (event)
	{
		case EVENT_COMMIT:

				if(trayIconHandle != 0){
				 	DetachTrayIconMenu (trayIconHandle);
	    			RemoveSysTrayIcon (trayIconHandle);	
					trayIconHandle = 0;
				}
			
			
				if(trayIconHandle == 0){
					if(control == GUIPanel_CMD_GREY){ 
						InstallSysTrayIcon ("StatusIcons/klid.ico", "Chill", TaskbarIconCB, &trayIconHandle);
						AttachTrayIconMenu (trayIconHandle);
    					InsertTrayIconMenuItem (trayIconHandle, "Quit", &menuItemIndex);  //1
						InsertTrayIconMenuItem (trayIconHandle, 0, &menuItemIndex);  //2
						InsertTrayIconMenuItem (trayIconHandle, "Help", &menuItemIndex); //3
    					InsertTrayIconMenuItem (trayIconHandle,"Open GUI", &menuItemIndex); //4
					}
					
					if(control == GUIPanel_CMD_RED){
						InstallSysTrayIcon ("StatusIcons/spatny.ico", "Bacha kámo", TaskbarIconCB, &trayIconHandle);
						AttachTrayIconMenu (trayIconHandle);
    					InsertTrayIconMenuItem (trayIconHandle, "Quit", &menuItemIndex);  //1
						InsertTrayIconMenuItem (trayIconHandle, 0, &menuItemIndex);  //2
						InsertTrayIconMenuItem (trayIconHandle, "Help", &menuItemIndex); //3
    					InsertTrayIconMenuItem (trayIconHandle,"Open GUI", &menuItemIndex); //4
					}
					
					if(control == GUIPanel_CMD_GREEN){
						InstallSysTrayIcon ("StatusIcons/dobry.ico", "Dobrý to je kámo", TaskbarIconCB, &trayIconHandle);
						AttachTrayIconMenu (trayIconHandle);
    					InsertTrayIconMenuItem (trayIconHandle, "Quit", &menuItemIndex);  //1
						InsertTrayIconMenuItem (trayIconHandle, 0, &menuItemIndex);  //2
						InsertTrayIconMenuItem (trayIconHandle, "Help", &menuItemIndex); //3
    					InsertTrayIconMenuItem (trayIconHandle,"Open GUI", &menuItemIndex); //4
				
					}
					}
			break;
	}
	return 0;
}

int CVICALLBACK HelpPanelCB (int panel, int event, void *callbackData,
							 int eventData1, int eventData2)
{
	{
    if (event == EVENT_CLOSE){
        DiscardPanel(HelpPanelHandle);
		HelpPanelHlidac = 1;
	}
    return 0;
	}
}

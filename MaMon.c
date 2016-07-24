#include <userint.h>
#include <ansi_c.h>
#include <cvirte.h>     
#include "MaMon.h"
#include "toolbox.h"

static int GUIPanelHandle;
static int HelpPanelHandle;
static int trayIconHandle;

int CVICALLBACK TaskbarIconCB (int iconHandle, int event, int eventData);
int GUIPanelHlidac = 1;
int HelpPanelHlidac = 1;


int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                       LPSTR lpszCmdLine, int nCmdShow)
{
    
    int menuItemIndex;

	GUIPanelHandle = LoadPanel (0, "MaMon.uir", GUIPanel);
	HelpPanelHandle=LoadPanel (0, "MaMon.uir", HelpPanel);	
    

    InstallSysTrayIcon ("StatusIcons/init.ico", "Inicializuji...",
                        TaskbarIconCB, &trayIconHandle);
    
    AttachTrayIconMenu (trayIconHandle);
    InsertTrayIconMenuItem (trayIconHandle, "Quit", &menuItemIndex);  //1
	
	InsertTrayIconMenuItem (trayIconHandle, 0, &menuItemIndex);  //2
	
	InsertTrayIconMenuItem (trayIconHandle, "Help", &menuItemIndex); //3
    
	InsertTrayIconMenuItem (trayIconHandle,"Open GUI", &menuItemIndex); //4
    
    RunUserInterface();

    DetachTrayIconMenu (trayIconHandle);
    RemoveSysTrayIcon (trayIconHandle);


    return 0;
}


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
     
		
		default:
            eventName[0] = 0;
        }
    	

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

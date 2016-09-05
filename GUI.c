#include <windows.h> 
#include <userint.h>
#include "toolbox.h"
#include "GUI.h"
#include "MaMon.h"
#include "iniReader.h"
#include "SQL.h"
#include "GUITable.h"
#include "OPC.h"
		  
int menuItemIndex;
int iniWatcher = 0;
/* TRAY MENU CALLBACK  */
int CVICALLBACK TaskbarIconCB (int iconHandle, int event, int eventData)
{
    
	char eventName [70];
    switch (event)
        {
        case EVENT_MENU_ITEM:
        	if (eventData == 1){
				Exit();
				
			}
			if (eventData == 4){
				
				if (GUIPanelHlidac == 0){
					IconChanger("Assets/Icon/GUIPanelIcon.ico",GUIPanelHandle);
					DisplayPanel(GUIPanelHandle);
					GUIPanelHlidac = 1;
				}
			}	
			if (eventData == 3){
				if (HelpPanelHlidac == 0){
					HelpPanelHandle = LoadPanel (0,"MaMon.uir", HelpPanel);
					IconChanger("Assets/Icon/HelpIcon v1.ico",HelpPanelHandle);
					DisplayPanel(HelpPanelHandle);
					HelpPanelHlidac = 1;
				}
			}
			
			break;
		case EVENT_LEFT_DOUBLE_CLICK:
			if (iniWatcher == 1){
				IconChanger("Assets/Icon/GUIPanelIcon.ico",GUIPanelHandle);
				DisplayPanel(GUIPanelHandle);
				GUIPanelHlidac = 1;
				break;	
				
			}else{
				break;	
				
			}
			
     	
		default:
            eventName[0] = 0;
        }
		
		return 0;
}

/* VYPINAC GUI */
int CVICALLBACK PanelCB (int panel, int event, void *callbackData,
                         int eventData1, int eventData2)
{
    
	if (event == EVENT_CLOSE){
		HidePanel(GUIPanelHandle);
		GUIPanelHlidac = 0;
		
	}
    
	return 0;
}


/* VYPINAC HELP PANELU */
int CVICALLBACK HelpPanelCB (int panel, int event, void *callbackData,
							 int eventData1, int eventData2)
{   
	if (event == EVENT_CLOSE){
        DiscardPanel(HelpPanelHandle);
		HelpPanelHlidac = 0;
	}
    
	return 0;
}


/* VYPINAC */
int Exit(){
	
	exit(0);
	
	return 0;
}

/* Cervena trayikona */
int TrayIconRed(){
	SetCtrlAttribute (GUIPanelHandle, GUIPanel_LED, ATTR_ON_COLOR, VAL_DK_RED);
	SetCtrlAttribute (GUIPanelHandle, GUIPanel_LED, ATTR_OFF_COLOR, VAL_DK_RED);
	RemoveSysTrayIcon (trayIconHandle);
	DetachTrayIconMenu (trayIconHandle);
	InstallSysTrayIcon ("Assets/StatusIcons/spatny.ico", "CHYBA!", TaskbarIconCB, &trayIconHandle); 
	//int menuItemIndex;	
	AttachTrayIconMenu (trayIconHandle);
    InsertTrayIconMenuItem (trayIconHandle, "Quit", &menuItemIndex);  //1
	InsertTrayIconMenuItem (trayIconHandle, 0, &menuItemIndex);  //2
	InsertTrayIconMenuItem (trayIconHandle, "Help", &menuItemIndex); //3
    InsertTrayIconMenuItem (trayIconHandle,"Open GUI", &menuItemIndex); //4
	
	return 0;
}	
/* Modra trayikona */
int TrayIconBlue(){
	SetCtrlAttribute (GUIPanelHandle, GUIPanel_LED, ATTR_ON_COLOR, VAL_DK_BLUE);
	SetCtrlAttribute (GUIPanelHandle, GUIPanel_LED, ATTR_OFF_COLOR, VAL_DK_BLUE);
	InstallSysTrayIcon ("Assets/StatusIcons/init.ico", "Inicializuji...",TaskbarIconCB, &trayIconHandle); 
	//int menuItemIndex;	
	AttachTrayIconMenu (trayIconHandle);
    InsertTrayIconMenuItem (trayIconHandle, "Quit", &menuItemIndex);  //1
	InsertTrayIconMenuItem (trayIconHandle, 0, &menuItemIndex);  //2
	InsertTrayIconMenuItem (trayIconHandle, "Help", &menuItemIndex); //3
    InsertTrayIconMenuItem (trayIconHandle,"Open GUI", &menuItemIndex); //4
	 
	return 0;
}

/* Modra trayikona pred nactenim */
int TryIconBluePreIni(){
	SetCtrlAttribute (GUIPanelHandle, GUIPanel_LED, ATTR_ON_COLOR, VAL_DK_BLUE);
	SetCtrlAttribute (GUIPanelHandle, GUIPanel_LED, ATTR_OFF_COLOR, VAL_DK_BLUE);
	InstallSysTrayIcon ("Assets/StatusIcons/init.ico", "Inicializuji...",TaskbarIconCB, &trayIconHandle);	
	DelayWithEventProcessing(2);
	AttachTrayIconMenu (trayIconHandle);
    InsertTrayIconMenuItem (trayIconHandle, "Quit", &menuItemIndex);  //1
	InsertTrayIconMenuItem (trayIconHandle, 0, &menuItemIndex);  //2
	InsertTrayIconMenuItem (trayIconHandle, "Help", &menuItemIndex); //3
    InsertTrayIconMenuItem (trayIconHandle,"Open GUI", &menuItemIndex); //4
	
	iniWatcher = 1;
	return 0;
}
/* Seda trayikona */
int TrayIconGray(){
	SetCtrlAttribute (GUIPanelHandle, GUIPanel_LED, ATTR_ON_COLOR, VAL_DK_GRAY);
	SetCtrlAttribute (GUIPanelHandle, GUIPanel_LED, ATTR_OFF_COLOR, VAL_DK_GRAY);
	
	RemoveSysTrayIcon (trayIconHandle);
	DetachTrayIconMenu (trayIconHandle);
	InstallSysTrayIcon ("Assets/StatusIcons/klid.ico", "Neni cas na mereni dat", TaskbarIconCB, &trayIconHandle);
	AttachTrayIconMenu (trayIconHandle);
    InsertTrayIconMenuItem (trayIconHandle, "Quit", &menuItemIndex);  //1
	InsertTrayIconMenuItem (trayIconHandle, 0, &menuItemIndex);  //2
	InsertTrayIconMenuItem (trayIconHandle, "Help", &menuItemIndex); //3
    InsertTrayIconMenuItem (trayIconHandle,"Open GUI", &menuItemIndex); //4
	
	return 0;
}
/* Zelena trayikona */
int TrayIconGreen(){
	SetCtrlAttribute (GUIPanelHandle, GUIPanel_LED, ATTR_ON_COLOR, VAL_DK_GREEN);
	SetCtrlAttribute (GUIPanelHandle, GUIPanel_LED, ATTR_OFF_COLOR, VAL_DK_GREEN);
	RemoveSysTrayIcon (trayIconHandle);
	DetachTrayIconMenu (trayIconHandle);
	InstallSysTrayIcon ("Assets/StatusIcons/dobry.ico", "Probiha nacitani dat a mereni", TaskbarIconCB, &trayIconHandle);
	//int menuItemIndex;	
	AttachTrayIconMenu (trayIconHandle);
    InsertTrayIconMenuItem (trayIconHandle, "Quit", &menuItemIndex);  //1
	InsertTrayIconMenuItem (trayIconHandle, 0, &menuItemIndex);  //2
	InsertTrayIconMenuItem (trayIconHandle, "Help", &menuItemIndex); //3
    InsertTrayIconMenuItem (trayIconHandle,"Open GUI", &menuItemIndex); //4
	
	return 0;
}



/* Vypne MaMon */
int CVICALLBACK QuitCB (int panel, int control, int event,
						void *callbackData, int eventData1, int eventData2)
{   
	switch (event)
	{
		case EVENT_COMMIT:
			Exit();
			break;
	}
	
	return 0;
}

/* Schova GUIPanel */
int CVICALLBACK HideBtnCB (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
	
	switch (event)
	{
		case EVENT_COMMIT:
			HidePanel(GUIPanelHandle);
			break;
	}
	
	return 0;
}

/*  Meni ikonu panelu  */
void IconChanger(char* icon_path,int panel_handle)
{
	
	int window;
	HANDLE handle_icon;
	handle_icon = LoadImage(0, icon_path, IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
	GetPanelAttribute (panel_handle, ATTR_SYSTEM_WINDOW_HANDLE, &window);
	SendMessage((HWND)window, WM_SETICON, ICON_SMALL, (LPARAM)handle_icon);
	
	
}

/* Callback pro merici button */
int CVICALLBACK mereniButtonCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			measureFun();
			SetCtrlAttribute (GUIPanelHandle, GUIPanel_MERENIBUTTON, ATTR_DIMMED, 1);
			 
			
			break;
	}
	return 0;
}



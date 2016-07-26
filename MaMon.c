#include "inifile.h"
#include <userint.h>
#include <ansi_c.h>
#include <cvirte.h>     
#include "MaMon.h"
#include "toolbox.h"
#include <string.h>
#include <stdio.h>

static int GUIPanelHandle;
static int HelpPanelHandle;
static int trayIconHandle;



/* GLOBÁLNÍ PROMÌNNÉ  */

int GUIPanelHlidac,HelpPanelHlidac;
char *DSN, *typ,*adresa,*casStart;
int *intervalSec,*PT,*alarmLimitProc,*pocetVzorku,*OK,*NOK;
//int tab1,tab2,tabCtrl,tabPanel1;
//int tabCtrl, tab1, tab2, tabPanel1, tabPanel2, testButton,panelHeight = 0, panelWidth = 0;

/*  PROTOTYPY FUNKCÍ  */

int CVICALLBACK TaskbarIconCB (int iconHandle, int event, int eventData);
int trayIconFunkce();
int iniFileReader();


/*               MAIN FUNKCE             */

int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                       LPSTR lpszCmdLine, int nCmdShow)
{
    	
	iniFileReader();
	
	DetachTrayIconMenu (trayIconHandle);
	RemoveSysTrayIcon (trayIconHandle);	
	
	InstallSysTrayIcon ("StatusIcons/klid.ico", "Chill", TaskbarIconCB, &trayIconHandle);
	trayIconFunkce();
    
	
	RunUserInterface();
	
	
    
	
	return 0;
}

/*         SysTray Menu Otevíraè      */


int CVICALLBACK TaskbarIconCB (int iconHandle, int event, int eventData)
{
    char eventName [70];
    
    switch (event)
        {
        case EVENT_MENU_ITEM:
        	if (eventData == 1){
				QuitUserInterface(0);	
				
			}
			if (eventData == 4){
				
				if (GUIPanelHlidac == 0){
					GUIPanelHandle = LoadPanel (0,"MaMon.uir", GUIPanel);
					/*
					tabCtrl = NewCtrl (GUIPanelHandle, CTRL_TABS, "Test Control", 100, 100);
					tab1 = InsertTabPage (GUIPanelHandle, tabCtrl, 0, "Test Tab One");
					tab2 = InsertTabPage (GUIPanelHandle, tabCtrl, 1, "Test Tab Two");
					GetPanelHandleFromTabPage (GUIPanelHandle, tabCtrl, 0, &tabPanel1);
					GetPanelAttribute (tabPanel1, ATTR_HEIGHT, &panelHeight);
					GetPanelAttribute (tabPanel1, ATTR_WIDTH, &panelWidth);
					testButton = NewCtrl (tabPanel1, CTRL_GRAPH, "Test Button", panelHeight - 50, panelWidth - 100);
					GetPanelHandleFromTabPage (GUIPanelHandle, tabCtrl, 1, &tabPanel2);
					
					
					tabCtrl = NewCtrl(GUIPanelHandle, CTRL_TABS, "", 0, 0);
					tab1 = InsertTabPage (GUIPanelHandle, tabCtrl, 0, "dude");
					tab2 = InsertTabPage (GUIPanelHandle, tabCtrl, 0, "weed");
					GetPanelHandleFromTabPage (GUIPanelHandle, tabCtrl, 0, &tabPanel1);
					SetActiveTabPage (GUIPanelHandle, tabCtrl, 1);
					*/
					
					DisplayPanel(GUIPanelHandle);
					GUIPanelHlidac = 1;
					
				}
			}	
					
			if (eventData == 3){
				if (HelpPanelHlidac == 0){
					HelpPanelHandle = LoadPanel (0, "MaMon.uir",HelpPanel);
					DisplayPanel(HelpPanelHandle);
					HelpPanelHlidac = 1;
					
					
					
					
				}
				
				
			}
			
			break;
     
		
		default:
            eventName[0] = 0;
        }
    	

    return 0;
}


/*          GUI VYPÍNAÈ      */

int CVICALLBACK PanelCB (int panel, int event, void *callbackData,
                         int eventData1, int eventData2)
{
    
	if (event == EVENT_CLOSE){
		DiscardPanel(GUIPanelHandle);
		GUIPanelHlidac = 0;
		
	}
        
	
    return 0;
}

/*            VYPÍNAÈ      */    

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


/*          STATUS IKONY        */ 

int CVICALLBACK CmdIcon (int panel, int control, int event,
						 void *callbackData, int eventData1, int eventData2)
{
	
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
						trayIconFunkce();
					}
					
					if(control == GUIPanel_CMD_RED){
						InstallSysTrayIcon ("StatusIcons/spatny.ico", "Bacha kámo", TaskbarIconCB, &trayIconHandle);
						trayIconFunkce();
					}
					
					if(control == GUIPanel_CMD_GREEN){
						InstallSysTrayIcon ("StatusIcons/dobry.ico", "Dobrý to je kámo", TaskbarIconCB, &trayIconHandle);
						trayIconFunkce();
				
					}
					}
			break;
	}
	return 0;
}



/*           HELP PANEL VYPÍNAÈ       */

int CVICALLBACK HelpPanelCB (int panel, int event, void *callbackData,
							 int eventData1, int eventData2)
{
	{
    if (event == EVENT_CLOSE){
        DiscardPanel(HelpPanelHandle);
		HelpPanelHlidac = 0;
	}
    return 0;
	}
}


/*            VYTVÁØEÈ SYSTRAY MENU          */

int trayIconFunkce(){
	int menuItemIndex;	
	AttachTrayIconMenu (trayIconHandle);
    InsertTrayIconMenuItem (trayIconHandle, "Quit", &menuItemIndex);  //1
	InsertTrayIconMenuItem (trayIconHandle, 0, &menuItemIndex);  //2
	InsertTrayIconMenuItem (trayIconHandle, "Help", &menuItemIndex); //3
    InsertTrayIconMenuItem (trayIconHandle,"Open GUI", &menuItemIndex); //4
	return 0;
	
	
	
	
}

/*       INI FILE OTEVÍRAÈ   */

int iniFileReader(){
	InstallSysTrayIcon ("StatusIcons/init.ico", "Inicializuji...",TaskbarIconCB, &trayIconHandle);
	trayIconFunkce();
	IniText iniLoadUp = Ini_New(0);
	
	Ini_ReadFromFile (iniLoadUp,"MaMon.ini");
	
	/* STRINGY  */
	
	Ini_GetStringCopy (iniLoadUp, "SQL", "DSN", &DSN);
	Ini_GetStringCopy (iniLoadUp, "ZpetnaVazba", "Typ", &typ);
	Ini_GetStringCopy (iniLoadUp, "ZpetnaVazba", "Adresa", &adresa);
	Ini_GetStringCopy(iniLoadUp,"SberDat","CasStart",&casStart);
	
	/*    INTY   */
	
	Ini_GetInt(iniLoadUp,"Stroj","PT",&PT);
	Ini_GetInt(iniLoadUp,"Stroj","AlarmLimitProc",&alarmLimitProc);
	Ini_GetInt(iniLoadUp,"SberDat","IntervalSec",&intervalSec);
	Ini_GetInt(iniLoadUp,"SberDat","PocetVzorku",&pocetVzorku);
	
	/*    BOOLEANY   */
	
	Ini_GetInt (iniLoadUp, "ZpetnaVazba", "StavOK", &OK);
	Ini_GetInt (iniLoadUp, "ZpetnaVazba", "StavNOK", &NOK);
	
	
	
	
	
	
	
	return 0;
	
	
	
	
}


















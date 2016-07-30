#include <formatio.h>
#include "inifile.h"
#include <userint.h>
#include <ansi_c.h>
#include <cvirte.h>     
#include "MaMon.h"
#include "toolbox.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

const char COLON = ':';

static int GUIPanelHandle;
static int HelpPanelHandle;
static int trayIconHandle;



/* GLOBÁLNÍ PROMÌNNÉ  */

int GUIPanelHlidac,HelpPanelHlidac;
char *DSN, *typ,*adresa,*casStart;
int PT,alarmLimitProc,pocetVzorku,OK,NOK,hodinaStart,minutaStart;
double intervalSecDouble;

/*  PROTOTYPY FUNKCÍ  */

int CVICALLBACK TaskbarIconCB (int iconHandle, int event, int eventData);
int trayIconFunkce();
int iniFileReader();
int Cekac();
int SystemCas();
int GodEnder();

/*               MAIN FUNKCE             */

int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpszCmdLine, int nCmdShow){
	
	/*   DÙLEŽITÉ  */
	SetSystemAttribute (ATTR_TASKBAR_BUTTON_VISIBLE, 0);
	/*  NEMAZAT	   */
	
	iniFileReader();
	SystemCas();
	Cekac();
	InstallSysTrayIcon ("StatusIcons/dobry.ico", "Probíhá ètení dat", TaskbarIconCB, &trayIconHandle);
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
				GodEnder();
				
			}
			if (eventData == 4){
				
				if (GUIPanelHlidac == 0){
					GUIPanelHandle = LoadPanel (0,"MaMon.uir", GUIPanel);
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
						InstallSysTrayIcon ("StatusIcons/klid.ico", "Nic se nedìje", TaskbarIconCB, &trayIconHandle);
						trayIconFunkce();
					}
					
					if(control == GUIPanel_CMD_RED){
						InstallSysTrayIcon ("StatusIcons/spatny.ico", "CHYBA", TaskbarIconCB, &trayIconHandle);
						trayIconFunkce();
					}
					
					if(control == GUIPanel_CMD_GREEN){
						InstallSysTrayIcon ("StatusIcons/dobry.ico", "Vše bìži v poøádku", TaskbarIconCB, &trayIconHandle);
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
	Ini_GetStringCopy (iniLoadUp, "SberDat", "CasStart", &casStart);
	
	/*    INTY   */
	
	Ini_GetInt(iniLoadUp,"Stroj","PT",&PT);
	Ini_GetInt(iniLoadUp,"Stroj","AlarmLimitProc",&alarmLimitProc);
	Ini_GetDouble(iniLoadUp,"SberDat","IntervalSec",&intervalSecDouble);
	Ini_GetInt(iniLoadUp,"SberDat","PocetVzorku",&pocetVzorku);
	
	/*    BOOLEANY   */
	
	Ini_GetInt (iniLoadUp, "ZpetnaVazba", "StavOK", &OK);
	Ini_GetInt (iniLoadUp, "ZpetnaVazba", "StavNOK", &NOK);
	
	
	/*============ ÈISTÁ MAGIE, NESAHAT =============================*/
	int rozdelovac = 0;
	char *p = casStart;
	while (*p){
    	if (isdigit(*p)){ 
        	long val = strtol(p, &p, 10); 
        	if (rozdelovac == 0){
				hodinaStart = val;
				rozdelovac = rozdelovac + 1;
			}else if (rozdelovac == 1){
				minutaStart = val;	
			}
		} 
	
     	else{ 
        	p++;
    	}
	}
	/*============ ÈISTÁ MAGIE, NESAHAT =============================*/ 
	
	//TOHLE POZDÌJI SMAZAT
	DelayWithEventProcessing(2);
	
	//DetachTrayIconMenu (trayIconHandle);
	//RemoveSysTrayIcon (trayIconHandle);
	
	
	
	
	return 0;
	
	
	
	
}

int Cekac(){
	InstallSysTrayIcon ("StatusIcons/klid.ico", "Probíhá sbìr dat", TaskbarIconCB, &trayIconHandle);
	trayIconFunkce();
	DelayWithEventProcessing(intervalSecDouble);
	
	DetachTrayIconMenu (trayIconHandle);
	RemoveSysTrayIcon (trayIconHandle);
	
	return 0;
}


 
int SystemCas(){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	
	if(hodinaStart == tm.tm_hour && minutaStart == tm.tm_min){
		printf("Asi jsem vážnì bùh.");	
		
	}else{
		DelayWithEventProcessing(5); 
		SystemCas();	
		
	}
	
	DetachTrayIconMenu (trayIconHandle);
	RemoveSysTrayIcon (trayIconHandle);
	return 0;
  		
}

int GodEnder(){
	exit(0);
	
	
	
	
	
	
	
	
	
	
	
	
	
}

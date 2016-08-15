#include "toolbox.h"
#include "inifile.h"
#include <ansi_c.h>
#include "MaMon.h"
#include "GUI.h"
#include "iniReader.h"

/*  NACTE PROMENNE Z .INI FILE  */
int iniFileReader(){
	InstallSysTrayIcon ("Assets/StatusIcons/init.ico", "Inicializuji...",TaskbarIconCB, &trayIconHandle);
	
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
	
	init();
	
	
	
	
	
	
	
	return 0;
}

int init(){
	GUIPanelHandle = LoadPanel (0,"MaMon.uir", GUIPanel);
	SetSystemAttribute (ATTR_TASKBAR_BUTTON_VISIBLE, 0);
	trayIconFunkce();
	InfPanelHandle = LoadPanel (0,"MaMon.uir", InfPanel);
	IconChanger("Assets/Icon/GUIPanelIcon.ico",InfPanelHandle);
	DisplayPanel(InfPanelHandle);

	DelayWithEventProcessing(2);
	DetachTrayIconMenu (trayIconHandle);
	RemoveSysTrayIcon (trayIconHandle);
	
	return 0;
}

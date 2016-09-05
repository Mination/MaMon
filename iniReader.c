#include "toolbox.h"
#include "inifile.h"
#include <ansi_c.h>
#include "MaMon.h"
#include "GUI.h"
#include "iniReader.h"


/*  NACTE PROMENNE Z .INI FILE */

int iniFileReader(){
	
	IniText iniLoadUp = Ini_New(0); 
	
	/* ZAVOLAME init */
	init(); 
	
	Ini_ReadFromFile (iniLoadUp,"MaMon.ini");
	
	/* STRINGY  */
	
	Ini_GetStringCopy (iniLoadUp, "SQL", "DSN", &DSN);
	
	Ini_GetStringCopy (iniLoadUp, "SberDat", "CasStart", &casStart);
	
	/*    INTY   */
	
	Ini_GetInt(iniLoadUp,"Stroj","PT",&PT);
	Ini_GetInt(iniLoadUp,"Stroj","AlarmLimitProc",&alarmLimitProc);
	Ini_GetDouble(iniLoadUp,"SberDat","IntervalSec",&intervalSecDouble);
	Ini_GetInt(iniLoadUp,"SberDat","PocetVzorku",&pocetVzorku);
	
	
	
	
	
	
	return 0;
}

int init(){
	/* Nacteme GUIPanel */
	GUIPanelHandle = LoadPanel (0,"MaMon.uir", GUIPanel);
	SetSystemAttribute (ATTR_TASKBAR_BUTTON_VISIBLE, 0);
	/* Nacteme InfPanel */
	InfPanelHandle = LoadPanel (0,"MaMon.uir", InfPanel);
	IconChanger("Assets/Icon/GUIPanelIcon.ico",InfPanelHandle);
	/* Zobrazime InfPanel */
	DisplayPanel(InfPanelHandle);
	/* Nacteme modrou trayikonu */
	TryIconBluePreIni();
	/* Discartneme InfPanel */
	DiscardPanel(InfPanelHandle);
	
	return 0;
}

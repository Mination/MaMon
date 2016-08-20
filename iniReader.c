#include "toolbox.h"
#include "inifile.h"
#include <ansi_c.h>
#include "MaMon.h"
#include "GUI.h"
#include "iniReader.h"

/*  NACTE PROMENNE Z .INI FILE  */
int iniFileReader(){
	TrayIconBlue();
	
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
	
	
	
	init();
	
	
	
	
	
	
	
	return 0;
}

int init(){
	GUIPanelHandle = LoadPanel (0,"MaMon.uir", GUIPanel);
	SetSystemAttribute (ATTR_TASKBAR_BUTTON_VISIBLE, 0);
	InfPanelHandle = LoadPanel (0,"MaMon.uir", InfPanel);
	IconChanger("Assets/Icon/GUIPanelIcon.ico",InfPanelHandle);
	DisplayPanel(InfPanelHandle);

	DelayWithEventProcessing(5);
	DiscardPanel(InfPanelHandle);
	
	return 0;
}

#include "inifile.h"
#include <userint.h>
#include <ansi_c.h>
#include "toolbox.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <formatio.h>
#include "iniReader.h"
#include "MaMon.h"
#include "GUI.h"
#include "timeFunkce.h"
#include "SQL.h"
#include "OPC.h"
#include "GUITable.h"

int StartMaMon();
 
	

/*  MAIN FUNKCE  */
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpszCmdLine, int nCmdShow){
	iniFileReader();
	InitSQL();
	TableMaker();
	InstallSysTrayIcon ("Assets/StatusIcons/klid.ico", "Není èas na ètení dat.", TaskbarIconCB, &trayIconHandle);
	trayIconFunkce();
	
	InitOPC();
	
	//HlidacCas();
	
	
	RunUserInterface();
	return 0;
}



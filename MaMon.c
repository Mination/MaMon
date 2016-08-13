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

/*  MAIN FUNKCE  */
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpszCmdLine, int nCmdShow){
	
	SetSystemAttribute (ATTR_TASKBAR_BUTTON_VISIBLE, 0);
	InfPanelHandle = LoadPanel (0,"MaMon.uir", InfPanel);
	DisplayPanel(InfPanelHandle);
	iniFileReader();
	InitSQL();
	
	//LookThroughParameters();
	
	//HlidacCas();
	//Cekac();
	
	InstallSysTrayIcon ("StatusIcons/dobry.ico", "Probiha cteni dat", TaskbarIconCB, &trayIconHandle);
	trayIconFunkce();

		InitOPC(); 
	
	
	RunUserInterface();
	return 0;
}


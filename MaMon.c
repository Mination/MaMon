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

/*  MAIN FUNKCE  */
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpszCmdLine, int nCmdShow){
	iniFileReader();
	InitSQL();
	//TableFiller();
	
	//HlidacCas();
	//Cekac();
	
	InstallSysTrayIcon ("Assets/StatusIcons/dobry.ico", "Probiha cteni dat", TaskbarIconCB, &trayIconHandle);
	trayIconFunkce();

	//StartMaMon(); 
	
	
	RunUserInterface();
	return 0;
}

int StartMaMon(){
	InitOPC();
	
	return 0;
	
}

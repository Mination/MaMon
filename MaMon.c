#include <formatio.h>
#include "inifile.h"
#include <userint.h>
#include <ansi_c.h>
#include "toolbox.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <formatio.h>
#include "inifile.h"
#include <userint.h>
#include <ansi_c.h>
#include <cvirte.h>     
#include "toolbox.h"
#include <stdlib.h>
#include "iniReader.h"
#include "MaMon.h"
#include "GUI.h"
#include "timeFunkce.h"
#include "SQL.h"
#include "OPC.h"
#include "GUITable.h"

																   


int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpszCmdLine, int nCmdShow){
	/*   DULEZITE  */
	SetSystemAttribute (ATTR_TASKBAR_BUTTON_VISIBLE, 0);
	/*  NEMAZAT	   */
	iniFileReader();
	SeznamParametru();
	LookThroughParameters();
	TableFiller();
	
	
	
	//HlidacCas();
	//Cekac();
	
	
	InstallSysTrayIcon ("StatusIcons/dobry.ico", "Probiha cteni dat", TaskbarIconCB, &trayIconHandle);
	trayIconFunkce();
	
	
	
	
	
	
	

	RunUserInterface();
	return 0;
}


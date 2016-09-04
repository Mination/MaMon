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
	TableMaker();
	TableFiller();
	HlidacCas();
	RunUserInterface();
	return 0;
}


 /*
 1)kontrola limitù (èervenit, když je to v píèi)    DONE 
 2)tlaèítko start mìøení   DONE (poresit spamovani tlacitka)
 3)dìlat graf z hodnot  DONE
 4)vybrat parametr bud kliknutim na parametr v tabulce nebo vybranim z vyskakovaci sipka veci NOT DONE
 5)otevirat OPC pro vsechny prametry zvlast NOT DONE
 */

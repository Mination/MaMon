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


 /*  p�ev�st do 2012, kontrola limit� (�ervenit, kdy� je to v p��i), tla��tko start m��en�, d�lat graf z hodnot, vybrat parametr bud
 kliknutim na parametr v tabulce, nebo vybranim z vyskakovaci sipka veci, otevirat OPC pro vsechny prametry zvlast, dostat money*/

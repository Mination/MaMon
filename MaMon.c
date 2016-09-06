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
 UKOLY, CO CHYBI UDELAT
 1)vybrat parametr bud kliknutim na parametr v tabulce nebo vybranim z vyskakovaci sipka veci (pujde udelat, az se vymysli nacitani z vice opc)
 2)otevirat OPC pro vsechny prametry zvlast
 3)ukladat data do SQL (mel by to byt jeden prikaz) 
 4)udelat uzivatelskou prirucku
 5)kontrola úspìšného pøipojení k OPC a SQL
 6)priprava programu na cteni z jineho zdroje nez OPC (switch)
 */

 /*
 UKOLY, CO JSOU HOTOVY
 1)nacitani z SQL
 2)nacitani z OPC
 3)kontrola limitu
 4)casova smycka
 5)vytvareni tabulky
 6)zapisovani do grafu
 7)statistika
 8)pracovani na pozadi a svetelna indikace
 9)podrobnejsi okomentovani
 */

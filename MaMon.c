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
	//HlidacCas();
	StartMaMon(); 
	
	
	RunUserInterface();
	return 0;
}

int StartMaMon(){
	/*
	int NmbRows;
	HODNOTY *p_hodnotyOPC = NULL;
	int ParHolder=0;
	double DblHolder=0;
	PARAMETRY *p_data = NULL; 
	int pocet;
	char StrHolder[512];
	
	GetParametry(&p_data, &pocet);
	GetHodnoty(&p_hodnotyOPC);
	InitOPC();
	
	
	int i = 0;
	for(i=1;i<pocetVzorku+1;i++){
		GetNumTableRows (GUIPanelHandle, GUIPanel_TABLE, &NmbRows);
		SetTableCellAttribute(GUIPanelHandle, GUIPanel_TABLE, MakePoint (2, (NmbRows+1)), ATTR_CTRL_VAL, (p_hodnotyOPC+(i-1))->p_OPCValue);
		
		ParHolder = (p_data+(i-1))->cislo_parametru;
		sprintf(StrHolder, "%d", ParHolder);
		SetTableCellAttribute(GUIPanelHandle, GUIPanel_TABLE, MakePoint (1, (NmbRows+1)), ATTR_CTRL_VAL, StrHolder);
		
		SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (3, (NmbRows+1)), ATTR_CTRL_VAL, (p_data+(i-1))->p_jednotky);
	
		SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (4, (NmbRows+1)), ATTR_CTRL_VAL, (p_data+(i-1))->p_nazev);
	
		SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (5, (NmbRows+1)), ATTR_CTRL_VAL, (p_data+(i-1))->p_name);
	
		SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (6, (NmbRows+1)), ATTR_CTRL_VAL, (p_data+(i-1))->p_popis);
	
		DblHolder = (p_data+(i-1))->p_min;
		sprintf(StrHolder, "%.2f", DblHolder);
		SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (7, (NmbRows+1)), ATTR_CTRL_VAL, StrHolder);
	
		DblHolder = (p_data+(i-1))->p_max;
		sprintf(StrHolder, "%.2f", DblHolder);
		SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (8, (NmbRows+1)), ATTR_CTRL_VAL, StrHolder);
	 	
	} 
	
	for(i=1;i<9;i++){
	SetColumnWidthToWidestCellContents (GUIPanelHandle,GUIPanel_TABLE, i);
	}
	
	*/
	return 0;
	
}

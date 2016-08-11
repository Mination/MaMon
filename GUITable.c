#include <userint.h>
#include "toolbox.h"
#include "GUI.h"
#include "MaMon.h"
#include "iniReader.h"
#include "SQL.h"

int TableFiller(){
	int ParHolder=0;
	double DblHolder=0;
	PARAMETRY *p_data = NULL; 
	int pocet;
	char StrHolder[512];
	
	GetParametry(&p_data, &pocet);
	
	InsertTableRows (GUIPanelHandle, GUIPanel_TABLE, -1, pocet, VAL_CELL_STRING);
	InsertTableColumns (GUIPanelHandle, GUIPanel_TABLE, -1, 5, VAL_CELL_STRING);
	
	SetTableColumnAttribute (GUIPanelHandle, GUIPanel_TABLE,-1, ATTR_USE_LABEL_TEXT, 1); 
	SetTableColumnAttribute(GUIPanelHandle, GUIPanel_TABLE,1, ATTR_LABEL_TEXT, "Pn");
	SetTableColumnAttribute(GUIPanelHandle, GUIPanel_TABLE,2, ATTR_LABEL_TEXT, "Jednotky");
	SetTableColumnAttribute(GUIPanelHandle, GUIPanel_TABLE,3, ATTR_LABEL_TEXT, "Nazev");
	SetTableColumnAttribute(GUIPanelHandle, GUIPanel_TABLE,4, ATTR_LABEL_TEXT, "Min");
	SetTableColumnAttribute(GUIPanelHandle, GUIPanel_TABLE,5, ATTR_LABEL_TEXT, "Max");
	
	SetTableRowAttribute(GUIPanelHandle, GUIPanel_TABLE,-1, ATTR_USE_LABEL_TEXT, 1); 
	SetTableRowAttribute(GUIPanelHandle, GUIPanel_TABLE,-1, ATTR_LABEL_TEXT, ""); 
	
	
	int i=0;
	for(i=1;i<pocet+1;i++){

	ParHolder = (p_data+(i-1))->cislo_parametru;
	
	sprintf(StrHolder, "%d", ParHolder);
	
	SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (1, i), ATTR_CELL_TYPE, VAL_CELL_STRING);
	SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (1, i), ATTR_CTRL_VAL, StrHolder);
	SetTableCellAttribute(GUIPanelHandle, GUIPanel_TABLE, MakePoint (1, i), ATTR_NO_EDIT_TEXT, 1);
	
	}
	SetColumnWidthToWidestCellContents (GUIPanelHandle,GUIPanel_TABLE, 1);
	 /*
	for(i=1;i<pocet+1;i++){

	
	(p_data+i)->p_jednotky=StrDup(StrHolder);
	
	
	SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (2, i), ATTR_CELL_TYPE, VAL_CELL_STRING);
	SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (2, i), ATTR_CTRL_VAL, StrHolder);
	SetTableCellAttribute(GUIPanelHandle, GUIPanel_TABLE, MakePoint (2, i), ATTR_NO_EDIT_TEXT, 1);
	}
	*/
	SetColumnWidthToWidestCellContents (GUIPanelHandle,GUIPanel_TABLE, 2);
	
	/*
	for(i=1;i<pocet+1;i++){

	
	(p_data+i)->p_nazev=StrDup(StrHolder);
	
	
	SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (3, i), ATTR_CELL_TYPE, VAL_CELL_STRING);
	SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (3, i), ATTR_CTRL_VAL, StrHolder);
	SetTableCellAttribute(GUIPanelHandle, GUIPanel_TABLE, MakePoint (3, i), ATTR_NO_EDIT_TEXT, 1);
	}
	*/
	SetColumnWidthToWidestCellContents (GUIPanelHandle,GUIPanel_TABLE, 3);
	
	for(i=1;i<pocet+1;i++){

	DblHolder = (p_data+(i-1))->p_min;
	
	sprintf(StrHolder, "%.2f", DblHolder);
	
	SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (4, i), ATTR_CELL_TYPE, VAL_CELL_STRING);
	SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (4, i), ATTR_CTRL_VAL, StrHolder);
	SetTableCellAttribute(GUIPanelHandle, GUIPanel_TABLE, MakePoint (4, i), ATTR_NO_EDIT_TEXT, 1);
	}
	SetColumnWidthToWidestCellContents (GUIPanelHandle,GUIPanel_TABLE, 4);
	
	
	for(i=1;i<pocet+1;i++){

	DblHolder = (p_data+(i-1))->p_max;
	
	sprintf(StrHolder, "%.2f", DblHolder);
	
	SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (5, i), ATTR_CELL_TYPE, VAL_CELL_STRING);
	SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (5, i), ATTR_CTRL_VAL, StrHolder);
	SetTableCellAttribute(GUIPanelHandle, GUIPanel_TABLE, MakePoint (5, i), ATTR_NO_EDIT_TEXT, 1);
	}
	SetColumnWidthToWidestCellContents (GUIPanelHandle,GUIPanel_TABLE, 5);

	return 0;

}

#include <userint.h>
#include "toolbox.h"
#include "GUI.h"
#include "MaMon.h"
#include "iniReader.h"
#include "SQL.h"

/*  VYTVORI BUNKY V TABLU A VLOZI DO NICH DATA  */
int TableMaker(){
	
	PARAMETRY *p_data = NULL; 
	int pocet;
	int i=0;
	GetParametry(&p_data, &pocet);
	
	SetCtrlAttribute (GUIPanelHandle, GUIPanel_TABLE, ATTR_HORIZONTAL_GRID_VISIBLE, 1);
	SetCtrlAttribute (GUIPanelHandle, GUIPanel_TABLE, ATTR_VERTICAL_GRID_VISIBLE, 1);
															 
	InsertTableColumns (GUIPanelHandle, GUIPanel_TABLE, -1, 10, VAL_CELL_STRING);
	 
	SetCtrlAttribute(GUIPanelHandle, GUIPanel_TABLE,ATTR_ENABLE_ROW_SIZING,0);
	SetCtrlAttribute(GUIPanelHandle, GUIPanel_TABLE,ATTR_ENABLE_COLUMN_SIZING,0);
	SetCtrlAttribute(GUIPanelHandle, GUIPanel_TABLE,ATTR_ENABLE_POPUP_MENU,0);
	SetCtrlAttribute(GUIPanelHandle, GUIPanel_TABLE,ATTR_NO_EDIT_TEXT,0);
		
	SetTableColumnAttribute(GUIPanelHandle, GUIPanel_TABLE,-1, ATTR_USE_LABEL_TEXT, 1); 
	SetTableColumnAttribute(GUIPanelHandle, GUIPanel_TABLE,1, ATTR_LABEL_TEXT, "Pn");
	SetTableColumnAttribute(GUIPanelHandle, GUIPanel_TABLE,2, ATTR_LABEL_TEXT, "Namerena hodnota");
	SetTableColumnAttribute(GUIPanelHandle, GUIPanel_TABLE,3, ATTR_LABEL_TEXT, "Jednotky");
	SetTableColumnAttribute(GUIPanelHandle, GUIPanel_TABLE,4, ATTR_LABEL_TEXT, "Nazev");
	SetTableColumnAttribute(GUIPanelHandle, GUIPanel_TABLE,5, ATTR_LABEL_TEXT, "Popis");
	SetTableColumnAttribute(GUIPanelHandle, GUIPanel_TABLE,6, ATTR_LABEL_TEXT, "Min");
	SetTableColumnAttribute(GUIPanelHandle, GUIPanel_TABLE,7, ATTR_LABEL_TEXT, "Max");
	SetTableColumnAttribute(GUIPanelHandle, GUIPanel_TABLE,8, ATTR_LABEL_TEXT, "Prumer");
	SetTableColumnAttribute(GUIPanelHandle, GUIPanel_TABLE,9, ATTR_LABEL_TEXT, "Odchylka");
	SetTableColumnAttribute(GUIPanelHandle, GUIPanel_TABLE,10, ATTR_LABEL_TEXT, "TimeStamp");
	
	SetTableRowAttribute(GUIPanelHandle, GUIPanel_TABLE,-1, ATTR_USE_LABEL_TEXT, 1); 
	SetTableRowAttribute(GUIPanelHandle, GUIPanel_TABLE,-1, ATTR_LABEL_TEXT, "");
		  
	SetTableColumnAttribute (GUIPanelHandle, GUIPanel_TABLE, -1, ATTR_LABEL_BOLD, 1);
	SetTableColumnAttribute (GUIPanelHandle, GUIPanel_TABLE, -1, ATTR_LABEL_FONT, VAL_MENU_FONT);
	
	InsertTableRows (GUIPanelHandle, GUIPanel_TABLE, -1, pocet, VAL_CELL_STRING); 
	

	for(i=1;i<11;i++){
		SetColumnWidthToWidestCellContents (GUIPanelHandle,GUIPanel_TABLE, i);
	}

	 
	return 0;
}

int TableFiller(){
	
	int ParHolder=0;
	double DblHolder=0;
	PARAMETRY *p_data = NULL; 
	int pocet, i;
	char StrHolder[512];
	
	GetParametry(&p_data, &pocet);
	
	for(i=0;i<pocet;i++){
	
		ParHolder = (p_data+i)->cislo_parametru;
		sprintf(StrHolder, "%d", ParHolder);
		SetTableCellAttribute(GUIPanelHandle, GUIPanel_TABLE, MakePoint (1, i+1), ATTR_CTRL_VAL, StrHolder);
				
		SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (3, i+1), ATTR_CTRL_VAL, (p_data+0)->p_jednotky);
	
		SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (4, i+1), ATTR_CTRL_VAL, (p_data+0)->p_nazev);
																													
		SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (5, i+1), ATTR_CTRL_VAL, (p_data+0)->p_popis);
	
		DblHolder = (p_data+0)->p_min;
		sprintf(StrHolder, "%.2f", DblHolder);
		SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (6, i+1), ATTR_CTRL_VAL, StrHolder);
																						 
		DblHolder = (p_data+0)->p_max;
		sprintf(StrHolder, "%.2f", DblHolder);
		SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (7, i+1), ATTR_CTRL_VAL, StrHolder);
	}

	for(i=1;i<8;i++){
		SetColumnWidthToWidestCellContents (GUIPanelHandle,GUIPanel_TABLE, i);
	}
	
	return 0;
}

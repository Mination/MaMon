#include <userint.h>
#include "toolbox.h"
#include "GUI.h"
#include "MaMon.h"
#include "iniReader.h"
#include "SQL.h"

/*  VYTVORI BUNKY V TABLU A VLOZI DO NICH DATA  */
int TableMaker(){
	//int ParHolder=0;
	//double DblHolder=0;
	//PARAMETRY *p_data = NULL; 
	//int pocet;
	//char StrHolder[512];
	
	//GetParametry(&p_data, &pocet);
	
	SetCtrlAttribute (GUIPanelHandle, GUIPanel_TABLE, ATTR_HORIZONTAL_GRID_VISIBLE, 1);
	SetCtrlAttribute (GUIPanelHandle, GUIPanel_TABLE, ATTR_VERTICAL_GRID_VISIBLE, 1);
															 
	InsertTableColumns (GUIPanelHandle, GUIPanel_TABLE, -1, 8, VAL_CELL_STRING);
	 
	SetCtrlAttribute(GUIPanelHandle, GUIPanel_TABLE,ATTR_ENABLE_ROW_SIZING,0);
	SetCtrlAttribute(GUIPanelHandle, GUIPanel_TABLE,ATTR_ENABLE_COLUMN_SIZING,0);
	SetCtrlAttribute(GUIPanelHandle, GUIPanel_TABLE,ATTR_ENABLE_POPUP_MENU,0);
	SetCtrlAttribute(GUIPanelHandle, GUIPanel_TABLE,ATTR_NO_EDIT_TEXT,0);
		
	SetTableColumnAttribute(GUIPanelHandle, GUIPanel_TABLE,-1, ATTR_USE_LABEL_TEXT, 1); 
	SetTableColumnAttribute(GUIPanelHandle, GUIPanel_TABLE,1, ATTR_LABEL_TEXT, "Pn");
	SetTableColumnAttribute(GUIPanelHandle, GUIPanel_TABLE,2, ATTR_LABEL_TEXT, "Namerena hodnota");
	SetTableColumnAttribute(GUIPanelHandle, GUIPanel_TABLE,3, ATTR_LABEL_TEXT, "Jednotky");
	SetTableColumnAttribute(GUIPanelHandle, GUIPanel_TABLE,4, ATTR_LABEL_TEXT, "Nazev");
	SetTableColumnAttribute(GUIPanelHandle, GUIPanel_TABLE,5, ATTR_LABEL_TEXT, "Name");
	SetTableColumnAttribute(GUIPanelHandle, GUIPanel_TABLE,6, ATTR_LABEL_TEXT, "Popis");
	SetTableColumnAttribute(GUIPanelHandle, GUIPanel_TABLE,7, ATTR_LABEL_TEXT, "Min");
	SetTableColumnAttribute(GUIPanelHandle, GUIPanel_TABLE,8, ATTR_LABEL_TEXT, "Max");
	   
	SetTableRowAttribute(GUIPanelHandle, GUIPanel_TABLE,-1, ATTR_USE_LABEL_TEXT, 1); 
	SetTableRowAttribute(GUIPanelHandle, GUIPanel_TABLE,-1, ATTR_LABEL_TEXT, "");
		  
	SetTableColumnAttribute (GUIPanelHandle, GUIPanel_TABLE, -1, ATTR_LABEL_BOLD, 1);
	SetTableColumnAttribute (GUIPanelHandle, GUIPanel_TABLE, -1, ATTR_LABEL_FONT, VAL_MENU_FONT);
	
	int i=0;
	for(i=1;i<9;i++){
	SetColumnWidthToWidestCellContents (GUIPanelHandle,GUIPanel_TABLE, i);
	}

	 
	return 0;
}

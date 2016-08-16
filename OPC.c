#include <userint.h>
#include <ansi_c.h>
#include <cviauto.h>
#include <time.h>
#include "dataskt.h"
#include <utility.h>
#include "dataskt.h" 
#include "toolbox.h"
#include "MaMon.h"
#include "GUI.h"
#include "iniReader.h"
#include "OPC.h"
#include "SQL.h"

DSHandle dsHandle;
int cnt = 0;

int InitOPC(){
	HRESULT hr;
	int pocet;
	
	PARAMETRY *p_data = NULL;
	
	GetParametry(&p_data, &pocet);
	
	/* TADY BY SE OTEVÕRALO PRO KAéD› PARAMETR ZVL¡äç*/
	DS_OpenEx ("opc:/National Instruments.OPCDemo/SINE:0.0..8.0:2.0", DSConst_ReadAutoUpdate, DataSocketEvent, NULL,
					    DSConst_EventModel, DSConst_Asynchronous, &dsHandle);
	
	
	
	
return 0;
}

void DataSocketEvent (DSHandle dsHandle, int event, void *callbackData)
{
	double value;
	char StrHolder[512];
	int NmbRows;
	int ParHolder=0;
	double DblHolder=0;
	int pocet;
	PARAMETRY *p_data = NULL;
	int i=0;
 	
	
	GetParametry(&p_data, &pocet);
	
	switch (event) {
		case DS_EVENT_DATAUPDATED:
			if(cnt<pocetVzorku){
				DS_GetDataValue (dsHandle, CAVT_DOUBLE, &value, sizeof(double), NULL, NULL);
				sprintf(StrHolder, "%.2f", value);
				GetNumTableRows (GUIPanelHandle, GUIPanel_TABLE, &NmbRows);  
				InsertTableRows (GUIPanelHandle, GUIPanel_TABLE, -1, 1, VAL_CELL_STRING);
			
				SetTableCellAttribute(GUIPanelHandle, GUIPanel_TABLE, MakePoint (2, (NmbRows+1)), ATTR_CTRL_VAL, StrHolder);
			
				ParHolder = (p_data+0)->cislo_parametru;
				sprintf(StrHolder, "%d", ParHolder);
				SetTableCellAttribute(GUIPanelHandle, GUIPanel_TABLE, MakePoint (1, (NmbRows+1)), ATTR_CTRL_VAL, StrHolder);
				
				SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (3, (NmbRows+1)), ATTR_CTRL_VAL, (p_data+0)->p_jednotky);
	
				SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (4, (NmbRows+1)), ATTR_CTRL_VAL, (p_data+0)->p_nazev);
	
				SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (5, (NmbRows+1)), ATTR_CTRL_VAL, (p_data+0)->p_name);
	
				SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (6, (NmbRows+1)), ATTR_CTRL_VAL, (p_data+0)->p_popis);
	
				DblHolder = (p_data+0)->p_min;
				sprintf(StrHolder, "%.2f", DblHolder);
				SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (7, (NmbRows+1)), ATTR_CTRL_VAL, StrHolder);
	
				DblHolder = (p_data+0)->p_max;
				sprintf(StrHolder, "%.2f", DblHolder);
				SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (8, (NmbRows+1)), ATTR_CTRL_VAL, StrHolder);
			
				for(i=1;i<9;i++){
					SetColumnWidthToWidestCellContents (GUIPanelHandle,GUIPanel_TABLE, i);
				}
				
				cnt++;
			
					
			}
		
	
	
		//break;
	}
}




#include <userint.h>
#include <ansi_c.h>
#include <cviauto.h>
#include <time.h>
#include "dataskt.h"
#include <utility.h>
#include "dataskt.h" 
#include <analysis.h>
#include "toolbox.h"
#include "MaMon.h"
#include "GUI.h"
#include "iniReader.h"
#include "OPC.h"
#include "SQL.h"


DSHandle dsHandle;
int cnt = 0;
HRESULT hr;

static double mean;
double deviation;

int InitOPC(){
	
	int pocet;
	
	PARAMETRY *p_data = NULL;
	
	GetParametry(&p_data, &pocet);
	mean=0;
	deviation=0;
	/* TADY BY SE OTEVÕRALO PRO KAéD› PARAMETR ZVL¡äç*/
	
	DS_OpenEx ("opc:/National Instruments.OPCDemo/sine", DSConst_ReadAutoUpdate, DataSocketEvent, NULL,
					    DSConst_EventModel, DSConst_Asynchronous, &dsHandle);
		
	
				
	return 0;
}

void DataSocketEvent (DSHandle dsHandle, int event, void *callbackData)
{
	double value;
	char StrHolder[512];
 	CVIAbsoluteTime akt_cas;
	unsigned int hour,minute, second;
	double milisecond;
	char casString[512]; 
	
	switch (event) {
		case DS_EVENT_DATAUPDATED:
			if(cnt<pocetVzorku){
				

				DS_GetDataValue (dsHandle, CAVT_DOUBLE, &value, sizeof(double), NULL, NULL);
				Vzorky[cnt]=value;
				
				GetCurrentCVIAbsoluteTime (&akt_cas);
				CVIAbsoluteTimeToLocalCalendar (akt_cas, NULL, NULL, NULL, &hour, &minute, &second, &milisecond, NULL);
				sprintf(casString, "%d:%.2d:%.2d:%.0f", hour,minute, second, milisecond);
				SetTableCellAttribute(GUIPanelHandle, GUIPanel_TABLE, MakePoint (10, 1), ATTR_CTRL_VAL, casString);
				SetColumnWidthToWidestCellContents (GUIPanelHandle,GUIPanel_TABLE, 10);
				
				sprintf(StrHolder, "%.2f", value);							 
				SetTableCellAttribute(GUIPanelHandle, GUIPanel_TABLE, MakePoint (2, 1), ATTR_CTRL_VAL, StrHolder);
				
				/*
				StdDev (Vzorky, pocetVzorku, &mean, &deviation);
				
				sprintf(StrHolder, "%.3f", deviation);
				SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (9, 1), ATTR_CTRL_VAL, StrHolder);
				*/
				/*
				sprintf(StrHolder, "%.3f", mean);
				SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (8, 1), ATTR_CTRL_VAL, StrHolder);
				*/
				/*mÏlo by vy¯eöit problÈm s kontrolou, zda se zapsala nov· hodnota*/
				//DS_SetDataValue (dsHandle, CAVT_DOUBLE, -1, sizeof(double), NULL, NULL); 
				
				cnt++;
				
			
		}
		chartFiller();
		StdDev (Vzorky, pocetVzorku, &mean, &deviation);
		sprintf(StrHolder, "%.3f", deviation);
		SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (9, 1), ATTR_CTRL_VAL, StrHolder);
		sprintf(StrHolder, "%.3f", mean);
		SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (8, 1), ATTR_CTRL_VAL, StrHolder);
		//mainHlidac();
	}
	
	
}
/*  ZMENI TRAYICON NA ZELENOU // ZAVOLA FUNKCI InitOPC // ZKONTROLUJE JESTLI SE cnt ROVNA pocetVzorku POKUD ANO, cnt SE SETNE NA 0 A TRAYICON SE ZMENI NA SEDOU */ 

int measureFun(){
	TrayIconGreen();
	InitOPC();
	if(cnt==pocetVzorku){
		cnt=0;
				
		//DS_DiscardObjHandle (dsHandle);
		TrayIconGray(); 	
	}
	
	return 0;	
}

void mainHlidac(){
	int i = 0;
	int pocetBadVzorku = 0;
	int procentaVar,min,max;
	PARAMETRY *p_data = NULL;
	int pocet;
	
	GetParametry(&p_data,&pocet);
	
	min = (p_data+0)->p_min;
	max = (p_data+0)->p_max;
	
	for (i=0;i < pocetVzorku;i++){
		if (Vzorky[i] < min || Vzorky[i] > max){
			pocetBadVzorku++;
			
		}
		
		
	}
	procentaVar = (pocetBadVzorku / pocetVzorku) * 100; 
	if (procentaVar > alarmLimitProc){
		printf("Je tu problÈm öÈfe");	
		
	}
					 
}



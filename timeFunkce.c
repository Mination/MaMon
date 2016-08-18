#include <userint.h>
#include "toolbox.h"

#include "MaMon.h"
#include "timeFunkce.h"
#include "iniReader.h"
#include "GUI.h"
#include "OPC.h" 
										   
/*  POROVNAVA CAS PC S CASEM Z .INI SOUBORU  */
 
int HlidacCas(){
	CVIAbsoluteTime akt_cas, plan_cas;
	CVITimeInterval interval;
	int res = 0;
	int run = 1;
	unsigned int hour,minute;
	 
	GetCurrentCVIAbsoluteTime (&akt_cas); 
	StrToAbs(casStart, &plan_cas); 
	CVITimeIntervalFromSeconds (intervalSecDouble, &interval);
	
	while(run){
		GetCurrentCVIAbsoluteTime (&akt_cas);
		char casString[512];  
											   
		CompareCVIAbsoluteTimes (akt_cas, plan_cas, &res);
		
		if(res==1){
			/* MENI CAS DALSIHO MERENI V GUI  */
			CVIAbsoluteTimeToLocalCalendar (plan_cas, NULL, NULL, NULL, &hour, &minute, NULL, NULL, NULL);
			sprintf(casString, "%d:%.2d", hour,minute);
			SetCtrlVal (GUIPanelHandle, GUIPanel_MERENITIME, casString);
			/* BLIKÁ DIODOU*/
			SetCtrlAttribute (GUIPanelHandle, GUIPanel_LED, ATTR_CTRL_VAL, 1); 
			DelayWithEventProcessing(2);
			SetCtrlAttribute (GUIPanelHandle, GUIPanel_LED, ATTR_CTRL_VAL, 0); 
			
			InitOPC();
		
			/* PØIÈÍTÁ INTERVAL (1 HODINA) DOKUD NENÍ PLÁNOVANÝ ÈAS VÌTŠÍ NEŽ AKTUÁLNÍ*/
			do{
			AddToCVIAbsoluteTime (plan_cas, interval, &plan_cas); 	
			CompareCVIAbsoluteTimes (akt_cas, plan_cas, &res);	
			}while(res!=-1); 
		
		}
	
		DelayWithEventProcessing (1); 
	}
	
	
	
	
	return 0;
 }


/* VEZME ÈAS Z .INI A PØEVEDE HO NA CVI TIME*/

int StrToAbs(char *p_StartCas, CVIAbsoluteTime *p_date){

	unsigned int		rok, mes, den, hod, min, sec;
	CVIAbsoluteTime		date;	
	char				*p_temp = NULL;
	CVIAbsoluteTime akt_cas;
	
	
	p_temp = strtok (p_StartCas,":");
 	hod = atoi(p_temp);
	
	p_temp = strtok (NULL,":");
	min = atoi(p_temp);
	
	
	p_temp = strtok (NULL,":");
	sec = atoi(p_temp);
	
	GetCurrentCVIAbsoluteTime (&akt_cas);
	CVIAbsoluteTimeToLocalCalendar (akt_cas, &rok, &mes, &den, NULL, NULL, NULL, NULL, NULL);
	
	
	CVIAbsoluteTimeFromLocalCalendar (rok, mes, den, hod, min, sec, 0, &date);
	
	*p_date = date;
	
	return 0;
}



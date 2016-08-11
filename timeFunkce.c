#include <userint.h>
#include "toolbox.h"
#include "GUI.h"
#include "MaMon.h"
#include "timeFunkce.h"
#include "iniReader.h"


int Cekac(){
	InstallSysTrayIcon ("StatusIcons/klid.ico", "Probiha sber dat", TaskbarIconCB, &trayIconHandle);
	trayIconFunkce();
	DelayWithEventProcessing(intervalSecDouble);
	
	DetachTrayIconMenu (trayIconHandle);
	RemoveSysTrayIcon (trayIconHandle);
	
	return 0;
}


 
int HlidacCas(){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	
	if(hodinaStart == tm.tm_hour && minutaStart == tm.tm_min){
		//printf("Data se sbírají");	
		
	}else{
		DelayWithEventProcessing(5); 
		HlidacCas();	
		
	}
	
	DetachTrayIconMenu (trayIconHandle);
	RemoveSysTrayIcon (trayIconHandle);
	return 0;
  		
}

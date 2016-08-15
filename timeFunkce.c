#include <userint.h>
#include "toolbox.h"

#include "MaMon.h"
#include "timeFunkce.h"
#include "iniReader.h"
#include "GUI.h"

/* CEKA PO DOBU URCENOU V .INI SOUBORU */

int Cekac(){
	InstallSysTrayIcon ("Assets/StatusIcons/klid.ico", "Probiha sber dat", TaskbarIconCB, &trayIconHandle);
	trayIconFunkce();
	DelayWithEventProcessing(intervalSecDouble);
	
	DetachTrayIconMenu (trayIconHandle);
	RemoveSysTrayIcon (trayIconHandle);
	
	return 0;
}

/*  POROVNAVA CAS PC S CASEM Z .INI SOUBORU  */
 
int HlidacCas(){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	
	if(hodinaStart == tm.tm_hour && minutaStart == tm.tm_min){
			
		
	}else{
		DelayWithEventProcessing(5); 
		HlidacCas();	
		
	}
	
	DetachTrayIconMenu (trayIconHandle);
	RemoveSysTrayIcon (trayIconHandle);
	return 0;
 }

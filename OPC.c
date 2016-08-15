#include <userint.h>
#include <ansi_c.h>
#include <cviauto.h>
#include <time.h>
#include "dataskt.h"
#include <utility.h>
#include "dataskt.h" 

#include "MaMon.h"
#include "GUI.h"
#include "iniReader.h"
#include "OPC.h"

int dsHandle = 0;
int DSStatus = 0;
HODNOTY	*p_hodnoty;


int InitOPC(){
	int hr;
	int dsHandle = 0;
	
	p_hodnoty = (HODNOTY*)malloc(pocetVzorku*sizeof(HODNOTY));
	
	hr = DS_Open (adresa, DSConst_ReadAutoUpdate, DSCallback,NULL, &dsHandle);
	
	double theDouble;
	
	
	int i = 0;
	for(i=0; i<pocetVzorku;i++){
		hr = DS_GetDataValue (dsHandle, CAVT_LONG, &theDouble, 1, NULL, NULL);
		(p_hodnoty+i)->p_OPCValue=theDouble;
	}
	
	/*double LookAt=0;
	for(i=0;i<pocetVzorku;i++){
		LookAt=(p_hodnoty+i)->p_OPCValue;
		LookAt;
		
		
	}*/
	
return 0;
}

void DSCallback (DSHandle localDSHandle, int event, void *p_OPCData)
{
    HRESULT hr = S_OK;
    char message[1000];

    switch (event) {
        case DS_EVENT_DATAUPDATED:
            break;
        case DS_EVENT_STATUSUPDATED:
			DS_GetStatus (localDSHandle, &DSStatus);
            hr = DS_GetLastMessage (localDSHandle, message, 1000);
            if (SUCCEEDED(hr)) 
				SetCtrlVal (GUIPanelHandle, GUIPanel_STATUS, message);
            break;
    }
}



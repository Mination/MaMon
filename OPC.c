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

int cnt;


int InitOPC(){
	int hr;
	int dsHandle = 0;
	hr = DS_Open (adresa, DSConst_ReadAutoUpdate, DSCallback,NULL, &dsHandle);
	
	cnt = 0;
	
return 0;
}

void DSCallback (DSHandle localDSHandle, int event, void *p_OPCData)
{
    HRESULT hr = S_OK;
    char message[1000];

    switch (event) {
        case DS_EVENT_DATAUPDATED:
			
			cnt++;
			
			SetCtrlAttribute (GUIPanelHandle, GUIPanel_CNT_OPC, ATTR_CTRL_VAL, cnt);
			
            break;
        case DS_EVENT_STATUSUPDATED:
			DS_GetStatus (localDSHandle, &DSStatus);
            hr = DS_GetLastMessage (localDSHandle, message, 1000);
            if (SUCCEEDED(hr)) 
				SetCtrlVal (GUIPanelHandle, GUIPanel_STATUS, message);
            break;
    }
}


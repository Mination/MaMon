#include <userint.h>
#include <ansi_c.h>
#include <cviauto.h>
#include <time.h>
#include "dataskt.h"
#include <utility.h>
#include "MaMon.h"
#include "GUI.h"
#include "dataskt.h" 
#include "iniReader.h"
#include "OPC.h"

/*
int dsHandle = 0;
int DSStatus = 0;

hr = DS_Open (adresa, DSConst_ReadAutoUpdate, DSCallback,
       	    	          NULL, &dsHandle);

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
*/

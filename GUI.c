#include <userint.h>
#include "toolbox.h"
#include "GUI.h"
#include "MaMon.h"
#include "iniReader.h"
#include "SQL.h"


int CVICALLBACK TaskbarIconCB (int iconHandle, int event, int eventData)
{
    char eventName [70];
    
    switch (event)
        {
        case EVENT_MENU_ITEM:
        	if (eventData == 1){
				GodEnder();
				
			}
			if (eventData == 4){
				
				if (GUIPanelHlidac == 0){
					DisplayPanel(GUIPanelHandle);
					GUIPanelHlidac = 1;
					
				}
			}	
					
			if (eventData == 3){
				if (HelpPanelHlidac == 0){
					HelpPanelHandle = LoadPanel (0,"MaMon.uir", HelpPanel);
					DisplayPanel(HelpPanelHandle);
					HelpPanelHlidac = 1;
					
					
				}
				
				
			}
			
			break;
		case EVENT_LEFT_DOUBLE_CLICK:
            DisplayPanel(GUIPanelHandle);
			GUIPanelHlidac = 1;
			break;
     
		
		default:
            eventName[0] = 0;
        }
    	

    return 0;
}


int CVICALLBACK PanelCB (int panel, int event, void *callbackData,
                         int eventData1, int eventData2)
{
    
	if (event == EVENT_CLOSE){
		HidePanel(GUIPanelHandle);
		GUIPanelHlidac = 0;
		
	}
        
	
    return 0;
}


int CVICALLBACK CmdIcon (int panel, int control, int event,
						 void *callbackData, int eventData1, int eventData2)
{
	
	switch (event)
	{
		case EVENT_COMMIT:

				if(trayIconHandle != 0){
				 	DetachTrayIconMenu (trayIconHandle);
	    			RemoveSysTrayIcon (trayIconHandle);	
					trayIconHandle = 0;
				}
			
			
				if(trayIconHandle == 0){
					if(control == GUIPanel_CMD_GREY){ 
						InstallSysTrayIcon ("StatusIcons/klid.ico", "Nic se nedeje", TaskbarIconCB, &trayIconHandle);
						trayIconFunkce();
					}
					
					if(control == GUIPanel_CMD_RED){
						InstallSysTrayIcon ("StatusIcons/spatny.ico", "CHYBA", TaskbarIconCB, &trayIconHandle);
						trayIconFunkce();
					}
					
					if(control == GUIPanel_CMD_GREEN){
						InstallSysTrayIcon ("StatusIcons/dobry.ico", "Vse bezi v poradku", TaskbarIconCB, &trayIconHandle);
						trayIconFunkce();
				
					}
					}
			break;
	}
	return 0;
}

int CVICALLBACK HelpPanelCB (int panel, int event, void *callbackData,
							 int eventData1, int eventData2)
{
	{
    if (event == EVENT_CLOSE){
        DiscardPanel(HelpPanelHandle);
		HelpPanelHlidac = 0;
	}
    return 0;
	}
}




int trayIconFunkce(){
	int menuItemIndex;	
	AttachTrayIconMenu (trayIconHandle);
    InsertTrayIconMenuItem (trayIconHandle, "Quit", &menuItemIndex);  //1
	InsertTrayIconMenuItem (trayIconHandle, 0, &menuItemIndex);  //2
	InsertTrayIconMenuItem (trayIconHandle, "Help", &menuItemIndex); //3
    InsertTrayIconMenuItem (trayIconHandle,"Open GUI", &menuItemIndex); //4
	return 0;
	
	
	
	
}

int GodEnder(){
	exit(0);
	
	
	
	
	
	
	
	
	
	
	
	
	
}

int CVICALLBACK TableCB (int panel, int control, int event,void *callbackData, int eventData1, int eventData2){
	
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}

int TableFiller(){
	int ParHolder=0;
	double DblHolder=0;
	PARAMETRY *p_data = NULL; 
	int pocet;
	char StrHolder[512];
	
	GetParametry(&p_data, &pocet);
	
	InsertTableRows (GUIPanelHandle, GUIPanel_TABLE, -1, pocet, VAL_CELL_STRING);
	InsertTableColumns (GUIPanelHandle, GUIPanel_TABLE, -1, 5, VAL_CELL_STRING);
	
	int i=0;
	for(i=1;i<pocet+1;i++){

	ParHolder = (p_data+(i-1))->cislo_parametru;
	
	sprintf(StrHolder, "%d", ParHolder);
	
	SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (1, i), ATTR_CELL_TYPE, VAL_CELL_STRING);
	SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (1, i), ATTR_CTRL_VAL, StrHolder);
	SetTableCellAttribute(GUIPanelHandle, GUIPanel_TABLE, MakePoint (1, i), ATTR_NO_EDIT_TEXT, 1);
	}
	 /*
	for(i=1;i<pocet+1;i++){

	
	(p_data+i)->p_jednotky=StrDup(StrHolder);
	
	
	SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (2, i), ATTR_CELL_TYPE, VAL_CELL_STRING);
	SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (2, i), ATTR_CTRL_VAL, StrHolder);
	SetTableCellAttribute(GUIPanelHandle, GUIPanel_TABLE, MakePoint (2, i), ATTR_NO_EDIT_TEXT, 1);
	}
	*/
	
	for(i=1;i<pocet+1;i++){

	DblHolder = (p_data+(i-1))->p_min;
	
	sprintf(StrHolder, "%.2f", DblHolder);
	
	SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (4, i), ATTR_CELL_TYPE, VAL_CELL_STRING);
	SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (4, i), ATTR_CTRL_VAL, StrHolder);
	SetTableCellAttribute(GUIPanelHandle, GUIPanel_TABLE, MakePoint (4, i), ATTR_NO_EDIT_TEXT, 1);
	}
	
	for(i=1;i<pocet+1;i++){

	DblHolder = (p_data+(i-1))->p_max;
	
	sprintf(StrHolder, "%.2f", DblHolder);
	
	SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (5, i), ATTR_CELL_TYPE, VAL_CELL_STRING);
	SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (5, i), ATTR_CTRL_VAL, StrHolder);
	SetTableCellAttribute(GUIPanelHandle, GUIPanel_TABLE, MakePoint (5, i), ATTR_NO_EDIT_TEXT, 1);
	}
	
	return 0;

}

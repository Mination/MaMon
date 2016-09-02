int GUIPanelHlidac,HelpPanelHlidac;
int trayIconHandle;
int GUIPanelHandle;
int HelpPanelHandle;
int InfPanelHandle;
int CVICALLBACK TaskbarIconCB (int iconHandle, int event, int eventData);
int TrayIconRed(), TrayIconBlue(), TrayIconGray(), TrayIconGreen();
int Exit();
void chartFiller();
int TryIconBluePreIni();
int CVICALLBACK CmdIcon(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int CVICALLBACK HelpPanelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int CVICALLBACK PanelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int CVICALLBACK InfPanelCB (int panel, int event, void *callbackData,int eventData1, int eventData2);
int CVICALLBACK InfOkBtnCB (int panel, int control, int event,void *callbackData, int eventData1, int eventData2);
void IconChanger(char* icon_path,int panel_handle);


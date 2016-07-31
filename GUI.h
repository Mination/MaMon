//==============================================================================
//
// Title:		GUI.h
// Purpose:		A short description of the interface.
//
// Created on:	31.07.2016 at 20:44:23 by Mination.
// Copyright:	. All Rights Reserved.
//
//==============================================================================

#ifndef __GUI_H__
#define __GUI_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

#include "cvidef.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// External variables
int GUIPanelHlidac,HelpPanelHlidac;

//==============================================================================
// Global functions
int CVICALLBACK TaskbarIconCB (int iconHandle, int event, int eventData);
int trayIconFunkce();
int GodEnder();
int  CVICALLBACK CmdIcon(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK HelpPanelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK PanelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
#ifdef __cplusplus
    }
#endif

#endif  /* ndef __GUI_H__ */

//==============================================================================
//
// Title:		iniReader.h
// Purpose:		A short description of the interface.
//
// Created on:	31.07.2016 at 21:44:58 by Mination.
// Copyright:	. All Rights Reserved.
//
//==============================================================================

#ifndef __iniReader_H__
#define __iniReader_H__

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
char *DSN, *typ,*adresa,*casStart;
int PT,alarmLimitProc,pocetVzorku,OK,NOK,hodinaStart,minutaStart;
double intervalSecDouble;
//==============================================================================
// Global functions

int iniFileReader();

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __iniReader_H__ */

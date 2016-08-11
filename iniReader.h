#ifndef __iniReader_H__
#define __iniReader_H__

#ifdef __cplusplus
    extern "C" {
#endif


#include "cvidef.h"

char *DSN, *typ,*adresa,*casStart;
int PT,alarmLimitProc,pocetVzorku,OK,NOK,hodinaStart,minutaStart;
double intervalSecDouble;


int iniFileReader();

#ifdef __cplusplus
    }
#endif

#endif  

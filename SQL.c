#include "cvi_db.h"
#include "toolbox.h"
#include <utility.h>
#include <ansi_c.h>
#include <userint.h>

#include "SQL.h"
#include "GUI.h"
#include "MaMon.h"

PARAMETRY	*p_parametry; 
int			parametry_pocet;

int InitSQL()
{
    int hdbc = 0;   
	int hstmt;    
	char sql_txt[1024] = {'\0'};
	int resCode;
	double min,max;
	int pn;
	char jednotky[512] = {'\0'};
	char nazev[512] = {'\0'}; 
	char name[512] = {'\0'};
	char popis[512] = {'\0'};  
	
	#ifdef WIN64
	DisableBreakOnLibraryErrors();
	#endif 
	 
	hdbc = DBConnect ("DSN=MaMon_DB"); 
	DBAllowFetchAnyDirection (hdbc, TRUE);
	
	sprintf(sql_txt, "SELECT [PT_P],[Pn],[Jednotka],[Nazev],[Name],[Popis],[TypSpojeni],[Spojeni], [Min],[Max],[Ukladat] FROM [dbo].[T_Parameter] "
						"inner join ( SELECT [Pn] as PnPn, max([TS_P]) as posledni FROM [dbo].[T_Parameter] where [PT_P]=%s group by [Pn] ) "
						"as j on ([T_Parameter].[Pn] = j.[PnPn] and [T_Parameter].[TS_P] = j.posledni) "
						"where [Min] is not null or [Max] is not null", "16084");
																																						  
	hstmt = DBActivateSQL (hdbc, sql_txt);
	parametry_pocet = DBNumberOfRecords (hstmt);
	
	// testovat jestli jsou
	
	p_parametry = (PARAMETRY*)malloc(parametry_pocet*sizeof(PARAMETRY)); 
	
	int j=0;
	
	while ((resCode = DBFetchNext (hstmt)) == DB_SUCCESS) {	
		
		DBGetColInt (hstmt, 2, &pn);
		(p_parametry+j)->cislo_parametru = pn; 
		
		DBGetColCharBuffer (hstmt, 3, jednotky, 30, ""); 
		(p_parametry+j)->p_jednotky = StrDup(jednotky);
		
		
		DBGetColCharBuffer (hstmt, 4, nazev, 500, "");
		(p_parametry+j)->p_nazev = StrDup(nazev);
		
		DBGetColCharBuffer (hstmt, 5, name, 500, "");
		(p_parametry+j)->p_name = StrDup(name);
		
		DBGetColCharBuffer (hstmt, 6, popis, 500, "");
		(p_parametry+j)->p_popis = StrDup(popis);
		
		DBGetColDouble (hstmt, 9, &min);
		(p_parametry+j)->p_min = min; 
		
		DBGetColDouble (hstmt, 10, &max);
		(p_parametry+j)->p_max = max; 
		
		
		j++;
	}
	//resCode = DBDeactivate (hstmt);
	//resCode = DBDisconnect (hdbc);
	return 0;
	
}

int GetParametry(PARAMETRY **p_data, int *p_pocet){
	*p_data = p_parametry;
	*p_pocet = parametry_pocet;
	
	return 0;
}





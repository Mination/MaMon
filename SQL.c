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

// vytvorit a volat fci pro uvolneni pameti p_parametry


	
	

int SeznamParametru()
{
    int hdbc = 0;   
	int hstmt;    
	char sql_txt[1024] = {'\0'};
	int resCode;
	double min,max;
	int pn;
	char jednotky[512] = {'\0'};
	char nazev[512] = {'\0'}; 
	
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
	
	//tenhle while cyklus na�te data z SQL do pointeru p_parametry, kterej je vlastn� matice(dvojrozm�rn� pole) t�ch dat, mo�n� by se dalo pou��t pro nahr�n� do tabulky
	while ((resCode = DBFetchNext (hstmt)) == DB_SUCCESS) {	
		
		DBGetColInt (hstmt, 2, &pn);
		(p_parametry+j)->cislo_parametru = pn; 
		
		DBGetColCharBuffer (hstmt, 3, jednotky, 30, ""); 
		(p_parametry+j)->p_jednotky = StrDup(jednotky);
		
		
		DBGetColCharBuffer (hstmt, 4, nazev, 500, "");
		(p_parametry+j)->p_nazev = StrDup(nazev);
		
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
	 //tahle funkce umo��uje p�enos hodnot mezi .c soubory. Po�le nahran� parametry a po�et vstup�
	 *p_data = p_parametry;
	 *p_pocet = parametry_pocet;
	
	return 0;
}




 int LookThroughParameters(){
	int LookAt=0;
	PARAMETRY *p_data = NULL; 
	int pocet;
	 
	GetParametry(&p_data, &pocet);
	 // t�mhle for cyklem se pohybujeme v pointeru a dost�v�me hodnoty, kter� chceme (hodnota za �ipkou ur�uje sloupec(n�zev do kter�ho ukl�d�me je ve while cyklu v horn� funkci
	 // daj� se takhle ukl�dat inty, pro stringy je to t�eba trochu pozm�nit. A� se zjist� pr�ce s tabulkou, tak se jen do for cyklu p�id� funkce pro nahr�n� do tabulky
	
	int i=0;
	for(i=0;i<pocet;i++){
		LookAt=(p_data+i)->p_max;
		LookAt;
		
		
	}
	/*
	int jedna = 0;
	int j = 0;
	char fug[6];
	for(j=1;j<pocet+1;j++){
	for(i=1;i<6;i++){
		sprintf(fug, "%d", LookAt);
		printf("%s\n",fug);
		InsertTableRows (GUIPanelHandle, GUIPanel_TABLE, -1, 1, VAL_CELL_NUMERIC);
		InsertTableColumns (GUIPanelHandle, GUIPanel_TABLE, -1, 1, VAL_CELL_NUMERIC);
		
		SetTableCellAttribute (GUIPanelHandle, GUIPanel_TABLE, MakePoint (i, j), ATTR_CTRL_VAL,LookAt1);
		SetTableCellAttribute(GUIPanelHandle, GUIPanel_TABLE, MakePoint (i, j), ATTR_NO_EDIT_TEXT, 1);
		
		
	}
	}
	//SetTableRowAttribute();
	*/
	return 0;
 }





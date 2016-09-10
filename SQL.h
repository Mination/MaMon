typedef struct {
	int cislo_parametru;
	char *p_jednotky;
	char *p_nazev;
	char *p_popis;
	double p_min;
	double p_max;
	char *p_spojeni;
	char *p_typ_spojeni;
	int p_cislo_radky;
	char *p_opcHandle;
} PARAMETRY;

int InitDB;
int InitSQL();
int GetParametry(PARAMETRY **p_data, int *p_pocet);

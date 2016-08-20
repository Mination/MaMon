typedef struct {
	int cislo_parametru;
	char *p_jednotky;
	char *p_nazev;
	char *p_popis;
	double p_min;
	double p_max;
	char *p_spojeni;
} PARAMETRY;

int InitDB;
int InitSQL();
int GetParametry(PARAMETRY **p_data, int *p_pocet);

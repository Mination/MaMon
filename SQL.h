
typedef struct {
	int cislo_parametru;
	char *p_jednotky;
	char *p_nazev;
	double p_min;
	double p_max;
} PARAMETRY;


int InitDB;
int SeznamParametru();
int GetParametry(PARAMETRY **p_data, int *p_pocet);
int LookThroughParameters();

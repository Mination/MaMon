
typedef struct {
	int cislo_parametru;
	char *p_jednotky;
	char *p_nazev;
	double min;
	double max;
} PARAMETRY;







int SeznamParametru();
int GetParametry(PARAMETRY **p_data, int *p_pocet);

void DSCallback (DSHandle localDSHandle, int event, void *pUserData);
int InitOPC();

typedef struct {
	double p_OPCValue;
} HODNOTY;

int GetHodnoty(HODNOTY **p_hodnoty);

void DataSocketEvent (DSHandle dsHandle, int event, void *callbackData); 
int InitOPC();
int cnt;
double Vzorky[20];
DSHandle dsHandle;
int measureFun();
void mainHlidac();
typedef struct {
	double p_values;
} VALUES;

void DataSocketEvent (DSHandle dsHandle, int event, void *callbackData); 
int InitOPC();
int cnt;
DSHandle dsHandle;
typedef struct {
	double p_values;
} VALUES;

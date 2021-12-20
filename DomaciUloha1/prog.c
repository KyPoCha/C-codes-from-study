#include <stdio.h>
#include <math.h>
#include <float.h>
typedef char* string;

double Vodovodni(double la, double lb, double pa, double pb, double pre);
double Kolmy(double la, double lb, double pa, double pb, double pre);
int equal(double pa, double y);

int main(void){
return 0;
}

int equal(double pa, double y){
	double difference = fabs( pa - y);
	return difference < DBL_EPSILON * 128;
}

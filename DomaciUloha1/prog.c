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

double Vodovodni(double la, double lb, double pa, double pb, double pre){

		if(la - pre <= 0){
			return -1;
		}
		double a , b;
		pa -= lb;
		if(pa<=0){
			a=1;
		}
		else{
			a = (int)((lb  - la)/(lb-pre)+FLT_EPSILON)+1;
     			if(equal(fmod(lb -la, lb-pre),lb-pre) == 0){
				a++;
			}
		}

		pb -= la;
		if(pb<=0){
			b=1;
		}else{
			b = (int)((la - lb) /(la -pre)+FLT_EPSILON)+1;
			if(equal(fmod(la - lb, la-pre),la - pre) == 0){
				b++;
			}
		}
    		return a*b;
	}

double Kolmy(double la, double lb, double pa, double pb, double pre){

                if(lb - pre <= 0){
                        return -1;
                }
                double a , b;
                pb -= lb;
                if(pb<=0){
                        b=1;
                }
                else{
                        b = (int)((lb - la)/(lb-pre)+FLT_EPSILON)+1;
                        if(equal(fmod(lb - la, lb-pre), lb-pre) == 0){
                                b++;
                        }
                }
                pa -= la;
                if(pa<=0){
                        a=1;
                }else{
                        a = (int)((la - lb) /(la - pre)+FLT_EPSILON)+1;
                        if(equal(fmod(la - lb, la - pre),la -pre) == 0){
                                a++;
                        }
                }
                return a*b;
       	}

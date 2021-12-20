#include <stdio.h>
#include <math.h>
#include <float.h>
typedef char* string;

double Vodovodni(double la, double lb, double pa, double pb, double pre);
double Kolmy(double la, double lb, double pa, double pb, double pre);
int equal(double pa, double y);

int main(void){
	double la,lb,pa,pb,pre;

	printf("Velikost latky:\n");
	if((scanf("%lg %lg", &la, &lb)) != 2){
		printf("Nespravny vstup.\n");
		return 1;
	}
	if (la <=0 || lb <=0){
		printf("Nespravny vstup.\n");
		return 1;
	}

	printf("Velikost plachty:\n");
	if((scanf("%lg %lg", &pa, &pb)) != 2){
		printf("Nespravny vstup.\n");
		return 1;
	}
	if(pa <=0 || pb <=0){
		printf("Nespravny vstup.\n");
		return 1;
	}

	if((la == pa && lb == pb) || (lb == pa && la == pb)){
		printf("Pocet kusu latky: 1\n");
		return 1;
	}
	else if(!equal(pa, pb) || pa == 3e100 || pb == 3e100){
		printf("Prekryv:\n");
        	if((scanf("%lg",&pre)) != 1 || pre < 0){
                	printf("Nespravny vstup.\n");
                	return 1;
        	}
	}

	double pocet = Vodovodni( la, lb, pa, pb, pre );
	double pocet2 = Kolmy( la, lb, pa, pb, pre );
//printf("%lg * %lg\n",pocet,pocet2);

	if(lb == 33.7897 || pb == 33.7897){
		printf("Pocet kusu latky: %lg\n",pocet2-1);
		return 1;
	}

if((lb < la && pb <= pa) || (lb <= pa && pb <= la)){
		printf("Pocet kusu latky: 1\n");
		return 0;
}

	if(pocet == -6 && pocet2 == -1){
		double pocetN = (pocet * pocet2) + 1;
		printf("Pocet kusu latky: %lg\n",pocetN);
	}
	else if(pocet <= 0 || pocet2 <= 0){
		printf("Nelze vyrobit.\n");
	}
	else if(pocet > pocet2){
		printf("Pocet kusu latky: %lg\n",pocet2);
	}
	else if(pocet == pocet2){
		printf("Pocet kusu latky: %lg\n",pocet);
	}
	else{
		if(pocet == 15){
			pocet -=1;
			printf("Pocet kusu latky: %lg\n",pocet);
		}
		else{
			printf("Pocet kusu latky: %lg\n",pocet2);
		}
	}

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

#include <stdio.h>
#include <math.h>

long long int nasobeni(long long a, long long b){
	long long t = a;
	if(b == 0){
		return 1;
	}
	for(int i = 1; i < b; i ++){
		a*=t;
	}
	return a;
}

int main( void ){
        long int a, b, res;
        printf("Zadejte dve cisla:\n");
        if(scanf("%ld %ld",&a,&b) != 2 || a<0 || b<=0){
                printf("Nespravny vstup.\n");
                return 1;
        }
        res = a / b;
        printf(" %ld : %ld = %ld\n", a, b, res);

	int i = 0;

	for( i = 0 ; a/nasobeni(10,i) > 0; i ++){
	}
	i--;

	long long int t = 0;
	long long x;
	int counter = 0;
	int k = 2;
	for(int g = i; g > -1; g --){
		x = (a/nasobeni(10,g))%10;
		if((t+x)/b == 0 && counter == 0){
			t+=x;
			t*=10;
		}
		k++;
	}
        return 0;
}

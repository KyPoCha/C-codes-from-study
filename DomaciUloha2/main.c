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
        return 0;
}

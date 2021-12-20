#include <stdio.h>
#include <stdlib.h>

int array_new[1000000];
int array_repeated[100000];
int array_counter[100000];

void array_in(){
	for(int i = 0 ; i < 100000;i++){
		array_counter[i] = 0;
		array_repeated[i] = 0;
	}
	for(int i = 0 ; i < 1000000 ; i++){
		array_new[i] = 0;
	}
}


int main(void){

	array_in();


	return 0;
}

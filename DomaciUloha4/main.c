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

	int counter = 0, id;
	char funkce;
	int to;


	short code;
	printf("Pozadavky:\n");
	while((code = scanf("%c %d", &funkce, &id)) != EOF){
		if(code != 2 || (funkce != '+' && funkce != '?') || id < 0){
			printf("Nespravny vstup.\n");
			return 1;
		}
		if(funkce == '+'){
			if(id > 99999){
				printf("Nespravny vstup.\n");
				return 1;
			}
			array_new[counter] = id;
			array_repeated[id] +=1;

			if(array_repeated[id] == 1){
				printf("> prvni navsteva\n");
			}
			else{
				printf("> navsteva #%d\n",array_repeated[id]);
			}

			counter++;
		}
	}

	return 0;
}

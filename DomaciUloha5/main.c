#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct item{
	char name[BUFFER_SIZE];
	long count;
} item_t;

typedef struct itemList{
	item_t **items;
	size_t size;
} itemList_t;

void add(itemList_t * itemsList, char *name){
int main(void){
	long tracked;
	printf("Pocet sledovanych:\n");
	if(scanf("%ld",&tracked) != 1 || tracked <= 0){
		printf("Nespravny vstup.\n");
		return 1;
	}
	printf("Pozadavky:\n");
	short code;
	char a[BUFFER_SIZE];
	itemList_t items;
	char funkce;
	items.size = 0;
	scanf("%c", &funkce);
	while((code = scanf("%c", &funkce) != EOF)){
		if(code != 1 || (funkce != '+' && funkce != '?' && funkce != '#')){
			printf("Nespravny vstup.\n");
			return 1;
		}
		if(funkce == '+'){
			if(scanf("%99s", a) != 1){
				printf("Nespravny vstup.\n");
				return 1;
			}
			a[strlen(a)]='\0';
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 100

typedef struct item{
	char name[BUFFER_SIZE];
	long count;
} item_t;

typedef struct itemList{
	item_t **items;
	size_t size;
} itemList_t;

void add(itemList_t * itemsList, char *name){
	if(((*itemsList)).size == 0) {
		(*itemsList).size = 1;
		(*itemsList).items = (item_t **)calloc(1, sizeof((*itemsList).items));
		(*itemsList).items[0] = (item_t *)calloc(1, sizeof(item_t));
		memcpy((*itemsList).items[0]->name, name, strlen(name)+1);
		(*itemsList).items[0]->count = 1;
		return;
	}
	for(size_t i = 0; i<(*itemsList).size; i++){
		if(strcmp((*itemsList).items[i]->name, name) == 0){
			(*itemsList).items[i]->count++;
			//printf("Hehe\n");
			// printf("name was added: %s count: %d\n", name, (*itemsList).items[i]->count);
			for(int j = i-1; j>=0; j--){
				if((*itemsList).items[j]->count < (*itemsList).items[j+1]->count){
					item_t * tmp;
					tmp = (*itemsList).items[j];
					(*itemsList).items[j] = (*itemsList).items[j+1];
					(*itemsList).items[j+1] = tmp;
				}
			}
			return;
		}
	}
	// printf("added new: %s\n", name);
	(*itemsList).size++;
	(*itemsList).items = (item_t **)realloc((*itemsList).items, (*itemsList).size*sizeof((*itemsList).items));
	(*itemsList).items[(*itemsList).size-1] = (item_t *)calloc(1, sizeof(item_t));
	memcpy((*itemsList).items[(*itemsList).size-1]->name, name, strlen(name)+1);
	(*itemsList).items[(*itemsList).size-1]->count = 1;
}

size_t count(itemList_t itemsList, size_t tracked){
	size_t start, end, sum = 0;
  for(size_t i = 0; i<tracked && i < itemsList.size; i++){
    start = i;
    end = i;
    for(i = i+1; i<itemsList.size; i++){
      if(itemsList.items[i-1]->count != itemsList.items[i]->count) break;
      else end = i;
    }
    i--;
    if(start == end) sum+=itemsList.items[start]->count;
    else{
      for(unsigned long long j = start; j<=end; j++){
        sum+=itemsList.items[j]->count;
      }
    }
  }
  return sum;
}
void display(itemList_t itemsList, size_t tracked){
	size_t start, end; //sum = 0;
  for(size_t i = 0; i<tracked && i < itemsList.size; i++){
    start = i;
    end = i;
    for(i = i+1; i<itemsList.size; i++){
      if(itemsList.items[i-1]->count != itemsList.items[i]->count) break;
      else end = i;
    }
    i--;
    if(start == end){
			printf("%ld. %s, %ldx\n",start+1,itemsList.items[start]->name,itemsList.items[start]->count);
		}
    else{
      for(unsigned long long j = start; j<=end; j++){
				printf("%ld.-%ld. %s, %ldx\n",start+1,end+1,itemsList.items[j]->name,itemsList.items[j]->count);
      }
    }
  }
	printf("Nejprodavanejsi zbozi: prodano %ld kusu\n",count(itemsList,tracked));
}
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

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

int main(void){
	return 0;
}

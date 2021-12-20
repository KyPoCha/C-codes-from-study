#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* defining "MAX" for arrays of chars */
#define MAX 10000
/* global counter variable */
long cnt = 0;
/* comparing function for qsort() */
long cmp(const void * a, const void * b){
  long arg1 = *(const long *)a;
  long arg2 = *(const long *)b;

  if(arg1 < arg2) return 1;
  if(arg1 > arg2) return -1;
  return 0;
}

int main(void){

  char charArray[MAX];
  long k;
  char c;
  printf("Pocet kostek:\n");
  short input = scanf("%ld", &k);
  /* processing of entries */
  if(input != 1 || k <= 0){
    printf("Nespravny vstup.\n");
    return 1;
  }
  /* processing of numbers entries */
  printf("Velikosti:\n");
  long * array = (long*)calloc(k,sizeof(long));
  for(long i = 0; i < k; i++){
    if(scanf("%ld", &array[i]) != 1 || array[i] <= 0){
      scanf("%c", &c);
      if(c != ' ' || c != '\n'){
        printf("Nespravny vstup.\n");
        free(array);
        return 1;
      }
      printf("Nespravny vstup.\n");
      free(array);
      return 1;
    }
  }

  return 0;
}

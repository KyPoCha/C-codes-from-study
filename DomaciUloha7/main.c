#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* defining "MAX" for arrays of chars */
#define MAX 10000
/* global counter variable */
long cnt = 0;

/* recursive function of printing new sorted variants */
void printNumbers(long *array, long k, long len, char * charArray){
    char * chars = (char *)calloc(MAX, sizeof(chars));
    memcpy(chars, charArray, MAX);
    for(long i = k+1; i<len; i++){
        printf("%s, %ld\n", charArray, *(array+i));
        cnt++;
        snprintf(chars + strlen(chars), MAX - strlen(chars), ", %ld", *(array+i));
        printNumbers(array, i, len, chars);
        while(i < len-1 && *(array+i) == *(array+i+1)){
          i+=1;
        }
        memcpy(chars, charArray, MAX);
    }
    free(chars);
    return;
}

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

  /* qsort() for sorting valid array of numbers with function cmp() */
  qsort(array, k, sizeof(long),(int (*)(const void*, const void*))cmp);

  /* loop for printing variants of sorted arrays */
  for (long i = 0; i < k; ++i) {
        printf("%ld\n", *(array+i));
        cnt++;
        snprintf(charArray, MAX, "%ld", *(array+i));
        printNumbers(array, i, k, charArray);
        while(i < k-1 && *(array+i) == *(array+i+1)){
          i+=1;
        }
    }

  /* print global variable "cnt" that counts variants */
  printf("Celkem: %ld\n",cnt);
  return 0;
}

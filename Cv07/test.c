#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#endif /* __PROGTEST__ */

void printArray ( int array[], int arrayLen){

	for(int i = 0; i < arrayLen - 1;i++){
		printf("%d ",array[i]);
	}
	printf("%d\n",array[arrayLen - 1]);

}


void rotateArray ( int array [], int arrayLen, int rotateBy )
{
	printArray(array, arrayLen);

	int *parray = array;
	int el1;
	if(rotateBy >= 0){
		el1 = parray[rotateBy - 1];
	}

	if(rotateBy < 0){
		el1 = parray[1 + rotateBy];
	}

	int el2;

	for(int i = 1; i < arrayLen; ++i){
		el2 = parray[i];
		parray[i] = el1;
		el1 = el2;
	}

	parray[0] = el1;

	printArray(parray, arrayLen);

}

#ifndef __PROGTEST__
int identicalArrays ( const int a[], const int b[], int cnt )
{
  /* TODO: Your code here */
}
int main (int argc, char * argv [])
{
  int in0 []  = { 1, 2, 3, 4, 5 };
  int out0 [] = { 5, 1, 2, 3, 4 };

  int in1 []  = { 1, 2, 3, 4, 5 };
  int out1 [] = { 2, 3, 4, 5, 1 };

  int in2 []  = { 1, 2, 3, 4, 5, 6 };
  int out2 [] = { 4, 5, 6, 1, 2, 3 };

  int in3 []  = { 1, 2, 3, 4, 5, 6, 7 };
  int out3 [] = { 3, 4, 5, 6, 7, 1, 2 };

  int in4 []  = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int out4 [] = { 2, 3, 4, 5, 6, 7, 8, 9, 1 };

  rotateArray ( in0, 5, 1 );
 // assert ( identicalArrays ( in0, out0, 5 ) );
  rotateArray ( in1, 5, -1 );
 // assert ( identicalArrays ( in1, out1, 5 ) );
  rotateArray ( in2, 6, -3 );
 // assert ( identicalArrays ( in2, out2, 6 ) );
  rotateArray ( in3, 7, 12 );
 // assert ( identicalArrays ( in3, out3, 7 ) );
  rotateArray ( in4, 9, -100 );
 //assert ( identicalArrays ( in4, out4, 9 ) );*/
  return 0;
}
#endif /* __PROGTEST__ */

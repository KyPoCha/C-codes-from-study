#include<stdio.h>
#include<math.h>
int main(void){
	double x,y;
	char f,r;
	printf("Zadejte vzorec:\n");
	scanf("%lg %c %lg %c",&x,&f,&y,&r);
	if(r!='='){
	printf("Nespravny vstup.\n");
	}
	else{
		switch(f){
			case '+':
				printf("%lg\n",(double)(x+y));
				break;
			case '-':
				printf("%lg\n",(double)(x-y));
				break;
			case '*':
				printf("%lg\n",(double)(x*y));
				break;
			case '/':
				if(y==0){
				printf("Nespravny vstup.\n");
				}
				else
				{
				printf("%lg\n",(double)(x/y));
				}
				/*if((char*)((double)(x)/y) == "inf"){
					printf("Nespravny vstup.\n");
				}else{
				printf("%.1f\n",(double)(x)/y);
				}*/
				break;
			default : printf("Nespravny vstup.\n");
		}
	}
	return 0;

}

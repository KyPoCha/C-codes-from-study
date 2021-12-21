#include<stdio.h>
int pocet,len;

void printSachy(int a, int length ,int cislo){
	for(int x=0; x < length * cislo ;x++){
			if((a/cislo)%2==0){
					if((x/cislo)%2==0){
							printf(" ");
					}
					else{
							printf("X");
					}
			}
			else{
					if((x/cislo)%2==0){
							printf("X");
					}
					else{
							printf(" ");
					}
			}
	}
}

int main()
{
    printf("Zadejte pocet poli:\n");
    if(scanf("%d",&len) != 1 || len <= 0){
        printf("Nespravny vstup.\n");
        return 1;
    }
    printf("Zadejte velikost pole:\n");
    if(scanf("%d",&pocet) != 1 || pocet <=0){
        printf("Nespravny vstup.\n");
        return 1;
    }



    printf("+");
    for(int i=1;i<=len*pocet;i++){
        printf("-");
    }
    printf("+\n");


    for(int a=0; a < len*pocet;a++){
        printf("|");
				printSachy(a,len,pocet);
        printf("|\n");
    }


    printf("+");
    for(int i=1;i<=len*pocet;i++){
        printf("-");
    }
    printf("+\n");

return 0;

}

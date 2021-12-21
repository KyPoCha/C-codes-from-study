#include<stdio.h>
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




return 0;

}

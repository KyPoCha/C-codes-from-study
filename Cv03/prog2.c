#include<stdio.h>

int main(void){
	int h1,m1,s1,ms1,h2,m2,s2,ms2,h,m,s,ms;
	char a,b,c,d,e,f;
	printf("Zadejte cas t1:\n");
	scanf(" %d %c %d %c %d %c %d",&h1,&a,&m1,&b,&s1,&c,&ms1);
	if(c == '.' || h1<0 || m1<0 || s1<0 || ms1<0){
	              printf("Nespravny vstup.\n");
	}
	else{
		printf("Zadejte cas t2:\n");
		scanf(" %d %c %d %c %d %c %d",&h2,&d,&m2,&e,&s2,&f,&ms2);
		if(f == '.'){
			printf("Nespravny vstup.\n");
		}
	}
	return 0;
}

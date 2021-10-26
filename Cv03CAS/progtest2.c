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
		else{

			if(h1 > h2 || h1>23 || h2>23 || h1<0 || h2<0 || m1<0 || m2<0 || s1<0 || s2<0 || ms1<0 || ms2<0){
			printf("Nespravny vstup.\n");
			}
			else if((h1==h2 && m2>m1) || m2==60 || m1==60 || s1==60 || s2==60 || ms1==1000 || ms2==1000){
			printf("Nespravny vstup.\n");
			}
			else{
				ms = ms2 - ms1;
				s = s2 - s1;
				m = m2 - m1;
				h = h2 - h1;
				if(ms<0){
					s -= 1;
					ms +=1000;
				}
				if(s<0){
					m -= 1;
					s +=60;
				}
				if(m<0){
					h -=1;
					m +=60;
				}
				if(h==1 && m!=0){
					h = 0;
				}


				if(h>=10){
					printf("Doba: %d:%.2d:%.2d,%.3d\n",h,m,s,ms);
				}
				else if(h<0){
					printf("Nespravny vstup.\n");
				}
				else{
					printf("Doba:  %d:%.2d:%.2d,%.3d\n",h,m,s,ms);
				}
			}
		}
	}
	return 0;
}

#include<stdio.h>
#include<math.h>
int main(void){
        double x,y;
        char f,r;
        printf("Zadejte vzorec:\n");
                switch(f){
                        case '+':
                                printf("%d\n",(int)(rint(x+y)));
                                break;
                        case '-':
                                printf("%d\n",(int)(rint(x-y)));
                                break;
                        case '*':
                                printf("%g\n",x*y);
                                break;
                        case '/':
                                if(y==0){
                                printf("Nespravny vstup.\n");
                                }
                                else
                                {
                                printf("%.f\n",(double)(x)/y);
                                }
                                break;
                        default : printf("Nespravny vstup.\n");
                }
        }
        return 0;

}

#include <stdio.h>

int main()
{


    int num1=0,num2=0,num3=0;

    int i=100,sum=0;
    
    while(i<1000)
    {

        num1=i/100;
        num2=i%100;
        num3=num2%10;
        num2=num2/10;

        /*num1=i/100;
        num2=i/10;
        num3=i%10;*/
        //printf("target=%d,num1=%d,num2=%d,num3=%d\n",i,num1,num2,num3);

        sum=(num1*num1*num1)+(num2*num2*num2)+(num3*num3*num3);
        if (sum==i)
        {
            /* code */
            printf("%d  ",i);
        }
        
        i++;

    }
    return 0;
}

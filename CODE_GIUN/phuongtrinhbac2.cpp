#include<stdio.h>
#include <iostream>
#include<math.h>// sd ham pow()

using namespace std;
float a,b,c,x1,x2,d;
int main(){

    printf("Nhap he so  a,b,c :");
    scanf("%f%f%f",&a,&b,&c);// so thuc
    d=pow(b,2)-4*a*c;
    if (d>0){
        x1=(-b+sqrt(d))/(2*a);
        x2=(-b-sqrt(d))/(2*a);
        printf ("\n pt co nghiem phan biet ");
        printf ("\n x1=%0.2f",x1);
        printf ("\n x2=%0.2f",x2);
    }
    else if (d==0)
              printf("\n Phuong trinh co nghiem kep x= %0.2f",-b/2*a);
         else printf("\n Pt vo nghiem ");
    return 0;

}

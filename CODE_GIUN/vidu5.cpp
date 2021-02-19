#include<stdio.h>
float diem;
int main(){
    printf(" Diem :");
    scanf("%f",&diem);
    if (diem<3.5) printf("KEM");
    else if (diem <5 ) printf("YEU");
    else if (diem <6.5) printf("TB");
    else if (diem < 8) printf("KHA");
    else printf("GIOI");
    return 0;
}

#include<stdio.h>
 int main(){
 int thang ,nam ;
 printf("\n Nhap thang "); scanf("%d",&thang);
 printf("\n Nhap nam "); scanf("%d",&nam);
 switch(thang){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        printf("thang co 31 ngay");
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        printf(" Thang co 30 ngay");
        break;
    case 2:
        if (( nam%4==0 &&  nam%100 !=0)  ||( nam% 400==0))

            printf(" Thang co 29 ngay");
        else
            printf(" Thang co 28 ngay");
        break;
}
 return 0;
}

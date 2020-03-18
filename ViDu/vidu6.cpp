#include<stdio.h>
int so;
int main(){
    printf("Nhap vao 1 so : ");
    scanf("%d",&so);
    switch (so){
        case 1:
            printf("Mot");
            break;
        case 2:
            printf("Hai");
            break;
        case 3:
            printf("Ba ");
            break;
        case 4:
            printf("Tu ");
            break;
        case 5:
            printf("Nam ");
        default:
            printf(" Khong dung yeu cau");
    }
    return 0;
}

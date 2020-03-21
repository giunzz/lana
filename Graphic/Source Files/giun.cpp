#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
void bong(int x, int y, int r, int mau)
{
  setcolor(mau);
  setfillstyle(1,mau);
  pieslice(x,y,0,360,r);
}
int main()
{
int driver=0, mode = 0, maloi;
initgraph(&driver,&mode,"C:/TC/BGI");
if ( (maloi=graphresult()) !=0 )
{
  printf("khong the khoi dong do hoa \n");
  printf("ma loi : %d \nnguyen nhan loi %s ",maloi, grapherrormsg(maloi) );
  getch();
  exit(1);
}
setcolor(RED);
setfillstyle(1,RED);
pieslice(50,50,0,360,50);
char *p;
int n= imagesize(0,0,100,100);
p=(char *)malloc(n);
getimage(0,0,100,100,p);
getch();
cleardevice();
randomize();
for (int i=0;i<=300; i++)
{
  int k=random(16);
  setcolor(k);
  setfillstyle(1,k);
  pieslice(random(640), random(480), 0,360,2);
}
int x=random(640-100), y=random(480-100),x1,y1;
do{
  putimage(x,y,p,1); /* in bóng màu d? v?i phép XOR (v? bóng trên màn hình ch? nào dã có màu l?n tru?c thì màu dó du?c in dè lên bóng do ta s? d?ng xor); */
  delay(100); // t?m d?ng
  putimage(x,y,p,1); /* in v?i phép XOR m?t l?n n?a (xoá bóng v?a in trên màn hình do bóng l?n tru?c in là màu d? l?i in l?i màu d? nhung theo phép xor thì 1 XOR 1 =0 t?c là 2 màu d? dè lên nhau s? ra màu n?n cu tru?c dó) */
  do{ /* m?c dích c?a vòng do while này nh?m không cho qu? bóng hi?n th? ngoài vùng màn hình (0,0,540,340) và t?o giá tr? to? d? ng?u nhiên m?i cho bóng */
  x1 =x+random(50) -25;
  y1 =y+random(50) -25;
 } while ( (x1<0) || ( x1> (639-100) ) || (y1<0) || (y1>(439-100) ) ) ;

x=x1;
y=y1;
}while(!kbhit()) ;
getch();
closegraph();
}

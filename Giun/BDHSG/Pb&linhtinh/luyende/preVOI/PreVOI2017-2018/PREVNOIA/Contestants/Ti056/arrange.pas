Const fi='arrange.inp';
      fo='arrange.out';
type mmc=array[0..100000] of longint;
Var f,g:text;
    n:longint;
    s,kq:int64;
    a:array[0..100000] of longint;
Procedure swap(var a,b:longint);
 Var tg:longint;
  Begin
        tg:=a;
        a:=b;
        b:=tg;
  ENd;
Procedure qsort(var ax:mmc);
 Procedure sort(l,r:longint);
  Var i,j,tg:longint;
   Begin
         i:=l;
         j:=r;
         tg:=a[(l+r) div 2];
         repeat
                WHile ax[i]<tg do inc(i);
                While ax[j]>tg do dec(j);
                if not(i>j) then
                  Begin
                        swap(ax[i],ax[j]);
                        inc(i);
                        dec(j);
                  End;
         Until i>j;
         if i<r then sort(i,r);
         if l<j then sort(l,j);
   End;
 Begin
       sort(1,n);
 ENd;
Procedure inp;
var i:longint;
 Begin
       Assign(f,fi);
       reset(f);
       Readln(f,n);
       For i:=1 to n do
          Begin
                read(f,a[i]);
                s:=s+a[i];
          End;
       Close(f);
 ENd;
Procedure sub1;
var i:longint;
    target:int64;
 Begin
       target:=s div n;
       for i:=1 to n do
          if a[i]<target then
            kq:=kq+target-a[i];
 End;
Procedure sub2;
var i,t:longint;
 Begin
       qsort(a);
       While a[n]-a[1]>1 do
          Begin
                t:=(a[n]-a[1]) div 2;
                kq:=kq+t;
                a[n]:=a[n]-t;
                a[1]:=a[1]+t;
                for i:=n downto 1 do
                   if a[i]<a[i-1] then
                     Begin
                            swap(a[i-1],a[i]);
                     End else break;
                For i:=1 to n do
                   if a[i]>a[i+1] then
                     Begin
                            swap(a[i],a[i+1]);
                     End else break;
          End;
 End;
Procedure output;
 Begin
       Assign(g,fo);
       Rewrite(g);
       Writeln(g,kq);
       Close(g);
 End;
Begin
      inp;
      if s mod n=0 then sub1 else sub2;
      output;
ENd.













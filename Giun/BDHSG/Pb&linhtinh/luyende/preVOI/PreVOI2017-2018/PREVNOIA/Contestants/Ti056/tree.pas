Const fi='tree.inp';
      fo='tree.out';
type mmc=array[0..5001] of int64;
Var f,g:text;
    a,d,c,cs,x,y,head:mmc;
    best:int64;
    n:longint;
    kt:array[0..10000] of boolean;
    ke:array[0..10000] of int64;
Procedure swap(var a,b:int64);
var tg:int64;
 Begin
       tg:=a;
       a:=b;
       b:=tg;
 End;
Procedure qsort(var ax:mmc);
 Procedure sort(l,r:longint);
  var i,j:longint;
      tg:int64;
   Begin
          i:=l;
          j:=r;
          tg:=ax[(l+r) div 2];
          Repeat
                 WHile ax[i]<tg do inc(i);
                 While ax[j]>tg do dec(j);
                 if not (i>j) then
                   Begin
                          swap(ax[i],ax[j]);
                          swap(cs[i],cs[j]);
                          inc(i);
                          dec(j);
                   ENd;
          Until i>j;
          if i<r then sort(i,r);
          if l<j then sort(l,j);
   End;
 Begin
       sort(1,n);
 End;
Procedure inp;
var i:longint;
 Begin
       Assign(f,fi);
       reset(f);
       readln(f,n);
       For i:=1 to n do read(f,a[i]);
       Readln(f);
       For i:=1 to n-1 do
          Begin
                read(f,x[i],y[i]);
                cs[i]:=i;
                inc(head[x[i]]);
                inc(c[x[i]]);
          End;
       cs[n]:=n;
       For i:=1 to n+1 do
          head[i]:=head[i-1]+head[i];
       For i:=1 to n-1 do
          begin
                ke[head[x[i]]]:=y[i];
                dec(head[x[i]]);
          End;
       qsort(c);
       Close(f);
 End;
Procedure cacu(i:longint);
var j:longint;
 Begin
       for j:=head[i]+1 to head[i+1] do
          if kt[ke[j]]=false then
            Begin
                  cacu(ke[j]);
                  d[i]:=d[i]+d[ke[j]];
            End else d[i]:=d[i]+d[ke[j]];
       kt[i]:=true;
 End;
Procedure tinh;
var i:longint;
    kq:int64;
 Begin
        cacu(1);
        kq:=0;
        for i:=1 to n do
           kq:=kq+abs(a[i]-d[i]);
        if kq<best then best:=kq;
 End;

Procedure tree(i:longint);
 Begin
       if c[i]>0 then
         Begin
               tinh;
               exit;
         ENd;
       d[cs[i]]:=1;
       kt[cs[i]]:=true;
       tree(i+1);
       d[cs[i]]:=0;
       tree(i+1);
 ENd;
Procedure output;
 Begin
       assign(g,fo);
       rewrite(g);
       write(g,best);
       close(g);
 End;
Begin
       inp;
       best:=high(int64);
       tree(1);
       output;
End.







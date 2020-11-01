uses math;
const fi='gifts.inp';
      fo='gifts.out';
var a,m:array[0..100000] of longint;
    i,n,kq,x,k,j:longint;
    f:text;
begin
     assign(f,fi);reset(f);
     readln(f,n,k);
     for i:=1 to n do read(f,a[i]);
     for i:=1 to k do m[k]:=m[k]+a[i];
     kq:=maxlongint;
     for i:=k+1 to n do m[i]:=m[i-1]-a[i-k]+a[i];
     for i:=k to n do
     begin
          x:=0;
          for j:=1 to i-k do
              if x<m[j] then x:=m[j];
          for j:=i+k to n do
              if x<m[j] then x:=m[j];
          if x<kq then kq:=x;
     end;
     assign(f,fo);rewrite(f);
     {for i:=1 to n do write(f,m[i],' ');
     writeln(f);}
     writeln(f,kq);
     close(f);
end.
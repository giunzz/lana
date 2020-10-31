uses math;
const fi='arrange.inp';
      fo='arrange.out';
var a,b:array[0..100000] of longint;
    i,n,s,x1,x2,k,sl,j,c,kq:longint;
    f:text;
procedure sub1;
begin
     x1:=s div n;
     for i:=1 to n do
         if a[i]<x1 then
         begin
              inc(sl);
              b[sl]:=i;
         end;
     j:=1;
     kq:=0;
     for i:=1 to n do
         while a[i]>x1 do
         begin
              c:=max(a[i]-(x1-a[b[j]]),x1);
              kq:=kq+(a[i]-c)*(i-b[j]);
              a[b[j]]:=a[b[j]]+a[i]-c;
              a[i]:=c;
              if a[b[j]]=x1 then inc(j);
         end;
     for i:=1 to sl do kq:=kq+x1-a[b[i]];
end;
procedure sub2;
begin
     x1:=s div n;
     x2:=x1+1;
     for i:=1 to n do
         if a[i]<=x1 then
         begin
              inc(sl);
              b[sl]:=i;
         end;
     j:=1;
     kq:=0;
     for i:=1 to n do
         while a[i]>x2 do
         begin
              c:=max(a[i]-(x2-a[b[j]]),x2);
              kq:=kq+(a[i]-c)*(i-b[j]);
              a[b[j]]:=a[b[j]]+a[i]-c;
              a[i]:=c;
              if a[b[j]]=x2 then inc(j);
         end;
     for i:=1 to sl do kq:=kq+x1-a[b[i]];
end;
begin
     assign(f,fi);reset(f);
     readln(f,n);
     s:=0;
     for i:=1 to n do
     begin
          read(f,a[i]);
          s:=s+a[i];
     end;
     if s mod n=0 then sub1 else sub2;
     assign(f,fo);rewrite(f);
     writeln(f,kq);
     close(f);
end.

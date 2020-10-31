uses math;
const fi='arrange.inp';
      fo='arrange.out';
var a,b:array[0..1000000] of longint;
    i,n,s,x1,x2,k,sl,j,c,s1:longint;
    kq:int64;
    kt1:array[0..1000000] of boolean;
    kt:boolean;
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
     for i:=1 to n do kt1[i]:=true;
     x1:=s div n;
     x2:=x1+1;
     s1:=x1*n;
     for i:=1 to n do b[i]:=x1;
     j:=n;
     while s1<>s do
     begin
          s1:=s1+1;
          b[j]:=x2;
          dec(j);
     end;
     for i:=1 to n do
     begin
          kt:=true;
          for j:=1 to n do
              if (kt1[j]) and (a[j]=b[i]) then
              begin
                   kt1[j]:=false;
                   kt:=false;
                   break;
              end;
          if kt then
          begin
               for j:=1 to n do
                   if (kt1[j]) and (a[j]<b[i]) then break;
               for k:=1 to n do
                   if (kt1[k]) and (a[k]>x2) then break;
               if (k=n) and (a[k]<=x2) then
               begin
                    for k:=1 to n do
                        if (kt1[k]) and (a[k]>=x2) then break;
               end;
               kq:=kq+(abs(k-j))*abs(b[i]-a[j]);
               a[k]:=a[k]-(b[i]-a[j]);
               kt1[j]:=false;
          end;
     end;
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

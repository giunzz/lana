const fi='tree.inp';
      fo='tree.out';
var a,cha,la,b:array[0..6000] of longint;
    kt:array[0..6000] of boolean;
    i,n,sl,kq,x,y:longint;
    f:text;
procedure up(x,y:longint);
begin
     b[x]:=b[x]+b[y];
     if x<>1 then up(cha[x],y);
end;
procedure try(i:longint);
var j,kq1,k:longint;
begin
     for j:=0 to 1 do
     begin
          b[la[i]]:=j;
          if i<sl then try(i+1) else
          begin
               for k:=1 to n do
                   if kt[k] then b[k]:=0;
               for k:=1 to sl do up(cha[la[k]],la[k]);
               kq1:=0;
               for k:=1 to n do kq1:=kq1+abs(a[k]-b[k]);
               if kq>kq1 then kq:=kq1;
          end;
     end;
end;
begin
     assign(f,fi);reset(f);
     readln(f,n);
     for i:=1 to n do read(f,a[i]);
     readln(f);
     for i:=1 to n-1 do
     begin
          readln(f,x,y);
          cha[y]:=x;
          kt[x]:=true;
     end;
     sl:=0;
     for i:=1 to n do
         if not kt[i] then
         begin
              inc(sl);
              la[sl]:=i;
         end;
     kq:=maxlongint;
     try(1);
     assign(f,fo);rewrite(f);
     writeln(f,kq);
     close(f);
end.

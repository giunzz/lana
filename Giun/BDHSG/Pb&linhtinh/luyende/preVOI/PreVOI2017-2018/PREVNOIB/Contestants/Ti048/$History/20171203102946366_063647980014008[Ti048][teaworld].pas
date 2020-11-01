uses math;
const  fi='TEAWORLD.INP';
       fo='TEAWORLD.OUT';
var  n,m,k,kq,u,v,c:longint;
     x,y,z,r,e,d:array[0..1000000] of longint;
     xn,yn,zn,xx:array[0..1000000] of longint;
     a:array[0..30,0..1000000] of longint;
     f:array[0..1000000] of boolean;
     s:ansistring;
     ok:boolean;
     a1,b1,c1:longint;


function check(x,y,u,v:longint):boolean;
begin
     if (x>=u) and (y<=v) then exit(false);
     if y<u then exit(false);
     if x>v then exit(false);
     exit(true);
end;

procedure inxau;
var i,j:longint;
begin
     u:=0;
     for i:=1 to n do if xx[i]=1 then
     begin
          for j:=1 to d[i] do
          if not f[a[i,j]] then
          begin
               f[a[i,j]]:=true;
               inc(u);
          end;
     end;

     c:=0;
     for i:=1 to n do if xx[i]=1 then
     begin
          c:=c+e[i];
          for j:=1 to d[i] do if f[a[i,j]] then f[a[i,j]]:=false;
     end;

     if u<=k then kq:=max(kq,c);
end;

procedure try(i:longint);
var j:byte;
begin
     for j:=0 to 1 do
     begin
          xx[i]:=j;
          if i=n then inxau else try(i+1);
     end;
end;

procedure inkq;
var i,j:longint;
begin
     assign(input,fi);
     reset(input);
     assign(output,fo);
     rewrite(output);
     readln(m,n,k);
     for i:=1 to m do read(x[i],y[i],z[i],r[i]);
     for i:=1 to n do read(xn[i],yn[i],zn[i],e[i]);
     read(x[0],y[0],z[0]);

     for i:=1 to n do
     begin
          a1:=y[0] - yn[i];
          for j:=1 to m do
          begin
               u:=x[j]-r[j];
               v:=x[j]+r[j];
               ok:=check(min(x[0],xn[i]),max(x[0],xn[i]),u,v);
               if ok then begin inc(d[i]);  a[i,d[i]]:=j; end;
          end;
     end;

     kq:=0;
     try(1);
     writeln(kq);
end;

begin
inkq;
end.


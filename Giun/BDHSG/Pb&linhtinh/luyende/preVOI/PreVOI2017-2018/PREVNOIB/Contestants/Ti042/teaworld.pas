uses math;
const  fi='teaworld.inp';
       fo='teaworld.out';
       base=1000000000;

var  n,m,i,j,k,kq,u,v,c:longint;
     x,y,z,r,e,d:array[0..1000000] of longint;
     xn,yn,zn,xx:array[0..1000000] of longint;
     a:array[0..20,0..10000] of longint;
     f:array[0..1000000] of boolean;
     s:ansistring;
     ok:boolean;
     a1,b1,c1:longint;

procedure openf;
begin
     assign(input,fi);  assign(output,fo);
     reset(input);      rewrite(output);
end;

procedure closef;
begin
     close(input);  close(output);
end;

function kc(x,y,u,v:longint):longint;
begin
     exit( sqr(x-u) + sqr(y-v) );
end;

function inside(u,v:longint):boolean;
begin
     exit(kc(u,v,x[i],y[i])<=sqr(r[i]));
end;

function check(xx,yy,u,v:longint):boolean;
begin
     if inside(xx,yy) and inside(u,v) then exit(false);
     if inside(xx,yy) and not inside(u,v) then exit(true);
     if not inside(xx,yy) and inside(u,v) then exit(true);
     if int64(sqr( int64(a1*x[i] + b1*y[i] +c1) )) <= int64(int64(sqr(r[i])))*int64((a1*a1 + b1*b1)) then exit(true) else exit(false);
     exit(false);
end;

procedure inxau;
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
begin
     readln(m,n,k);
     for i:=1 to m do read(x[i],y[i],z[i],r[i]);
     for i:=1 to n do read(xn[i],yn[i],zn[i],e[i]);
     read(x[0],y[0],z[0]);

     for i:=1 to n do
     begin
          a1:=y[0] - yn[i];
          b1:=xn[i] - x[0];
          c1:= - (a1*x[0] + b1*y[0]);
          for j:=1 to m do
          begin

               ok:=check(x[0],y[0],xn[i],yn[i]);
               if ok then begin inc(d[i]);  a[i,d[i]]:=j; end;
          end;
     end;

     kq:=0;
     try(1);
     writeln(kq);
end;

BEGIN
     openf;
     inkq;
     closef;
END.

const fi='ROBOTS.inp';
      fo='ROBOTS.out';
var f:array[-2002..2002,-2002..2002] of boolean;
    d,u,v:array[0..5000000] of longint;
    a,b:array[0..10000] of longint;
    p:array[1..4] of longint=(-1,0,0,1);
    q:array[1..4] of longint=(0,-1,1,0);
    kq,n,m,uu,vv:longint;
procedure enter;
var i:longint;
   begin
   assign(input,fi); reset(input);
   read(n,m);
   for i:=1 to n do read(a[i],b[i]);
   read(uu,vv);
   close(input);
   End;
function ktt(x,y:longint):boolean;
   begin
   if (abs(x)<=1000)and(abs(y)<=1000) then exit(true);
   exit(false);
   End;
Function kt(x,y:longint):boolean;
   begin
   if abs(x-uu)+abs(y-vv)<=m then exit(true);
   exit(false);
   End;
Procedure main;
var l,r,i,x,y,xx,yy,tg:longint;
   begin
   l:=1; r:=0;
   For i:=1 to n do
      begin
      inc(r); u[r]:=a[i]; v[r]:=b[i]; d[r]:=0; f[a[i],b[i]]:=true;
      End;
   While l<r do
      begin
      x:=u[l]; y:=v[l]; tg:=d[l]; inc(l);
      for i:=1 to 4 do
         begin
         xx:=x+p[i]; yy:=y+q[i];
         if (ktt(xx,yy))and(f[xx,yy]=false) then
            begin
            inc(r); u[r]:=xx; v[r]:=yy; f[xx,yy]:=true; d[r]:=tg+1;
            if kt(xx,yy) then kq:=tg+1;
            End;
         End;
      End;
   End;
procedure print;
    begin
    assign(output,fo); rewrite(output);
    write(kq);
    close(output);
    End;
begin
enter;
main;
print;
end.

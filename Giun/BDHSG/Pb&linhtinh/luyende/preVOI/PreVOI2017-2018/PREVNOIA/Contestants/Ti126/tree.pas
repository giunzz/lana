uses math;
const fi='tree.inp';
      fo='tree.out';
var t,kq:int64;
    i,n,m,x,y:longint;
    a,b,con1,con2,socon,la:array[1..1000000] of longint;


function tong(i:longint):longint;
var u:int64;
begin
u:=0;
if socon[i]=0 then
   begin
   t:=t+abs(b[i]-a[i]);
   exit(b[i]);
   end;
if socon[i]=1 then
   begin
   u:=u+tong(con1[i]);
   t:=t+abs(u-a[i]);
   exit(u);
   end;
if socon[i]=2 then
   begin
   u:=u+tong(con1[i])+tong(con2[i]);
   t:=t+abs(u-a[i]);
   exit(u);
   end;
end;

procedure try(i:longint);
var j:longint;
    vl:int64;
begin
for j:=0 to 1 do
    begin
    b[la[i]]:=j;
    if i<m then try(i+1)
    else
       begin
       t:=0;
       vl:=tong(1);
       kq:=min(kq,t);
       end;
    end;
end;

begin

assign(input,fi);
reset(input);
assign(output,fo);
rewrite(output);
read(n);
for i:=1 to n do read(a[i]);
for i:=1 to n-1 do
    begin
    read(x,y);
    socon[x]:=socon[x]+1;
    if con1[x]=0 then con1[x]:=y
    else con2[x]:=y;
    end;
for i:=2 to n do
    if socon[i]=0 then
       begin
       m:=m+1;
       la[m]:=i;
       end;
kq:=high(int64);
if m>=1 then try(1);
write(kq);
close(input);
close(output);
end.

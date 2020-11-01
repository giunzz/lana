uses    math;
const   fi='minsum.inp';
        fo='minsum.out';
var     f,f1:text;
        a,b,tg,aaa,bbb,t,i:longint;
        ktra:array[0..10000000] of longint;
(*=================================*)
procedure eratos;

var i,j : longint;
begin
ktra[1]:=1;
for i:=2 to 1000000 div 2 do if ktra[i]=0 then for j:=2 to 1000000 div i do ktra[i*j]:=1;
end;
(*=================================*)
function rutgon(x:longint):longint;
var j:longint;
Begin
j:=2;
while j<8 do
 begin
  if x mod (j*j)=0 then begin x:=x div (j*j); j:=2; end
                   else inc(j);
 end;
exit(x);
End;
(*=================================*)
function gcd(x,y:longint):longint;
var k:longint;
Begin
for k:=x downto 1 do if (x mod k=0) and (y mod k=0) then exit(k);
End;
(*=================================*)
procedure trong(a,b:longint);
var u,tg,aa,bb:longint;
Begin
a:=rutgon(a);
b:=rutgon(b);
while gcd(a,b)<>1 do
 begin
  u:=gcd(a,b);
  a:=a div u;
  b:=b div u;
 end;
if (ktra[a]=0) and (ktra[b]=0) then begin aaa:=a; bbb:=b; exit; end;
tg:=max(a,b);
a:=min(a,b);
b:=tg;
tg:=a+b;
for u:=1 to trunc(sqrt(b))+1 do if b mod u=0 then
 begin
  aa:=a*u;
  bb:=b div u;
  if aa+bb<tg then begin tg:=aa+bb; aaa:=aa; bbb:=bb; end;
 end;
End;
(*=================================*)
BEGIN
assign(f,fi);
reset(f);
assign(f1,fo);
rewrite(f1);
eratos;
ktra[1]:=0;
read(f,t);
for i:=1 to t do
 begin
  read(f,a,b);
  trong(min(a,b),max(a,b));
  writeln(f1,aaa,' ',bbb);
 end;
close(f);
close(f1);
END.

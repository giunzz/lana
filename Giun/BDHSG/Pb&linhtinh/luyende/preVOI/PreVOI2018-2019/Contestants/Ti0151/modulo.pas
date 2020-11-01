const fi='modulo.inp';
    fo='modulo.out';
var b,c:array[0..1000] of int64;
    aa,bb,n,m,tg,s,ss,kq,k,t,d:int64;
    kt:boolean;
Procedure enter;
   begin
   assign(input,fi); reset(input);
   read(aa,bb); read(n,k);
   close(input);
   End;
procedure try(x:longint);
   begin
   if (kt)or(d>5000000) then exit;
   inc(d);
   if x>n then
      begin
      if ss*(bb-aa) mod m=t then kt:=true;
      Exit;
      End;
   c[x]:=aa;
   try(x+1);
   if (kt)or(d>5000000) then exit;
   c[x]:=bb;
   ss:=ss+b[x];
   try(x+1);
   ss:=ss-b[x];
   End;
procedure main;
var i:longint;
   begin
   m:=2;
   for i:=2 to n do m:=m*2;
   b[1]:=1;
   for i:=2 to n do b[i]:=(b[i-1]*10) mod m;
   s:=0; for i:=1 to n do s:=(s+b[i]) mod m;
   if aa>bb then begin tg:=aa; aa:=bb; bb:=tg; End;
   tg:=(aa*s) mod m;
   if tg<=k then t:=k-tg else t:=(m+k)-tg;
   kq:=-1; d:=1; kt:=false;
   ss:=0; try(1);
   End;
Procedure print;
var i:longint;
   begin
   assign(output,fo); rewrite(output);
   if kt then
       begin
       for i:=n downto 1 do write(c[i]);
       End
   else write(-1);
   close(output);
   End;
begin
enter;
main;
print;
End.

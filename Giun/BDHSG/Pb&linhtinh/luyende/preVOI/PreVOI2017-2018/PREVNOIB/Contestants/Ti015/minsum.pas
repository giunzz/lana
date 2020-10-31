uses math;
var a,b,res,res1:int64;
    dem,h,t:longint;
    prime:array[0..1000000] of longint;
    nt:array[0..1000000] of int64;
function gcd(a,b:int64):int64;
begin
 if b=0 then exit(a);
 exit(gcd(b,a mod b));
end;
procedure snt(n:longint);
var i,j:longint;
begin
 for i:=2 to trunc(sqrt(n)) do
  if prime[i]=0 then
   begin
    j:=i*i;
    while j<=n do
     begin
      prime[j]:=1;
      j:=j+i;
     end;
   end;
 for i:=2 to n do
  if prime[i]=0 then
   begin
    inc(dem);
    nt[dem]:=i;
   end;
end;
procedure nhap;
var i,pp:longint; tmp:int64;
begin
 read(a,b);
 tmp:=gcd(A,b);
 a:=a div tmp; b:=b div tmp;   res:=1; res1:=1;
 for i:=1 to dem do
   begin
    pp:=0;
    while a mod nt[i]=0 do
     begin
      inc(pp);
      a:=a div nt[i];
     end;
    if pp mod 2=1 then res:=res*nt[i];
    pp:=0;
    while b mod nt[i]=0 do
     begin
      inc(pp);
      b:=b div nt[i];
     end;
    if pp mod 2=1 then res1:=res1*nt[i];
   end;
 if a<>1 then res:=res*a;
 if b<>1 then res1:=res1*b;
 writeln(Res,' ',res1);
end;
begin
 assign(input,'minsum.inp');reset(input);
 assign(output,'minsum.out');rewrite(output);
 snt(32000);
 read(t);
 for h:=1 to t do
  begin
   nhap;
  end;
 close(input); close(output);
end.
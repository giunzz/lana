const   fi='MODULO.INP';
        fo='MODULO.OUT';
var
a,b,n:longint;
k,m:int64;
t:array[1..2] of integer;
f:array[0..64] of longint;
s:array[0..64] of string;
Procedure inp;
 begin
 assign(input,fi);reset(input);
 assign(output,fo);rewrite(output);
 readln(a,b);
 t[1]:=a;t[2]:=b;
 read(n,k);
 close(input);
 end;
Function lt(a,b:longint):int64;
var tg:int64;
 begin
 if b=1 then exit(a);
 tg:=lt(a,b div 2);
 if b mod 2=0 then exit(tg*tg)
 else exit(tg*tg*a);
 end;
Function tinh(x:longint):int64;
var j:longint;st:string;
 begin
 if x>n then
   if f[x-1] mod m=k then begin write(s[x-1]);halt;end else exit;
 For j:=1 to 2 do
 begin
 str(t[j],st);
 s[x]:=s[x-1]+st;
 f[x]:=((((f[x-1] mod m)*10) mod m)+t[j]) mod m;
 tinh(x+1);
 end;
 exit(f[x]);
 end;
Procedure main;
var i,j:longint;
 begin
 inp;
 m:=lt(2,n);
 For i:=1 to n do s[i]:='';
 fillchar(f,sizeof(f),0);
 tinh(1);
 write(-1);
 end;
BEGIN
main;
END.

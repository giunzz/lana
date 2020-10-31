const   fi='LIONDANCE.INP';
        FO='LIONDANCE.OUT';
var
n,k:longint;
a,b,c:array[0..4001] of longint;
F,d:array[0..4001,0..4001] of longint;
Procedure inp;
var i:longint;
 begin
 assign(input,fi);reset(input);
 assign(output,fo);rewrite(output);
 read(n,k);
 For i:=1 to n do read(a[i]);
 For i:=1 to n do read(b[i]);
 end;
Function max(a,b:longint):longint;
 begin
 If a>=b then exit(a);
 exit(b);
 end;
PRocedure tv(x,y:longint);
 begin
 If (x<=0) or (y<=0) then exit;
 if f[x,y]=F[x-1,y-1]+1 then begin tv(x-1,y-1);write(a[x],' ');exit;end;
 if f[x,y]=F[x-1,y] then begin tv(x-1,y);exit;end;
 if f[x,y]=F[x,y-1] then begin tv(x,y-1);exit;end;
 end;
Procedure main;
var i,j:longint;
 begin
 For i:=1 to n do
 For j:=1 to n do
  IF (a[i]=b[j]) and ((abs(c[F[i-1,j-1]]-a[i])<=k) or (F[i-1,j-1]=0))  and (a[i]>c[f[i,j]]) then
  begin
   F[i,j]:=F[i-1,j-1]+1;
   c[F[i,j]]:=A[i];
  end
  else F[i,j]:=max(f[i-1,j],F[i,j-1]);
 writeln(f[n,n]);
 For i:=1 to F[n,n] do write(c[i],' ');
 end;
BEGIN
inp;
main;
END.

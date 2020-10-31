uses math;
const   fi='TABLE.INP';
        fo='TABLE.OUT';
type mn=record
     x,y:longint;
     end;
var
tr:array[0..301,0..301] of mn;
a:array[0..301,0..301] of longint;
F:array[0..301,0..301] of int64;
n,m,k:longint;
Procedure inp;
var i,j:longint;
 begin
 assign(input,fi);reset(input);
 assign(output,fo);rewrite(output);
 read(n,m,k);
 For i:=1 to n do
 For j:=1 to m do read(a[i,j]);
 end;
Procedure xuli;
var i,j,tt,u,v,p,q:longint; tg:mn;
 begin
 read(u,v,p,q);
 For i:=1 to n do
 For j:=1 to m do
  If f[i-1,j]>=F[i,j-1] then
   begin
   tr[i,j].x:=i-1;
   tr[i,j].y:=j;
   F[i,j]:=F[i-1,j]+a[i,j];
   end
  Else
  Begin
   tr[i,j].x:=i;
   tr[i,j].y:=j-1;
   F[i,j]:=F[i,j-1]+a[i,j];
  end;
 i:=tr[p,q].x;j:=tr[p,q].y;tt:=a[i,j];tg.x:=i;tg.y:=j;
 while (i>u) and (j>v) do
  begin
  if a[i,j]>tt then begin tt:=a[i,j]; tg.x:=i;tg.y:=j;end;
  i:=tr[i,j].x;
  j:=tr[i,j].y;
  end;
 if (tg.x=u) and (tg.y=v) then begin tg.x:=0;tg.y:=0;end;
 For i:=1 to n do
 For j:=1 to m do F[i,j]:=0;
 For i:=1 to n do
 For j:=1 to m do
  IF (i<>tg.x)or(j<>tg.y) then
  F[i,j]:=max(F[i-1,j],F[i,j-1])+a[i,j];
 writeln(f[p,q]-F[u,v]+a[u,v]);
 end;
Procedure main;
var i:longint;
 begin
 For i:=1 to k do xuli;
 end;
BEGIN
inp;
main;
END.

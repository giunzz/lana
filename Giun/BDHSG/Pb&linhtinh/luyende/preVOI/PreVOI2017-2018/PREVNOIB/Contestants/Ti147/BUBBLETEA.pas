const fi='BUBBLETEA.inp';
      fo='BUBBLETEA.out';
var kt,bb:array[1..100000] of boolean;
    c,h,ke,a,b,cha,gt,u,v,bac,t:array[1..100000] of longint;
    max:int64;
    k,tt:longint;
Procedure dfs(u,v:longint);
var i:integer;
   begin
   bac[u]:=v;
   For i:=h[u]+1 to h[u+1] do dfs(ke[i],v+1);
   End;
Function kc(x,y:longint):int64;
var s:int64;
  begin
  s:=0;
  While bac[x]>bac[y] do begin s:=s+gt[x]; x:=cha[x]; End;
  While bac[x]<bac[y] do begin s:=s+gt[y]; y:=cha[y]; End;
  While x<>y do begin s:=s+gt[x]+gt[y]; x:=cha[x]; y:=cha[y]; End;
  exit(s);
  End;
Procedure xuly;
var tong,tg:int64;
    i:integer;
    begin
    tong:=kc(u[1],v[1]);
    For i:=2 to tt do
        begin
        tg:=kc(u[i],v[i]);
        if tong<tg then tong:=tg;
        End;
    if tong<max then max:=tong;
    End;
Procedure taov(x,y:longint);
var i:integer;
   begin
   if x>tt then begin xuly; exit; ENd;
   For i:=y+1 to k do
   if bb[i] then
      begin
      v[x]:=c[i];
      bb[i]:=false;
      taov(x+1,i);
      bb[i]:=true;
      End;
   End;
Procedure taou(x,y:longint);
var i:integer;
   begin
   if x>tt then begin taov(1,0); exit; End;
   For i:=y+1 to k do
   if bb[i] then
      begin
      bb[i]:=false;
      u[x]:=c[i];
      taou(x+1,i);
      bb[i]:=true;
      End;
   End;
Procedure main;
var n,i,goc:longint;
  begin
  assign(input,fi); reset(input);
  assign(output,fo); rewrite(output);
  read(n,k);
  For i:=1 to n do kt[i]:=true;
  For i:=1 to k do begin read(c[i]); bb[i]:=true; End;
  For i:=1 to n do h[i]:=0;
  FOr i:=1 to n-1 do
     begin
     read(a[i],b[i],t[i]);
     inc(h[a[i]]);
     cha[b[i]]:=a[i];
     kt[b[i]]:=false;
     gt[b[i]]:=t[i];
     End;
  For i:=2 to n do h[i]:=h[i-1]+h[i];
  For i:=1 to n-1 do
     begin
     ke[h[a[i]]]:=b[i];
     dec(h[a[i]]);
     End;
  For i:=1 to n do
  if kt[i] then goc:=i;
  dfs(goc,1);
  max:=10000000000000000;
  tt:=k div 2;
  taou(1,0);
  write(max);
  close(input);
  close(output);
  End;
Begin
main;
End.
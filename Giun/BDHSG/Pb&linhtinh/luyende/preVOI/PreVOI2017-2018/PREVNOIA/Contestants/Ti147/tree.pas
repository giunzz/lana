const fi='TREE.inp';
      fo='TREE.out';
var a,c,d,cha,k:array[1..5001] of longint;
    b:array[1..5000] of boolean;
    n:longint;
Procedure main;
var i,j,dem,t,tt,ss:longint;
  begin
  assign(input,fi); reset(input);
  assign(output,fo); rewrite(output);
  read(n);
  For i:=1 to n do read(a[i]);
  For i:=1 to n do b[i]:=false;
  For i:=1 to n-1 do begin read(c[i],d[i]); End;
  For i:=1 to n-1 do
      begin
      b[c[i]]:=true;
      cha[d[i]]:=c[i];
      End;
  dem:=0;  cha[1]:=-1;
  For i:=1 to n do k[i]:=0;
  For i:=1 to n do
  if not(b[i]) then
    begin
    if a[i]>1 then begin dem:=dem+a[i]-1; a[i]:=1; End;
    k[i]:=a[i];
    j:=cha[i];
    if a[i]=1 then While j<>-1 do begin k[j]:=k[j]+1; j:=cha[j]; End;
    End;
   For i:=1 to n do
   if not(b[i]) then
       begin
       tt:=1; ss:=0;
       if k[i]=1 then t:=-1 else t:=1;
       j:=cha[i];
       While j<>-1 do begin ss:=ss+abs(a[j]-k[j]); tt:=tt+abs(k[j]+t-a[j]); j:=cha[j]; End;
       if tt<ss then
           begin
           k[i]:=1-k[i];
           j:=cha[i];
           While j<>-1 do begin k[j]:=k[j]+t; j:=cha[j]; End;
           End;
       End;
   For i:=1 to n do
   dem:=dem+abs(a[i]-k[i]);
   write(dem);
   Close(input);
  close(output);
  End;
Begin
main;
End.
const   fi='teaworld.inp';
        fo='teaworld.out';
var     f:text;
        i,m,n,x,k,kq,tongy:longint;
        quacau,quacauy,trasuay,r,trasua,a,c,xoa:array[0..1000000] of longint;
(*=================================*)
procedure inp;
Begin
assign(f,fi);
reset(f);
read(f,m,n,k);
for i:=1 to m do begin read(f,quacau[i],quacauy[i],x,R[i]);  tongy:=tongy+quacauy[i]; end;
for i:=1 to n do begin read(f,trasua[i],trasuay[i],x,A[i]);  tongy:=tongy+trasuay[i]; end;
read(f,X);
close(f);
End;
(*=================================*)
procedure trong;
Begin

End;
(*=================================*)
procedure output;
var i,j,dem,tong:longint; ktra:boolean;
Begin
for i:=1 to n do if c[i]=1 then
  for j:=1 to m do if tongy=0 then
   begin
    ktra:=false;
    if ((trasua[i]>quacau[j]+R[j]) or (trasua[i]<quacau[j]-R[j])) and ((X>quacau[j]+R[j]) or (X<quacau[j]-R[j])) then ktra:=true;
    if ((trasua[i]<=quacau[j]+R[j]) and (trasua[i]>=quacau[j]-R[j])) and ((X<=quacau[j]+R[j]) and (X>=quacau[j]-R[j])) then ktra:=true;
    if ktra=false then xoa[j]:=1;
   end
   else trong;
dem:=0;
for i:=1 to m do if xoa[i]=1 then begin xoa[i]:=0; inc(dem); if dem>k then exit; end;
tong:=0;
if dem<=k then for i:=1 to n do if c[i]=1 then tong:=tong+a[i];
if tong>kq then kq:=tong;
End;
(*=================================*)
procedure dq(i:longint);
var j:longint;
Begin
for j:=0 to 1 do
 begin
  c[i]:=j;
  if i=n then output else dq(i+1);
 end;
End;
(*=================================*)
BEGIN
inp;
assign(f,fo);
rewrite(f);
dq(1);
writeln(f,kq);
close(f);
END.

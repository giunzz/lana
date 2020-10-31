uses    math;
const   fi='gifts.inp';
        fo='gifts.out';
var     f:text;
        i,j,n,dem,k,poss:longint;
        tg,kq,kq2,kq1:int64;
        c,b,a,s:array[0..1001000] of int64;
(*====================================*)
procedure inp;
Begin
assign(f,fi);
reset(f);
read(f,n,k);
for i:=1 to n do read(f,a[i]);
close(f);
End;
(*====================================*)
procedure sub2;
Begin
kq:=trunc(10e16);
for i:=1 to n-k+1 do
 begin
  tg:=0; dem:=0;
  for j:=1 to i-1 do begin inc(dem); b[dem]:=a[j]; end;
  for j:=i+k to n do begin inc(dem); b[dem]:=a[j]; end;
  for j:=1 to dem do
    begin
     c[j]:=c[j-1]+b[j];
     if j>=k then begin tg:=max(tg,c[j]-c[j-k]); if tg>kq then break; end;
    end;
  if tg<kq then kq:=tg;
 end;
End;
(*====================================*)
procedure sub3;
Begin
for i:=1 to n do s[i]:=s[i-1]+a[i];
for i:=1 to n-k+1 do if s[i+k-1]-s[i-1]>kq1 then begin poss:=i; kq1:=s[i+k-1]-s[i-1]; end;
dem:=0;
tg:=0;
kq2:=trunc(10e16);
for i:=1 to poss-1 do begin inc(dem); b[dem]:=a[i]; end;
for i:=poss+k to n do begin inc(dem); b[dem]:=a[i]; end;
for i:=1 to dem do
 begin
  s[i]:=s[i-1]+b[i];
  if i>=k then begin tg:=max(tg,s[i]-s[i-k]); if tg>kq2 then break; end;
 end;
kq2:=min(kq2,tg);
End;
(*====================================*)
BEGIN
inp;
assign(f,fo);
rewrite(f);
sub2;
sub3;
if n<=3000 then begin sub2; writeln(f,kq); end
           else begin sub3; writeln(f,kq2); end;
close(f);
END.

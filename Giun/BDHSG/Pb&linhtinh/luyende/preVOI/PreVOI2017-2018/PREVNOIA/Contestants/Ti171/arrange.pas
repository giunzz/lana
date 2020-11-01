const   fi='arrange.inp';
        fo='arrange.out';
var     f:text;
        i,n,j:longint;
        kq,tong:int64;
        a:array[0..1000000] of int64;
(*==========================================*)
procedure inp;
Begin
assign(f,fi);
reset(f);
read(f,n);
for i:=1 to n do begin read(f,a[i]); tong:=tong+a[i]; end;
tong:=tong div n;
close(f);
End;
(*==========================================*)
procedure sub1;
Begin
j:=1;
for i:=1 to n do if a[i]<tong then while a[i]<tong do
 begin
  while a[j]<=tong do inc(j);
  if a[j]-tong>=tong-a[i] then begin kq:=kq+(tong-a[i])*abs(i-j); a[j]:=a[j]-(tong-a[i]); a[i]:=tong; end
                          else begin kq:=kq+(a[j]-tong)*abs(i-j); a[i]:=a[i]+a[j]-tong;   a[j]:=tong; end;
 end;
writeln(f,kq);
End;
(*==========================================*)
BEGIN
inp;
assign(f,fo);
rewrite(f);
sub1;
close(f);
END.

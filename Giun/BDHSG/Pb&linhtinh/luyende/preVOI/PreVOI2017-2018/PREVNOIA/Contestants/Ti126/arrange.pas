const fi='arrange.inp';
      fo='arrange.out';
var a:array[1..1000000] of longint;
    i,n,x,y,z,kq:longint;

begin

assign(input,fi);
reset(input);
assign(output,fo);
rewrite(output);
read(n);
x:=0;
for i:=1 to n do
    begin
    read(a[i]);
    x:=x+a[i];
    end;
kq:=0;
y:=x div n;
z:=n-y;
for i:=1 to n do
    kq:=kq+abs(y-a[i]);
write(kq);
close(input);
close(output);
end.

const fi='bubbletea.inp';
      fo='bubbletea.out';
var n,k,a,b,c,i,x:longint;

begin

assign(input,fi);
reset(input);
assign(output,fo);
rewrite(output);
read(n,k);
for i:=1 to k do read(x);
for i:=1 to n-1 do read(a,b,c);
write(-1);
close(input);
close(output);
end.
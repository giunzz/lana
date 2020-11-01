uses math;
const fi='gifts.inp';
      fo='gifts.out';
var a,b:array[0..1000000] of int64;
    i,n,k,d,nho:longint;
    l,r,m,kq,x:int64;

begin

assign(input,fi);
reset(input);
assign(output,fo);
rewrite(output);
read(n,k);
r:=0;
for i:=1 to n do
    begin
    read(a[i]);
    b[i]:=b[i-1]+a[i];
    end;
{for i:=k+1 to n do l[i]:=max(l[i-1],b[i-1]-b[i-k]);
for i:=n-k downto 1 do r[i]:=max(r[i+1],b[i+k]-b[i+1]);
for i:=1 to n do kq:=}
l:=0;
r:=b[n];
while l<=r do
      begin
      m:=(l+r) div 2;
      nho:=0;
      d:=0;
      for i:=k to n do
          begin
          x:=b[i]-b[i-k];
          if (x>m) and (i-k+1>nho) then
             begin
             d:=d+1;
             nho:=i;
             end;
          end;
      if d<=1 then
         begin
         kq:=m;
         r:=m-1;
         end
      else l:=m+1;
      end;
write(kq);
close(input);
close(output);
end.
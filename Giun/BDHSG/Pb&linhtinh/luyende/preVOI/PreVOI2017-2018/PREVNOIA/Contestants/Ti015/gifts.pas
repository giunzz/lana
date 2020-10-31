uses math;
var n,k:longint;
    res:int64;
    s,left,right,a:array[0..2000000] of int64;
   // a:array[0..1000000] of longint;
procedure nhap;
var i:longint;
begin
 read(n,k);
 for i:=1 to n do
  begin
   read(a[i]);
   s[i]:=s[i-1]+a[i];
  end;
end;
procedure xuli;
var i:longint; tmp:int64;
begin
 res:=high(int64);
 for i:=1 to n do
  if i-k>=0 then left[i]:=max(left[i-1],s[i]-s[i-k])
  else left[i]:=0;
 for i:=n downto 1 do
  if i+k-1<=n then right[i]:=max(right[i+1],s[i+k-1]-s[i-1])
  else right[i]:=0;
 for i:=1 to n do
  if i-k>=0 then
   begin
    tmp:=max(left[i-k],right[i+1]);
    res:=min(res,tmp);
   end;
 write(Res);
end;
begin
 assign(input,'gifts.inp');reset(input);
 assign(output,'gifts.out');rewrite(output);
 nhap;
 xuli;
 close(input); close(output);
end.

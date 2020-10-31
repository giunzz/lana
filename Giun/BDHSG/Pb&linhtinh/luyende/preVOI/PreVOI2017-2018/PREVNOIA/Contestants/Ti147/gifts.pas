const fi='gifts.inp';
      fo='gifts.out';
var s,l,r:array[0..1000001] of uint64;
Function max(x,y:uint64):uint64;
   begin
   if x>=y then exit(x);
   exit(y);
   End;
Function min(x,y:uint64):uint64;
   begin
   if x<=y then exit(x);
   exit(y);
   End;
Procedure main;
var i,n,k,u:longint;
    x:uint64;
  begin
  assign(input,fi); reset(input);
  assign(output,fo); rewrite(output);
  fillchar(l,sizeof(l),0);
  fillchar(r,sizeof(r),0);
  s[0]:=0; x:=1000000000000000000;
  read(n,k);
  For i:=1 to n do begin read(u); s[i]:=s[i-1]+u; End;
  For i:=k to n do l[i]:=max(l[i-1],s[i]-s[i-k]);
  For i:=n-k+1 downto 1 do r[i]:=max(r[i+1],s[i+k-1]-s[i-1]);
  For i:=1 to n-k+1 do
  x:=min(x,max(l[i-1],r[i+k]));
  write(x);
  close(input);
  close(output);
  End;
Begin
main;
End.

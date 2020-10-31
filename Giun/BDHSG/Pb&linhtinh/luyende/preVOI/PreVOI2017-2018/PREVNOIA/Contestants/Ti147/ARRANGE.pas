const fi='ARRANGE.inp';
      fo='ARRANGE.out';
var a:array[1..100000] of longint;
Procedure main;
var i,n,j,k:longint;
    s,dem:int64;
  begin
  assign(input,fi); reset(input);
  assign(output,fo); rewrite(output);
  s:=0;
  read(n);
  For i:=1 to n do begin read(a[i]); s:=s+a[i]; End;
  if s mod n =0 then
      begin
      s:=s div n;
      dem:=0;
      For i:=1 to n do
      if a[i]<s then begin a[i+1]:=a[i+1]-(s-a[i]); dem:=dem+(s-a[i]); End
      else if a[i]>s then begin a[i+1]:=a[i+1]+(a[i]-s); dem:=dem+(a[i]-s); End;
      write(dem);
      close(input);
      close(output);
      exit;
      End;
  s:=s div n;
  dem:=0;
  For i:=1 to n do
    begin
    While a[i]<s do
      begin
      j:=i;
      k:=i;
      While (j>0)and(a[j]<=s) do dec(j);
      While (k<=n)and(a[k]<=s)do inc(k);
      if k<=n then
           if j=0 then j:=k
           else
          begin
          if i-j>k-i then j:=k;
          End;
      inc(a[i]);
      dec(a[j]);
      dem:=dem+abs(j-i);
      End;
    While a[i]>s+1 do
      begin
      j:=i;
      k:=i;
      While (a[j]>=s+1)and(j>0) do dec(j);
      While (a[k]>=s+1)and(k<=n) do inc(k);
      if k<=n then
           if j=0 then j:=k
           else
          begin
          if i-j>k-i then j:=k;
          End;
      dec(a[i]);
      inc(a[j]);
      dem:=dem+abs(j-i);
      End;
    End;
    write(dem);
  Close(input);
  close(output);
  End;
Begin
main;
End.

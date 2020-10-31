uses math;
const fi='gifts.inp';
      fo='gifts.out';
var n,k:longint;
    f,fleft,fright,a:array[0..1000000] of int64;
//----------------
procedure doc;
var i:longint;
begin
      read(n,k);
      for i:=1 to n do
      begin
            read(a[i]);
            f[i]:=f[i-1]+a[i];
      end;
end;
//----------------
procedure xuli;
var i:longint;
    res:int64;
begin
      for i:=k to n do
            fleft[i]:=max(fleft[i-1],f[i]-f[i-k]);
      for i:=n-k+1 downto 1 do
            fright[i]:=max(fright[i+1],f[i+k-1]-f[i-1]);
      res:=high(int64);
      for i:=1 to n-k+1 do
      begin
            res:=min(res,max(fleft[i-1],fright[i+k]));
      end;
      write(res);
end;
//----------------
begin
      assign(input,fi); reset(input);
      assign(output,fo); rewrite(output);
      doc;
      xuli;
end.

const fi='gifts.inp';
      fo='gifts.out';
      maxn=trunc(1e6)+1;
var   n,k:longint;
      sol,val:int64;
      l,r,s:array[0..maxn]of int64;
function max(i,j:int64):int64;inline; begin if i>j then exit(i); exit(j); end;
function min(i,j:int64):int64;inline; begin if i>j then exit(j); exit(i); end;
procedure main;
var i:longint;
begin
      read(n,k);
      for i:=1 to n do
      begin
          read(s[i]);
          s[i]:=s[i-1]+s[i];
      end;
      l[k]:=s[k];
      r[n-k+1]:=s[n]-s[n-k];
      for i:=k+1 to n-k do l[i]:=max(l[i-1],s[i]-s[i-k]);
      for i:=n-k downto k+1 do r[i]:=max(r[i+1],s[i+k-1]-s[i-1]);
      for i:=k to n-k do
      begin
          val:=min(l[i],r[i+1]);
          sol:=max(sol,val);
      end;
      write(sol);
end;
begin
      assign(input,fi);
      reset(input);
      assign(output,fo);
      rewrite(output);
      main;
end.

const
  fi='gifts.inp';
  fo='gifts.out';
var
  f:text;
  n,k:longint;
  a,l,max,max1,l1:array[0..2000000] of int64;
  kq:int64;
procedure  nhap;
  var i:longint;
  begin
     assign(f,fi);
     reset(f);
     readln(f,n,k);
     for i:=1 to n do
         read(f,a[i]);
     close(f);
  end;
procedure  init;
  var  i:longint;
  begin
    l[0]:=0;
    for i:=1 to n do
        l[i]:=l[i-1]+a[i];
  end;
procedure  xuli;
  var  i,j:longint;
       t,c:int64;
  begin
    kq:=high(int64);
    for i:=1 to n-k+1 do
        begin
          c:=l[i+k-1]-l[i-1];
          t:=high(int64);
          if i-1-k+1>=1 then
             begin
             t:=0;
          for j:=1 to i-1-k+1 do
              if l[j+k-1]-l[j-1]>t then t:=l[j+k-1]-l[j-1]; end;
          if (t=high(int64)) and (i+k<=n-k+1) then
          begin
          t:=0;
          for j:=i+k to n-k+1 do
              if l[j+k-1]-l[j-1]>t then t:=l[j+k-1]-l[j-1];
          end;
          if t<kq then kq:=t;
        end;
  end;
procedure  xuli1;
  var xd,i:longint;
      t,c:int64;
  begin
    for i:=1 to n-k+1do
        l1[i]:=l[i+k-1]-l[i-1];
    kq:=high(int64);
    max[0]:=0;
    for i:=1 to n do
        if max[i-1]>l1[i] then max[i]:=max[i-1]
        else max[i]:=l1[i];
    max1[n+1]:=0;
    for i:=n downto 1 do
        if max1[i+1]>l1[i] then max1[i]:=max1[i+1]
        else max1[i]:=l1[i];
    for i:=1 to n-k+1 do
        begin
          c:=0;
          if i>k then c:=max[i-k];
          if i<=n-2*k+1 then
              if max1[i+k]>c then c:=max1[i+k];
          if c<kq then begin kq:=c;end;
        end;
  end;

BEGIN
  nhap;
  init;
  if n<=5000 then
  xuli
  else
  xuli1;
  assign(f,fo);
  rewrite(f);
  writeln(f,kq);
  close(f);
END.

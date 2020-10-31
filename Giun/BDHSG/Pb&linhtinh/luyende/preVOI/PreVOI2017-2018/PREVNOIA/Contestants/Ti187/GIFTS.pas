uses math;
const nmax=100000;
    fin='GIFTS.INP';
    fout='GIFTS.OUT';
var n,k: longint;
    fi,fo:text;
    l,r:array[1..nmax] of int64;
    a:array[1..nmax] of longint;
procedure nhap;
var i:longint;
    sum:array[1..nmax] of int64;
begin
    sum[1]:=0;
   assign(fi,fin);
   assign(fo,fout);
   reset(fi);
   rewrite(fo);
   read(fi,n,k);
   for i := 1 to n do read(fi,a[i]);
   for i := 1 to k do sum[1]:=sum[1]+a[i];
   for i := 2 to n-k+1 do sum[i]:=sum[i-1]-a[i-1]+a[i+k-1];
   l[1]:=sum[1];
   for i := 2 to n-k+1 do l[i]:=max(l[i-1],sum[i]);
   r[n-k+1]:=sum[n-k+1];
   for i := n-k downto 1 do r[i]:=max(r[i+1],sum[i]);
end;
procedure solve;
var i,j:longint;
    kq,q:int64;
begin
    //for i := 1 to n-k+1 do write(fo,l[i],' ');
    //writeln(fo);
    //for i := 1 to n-k+1 do write(fo,r[i],' ');
    kq    := high(int64);
    for i:=1 to n-k+1 do begin
        q     := 0;
        if i-k>=1 then q:=l[i-k];
        if (i+k<=n-k+1) and (r[i+k]>q) then q:=r[i+k];
        if kq>q then kq:=q;
    end;
    writeln(fo,kq);
    close(fo);
end;
BEGIN
    nhap;
    solve;
END.
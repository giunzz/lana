const   fi='gifts.inp';
        fo='gifts.out';
        maxn=round(1e5+5);
var
        n,k:longint;
        a:array[0..maxn]of longint;
        s,maxd,maxc:array[0..maxn]of int64;
procedure nhap;
var     i,j:longint;
begin
        assign(input,fi);reset(input);
        read(n,k);
        for i:=1 to n do read(a[i]);
        for i:=1 to n do
                s[i]:=s[i-1]+a[i];
end;
function max(a,b:int64):int64;
begin
        if a>b then exit(a) else exit(b);
end;
function min(a,b:int64):int64;
begin
        if a<b then exit(a) else exit(b);
end;
procedure trau;
var     i,j,vt1,vt2:longint;
        t1,t2,kq:int64;
begin
        assign(output,fo);
        rewrite(output);
        kq:=high(longint);
        for i:=1 to n-k+1 do
                begin
                t2:=-1;
                vt1:=i-1;vt2:=i+k;
                for j:=1 to vt1-k+1 do
                         t2:=max(t2,s[j+k-1]-s[j-1]);
                for j:=vt2 to n-k+1 do
                        t2:=max(t2,s[j+k-1]-s[j-1]);
                kq:=min(kq,t2);
                end;
                write(kq);
end;
procedure tinhte;
var     i,j,d,c:longint;
        kq:int64;
begin
        assign(output,fo);rewrite(output);
        for i:=n-k+1 downto 1do
                maxc[i]:=max(maxc[i+1],s[i+k-1]-s[i-1]);
        for i:=1 to n-k+1 do
                maxd[i]:=max(maxd[i-1],s[i+k-1]-s[i-1]);
        kq:=high(longint);
        for i:=1 to n-k+1 do
                begin
                d:=i-1;c:=i+k;
                if (d-k+1>=1)and(c<=n-k+1) then
                        kq:=min(maxd[d-k+1],maxc[c]);
                end;
                write(kq);
end;
begin
        nhap;
        if n<=1000 then trau else
                tinhte;
end.
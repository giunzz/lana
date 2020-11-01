uses math;
const   fii='gifts.inp';
        foo='gifts.out';
        maxn=trunc(1e6);
type    li=longint;
var     fi,fo:text;
        k,n:li;
        a,s:array[0..maxn] of int64;

procedure input;
var     i:li;
begin
        readln(fi,n,k);
        s[0]:=0;
        for i:=1 to n do
                begin
                        read(fi,a[i]);
                        s[i]:=s[i-1]+a[i];
                end;
end;

procedure sol;
var     s1,s2,kq:int64;
        i,j:li;
begin
        kq:=maxn;
        for i:=k to n do
                begin
                        s1:=s[i]-s[i-k];
                        s2:=-1;
                        for j:=i-k downto 1 do
                                if j-k>=0 then s2:=max(s2,s[j]-s[j-k]);
                        for j:=i+k to n do
                                s2:=max(s2,s[j]-s[j-k]);
                        if s2<=s1 then kq:=min(kq,s1);
                end;
        write(fo,kq);
end;

procedure xl;
begin
        assign(fi,fii); reset(fi);
        assign(fo,foo); rewrite(fo);
        input;
        sol;
        close(fi);
        close(fo);
end;

BEGIN
        XL;
END.
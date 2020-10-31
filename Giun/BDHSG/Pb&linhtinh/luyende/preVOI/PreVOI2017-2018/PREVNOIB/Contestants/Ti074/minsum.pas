uses math;
const   fii='minsum.inp';
        foo='minsum.out';
        maxt=500;
        maxn=trunc(1e6);
type    li=longint;
        bg=record
        dau,cuoi,gt:li;
        end;
var     fi,fo:text;
        t,a,b:li;
        kq:bg;
        mang:array[1..5000,1..5000] of boolean;

function ucln(m,n:li):li;
begin
        if m=n then exit(m);
        if m mod n = 0 then exit(n);
        if n mod m = 0 then exit(m);
        while (m<>0) and (n<>0) do
                begin
                        if m>n then m:=m-n
                        else
                                if m<n then n:=n-m;
                        if m=n then exit(m);
                end;
end;

procedure dq(a,b:li);
var     i,a1,b1,x,na,nb:li;
        ua,ub:array[1..maxn] of li;
begin
        if mang[a,b]=false then exit;
        mang[a,b]:=false;
        x:=ucln(a,b);
        if x<>1 then
                begin
                        kq.dau:=a div x;
                        kq.cuoi:=b div x;
                        kq.gt:=kq.dau+kq.cuoi;
                        {dq(kq.dau,kq.cuoi);}
                        exit;
                end;
        na:=0;
        fillchar(ua,sizeof(ua),0);
        for i:=1 to a do
                if a mod i=0 then
                        begin
                                inc(na);
                                ua[na]:=i;
                        end;
        nb:=0;
        fillchar(ub,sizeof(ub),0);
        for i:=1 to b do
                if b mod i=0 then
                        begin
                                inc(nb);
                                ub[nb]:=i;
                        end;
        for i:=2 to na do
                begin
                        a1:=a div ua[i];
                        b1:=b*ua[i];
                        if (a1=kq.dau) and (b1=kq.cuoi) then exit;
                        if a1+b1<kq.gt then
                                begin
                                        kq.dau:=a1;
                                        kq.cuoi:=b1;
                                        kq.gt:=kq.dau+kq.cuoi;
                                end;
                        if (a1<>0) and (b1<>0) then dq(a1,b1);
                        if (a1=0) or (b1=0) then exit;
                end;
        {for i:=2 to nb do
                begin
                        b1:=b div ub[i];
                        a1:=a*ub[i];
                        if (a1=kq.dau) and (b1=kq.cuoi) then exit;
                        if a1+b1<kq.gt then
                                begin
                                        kq.dau:=a1;
                                        kq.cuoi:=b1;
                                        kq.gt:=kq.dau+kq.cuoi;
                                end;
                        if (a1<>0) and (b1<>0) then dq(a1,b1);
                        if (a1=0) or (b1=0) then exit;
                end;}
end;

procedure sol(a,b:li);
var     a1,b1,x,i:li;
begin
        kq.dau:=a;
        kq.cuoi:=b;
        kq.gt:=a+b;
        fillchar(mang,sizeof(mang),true);
        dq(a,b);
        writeln(fo,kq.dau,' ',kq.cuoi);
end;

procedure input;
var     i,a,b:li;
begin
        readln(fi,t);
        for i:=1 to t do
                begin
                        readln(fi,a,b);
                        if a=b then writeln(fo,1,' ',1)
                        else sol(a,b);
                end;
end;

procedure xl;
begin
        assign(fi,fii);
        assign(fo,foo);
        reset(fi);
        rewrite(fo);
        input;
        close(fi);
        close(fo);
end;

BEGIN
        XL;
END.

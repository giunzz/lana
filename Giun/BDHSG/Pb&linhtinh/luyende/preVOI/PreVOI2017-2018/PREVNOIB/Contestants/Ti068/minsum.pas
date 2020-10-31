uses    math;
const   fi='minsum.inp';
        fo='minsum.out';
        maxn=trunc(1e6);
        oo=trunc(1e9);
type    num=record
        gt,ts:longint;
end;
var     n,m,t,d,k,kq1,kq2,kq,d1:int64;
        nt:array[0..maxn] of longint;
        p:array[0..maxn] of num;

function        ucln(a,b:longint):longint;
begin
        if b>a then exit(ucln(b,a));
        if a mod b=0 then exit(b);
        exit(ucln(b,a mod b));
end;

function        ktra(x:longint):boolean;
var     i,j:longint;
begin
        for i:=2 to trunc(sqrt(x)) do if x mod i=0 then exit(false);
        exit(true);
end;

procedure       pt(a:longint);
var     i,j:longint;
begin
        d1:=0;
        for i:=1 to d do
                begin
                        if nt[i]>a then exit;
                        if a mod nt[i]=0 then
                                begin
                                        inc(d1);
                                        p[d1].gt:=nt[i];
                                        p[d1].ts:=0;
                                        while (a mod nt[i]=0) and (a>0) do
                                                begin
                                                        inc(p[d1].ts);
                                                        a:=a div nt[i];
                                                end;
                                        if a=0 then exit;
                                end;
                end;
        if a<>0 then
                begin
                        inc(d1);
                        p[d1].ts:=1;
                        p[d1].gt:=a;
                end;
end;

function        lt(x,y:longint):longint;
var     t:longint;
begin
        if y=0 then exit(1);
        if y=1 then exit(x);
        t:=lt(x,y div 2);
        if y mod 2=0 then exit(t*t) else
        exit(t*t*x);
end;

procedure       xl(a,b:longint);
var     tg,i,j,tg1,tg2:longint;
begin
        tg:=ucln(a,b);
        kq1:=a div tg;
        kq2:=b div tg;
        kq:=kq1+kq2;
        a:=kq1;
        b:=kq2;
        if ktra(a) then
                if ktra(b) then exit;
        pt(a);
        for i:=1 to d1 do
                if p[i].ts>1 then
                        begin
                                tg1:=(p[i].ts div 2)*2;
                                tg2:=lt(p[i].gt,tg1);
                                a:=a div tg2;
                        end;
        pt(b);
        for i:=1 to d1 do
                if p[i].ts>1 then
                        begin
                                tg1:=(p[i].ts div 2)*2;
                                tg2:=lt(p[i].gt,tg2);
                                b:=b div tg2;
                        end;
        kq1:=a;
        kq2:=b;
end;

procedure       tmnt;
var     i:longint;
        kt:array[0..maxn] of boolean;
        j:int64;
begin
        fillchar(kt,sizeof(kt),true);
        d:=0;
        for i:=2 to maxn do
                if kt[i] then
                        begin
                                inc(d);
                                nt[d]:=i;
                                if i<=3000 then
                                begin
                                j:=i*i;
                                while j<=maxn do
                                        begin
                                                kt[j]:=false;
                                                j:=j+i;
                                        end;
                                end;
                        end;
end;


procedure       ddl;
var     i,j,a,b:longint;
        f1,f2:text;
begin
        assign(f1,fi);
        assign(f2,fo);
        reset(f1);
        rewrite(f2);
        tmnt;
        read(f1,t);
        for i:=1 to t do
                begin
                        read(f1,a,b);
                        kq1:=trunc(1e9);
                        kq2:=trunc(1e9);
                        xl(a,b);
                        writeln(f2,kq1,' ',kq2);
                end;
        close(f1);
        close(f2);
end;

begin
        ddl;
end.

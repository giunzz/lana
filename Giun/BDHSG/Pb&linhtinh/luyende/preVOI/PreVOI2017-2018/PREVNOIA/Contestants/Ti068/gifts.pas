uses    math;
const   fi='gifts.inp';
        fo='gifts.out';
        maxn=trunc(1e6);
        oo=trunc(1e15);
var     m,n,k,kq:int64;
        a,s,b,c:array[0..maxn] of int64;

procedure       xl;
var     i,j,u,v:longint;
        tg:int64;
begin
        tg:=-oo;
        kq:=oo;
        u:=0;
        m:=0;
        for i:=k to n do
                if s[i]-s[i-k]>tg then
                        begin
                                tg:=s[i]-s[i-k];
                                u:=i;
                        end;
        for i:=k to n do
                if s[i]-s[i-k]=tg then
                        begin
                                inc(m);
                                b[m]:=i;
                        end;

        for j:=1 to m do
                begin
                        u:=b[j];
                        tg:=-oo;
                        for i:=k to u-k do tg:=max(tg,s[i]-s[i-k]);
                        for i:=u+k to n do tg:=max(tg,s[i]-s[i-k]);
                        kq:=min(kq,tg);
                end;
end;


procedure       ddl;
var     i,j:longint;
        f1,f2:text;
begin
        assign(f1,fi);
        assign(f2,fo);
        reset(f1);
        rewrite(f2);
        read(f1,n,k);
        s[0]:=0;
        for i:=1 to n do
                begin
                        read(f1,a[i]);
                        s[i]:=s[i-1]+a[i];
                end;
        kq:=0;
        xl;
        writeln(f2,kq);
        close(f1);
        close(f2);
end;

begin
        ddl;
end.

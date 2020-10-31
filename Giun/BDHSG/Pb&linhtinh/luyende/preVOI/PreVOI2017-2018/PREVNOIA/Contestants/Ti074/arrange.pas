uses math;
const   fii='arrange.inp';
        foo='arrange.out';
        maxn=5*trunc(1e3);
type    li=longint;
var     fi,fo:text;
        n,s:int64;
        a,b:array[1..maxn] of int64;

procedure input;
var     i:li;
begin
        readln(fi,n);
        s:=0;
        for i:=1 to n do
                begin
                        read(fi,a[i]);
                        s:=s+a[i];
                end;
end;

{procedure qs(l,r:li);
var     g,tg,i,j:li;
begin
        i:=l;
        j:=r;
        g:=a[(l+r) div 2];
        repeat
                while a[i]<g do inc(i);
                while a[j]>g do dec(j);
                if i<=j then
                        begin
                                tg:=a[i];
                                a[i]:=a[j];
                                a[j]:=tg;
                                inc(i);
                                dec(j);
                        end;
        until i>j;
        if i<r then qs(i,r);
        if l<j then qs(l,j);
end; }

procedure sub1;
var     tb,time,x:int64;
        i,j:li;
begin
        tb:=s div n;
        time:=0;
        for i:=1 to n do
                begin
                        if a[i]<tb then
                                for j:=1 to n do
                                        if a[j]>tb then
                                                begin
                                                        x:=a[i];
                                                        a[i]:=tb;
                                                        a[j]:=a[j]-(tb-x);
                                                        time:=time+(tb-x)*abs(i-j);
                                                        break;
                                                end;
                        if a[i]>tb then
                                for j:=1 to n do
                                        if a[j]<tb then
                                                begin
                                                        x:=a[i];
                                                        a[i]:=tb;
                                                        a[j]:=a[j]+(x-tb);
                                                        time:=time+(x-tb)*abs(i-j);
                                                        break;
                                                end;
                end;
        write(fo,time);
end;

procedure sub2;
var     tb,time,x,x1:int64;
        i,j:li;
begin
        tb:=trunc(s/n);
        time:=0;
        for i:=1 to n do
                begin
                        if (a[i]<tb) and (a[i]<tb+1) then
                                begin
                                        x1:=maxn;
                                        b:=a;
                                        for j:=1 to n do
                                        if (a[j]>=tb+1) then
                                                begin
                                                        x:=a[i];
                                                        b[i]:=tb;
                                                        b[j]:=b[j]-(tb-x);
                                                        x1:=min(x1,time+(tb-x)*abs(i-j));
                                                end;
                                        if x1<>maxn then time:=x1;
                                end;
                        if a[i]>=tb+1 then
                                begin
                                        x1:=maxn;
                                        b:=a;
                                        for j:=1 to n do
                                        if a[j]<tb then
                                                begin
                                                        x:=a[i];
                                                        b[i]:=tb+1;
                                                        b[j]:=b[j]+(x-tb-1);
                                                        x1:=min(x1,time+(x-tb-1)*abs(i-j));
                                                end;
                                        if x1<>maxn then time:=x1;
                                end;
                end;
        write(fo,time);
end;

{procedure sol;
var     kq:li;
begin
        qs(1,n);
        kq:=0;
        while a[n]-a[1]<>1 do
                begin
                        inc(kq);
                        a[n]:=a[n]-1;
                        a[1]:=a[1]+1;
                        qs(1,n);
                end;
        writeln(fo,kq);
end; }

procedure xl;
begin
        assign(fi,fii);
        assign(fo,foo);
        reset(fi);
        rewrite(fo);
        input;
        if s div n = s/n then sub1
        else sub2;
        close(fi);
        close(fo);
end;

BEGIN
        XL;
END.

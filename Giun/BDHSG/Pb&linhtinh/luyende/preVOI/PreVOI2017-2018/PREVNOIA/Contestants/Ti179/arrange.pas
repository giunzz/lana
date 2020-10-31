const   fi='arrange.inp';
        fo='arrange.out';
type    data=record
                cs,gt:longint;
end;
var     f:text;
        a:array[1..100000] of data;
        b:array[1..100000] of longint;
        n,kq,cnt,j:longint;
procedure enter;
var     i:longint;
begin
        assign(f,fi);reset(f);
        read(f,n);
        for i:=1 to n do
                begin
                        read(f,a[i].gt);
                        a[i].cs:=i;
                end;
        close(f);
end;

procedure sol;
var     i,d,t,be:longint;
        s:int64;
begin

        s:=0;
        for i:=1 to n do
                s:=s+a[i].gt;
        cnt:=s div n;
        t:=s-cnt*n;
        be:=n-t;
        kq:=0;
        j:=0;
        for i:=1 to n do
                if a[i].gt>cnt then
                        begin
                                inc(j);
                                b[j]:=i;
                                dec(t);
                        end;
        for i:=1 to j do
                begin
                        for d:=1 to b[i] do
                                if a[d].gt<cnt  then
                                        begin
                                                a[b[i]].gt:=a[b[i]].gt-(cnt-a[d].gt);
                                                a[d].gt:=cnt;
                                                kq:=kq+(cnt-a[d].gt)*abs(b[i]-d);
                                        end;
                        if a[b[j]].gt>cnt then
                        for d:=b[i] to n do
                                 if a[d].gt<cnt  then
                                        begin
                                                a[b[i]].gt:=a[b[j]].gt-(cnt-a[d].gt);
                                                a[d].gt:=cnt;
                                                kq:=kq+(cnt-a[d].gt)*abs(b[i]-d);
                                        end;
                end;


        assign(f,fo); rewrite(f);
        write(f,kq);
        close(F);
end;
begin
        enter;
        sol;
end.

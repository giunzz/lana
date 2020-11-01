const   fi='gifts.inp';
        fo='gifts.out';
var     f:text;
        a:array[1..1000000] of longint;
        s:array[0..1000000] of   int64;
        n,k,kq,m,m1:int64;
procedure enter;
var     i:longint;
begin
        assign(f,fi);reset(f);
        readln(f,n,k);
        for i:=1 to n do
                read(f,a[i]);
        close(f);
end;
procedure init;
var     i:longint;
begin
        s[0]:=0;
        for i:=1 to n do
                s[i]:=s[i-1]+a[i];
end;
procedure sol;
var     i:longint;
begin
        init;
        kq:=0;
        for i:=0 to n-k do
                if s[i+k]-s[i]>kq then
                        begin
                                kq:=s[i+k]-s[i];
                                m:=i+1;
                        end;
        kq:=0;
        for i:=0 to n-k+1 do
                begin
                        if (i<m) then
                                if (i+k)<m then
                                if (s[i+k]-s[i])>kq then
                                        begin
                                                kq:=s[i+k]-s[i];
                                        end;
                        if i>m+k-1 then
                                if (s[i+k]-s[i])>kq then
                                        begin
                                                kq:=s[i+k]-s[i];
                                        end;
                end;

        assign(f,fo);rewrite(f);
        write(f,kq);
        close(f);
end;
begin
        enter;
        sol;
end.





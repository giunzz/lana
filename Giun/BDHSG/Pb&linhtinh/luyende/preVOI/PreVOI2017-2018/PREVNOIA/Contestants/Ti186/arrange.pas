const   fi='arrange.inp';
        fo='arrange.out';
        maxn=round(1e5+5);
var
        n:longint;
        a:array[0..maxn]of longint;
        res:int64;
procedure nhap;
var     i,j:longint;
begin
        assign(input,fi);reset(input);
        read(n);
        for i:=1 to n do read(a[i]);
end;
procedure chuyen1(x,t:longint);
var     i,j,t1,t2:longint;
begin
        i:=x;j:=x;
        while a[x]<t do
                begin
                if i-1>0 then
                begin
                i:=i-1;
                if a[i]>t then
                        begin
                        t1:=a[i]-t;t2:=t-a[x];
                        if t1<=t2 then begin a[x]:=a[x]+t1;a[i]:=a[i]-t1;inc(res,(x-i)*t1);end
                                else begin a[x]:=a[x]+t2;a[i]:=a[i]-t2;inc(res,(x-i)*t2);end;
                        end;
                end;
                if j+1<=n then
                begin
                j:=j+1;
                if a[j]>t then
                        begin
                        t1:=a[j]-t;t2:=t-a[x];
                        if t1<=t2 then begin a[x]:=a[x]+t1;a[j]:=a[j]-t1;inc(res,(j-x)*t1) end
                                else begin a[x]:=a[x]+t2;a[j]:=a[j]-t2;inc(res,(j-x)*t2);end;
                        end;
                end;
                end;
end;
procedure chuyen2(x,t:longint);
var     i,j:longint;
begin
        i:=x;j:=x;
        while a[x]>t do
                begin
                if i-1>0 then
                        begin
                        i:=i-1;
                        if a[i]<t then
                                begin
                                inc(a[i]);dec(a[x]);
                                inc(res,x-i);
                                end;
                        end;
                if (j+1<=n)and(a[x]>t)then
                        begin
                        j:=j+1;
                        if a[j]<t then
                                begin
                                inc(a[j]);dec(a[x]);
                                inc(res,j-x);
                                end;
                        end;
                end;
end;
procedure trau;
var     i,j,k,t:longint;
        s:int64;
begin
        assign(output,fo);rewrite(output);
        s:=0;res:=0;
        for i:=1to n do
                s:=s+a[i];
        t:=s div n;
        for i:=1 to n do
                if a[i]<t then chuyen1(i,t);
        for i:=1 to n do
                if a[i]>t+1 then chuyen2(i,t+1);
        write(res);
end;
begin
        nhap;
        trau;
end.




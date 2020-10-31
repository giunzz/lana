var h,c,d:array[1..63] of int64;
//v:array[1..1000000] of int64;
p,v:array[1..63,0..1000000] of int64;
n,i,a,b,xet:longint;
st,res:ansistring;
s,k:int64;
f,g:text;
procedure check;
var t,x:longint;
p:int64;
begin
    p:=0;
    for t:=1 to n do
    begin
        if h[t]=1 then x:=a
        else
        x:=b;
        p:=p*10+x;
        p:=p mod s;
    end;
    if p=k then
    begin
        for t:=1 to n do
        if h[t]=1 then write(g,a)
        else
        write(g,b);
        xet:=1;
    end;
end;
procedure try(i:longint);
var j:longint;
begin
    for j:=1 to 2 do
    begin
        h[i]:=j;
        if i<n then try(i+1)
        else
        check;
        if xet=1 then exit;
    end;
end;
function tinh(i,nho:int64):longint;
var j,kq,t:longint;
begin
    if i=n+1 then
    begin
        if nho=k then exit(1)
        else
        exit(0);
    end;
    for t:=1 to d[i] do
    if v[i,t]=nho then exit(p[i,t]);
    kq:=0;
    for j:=1 to 2 do
    begin
        kq:=(kq+tinh(i+1,(nho*10+c[j]) mod s));
        if kq>0 then
        begin
            str(c[j],st);
            res:=st+res;
            exit(kq);
        end;
    end;
    inc(d[i]);
    v[i,d[i]]:=nho;
    p[i,d[i]]:=kq;
    exit(kq);
end;
procedure xl;
var i,j,z:longint;
begin
    for i:=1 to n do
    for j:=0 to 1000000 do p[i,j]:=-1;
    z:=tinh(1,0);
    if z>0 then write(g,res)
    else
    write(g,-1);
end;
begin
    assign(f,'modulo.inp');reset(f);
    assign(g,'modulo.out');rewrite(g);
    read(f,a,b);
    read(f,n,k);
    s:=1;
    xet:=0;
    for i:=1 to n do s:=s*2;
    c[1]:=a;
    c[2]:=b;
    if n<=26 then
    begin
        try(1);
        if xet<=0 then write(g,-1);
    end
    else
    xl;
    //else
    //write(g,-1);
    close(g);
end.

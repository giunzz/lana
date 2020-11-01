const nmax = 100000;
    fin = 'ARRANGE.INP';
    fout = 'ARRANGE.OUT';
var n : longint;
    a : array[1..nmax] of longint;
    f1,f2 : text;
procedure nhap;
var i : longint;
begin
    assign(f1,fin);
    reset(f1);
    readln(f1,n);
    for i := 1 to n do read(f1,a[i]);
    close(f1);
end;
procedure sort(l,r : longint);
var i,j,tg,p : longint;
begin
    if r <= l then exit;
    i := l; j := r;
    p := a[(l+r) div 2];
    repeat
        while a[i]<p do inc(i);
        while a[j]>p do dec(j);
        if i <= j then
        begin
            tg := a[i];
            a[i]:=a[j];
            a[j]:=tg;
            inc(i);
            dec(j);
        end;
    until i > j;
    sort(l,j);
    sort(i,r);
end;
procedure tinh;
var i,cnt : longint;
begin
    assign(f2,fout);
    rewrite(f2);
    cnt := 0;
    sort(1,n);
    i := 1;
    while i <= n do
    begin
        if (a[n]-a[i])>1 then
        begin
            repeat
                dec(a[n]);
                inc(a[i]);
                inc(cnt);
            until a[n]-a[i]<=1;
            inc(i);
        end;
        inc(i);
    end;
    writeln(f2,cnt);
    close(f2);
end;
BEGIN
    nhap;
    tinh;
END.
uses math;
const nmax = 1000000;
    fin = 'GIFTS.INP';
    fout = 'GIFTS.OUT';
var n,k : longint;
    a,sum : array[1..nmax] of longint;
    f1,f2 : text;
procedure nhap;
var i : longint;
begin
    assign(f1,fin);
    reset(f1);
    readln(f1,n,k);
    for i := 1 to n do 
    begin 
        read(f1,a[i]);
    end;
    close(f1);
end;
procedure tinhs;
var i,x,xt,v : longint;
begin
    assign(f2,fout);
    rewrite(f2);
    x  := 0;
    xt := 0;
    sum[1]:=a[1]+a[2];
    for i:=  2 to n do 
    begin
        sum[i]:=a[i-1]+a[i];
        //write(f2,sum[i],' ');
        if x < sum[i] then x := sum[i];
        xt := min(x,sum[i]);
    end;
    writeln(f2,xt);
    close(f2);
end;
BEGIN
    nhap;
    tinhs;
END.
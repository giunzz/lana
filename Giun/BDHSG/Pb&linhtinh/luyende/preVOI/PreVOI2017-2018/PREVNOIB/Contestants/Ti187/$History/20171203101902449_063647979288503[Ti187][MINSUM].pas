const nmax=50000;
fin='MINSUM.INP';
fout='MINSUM.OUT';
var t,n,a,b:longint;
    fi,fo:text;
function UCLN(a,b:longint):longint;
var i,tg:longint;
begin 
    if a>b then begin
        tg := a;
        a  := b;
        b  := tg;
    end;
    if b mod a=0 then exit(a);
    for i:=2 to trunc(sqrt(a)) do 
    begin 
        if (a mod i =0) then tg:=a div i;
        if b mod tg =0 then exit(tg);
    end;
    exit(-1);
end;
function ULN(a:longint):longint;
var i:longint;
begin
for i:=2 to trunc(sqrt(a)) do 
    begin
        if (a mod i =0) then exit(a div i);
    end;
exit(a);
end;
procedure solve(p,q:longint);
var x,kq,a,b:longint;
begin 
    repeat 
        x := UCLN(p,q);
        a := p;
        b := q;
        if x<>-1 then begin
            a := a div x;
            b := b div x;
        end;
        kq := a+b;
        x  := uLN(a);
        a  := a div x;
        b  := b*x;
        if a+b<kq then kq:=a+b;
        if x=1 then begin 
            x := uln(b);
            A := A*x;
            b := b div x;
        end;
        if a+b<kq then kq:=a+b;
    until x=-1;
    write(fo,kq);
end;
procedure nhap;
var i:longint;
begin 
    assign(fi,fin);
    assign(fo,fout);
    reset(fi);
    rewrite(fo);
    read(fi,t);
    for i:=1 to t do 
    begin 
        read(fi,a,b);
        solve(a,b);
    end;
    close(fo);
    close(fi);
end;
BEGIN 
    nhap;
END.
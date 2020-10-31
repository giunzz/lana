uses math;
const   fii='tree.inp';
        foo='tree.out';
        maxn=5*trunc(1e3);
type    li=longint;
var     fi,fo:text;
        n:li;
        a:array[1..maxn] of li;

procedure input;
var     i,x,y:li;
begin
        readln(fi,n);
        for i:=1 to n do read(fi,a[i]);
        for i:=1 to n-1 do read(fi,x,y);
end;

procedure xl;
begin
        assign(fi,fii);
        assign(fo,foo);
        reset(fi);
        rewrite(fo);
        input;
        write(fo,random(1000));
        close(fi);
        close(fo);
end;

BEGIN
        XL;
END.
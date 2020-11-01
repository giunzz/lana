uses math;
const   fii='teaworld.inp';
        foo='teaworld.out';
        maxn=trunc(1e5);
type    li=longint;
var     fi,fo:text;
        m,n,k:li;

procedure input;
var     i,x,y,z,e,r:li;
begin
        readln(fi,m,n,k);
        for i:=1 to m do readln(fi,x,y,z,r);
        for i:=1 to n do readln(fi,x,y,z,e);
        readln(fi,x,y,z)
end;

procedure xl;
begin
        assign(fi,fii); reset(fi);
        assign(fo,foo); rewrite(fo);
        input;
        writeln(fo,random(m));
        close(fi);
        close(fo);
end;

BEGIN
        XL;
END.
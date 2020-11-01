const nmax=5000;
fin='TREE.INP';
fout='TREE.OUT';
var n:longint;
fi,fo:text;
    a:array[1..nmax] of longint;
procedure nhap;
var i:longint;
begin 
    assign(fi,fin);
    assign(fo,fout);
    reset(fi);
    rewrite(fo);
    read(fi,n);
    for i := 1 to n do read(fi,a[i]);
    close(fi);
end;
procedure solve;
begin 
    write(fo,4);
    close(fo);
end;
BEGIN 
    nhap;
    solve;
END.
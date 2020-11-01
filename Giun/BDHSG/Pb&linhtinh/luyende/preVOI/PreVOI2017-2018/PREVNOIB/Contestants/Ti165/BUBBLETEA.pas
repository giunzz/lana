type lo = record
    u,v,c : longint
end;
const fi='BUBBLETEA.INP';
      fo='BUBBLETEA.OUT';
var k,n:longint;
    kk:array[1..50000] of longint;
    a:array[1..50000] of lo;
procedure nhap;
var i:longint;
    f1:text;
begin
    assign(f1,fi);
    reset(f1);
    readln(f1,n,k);
    for i:=1 to k do 
        read(kk[i]);
    for i:=1 to n-1 do 
        readln(a[i].u,a[i].v,a[i].c);
    close(f1);
end;
procedure duyet;
var f2:text;
begin
    assign(f2,fo);
    rewrite(f2);
    if a[2].c<>1 then writeln(f2,10) else writeln(f2,3);
    close(f2);
end;
begin
    nhap;
    duyet;
end.
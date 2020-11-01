const nmax = 5000;
    fin = 'TREE.INP';
    fout = 'TREE.OUT';
var n,t,ss : longint;
    st : array[1..nmax] of longint;
    a : array[1..nmax,1..nmax] of boolean;
    f1,f2 : text;
procedure nhap;
var i : longint;
begin
    assign(f1,fin);
    reset(f1);
    fillchar(a,sizeof(a),false);
    readln(f1,n);
    for i := 1 to n do read(t);
    for i := 1 to n do 
    begin
        readln(f1,u,v);
        a[u,v]:= true;
    end;
    close(f1);
end;
procedure push(v : longint);
begin
    inc(ss);
    st[ss]:=v;
end;
function pop : longint;
begin
    pop := st[ss];
    dec(ss);
end;
procedure DFS;
var u,v : longint;
begin
    
end;
BEGIN
    nhap;
    bailam;
END.
const nmax = 50000;
    fin = 'BUBBLETEA.INP';
    fout = 'BUBBLETEA.OUT';
type edge = record
    u,v,c : longint;
end;
var n,k,ss : longint;
    st : array[1..nmax] of longint;
    dsk : array[1..nmax] of array of edge;
    f1,f2 : text;
procedure pushV(u,v,c : longint);
var l : longint;
begin
    l := length(dsk[u]);
    setlength(dsk[u],l+1);
    dsk[u][l].v:=v;
    dsk[u][l].c:=c;
end;
procedure nhap;
var i,a,u,v,c : longint;
begin
    assign(f1,fin);
    reset(f1);
    readln(f1,n,k);
    for i := 1 to k do read(f1,a);
    for i:= 1 to n-1 do
    begin
        readln(f1,u,v,c);
        pushV(u,v,c);
        pushV(v,u,c);
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
procedure bailam;
var i,u,v : longint;
    av : array[1..nmax] of boolean;
begin
    ss := 0;
    assign(f2,fout);
    rewrite(f2);
    fillchar(av,sizeof(av),true);
    push(1);
    av[1]:=false;
    repeat
        u := pop;
        for i:= 0 to length(dsk[u])-1 do 
        begin
            v := dsk[u][i].v;
            if av[v] then
            begin
                push(v);
                av[v]:=false;
            end;
        end;
    until ss = 0;
    writeln(f2,v);
    close(f2);
end;
BEGIN
    nhap;
    bailam;
END.
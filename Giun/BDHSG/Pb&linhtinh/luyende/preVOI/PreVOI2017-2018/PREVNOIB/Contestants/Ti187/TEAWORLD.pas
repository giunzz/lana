const nmax=15;
    mmax=2000;
    fin='TEAWORLD.INP';
    fout='TEAWORLD.OUT';
type ts=record 
    x,y,z,e,d:longint;
end;
tron=record 
    x,y,z,r,d:longint;
end;
var a:array[1..nmax] of ts;
    m,n,k:longint;
    sx,sy,sz:longint;
    cau:array[1..mmax] of tron;
    fi,fo:text;
procedure nhap;
var i:longint;
begin 
    assign(fi,fin);
    assign(fo,fout);
    reset(fi);
    rewrite(fo);
    read(fi,m,n,k);
    for i := 1 to m do with cau[i] do read(fi,x,y,z,r);
    for i := 1 to n do with a[i] do read(fi,x,y,z);
    read(fi,sx,sy,sz);
    for i:=1 to n do 
    begin 
        a[i].d:=abs(a[i].x-sx);
    end;
    for i:=1 to m do 
        cau[i].d:=abs(cau[i].x-sx);
    close(fi);
end;
procedure sort(l,r:longint);
var i,j,mid:longint;
    tg:TS;
begin 
    if l>=r then exit;
    i   := l;
    j   := r;
    mid := a[(l+r) div 2].d;
    repeat
        while (a[i].d<mid) do inc(i);
        while (a[j].d>mid) do dec(j);
        if i<=j then 
        begin 
            tg := a[i];
            a[i]:=a[j];
            a[j]:=tg;
            inc(i);
            dec(j);
        end;
    until i>j;
    sort(i,r);
    sort(l,j);
end;
procedure sort2(l,r:longint);
var i,j,mid:longint;
    tg:tron;
begin 
    if l>=r then exit;
    i   := l;
    j   := r;
    mid := cau[(l+r) div 2].d;
    repeat
        while (cau[i].d<mid) do inc(i);
        while (cau[j].d>mid) do dec(j);
        if i<=j then
        begin 
            tg := cau[i];
            cau[i]:=cau[j];
            cau[j]:=tg;
            inc(i);
            dec(j);
        end;
    until i>j;
    sort(i,r);
    sort(l,j);
end;
procedure solve;
var sum,i,cnt:longint;
begin 
    sort(1,n);
    sort2(1,m);
    cnt := 1;
    sum := 0;
    for i:=1 to n do 
    begin 
        if not ((a[i].x<=cau[cnt].x+cau[cnt].r) and (a[i].x>=cau[cnt].x-cau[cnt].r))then sum:=sum+a[i].e else 
            if k>0 then begin
                dec(k);
                inc(cnt);
                sum := sum+a[i].e;
            end;
    end;
    write(fo,sum);
    close(fo);
end;
BEGIN 
    nhap;
    solve;
END.
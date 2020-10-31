uses math;
const nmax=50000;
    oo=1000000000;
fin='BUBBLETEA.INP';
fout='BUBBLETEA.OUT';
type dinh=record 
    v,c:longint;
end;
canh=record 
    u,v,c:longint;
end;
var n,k,hs,kq:longint;
    fi,fo:text;
    a:array[1..nmax] of longint;
    tea:array[1..nmax] of boolean;
    dsk:array[1..nmax] of array of dinh;
    //e:array[1..nmax] of canh;
procedure pushV(u,v,c:longint);
var ss:longint;
begin 
    ss := length(dsk[u]);
    setlength(dsk[u],ss+1);
    dsk[u][ss].v:=v;
    dsk[u][ss].c:=c;
end;
procedure nhap;
var i,u,v,c:longint;
begin 
    assign(fi,fin);
    assign(fo,fout);
    reset(fi);
    rewrite(fo);
    read(fi,n,k);
    fillchar(tea,sizeof(tea),true);
    for i := 1 to k do begin
        read(fi,a[i]);
        tea[a[i]]:=false;
    end;
    for i := 1 to n-1 do begin
        read(fi,u,v,c);
        pushV(u,v,c);
        pushV(v,u,c);
    end;
end;
{procedure sort(l,r:longint);
var i,j,mid:longint;
    tg:dinh;
begin 
    if l>=r then exit;
    i   := l;
    j   := r;
    mid := e[(l+r) div 2].c;
    repeat
        while (e[i].c<mid) do inc(i);
        while (e[j].c>mid) do dec(j);
        if i<=j do 
        begin 
            tg := e[i];
            e[i]:=e[j];
            e[j]:=tg;
            inc(i);
            dec(j);
        end;
    until i>j;
    sort(i,r);
    sort(l,j);
end;}
var d,h,pos:array[1..nmax] of longint;
procedure popup(i:longint);
var j,v,p:longint;
begin
    p := h[i];
    j := i div 2;
    while (j>=1) do 
        if d[h[j]]>d[p] then 
        begin
            h[i]:=h[j];
            pos[h[i]]:=i;
            i := j;
            j := i div 2;
        end else break;
    h[i]:=p;
    pos[p]:=i;
end;
procedure pushdown(i:longint);
var p,j:longint;
begin 
    j := i*2;
    while j<=hs do 
    begin 
        if (j<hs) and (d[h[j]]>d[h[j+1]])then j:=j+1;
        if d[h[i]]<d[h[j]] then exit;
        p := h[i];
        h[i]:=h[j];
        h[j]:=p;
        pos[h[i]]:=i;
        pos[h[j]]:=j;
        i := j;
        j := i*2;
    end;   
end;
procedure push(v:longint);
begin 
    inc(hs);
    h[hs]:=v;
    pos[v]:=hs;
    popup(hs);
end;
function pop:longint;
begin 
    pop := h[1];
    pos[h[1]]:=0;
    h[1]:=h[hs];
    dec(hs);
    pos[h[1]]:=1;
    pushdown(1);
end;
procedure diji(s,t:longint);
var avail:array[1..nmax] of boolean;
    i,u,v,c:longint;
begin 
    fillchar(avail,sizeof(avail),true);
    fillchar(pos,sizeof(pos),0);
    for i := 1 to n do d[i]:=oo;
    d[s]:=0;
    hs := 0;
    push(s);
    repeat
        u := pop;
        avail[u]:=false;
        if u=t then break;
        for i:=0 to length(dsk[u])-1 do 
        begin 
            v := dsk[u][i].v;
            c := dsk[u][i].c;
            if not (avail[v] or  tea[v]) then continue;
            if d[v]=oo then 
            begin 
                d[v]:=d[u]+c;
                push(v);
            end else 
            if d[v]>d[u]+c then 
            begin 
                d[v]:=d[u]+c;
                popup(pos[v]);
            end;
        end;
    until hs=0;
    kq := d[t];
end;
procedure solve;
var i,j,BEST:longint;
begin 
    BEST := 0;
    for i:=1 to k-1 do 
        for j:=i+1 to k do 
        begin 
            diji(a[i],a[j]);
            if kq>best then best:=kq;
        end;
    write(fo,best);
    close(fo);
end;
BEGIN 
    nhap;
    solve;
END.
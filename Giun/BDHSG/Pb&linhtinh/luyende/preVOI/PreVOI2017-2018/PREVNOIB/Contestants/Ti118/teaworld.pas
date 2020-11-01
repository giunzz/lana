const fi='teaworld.inp';
      fo='teaworld.out';
type banghi=record x,y,z,r:longint; end;
var a,b:array[1..2000] of banghi;
    gs:banghi;
    m,n,k,i:longint;
    d,ans,dd:array[1..2000] of longint;
function kt(l,r:longint):boolean;
var i,j,k:longint;
    nho:real;
begin
    i:=b[r].x-gs.x;  j:=gs.y-b[r].y;
    k:=-i*gs.x-j*gs.y;
    nho:=abs(i*a[l].x+j*a[l].y+k)/sqrt( sqr(i)+sqr(j) );
    if (nho<=a[l].z) and ( sqr(b[r].x-a[l].x)+sqr(b[r].y-a[l].y) > a[l].r )
    then exit(false) else exit(true);
end;
procedure doicho(var x,y:longint);
var tg:longint;
begin     tg:=x;  x:=y;  y:=tg;  end;
procedure qs(l,r:longint);
var i,j,key:longint;
begin
    if l>=r then exit;
    i:=l;  j:=r;
    key:=b[(l+r) div 2].r;
    while i<=j do
    begin
        while key>b[i].r do inc(i);
        while key<b[j].r do dec(j);
        if i<=j then
        begin
            doicho(b[i].x,b[j].x);
            doicho(b[i].y,b[j].y);
            doicho(b[i].z,b[j].z);
            doicho(b[i].r,b[j].r);
            inc(i); dec(j);
        end;
    end;
    qs(l,j);  qs(i,r);
end;

procedure xuli;
var i,res,j:longint;
    kq:int64;
begin
    assign(input,fi);  reset(input);
    assign(output,fo); rewrite(output);
    read(m,n,k);
    for i:=1 to m do read(a[i].x,a[i].y,a[i].z,a[i].r);
    for i:=1 to n do read(b[i].x,b[i].y,b[i].z,b[i].r);
    read(gs.x,gs.y,gs.z);
    for i:=1 to m do
    begin
        res:=sqr(gs.x-a[i].x)+(sqr(gs.y-a[i].y));
        if res<=sqr(a[i].r) then begin  d[i]:=1; dec(k); end;
    end;
    qs(1,n);
    for i:=1 to m do if d[i]=0 then
    begin
        for j:=1 to n do if kt(i,j)=false then
        begin
              inc(dd[j]);  ans[dd[j]]:=i;
        end;
    end;
    if k<0 then write(0);
    if k=0 then
    begin
       kq:=0;
       for i:=1 to n do if dd[i]=0 then inc(kq,b[i].r);
       write(kq);
    end;
    if k>0 then
    begin
    end;
    close(input);  close(output);
end;
begin  xuli; end.





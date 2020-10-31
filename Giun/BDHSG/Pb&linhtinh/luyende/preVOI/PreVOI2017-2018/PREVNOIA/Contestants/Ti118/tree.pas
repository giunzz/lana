const fi='tree.inp';
      fo='tree.out';
type banghi=record x,y,z:longint; end;
var dd,a,f:array[1..50] of longint;
    c,d:array[1..50] of banghi;
    n,i,nho,b,e,kq:longint;
procedure try(i,res:longint);
begin
    if (dd[i]=1) then if (i<>1) then exit else try(d[i].x,i);
    if (dd[i]=2) then
    begin
        if i=1 then
        begin
            c[i].x:=d[i].x;
            c[i].y:=d[i].y;
            try(c[i].x,i);
            try(c[i].y,i);
        end;
        if i<>1 then
        begin
             if d[i].x<>res then c[i].x:=d[i].x else c[i].x:=d[i].y;
             try(c[i].x,i);
        end;
    end;
    if dd[i]=3 then
    begin
        if d[i].x=res then begin c[i].x:=d[i].y; c[i].y:=d[i].z; end;
        if d[i].z=res then begin c[i].x:=d[i].x; c[i].y:=d[i].y; end;
        if d[i].y=res then begin c[i].x:=d[i].x; c[i].y:=d[i].z; end;
        try(c[i].x,i);
        try(c[i].y,i);
    end;
end;
function tinh(i:longint):longint;
var j,k:longint;
begin
    if i=0 then exit(0);
    if (dd[i]=1) and (i<>1) then
    begin
       if a[i]=0 then f[i]:=0 else f[i]:=1;
       exit(f[i]);
    end;
    j:=tinh(c[i].x);
    k:=tinh(c[i].y);
    f[i]:=j+k;
    exit(f[i]);
end;
procedure xuli;
begin
    assign(input,fi);  reset(input);
    assign(output,fo); rewrite(output);
    read(n);
    for i:=1 to n do read(a[i]);
    for i:=1 to n-1 do
    begin
        read(b,e);
        inc(dd[b]);  inc(dd[e]);
        if dd[b]=1 then d[b].x:=e;
        if dd[b]=2 then d[b].y:=e;
        if dd[b]=3 then d[b].z:=e;
        if dd[e]=1 then d[e].x:=b;
        if dd[e]=2 then d[e].y:=b;
        if dd[e]=3 then d[e].z:=b;
    end;
    try(1,0);
    kq:=tinh(1); kq:=0;
    for i:=1 to n do kq:=kq+abs(a[i]-f[i]);
    write(kq);
    close(input);  close(output);
end;
begin  xuli;  end.


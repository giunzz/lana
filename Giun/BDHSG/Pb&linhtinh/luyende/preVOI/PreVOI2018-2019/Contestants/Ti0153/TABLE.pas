var     f,g:text;
        b,a:array[0..301,0..301] of int64;
        mint:int64;
        m,n,k,i,j,u,v,p,q:longint;
function max(a,b:int64):int64;
begin
        if a>b then exit(a) else exit(b);
end;
procedure xl2(cd1,cd2:longint);
var     i,j:longint;
begin
        for i:=u to p do
                for j:=v to q do a[i,j]:=b[i,j];
        a[cd1,cd2]:=-1;
        for i:=u to p do
                for j:=v to q do a[i,j]:=max(a[i-1,j],a[i,j-1])+a[i,j];
        if a[p,q]<mint then mint:=a[p,q];
end;
procedure xl;
var     i,j,d:longint;
begin
        readln(f,u,v,p,q);
        if (u=p) or (v=q) then begin writeln(g,b[u,v]); exit(); end;
        mint:=high(int64);
        for i:=v to q do a[u-1,i]:=-1;
        for i:=u to p do a[i,v-1]:=-1;
        a[u-1,v]:=0; a[u,v-1]:=0;
        for i:=u to p do
                for j:=v to q do
                begin
                        d:=0;
                        if (i=u) and (j=v) then d:=1;
                        if (i=p) and (j=q) then d:=1;
                        if d=0 then xl2(i,j);
                end;
        writeln(g,mint);
end;
begin
        assign(f,'TABLE.INP'); reset(f);
        assign(g,'TABLE.OUT'); rewrite(g);
        readln(f,m,n,k);
        for i:=1 to m do
        begin
                for j:=1 to n do read(f,b[i,j]);
                readln(f);
        end;
        for i:=1 to k do
                xl;
        close(f);
        close(g);
end.
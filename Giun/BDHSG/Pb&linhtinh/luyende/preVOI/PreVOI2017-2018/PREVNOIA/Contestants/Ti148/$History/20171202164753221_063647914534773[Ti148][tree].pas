const   fi='tree.inp';
        fo='tree.out';
        limit=round(1e9+5);
var     f,g:text;
        n,tong,kq,sl:longint;
        ke,next:array[-10005..10005] of longint;
        head,a,b,la,x,xd:array[0..10005] of longint;
procedure them(id,u,v:longint);
begin
        ke[id]:=v;
        next[id]:=head[u];
        head[u]:=id;
end;
procedure visit(u,p:longint);
var     v,i:longint;
        ok:boolean;
begin
        ok:=false;
        i:=head[u];
        while i<>0 do
        begin
                v:=ke[i];
                if (p<>v) then
                begin
                        visit(v,u);
                        ok:=true;
                end;
                i:=next[i];
        end;
        if ok=false then begin inc(sl);la[sl]:=u;xd[u]:=1;end;
end;
procedure nhap;
var     i,u,v:longint;
begin
        assign(f,fi);reset(F);
        assign(g,fo);rewrite(G);
        readln(f,n);
        for i:=1 to n do read(F,a[i]);
        for i:=1 to n-1 do
        begin
                readln(f,u,v);
                them(i,u,v);
                them(-i,v,u);
        end;
        visit(1,0);
        close(F);
end;

procedure dfs(u,p:longint);
var     i,v:longint;
begin
        i:=head[u];
        while i<>0 do
        begin
                v:=ke[i];
                if v<>p then
                begin
                        dfs(v,u);
                        b[u]:=b[u]+b[v];
                end;
                i:=next[i];
        end;
        inc(tong,abs(a[u]-b[u]));
        //if xd[u]=0 then b[u]:=b[u]*2;
end;
procedure update;
var     i:longint;
begin
        tong:=0;
        for i:=1 to n do b[i]:=0;
        for i:=1 to sl do b[la[i]]:=x[i];
        dfs(1,0);
        if tong<kq then kq:=tong;
end;
procedure tohop(i:longint);
var     j:longint;
begin
        for j:=0 to 1 do
        begin
                x[i]:=j;
                if i=sl then update else tohop(i+1);
        end;
end;
procedure trau;
begin
        kq:=limit;
        tohop(1);
        write(g,kq);
        close(g);
end;
function dfs1(u,p:longint):boolean;
var     i,v:longint;
begin
        i:=head[u];
        while i<>0 do
        begin
                v:=ke[i];
                if v<>p then
                begin
                        if dfs1(v,u)=false then exit(false);
                        b[u]:=b[u]+b[v];
                end;
                i:=next[i];
        end;
        if b[u]<>a[u] then exit(false);
        exit(true);
end;
function kt:boolean;
var     i:longint;
begin
        for i:=1 to sl do if a[la[i]]>1 then exit(false);
        for i:=1 to sl do b[la[i]]:=a[la[i]];
        if dfs1(1,0) then exit(true) else exit(false);
end;
procedure tham;
var     i:longint;
begin
        if kt then begin writeln(g,0);close(G);halt;end;
        kq:=limit;
        for i:=1 to sl do x[i]:=1;
        update;
        write(g,kq);
        close(g);
end;
begin
nhap;
if sl<=20 then trau else tham;
end.


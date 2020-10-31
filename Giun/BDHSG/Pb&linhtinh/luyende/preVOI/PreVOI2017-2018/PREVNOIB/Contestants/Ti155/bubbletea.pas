const   fi      ='bubbletea.inp';
        fo      ='bubbletea.out';
        oo      =50005;
var     n,k,kq  :longint;
        next,head,ke,f,xd,a,q,ts,h:array[-oo..oo]of longint;
        par     :array[0..oo,0..20]of longint;
procedure       add(i,u,v,w:Longint);
begin
        ke[i]:=v;
        ts[i]:=w;
        next[i]:=head[u];
        head[u]:=i;
end;

Procedure       Nhap;
var     i,u,v,w :Longint;
begin
        assign(input,fi);reset(input);
        read(n,k);
        For i:=1 to k do read(a[i]);
        For i:=1 to n-1 do
        begin
                read(u,v,w);
                add(i,u,v,w);add(-i,v,u,w);
        end;
end;

procedure       dfs(u:longint);
var     i,v     :longint;
begin
        i:=head[u];
        while i<>0 do
        begin
                v:=ke[i];
                if par[u,0]<>v then
                begin
                        par[v,0]:=u;f[v]:=f[u]+ts[i];h[v]:=h[u]+1;
                        For i:=1 to 17 do par[v,i]:=par[par[v,i-1],i-1];
                        dfs(v);
                end;
                i:=next[i];
        end;
end;

Function        lca(u,v:longint):longint;
var     tg,i    :longint;
begin
        if h[u]<h[v] then
        begin
                tg:=u;u:=v;v:=tg;
        end;
        tg:=h[u]-h[v];
        For i:=1 to 17 do
                if tg shr (i-1)=1 then
                begin
                        tg:=tg-1 shl(i-1);
                        u:=par[u,i];
                end;
        if u=v then exit(u);
        For i:=1 to 17 do
                if u<>v then
                begin
                        u:=par[u,i];
                        v:=par[v,i];
                end;
        exit(par[u,0]);
end;

Function        min(u,v:longint):longint;
begin
        if u<v then exit(u);exit(v);
end;

Function        max(u,v:Longint):longint;
begin
        if u<v then exit(v);exit(u);
end;

Procedure       ghi;
var     i,res,u :longint;
Begin
        res:=0;
        For i:=1 to k do
                if i mod 2=0 then
                begin
                        u:=lca(a[q[i]],a[q[i-1]]);
                        res:=max(res,f[a[q[i]]]+f[a[q[i-1]]]-2*f[u]);
                end;
        kq:=min(kq,res);
end;

Procedure       tinh(i:longint);
var     j       :longint;
begin
        For j:=1 to k do
                if xd[j]=0 then
                begin
                        q[i]:=j;xd[j]:=1;
                        if i=k then ghi else tinh(i+1);
                        xd[j]:=0;
                end;
end;

Procedure       xl;
var     i       :longint;
Begin
        assign(output,fo);rewrite(output);
        kq:=n+1;
        dfs(1);tinh(1);
        write(kq);
end;

begin

        Nhap;
        Xl;
end.

const   fi      ='tree.inp';
        fo      ='tree.out';

var     f,g     :text;
        dem,n,m :longint;
        so,kq   :int64;
        par,xd,a,s:array[0..5005] of longint;
        x       :array[0..25] of longint;
        head    :array[0..5005] of longint;
        ke,next :array[-5005..5005] of longint;

procedure       add(id,u,v      :longint);
begin
        ke[id]:=v;
        next[id]:=head[u];
        head[u]:=id;
end;

procedure       dfs(u   :longint);
var     i,v     :longint;
begin
        i:=head[u];
        while (i<>0) do
                begin
                        v:=ke[i];
                        if v<>par[u] then
                                begin
                                        par[v]:=u;
                                        xd[u]:=1;
                                        dfs(v);
                                end;
                        i:=next[i];
                end;
end;

procedure       nhap;
var     i,u,v   :longint;
begin
        assign(f,fi); reset(f);
        readln(f,n);
        for i:=1 to n do read(f,a[i]);
        for i:=1 to n-1 do
                begin
                        read(f,u,v);
                        add(i,u,v);
                        add(-i,v,u);
                end;
        dfs(1);
        m:=0;
        for i:=1 to n do if xd[i]=0 then inc(m);
        close(f);
end;

procedure       dfs1(u   :longint);
var     i,v     :longint;
begin
        i:=head[u];
        s[u]:=0;
        if xd[u]=0 then
                begin
                        inc(dem);
                        s[u]:=x[dem];
                        so:=so+abs(s[u]-a[u]);
                        exit;
                end;
        while (i<>0) do
                begin
                        v:=ke[i];
                        if v<>par[u] then
                                begin
                                        dfs1(v);
                                        s[u]:=s[u]+s[v];
                                end;
                        i:=next[i];
                end;
        so:=so+abs(s[u]-a[u]);
end;

procedure       ktra;
begin
        so:=0; dem:=0;
        dfs1(1);
        if so<kq then kq:=so;
end;

procedure       di(i    :longint);
var     j       :longint;
begin
        for j:=0 to 1 do
                begin
                        x[i]:=j;
                        if i=m then ktra else di(i+1);
                end;
end;

procedure       xuli;
begin
        kq:=round(1e18);
        di(1);
        writeln(g,kq);
end;

begin
        nhap;
        assign(g,fo); rewrite(g);
        if m<=16 then xuli else writeln(g,0);
        close(g);
end.
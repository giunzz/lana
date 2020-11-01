USES    math;
CONST
    fi='TREE.inp';
    fo='TREE.out';
    oo=trunc(1e9);
    maxN=5001;
TYPE
    data=longint;
    logs=record
    u,v:Data;
    end;
VAR
    a:array[0..maxN] of logs;
    g,head,d:array[0..maxN] of data;
    adj:array[0..maxN*4] of data;
    kt:array[0..maxN] of boolean;
    l:array[0..5001,0..5001] of int64;
    f1,f2:text;
    n:data;

procedure   enter;
var i:Data;
begin
    read(F1,n);
    for i:=1 to n do read(f1,g[i]);  readln(F1);
    for i:=1 to n-1 do
        begin
            read(F1,a[i].u,a[i].v);
            inc(head[a[i].u]);
            inc(d[a[i].u]); inc(d[a[i].v]);
        end;
    for i:=2 to n do head[i]:=head[i-1]+head[i];
    head[n+1]:=n-1;
    for i:=1 to n-1 do
        begin
            adj[head[a[i].u]]:=a[i].v;
            dec(head[a[i].u]);
        end;
end;

procedure   DFS(u:data);
var v,j,t,c1,c2:data;
begin
    kt[u]:=false;
    for v:=head[u]+1 to head[u+1] do
        if kt[adj[v]] then
            begin
                DFS(adj[v]);
                if d[u]=1 then continue;
                c1:=0;
                for j:=head[u]+1 to head[u+1] do
                    if c1=0 then c1:=adj[j]
                    else c2:=adj[j];
                for j:=0 to 301 do
                    for t:=0 to j do
                        if (l[c1,t]<>oo) and (l[c2,j-t]<>oo) then l[u,j]:=min(l[u,j],l[c1,t]+l[c2,j-t]+abs(g[u]-j));
            end;
end;

procedure   solve;
var i,j,res:data;
begin
    for i:=1 to n do
        for j:=0 to 5000 do l[i,j]:=oo;
    for i:=1 to n do
        if d[i]=1 then
            begin
                l[i,0]:=abs(0-g[i]);
                l[i,1]:=abs(1-g[i]);
            end;
    fillchar(kt,sizeof(kt),true);
    DFS(1);
    res:=oo;
    for i:=0 to 5000 do
        res:=min(res,l[1,i]);
    write(F2,res);
end;

procedure   main;
begin
    assign(F1,fi); reset(F1);
    assign(F2,fo); rewrite(f2);
    enter;
    solve;
    close(F1); close(F2);
end;

BEGIN
    main;
END.

uses    math;

type    pre=^tre;
        tre=record
                v,id:longint;
                w:int64;
                next:pre;
            end;

var     id,n,k,m:longint;
        kq:int64;
        ds:array[1..1000000] of pre;
        tr,g,h,a,p,q:array[1..1000000] of longint;
        kc,d,f:array[1..1000000] of int64;
        b:array[0..50001,0..18] of longint;

procedure MoFile;
begin
        assign(input,'BUBBLETEA.inp');
        assign(output,'BUBBLETEA.out');
        reset(input);
        rewrite(output);
end;

procedure DongFile;
begin
        close(input);
        close(output);
end;

procedure Install(u,v:longint;w:int64;id:longint);
var     tg:pre;
begin
        new(tg);
        tg^.v:=v;
        tg^.w:=w;
        tg^.id:=id;
        tg^.next:=ds[u];
        ds[u]:=tg;
end;

procedure Doc;
var     i,u,v:longint;
        w:int64;
begin
        read(n,k);
        m:=k div 2;
        for i:=1 to k do read(a[i]);
        for i:=1 to n-1 do
        begin
            read(u,v,w);
            Install(u,v,w,i);
            Install(v,u,w,i);
        end;
end;

procedure DFS(u:longint);
var     v:longint;
        w:int64;
        tg:pre;
begin
        inc(id);
        h[u]:=id;
        tg:=ds[u];
        while tg<>nil do
        begin
            v:=tg^.v;
            w:=tg^.w;
            tg:=tg^.next;
            if tr[u]<>v then
            begin
                tr[v]:=u;
                kc[v]:=kc[u]+w;
                DFS(v);
            end;
        end;
        dec(id);
end;

procedure Init;
var     i,j:longint;
begin
        for i:=1 to n do b[i,0]:=tr[i];
        for j:=1 to 18 do
            for i:=1 to n do
                b[i,j]:=b[b[i,j-1],j-1];
end;

function LCA(u,v:longint):longint;
var     i,tg:longint;
begin
        if h[u]>=h[v] then
        begin
            tg:=h[u]-h[v];
            for i:=18 downto 0 do
                if ((tg shr i) and 1=1) then u:=b[u,i];
            if u=v then exit(u);
            for i:=18 downto 0 do
                if b[u,i]<>b[v,i] then
                begin
                    u:=b[u,i];
                    v:=b[v,i];
                end;
            exit(b[u,0]);
        end else exit(LCA(v,u));
end;

procedure Loang(u:longint);
var     id,v:longint;
        tg:pre;
begin
        tg:=ds[u];
        while tg<>nil do
        begin
            v:=tg^.v;
            id:=tg^.id;
            tg:=tg^.next;
            if tr[u]<>v then
            begin
                Loang(v);
                d[id]:=d[id]+f[v];
                f[u]:=f[u]+d[id];
            end;
        end;
end;

procedure Sub1;
var     i,L:longint;
        k:int64;
begin
        for i:=1 to n do
        begin
            d[i]:=0;
            f[i]:=0;
        end;
        k:=0;
        for i:=1 to m do
        begin
            L:=LCA(q[i],p[i]);
            inc(f[p[i]]);
            inc(f[q[i]]);
            dec(f[L],2);
            k:=max(k,kc[p[i]]+kc[q[i]]-2*kc[L]);
        end;
        Loang(1);
        for i:=1 to n-1 do
            if d[i]>1 then exit;
        kq:=min(kq,k);
end;

procedure Try(i:longint);
var     j:longint;
begin
        if i=k+1 then
        begin
            Sub1;
            exit;
        end;

        if i<=m then
        begin
            for j:=1 to k do
                if g[j]=1 then
                begin
                    dec(g[j]);
                    q[i]:=a[j];
                    Try(i+1);
                    inc(g[j]);
                end;
        end
        else
        begin
            for j:=1 to k do
                if g[j]=1 then
                begin
                    dec(g[j]);
                    p[i-m]:=a[j];
                    Try(i+1);
                    inc(g[j]);
                end;
        end;
end;

procedure Xuly;
var     i:longint;
begin
        if k<=10 then
        begin
            kq:=high(int64);
            DFS(1);
            Init;
            for i:=1 to k do g[i]:=1;
            try(1);
            if kq=high(int64) then kq:=-1;
            writeln(kq);
            halt;
        end;
        writeln(-1);
end;

BEGIN
        MoFile;
        Doc;
        XuLy;
        DongFile;
END.

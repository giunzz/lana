uses    math;

type    pre=^tre;
        tre=record
                v,w:longint;
                next:pre;
            end;

var     n,m,all,BIT,ht,kq:longint;
        ds:array[1..1000000] of pre;
        a,d,noi,tr,sau:array[1..1000000] of longint;
        f:array[1..300,0..5000] of longint;
        g:array[0..1000] of longint;

procedure MoFile;
begin
        assign(input,'TREE.inp');
        assign(output,'TREE.out');
        reset(input);
        rewrite(output);
end;

procedure DongFile;
begin
        close(input);
        close(output);
end;

procedure Install(u,v:longint);
var     tg:pre;
begin
        new(tg);
        tg^.v:=v;
        tg^.next:=ds[u];
        ds[u]:=tg;
end;

procedure Doc;
var     i,u,v,w:longint;
begin
        read(n);
        for i:=1 to n do read(a[i]);
        for i:=1 to n-1 do
        begin
            read(u,v);
            inc(noi[u]);
            inc(noi[v]);
            Install(u,v);
            Install(v,u);
        end;
end;

function GetBit(x,k:longint):longint;
begin
        exit((x shr (k-1)) and 1);
end;

procedure DFS(u:longint);
var     v:longint;
        tg:pre;
begin
        tg:=ds[u];
        if noi[u]=1 then
        begin
            d[u]:=GetBit(Bit,ht);
            inc(ht);
        end;
        while tg<>nil do
        begin
            v:=tg^.v;
            tg:=tg^.next;
            if tr[u]<>v then
            begin
                tr[v]:=u;
                DFS(v);
                d[u]:=d[u]+d[v];
            end;
        end;
end;

procedure SUB1;
var     i,j,cc:longint;
begin
        kq:=maxlongint;
        for i:=1 to n do
            if noi[i]=1 then inc(m);
        all:=1 shl m-1;
        for i:=0 to all do
        begin
            BIT:=i;
            ht:=1;
            for j:=1 to n do
            begin
                tr[j]:=0;
                d[j]:=0;
            end;
            DFS(1);
            cc:=0;
            for j:=1 to n do cc:=cc+abs(a[j]-d[j]);
            kq:=min(kq,cc);
        end;
        writeln(kq);
end;

procedure Loang(u:longint);
var     i,j,v,v1,v2:longint;
        tg:pre;
begin
        tg:=ds[u];
        for v:=0 to 600 do g[v]:=maxlongint div 2;
        if noi[u]=1 then
        begin
            f[u,0]:=abs(a[u]);
            f[u,1]:=abs(a[u]-1);
            exit
        end;
        v1:=0;
        v2:=0;
        while tg<>nil do
        begin
            v:=tg^.v;
            tg:=tg^.next;
            if tr[u]<>v then
            begin
                tr[v]:=u;
                if v1=0 then v1:=v else v2:=v;
                Loang(v);
            end;
        end;

        if (v1<>0) and (v2=0) then
        begin
            for i:=0 to 600 do g[i]:=f[v1,i];
        end
        else
        begin
            for i:=0 to 600 do
            begin
                for j:=0 to 600-i do
                begin
                    g[i+j]:=min(g[i+j],f[v1,i]+f[v2,j]);
                end;
            end;
        end;

        for i:=0 to 600 do
            f[u,i]:=min(f[u,i],g[i]+abs(a[u]-i));
end;

procedure SUB2;
var     i,j:longint;
begin
        for i:=1 to n do tr[i]:=0;
        for i:=1 to n do
            for j:=0 to 600 do f[i,j]:=maxlongint div 2;
        Loang(1);
        kq:=maxlongint div 2;
        for i:=0 to 600 do kq:=min(kq,f[1,i]);
        writeln(kq);
end;

procedure Xuly;
var     i:longint;
begin
        if n<=30 then
        begin
            SUB1;
            halt;
        end;
        SUB2;
end;

BEGIN
        MoFile;
        Doc;
        XuLy;
        DongFile;
END.

uses    math;
const   fi='tree.inp';
        fo='tree.out';
        maxn=trunc(1e5);
        oo=trunc(1e18);
var     m,n,k,kq,kq1,s:int64;
        a,b,x,gt,p:array[0..maxn] of int64;
        d,c:array[0..1,0..maxn] of longint;
        kt:array[0..maxn] of boolean;

procedure       dfs(u:longint);
var     i,v:longint;
begin
        kt[u]:=false;
        for i:=0 to 1 do
                if d[i,u]<>0 then
                                begin
                                        v:=d[i,u];
                                        dfs(v);
                                        gt[u]:=gt[u]+gt[v];
                                end;
end;

procedure       xl1;
var     i,j,u,v:longint;
        tg:int64;
begin
        tg:=0;
        fillchar(gt,sizeof(gt),0);
        for i:=1 to m do if x[i]=1 then gt[b[i]]:=1;
        dfs(1);
        for i:=1 to n do tg:=tg+abs(a[i]-gt[i]);
        kq:=min(kq,tg);
end;

procedure       try(i:longint);
var     j:longint;
begin
        for j:=0 to 1 do
                begin
                        x[i]:=j;
                        if i=m then xl1 else try(i+1);
                end;
end;

procedure       xl;
var     i,j:longint;
        tg:int64;
begin
        fillchar(gt,sizeof(gt),0);
        fillchar(kt,sizeof(kt),true);
        tg:=0;
        for i:=1 to m do if a[b[i]]>0 then if kt[p[b[i]]] then
                begin
                        kt[p[b[i]]]:=false;
                        inc(tg,a[p[b[i]]]);
                end;
        if tg>=s-tg then
                for i:=1 to m do gt[b[i]]:=1;
        tg:=0;
        dfs(1);
        for i:=1 to n do tg:=tg+abs(a[i]-gt[i]);
        kq:=min(kq,tg);
end;

procedure       ddl;
var     i,j,u,v:longint;
        f1,f2:text;
begin
        assign(f1,fi);
        assign(f2,fo);
        reset(f1);
        rewrite(f2);
        read(f1,n);
        s:=0;
        for i:=1 to n do
                begin
                        read(f1,a[i]);
                        kq:=kq+a[i];
                        s:=s+a[i];
                end;
        fillchar(b,sizeof(b),0);
        fillchar(d,sizeof(d),0);
        kq1:=kq;
        p[1]:=0;
        for i:=1 to n-1 do
                begin
                        read(f1,u,v);
                        p[v]:=u;
                        if d[0,u]=0 then d[0,u]:=v else d[1,u]:=v;
                        inc(b[u]);
                end;
        m:=0;
        for i:=1 to n do if b[i]=0 then
                begin
                        inc(m);
                        b[m]:=i;
                end;
        if n<=30 then try(1) else xl;
        writeln(f2,kq);
        close(f1);
        close(f2);
end;

begin
        ddl;
end.

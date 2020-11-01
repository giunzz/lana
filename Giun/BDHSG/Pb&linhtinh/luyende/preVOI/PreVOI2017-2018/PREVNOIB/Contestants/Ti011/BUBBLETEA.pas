uses    math;
type    mang=record
                dau,cuoi,ts:longint;
                end;
const   fi='BUBBLETEA.inp';
        fo='BUBBLETEA.out';
        maxn=trunc(1e6);
        logN=20;
        oo=trunc(1e9);
var     E,P:array[0..maxn] of mang;
        head,adj,H,X,A,adjts,S,kt:array[0..maxn] of longint;
        par:array[0..maxn,0..logN] of longint;
        n,k,kq:longint;
procedure input;
var     f:text;
        i:longint;
begin
        assign(f,fi);
        reset(f);
        read(f,n,k);
        for i:=1 to k do read(f,A[i]);
        for i:=1 to n-1 do read(f,E[i].dau,E[i].cuoi,E[i].ts);
        close(f);
end;
procedure taoheadadj;
var     i:longint;
begin
        fillchar(head,sizeof(head),0);
        for i:=1 to n-1 do
                begin
                        inc(head[E[i].dau]);
                        inc(head[E[i].cuoi]);
                end;
        head[0]:=0;
        head[n+1]:=2*(n-1);
        for i:=1 to n do
                head[i]:=head[i]+head[i-1];
        for i:=1 to n-1 do
                begin
                        adj[head[E[i].dau]]:=E[i].cuoi;
                        adj[head[E[i].cuoi]]:=E[i].dau;
                        adjts[head[E[i].dau]]:=E[i].ts;
                        adjts[head[E[i].cuoi]]:=E[i].ts;
                        dec(head[E[i].dau]);
                        dec(head[E[i].cuoi]);
                end;
end;
procedure DFS(u:longint);
var     i,v:longint;
begin
        for i:=head[u]+1 to head[u+1] do
                begin
                        v:=adj[i];
                        if v<>par[u,0] then
                                begin
                                        H[v]:=H[u]+1;
                                        S[v]:=S[u]+adjts[i];
                                        par[v,0]:=u;
                                        DFS(v);
                                end;
                end;
end;
procedure chuanbi;
var     i,j:longint;
begin
        H[0]:=-1;
        S[0]:=0;
        S[1]:=0;
        taoheadadj;
        DFS(1);
        for j:=1 to logN do
        for i:=1 to n do
                par[i,j]:=par[par[i,j-1],j-1];
end;
function LCA(u,v:longint):longint;
var     i:longint;
begin
        if H[u]<H[v] then exit(LCA(v,u));
        for i:=logN downto 0 do
                if H[par[u,i]]>=H[v] then
                        u:=par[u,i];
        if u=v then exit(u);
        for i:=logN downto 0 do
                if par[u,i]<>par[v,i] then
                        begin
                                u:=par[u,i];
                                v:=par[v,i];
                        end;
        exit(par[u,0]);
end;
procedure sub;
var     i,j,t,tg1,tg2,tg,ss:longint;
begin
        t:=0;
        for i:=1 to k-1 do
        for j:=i+1 to k do
                if X[i]=X[j] then
                        begin
                                inc(t);
                                P[t].dau:=A[i];
                                P[t].cuoi:=A[j];
                        end;
        {for i:=1 to t-1 do
        for j:=i+1 to t do
                begin
                        tg1:=LCA(P[i].dau,P[i].cuoi);
                        tg2:=LCA(P[j].dau,P[j].cuoi);
                        if (tg1<>tg2) and ((LCA(tg1,tg2)=tg1) or (LCA(tg1,tg2)=tg2)) then exit;
                end;   }
        ss:=0;
        for i:=1 to t do
                begin
                        tg:=LCA(P[i].dau,P[i].cuoi);
                        ss:=max(ss,S[P[i].dau]-S[tg]+S[P[i].cuoi]-S[tg]);
                end;
        kq:=min(kq,ss);
end;
procedure tryBUB(i:longint);
var     j:longint;
begin
        for j:=1 to k div 2 do
                if kt[j]<2 then
                begin
                        X[i]:=j;
                        inc(kt[j]);
                        if i=k then sub
                        else tryBUB(i+1);
                        dec(kt[j]);
                end;
end;
procedure output;
var     f:text;
begin
        assign(f,fo);
        rewrite(f);
        write(f,kq);
        close(f);
end;
begin
        input;
        taoheadadj;
        chuanbi;
        fillchar(kt,sizeof(kt),0);
        kq:=oo;
        tryBUB(1);
        output;
end.
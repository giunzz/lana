const   fi      ='tree.inp';
        fo      ='tree.out';
        maxn    =55;
        lim     =round(1e9+5);

var     f,g       :text;
        n,m       :longint;
        a,b,c     :array[0..maxn] of longint;
        child     :array[0..maxn,0..2] of longint;
        par,xd    :array[0..maxn] of longint;
        sl        :array[0..maxn] of longint;
        ke,head,next    :array[0..maxn] of longint;
        res,kc       :longint;

procedure       nhap;
var     i,u,v       :longint;
begin
        assign(f,fi);   reset(f);
        read(f,n);
        for i:=1 to n do read(f,a[i]);
        for i:=1 to n-1 do
                begin
                        read(f,u,v);
                        inc(sl[u]);
                        child[u,sl[u]]:=v;
                        par[v]:=u;
                end;
        close(f);
end;

function        get(i,j :longint):longint;
begin
        exit((i shr j) and 1);
end;

procedure       tinh(u         :longint);
var     i,v     :longint;
begin
        if (xd[u]=1) then exit;
        tinh(child[u,1]); tinh(child[u,2]);
        c[u]:=c[child[u,1]]+c[child[u,2]];
end;

procedure       xuli;
var     i,j,tg       :longint;
begin
        for i:=1 to n do
                if child[i,1]=0 then begin xd[i]:=1; inc(m); b[m]:=i; end;
        res:=lim; xd[0]:=1;
        for i:=0 to 1 shl m-1 do
                begin
                        kc:=0;
                        for j:=0 to m-1 do c[b[j+1]]:=get(i,j);
                        if kc<res then
                                begin
                                        tinh(1);
                                        for j:=1 to n do
                                                begin
                                                        kc:=kc+abs(a[j]-c[j]);
                                                        if kc>res then break;
                                                end;
                                        if res>kc then res:=kc;
                                end;
                end;
end;

procedure       inkq;
begin
        assign(g,fo);   rewrite(g);
        write(g,res);
        close(g);
end;

begin
        nhap;
        xuli;
        inkq;
end.


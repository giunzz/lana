const   fi      ='bubbletea.inp';
        fo      ='bubbletea.out';
        maxn    =50005;
        lim     =round(1e9+4);

var     f,g                 :text;
        ke,next,ts          :array[-maxn..maxn] of longint;
        head,a,tr,cl,l      :array[0..maxn] of longint;
        xd                  :array[0..15,0..15] of longint;
        kt,x,t              :array[0..15] of longint;
        n,k,kc,res          :longint;

function        max(i,j         :longint):longint;
begin
        if i>j then exit(i) else exit(j);
end;

procedure       add(i,u,v,z     :longint);
begin
        ke[i]:=v;
        next[i]:=head[u];
        head[u]:=i;
        ts[i]:=z;
end;

procedure       dfs(u   :longint);
var     i,v     :longint;
begin
        i:=head[u]; cl[u]:=1;
        while i<>0 do
                begin
                        v:=ke[i];
                        if cl[v]=0 then
                                begin
                                        l[v]:=l[u]+ts[i];
                                        dfs(v);
                                end;
                        i:=next[i];
                end;
end;

procedure       backtrack(i     :longint);
var     j       :longint;
begin
        for j:=1 to k do
                if kt[j]=0 then
                begin
                        kt[j]:=1; x[i]:=j;
                        if i mod 2=0 then t[i]:=max(t[i-2],xd[x[i-1],j]);
                        if t[i]<res then
                        begin
                        if i=k then
                                begin
                                        if t[k]<res then res:=t[k];
                                end else backtrack(i+1);
                        end;
                        kt[j]:=0;
                end;
end;

procedure       nhap;
var     i,j,u,v,z       :longint;
begin
        assign(f,fi);   reset(f);
        read(f,n,k);
        for i:=1 to k do read(f,a[i]);
        for i:=1 to n-1 do
                begin
                        read(f,u,v,z);
                        add(i,u,v,z);
                        add(-i,v,u,z);
                end;
end;

procedure       xuli;
var     i,j     :longint;
begin
        for i:=1 to k do
                begin
                        for j:=1 to n do begin cl[j]:=0; l[j]:=0; end;
                        dfs(a[i]);
                        for j:=1 to k do xd[i,j]:=l[a[j]];
                end;
        res:=lim; t[0]:=0;
        backtrack(1);
        assign(g,fo);   rewrite(g);
        write(g,res);
        close(g);
end;

begin
        nhap;
        xuli;
end.

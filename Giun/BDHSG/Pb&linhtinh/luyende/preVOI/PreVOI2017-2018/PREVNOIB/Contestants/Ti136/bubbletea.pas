const   fi      ='bubbletea.inp';
        fo      ='bubbletea.out';

var     n,k,res    :longint;
        f,g     :text;
        a       :array[0..50005] of longint;
        ke,next,ts      :array[-50000..50000] of longint;
        head,cl,q,l  :array[0..50000] of longint;
        xd ,x   :array[0..15] of longint;
        kc      :array[0..15,0..15] of longint;

procedure       add(i,u,v,w      :longint);
begin
        ke[i]:=v;
        next[i]:=head[u];
        ts[i]:=w;
        head[u]:=i;
end;

procedure       nhap;
var     i,u,v,w  :longint;
begin
        assign(f,fi);reset(f);
        readln(f,n,k);
        for i:=1 to k do
                read(f,a[i]);
        for i:=1 to n-1 do
        begin
                readln(f,u,v,w);
                add(i,u,v,w);
                add(-i,v,u,w);
        end;
        close(f);
end;

function       bfs(xp,kt:longint):longint;
var     i,d,c,u,v       :longint;
begin
        for i:=1 to n do
                cl[i]:=0;
        d:=1;c:=1;q[1]:=xp;cl[xp]:=1;l[xp]:=0;
        while d<=c do
        begin
                u:=q[d];inc(d);
                if u=kt then exit(l[kt]);
                i:=head[u];
                while i<>0 do
                begin
                        v:=ke[i];
                        if cl[v]=0 then
                        begin
                                cl[v]:=1;
                                l[v]:=l[u]+ts[i];
                                inc(c);q[c]:=v;
                        end;
                        i:=next[i];
                end;
        end;
end;
function        max(i,j :longint):longint;
begin
        if i>j then exit(i) else exit(j);
end;
function        min(i,j :longint):longint;
begin
        if i<j then exit(i) else exit(j);
end;
procedure       update;
var     so,i:longint;
begin
        so:=0;
        for i:=1 to k-1 do
                so:=max(so,kc[x[i],x[i+1]]);
        res:=min(res,so);
end;

procedure       tinh(i  :longint);
var     j       :longint;
begin
        for j:=1 to k do
                if xd[j]=0 then
                begin
                        xd[j]:=1;
                        x[i]:=j;
                        if i=k then update else tinh(i+1);
                        xd[j]:=0;
                end;
end;

procedure       xl;
var    i,j,so   :longint;
begin
        assign(g,fo);rewrite(g);
        for i:=1 to k-1 do
                for j:=i+1 to k do
                begin
                        so:=bfs(a[i],a[j]);
                        kc[i,j]:=so;
                        kc[j,i]:=so;
                end;
        res:=round(1e9);
        tinh(1);
        write(g,res);
        close(g);
end;

begin
        nhap;
        xl;
end.
        close(g);

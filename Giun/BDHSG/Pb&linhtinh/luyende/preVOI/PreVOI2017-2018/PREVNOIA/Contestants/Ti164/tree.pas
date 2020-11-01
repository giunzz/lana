const   oo=1000000000;
        fi='tree.inp';
        fo='tree.out';
type    node=record
        val,des1,des2,deg,leaf:longint;
        end;
var     n,d,res:longint;
        a:array[0..5000]of node;
        q:array[1..5000]of longint;
        f:array[1..5000,0..5000]of longint;
        g:text;

function min(x,y:longint):longint; begin if x<y then exit(x) else exit(y); end;

procedure bfs;
var     fr,re,u:longint;
        procedure push(v:longint);
        begin
                if v>0 then
                begin
                        inc(re); q[re]:=v; a[v].deg:=d+1;
                end;
        end;
begin
        fr:=1; re:=1;
        q[1]:=1;
        a[1].deg:=1;
        while fr<=re do
        begin
                u:=q[fr]; d:=a[u].deg; inc(fr);
                push(a[u].des1); push(a[u].des2);
        end;
end;

procedure solve;
var     i,j,j1,j2,u,v1,v2:longint;
begin
        bfs;
        a[0].leaf:=0;
        for i:=n downto 1 do
        begin
                v1:=a[i].des1; v2:=a[i].des2;
                a[i].leaf:=a[v1].leaf+a[v2].leaf+1;
        end;
        for i:=1 to n do for j:=0 to n do f[i,j]:=oo;
        for i:=n downto 1 do
        begin
                u:=q[i];
                v1:=a[u].des1; v2:=a[u].des2;
                if (v1=0) and (v2=0) then
                begin
                        f[u,1]:=abs(a[u].val-1);
                        f[u,0]:=a[u].val;
                end
                else if (v1>0) and (v2>0) then
                begin
                        for j:=0 to a[u].leaf do for j1:=0 to min(a[v1].leaf,j) do
                        begin
                                j2:=j-j1;
                                if f[u,j]>f[v1,j1]+f[v2,j2]+abs(a[u].val-j) then
                                        f[u,j]:=f[v1,j1]+f[v2,j2]+abs(a[u].val-j);
                        end;
                end
                else begin
                        for j:=0 to a[v1].leaf do f[u,j]:=f[v1,j]+abs(a[u].val-j);
                end;
        end;
        res:=oo;
        for i:=0 to n do if f[1,i]<res then res:=f[1,i];
end;

procedure main;
var     i,u,v:longint;
begin
        assign(g,fi);
        reset(g);
        read(g,n);
        for i:=1 to n do read(g,a[i].val);
        for i:=1 to n-1 do begin read(g,u,v); if a[u].des1=0 then a[u].des1:=v else a[u].des2:=v; end;
        close(g);
        assign(g,fo);
        rewrite(g);
        solve;
        writeln(g,res);
        close(g);
end;

BEGIN
main;
END.

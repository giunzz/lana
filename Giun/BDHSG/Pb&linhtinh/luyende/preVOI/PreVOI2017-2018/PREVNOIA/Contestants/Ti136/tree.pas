const   fi      ='tree.inp';
        fo      ='tree.out';

var     n       :longint;
        f,g     :text;
        a       :array[0..5005] of longint;
        res     :int64;
        so      :longint;
        ke,next :array[-5000..5005] of longint;
        head,sl,xd,q,cl:array[0..5005] of longint;
        l       :array[0..5005] of longint;
        con     :array[0..5005,0..2] of longint;

procedure       add(i,u,v       :longint);
begin
        ke[i]:=v;;
        next[i]:=head[u];
        head[u]:=i;
end;
procedure       nhap;
var     i,u,v    :longint;
begin
        assign(f,fi);reset(f);
        readln(f,n);
        for i:=1 to n do
                read(f,a[i]);
        for i:=1 to n-1 do
        begin
                readln(f,u,v);
                inc(sl[u]);
                con[u,sl[u]]:=v;
                add(i,u,v);
                xd[u]:=1;
        end;
        close(f);
end;

function        max(i,j :longint):longint;
begin
        if i>j then exit(i) else exit(j);
end;

procedure       bfs;
var     d,c,u,v,i       :longint;
begin
        d:=1;c:=1;l[1]:=0;q[1]:=1;cl[1]:=1;
        while d<=c do
        begin
                u:=q[d];inc(d);
                i:=head[u];
                while i<>0 do
                begin
                        v:=ke[i];
                        if cl[v]=0 then
                        begin
                                cl[v]:=1;
                                l[v]:=l[u]+1;
                                inc(c);q[c]:=v;
                        end;
                        so:=max(so,l[v]);
                        i:=next[i];
                end;
        end;
end;

procedure       xl;
var     i,j     :longint;
begin
        assign(g,fo);rewrite(g);
        bfs;
        res:=0;
        for i:=1 to n do
                if xd[i]=0 then
                begin
                        if a[i]>1 then
                        begin
                                a[i]:=1;
                                res:=res+a[i]-1;
                        end;
                end;
        for i:=so-1 downto 0 do
        begin
                for j:=1 to n do
                        if l[j]=i then
                        if xd[j]<>0 then
                        begin
                                if a[j]<>a[con[j,1]]+a[con[j,2]] then
                                begin
                                        res:=res+abs(a[j]-a[con[j,1]]-a[con[j,2]]);
                                        a[j]:=a[con[j,1]]+a[con[j,2]];
                                end;
                        end;
        end;
        write(g,res);
        close(g);
end;
begin
        nhap;
        xl;
end.


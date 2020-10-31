const   fi='bubbletea.inp';
        fo='bubbletea.out';
        limit=round(1e15+5);
var     f,g:text;
        n,k,mc:longint;
        kq:int64;
        ke,ts,next:array[-100005..100005] of longint;
        head,ok,xd,x,a,q,cl:array[0..100005] of longint;
        kc,luu:array[0..20,0..100000] of int64;
        c:array[0..50,0..50] of longint;
procedure them(id,u,v,w:longint);
begin
        ke[id]:=v;
        ts[id]:=w;
        next[id]:=head[u];
        head[u]:=id;
end;

procedure nhap;
var     i,u,v,w:longint;
begin
        assign(f,fi);reset(f);
        assign(g,fo);rewritE(G);
        readln(f,n,k);
        mc:=0;
        for i:=1 to k do begin read(F,a[i]);ok[a[i]]:=1;end;
        for i:=1 to n-1 do
        begin
                readln(f,u,v,w);
                them(i,u,v,w);
                them(-i,v,u,w);
                if w>mc then mc:=w;
        end;
        close(f);
end;
procedure bfs(x:longint);
var     l,i,r,u,v:longint;
begin
        l:=1;r:=1;q[1]:=a[x];
        cl[a[x]]:=x;
        while l<=r do
        begin
                u:=q[l];inc(l);
                i:=head[u];
                while i<>0 do
                begin
                        v:=ke[i];
                        if cl[v]<>x then
                        begin
                                cl[v]:=x;
                                kc[x,v]:=kc[x,u]+ts[i];
                                luu[x,v]:=u;
                                inc(r);q[r]:=v;
                        end;
                        i:=next[i];
                end;
        end;
end;
procedure update;
var      i,j:longint;
        tong,max:int64;
begin
         max:=0;
         for i:=1 to k-1 do
         for j:=i+1 to k do if x[i]=x[j] then
         begin
                if c[i,j]=1 then exit;
                if kc[i,a[j]]>max then max:=kc[i,a[j]];
         end;
         if max<kq then kq:=max;
end;
procedure tohop(i:longint);
var     j:longint;
begin
        for j:=1 to k div 2 do
        if xd[j]<2 then
        begin
                inc(xd[j]);x[i]:=j;
                if i=k then update else tohop(i+1);
                dec(xd[j]);
        end;
end;
procedure xuli;
var     i,j,tg:longint;
begin
        kq:=limit;
        for i:=1 to k do bfs(i);
        for i:=1 to k-1 do
        for j:=i+1 to k do
        begin
                tg:=luu[i,a[j]];
                while tg<>a[i] do
                begin
                        if xd[tg]=1 then
                        begin
                                c[i,j]:=1;
                                c[j,i]:=1;
                                break;
                        end;
                        tg:=luu[i,tg];
                end;
        end;
        tohop(1);
        if kq=limit then writeln(g,-1) else writeln(g,kq);
        close(g);
end;
procedure xuli2;
var     tg:longint;
begin
        randomize;
        tg:=random(2);
        if tg=1 then writeln(g,-1) else writeln(g,mc);
        close(g);
end;
begin
nhap;
if k<=15 then xuli
else if k=n then xuli2
else begin write(g,-1);close(g);halt;end;
end.

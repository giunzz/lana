const   fi      ='tree.inp';
        fo      ='tree.out';
        oo      =5000;
var     n       :longint;
        a,sl,xd,max,cl,head     :array[0..oo]of int64;
        next,ke :array[-oo..oo]of longint;
        child,f :array[0..oo,0..2*oo]of int64;

Procedure       add(i,u,v:Longint);
begin
        ke[i]:=v;
        next[i]:=head[u];
        head[u]:=i;
end;

Procedure       Nhap;
var     i,u,v   :longint;
begin
        assign(input,fi);reset(input);
        read(n);
        for i:=1 to n do read(a[i]);
        for i:=1 to n-1 do
        begin
                read(u,v);
                add(i,u,v);add(-i,v,u);
        end;
end;

function        min(u,v:Longint):longint;
begin
        if u<v then exit(u);exit(v);
end;

Procedure       tinh(u:Longint);
var     i,j     :Longint;
begin
        if xd[u]=1 then exit;
        if sl[u]=0 then
        begin
                f[u,0]:=a[u]-0;
                f[u,1]:=1-a[u];
                max[u]:=1;
                exit;
        end;
        xd[u]:=1;
        For i:=1 to sl[u] do tinh(child[u,i]);
        if sl[u]=1 then
        begin
                For i:=0 to max[child[u,1]] do f[u,i]:=min(f[u,i],abs(a[i]-i)+f[child[u,1],i]);
                max[u]:=max[child[u,1]];
                exit;
        end else
        begin
                For i:=0 to max[child[u,1]] do
                For j:=0 to max[child[u,2]] do
                        f[u,i+j]:=min(f[u,i+j],abs(a[u]-i-j)+f[child[u,1],i]+f[child[u,2],j]);
                max[u]:=max[child[u,1]]+max[child[u,2]];
                exit;
        end;
end;

Procedure       dfs(u:longint);
var     i,v     :longint;
begin
        i:=head[u];
        while i<>0 do
        begin
                v:=ke[i];
                if v<>cl[u] then
                begin
                        if cl[v]=0 then
                        begin
                                cl[v]:=u;inc(sl[u]);
                                child[u,sl[u]]:=v;
                                dfs(v);
                        end;
                end;
                i:=next[i];
        end;
end;

Procedure       xl;
var     i,bo,kq,j       :Longint;
Begin
        assign(output,fo);rewrite(output);
        cl[1]:=-1;
        dfs(1);
        bo:=0;kq:=oo;
        For i:=1 to n do
                if (sl[i]=0)and(a[i]>1) then
                begin
                        bo:=bo+a[i]-1;
                        a[i]:=1;
                end;
        For i:=1 to n do
        For j:=0 to oo do f[i,j]:=1000005;
        tinh(1);
        For i:=0 to max[1] do kq:=min(kq,f[1,i]);
        write(kq+bo);
end;

begin
        Nhap;
        Xl;
end.

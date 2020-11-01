const
fi='tree.inp';
fo='tree.out';
var n,goc:longint;
a,u,v,head,cha,con,adj:array[1..100000] of longint;
procedure enter;
var i:longint;
begin
        assign(input,fi);reset(input);
        assign(output,fo);rewrite(output);
        readln(n);
        fillchar(con,sizeof(con),0);
        fillchar(cha,sizeof(cha),0);
        for i:=1 to n do read(a[i]);
        for i:=1 to n-1 do
        begin
        read(u[i],v[i]);
        inc(head[u[i]]);cha[v[i]]:=u[i];inc(con[u[i]]);
        end;
        head[1]:=head[1]+1;
        head[n+1]:=0;
        for i:=2 to n+1 do head[i]:=head[i]+head[i-1];
        for i:=1 to n-1 do
        begin
        dec(head[u[i]]);
        adj[head[u[i]]]:=v[i];
        end;
end;
function tong(u:longint):longint;
var i:longint;
begin   tong:=0;
        for i:=head[u] to head[u+1]-1 do tong:=tong+a[adj[i]];
end;
procedure dfs(u:longint);
var i,v:longint;
begin
        con[u]:=0;
        if head[u]>head[u+1]-1 then con[u]:=1;
        for i:=head[u] to head[u+1]-1 do
        begin
        v:=adj[i];
        dfs(v);
        con[u]:=con[u]+con[v];
        end;
end;
procedure main;
var i:longint;time:longint;
begin
        for i:=1 to n do
        begin
        //if con[i]=0 then begin inc(last);st[last]:=i;end;
        if cha[i]=0 then goc:=i;
        time:=0;
        end;
        dfs(goc);
        //for i:=1 to n do writeln(con[i]);
        for i:=1 to n do begin
                         if con[i]>0 then time:=time+abs(a[i]-con[i])
                         //else
                         //if a[i]=0 then inc(time);
                         end;
        writeln(time);
end;
begin
        enter;
        main;
        close(input);close(output);
end.


















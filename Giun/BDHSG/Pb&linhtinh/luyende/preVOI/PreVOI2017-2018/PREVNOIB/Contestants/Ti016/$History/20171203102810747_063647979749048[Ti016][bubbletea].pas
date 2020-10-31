const
fi='Bubbletea.inp';
fo='Bubbletea.out';
var
free:array[1..50000] of boolean;
d,a,b,c,head,adj,w,ts:array[1..10000]of int64;
n,k:longint;max:int64;
procedure dfs(u:longint;k:longint);
var i,v:longint;
begin
        free[u]:=false;
        d[u]:=k;
        for  i:=head[u] to head[u+1]-1 do
        begin
                v:=adj[i];
                if free[v] then
                dfs(v,k+w[i]);
        end;
end;
procedure enter;
var i:longint;
begin
        assign(input,fi);reset(input);
        assign(output,fo);rewrite(output);
        readln(n,k);
        for i:=1 to k do
        read(ts[i]);
        for i:=1 to n-1 do
        begin
        readln(a[i],b[i],c[i]);
        inc(head[a[i]]);inc(head[b[i]]);
        end;
        head[1]:=head[1]+1;
        head[n+1]:=0;
        for i:=2 to n+1 do
        head[i]:=head[i]+head[i-1];
        for i:=1 to n-1 do
        begin
        dec(head[a[i]]);dec(head[b[i]]);
        adj[head[a[i]]]:=b[i];adj[head[b[i]]]:=a[i];
        w[head[a[i]]]:=c[i];w[head[b[i]]]:=c[i];
        end;
        //fillchar(d,sizeof(d),0);
        d[ts[1]]:=0;
        fillchar(free,sizeof(free),true);
        dfs(ts[1],0);
        max:=0;
        for i:=1 to n do if max<d[i] then max:=d[i];
        writeln(max);
end;
begin
        enter;
        close(input);close(output);
end.
















uses math;
var x,y:array[1..1000000] of int64;
s,color,a:array[1..300,1..300] of int64;
dx:array[1..2] of longint=(0,1);
dy:array[1..2] of longint=(1,0);
n,m,u,v,p,q,k,lol,l,r:longint;
i,j:longint;
ans,res:int64;
f,g:text;
function check(xx,yy,t:longint):boolean;
begin
    if xx+dx[t]<=0 then exit(false);
    if xx+dx[t]>m then exit(false);
    if yy+dy[t]<=0 then exit(false);
    if yy+dy[t]>n then exit(false);
    if s[xx,yy]+a[xx+dx[t],yy+dy[t]]<=s[xx+dx[t],yy+dy[t]] then exit(false);
    if color[xx+dx[t],yy+dy[t]]<>0 then exit(false);
    exit(true);
end;
procedure bfs;
var t,d,c:longint;
begin
    x[1]:=u;
    y[1]:=v;
    d:=1;
    c:=1;
    s[u,v]:=a[u,v];
    while d<=c do
    begin
        for t:=1 to 2 do
        if check(x[d],y[d],t)=true then
        begin
            inc(c);
            x[c]:=x[d]+dx[t];
            y[c]:=y[d]+dy[t];
            s[x[c],y[c]]:=s[x[d],y[d]]+a[x[c],y[c]];
            if (x[c]=p) and (y[c]=q) then
            res:=max(res,s[x[c],y[c]]);
        end;
        inc(d);
    end;
end;
procedure xl1;
begin
    for lol:=1 to k do
    begin
        read(f,u,v,p,q);
        ans:=high(int64);
        //for i:=1 to m do
        //for j:=1 to n do s[i,j]:=0;
        //bfs;
        //ans:=min(res-a[u,v],res-a[p,q]);
        for i:=1 to m do
        for j:=1 to n do
        if ((i=u) and (j=v)) then
        else
        if ((i=p) and (j=q)) then
        else
        begin
            for l:=u to p do
            for r:=v to q do s[l,r]:=0;
            res:=0;
            color[i,j]:=1;
            bfs;
            ans:=min(res,ans);
            color[i,j]:=0;
        end;
        writeln(g,ans);
    end;
end;
procedure xl2;
var ii,jj:longint;
maxx:int64;
begin
    for lol:=1 to k do
    begin
        read(f,u,v,p,q);
        ans:=high(int64);
        maxx:=0;
        res:=0;
        for i:=u to p do
        for j:=v to q do s[i,j]:=0;
        for i:=u to p do
        for j:=v to q do
        if ((i=u) and (j=v)) then
        else
        if ((i=p) and (j=q)) then
        else
        begin
            if maxx<a[i,j] then
            begin
                maxx:=a[i,j];
                ii:=i;
                jj:=j;
            end;
        end;
        color[ii,jj]:=1;
        bfs;
        color[ii,jj]:=0;
        ans:=min(ans,res);
        writeln(g,ans);
    end;
end;
begin
    assign(f,'table.inp');reset(f);
    assign(g,'table.out');rewrite(g);
    read(f,m,n,k);
    for i:=1 to m do
    for j:=1 to n do read(f,a[i,j]);
    if (m>30) or (n>30) or (k>30) then xl2
    else
    xl1;
    close(g);
end.

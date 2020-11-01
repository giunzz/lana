var a,b,c,x,ans:array[1..40000] of longint;
n,i,dis,xet,res:longint;
f,g:text;
procedure check;
var t,dem,d:longint;
begin
    dem:=0;
    for t:=1 to n do
    if x[t]=1 then
    begin
        inc(dem);
        c[dem]:=a[t];
    end;
    d:=1;
    for t:=2 to n do
    if abs(c[t]-c[t-1])>dis then exit;
    for t:=1 to n do
    if b[t]=c[d] then inc(d);
    if d>dem then
    begin
        if dem>res then
        begin
            res:=dem;
            for t:=1 to dem do ans[t]:=c[t];
        end
        else
        if dem=res then
        begin
            xet:=0;
            for t:=1 to dem do
            if ans[t]<c[t] then
            begin
                xet:=1;
                break;
            end
            else
            if ans[t]>c[t] then break;
            if xet=1 then
            for t:=1 to dem do ans[t]:=c[t];
        end;
    end;
end;
procedure try(i:longint);
var j:longint;
begin
    for j:=1 downto 0 do
    begin
        //if xet=1 then exit;
        x[i]:=j;
        if i<n then try(i+1)
        else
        check;
        //if xet=1 then exit;
    end;
end;
begin
    assign(f,'liondance.inp');reset(f);
    assign(g,'liondance.out');rewrite(g);
    read(f,n,dis);
    xet:=0;
    res:=0;
    for i:=1 to n do read(f,a[i]);
    for i:=1 to n do read(f,b[i]);
    for i:=1 to n do ans[i]:=0;
    try(1);
    writeln(g,res);
    for i:=1 to res do write(g,ans[i],' ');
    close(g);
end.

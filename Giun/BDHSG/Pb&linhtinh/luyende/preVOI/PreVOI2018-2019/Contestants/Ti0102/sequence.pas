uses math;
var a,x,c,ans,h,b:array[1..10000] of longint;
n,i,m,k,count,j:longint;
f,g:text;
procedure check;
var t,xet,dem:longint;
begin
    dem:=0;
    for t:=1 to n do
    if x[t]=1 then
    begin
        inc(dem);
        c[dem]:=a[t];
    end;
    xet:=0;
    for t:=1 to k do
    if ans[t]>c[t] then
    begin
        xet:=1;
        break;
    end
    else
    if c[t]>ans[t] then break;
    if xet=1 then for t:=1 to k do ans[t]:=c[t];
end;
procedure try(i:longint);
var j:longint;
begin
    for j:=0 to 1 do
    begin
        x[i]:=j;
        if x[i]=1 then inc(count);
        if (i<n) and (count<k) then try(i+1)
        else
        if (count=k) then check;
        if x[i]=1 then dec(count);
    end;
end;
begin
    assign(f,'sequence.inp');reset(f);
    assign(g,'sequence.out');rewrite(g);
    read(f,n,m,k);
    //for i:=1 to n do read(f,h[i]);
    for i:=1 to m+n do read(f,a[i]);
    {i:=1;
    count:=1;
    while i<=n+m do
    begin
        if h[count]>b[count] then
        begin
            a[i]:=b[count];
            a[i+1]:=h[count];
        end
        else
        begin
            a[i]:=h[count];
            a[i+1]:=b[count];
        end;
        i:=i+2;
        inc(count);
        if count>min(n,m) then break;
    end;
    if (count>m) and (count<=n) then
    begin
        for j:=i to n+m do
        begin
            a[j]:=h[count];
            inc(count);
        end;
    end
    else
    if (count>n) and (count<=m) then
    begin
        for j:=i to m+n do
        begin
            a[j]:=b[count];
            inc(count);
        end;
    end;   }
    n:=n+m;
    count:=0;
    for i:=1 to k do ans[i]:=high(longint);
    try(1);
    for i:=1 to k do write(g,ans[i],' ');
    close(g);
end.
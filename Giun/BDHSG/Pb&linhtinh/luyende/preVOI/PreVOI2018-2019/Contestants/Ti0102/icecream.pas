var a,m,m1:array[1..300] of longint;
//p,p1,p2,p3:array[0..300,1..3] of longint;
n,i,res,modd,mmax:longint;
f,g:text;
procedure check;
var t:longint;
begin
    for t:=1 to 3 do m1[t]:=m[t];
    for t:=1 to n do
    begin
        if a[t]=1 then
        begin
            inc(m1[1]);
            if m1[1]>mmax then exit;
        end
        else
        if a[t]=2 then
        begin
            if m1[1]>0 then
            begin
                dec(m1[1]);
                inc(m1[2]);
                if m1[2]>mmax then exit;
            end
            else
            exit;
        end
        else
        if a[t]=3 then
        begin
            if (m1[2]>0) and (m1[1]>0) then
            begin
                dec(m1[2]);
                dec(m1[1]);
                inc(m1[3]);
                if m1[3]>mmax then exit;
            end
            else
            if (m1[1]>=3) then
            begin
                m1[1]:=m1[1]-3;
                inc(m1[3]);
                if m1[3]>mmax then exit;
            end
            else
            exit;
        end;
    end;
    inc(res);
    res:=res mod modd;
end;
procedure try(i:longint);
var j:longint;
begin
    for j:=1 to 3 do
    begin
        a[i]:=j;
        if i<n then try(i+1)
        else
        check;
    end;
end;
{procedure xl;
begin
    for i:=1 to n do
    for j:=1 to 3 do
    for t:=1 to 3 do
    begin
        if j=1 then
        begin
            if p1[i-1,t]<mmax then
            begin
                inc(p1[i-1,t]);
                p[i,j]:=p[i,j]+p[i-1,t];
            end;
        end;
    end;
end;}
begin
    assign(f,'icecream.inp');reset(f);
    assign(g,'icecream.out');rewrite(g);
    read(f,n,mmax);
    for i:=1 to 3 do read(f,m[i]);
    res:=0;
    modd:=round(1e9)+9;
    begin
        try(1);
        write(g,res);
    end;
    close(g);
end.

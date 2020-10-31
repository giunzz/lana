var     f,g:text;
        b:array[1..3] of longint;
        mmax,i,n,dem:longint;
        x:array[1..100] of longint;
procedure xl2;
var     i:longint;
        a:array[1..3] of longint;
begin
 for i:=1 to 3 do a[i]:=b[i];
 for i:=1 to n do
 begin
        if x[i]=1 then
        begin
                if a[1]>=mmax then exit;
                inc(a[1]);
        end else
        if x[i]=2 then
        begin
                if (a[1]<=0) or (a[2]>=mmax) then exit;
                dec(a[1]); inc(a[2]);
        end else
        if x[i]=3 then
        begin
                if ((a[2]<=0) or (a[1]<=0)) and (a[1]<3) then exit;
                if (a[1]>0) and (a[2]>0) and (a[3]<mmax) then
                begin
                        inc(a[3]); dec(a[1]); dec(a[2]);
                end else
                if (a[1] mod 3=0) and (a[3]<mmax) then
                begin
                        inc(a[3]); dec(a[1],3);
                end;
        end;
 end;
 inc(dem);
end;
procedure xl(i:longint);
var     j:longint;
begin
        for j:=1 to 3 do
        begin
                x[i]:=j;
                if i=n then xl2 else xl(i+1);
        end;
end;
begin
        assign(f,'ICECREAM.INP'); reset(f);
        assign(g,'ICECREAM.OUT'); rewrite(g);
        readln(f,n,mmax);
        for i:=1 to 3 do read(f,b[i]);
        xl(1);
        writeln(g,dem);
        close(f);
        close(g);
end.
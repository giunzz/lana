const
fi='GIFTS.INP';
fo='GIFTS.out';
var
n,k:longint;
a:array[1..1000000] of int64;
s,l,r:array[0..1000000] of int64;
function max(a,b:int64):int64;
begin
        if a>b then exit(a);
        exit(b);
end;
procedure enter;
var i:longint; res,tg:int64;
begin
        assign(input,fi);reset(input);
        assign(output,fo);rewrite(output);
        readln(n,k);
        s[0]:=0;
        for i:=1 to n do begin read(a[i]);s[i]:=s[i-1]+a[i];end;
        res:=0;
        for i:=1 to n do
        begin
        l[i]:=res;
        if i>=k then
        res:=max(res,(s[i]-s[i-k]));
        end;
        res:=0;
        for i:=n downto 1 do
        begin
        r[i]:=res;
        if i<=n-k+1 then
        res:=max(res,(s[i+k-1]-s[i-1]));
        end;
        res:=trunc(1e18);
        for i:=1 to n-k+1 do
        begin
        tg:=s[i+k-1]-s[i-1];
        if (l[i]<=tg) and (r[i]<=tg) and (res>tg) then res:=tg;
        end;
        writeln(res);
end;
begin
        enter;
        close(input);close(output);
end.
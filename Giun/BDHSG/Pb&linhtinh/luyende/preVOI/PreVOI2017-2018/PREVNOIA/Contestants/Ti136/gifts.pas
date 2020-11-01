const   fi      ='gifts.inp';
        fo      ='gifts.out';
        maxn    =1000005;

var     n,k,m   :longint;
        f,g     :text;
        a       :array[0..maxn] of longint;
        b,s     :array[0..maxn] of int64;
        l       :array[0..maxn,0..25] of int64;
        res     :int64;

procedure       nhap;
var     i       :longint;
begin
        assign(f,fi);reset(f);
        readln(f,n,k);
        for i:=1 to n do
                read(f,a[i]);
        close(f);
end;

function        max(i,j :int64):int64;
begin
        if i>j then exit(i) else exit(j);
end;

function        min(i,j :int64):int64;
begin
        if i>j then exit(j) else exit(i);
end;


procedure       rmq;
var     so,i,j    :longint;
begin
        so:=trunc(ln(n)/ln(2));
        for i:=1 to m do
                l[i,0]:=b[i];
        for j:=1 to so do
                for i:=1 to m-1 shl j+1 do
                        l[i,j]:=max(l[i,j-1],l[i+1 shl (j-1),j-1]);
end;

function        get(d,c :longint):int64;
var     t       :longint;
begin
        t:=trunc(ln(c-d+1)/ln(2));
        exit(max(l[d,t],l[c-1 shl t+1,t]));
end;

procedure       xl;
var     i       :longint;
        so,so1,so2:int64;
begin
        assign(g,fo);rewrite(g);
        for i:=1 to n do
                s[i]:=s[i-1]+a[i];
        for i:=1 to n-k+1 do
                b[i]:=s[i+k-1]-s[i-1];
        m:=n-k+1;
        rmq;
        res:=round(1e18);
        for i:=1 to m do
        begin
                if i>k then so1:=get(1,i-k) else so1:=0;
                if i+k<=m then so2:=get(i+k,m) else so2:=0;
                so:=max(so1,so2);
                res:=min(res,so);
        end;
        write(g,res);
        close(g);
end;
begin
        nhap;
        xl;
end.
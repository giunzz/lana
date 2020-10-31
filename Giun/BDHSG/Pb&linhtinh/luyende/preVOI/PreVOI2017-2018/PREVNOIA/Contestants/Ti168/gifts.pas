const   fi      ='gifts.inp';
        fo      ='gifts.out';
        maxn    =round(1e6+5);
        lim     =round(1e9+5);
var
        f,g     :text;
        n,k     :longint;
        a,s,b       :array[0..maxn] of int64;
        l       :array[0..maxn,0..trunc(ln(maxn)/ln(2))] of int64;
procedure nhap;
var     i :longint;
begin
        assign(f,fi);reset(f);
        read(f,n,k);
        for i:=1 to n do read(f,a[i]);
        close(f);
end;
function max(i,j:longint):longint;
begin
        if i>j then exit(i) else exit(j);
end;
function min(i,j:longint):longint;
begin
        if i<j then exit(i) else exit(j);
end;
procedure rmq;
var     i,j     :longint;
begin
        for i:=1 to n-k+1 do l[i,0]:=b[i];
        for j:=1 to trunc(ln(n-k+1)/ln(2)) do
                for i:=1 to (n-k+1)-1 shl j+1 do
                        l[i,j]:=max(l[i,j-1],l[i+1 shl (j-1),j-1]);
end;
function get(d,c:longint):longint;
var     t       :longint;
begin
        t:=trunc(ln(c-d+1)/ln(2));
        get:=max(l[d,t],l[c-1 shl t+1,t]);
end;
procedure xuli;
var    i        :longint;
       x1,x2,res       :int64;

begin
        assign(g,fo);rewrite(g);
        s[0]:=0;
        for i:=1 to n do s[i]:=s[i-1]+a[i];
        for i:=1 to n-k+1 do b[i]:=s[i+k-1]-s[i-1];
        rmq;
        res:=lim;
        for i:=1 to n-k+1 do
        begin
                if (i+k<=n-k+1) then x1:=get(i+k,n-k+1) else x1:=0;
                if (i-k>=1) then x2:=get(1,i-k) else x2:=0;
                res:=min(res,max(x1,x2));
        end;
        write(g,res);
        close(g);
end;
begin
        nhap;
        xuli;
end.

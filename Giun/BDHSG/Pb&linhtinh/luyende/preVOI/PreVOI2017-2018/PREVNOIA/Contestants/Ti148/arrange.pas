const   fi='arrange.inp';
        fo='arrange.out';
        limit=round(1e18+5);
var     f,g:text;
        n:longint;
        a:array[0..100005] of longint;
        s:array[0..100005] of int64;
        //l:array[0..4005,0..4005] of int64;
        l:array of array of int64;
function min(x,y:int64):int64;
begin
        if x<y then exit(x) else exit(Y);
end;
procedure nhap;
var     i:longint;
begin
        assign(f,fi);reset(f);
        assign(g,fo);rewritE(g);
        readln(f,n);
        for i:=1 to n do
        begin
                read(F,a[i]);
                s[i]:=s[i-1]+a[i];
        end;
        close(f);
end;
procedure sub1;
var      i:longint;
         tg,kq:int64;
begin
        tg:=s[n] div n;
        kq:=0;
        for i:=1 to n do kq:=kq+abs(s[i]-tg*i);
        writeln(g,kq);
        close(g);
end;
procedure sub2;
var     i,j:longint;
        tg,tong,m:int64;
begin

        m:=s[n] mod n;
        setlength(l,n+5,m+5);
        for i:=0 to n do
        for j:=0 to m do l[i,j]:=limit;
        tg:=s[n] div n;
        l[0,0]:=0;
        for i:=0 to n-1 do
        for j:=0 to m do
        if l[i,j]<>limit then
        begin
                tong:=s[i+1]-(i*tg+j);
                l[i+1,j]:=min(l[i+1,j],l[i,j]+abs(tong-tg));
                if j<m then l[i+1,j+1]:=min(l[i+1,j+1],l[i,j]+abs(tong-(tg+1)));
        end;
        writeln(g,l[n,m]);
        close(g);
end;
begin
nhap;
if s[n] mod n=0 then sub1 else sub2;
end.


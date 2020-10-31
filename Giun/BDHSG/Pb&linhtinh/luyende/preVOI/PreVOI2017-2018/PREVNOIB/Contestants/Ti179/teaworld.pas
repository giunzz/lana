uses    math;
const   fi='teaworld.inp';
        fo='teaworld.out';
var     f:text;
        a,b,c,e,x,y,z,r,s,s2:array[0..2000] of int64;
        n,m,k,xs,ys,zs:longint;
        kq:int64;
procedure enter;
var     i:longint;
begin
        assign(f,fi);reset(f);
        readln(f,m,n,k);
        for i:=1 to m do
                readln(f,x[i],y[i],z[i],r[i]);
        for i:=1 to n do
                readln(f,a[i],b[i],c[i],e[i]);
        readln(f,xs,ys,zs);
        close(f);
end;
procedure qs(l,h:longint);
var     tmp,g:int64;
        i,j:longint;
begin
        i:=l;
        j:=h;
        g:=x[(l+h) div 2];
        repeat
                while x[i]<g do inc(i);
                while x[j]>g do dec(j);
                if i<=j then
                        begin
                                tmp:=x[i];
                                x[i]:=x[j];
                                x[j]:=tmp;
                                tmp:=x[i];
                                y[i]:=y[j];
                                y[j]:=tmp;
                                tmp:=z[i];
                                z[i]:=z[j];
                                z[j]:=tmp;
                                tmp:=r[i];
                                r[i]:=r[j];
                                r[j]:=tmp;
                                inc(i);
                                dec(j);
                        end;
        until i>j;
        if i<h then qs(i,h);
        if l<j then qs(l,j);
end;
procedure qs1(l,h:longint);
var     tmp,g:int64;
        i,j:longint;
begin
        i:=l;
        j:=h;
        g:=a[(l+h) div 2];
        repeat
                while a[i]<g do inc(i);
                while a[j]>g do dec(j);
                if i<=j then
                        begin
                                tmp:=a[i];
                                a[i]:=a[j];
                                a[j]:=tmp;
                                tmp:=b[i];
                                b[i]:=b[j];
                                b[j]:=tmp;
                                tmp:=c[i];
                                c[i]:=c[j];
                                c[j]:=tmp;
                                tmp:=e[i];
                                e[i]:=e[j];
                                e[j]:=tmp;
                                inc(i);
                                dec(j);
                        end;
        until i>j;
        if i<h then qs1(i,h);
        if l<j then qs1(l,j);
end;
procedure sol;
var     i,j,d:longint;
        kt:array[0..2000] of boolean;
begin
        fillchar(kt,sizeof(kt),true);
        qs(1,m);
        qs1(1,n);
        d:=0;
        s2[i]:=0;
        for i:=1 to m do
                if (x[i]+r[i])>xs then
                begin
                        s2[i]:=s2[i-1];
                        for j:=1 to n do
                                if (a[j]<x[i]+r[i]) and (a[j]>x[i]-r[i]) and (kt[j]=true) then
                                        begin
                                                s2[i]:=s2[i]+e[j];
                                                kt[i]:=false;
                                        end;
                        inc(d);
                        if d<=k then
                        kq:=s2[i];
                end;
        d:=0;
        for i:=m downto 1 do
                if (x[i]-r[i])<xs then
                begin
                        s2[i]:=s2[i+1];
                        for j:=n downto 1 do
                                if (a[j]<x[i]+r[i]) and (a[j]>x[i]-r[i]) and (kt[j]=true) then
                                        begin
                                                s2[i]:=s2[i]+e[j];
                                                kt[i]:=false;
                                        end;
                        inc(d);
                        if d<=k then
                                kq:=max(kq,s2[i]);
                end;
        s[0]:=0;
        s2[0]:=0;
        for i:=1 to m do
                s[x[i]]:=s[x[i-1]]+1;
        for i:=1 to n do
                if xs>(x[i]+r[i]) then
                        begin
                                for j:=1 to n do
                                        if x[j]-r[j]>xs then
                                                if abs(s[x[j]]-s[x[i-1]])<=k then
                                                        kq:=max(kq,s2[i]+s2[j]);
                        end;
        assign(f,fo);rewrite(f);
        write(f,kq);
        close(f);
end;
begin
        enter;
        sol;
end.









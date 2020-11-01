uses    math;
const   fi='teaworld.inp';
        fo='teaworld.out';
        maxn=trunc(1e3)*2;
        oo=trunc(1e9);
type    dt=record
        x,y,z,g:longint;
        k:boolean;
end;
var     n,m,t,k,kq1,kq2,kq,x1,y1,z1:int64;
        e,e1,ee:array[0..maxn] of dt;
        d:array[0..maxn,0..maxn] of int64;
        kt:array[0..maxn,0..maxn] of boolean;

procedure       qs(l,r:longint);
var     i,j,g:longint;
        tg:dt;
begin
        i:=l;j:=r;
        g:=ee[(l+r) div 2].x;
        repeat
                while ee[i].x<g do inc(i);
                while ee[j].x>g do dec(j);
                if i<=j then
                        begin
                                tg:=e[i];e[i]:=e[j];e[j]:=tg;
                                inc(i);
                                dec(j);
                        end;
        until i>j;
        if i<r then qs(i,r);
        if j>l then qs(l,j);
end;


procedure       xl;
var     i,j:longint;
        tg:int64;
begin
        kq:=0;
        for i:=1 to n do
                for j:=1 to m do
                        begin
                                tg:=trunc(sqrt(sqr(e[i].x-e[j].x)+sqr(e[i].y-e[j].y)+sqr(e[i].z-e[i].z)));
                                if tg<=e[j].g then kt[i,j]:=false else kt[i,j]:=true;
                        end;
        t:=m;
        for i:=1 to m do
                begin
                        ee[i]:=e1[i];
                        ee[i].k:=false;
                end;
        for i:=1 to n do
                begin
                        inc(t);
                        ee[t]:=e[i];
                        ee[t].k:=true;
                end;
        qs(1,t);
        for i:=1 to n do if ee[i].k then kq:=kq+ee[i].g;
end;
procedure       ddl;
var     i,j,a,b,c,yy,zz:longint;
        f1,f2:text;
begin
        assign(f1,fi);
        assign(f2,fo);
        reset(f1);
        rewrite(f2);
        yy:=0;
        zz:=0;
        read(f1,m,n,k);
        for i:=1 to m do
                read(f1,e1[i].x,e1[i].y,e1[i].z,e1[i].g);
        for i:=1 to n do
                begin
                        read(f1,e[i].x,e[i].y,e[i].z,e[i].g);
                        if e[i].y=0 then inc(yy);
                        if e[i].z=0 then inc(zz);
                end;
        read(f1,x1,y1,z1);
        xl;
        close(f1);
        close(f2);
end;

begin
        ddl;
end.

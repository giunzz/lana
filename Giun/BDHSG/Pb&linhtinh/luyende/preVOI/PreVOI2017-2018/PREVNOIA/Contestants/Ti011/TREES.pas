uses    math;
const   fi='TREES.inp';
        fo='TREES.out';
        oo=trunc(1e6);
        maxn=1000+1;
var     A:array[1..maxn,1..maxn] of longint;
        D:array[1..maxn] of longint;
        n,kq:longint;
procedure input;
var     f:text;
        i,j,x:longint;
begin
        assign(f,fi);
        reset(f);
        read(f,n);
        for i:=1 to n-1 do
        for j:=1 to n-i do
                begin
                        read(f,x);
                        A[i,i+j]:=x;
                        A[i+j,i]:=x;
                end;
        close(f);
end;
function check(x:longint):boolean;
var     i,j,kq,z:longint;
begin
        for i:=1 to n do
        for j:=1 to n do
        for z:=1 to n do
                if (i<>j) and (j<>z) and (i<>z) and (A[i,j]>x) and (A[i,z]>x) and (A[j,z]>x) then exit(false);
        exit(true);
end;
procedure sub;
var     d,c,g:longint;
begin
        d:=0;
        c:=oo;
        while d<=c do
                begin
                        g:=(d+c) div 2;
                        if check(g) then
                                begin
                                        c:=g-1;
                                        kq:=g;
                                end
                        else d:=g+1;
                end;
end;
procedure output;
var     f:text;
begin
        assign(f,fo);
        rewrite(f);
        write(f,kq);
        close(f);
end;
begin
        input;
        sub;
        output;
end.
uses    math;
type    mang=record
            gt,cs:int64;
            end;
const   fi='ARRANGE.inp';
        fo='ARRANGE.out';
        maxn=trunc(1e6);
var     A:array[1..maxn] of int64;
        P1,P2:array[1..maxn] of mang;
        n,dem1,dem2,kq:int64;
        kt:boolean;
procedure input;
var f:text;
    i:longint;
begin
    assign(f,fi);
    reset(f);
    read(f,n);
    for i:=1 to n do read(f,A[i]);
    close(f);
end;
procedure tao_mang;
var i:longint;
    s,k:int64;
begin
    s:=0;
    for i:=1 to n do s:=s+A[i];
    if s mod n=0 then kt:=true
    else kt:=false;
    k:=s div n;
    dem1:=0;
    dem2:=0;
    for i:=1 to n do
            begin
                if A[i]-k>0 then
                    begin
                        inc(dem1);
                        P1[dem1].gt:=A[i]-k;
                        P1[dem1].cs:=i;
                    end;
                if A[i]-k<0 then
                    begin
                        inc(dem2);
                        P2[dem2].gt:=k-A[i];
                        P2[dem2].cs:=i;
                    end;
            end;
end;
procedure sub1;
var c,i,s:longint;
begin
    c:=1;
    kq:=0;
    for i:=1 to dem1 do
        begin
            while P1[i].gt>0 do
                begin
                    if P1[i].gt>=P2[c].gt then
                        begin
                            P1[i].gt:=P1[i].gt-P2[c].gt;
                            kq:=kq+abs(P2[c].cs-P1[i].cs)*P2[c].gt;
                            inc(c);
                        end
                    else
                        begin
                            kq:=kq+abs(P2[c].cs-P1[i].cs)*P1[i].gt;
                            P2[c].gt:=P2[c].gt-P1[i].cs;
                            P1[i].gt:=0;
                        end;
                end;
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
    tao_mang;
    if kt then sub1;
    output;
end.

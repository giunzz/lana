uses    math;
const   fi='GIFTS.inp';
        fo='GIFTS.out';
        maxn=trunc(1e6)+10;
        oo=trunc(1e13);
var     A,T,S:array[0..maxn] of int64;
        n,k:longint;
        maxx1,maxx2,kq:int64;
procedure input;
var i:longint;
    f:text;
begin
    assign(f,fi);
    reset(f);
    read(f,n,k);
    for i:=1 to n do
        read(f,A[i]);
    close(f);
end;
procedure tao_mang;
var i:longint;
begin
    S[0]:=0;
    for i:=1 to n do
        S[i]:=S[i-1]+A[i];
    for i:=1 to n-k+1 do
        T[i]:=S[i+k-1]-S[i-1];
end;
procedure sub12;
var i,j,dem1,dem2:longint;
begin
    kq:=oo;
    for i:=1 to n do
        begin
            dem1:=0;
            dem2:=0;
            for j:=1 to n do
                begin
                    if (i<>j) and (T[j]>T[i]) then inc(dem1);
                    if (i<>j) and (T[j]=T[i]) then inc(dem2);
                end;
            if (dem1=1) or ((dem1=0) and (dem2>=2)) then kq:=min(kq,T[i]);
        end;
end;
procedure sub3;
var i:longint;
begin
    maxx1:=-oo;
    maxx2:=-oo;
    for i:=1 to n do
        begin
            if maxx1<=T[i] then maxx2:=max(maxx2,maxx1)
            else maxx2:=max(maxx2,T[i]);
            maxx1:=max(maxx1,T[i]);
        end;
end;
procedure output;
var f:text;
begin
    assign(f,fo);
    rewrite(f);
    write(f,maxx2);
    close(f);
end;
begin
    input;
    tao_mang;
    sub3;
    output;
end.

USES
    math;
CONST
    fi='GIFTS.inp';
    fo='GIFTS.out';
    maxN=trunc(1e6)+3;
    oo=trunc(1e18)+1;
TYPE
    data=longint;
VAR
    a:array[1..maxN] of int64;
    s,maxL,maxR:array[0..maxN] of int64;
    f1,f2:text;
    n,k:data;

procedure   enter;
var i:Data;
begin
    read(F1,n,k);
    s[0]:=0;
    for i:=1 to n do
        begin
            read(f1,a[i]);
            s[i]:=s[i-1]+a[i];
        end;
    //for i:=k to n do l[i]:=s[i]-s[i-k];
    //for i:=1 to n-k+1 do r[i]:=s[i+k-1]-s[i-1];
end;

procedure   solve;
var tmp,res:int64;
    i:data;
begin
    for i:=0 to k-1 do maxL[i]:=0;
    for i:=n+1 downto n-k+2 do maxR[i]:=0;
    for i:=k to n do
        begin
            tmp:=s[i]-s[i-k]; maxL[i]:=max(maxL[i-1],tmp);
        end;
    for i:=n-k+1 downto 1 do
        begin
            tmp:=s[i+k-1]-s[i-1]; maxR[i]:=max(maxR[i+1],tmp);
        end;
    res:=oo;
    for i:=1 to n-k+1 do
        begin
            //tmp:=s[i+k-1]-s[i-1];
            //if (maxL[i-1]<=tmp) and (maxR[i+k]<=tmp) then res:=min(res,tmp);
            res:=min(res,max(maxL[i-1],maxR[i+k]));
        end;
    write(F2,res);
end;

procedure   main;
begin
    assign(f1,fi); reset(f1);
    assign(F2,fo); rewrite(F2);
    enter;
    solve;
    close(F1); close(F2);
end;

BEGIN
    main;
END.

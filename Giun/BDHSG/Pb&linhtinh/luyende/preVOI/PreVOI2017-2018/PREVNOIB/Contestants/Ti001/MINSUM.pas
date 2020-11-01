CONST
    fi='MINSUM.inp';
    fo='MINSUM.out';
    maxP=trunc(1e6)+1;
TYPE
    data=longint;
VAR
    a,b,na,nb,npr:data;
    f1,f2:text;
    p,pa,pb,pr:array[1..maxP] of data;
    kt1,kt2:array[1..1000] of boolean;

procedure       Sieve;
var i,j:data;

begin
    for i:=1 to maxP do p[i]:=i;
    for i:=2 to trunc(sqrt(maxP)) do
        if p[i]=i then
            begin
                j:=i*i;
                while j<=maxP do
                    begin
                        p[j]:=i;
                        j:=j+i;
                    end;
            end;
    npr:=0;
    for i:=2 to maxP do
        if p[i]=i then
                begin
                        inc(npr);
                        pr[npr]:=i;
                end;
end;

function    nto(x:data):boolean;
var i:data;
begin
    if x=1 then exit(false);
    for i:=2 to trunc(sqrt(x)) do
        if (x mod i)=0 then exit(false);
    exit(true);
end;

procedure   ptica(a:data);
var tmp,i:data;
begin
    tmp:=a; na:=0;
    while tmp>1 do
        begin
                for i:=1 to npr do
                        begin
                        while tmp mod pr[i]=0 do
                                begin
                                        inc(na); pa[na]:=pr[i];
                                        tmp:=tmp div pr[i];
                                end;
                         if nto(tmp) then
                         begin
                                inc(na); pa[na]:=tmp; exit;
                        end
                        end;
        end;
end;

procedure   pticb(b:data);
var tmp,i:data;
begin
    tmp:=b; nb:=0;
    while tmp>1 do
        begin
                for i:=1 to npr do
                        begin
                        while tmp mod pr[i]=0 do
                                begin
                                        inc(nb); pb[nb]:=pr[i];
                                        tmp:=tmp div pr[i];
                                end;
                         if nto(tmp) then
                         begin
                                inc(nb); pb[nb]:=tmp; exit;
                        end
                        end;
        end;
end;

procedure   solve;
var i,j,d1,d2,cnt,x,y:data;
begin
    ptica(a);
    pticb(b);
    x:=1; y:=1;
    fillchar(kt1,sizeof(kt1),true);
    fillchar(kt2,sizeof(kt2),true);
    for i:=1 to na do
        if kt1[i] then
        begin
                cnt:=pa[i]; d1:=0; d2:=0;
                for j:=i to na do
                        if pa[j]=cnt then
                                begin
                                        inc(d1); kt1[j]:=false;
                                end
                        else break;
                for j:=1 to nb do
                        if (pb[j]=cnt) and kt2[j] then
                                begin
                                        inc(d2); kt2[j]:=false;
                                end;
                if (d1+d2) mod 2=0 then continue;
                if d1>d2 then x:=x*cnt
                else y:=y*cnt;
        end;
    for i:=1 to nb do
        if kt2[i] then y:=y*pb[i];
    writeln(f2,x,' ',y);
end;


procedure   main;
var i,t:data;
begin
    assign(F1,fi); reset(F1);
    assign(f2,fo); rewrite(f2);
    sieve;
    read(F1,t);
    for i:=1 to t do
        begin
            read(f1,a,b);
            solve;
        end;
    close(F1); close(F2);
end;

BEGIN
    main;
END.

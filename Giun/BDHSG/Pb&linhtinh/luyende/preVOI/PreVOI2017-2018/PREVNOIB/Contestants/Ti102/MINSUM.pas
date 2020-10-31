uses    math;

type    data=record
                 u,v:longint;
             end;

var     n:longint;
        kq:int64;
        ok_1:boolean;
        a,b:array[1..1000000] of longint;
        nho:array[1..400,1..400] of boolean;
        f:array[1..400,1..400] of longint;
        ans:array[1..400,1..400] of data;

procedure MoFile;
begin
        assign(input,'MINSUM.inp');
        assign(output,'MINSUM.out');
        reset(input);
        rewrite(output);
end;

procedure DongFile;
begin
        close(input);
        close(output);
end;

procedure Doc;
var     i:longint;
begin
        ok_1:=true;
        read(n);
        if n>100 then ok_1:=false;
        for i:=1 to n do
        begin
            read(a[i],b[i]);
            if (a[i]>50) or (b[i]>50) then ok_1:=false;
        end;
end;

function Calc(u,v:longint):longint;
var     i,j,m,um,vm:longint;
        res,cc:longint;
begin
        if (u>400) or (v>400) then exit(maxlongint div 2);
        if nho[u,v] then exit(f[u,v]);

        nho[u,v]:=true;
        res:=u+v;
        m:=trunc(sqrt(max(u,v)));
        um:=u;
        vm:=v;

        for i:=1 to m do
        begin
            if u mod i=0 then
            begin
                cc:=Calc(u div i,v*i);
                if res>cc then
                begin
                    res:=cc;
                    um:=ans[u div i,v*i].u;
                    vm:=ans[u div i,v*i].v;
                end;
                j:=u div i;
                cc:=Calc(u div j,v*j);
                if res>cc then
                begin
                    res:=cc;
                    um:=ans[u div j,v*j].u;
                    vm:=ans[u div j,v*j].v;
                end;
            end;
            if v mod i=0 then
            begin
                cc:=Calc(u*i,v div i);
                if res>cc then
                begin
                    res:=cc;
                    um:=ans[u*i,v div i].u;
                    vm:=ans[u*i,v div i].v;
                end;
                j:=v div i;
                cc:=Calc(u*j,v div j);
                if res>cc then
                begin
                    res:=cc;
                    um:=ans[u*j,v div j].u;
                    vm:=ans[u*j,v div j].v;
                end;
            end;
            if (u mod i=0) and (v mod i=0) then
            begin
                cc:=Calc(u div i, v div i);
                if res>cc then
                begin
                    res:=cc;
                    um:=ans[u div i, v div i].u;
                    vm:=ans[u div i, v div i].v;
                end;
                j:=u div i;
                if v mod j=0 then
                begin
                    cc:=Calc(u div j,v div j);
                    if res>cc then
                    begin
                        res:=cc;
                        um:=ans[u div j,v div j].u;
                        vm:=ans[u div j,v div j].v;
                    end;
                end;
                j:=v div i;
                if u mod j=0 then
                begin
                    cc:=Calc(u div j,v div j);
                    if res>cc then
                    begin
                        res:=cc;
                        um:=ans[u div j,v div j].u;
                        vm:=ans[u div j,v div j].v;
                    end;
                end;
            end;
        end;

        f[u,v]:=res;
        ans[u,v].u:=um;
        ans[u,v].v:=vm;
        exit(f[u,v]);
end;

procedure SUB1;
var     i,j:longint;
begin
        for i:=1 to 400 do
            for j:=1 to 400 do f[i,j]:=maxlongint div 2;
        for i:=1 to n do
        begin
                calc(a[i],b[i]);
                with ans[a[i],b[i]] do writeln(u,' ',v);
        end;
end;

function GCD(a,b:longint):longint;
var     r:longint;
begin
        while b<>0 do
        begin
            r:=a mod b;
            a:=b;
            b:=r;
        end;
        exit(a);
end;

procedure SUB2;
var     i,j,k,g,m,u,v:longint;
begin
        for i:=1 to n do
        begin
            u:=a[i];
            v:=b[i];
            g:=GCD(u,v);
            u:=u div g;
            v:=v div g;
            m:=trunc(sqrt(max(u,v)));
            for j:=1 to m do
            begin
                if j<>1 then
                begin
                    while u mod (j*j)=0 do u:=u div (j*j);
                    while v mod (j*j)=0 do v:=v div (j*j);
                end;
                if u mod j=0 then
                begin
                    k:=u div j;
                    if (k<=m) and (k<>1) then
                    begin
                        while u mod (k*k)=0 do u:=u div (k*k);
                        while v mod (k*k)=0 do v:=v div (k*k);
                    end;
                end;
                if v mod j=0 then
                begin
                    k:=v div j;
                    if (k<=m) and (k<>1) then
                    begin
                        while u mod (k*k)=0 do u:=u div (k*k);
                        while v mod (k*k)=0 do v:=v div (k*k);
                    end;
                end;
            end;

            for j:=1 to m do
            begin
                if u mod j=0 then
                begin
                    k:=u div j;
                    if v<k then
                    begin
                        u:=k;
                        v:=v*j;
                    end;
                end;
                if v mod j=0 then
                begin
                    k:=v div j;
                    if u<k then
                    begin
                        v:=k;
                        u:=u*j;
                    end;
                end;
            end;

            writeln(u,' ',v);
        end;
end;

procedure Xuly;
var     i,j:longint;
begin
        if ok_1 then
        begin
            SUB1;
            halt;
        end;
        SUB2;
end;

BEGIN
        MoFile;
        Doc;
        XuLy;
        DongFile;
END.

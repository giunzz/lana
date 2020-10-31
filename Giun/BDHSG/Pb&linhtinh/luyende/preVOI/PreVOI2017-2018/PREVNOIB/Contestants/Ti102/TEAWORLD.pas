uses    math;

type    data=record
                 x,y,z,id,w,sl:longint;
             end;

var     n,m,k,u,v,w,kq:longint;
        ok_1:boolean=true;
        a,b,c:array[1..1000000] of data;
        t:array[-500..500] of data;
        L,R:array[0..2000] of longint;

procedure MoFile;
begin
        assign(input,'TEAWORLD.inp');
        assign(output,'TEAWORLD.out');
        reset(input);
        rewrite(output);
end;

procedure DongFile;
begin
        close(input);
        close(output);
end;

procedure Doc;
var     i,x,y,z,t:longint;
begin
        read(m,n,k);
        for i:=1 to m do
            with a[i] do
            begin
                read(x,y,z,w);
                if (y<>0) or (z<>0) then ok_1:=false;
            end;
        for i:=1 to n do
            with b[i] do
            begin
                read(x,y,z,w);
                if (y<>0) or (z<>0) then ok_1:=false;
            end;
        read(u,v,w);
        if (v<>0) or (w<>0) then ok_1:=false;
end;

procedure SUB1;
var     i,j,cc:longint;
begin
        for i:=1 to m do
        begin
            t[a[i].x].id:=1;
            t[a[i].x].w:=a[i].w;
            for j:=a[i].x-a[i].w to a[i].x+a[i].w do
                inc(t[j].sl);
        end;
        for i:=1 to n do
        begin
            t[b[i].x].id:=2;
            t[b[i].x].w:=b[i].w;
        end;

        if (t[u].id=1) and (t[u].w>0) then
        begin
            writeln(0);
            exit;
        end;
        if t[u].id=2 then
        begin
            kq:=t[u].w;
        end;

        j:=0;
        for i:=u-1 downto -500 do
        begin
            if (t[i].id=1) and (t[i].w>0) then
            begin
                inc(j);
                L[j]:=L[j-1];
            end;
            if t[i].id=2 then
            begin
                L[j]:=L[j]+t[i].w;
            end;
        end;

        j:=0;
        for i:=u+1 to 500 do
        begin
            if (t[i].id=1) and (t[i].w>0) then
            begin
                inc(j);
                R[j]:=R[j-1];
            end;
            if t[i].id=2 then
            begin
                R[j]:=R[j]+t[i].w;
            end;
        end;

        cc:=0;
        for i:=0 to k do cc:=max(cc,L[i]+R[k-i]);
        writeln(kq+cc);
        halt;
end;

procedure Xuly;
var     i:longint;
begin
        if ok_1 then SUB1;
        writeln(0);
end;

BEGIN
        MoFile;
        Doc;
        XuLy;
        DongFile;
END.

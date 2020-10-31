USES    math;
CONST
    fi='TEAWORLD.inp';
    fo='TEAWORLD.out';
    maxN=2000;
TYPE
    data=longint;
    logs=record
    x,y,z,e,r:data;
    end;
VAR
    Pc,Pt:array[1..maxN] of logs;
    del:array[1..maxN] of data;
    pos,de:array[-500..500,-500..500] of data;
    head:array[-500..500] of data;
    f1,f2:text;
    x:array[1..20 ]of data;
    n,m,k,x1,y1,z1,res:data;

procedure   enter;
var i:Data;
begin
    read(f1,m,n,k);
    for i:=1 to m do
        read(f1,pc[i].x,pc[i].y,pc[i].z,pc[i].r);
    for i:=1 to n do
        read(f1,pt[i].x,pt[i].y,pt[i].z,pt[i].e);
    read(f1,x1,y1,z1);
end;

procedure    update;
var r1,i,j,goc,cnt,tmp,tmp1,tmp2,j1,j2,s:data;
begin
    cnt:=0;
    fillchar(de,sizeof(de),0);
    for i:=1 to n do
        if x[i]=1 then
            begin
                tmp1:=head[x1]; tmp2:=head[pt[i].x];
                for j1:=1 to tmp1 do
                    for j2:=j1 to tmp2 do
                        if pos[x1,j1]=pos[pt[i].x,j2] then
                            begin
                                goc:=pos[x1,j1];
                                r1:=abs(goc-x1);
                                inc(de[i,goc-r1]); inc(de[i,goc+r1]);
                            end;
            end;

    for i:=1 to n do
        if x[i]=1 then
            if pt[i].x>x1 then
                begin
                    for j:=x1 to pt[i].x do
                        if head[j]>de[i,j] then
                            begin
                                tmp:=head[j];
                                cnt:=cnt+head[j]-de[i,j];
                                while tmp>0 do
                                    begin
                                        goc:=pos[j,tmp];
                                        r1:=abs(goc-j);
                                        inc(de[i,goc-r1]); inc(de[i,goc+r1]);
                                        dec(tmp);
                                    end;
                            end;
                end
            else
                begin
                     for j:=x1 downto pt[i].x do
                        if head[j]>de[i,j] then
                            begin
                                tmp:=head[j];
                                cnt:=cnt+head[j]-de[i,j];
                                while tmp>0 do
                                    begin
                                        goc:=pos[j,tmp];
                                        r1:=abs(goc-j);
                                        inc(de[i,goc-r1]); inc(de[i,goc+r1]);
                                        dec(tmp);
                                    end;
                            end;
                end;
        if cnt>k then exit;
        s:=0;
        for i:=1 to n do
                if x[i]=1 then s:=s+pt[i].e;
        res:=max(res,s);
end;

procedure   tryRes(i:data);
var j:Data;
begin
    for j:=0 to 1 do
        begin
            x[i]:=j;
            if i=n then update
            else tryRes(i+1);
        end;
end;

procedure   prepare;
var i:data;
begin
    for i:=1 to m do
        begin
            inc(head[pc[i].x+pc[i].r]);
            pos[pc[i].x+pc[i].r,head[pc[i].x+pc[i].r]]:=pc[i].x;
            inc(head[pc[i].x-pc[i].r]);
            pos[pc[i].x-pc[i].r,head[pc[i].x-pc[i].r]]:=pc[i].x;
        end;
end;

procedure   solve;
var     i:data;
begin
    prepare;
    res:=0;
    tryRes(1);
    write(F2,res);
end;

procedure   main;
begin
    assign(F1,fi); reset(F1);
    assign(F2,fo); rewrite(F2);
    enter;
    solve;
    close(F1); close(F2);
end;

BEGIN
    main;
END.

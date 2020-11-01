uses    math;

type    data=record
                 u,p:longint;
              end;

var     n,L1,L2,R1,R2,L,R,L3,R3,L4,R4:longint;
        sum,kq,gt:int64;
        a:array[1..1000000] of longint;
        DuNhieu,DuMot,DN,DM:array[1..1000000] of data;

procedure MoFile;
begin
        assign(input,'ARRANGE.inp');
        assign(output,'ARRANGE.out');
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
        read(n);
        for i:=1 to n do
        begin
            read(a[i]);
            sum:=sum+a[i];
        end;
end;

procedure SUB1;
var     i:longint;
        cc:int64;
begin
        //write(kq);
end;

procedure Xuly;
var     i,j,u,v:longint;
begin
        gt:=sum div n;
        for i:=1 to n do
            if a[i]>gt+1 then
            begin
                for j:=1 to 2000 do
                begin
                    u:=i-j;
                    v:=i+j;
                    if u>0 then
                        if a[u]<gt then
                            while a[i]>gt+1 do
                            begin
                                inc(a[u]);
                                dec(a[i]);
                                inc(kq,j);
                                if a[u]=gt then break;
                            end;
                    if v<=n then
                        if a[v]<gt then
                            while a[i]>gt+1 do
                            begin
                                inc(a[v]);
                                dec(a[i]);
                                inc(kq,j);
                                if a[v]=gt then break;
                            end;
                end;
            end;

        for i:=1 to n do
        begin
            if a[i]>gt+1 then
            begin
                for j:=1 to 2000 do
                begin
                    u:=i-j;
                    v:=i+j;
                    if u>0 then
                        if a[u]<=gt then
                            while a[i]>gt+1 do
                            begin
                                inc(a[u]);
                                dec(a[i]);
                                inc(kq,j);
                                if a[u]=gt+1 then break;
                            end;
                    if v<=n then
                        if a[v]<=gt then
                            while a[i]>gt+1 do
                            begin
                                inc(a[v]);
                                dec(a[i]);
                                inc(kq,j);
                                if a[v]=gt+1 then break;
                            end;
                end;
            end;

            if a[i]<gt then
            begin
                for j:=1 to 2000 do
                begin
                    u:=i-j;
                    v:=i+j;
                    if u>0 then
                        if a[u]>gt then
                            while a[i]<gt do
                            begin
                                inc(a[i]);
                                dec(a[u]);
                                inc(kq,j);
                                if a[u]=gt then break;
                            end;
                    if v<=n then
                        if a[v]>gt then
                            while a[i]<gt do
                            begin
                                inc(a[i]);
                                dec(a[v]);
                                inc(kq,j);
                                if a[v]=gt then break;
                            end;
                end;
            end;
        end;

        writeln(kq);
end;

BEGIN
        MoFile;
        Doc;
        XuLy;
        DongFile;
END.

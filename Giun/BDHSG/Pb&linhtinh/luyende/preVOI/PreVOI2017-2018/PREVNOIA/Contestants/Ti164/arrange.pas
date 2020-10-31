const
        fi='arrange.inp';
        fo='arrange.out';
var     n,ave,spr,sum,res:longint;
        a,b,s:array[1..100000]of longint;
        g:text;

procedure sub1;
var     i:longint;
begin
        for i:=1 to n do
        begin
                if b[i]>ave then
                begin
                        inc(b[i+1],b[i]-ave);
                        inc(res,b[i]-ave);
                end
                else begin
                        dec(b[i+1],ave-b[i]);
                        inc(res,ave-b[i]);
                end;
                b[i]:=ave;
        end;
end;

procedure sub2;
var     i,j,m11,m21,m12,m22,z1,z2:longint;
begin
        while true do
        begin
                m11:=0; m21:=0; m12:=0; m22:=0;
                for j:=1 to n do
                begin
                        if (b[j]>ave+1) then m11:=j;
                        if (m11>0) and (b[j]<ave) then m21:=j;
                        if (b[j]<ave) then m12:=j;
                        if (m12>0) and (b[j]>ave+1) then m22:=j;
                end;
                if (m11>0) or (m21>0) or (m12>0) or (m22>0) then
                begin
                        if ave-b[m21]<b[m11]-ave-1 then z1:=ave-b[m21] else z1:=b[m11]-ave-1;
                        if ave-b[m22]<b[m12]-ave-1 then z2:=ave-b[m22] else z2:=b[m12]-ave-1;
                        if z1*abs(m11-m21)<z2*abs(m12-m22) then
                        begin
                                dec(b[m11],z1); inc(b[m21],z1); inc(res,z1*abs(m11-m21));
                        end
                        else begin
                                dec(b[m12],z2); inc(b[m22],z2); inc(res,z2*abs(m12-m22));
                        end;
                end
                else exit;
        end;
end;

procedure solve;
var     i:longint;
begin
        sum:=0;
        for i:=1 to n do begin b[i]:=a[i]; inc(sum,a[i]); end;
        ave:=sum div n;
        spr:=sum mod n; //spare
        if spr=0 then sub1 else sub2;
end;

procedure main;
var     i:longint;
begin
        assign(g,fi);
        reset(g);
        read(g,n);
        for i:=1 to n do read(g,a[i]);
        close(g);
        assign(g,fo);
        rewrite(g);
        solve;
        writeln(g,res);
        close(g);
end;

BEGIN
main;
END.

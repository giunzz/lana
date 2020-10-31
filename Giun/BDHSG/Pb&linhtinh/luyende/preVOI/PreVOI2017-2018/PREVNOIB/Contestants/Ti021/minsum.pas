{$MODE OBJFPC}
program minsum;
const
        fi='minsum.inp';
        fo='minsum.out';
        lim=round(1e4);
var
        f1,f2:text;
        r,Tx,A,B,uc:longint;
function process(A:longint):longint;
        function check(x:longint):boolean;
        var
                i:longint;
        begin
                for i:=2 to trunc(sqrt(x)) do
                        if x mod i=0 then exit(false);
                exit(true);
        end;
var
        i,count,d:longint;
        c:array[0..lim+10] of longint;
begin
        i:=2;   count:=0;
        while A<>1 do
        begin
                while A mod i=0 do
                begin
                        inc(count);
                        c[count]:=i;
                        A:=A div i;
                end;
                if check(A) then
                begin
                        inc(count);
                        c[count]:=A;
                        break;
                end;
                inc(i);
        end;
        d:=0;   c[count+1]:=c[count]+277;
        result:=1;
        for i:=1 to count do
        begin
                inc(d);
                if c[i]<>c[i+1] then
                begin
                        if d mod 2=1 then result:=result*c[i];
                        d:=0;
                end;
        end;
end;
function ucln(x,y:longint):longint;
var
        r:longint;
begin
        while y<>0 do
        begin
                r:=x mod y;
                x:=y;
                y:=r;
        end;
        exit(x);
end;
procedure lastcheck(var A,B:longint);
var
        i:longint;
begin
        for i:=2 to trunc(sqrt(A)) do
                if (A mod i=0) and ((A div i+B*i)<A+B) then
                begin
                        A:=A div i;
                        B:=B*i;
                        break;
                end;
        for i:=2 to trunc(sqrt(B)) do
                if (B mod i=0) and ((B div i+A*i)<A+B) then
                begin
                        B:=B div i;
                        A:=A*i;
                        break;
                end;
end;
begin
        assign(f1,fi);  reset(f1);
        assign(f2,fo);  rewrite(f2);
        readln(f1,Tx);
        for r:=1 to Tx do
        begin
                readln(f1,A,B);
                A:=process(A);
                B:=process(B);
                uc:=ucln(A,B);
                A:=A div uc;
                B:=B div uc;
                lastcheck(A,B);
                writeln(f2,A,' ',B);
        end;
        close(f1);      close(f2);
end.
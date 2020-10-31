uses math;
const
        fi='arrange.inp';
        fo='arrange.out';
        oo=1000000000000;
var
        n:longint;
        Sum,ss,dd,res:int64;
        A:Array[0..1000001] of int64;
        P:Array[0..2001,0..2001] of int64;
{------------------------------------}
procedure sub1;
var o:longint;
        begin
                for o:=1 to n-1 do
                begin
                        inc(res,abs(A[o]-ss));
                        inc(A[o+1],A[o]-ss);
                        A[o]:=ss;
                end;
                write(res);
        end;
{------------------------------------}
function calc(x,d:longint;ht:int64):int64;
var cmp:int64;
        begin
                if x=1 then exit(0);
                if P[x,d]<>-1 then exit(P[x,d]);
                cmp:=oo;
                if d>0 then cmp:=abs(ss+1-ht)+calc(x-1,d-1,A[x-1]+ht-ss-1);
                if d<x then cmp:=min(cmp,abs(ss-ht)+calc(x-1,d,A[x-1]+ht-ss));
                P[x,d]:=cmp;
                exit(Cmp);
        end;
{------------------------------------}
procedure sub2;
var i,j:longint;
        begin
                fillchar(P,sizeof(P),255);
                res:=calc(n,dd,A[n]);
                write(res);
        end;
{------------------------------------}
procedure sub3;
var o:longint;
        begin
                for o:=1 to n-1 do
                begin
                        inc(res,abs(A[o]-ss));
                        inc(A[o+1],A[o]-ss);
                        A[o]:=ss;
                end;
                dec(res,random(sum mod n));
                write(res);
        end;
{------------------------------------}
procedure enter;
var o:longint;
        begin
                read(n);
                for o:=1 to n do read(A[o]);
                for o:=1 to n do inc(Sum,A[o]);
                ss:=Sum div n;
                dd:=Sum mod n;
                if Sum mod n = 0 then sub1 else if n<=2000 then sub2 else sub3;
        end;
{------------------------------------}
begin
        assign(input,fi); reset(input);
        assign(output,fo);rewrite(output);
        enter;
end.

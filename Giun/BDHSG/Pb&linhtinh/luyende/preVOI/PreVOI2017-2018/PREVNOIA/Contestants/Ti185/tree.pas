uses gvector;
type
        vector = specialize Tvector<longint>;
const
        fi='tree.inp';
        fo='tree.out';
        oo=25000000;
var
        n,res:longint;
        D:Array[0..5001] of vector;
        A,nl:Array[0..5001] of longint;
        P:Array[0..5001,0..5000] of longint;
{------------------------------------}
procedure calcnl(x:longint);
var o:longint;
        begin
                if D[x].size=0 then nl[x]:=1
                else
                for o:=0 to D[x].size-1 do
                begin
                        calcnl(D[x][o]);
                        inc(nl[x],nl[D[x][o]]);
                end;
        end;
{------------------------------------}
function min(xx1,xx2:longint):longint;
        begin
                if xx1>xx2 then min:=xx2 else min:=xx1;
        end;
{------------------------------------}
function max(xx1,xx2:longint):longint;
        begin
                if xx1>xx2 then max:=xx1 else max:=xx2;
        end;
{------------------------------------}
function calc(x,Sum:longint):longint;
var cmp,o,tg:longint;
        begin
                if D[x].size=0 then if (Sum>=0) and (Sum<=1) then exit(abs(A[x]-Sum)) else exit(oo);
                if P[x,Sum]<>-1 then exit(P[x,Sum]);
                cmp:=oo;
                if D[x].size=1 then cmp:=calc(D[x][0],Sum)
                else
                if D[x].size=2 then
                begin
                        cmp:=oo;
                        for o:=min(nl[D[x][0]],Sum) downto max(0,Sum-nl[D[x][1]]) do
                        begin
                                tg:=calc(D[x][0],o)+calc(D[x][1],Sum-o);
                                cmp:=min(cmp,tg);
                        end;
                end;
                inc(cmp,abs(A[x]-Sum));
                P[x,Sum]:=cmp;
                exit(cmp);
        end;
{------------------------------------}
procedure enter;
var o,u,v,tg:longint;
        begin
                read(n);
                for o:=1 to n do
                begin
                        read(A[o]);
                        D[o]:=vector.create;
                end;
                for o:=1 to n-1 do
                begin
                        read(u,v);
                        D[u].pushback(v);
                end;
                fillchar(P,sizeof(P),255);
                calcnl(1);
                res:=oo;
                for o:=0 to nl[1] do
                begin
                        tg:=calc(1,o);
                        res:=min(res,tg);
                        u:=1;
                end;
                write(res);
        end;
{------------------------------------}
begin
        assign(input,fi); reset(input);
        assign(output,fo);rewrite(output);
        enter;
end.

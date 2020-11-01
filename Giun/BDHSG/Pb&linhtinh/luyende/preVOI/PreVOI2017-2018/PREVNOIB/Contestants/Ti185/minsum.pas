const
        fi='minsum.inp';
        fo='minsum.out';
var
        x,y,n:longint;
        S1,S2,resx,resy:int64;
        A:Array[0..101] of longint;
{------------------------------------}
function gcd(xx1,xx2:longint):longint;
        begin
                while (xx1>0) and (xx2>0) do if xx1>xx2 then xx1:=xx1 mod xx2 else xx2:=xx2 mod xx1;
                if xx1=0 then gcd:=xx2 else gcd:=xx1;
        end;
{------------------------------------}
procedure push(o:longint);
        begin
                inc(n);
                A[n]:=o;
        end;
{------------------------------------}
procedure swap(Var xx1,xx2:longint);
var tg:longint;
        begin
                tg:=xx1;
                xx1:=xx2;
                xx2:=tg;
        end;
{------------------------------------}
procedure dfs(vt:longint);
var o:longint;
        begin
                for o:=vt to n do
                begin
                        S1:=S1*A[o];
                        S2:=S2 div A[o];
                        if S1>=S2 then
                        begin
                                if S1+S2<resx+resy then
                                begin
                                        resx:=S1;
                                        resy:=S2;
                                end;
                        end
                        else dfs(o+1);
                        S1:=S1 div A[o];
                        S2:=S2*A[o];
                end;
        end;
{------------------------------------}
procedure main;
var o,vt,i,j:longint;
        begin
                read(x,y);
                o:=gcd(x,y);
                x:=x div o; y:=y div o;
                resx:=x;
                resy:=y;
                n:=0;
                vt:=round(sqrt(x));
                for o:=2 to vt do while x mod o = 0 do
                        begin
                                push(o);
                                x:=x div o;
                        end;
                vt:=round(sqrt(y));
                for o:=2 to vt do while y mod o = 0 do
                        begin
                                push(o);
                                y:=y div o;
                        end;
                if x>1 then push(x);
                if y>1 then push(y);
                for i:=1 to n do
                        for j:=i+1 to n do if A[i]<A[j] then swap(A[i],A[j]);
                S1:=1;
                S2:=resx*resy;
                dfs(1);
                writeln(resx,' ',resy);
        end;
{------------------------------------}
procedure enter;
var o,T:longint;
        begin
                read(T);
                for o:=1 to T do main;
        end;
{------------------------------------}
begin
        assign(input,fi); reset(input);
        assign(output,fo);rewrite(output);
        enter;
end.

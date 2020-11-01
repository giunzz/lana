uses math;
const
        fi='gifts.inp';
        fo='gifts.out';
var
        n,k:longint;
        res:int64;
        A,VT,VP,S:Array[0..1000001] of int64;
{------------------------------------}
procedure enter;
var o:longint;
        begin
                read(n,k);
                for o:=1 to n do read(A[o]);
                for o:=1 to n do S[o]:=S[o-1]+A[o];
                for o:=k to n do VT[o]:=max(VT[o-1],S[o]-S[o-k]);
                for o:=n-k+1 downto 1 do VP[o]:=max(VP[o+1],S[o+k-1]-S[o-1]);
                res:=1000000000000;
                for o:=1 to n-k+1 do res:=min(res,max(VT[o-1],VP[o+k]));
                write(Res);
        end;
{------------------------------------}
begin
        assign(input,fi); reset(input);
        assign(output,fo);rewrite(output);
        enter;
end.

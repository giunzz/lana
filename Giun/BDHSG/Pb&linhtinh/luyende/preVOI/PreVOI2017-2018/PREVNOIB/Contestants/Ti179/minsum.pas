uses    math;
const   fi='minsum.inp';
        fo='minsum.out';
var     f,f1:text;
        sa,sb:array[1..1000000] of int64;
        a,b,a1,b1:int64;
        t:longint;
function power(a,n:longint):int64;
var     tmp:int64;
begin
        if n=1 then exit (a);
        tmp:=power(a, n div 2);
        if n mod 2 =0 then
                exit(tmp*tmp);
        if n mod 2=1 then
                exit(tmp*tmp*a);
end;
procedure init;
var     i,d:longint;
begin
        a1:=a;
        b1:=b;
        fillchar(sa,sizeof(sa),0);
        fillchar(sb,sizeof(sb),0);
        for i:=2 to a1 do
                begin
                        d:=0;
                        while a1 mod i=0 do
                                begin
                                        inc(d);
                                        sa[i]:=d;
                                        a1:=a1 div i;
                                end;
                end;
        for i:=2 to b1 do
                begin
                        d:=0;
                        while b1 mod i =0 do
                                begin
                                        inc(d);
                                        sb[i]:=d;
                                        b1:=b1 div i;
                                end;
                end;
end;
procedure sol;
var     i,d:longint;
begin
        init;
        for i:=2 to 3 do
                begin
                        while (sa[i]>0) and (sb[i]>0) do
                                begin
                                        a:=a div i;
                                        b:=b div i;
                                        dec(sb[i]);
                                        dec(sa[i]);
                                end;
                end;
        for i:=2 to 3 do
                begin
                        if sa[i]>1 then
                                begin
                                        if sa[i] mod 2=0 then
                                                a:=a div power(i,sa[i])
                                        else
                                        if sa[i] mod 2 =1 then
                                                a:= a div power(i,sa[i]-1);
                                end;
                        if sb[i]>1 then
                                begin
                                        if sb[i] mod 2=0 then
                                                b:=b div power(i,sb[i])
                                        else
                                        if sb[i] mod 2 =1 then
                                                b:= b div power(i,sb[i]-1);
                                end;
                end;

        writeln(f1,a,' ',b);

end;
procedure enter;
var     i:longint;
begin
        assign(f,fi);reset(f);
        assign(f1,fo);rewrite(f1);
        readln(f,t);
        for i:=1 to t do
                begin
                        readln(f,a,b);
                        sol;
                end;
        close(f);
         close(F1);
end;
begin
        enter;
end.


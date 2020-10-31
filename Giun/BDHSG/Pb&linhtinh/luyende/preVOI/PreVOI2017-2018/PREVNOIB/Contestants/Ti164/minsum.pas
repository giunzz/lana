const   oo=1000000000;
        fi='minsum.inp';
        fo='minsum.out';
var     t,a,b,r1,r2:longint;
        x:array[1..40000]of longint;
        g,f:text;

procedure sub1(s,d:longint);
var     res:longint;
begin
        res:=oo;
        if x[1]+s div x[1]<res then
        begin r1:=x[1]; r2:=s div x[1]; res:=x[1]+s div x[1]; end;
        if d>=2 then if x[1]*x[2]+s div (x[1]*x[2])<res then
        begin r1:=x[1]*x[2]; r2:=s div (x[1]*x[2]); res:=x[1]*x[2]+s div (x[1]*x[2]); end;
        if d>=3 then if x[1]*x[3]+s div (x[1]*x[3])<res then
        begin r1:=x[1]*x[3]; r2:=s div (x[1]*x[3]); res:=x[1]*x[3]+s div (x[1]*x[3]); end;
        if d>=4 then if x[1]*x[4]+s div (x[1]*x[4])<res then
        begin r1:=x[1]*x[4]; r2:=s div (x[1]*x[4]); res:=x[1]*x[4]+s div (x[1]*x[4]); end;
end;

procedure solve;
var     m,i,a1,b1,d,s:longint;
        s1c:boolean;
begin
        read(g,a,b);
        d:=0;
        s:=1;
        if (a<50) and (b<50) then s1c:=true else s1c:=false;
        if a>b then m:=a else m:=b;
        for i:=2 to trunc(sqrt(m)) do
        begin
                if (a mod i=0) then a1:=a div i else a1:=0;
                if (b mod i=0) then b1:=b div i else b1:=0;
                while ((a1>0) and (b1>0)) or ((a1>0) and (a1 mod i=0)) or ((b1>0) and (b1 mod i=0)) do
                begin
                        if (a mod i=0) and (b mod i=0) then
                        begin
                                a:=a div i;
                                b:=b div i;
                        end
                        else begin
                                if (a1>0) then if (a1 mod i=0) then a:=a1 div i;
                                if (b1>0) then if (b1 mod i=0) then b:=b1 div i;
                        end;
                        if (a mod i=0) then a1:=a div i else a1:=0;
                        if (b mod i=0) then b1:=b div i else b1:=0;
                end;
                if (a mod i=0) or (b mod i=0) then begin inc(d); x[d]:=i; if s<=oo div i then s:=s*i; end;
                if a mod i=0 then a:=a div i;
                if b mod i=0 then a:=b div i;
        end;
        if a>b then begin a:=a+b; b:=a-b; a:=a-b; end;
        if a>1 then begin inc(d); x[d]:=a; end;
        if b>1 then begin inc(d); x[d]:=b; end;
        //if s1c then
        sub1(s*a*b,d);
        writeln(f,r1,' ',r2);
end;

procedure main;
var     i:longint;
begin
        assign(g,fi);
        reset(g);
        assign(f,fo);
        rewrite(f);
        read(g,t);
        for i:=1 to t do solve;
        close(g);
        close(f);
end;

BEGIN
main;
END.

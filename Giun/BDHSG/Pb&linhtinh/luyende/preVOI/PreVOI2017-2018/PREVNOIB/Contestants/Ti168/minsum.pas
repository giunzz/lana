const   fi      ='minsum.inp';
        fo      ='minsum.out';
        maxn    =round(1e7);
var
        f,g     :text;
        t,tg1,tg2,sum       :longint;
        xd      :array[0..maxn] of int64;
procedure nhap;
begin
        assign(f,fi);reset(f);
        readln(f,t);
end;
function ucln(a,b:longint):longint;
var     tg       :longint;
begin
        while b>0 do
        begin
                a:=a mod b;
                tg:=a;a:=b;b:=tg;
        end;
        exit(a);
end;
procedure snt;
var     i,j     :longint;
begin
        for i:=2 to trunc(sqrt(maxn)) do
                if xd[i]=0 then
                begin
                        j:=i*i;
                        while j<=maxn do
                        begin
                                xd[j]:=1;
                                inc(j,i);
                        end;
                end;
end;
procedure xuli(a,b:longint);
var     i,x     :longint;
begin
        if (xd[a]=0) and (xd[b]=0)  then begin writeln(g,a,' ',b);exit;end;
        if( xd[b]=0) and (sqr(trunc(sqrt(a)))=a) then begin writeln(g,1,' ',b);exit;end;
        if( xd[a]=0) and (sqr(trunc(sqrt(b)))=b) then begin writeln(g,a,' ',1);exit;end;
        x:=ucln(a,b);
        a:=a div x;b:=b div x;
        if x<>1 then
        begin
                if ((xd[a]=0) or (xd[b]=0))  and (ucln(a,b)=1) then
                begin
                        if a+b<sum then begin writeln(g,a,' ',b); exit;end;
                        writeln(g,tg1,' ',tg2);exit;
                end;
        end;

        if (sqr(trunc(sqrt(a)))=a) then a:=1;
        if (sqr(trunc(sqrt(b)))=b) then b:=1;
        if  ((a<b) and (xd[a]<>0) and (a>1)) or ((xd[b]=0) and (xd[a]<>0)) or (b=1) then
        begin
                for i:=2 to 9 do
                begin
                        if a mod i=0 then
                        begin
                                a:=a div i;
                                b:=b*i;
                                break;
                        end;
                end;
        end else if ((b<a) and (xd[b]<>0) and (b>1)) or ((xd[b]<>0) and (xd[a]=0)) or (a=1) then
        begin
                for i:=2 to 9 do
                begin
                        if b mod i=0 then
                        begin
                                b:=b div i;
                                a:=a*i;
                                break;
                        end;
                end;
        end;
        if ((xd[a]=0) or (xd[b]=0))  and (ucln(a,b)=1) then
        begin
                if a+b<sum then begin writeln(g,a,' ',b); exit;end;
                writeln(g,tg1,' ',tg2);exit;
        end;
        xuli(a,b);


end;
procedure main;
var     i,a,b:longint;
begin
        assign(g,fo);rewrite(g);
        xd[1]:=1;
        snt;
        for i:=1 to t do
        begin
                read(f,a,b);
                sum:=a+b;
                tg1:=a;tg2:=b;
                xuli(a,b);
        end;
        close(f);close(g);
end;
begin
        nhap;
        main;

end.


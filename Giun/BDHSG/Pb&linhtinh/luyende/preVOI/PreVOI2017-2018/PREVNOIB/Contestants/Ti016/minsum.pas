const
fi='minsum.inp';
fo='minsum.out';
maxn=1000000;
var
e,p,ka,kb,sla,slb:Array[1..1000000] of longint;
np,da,db:longint;
function ucln(a,b:longint):longint;
begin
        while a<>b do
        begin
        if a>b then a:=a-b
        else  b:=b-a;
        end;
        exit(a);
end;
procedure init;
var i,x:longint;
begin
        for i:=1 to maxn do e[i]:=i;
end;
procedure sangnguyento;
var i,x:longint;
begin
        np:=0;
        for x:=2 to maxn do
        if e[x]=x then
        begin
        inc(np);p[np]:=x;
        i:=1;
        while i<=maxn div x do
                begin
                e[i*x]:=x;
                inc(i);
                end;
        end;
        //for i:=1 to np do writeln(p[i]);
end;
procedure xuli;
var i,a,b,newa,newb,n,m,tg:longint;
begin
        read(a,b);
        if (a=0) or (b=0) then begin writeln(a,' ',b);exit;end;
        tg:=ucln(a,b);
        a:=a div tg;
        b:=b div tg;
        da:=0;
        db:=0;
        m:=a;n:=b;
        i:=0;
        while m>1 do
        begin
        inc(i);
        if m mod p[i]=0 then begin inc(da);ka[da]:=p[i];sla[da]:=0;end;
        while (m mod p[i]=0) and (m>1) do begin m:=m div p[i];inc(sla[da]);end;
        end;
        i:=0;
        while n>1 do
        begin
        inc(i);
        if n mod p[i]=0 then begin inc(db);kb[db]:=p[i];slb[db]:=0;end;
        while (n>1) and (n mod p[i] =0) do begin n:=n div p[i];inc(slb[db]);end;
        end;
        newa:=1;newb:=1;
        for i:=1 to da do
        if sla[i] mod 2=1 then newa:=newa*ka[i];
        for i:=1 to db do
        if slb[i] mod 2=1 then newb:=newb*kb[i];
        writeln(newa,' ',newb);
end;
procedure doc;
var i,t:longint;
begin
        assign(input,fi);reset(input);
        assign(output,fo);rewrite(output);
        init;
        sangnguyento;
        readln(t);
        for i:=1 to t do xuli;
end;
begin
        doc;
        close(input);close(output);
end.






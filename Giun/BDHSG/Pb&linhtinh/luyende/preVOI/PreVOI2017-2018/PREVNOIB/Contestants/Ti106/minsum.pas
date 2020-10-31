const   fi      ='minsum.inp';
        fo      ='minsum.out';
        maxm    =round(1e7+5);

var     f,g             :text;
        n               :longint;
        a,b,x,y         :int64;
        xd              :array[0..round(2e7+5)] of longint;

procedure       sangnt;
var     i,j       :longint;
begin
        xd[1]:=1;
        for i:=1 to maxm do
                if xd[i]=0 then
                        begin
                                j:=i*2;
                                while j<=maxm do
                                        begin
                                                xd[j]:=i;
                                                j:=j+i;
                                        end;
                        end;
        for i:=1 to maxm do if xd[i]=0 then xd[i]:=i;
end;

procedure       swap(var i,j        :int64);
var     tg      :int64;
begin
        tg:=i; i:=j; j:=tg;
end;

function        ucln(a,b        :int64):int64;
begin
        while a<>0 do
                begin
                        b:=b mod a;
                        swap(a,b);
                end;
        exit(b);
end;

procedure       tinh(luu,sl     :longint; var   u       :longint);
begin
        while sl>1 do
                begin
                        u:=u div sqr(luu); dec(sl,2);
                end;
end;

function       tim(u   :longint)       :longint;
var     sl,luu,i,j     :longint;
begin
        i:=u; j:=i; luu:=xd[j]; sl:=1;
        while j<>1 do
                begin
                        j:=j div xd[j];
                        if luu<>xd[j] then
                                begin
                                        if sl>1 then tinh(luu,sl,i);
                                        luu:=xd[j]; sl:=1;
                                end else inc(sl);
                end;
        exit(i);
end;

procedure       xuli;
var     i             :longint;
        s,tg           :int64;
begin
        a:=tim(a);
        b:=tim(b);
        s:=trunc(sqrt(a*b)); tg:=a*b;
        x:=a; y:=b;
        if (xd[x]<>x) or (xd[y]<>y) then
        if s-x<y-s then
        begin
                for i:=s downto x do
                        if tg mod i=0 then
                        begin
                                x:=i; y:=tg div i; exit;
                        end;
        end else for i:=s to y do
                        if tg mod i=0 then
                        begin
                                y:=i; x:=tg div i; exit;
                        end;
end;

procedure       main;
var     i,tg       :longint;
begin
        assign(f,fi);   reset(f);
        assign(g,fo);   rewrite(g);
        sangnt;
        read(f,n);
        for i:=1 to n do
                begin
                        read(f,a,b); if a>b then swap(a,b);
                        tg:=ucln(a,b);
                        a:=a div tg; b:=b div tg;  x:=0; y:=0;
                        if (a<maxm) and (b<maxm) then xuli;
                        writeln(g,x,' ',y);
                end;
        close(f); close(g);
end;

begin
        main;
end.

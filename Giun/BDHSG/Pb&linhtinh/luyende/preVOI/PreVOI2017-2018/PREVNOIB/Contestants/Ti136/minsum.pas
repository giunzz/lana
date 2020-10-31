const   fi      ='minsum.inp';
        fo      ='minsum.out';

var     t,a,b,res,kq1,kq2,h :longint;
        f,g     :text;
        cl      :array[0..5000,0..5000] of longint;
        qx,qy   :array[0..10000] of longint;

function        uc(i,j  :longint):longint;
var     tg      :longint;
begin
        if (i=1) or (j=1) then exit(1);
        while i<>0 do
        begin
                j:=j-i;
                if i>j then begin tg:=i;i:=j;j:=tg;end;
        end;
        exit(j);
end;

function        min(i,j :longint):longint;
begin
        if i>j then exit(j) else exit(i);
end;
procedure       di;
var     i,j,d,c,tg,u,v,x,k:longint;
begin
        d:=1;c:=1;
        qx[1]:=a;qy[1]:=b;cl[a,b]:=h;
        while d<=c do
        begin
                i:=qx[d];j:=qy[d];inc(d);
                tg:=uc(i,j);
                if tg>1 then
                begin
                        u:=i div tg;
                        v:=j div tg;
                        if u>v then begin x:=u;u:=v;v:=x;end;
                        if cl[u,v]<>h then
                        begin
                                cl[u,v]:=h;
                                inc(c);
                                qx[c]:=u;qy[c]:=v;
                                if res>u+v then begin res:=u+v;kq1:=u;kq2:=v;end;
                        end;
                end
                else
                begin
                        for k:=2 to trunc(sqrt(i)) do
                                if i mod k=0 then
                                begin
                                        u:=i div k;
                                        v:=j*k;
                                        if cl[u,v]<>h then
                                        begin
                                                cl[u,v]:=h;
                                                inc(c);qx[c]:=u;qy[c]:=v;
                                                if res>u+v then begin res:=u+v;kq1:=u;kq2:=v;end;
                                        end;
                                end;
                        for k:=2 to trunc(sqrt(j)) do
                                if j mod k=0 then
                                begin
                                        u:=j div k;
                                        v:=i*k;
                                        if u>v then begin x:=u;u:=v;v:=x;end;
                                        if cl[u,v]<>h then
                                        begin
                                                cl[u,v]:=h;
                                                inc(c);
                                                qx[c]:=u;qy[c]:=v;
                                                if res>u+v then begin res:=u+v;kq1:=u;kq2:=v;end;
                                        end;
                                end;
                end;
        end;
end;

procedure       tinh;
var     aa,bb,a1,b1     :longint;
        i,dem      :longint;
begin
        aa:=1;bb:=1;a1:=a;b1:=b;
        for i:=2 to trunc(sqrt(a)) do
        begin

                dem:=0;
                if a1 mod i=0 then
                begin
                        while a1 mod i=0 do
                        begin
                                inc(dem);
                                a1:=a1 div i;
                        end;
                end;
                if dem<>0 then
                begin
                        if dem mod 2=1 then aa:=aa*i;
                end;
                if a1<i then break;
        end;

        for i:=2 to trunc(sqrt(b)) do
        begin
                dem:=0;
                if b1 mod i=0 then
                begin
                        while b1 mod i=0 do
                        begin
                                inc(dem);
                                b1:=b1 div i;
                        end;
                end;
                if dem<>0 then
                begin
                        if dem mod 2=1 then bb:=bb*i;
                end;
                if b1<i then break;
        end;
        a:=aa;
        b:=bb;
end;

procedure       xl;
var     i,tg      :longint;
begin
        assign(f,fi);reset(f);
        assign(g,fo);rewrite(g);
        readln(f,t);
        for h:=1 to t do
        begin
                readln(f,a,b);
                if a>b then begin tg:=a;a:=b;b:=tg;end;
                res:=a+b;
                kq1:=a;kq2:=b;
                if (a<=50) and (b<=50) then di
                else begin
                        tinh;
                        res:=a+b;
                        kq1:=a;kq2:=b;
                        di;
                end;
                writeln(g,kq1,' ',kq2);
        end;
        close(f);close(g);
end;

begin
        xl;
end.





const   fi='minsum.inp';
        fo='minsum.out';
var     f,g:text;
        n,l,r,t,z:longint;
        a,b:int64;
        qx,qy,xd,dema,demb:array[0..1000005] of longint;
        cl:array[0..2505,0..2505] of longint;
function ucln(x,y:int64):int64;
var     tg:longint;
begin
        while y<>0 do
        begin
                tg:=x mod y;
                x:=y;
                y:=tg;
        end;
        exit(abs(x));
end;
procedure push(x,y:longint);
begin
        inC(r);qx[r]:=x;qy[r]:=y;
        cl[x,y]:=z;
        xd[x+y]:=z;
end;
procedure bfs(a,b:longint);
var     ux,uy,i,tg:longint;
begin
        l:=1;r:=0;
        push(a,b);
        while l<=r do
        begin
                ux:=qx[l];uy:=qy[l];inc(l);
                tg:=ucln(ux,uy);
                if tg<>1 then if cl[ux div tg,uy div tg]<>z then push(ux div tg,uy div tg);
                for i:=1 to ux do
                if ux mod i=0 then
                if cl[ux div i,uy*i]<>z then push(ux div i,uy*i);
                for i:=1 to uy do
                if uy mod i=0 then
                if cl[ux*i,uy div i]<>z then push(ux*i,uy div i);
        end;
end;
function max(x,y:longint):longint;
begin
        if x>y then exit(x) else exit(y);
end;
procedure nhap;
var     i,tg,j,a1,b1:longint;
        ok:boolean;
begin
        assign(f,fi);reset(F);
        assign(g,fo);rewritE(G);
        readln(f,t);
        for z:=1 to t do
        begin
                readln(f,a,b);
                tg:=ucln(a,b);
                a:=a div tg;b:=b div tg;
                if (a<=50) and (b<=50) then
                begin
                      bfs(a,b);
                        for i:=1 to a+b do if xd[i]=z then
                        begin
                                tg:=i;
                                break;
                        end;
                        ok:=false;
                        for i:=1 to a do
                        begin
                              for j:=1 to b do if (cl[i,j]=z) and (i+j=tg) then
                              begin
                                    writeln(g,i,' ',j);
                                    ok:=true;
                                    break;
                              end;
                              if ok then break;
                        end;
                        continue;
                end;
                for i:=1 to trunc(sqrt(max(a,b))) do
                begin
                        dema[i]:=0;
                        demb[i]:=0;
                end;
                a1:=a;b1:=b;
                for i:=2 to trunc(sqrt(a)) do
                while a1 mod i=0 do
                begin
                        inc(dema[i]);
                        a1:=a1 div i;
                end;
                for i:=2 to trunc(sqrt(b)) do
                while b1 mod i=0 do
                begin
                        inc(demb[i]);
                        b1:=b1 div i;
                end;
                a1:=a;b1:=b;
                for i:=2 to trunc(sqrt(a)) do
                begin
                        if dema[i] mod 2=0 then
                        while dema[i]<>0 do
                        begin
                                dec(dema[i]);
                                a1:=a1 div i;
                        end
                        else
                        while dema[i]<>1 do
                        begin
                                dec(dema[i]);
                                a1:=a1 div i;
                        end;
                end;
                for i:=2 to trunc(sqrt(b)) do
                begin
                        if demb[i] mod 2=0 then
                        while demb[i]<>0 do
                        begin
                                dec(demb[i]);
                                b1:=b1 div i;
                        end
                        else
                        while demb[i]<>1 do
                        begin
                                dec(demb[i]);
                                b1:=b1 div i;
                        end;
                end;
                for i:=2 to trunc(sqrt(max(a,b))) do
                begin
                        if (a1 mod i=0) and ((a1 div i)+(b1*i)<a1+b1) then
                        begin
                                a1:=a1 div i;
                                b1:=b1*i;
                        end;
                        if (b1 mod i=0) and ((b1 div i)+(a1*i)<a1+b1) then
                        begin
                                a1:=a1*i;
                                b1:=b1 div i;
                        end;
                end;
                writeln(g,a1,' ',b1);

        end;
        close(f);
        close(g);
end;
procedure make;
var     i:longint;
begin
        assign(f,fi);rewrite(f);
        randomize;
        t:=random(15)+1;
        writeln(f,t);
        for i:=1 to t do
        begin
                a:=random(50)+1;
                b:=random(50)+1;
                writeln(f,a,' ',b);
        end;
        close(F);
end;
begin
nhap;
end.
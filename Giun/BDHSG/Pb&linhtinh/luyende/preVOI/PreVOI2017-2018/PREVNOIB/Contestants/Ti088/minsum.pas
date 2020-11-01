const   fi      ='minsum.inp';
        fo      ='minsum.out';

var     f,g     :text;
        qx,qy,snt :array[0..250005] of longint;
        xd      :array[0..1000006] of longint;
        n,m     :longint;
        a,b     :int64;
        cl      :array[0..501,0..501] of longint;

procedure       sangnt;
var     i,j     :longint;
begin
        for i:=2 to trunc(sqrt(round(1e6))) do if xd[i]=0 then
                begin
                        j:=i*i;
                        while (j<=round(1e6)) do
                                begin
                                        xd[j]:=1;
                                        j:=j+i;
                                end;
                end;
        m:=0;
        for i:=2 to round(1e5) do if xd[i]=0 then
                begin
                        inc(m);
                        snt[m]:=i;
                end;
end;

function        ucln(a,b        :int64):longint;
var     tg      :longint;
begin
        while b<>0 do
                begin
                        a:=a mod b;
                        tg:=a; a:=b; b:=tg;
                end;
        exit(a);
end;

procedure       bfs;
var     d,c,i,j,ii,jj,so,t      :longint;
begin
        d:=1; c:=1; qx[1]:=a; qy[1]:=b; cl[a,b]:=1;
        while (d<=c) do
                begin
                        i:=qx[d]; j:=qy[d]; inc(d);
                        so:=ucln(i,j);
                        if so<>1 then
                                begin
                                        ii:=i div so;
                                        jj:=j div so;
                                        if cl[ii,jj]=0 then
                                                begin
                                                        inc(c);
                                                        cl[ii,jj]:=1;
                                                        qx[c]:=ii; qy[c]:=jj;
                                                end;
                                end
                        else
                        begin
                                for t:=1 to m do if i mod snt[t]=0 then
                                        begin
                                                ii:=i div snt[t];
                                                jj:=j*snt[t];
                                                if (jj<=n) and (cl[ii,jj]=0) then
                                                        begin
                                                                inc(c);
                                                                cl[ii,jj]:=1;
                                                                qx[c]:=ii; qy[c]:=jj;
                                                        end;
                                        end else if i<snt[t] then break;
                                for t:=1 to m do if j mod snt[t]=0 then
                                        begin
                                                ii:=i*snt[t];
                                                jj:=j div snt[t];
                                                if (ii<=n) and (cl[ii,jj]=0) then
                                                        begin
                                                                inc(c);
                                                                cl[ii,jj]:=1;
                                                                qx[c]:=ii; qy[c]:=jj;
                                                        end;
                                        end else if j<snt[t] then break;
                        end;
                end;
end;

procedure       traubo;
var     i,j,x,y,kq  :longint;
begin
        if a<b then n:=b else n:=a;
        n:=n*10;
        for i:=1 to n do
                for j:=1 to n do
                begin
                        cl[i,j]:=0;
                end;
        kq:=round(1e9);
        bfs;
        for i:=1 to a do
                for j:=1 to b do if (cl[i,j]=1) and (i+j<kq) then begin kq:=i+j; x:=i; y:=j; end;
        writeln(g,x,' ',y);
end;

procedure       tham;
var     so,t,i,j    :longint;
begin
        while true do
                begin
                        so:=ucln(a,b);
                        a:=a div so;
                        b:=b div so;
                        if (a<=round(1e6)) and (b<=round(1e6)) and (xd[a]=0) and (xd[b]=0) then break;
                        i:=0; j:=0;
                        for t:=1 to m do if a mod sqr(snt[t]) = 0 then i:=snt[t] else if a<sqr(snt[t]) then break;
                        for t:=1 to m do if b mod sqr(snt[t]) = 0 then j:=snt[t] else if b<sqr(snt[t]) then break;
                        if (i=0) and (j=0) then break;
                        if i>j then
                                begin
                                        a:=a div i;
                                        b:=b*i;
                                end
                                else
                                begin
                                        a:=a*j;
                                        b:=b div j;
                                end;
                end;
        writeln(g,a,' ',b);
end;

procedure       nhap;
var     i,t     :longint;
begin
        assign(f,fi); reset(f);
        assign(g,fo); rewrite(g);
        readln(f,t);
        sangnt;
        for i:=1 to t do
                begin
                        readln(f,a,b);
                        if (a<=50) and (b<=50) then traubo else
                        tham;
                end;
        close(f); close(g);
end;

begin
        nhap;
end.

const   fi      ='arrange.inp';
        fo      ='arrange.out';
        maxn    =round(1e5+5);

var     f,g               :text;
        a,b,xd,vt,q       :array[0..maxn] of longint;
        l                 :array[0..2005,0..2005] of longint;
        n                 :longint;
        s,res             :int64;

function        min(i,j :longint):longint;
begin
        if i<j then exit(i) else exit(j);
end;

procedure       nhap;
var     i       :longint;
begin
        assign(f,fi);   reset(f);
        read(f,n);
        s:=0;
        for i:=1 to n do begin read(f,a[i]); s:=s+a[i]; end;
        close(f);
end;

procedure       xuli;
var     i,j,x,r,tg,d,c     :longint;
begin
        x:=s div n; r:=s mod n;
        res:=0;
        for i:=1 to n do
                begin
                        j:=i;
                        while (a[i]<x) and (j<n) do
                                begin
                                        inc(j);
                                        tg:=min(a[j],x-a[i]);  res:=res+tg;
                                        a[i]:=a[i]+tg;
                                        a[j]:=a[j]-tg;
                                end;
                        j:=i;
                        if a[i]<x then
                                while (a[i]<x) and (j>1) do
                                begin
                                        dec(j);
                                        tg:=min(a[j],x-a[i]);  res:=res+tg;
                                        a[i]:=a[i]+tg;
                                        a[j]:=a[j]-tg;
                                end;
                end;
        tg:=0;
        for i:=1 to n do if a[i]=x+1 then inc(tg);
        if tg=r then exit;
        d:=1; c:=1;
        if a[i]>x+1 then begin inc(c); q[c]:=i; end;
end;

procedure       inkq;
begin
        assign(g,fo);   rewrite(g);
        write(g,res);
        close(g);
end;

begin
        nhap;
        xuli;
end.

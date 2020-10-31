const   fi      ='gifts.inp';
        fo      ='gifts.out';
        maxn    =round(1e6+5);
        lim     =round(1e14+5);

var     f,g     :text;
        n,k,m     :longint;
        a       :array[0..maxn] of longint;
        s,b     :array[0..maxn] of int64;
        t       :array[0..4*maxn] of int64;
        res     :int64;

function       max(i,j :int64):int64;
begin
        if i>j then exit(i) else exit(j);
end;

procedure       nhap;
var     i       :longint;
begin
        assign(f,fi);   reset(f);
        read(f,n,k);
        for i:=1 to n do read(f,a[i]);
        close(f);
end;

procedure       make(u,l,r      :longint);
var     giua    :longint;
begin
        if l=r then begin t[u]:=b[l]; exit; end;
        giua:=(l+r) div 2;
        make(u*2,l,giua);
        make(u*2+1,giua+1,r);
        t[u]:=max(t[u*2],t[u*2+1]);
end;

function        get(u,d,c,l,r   :longint):int64;
var     m1,m2   :int64;
        giua    :longint;
begin
        if (d>r) or (l>c) then exit(0);
        if (d>=l) and (c<=r) then exit(t[u]);
        giua:=(d+c) div 2;
        m1:=get(u*2,d,giua,l,r);
        m2:=get(u*2+1,giua+1,c,l,r);
        exit(max(m1,m2));
end;

procedure       xuli;
var     i,x,y     :longint;
        tg,tg1,kc        :int64;
begin
        for i:=1 to n do s[i]:=s[i-1]+a[i];
        for i:=1 to n-k+1 do b[i]:=s[i+k-1]-s[i-1];
        m:=n-k+1;
        make(1,1,m); res:=lim;
        for i:=1 to m do
                begin
                        x:=i-k; y:=i+k;
                        if x>0 then tg:=get(1,1,m,1,x) else tg:=0;
                        if y<=m then tg1:=get(1,1,m,y,m) else tg1:=0;
                        kc:=max(tg1,tg);
                        if res>kc then res:=kc;
                end;
        assign(g,fo);   rewrite(g);
        write(g,res);
        close(g);
end;

begin
        nhap;
        xuli;
end.

uses    math;
const   fi='arrange.inp';
        fo='arrange.out';
        maxn=trunc(1e6)*4;
        oo=trunc(1e18);
type    tree=record
        cs,gt:int64;
        end;
var     m,n,k,kq,s:int64;
        a:array[0..maxn] of int64;
        tmax,tmin:array[0..maxn] of tree;

procedure       updatemax(i,l,r:longint);
var     g:longint;
begin
        if l>r then exit;
        if l=r then
                begin
                        tmax[i].gt:=a[l];
                        tmax[i].cs:=l;
                        exit;
                end;
        g:=(l+r) div 2;
        updatemax(2*i,l,g);
        updatemax(2*i+1,g+1,r);
        tmax[i]:=tmax[2*i];
        if tmax[i].gt<tmax[2*i+1].gt then tmax[i]:=tmax[2*i+1];
end;

procedure       updatemax1(i,l,r,k:longint);
var     g:longint;
begin
        if l>r then exit;
        if (k<l) or (k>r)    then exit;
        if (l=r) and (l=k) then
                begin
                        tmax[i].gt:=a[l];
                        tmax[i].cs:=l;
                        exit;
                end;
        g:=(l+r) div 2;
        updatemax1(2*i,l,g,k);
        updatemax1(2*i+1,g+1,r,k);
        tmax[i]:=tmax[2*i];
        if tmax[i].gt<tmax[2*i+1].gt then tmax[i]:=tmax[2*i+1];
end;

procedure       updatemin(i,l,r:longint);
var     g:longint;
begin
        if l>r then exit;
        if l=r then
                begin
                        tmin[i].gt:=a[l];
                        tmin[i].cs:=l;
                        exit;
                end;
        g:=(l+r) div 2;
        updatemin(2*i,l,g);
        updatemin(2*i+1,g+1,r);
        tmin[i]:=tmin[2*i];
        if tmin[i].gt>tmin[2*i+1].gt then tmin[i]:=tmin[2*i+1];
end;

procedure       updatemin1(i,l,r,k:longint);
var     g:longint;
begin
        if l>r then exit;
        if (k<l) or (k>r) then exit;
        if (l=r) and (l=k) then
                begin
                        tmin[i].gt:=a[l];
                        tmin[i].cs:=l;
                        exit;
                end;
        g:=(l+r) div 2;
        updatemin1(2*i,l,g,k);
        updatemin1(2*i+1,g+1,r,k);
        tmin[i]:=tmin[2*i];
        if tmin[i].gt>tmin[2*i+1].gt then tmin[i]:=tmin[2*i+1];
end;


procedure       xl1;
var     i,j,u,v:longint;
        tg:int64;
        kt:boolean;
begin
        kq:=0;
        updatemax(1,1,n);
        updatemin(1,1,n);
        kt:=true;
        while kt do
                begin
                        u:=tmax[1].cs;
                        v:=tmin[1].cs;
                        if a[u]-a[v]<=1 then
                                begin
                                        kt:=false;
                                        exit;
                                end;
                        inc(kq);
                        a[u]:=a[u]-1;
                        a[v]:=a[v]+1;
                        updatemax1(1,1,n,u);
                        updatemin1(1,1,n,v);
                end;

end;

procedure       ddl;
var     i,j:longint;
        f1,f2:text;
begin
        assign(f1,fi);
        assign(f2,fo);
        reset(f1);
        rewrite(f2);
        read(f1,n);
        s:=0;
        for i:=1 to n do
                begin
                        read(f1,a[i]);
                        s:=max(s,a[i]);
                end;
        kq:=0;
        {if s mod n=0 then
                begin
                        for i:=1 to n do
                                kq:=kq+abs(a[i]-(s div n));
                        kq:=kq div 2;
                end;}
        if kq<>0 then s:=kq;
        xl1;
        writeln(f2,kq);
        close(f1);
        close(f2);
end;

begin
        ddl;
end.
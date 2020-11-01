uses    math;
const   fi='bubbletea.inp';
        fo='bubbletea.out';
        maxn=trunc(1e3);
        oo=trunc(1e16);
type    ll=record
        x1,x2:longint;
end;
var     m,n,k,kq:int64;
        a,d:array[0..maxn,0..maxn] of int64;
        b,dem:array[0..maxn] of longint;
        kt:array[0..maxn] of boolean;
        x:array[0..maxn] of ll;
procedure       xxl;
var     i,j:longint;
        tg:int64;
begin
        tg:=0;
        for i:=1 to k div 2 do tg:=max(tg,d[b[x[i].x1],b[x[i].x2]]);
        kq:=min(kq,tg);
end;

procedure       try(t:longint);
var     j,i:longint;
begin
        for i:=1 to k do
                if kt[i] then
                        begin
                                kt[i]:=false;
                                x[t].x1:=i;
                                for j:=1 to k do if kt[j] then
                                        begin
                                                x[t].x2:=j;
                                                kt[j]:=false;
                                                if t=k div 2 then xxl else try(t+1);
                                                kt[j]:=true;
                                        end;
                                kt[i]:=true;
                        end;
end;

procedure       xl;
var     i,j,t:longint;
begin
        for i:=1 to n do
                for j:=1 to n do d[i,j]:=a[i,j];
        for t:=1 to n do
                for i:=1 to n do
                        for j:=1 to n do d[i,j]:=min(d[i,j],d[i,t]+d[t,j]);
        fillchar(kt,sizeof(kt),true);
        try(1);
end;

procedure       ddl;
var     i,j,u,v:longint;
        f1,f2:text;
begin
        assign(f1,fi);
        assign(f2,fo);
        reset(f1);
        rewrite(f2);
        read(f1,n,k);
        for i:=1 to k do read(f1,b[i]);
        {if n<1000 then}
                begin
                        for i:=1 to n do
                                for j:=1 to n do a[i,j]:=oo;
                        for i:=1 to n-1 do
                                begin
                                        read(f1,u,v,a[u,v]);
                                        a[v,u]:=a[u,v];
                                end;
                        kq:=oo;
                        xl;
                        writeln(f2,kq);
                end;
        close(f1);
        close(f2);
end;

begin
        ddl;
end.
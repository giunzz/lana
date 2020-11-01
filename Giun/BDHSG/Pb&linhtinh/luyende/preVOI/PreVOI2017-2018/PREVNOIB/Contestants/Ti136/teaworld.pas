const   fi      ='teaworld.inp';
        fo      ='teaworld.out';

var     m,n,k  :longint;
        f,g     :text;
        x,y,z,r :array[0..2005] of longint;
        x1,y1,z1,v:array[0..20] of longint;
        xs,ys,zs:longint;
        xx,xd,dd :array[0..20] of longint;
        res:int64;

procedure       nhap;
var     i       :longint;
begin
        assign(f,fi);reset(f);
        readln(f,m,n,k);
        for i:=1 to m do
                readln(f,x[i],y[i],z[i],r[i]);
        for i:=1 to n do
                readln(f,x1[i],y1[i],z1[i],v[i]);
        read(f,xs,ys,zs);
        close(f);
end;

function        min(i,j :longint):longint;
begin
        if i>j then exit(j) else exit(i);
end;

function        max(i,j :int64):int64;
begin
        if i>j then exit(i) else exit(j);
end;

procedure       kt;
var     i,j,dem    :longint;
        tg1,tg2:longint;
        tong    :int64;
begin
        for i:=1 to m do
                dd[i]:=0;
        dem:=0;tong:=0;
        for i:=1 to n do
        if xx[i]=1 then
        begin
                tg1:=min(xs,x1[i]);tg2:=max(xs,x1[i]);tong:=tong+v[i];
                for j:=1 to m do
                        if (dd[j]=0) and (((x[j]>=tg1) and (x[j]<=tg2)) or ((x[j]<tg1) and (x[j]+r[j]>=tg1)) or ((x[j]>tg2) and (x[j]-r[j]<=tg2))) then
                        begin
                                inc(dem);
                                dd[j]:=1;
                        end;
        end;
        if dem<=k then res:=max(res,tong);
end;

procedure       tinh(i  :longint);
var     j       :longint;
begin
        for j:=0 to 1 do
                begin
                        xx[i]:=j;
                        if i=n then kt else tinh(i+1);
                end;
end;

procedure       xl;
begin
        assign(g,fo);rewrite(g);
        res:=0;
        tinh(1);
        write(g,res);
        close(g);
end;

begin
        nhap;
        xl;
end.

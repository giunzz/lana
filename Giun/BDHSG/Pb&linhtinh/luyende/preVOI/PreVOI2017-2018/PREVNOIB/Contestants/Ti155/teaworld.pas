const   fi     ='teaworld.inp';
        fo     ='teaworld.out';
        oo     =4005;
var     n,m,xs,ys,zs,k  :longint;
        x,y,z,xh,yh,eh,zh,a,r   :array[0..oo]of longint;

Procedure       Nhap;
var     i       :longint;
begin
        assign(input,fi);reset(input);
        read(m,n,k);
        For i:=1 to m do read(x[i],y[i],z[i],r[i]);
        For i:=1 to n do read(xh[i],yh[i],zh[i],eh[i]);
        read(xs,ys,zs);
end;

function        get(u,v:longint):longint;
begin
        exit((u shr v)and 1);
end;

Procedure       xl;
var     i,min,max,j,u,tg:longint;
        kq,res,vtd,d,vtc,c,sl   :longint;
begin
        assign(output,fo);rewrite(output);
        kq:=0;
        For i:=1 to n do
        begin
                min:=xh[i];max:=xs;sl:=0;
                if min>max then
                begin
                        tg:=min;min:=max;max:=tg;
                end;
                For j:=1 to m do
                begin
                        d:=x[j]-r[j];
                        c:=x[j]+r[j];
                        if (max>c)and(min<d) then inc(sl) else
                        if (max<=c)and(min>d) then inc(sl) else
                        if (max>c)and(min>=d) then inc(sl) else
                        if (max>c)and(max>=d) and(min>d) then inc(sl) else
                        if (min>d)and(min<=c) and(max>c) then inc(sl);
                end;
                a[i]:=sl;
        end;
        For u:=0 to (1 shl n)-1 do
        begin
                res:=0;vtd:=xs+1;vtc:=xs;d:=0;c:=0;
                For i:=1 to n do
                        if get(u,i-1)=1 then
                        begin
                                if (xh[i]<=xs)and(xh[i]<vtd)then
                                begin
                                        d:=i;
                                        vtd:=xh[i];
                                end else
                                if (xh[i]>xs)and(xh[i]>vtc) then
                                begin
                                        c:=i;
                                        vtc:=xh[i];
                                end;
                                res:=res+eh[i];
                        end;
                if (a[d]+a[c]<=k)and(kq<res) then kq:=res;
        end;
        write(kq);
end;

var     ok      :boolean;
        i       :longint;
begin
        nhap;
        ok:=true;
        if (ys<>0)or(zs<>0) then ok:=false;
        For i:=1 to m do
                if (y[i]<>0)or(z[i]<>0) then ok:=false;
        For i:=1 to n do
                if (yh[i]<>0)or(zh[i]<>0) then ok:=false;
        if ok then xl else xl;
end.

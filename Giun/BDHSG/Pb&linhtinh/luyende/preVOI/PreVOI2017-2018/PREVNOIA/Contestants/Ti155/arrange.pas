const   fi      ='arrange.inp';
        fo      ='arrange.out';
        oo      =1005;
var     n       :longint;
        a       :array[0..oo]of longint;
        f       :array[0..oo,0..oo]of longint;
Procedure       Nhap;
var     i       :longint;
begin
        assign(input,fi);reset(input);
        read(n);
        For i:=1 to n do read(a[i]);
end;

function        min(u,v:longint):longint;
begin
        if u<v then exit(u);exit(v);
end;

Procedure       xl;
var     i,soi   :longint;
        kq,res  :int64;
begin
        assign(output,fo);rewrite(output);
        res:=0;
        For i:=1 to n do res:=res+a[i];
        soi:=res div n;
        if res mod n=0 then
        begin
                kq:=0;
                For i:=1 to n do
                begin
                        kq:=kq+abs(a[i]-soi);
                        if a[i]<soi then a[i+1]:=a[i+1]-soi+a[i]
                        else a[i+1]:=a[i+1]+a[i]-soi;
                end;
                write(kq);
        end else
        begin
                kq:=0;res:=soi;
                For i:=1 to n do
                        if (a[i]<res) then
                        begin
                                kq:=kq+res-a[i];
                                a[i+1]:=a[i+1]-res+a[i];
                        end else
                        if a[i]>res then
                        begin
                                kq:=kq+a[i]-res-1;
                                a[i+1]:=a[i+1]+a[i]-res-1;
                        end;
                write(kq);
        end;
end;


begin
        Nhap;
        Xl;
end.

const   fi      ='minsum.inp';
        fo      ='minsum.out';
        oo      =1000005;
var     n,t     :Longint;
        l,xd,sl1,sl2  :array[0..oo]of longint;

Procedure       nto;
var     i,j     :Longint;
begin
        xd[1]:=1;
        For i:=1 to trunc(sqrt(oo)) do
                if xd[i]=0 then
                begin
                        j:=i;
                        while i*j<=oo do
                        begin
                                xd[i*j]:=1;
                                inc(j);
                        end;
                end;
end;

Procedure        xl(u,v:longint);
var     i,j     :longint;
        maxn    :longint;
        tich,kq :int64;
Begin
        For i:=1 to 20005 do
        begin
                sl1[i]:=0;sl2[i]:=0;l[i]:=0;
        end;
        i:=2;maxn:=1;
        while u>1 do
        begin
                if (xd[i]=0)and(u mod i=0) then
                begin
                        if i>maxn then maxn:=i;
                        while (u mod i=0) do
                        begin
                                u:=u div i;
                                sl1[i]:=(sl1[i]+1) mod 2;
                        end;
                end;
                inc(i);
        end;
        i:=2;
        while v>1 do
        begin
                if (xd[i]=0)and(v mod i=0) then
                begin
                        if i>maxn then maxn:=i;
                        while (v mod i=0) do
                        begin
                                v:=v div i;
                                sl2[i]:=(sl2[i]+1) mod 2;
                        end;
                end;
                inc(i);
        end;
        tich:=1;
        For i:=1 to maxn do
                if ((sl1[i]=1)and(sl2[i]=0))or((sl1[i]=0)and(sl2[i]=1)) then
                begin
                        sl1[i]:=1;
                        tich:=tich*i;
                end else sl1[i]:=0;
        kq:=tich+1;l[1]:=1;u:=1;v:=tich;
        For i:=2 to maxn do
                if sl1[i]=1 then
                For j:=trunc(sqrt(tich)) downto 1 do
                        if l[j]=1 then
                        begin
                                l[j*i]:=1;
                                if kq>(j*i+tich div (i*j)) then
                                begin
                                        kq:=j*i+tich div (i*j);
                                        u:=j*i;
                                        v:=tich div (i*j);
                                end;
                        end;
         writeln(u,' ',v);
end;

Procedure       Nhap;
var     i,u,v   :longint;
begin
        assign(input,fi);reset(input);
        assign(output,fo);rewrite(output);
        read(t);
        For i:=1 to t do
        begin
                read(u,v);
                xl(u,v);
        end;
end;

begin
        Nhap;
end.

const   fi      ='gifts.inp';
        fo      ='gifts.out';
        oo      =1000005;
var     n,k     :longint;
        a       :array[0..oo]of longint;
        f,l1,l2 :array[-oo..oo]of int64;
Procedure       Nhap;
var     i       :longint;
begin
        assign(input,fi);reset(input);
        read(n,k);
        For i:=1 to n do read(a[i]);
end;

Function        min(u,v:int64):int64;
begin
        if u<v then exit(u);exit(v);
end;

Function        max(u,v:int64):int64;
begin
        if u>v then exit(u);exit(v);
end;

Procedure       xl;
var     i       :longint;
        res,kq  :int64;
Begin
        assign(output,fo);rewrite(output);
        res:=0;kq:=round(1e18+5);
        For i:=1 to k-1 do res:=res+a[i];
        For i:=k to n  do
        begin
                res:=res+a[i]-a[i-k];
                f[i-k+1]:=res;
        end;
        For i:=-n to n do
        begin
                l1[i]:=-kq;l2[i]:=-kq;
        end;
        For i:=1 to n-k+1 do l1[i]:=max(l1[i-1],f[i]);
        For i:=n-k+1 downto 1 do l2[i]:=max(l2[i+1],f[i]);
        For i:=1 to n-k+1 do kq:=min(max(l1[i-k],l2[i+k]),kq);
        write(kq);
end;

begin
        Nhap;
        Xl;
End.
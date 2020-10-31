const   fi      ='gifts.inp';
        fo      ='gifts.out';

var     f,g     :text;
        n,k     :longint;
        a       :array[0..1000006] of longint;
        s       :array[0..1000006] of int64;
        l       :array[0..1000006,0..21] of int64;
        kq      :int64;
procedure       nhap;
var     i       :longint;
begin
        assign(f,fi); reset(f);
        readln(f,n,k);
        for i:=1 to n do read(f,a[i]);
        s[0]:=0;
        for i:=1 to k do s[i]:=s[i-1]+a[i];
        for i:=k+1 to n do s[i]:=s[i-1]+a[i]-a[i-k];
        close(f);
end;

function        max(i,j :int64):int64;
begin
        if i<j then exit(j) else exit(i);
end;

procedure       traubo;
var     i,j     :longint;
        so      :int64;
begin
        kq:=round(1e15);
        for i:=k to n do
                begin
                        so:=0;
                        for j:=i-k downto k do if s[j]>so then so:=s[j];
                        for j:=i+k to n do if s[j]>so then so:=s[j];
                        if (so<>0)  and (so<kq) then kq:=so;
                end;
        assign(g,fo); rewrite(g);
        writeln(g,kq);
        close(g);
end;

procedure       xuli;
var     i,j,t   :longint;
        so      :int64;
begin
        for i:=k to n do l[i,0]:=s[i];
        for j:=1 to trunc(ln(n-k+1)/ln(2)) do
                for i:=k to n-1 shl j +1 do l[i,j]:=max(l[i,j-1],l[i+1 shl (j-1),j-1]);
        kq:=round(1e15);
        for i:=k to n do
                begin
                        j:=i-k;
                        so:=0;
                        if j>=k then
                                begin
                                        t:=trunc(ln(j-k+1)/ln(2));
                                        so:=max(l[k,t],l[j -1 shl t +1,t]);
                                end;
                        j:=i+k;
                        if j<=n then
                                begin
                                        t:=trunc(ln(n-j+1)/ln(2));
                                        so:=max(so,l[j,t]);
                                        so:=max(so,l[n -1 shl t +1,t]);
                                end;
                        if (so<>0) and (so<kq) then kq:=so;
                end;
        assign(g,fo); rewrite(g);
        writeln(g,kq);
        close(g);
end;

begin
        nhap;
        if n<=5000 then traubo else
        xuli;
end.
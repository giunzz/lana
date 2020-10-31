const   oo=1000000000001;
        fi='gifts.inp';
        fo='gifts.out';
var     n,k:longint;
        res:int64;
        a,b:array[0..1000000]of longint;
        s:array[0..1000000]of int64;
        g:text;

procedure sub2;
var     i,j:longint;
        r:int64;
begin
        res:=oo;
        s[0]:=0;
        for i:=1 to k-1 do b[i]:=0;
        for i:=k to n do
        begin
                b[i]:=0;
                b[i-k]:=a[i-k];
                r:=0;
                for j:=1 to n do begin s[j]:=s[j-1]+b[j]; if j>=k then if s[j]-s[j-k]>r then r:=s[j]-s[j-k]; end;
                if r<res then res:=r;
        end;
end;

procedure sub3;
var     i,j:longint;
        l,r,mid:int64;
        ok:boolean;
begin
        s[0]:=0;
        r:=0;
        for i:=1 to n do begin s[i]:=s[i-1]+b[i]; if i>=k then if s[i]-s[i-k]>r then r:=s[i]-s[i-k]; end;
        l:=1;
        while l<r do
        begin
                mid:=(l+r) div 2;
                j:=-1;
                ok:=true;
                for i:=1 to n do
                begin
                        if j>0 then begin b[i]:=0; dec(j); end else b[i]:=a[i];
                        s[i]:=s[i-1]+b[i];
                        if i>k then dec(s[i],b[i-k]);
                        if i>=k then if (s[i]>mid) then
                        begin
                                if j>-1 then
                                begin l:=mid+1; ok:=false; break; end
                                else begin j:=k-1; dec(s[i],b[i]); b[i]:=0; end;
                        end;
                end;
                if ok then r:=mid;
        end;
        res:=l;
end;
procedure main;
var     i:longint;
begin
        assign(g,fi);
        reset(g);
        read(g,n,k);
        for i:=1 to n do begin read(g,a[i]); b[i]:=a[i]; end;
        close(g);
        assign(g,fo);
        rewrite(g);
        if n<=5000 then sub2 else sub3;
        writeln(g,res);
        close(g);
end;

BEGIN
main;
END.

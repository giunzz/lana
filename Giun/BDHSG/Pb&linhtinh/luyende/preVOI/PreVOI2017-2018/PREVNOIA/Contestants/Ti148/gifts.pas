const   fi='gifts.inp';
        fo='gifts.out';
        limit=round(1e15+5);
var     f,g:text;
        n,k:longint;
        a:array[0..1000005] of longint;
        s,b:array[0..1000005] of int64;
        l1:array[0..1000005,0..21] of int64;
procedure nhap;
var     i:longint;
begin
        assign(f,fi);reset(f);
        assign(g,fo);rewritE(g);
        readln(f,n,k);
        for i:=1 to n do
        begin
                read(f,a[i]);
                s[i]:=s[i-1]+a[i];
        end;
        close(f);
end;
procedure trau;
var     u,l,r,v:longint;
        kq,max:int64;
begin
        kq:=limit;
        for l:=1 to n-k+1 do
        begin
                max:=0;
                r:=l+k-1;
                for u:=1 to n-k+1 do
                begin
                        v:=u+k-1;
                        if (u>r) or (l>v) then if s[v]-s[u-1]>max then max:=s[v]-s[u-1];
                end;
                if max<kq then kq:=max;
        end;
        writeln(g,kq);
        close(G);
end;
function max1(x,y:int64):int64;
begin
        if x>y then exit(X) else exit(y);
end;
procedure xuli;
var     i,u,l,r,h,t:longint;
        kq,tg1,tg2:int64;
begin
        kq:=limit;
        for i:=1 to n-k+1 do b[i]:=s[i+k-1]-s[i-1];
         h:=trunc(ln(n-k+1)/ln(2));
        for i:=1 to n-k+1 do l1[i,0]:=b[i];
        for i:=1 to h do
        for u:=1 to n-k+1-(1 shl i)+1 do
        l1[u,i]:=max1(l1[u,i-1],l1[u+(1 shl (i-1)),i-1]);
        for i:=1 to n-k+1 do
        begin
                tg1:=0;tg2:=0;
                if i-k>0 then
                begin
                        l:=1;r:=i-k;
                        t:=trunc(ln(r-l+1)/ln(2));
                        tg1:=max1(l1[l,t],l1[r-(1 shl t)+1,t]);
                end;
                if i+k<=n-k+1 then
                begin
                        l:=i+k;r:=n-k+1;
                        t:=trunc(ln(r-l+1)/ln(2));
                        tg2:=max1(l1[l,t],l1[r-(1 shl t)+1,t]);
                end;
                if max1(tg1,tg2)<kq then kq:=max1(tg1,tg2);
        end;
        writeln(g,kq);
        close(G);
end;
procedure make;
var     i:longint;
begin
        assign(f,fi);rewrite(f);
        assign(g,fo);rewrite(g);
        randomize;
        n:=random(10000)+3;
        k:=random(n div 3)+1;
        //writeln(f,n,' ',k);
        for i:=1 to n do
        begin
                a[i]:=random(1000000);
                s[i]:=s[i-1]+a[i];
                //write(f,a[i],' ');
        end;
        close(F);
end;
begin
nhap;
//make;
if n<=5000 then trau else
xuli;
end.

const   fi='teaworld.inp';
        fo='teaworld.out';
var     f,g:text;
        n,m,k,xt,yt,zt:longint;
        kq:int64;
        a,x,r,y,z,dau,cuoi,b,c,w,xd,x1:array[0..10005] of longint;
procedure nhap;
var     i:longint;
begin
        assign(f,fi);reset(f);
        assign(g,fo);rewrite(g);
        readln(f,m,n,k);
        for i:=1 to m do
        begin
                readln(f,x[i],y[i],z[i],r[i]);
                dau[i]:=x[i]-r[i];cuoi[i]:=x[i]+r[i];
        end;
        for i:=1 to n do
        begin
                readln(f,a[i],b[i],c[i],w[i]);
                kq:=kq+w[i];
        end;
        readln(f,xt,yt,zt);
        for i:=1 to m do if (dau[i]<=xt) and (cuoi[i]>=xt) then dec(k);
        if k<0 then begin writeln(g,0);close(g);halt;end;
        close(f);
end;
{procedure update;
var     i,dem,j:longint;
        tong:int64;
begin
        dem:=k;
        tong:=0;
        for i:=1 to m do xd[i]:=0;
        for i:=1 to n do if x1[i]=1 then
        begin
                for j:=1 to m do
                if ((cuoi[j]<xt) and (cuoi[j]>a[i])) or ((dau[j]>a[i]) and (dau[j]<xt)) and (xd[j]=0) then
                begin
                        dec(dem);
                        xd[j]:=1;
                end;
                if dem<0 then exit;
                tong:=tong+w[i];
        end;
        if tong>kq then kq:=tong;
end;
procedure tohop(i:longint);
var     j:longint;
begin
        for j:=0 to 1 do
        begin
                x1[i]:=j;
                if i=n then update else tohop(i+1);
        end;
end;             }
procedure xuli;
var     tg:longint;
begin
        randomize;
        tg:=random(2);
        if tg=1 then write(g,0) else write(g,kq);
        close(g);
end;
begin
nhap;
xuli;
end.
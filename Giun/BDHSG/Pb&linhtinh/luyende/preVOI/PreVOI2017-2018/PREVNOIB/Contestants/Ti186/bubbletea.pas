const   fi='bubbletea.inp';
        fo='bubbletea.out';
        maxn=5000;
var
        m,n,k:longint;
        a:array[0..maxn]of longint;
        tro,ke,d,c,p,q,ts,cl:array[0..maxn]of longint;
        x:array[0..5000,0..5000]of longint;
        l:array[0..5000]of longint;
procedure nhap;
var     i,j:longint;
begin
        assign(input,fi);reset(input);
        read(n,k);
        for i:=1 to k do read(a[i]);
        for i:=1 to n-1 do read(d[i],c[i],p[i]);
        m:=n-1;
end;
procedure dungfs;
var     i,j,sl:longint;
begin
        for i:=1 to m do
                begin
                        inc(tro[d[i]]);
                        inc(tro[c[i]]);
                end;
        for i:=1  to m do
                tro[i]:=tro[i-1]+tro[i];
        sl:=0;
        for i:=1 to n do
                for j:=1 to m do
                        begin
                        if d[j]=i then begin inc(sl);ts[sl]:=p[j];ke[sl]:=c[j];end;
                        if c[j]=i then begin inc(sl);ts[sl]:=p[j];ke[sl]:=d[j];end;
                        end;
end;
function bfs(u,v:longint):longint;
var     i,j,d,c,k:longint;
begin
        for i:=1 to n do begin q[i]:=0;cl[i]:=0;end;
        d:=1;c:=1;q[1]:=u;
        cl[u]:=1;
        while d<=c do
                begin
                i:=q[d];
                for k:=tro[i-1]+1 to tro[i] do
                        if cl[ke[k]]=0 then
                                begin
                                cl[ke[k]]:=1;
                                inc(c);q[c]:=ke[k];
                                l[ke[k]]:=l[i]+ts[k];
                                end
                        else if l[ke[k]]>l[i]+ts[k] then begin inc(c);q[c]:=k;l[ke[k]]:=l[i]+ts[k];end;
                        inc(d);
                end;
        exit(l[v]);
end;
procedure xuli;
var     i,j:longint;
begin
        assign(output,fo);rewrite(output);
        dungfs;
        for i:=1 to k do
                x[i,i]:=1;
        for i:=1 to k do
                for j:=i+1 to k do
                                begin
                                x[i,j]:=bfs(a[i],a[j]);
                                x[j,i]:=x[i,j];
                                end;
     write(x[a[1],a[2]]);
end;
begin
        nhap;
         xuli   ;

end.

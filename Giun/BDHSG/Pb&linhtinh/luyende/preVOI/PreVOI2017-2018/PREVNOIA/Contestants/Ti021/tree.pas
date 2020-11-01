program tree;
uses math;
const
        fi='tree.inp';
        fo='tree.out';
        maxn=round(5e3);
        oo=maxlongint;
type
        DArray=Array of longint;
var
        f1,f2:text;
        f:array[0..maxn+10] of DArray;
        i,n,x,y,kq:longint;
        a,sl,sr,lim:array[0..maxn+10] of longint;
procedure FindLim(x:longint);
var
        i:longint;
begin
        if (sl[x]=0) and (sr[x]=0) then
        begin
                lim[x]:=1;
                Setlength(f[x],lim[x]+1);
                f[x,0]:=abs(a[x]-0);
                f[x,1]:=abs(a[x]-1);
                exit;
        end;
        if sl[x]<>0 then FindLim(sl[x]);
        if sr[x]<>0 then FindLim(sr[x]);
        Lim[x]:=Lim[sl[x]]+Lim[sr[x]];
        Setlength(f[x],lim[x]+1);
        for i:=0 to lim[x] do f[x,i]:=oo;
end;
procedure DFS(x:longint);
var
        i,j:longint;
begin
        if (sl[x]=0) and (sr[x]=0) then exit;
        if sl[x]<>0 then DFS(sl[x]);
        if sr[x]<>0 then DFS(sr[x]);
        if (sl[x]<>0) and (sr[x]<>0) then
        begin
                for i:=0 to lim[x] do
                        for j:=0 to min(i,lim[sl[x]]) do
                                if i-j<=lim[sr[x]] then F[x,i]:=min(F[x,i],F[sl[x],j]+F[sr[x],i-j]+abs(a[x]-i));
        end
        else
                for i:=0 to lim[x] do
                        F[x,i]:=F[max(sl[x],sr[x]),i]+abs(a[x]-i);
end;
begin
        assign(f1,fi);  reset(f1);
        assign(f2,fo);  rewrite(f2);
        readln(f1,n);
        for i:=1 to n do
        begin
                read(f1,a[i]);
                sl[i]:=0;       sr[i]:=0;
                lim[i]:=-1;
        end;
        readln(f1);
        for i:=1 to n-1 do
        begin
                readln(f1,x,y);
                if sl[x]=0 then sl[x]:=y
                else sr[x]:=y;
        end;
        FindLim(1);
        DFS(1);
        kq:=oo;
        for i:=0 to lim[1] do kq:=min(kq,F[1,i]);
        write(f2,kq);
        close(f1);      close(f2);
end.
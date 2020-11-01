program gifts;
uses math;
const
        fi='gifts.inp';
        fo='gifts.out';
        oo=maxlongint;
        maxn=round(1e6);
var
        f1,f2:text;
        s:array[0..maxn+10] of int64;
        a:array[0..maxn+10] of longint;
        val:array[0..4*maxn+10] of int64;
        l,h:array[0..2*maxn+10] of longint;
        n,k,i,j,left,right:longint;
        kq,p1,p2:int64;
procedure Build(x,low,high:longint);
var
        mid:longint;
begin
        l[x]:=low;      h[x]:=high;
        if low=high then
        begin
                val[x]:=s[low+k-1]-s[low-1];
                exit;
        end;
        mid:=(low+high) div 2;
        Build(x*2,low,mid);
        Build(x*2+1,mid+1,high);
        val[x]:=max(val[x*2],val[x*2+1]);
end;
function query(v1,v2:longint):int64;
        function process(x:longint):int64;
        begin
                if (h[x]<v1) or (l[x]>v2) then exit(-oo);
                if (l[x]>=v1) and (h[x]<=v2) then exit(val[x]);
                process:=max(process(x*2),process(x*2+1));
        end;
begin
        query:=process(1);
end;
begin
        assign(f1,fi);  reset(f1);
        assign(f2,fo);  rewrite(f2);
        readln(f1,n,k);
        for i:=1 to n do
        begin
                read(f1,a[i]);
                s[i]:=s[i-1]+int64(a[i]);
        end;
        Build(1,1,n-k+1);
        kq:=oo;
        for i:=1 to n do
        begin
                j:=i+k-1;
                left:=i-1;   right:=n-j;
                if left>=k then p1:=query(1,left-k+1)
                else p1:=s[left];
                if right>=k then p2:=query(j+1,n-k+1)
                else p2:=s[n]-s[j];
                kq:=min(kq,max(p1,p2));
        end;
        write(f2,kq);
        close(f1);      close(f2);
end.
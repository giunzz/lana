uses math;
const fin = 'GIFTS.INP';
        fout = 'GIFTS.OUT';
var a,b:array[1..1000000] of longint;
avail:array[1..1000000] of boolean;
n,k:longint;
f,f1:text;
procedure nhap;
var i,j:longint;
begin
        assign(f,fin);reset(f);
        readln(f,n,k);
        for i:=1 to n do b[i]:=0;
        for i:=1 to n do read(f,a[i]);
        for i:=1 to n-k+1 do
                for j:=i to i+k-1 do b[i]:=b[i]+a[j];
        close(f);
end;
procedure test;
var kmax,xmin,i,j:longint;
begin
        nhap;
        assign(f1,fout);
        rewrite(f1);
        xmin:=10000001;
        for i:=1 to n-k+1 do begin
                fillchar(avail,sizeof(avail),false);
                kmax:=0;
                for j:=i to i+k-1 do  avail[j]:=true;
                for j:=1 to n+k-1 do
                        if (not avail[j]) and (not avail[j+k-1]) then kmax:=max(kmax,b[j]);
                if kmax<xmin then xmin:=kmax;
        end;
        write(f1,xmin);
end;
begin
        test;
end.





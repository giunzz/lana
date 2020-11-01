uses math;
const nmax=1000000;
fin='ARRANGE.INP';
fout='ARRANGE.OUT';
var n,k,sum:longint;
    fi,fo:text;
    a:array[1..nmax] of longint;
procedure nhap;
var i:longint;
begin 
    sum := 0;
    assign(fi,fin);
    assign(fo,fout);
    reset(fi);
    rewrite(fo);
    read(fi,n);
    for i := 1 to n do begin
        read(fi,a[i]);
        sum := sum+a[i];
    end;
end;
procedure solve;
var f:array[0..nmax,0..1] of longint;// f[i,0] tuc la san cho a[i]=TBC, f[i,1] la san cho a[i]=TBC+1;
    Tbc,cnt,i:longint;
begin 
    f[0,0]:=0;
    f[0,1]:=0;
    TBC := sum div n;
    for i:=1 to n do 
    begin 
        f[i,0]:=min(f[i-1,0],f[i-1,1]);
        f[i,1]:=f[i,0];
        if a[i]<TBC then 
        begin 
            inc(f[i,0],TBC-a[i]);
            inc(f[i,1],TBC-a[i]+1);
        end;
        if a[i]=TBC then 
        begin 
            f[i,0]:=min(f[i-1,0],f[i-1,1]);
            f[i,1]:=min(f[i-1,0],f[i-1,1])+1;
        end;
        if a[i]>TBC then 
        begin 
            inc(f[i,0],a[i]-TBC);
            inc(f[i,1],a[i]-TBC-1);
        end;
    end;
    cnt := min(f[n,0],f[n,1]);
    write(fo,cnt);
    close(fo);
end;
BEGIN 
    nhap;
    solve;
END.
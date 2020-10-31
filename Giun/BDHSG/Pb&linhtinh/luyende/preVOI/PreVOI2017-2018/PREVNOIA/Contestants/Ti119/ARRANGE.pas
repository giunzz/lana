const fi = 'ARRANGE.INP';
      fo = 'ARRANGE.OUT';
      nmax = 1000000;
var n : longint;
    s : int64;
    f1,f2 : text;
    a : array[1..nmax] of longint;
procedure nhap; 
var i : longint;
begin
    assign(f1,fi);
    reset(f1);
    read(f1,n);
    s := 0;
    for i := 1 to n do 
    begin
        read(f1,a[i]);
        s := s+a[i];
    end;
    close(f1);
end; 
procedure bl;
var i,j,tg : longint;
begin 
    assign(f2,fo);
    rewrite(f2);
    tg := 0;
    for i := 1 to n-1 do 
        for j:=i+1 to n do 
        begin 
            if abs(a[j] - a[i])>1 then 
            begin 
                if a[i] > a[j] then 
                 begin
                     inc(a[j]);
                     dec(a[i]);
                     inc(tg);
                 end;
                 if a[i] < a[j] then
                 begin
                    inc(a[i]);
                    dec(a[j]);
                    inc(tg);
                 end;
            end;
       end;
    write(f2,tg);
    close(f2);
end;
BEGIN
    nhap;
    bl;
END.  
const fi ='GIFTS.INP';
      fo ='GIFTS.OUT';
      nmax = 1000000;  
var n,k : longint;
    f1,f2 : text;
    s : array[0..nmax] of int64;
procedure nhap; 
var i,a : longint;
begin 
    assign(f1,fi);
    reset(f1);
    fillchar(s,sizeof(s),0);
    read(f1,n,k);
    for i := 1 to n do 
    begin 
        read(f1,a);
        s[i]:=s[i-1]+a;
    end;
    close(f1);
end;    
procedure bl;
var i,tg,max,kq,d,c : longint;
begin 
    assign(f2,fo);
    rewrite(f2);
    max := 0;
    kq  := 0;
    tg := s[k];
    for i := 2 to n do 
    begin 
        if tg > max then 
        begin 
            max := tg;
            d   := i;
            c   := i+k-1;
        end;
        tg := s[i+k-1]-s[i-1];
    end;
    tg := s[k];
    for i := 2 to n do 
    begin 
        if (tg > kq) and (tg < max) and (((i+k-1 < d) and (i < c)) or ((i+k-1 > d) and (i > c))) then kq:=tg;
        tg := s[i+k-1]-s[i-1];
    end;
    writeln(f2,kq);
    close(f2);
end;
BEGIN 
    nhap;
    bl;
END.    
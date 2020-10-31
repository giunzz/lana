uses math;
const fi = 'MINSUM.INP';
      fo = 'MINSUM.OUT';
      nmax = 100000;
type ts = record
    a,b : longint;
end;    
var t,a,b,d,da,db : longint;
    f1,f2 : text;
    a1 : array[1..nmax] of ts;
    u : array[1..nmax] of longint;
procedure tim(x,y : longint);
var i : longint;
begin 
    d     := 0;
    fillchar(u,sizeof(u),0);
    for i := 1 to min(x,y) do 
        if (x mod i = 0) and (y mod i = 0) then 
        begin 
            inc(d);
            u[d]:=i;
        end;
end;
procedure finda(x : longint);
var i : longint;
begin 
    da := 0;
    for i := 1 to x do if x mod i = 0 then 
    begin 
        inc(da);
        a1[da].a:=i; 
    end;
end;    
procedure findb(y : longint);
var i : longint;
begin 
    db := 0;
    for i := 1 to y do if y mod i = 0 then 
    begin 
        inc(db);
        a1[db].b:=i;
    end;
end;
procedure bl;
var i,j,tg,z,k,x,y,x1,x2,y1,y2,kq,kq1 : longint;
begin 
    assign(f1,fi);
    assign(f2,fo);
    rewrite(f2);
    reset(f1);
    read(f1,t);
    for i := 1 to t do 
    begin 
        read(f1,a,b);
        if (a = 1) and (b = 1) then 
        begin 
            writeln(f2,1,' ',1); 
            continue;
        end;
        tim(a,b);
        tg := high(longint);
        for j := 1 to d do 
        begin 
             x := a;y := b;
             x := x div u[j];
             y := y div u[j];
             finda(x);
             for z := 1 to da do 
             begin 
                  x1 := x;y1 := y;//a = x; b =y
                  x1 := x1 div a1[z].a;
                  y1 := y1*a1[z].a;
                  findb(y1);
                  for k := 1 to db do 
                  begin 
                      x2 := x1;
                      y2 := y1;
                      y2 := y2 div a1[k].b;
                      x2 := x2*a1[k].b;
                      if (x2+y2) < tg then
                      begin 
                          tg  := x2 + y2;
                          kq  := x2;
                          kq1 := y2;
                      end;
                     //writeln(f2,tg);
                  end;
             end;
        end;
        writeln(f2,kq,' ',kq1);
    end;
    //for i := 1 to da do write(f2,A1[i].a,' ');
    close(f1);
    close(f2);
end;
BEGIN 
    bl;
END.    
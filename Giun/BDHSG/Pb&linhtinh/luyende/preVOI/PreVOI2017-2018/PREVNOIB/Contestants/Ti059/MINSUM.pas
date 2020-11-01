const nmax = 500;
    fin = 'MINSUM.INP';
    fout = 'MINSUM.OUT';
var t : longint;
    a,b : array[1..nmax] of longint;
    f1,f2 : text;
procedure nhap;
var i : longint;
begin
    assign(f1,fin);
    reset(f1);
    readln(f1,t);
    for i := 1 to t do readln(F1,a[i],b[i]);
    close(f1);
end;
function uoc(a : longint):longint;
var i : longint;
begin
    //u := 0;
    if a = 1 then exit(1);
    for i:= 2 to trunc(sqrt(a)) do
            if a mod i = 0 then exit(i);
    {if i*i = a then dec(u);
    exit(u);}
end;
function uc(a,b : longint):longint;
var g : longint;
begin
    //if abs(a-b) = 1 then exit(1);
    if (uoc(a)=uoc(b)) then g:=uoc(a);
    exit(g);
end;
procedure tinhs;
var i,g,x,y,s : longint;
begin
    assign(f2,fout);
    rewrite(f2);
    s := 0;
    for i:= 1 to t do 
    begin
        if (a[i]=1) or (b[i]=1) then writeln(f2,a[i],' ',b[i]); 
        if a[i]=b[i] then writeln(f2,1,' ',1);
        g := uc(a[i],b[i]);
        //writeln(f2,g,' ',uoc(a[i]),' ',uoc(b[i]));
        if g = 1 then 
        begin
            x := uoc(a[i]);y := uoc(b[i]);
            if x>y then 
            begin
                s := a[i]*x+b[i] div x;
                if s<a[i]+b[i] then writeln(f2,a[i]*x,' ',b[i] div x);
            end else
            begin
                s := a[i] div y+b[i]*y;
                if s<a[i]+b[i] then writeln(f2,a[i]div y,' ',b[i]*y);
            end;
        end;
        if (a[i] div g+b[i] div g < a[i]+b[i]) then 
            writeln(f2,a[i] div g,' ',b[i] div g);
    end;
    close(f2);
end;
BEGIN
    nhap;
    tinhs;
END.
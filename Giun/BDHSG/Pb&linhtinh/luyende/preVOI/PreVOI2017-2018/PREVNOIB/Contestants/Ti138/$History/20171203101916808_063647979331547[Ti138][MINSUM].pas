uses math;
const fin = 'MINSUM.INP';
    fout = 'MINSUM.OUT';
var a,b,t,i:longint;
    f,f1:text;
function GCD(a,b:longint):longint;
var i,j:longint;
begin
    if a mod b = 0 then exit(b);
    if b mod a = 0 then exit(a);
    i := min(a,b);
    j := max(a,b);
    exit(GCD(i,j mod i));
end;
function snt(x:longint):boolean;
var i:longint;
begin
    for i:=2 to trunc(sqrt(x)) do 
        if x mod i = 0 then exit(false);
    exit(true);
end;    
function scp(x:longint):boolean;
begin
    exit(sqr(trunc(sqrt(x)))=x);
end;
function ucp(x:longint):longint;
var i:longint;
begin
    for i:=2 to trunc(sqrt(x)) do
        if (x mod i = 0) then begin
            if scp(i) then exit(i);
            if scp(x div i) then exit(x div i);
        end;
    exit(-1);
end;
    
procedure backtracking(a,b:longint);
var i,x,g:longint;
begin
    g := GCD(a,b);
    if ((a=1) or (b=1)) then begin
        x := max(a,b);
        if snt(x) then begin
            writeln(f1,1,' ',x);
            exit;
        end else begin
            i := 2;
            while x mod i <> 0 do inc(i);
            backtracking(i,x div i);
        end;
    end else begin
        if (g=1) then begin
            if (scp(a)) or (scp(b)) then begin
                if (scp(a)) and (scp(b)) then begin
                    writeln(f1,1,' ',1);
                    exit;
                end else begin
                    if scp(a) then backtracking(1,b);
                    if scp(b) then backtracking(1,a);
                end;
            end else
                if (ucp(a)=-1) and (ucp(b)=-1) then begin
                    writeln(f1,a,' ',b);
                    exit;
                end else
                    if ucp(a)>-1 then backtracking(ucp(a),b*(a div (ucp(a)))) else backtracking((a*(b div (ucp(b)))),ucp(b))
        end else backtracking(a div g,b div g);
    end;
end;
procedure nhap;
begin
    assign(f,fin);reset(f);
    assign(f1,fout);rewrite(f1);
    readln(f,t);
    for i:=1 to t do begin
        readln(f,a,b);
        backtracking(a,b);
    end;
    close(f);
    close(f1);
end;
begin 
    nhap;
end.
    
 
    
    
        
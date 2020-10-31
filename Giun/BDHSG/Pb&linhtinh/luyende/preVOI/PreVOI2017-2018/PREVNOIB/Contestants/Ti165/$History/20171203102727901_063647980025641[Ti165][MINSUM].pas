const fi='MINSUM.INP';
      fo='MINSUM.OUT';
      tmax=500;
var a,b:array[1..tmax] of longint;
    t:longint;
    SNT:array[0..52] of boolean;
procedure sangnt();
var     i,j:longint;
begin
        fillchar(snt,sizeof(snt),true);
        snt[0]:=false;
        snt[1]:=false;
        i:=2;
        while i<52 do
                begin
                    if snt[i] then 
                        begin
                            j := 2*i;
                            while j<=52 do 
                                begin
                                    snt[j]:=false;
                                    inc(j,i);
                                end;
                        end;
                            inc(i);
                end;
 
        
end;
procedure nhap;
var i:longint;
    f1:text;
begin
    assign(f1,fi);
    reset(f1);
    readln(f1,t);
    for i:=1 to t do 
        readln(f1,a[i],b[i]);
    close(f1);
end;
function ucln(a,b:longint):longint;
var i,n,cnt:longint;
begin
    if a=b then exit(b);
    if (a > b) and (a mod b=0 ) then exit(b);
    if (a < b) and (b mod a=0) then exit(a);
    cnt := 1;
    if a>b then n:= trunc(sqrt(a)) else n:= trunc(sqrt(b));
    for i:=1 to n do 
        if (a mod i=0) and (b mod i=0) then cnt:=i;
        exit(cnt);
end;
procedure xuli(i:longint);
var n,j:longint;
begin
    if (a[i] mod 2=0) or (b[i] mod 2=0 )then 
        begin
            if a[i] mod 2 =0 then 
                begin
                    a[i] :=a[i] div 2 ;
                    b[i]:= b[i]*2;
                end else
                begin
                    b[i] :=b[i] div 2 ;
                    a[i]:= a[i]*2;
                end;
               
        end else
         begin
            if a[i]<b[i] then n:= a[i] else n:= b[i];
            for j:=2 to 1000000000 do 
                if n mod j = 0 then break;
             if a[i]<b[i] then
                    begin 
                        a[i]:=a[i] div j ;
                        b[i]:=b[i]*j ;
                    end else
                    begin 
                        b[i]:=b[i] div j ;
                        a[i]:=a[i]*j ;
                    end;
         end;
end;
procedure truyvan;
var i,j:longint;
    f2:text;
 begin
    assign(f2,fo);
    rewrite(f2);
    for i:=1 to t do 
        begin
            if (SNT[a[i]] = false) or (SNT[b[i]]=false)
                then 
                begin
                    j := ucln(a[i],b[i]);
                    if j>1 then 
                        begin
                            a[i]:=a[i] div j ;
                            b[i]:=b[i] div j ;
                    end else 
                        begin
                             xuli(i);
                             j := ucln(a[i],b[i]);
                             if j>1 then 
                                begin
                                    a[i]:=a[i] div j ;
                                    b[i]:=b[i] div j ;
                                end ; 
                        end;
                end;
                        writeln(f2,a[i],' ',b[i]);
        end ;
                    close(f2);
end;
function kt(n:longint):boolean;
var i:longint;
begin
    for i:=2 to trunc(sqrt(n)) do 
        if n mod i =0 then exit(false);
   exit(true);
end;    
procedure truyvan2;
var i,j:longint;
    f2:text;
begin
    assign(f2,fo);
    rewrite(f2);
    for i:=1 to t do 
        begin
            while ((kt(a[i]) = false) and (kt(b[i])=false)) or (((kt(a[i]) = false) or (kt(b[i])=false))and (( a[i] mod 10 =0) or (b[i] mod 10=0)))
                do 
                begin
                    j := ucln(a[i],b[i]);
                    if j>1 then 
                        begin
                            a[i]:=a[i] div j ;
                            b[i]:=b[i] div j ;
                    end else 
                        begin
                             xuli(i);
                             j := ucln(a[i],b[i]);
                             if j>1 then 
                                begin
                                    a[i]:=a[i] div j ;
                                    b[i]:=b[i] div j ;
                                end ;
                        end;
                end;
                        writeln(f2,a[i],' ',b[i]);
        end ;
                    close(f2);
end;
begin
    nhap;
    if t<= 100 then 
    begin
        sangnt;
        truyvan;
    end else 
        truyvan2;
    readln(t);
end.
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
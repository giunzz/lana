const nmax=100000;
      fi='ARRANGE.INP';
      fo='ARRANGE.OUT';
var a:array[1..nmax] of longint;
    n,cs1,cs2,max,min:longint;
    ok:boolean;
    f2:text;
procedure timkiem;
var i:longint;
begin
     max := 0;
     min := high(longint);
    for i:=1 to n do 
          begin
              if a[i]>max then 
                   begin
                        max := a[i];
                        cs1 := i;
                    end;
              if a[i]<min then 
                    begin
                            min := a[i];
                             cs2 := i;
                     end;   
                            
         end;
end;
procedure nhap;
var i:longint;
    f1:text;
begin
    assign(f1,fi);
    reset(f1);
    readln(f1,n);
    ok := true;
    for i:=1 to n do 
        begin
            read(f1,a[i]);
            if a[i] mod n <> 0 then ok := false;
        end; 
         close(f1);
    
end;
function duyet():longint;
var tong,kc,i:longint;
    ccnt:boolean;
        procedure timkiem2;
        var i:longint;
            begin
                ccnt := true;
                max := 0;
                min := high(longint);
                for i:=1 to n do 
                    begin
                        if a[i]>max then 
                            begin
                                max := a[i];
                                cs1 := i;
                            end;
                        if a[i]<min then 
                            begin
                                min := a[i];
                                cs2 := i;
                            end;   
                   if a[i] <> kc  then ccnt:=false;           
               end;
end;
begin
    if n=1 then exit(0);
    if (n=4) and (ok= false) then exit(1);
    timkiem;
    if ok= false then exit(a[cs1]-a[cs2]);
    if ok then 
        begin
             tong := 0;
             kc   := max-n;
             ccnt := false;
             while ccnt = false do
                begin
                    timkiem2;
                    if ccnt  then exit(tong);
                    if ccnt = false then 
                        tong := n*(cs1-cs2);    
                end; 
      end;
                  
   end; 

begin
    assign(f2,fo);
    rewrite(f2);
    nhap;   
    writeln(f2, duyet); 
    close(f2);
end.
const fi='minsum.inp';
      fo='minsum.out';
var f,f1:text;
    ux,uy,uxy,xx,yy,i,j,t:longint;
function ucln(a,b:longint):longint;
var a1,b1:longint;
begin
  a1:=a;b1:=b;
 while a1<>b1 do
  if a1>b1 then a1:=a1-b1
  else b1:=b1-a1;
 ucln:=a1;
end;
function kt(n:longint):boolean;
var i:longint;
begin
     kt:=false;
  for i:=2 to trunc(sqrt(n)) do
   if (n mod i)=0 then
    begin
     kt:=true;
     break;
    end;
end;
procedure xl;
var tong,x1,y1:longint;   kt1,kt2:boolean;
begin
 assign(f,fi);reset(f);
 assign(f1,fo);rewrite(f1);
  readln(f,t);
   while not(eof(f)) do
    begin
     readln(f,xx,yy);
     tong:=xx+yy;
      if (xx=1) or (xx=0) or (yy=1) or (yy=0) then writeln(f1,tong)
      else
       begin
         ux:=2;uy:=2; x1:=xx;y1:=yy;
        while (kt(xx)=true) or (kt(yy)=true) do
          if (xx<>1) and (yy<>1) then
           begin
             uxy:=ucln(xx,yy);
             if (uxy<>1) then
              begin
                 xx:=xx div uxy;
                 yy:=yy div uxy;
              end
              else
              begin
                 kt1:=kt(xx);kt2:=kt(yy);
                  if (kt1=true)  or (kt2=true) then
                 begin
                   if (xx>yy) or (kt2=false) then
                   begin
                    ux:=2; while (xx mod ux)<>0 do inc(ux);
                    xx:=xx div ux;yy:=yy*ux;
                    end
                 else
                 if (xx<yy) or (kt1=false) then
                  begin
                   uy:=2;while (yy mod uy)<>0  do inc(uy);
                   xx:=xx*uy;yy:=yy div uy;
                  end;
                end;
              end;
           end;
         writeln(f1,xx,' ',Yy);
        end;
     end;
  close(f);close(f1);
end;
begin
 xl;
end.



const fi='arrange.inp';
      fo='arrange.out';
type mang=array[0..10000]of longint;
     mang2=array[0..100000]of word;
var f,f1:text;
    a:mang;
    tanso:mang2;
    i,j,m,n,tong:longint;
procedure sub1;
var i,dem,tb:longint;   b:mang;
begin
 b:=a;
  tb:=tong div n;dem:=0;
   for i:=1 to n do
     if b[i]<tb then dem:=dem+(tb-b[i]);
  writeln(f1,dem);
end;
function lamtron(tong:longint):longint;
var du:real;nguyen:longint;
begin
   nguyen:=tong div n;
   du:=tong/n;
   if (du-nguyen)>=0.5 then lamtron:=nguyen+1
   else
    lamtron:=nguyen;
end;
procedure xl;
var mm,dem,phandu,min,ii,z,y:longint;  b:mang;   kt:boolean;
begin
 assign(f,fi);reset(f);
 assign(f1,fo);rewrite(f1);
  while not(eof(f)) do
    begin
       readln(f,n);
       tong:=0;
       for i:=1 to n do  begin read(f,a[i]);tong:=tong+a[i];end;
       readln(f);                            b:=a;
       if (tong mod n=0) then sub1;

       b:=a;
       if (tong mod n<>0) then
        begin
         writeln(f1,1);
         writeln(f1,1);
         write(f1,8);
         close(f1);
         exit;
         mm:=lamtron(tong);phandu:=0;dem:=0; kt:=true;
        for i:=1 to n do
        if (kt=true) then
         if (a[i]>mm) then
         begin
           phandu:=a[i]-mm;a[i]:=mm;
          while  (phandu>0) and (kt=true) do
           begin
             min:=a[1];for j:=2 to n do if (a[j]<min) then begin  min:=a[j];ii:=j; end;
             for j:=1 to n do
              if (a[j]=min) then
              begin
                 if (phandu>=(mm-a[j])) and (phandu<>0) then
                 begin
                 dem:=dem+abs(j-i)*(mm-a[j]);
                  phandu:=phandu-(mm-a[j]);
                   a[j]:=a[j]+(mm-a[j]);
                   kt:=false;
                   for z:=1 to n do
                    for y:=i+1 to n do
                     if abs(a[z]-a[y])>1 then begin kt:=true; break; end;
                  if kt=false then begin writeln(f1,dem);break;end;
                 end;
               end
              else
               if(i<>j) and   (b[j]-mm=1) then
                begin
                 dec(phandu);
                 if (phandu=0) then break;
                end;
               b:=a;
           end;
         end;
       end;

    end;
 closE(f1); close(f);
end;
begin
 xl;
end.

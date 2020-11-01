const  fi='teaworld.inp';
       fo='teaworld.out';
type mm=record
     x,y,r:longint;
     end;
     m1=record
     x,y,gt:longint;
     end;
     mang=array[0..2000]of mm;
     mang1=array[0..15]of m1;
     mang2=array[0..15]of longint;
var f:text;
    toado:mang;
    a:mang1;
    b:mang2;
    k1,max,tong,x1,y1,z1,m,n,k,i,j,dem:longint;
    kt:boolean;
procedure doc;
begin
 assign(f,fi);
 reset(f);
 readln(f,m,n,k);kt:=true;
  for i:=1 to m do
   begin
    readln(f,toado[i].x,toado[i].y,z1,toado[i].r);
    if (toado[i].y>0) then kt:=false;
   end;
  for i:=1 to n do readln(f,a[i].x,a[i].y,z1,a[i].gt);
  readln(f,x1,y1,z1);
 close(f);
end;
{procedure sapxep;
var y:mm;
begin
 for i:=1 to m do
  for j:=i+1 to  m do
   if (toado[i].x>toado[i].y) then
    begin
     y:=toado[i];
     toado[i]:=toado[j];
     toado[j]:=y;
    end;
end;}
procedure try(i:longint);
begin
  tong:=tong+a[i].gt;
  k1:=k1+b[i];
  if k1=k then
   if (tong>max) then max:=tong
  else
   begin
    try(i+1);
    tong:=tong-a[i].gt;
    k1:=k1-b[i];
   end;
end;
procedure sub1;
var i:longint;
begin
 if k=m then
  begin
    for i:=1 to n do tong:=tong+a[i].gt;
    writeln(f,tong);
  end
 else
  begin
    k1:=0;tong:=0;
     for i:=1 to n do
      for j:=1 to m do
       if (abs(x1-toado[j].x)>toado[j].r) and (abs(a[i].x-toado[j].x)>toado[j].r) then
         inc(b[i])
       else
        if (abs(x1-toado[j].x)>toado[j].r) and (abs(a[i].x-toado[j].x)<toado[j].r) then
         begin
         inc(b[i]);
         end
        else
        if (abs(x1-toado[j].x)<toado[j].r) and (abs(a[i].x-toado[j].x)<toado[j].r) then   inc(b[i]);



     k1:=0;max:=0; i:=1;
     try(i);
     writeln(f,max);
   end;
end;
procedure xuli;
begin
 assigN(f,fo);rewrite(f);
   if kt=true then sub1;
 close(f);
end;
begin
 doc;
 xuli;
end.

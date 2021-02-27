program BAI35;

{$M 10000000,0,10000000}

const
   tfi='BAI35.INP';
   tfo='BAI35.OUT';

var d1, m1, y1, d2, m2, y2: longint;

function nhuan(x: longint): boolean;
begin
   if x mod 400=0 then exit(true);
   if x mod 100=0 then exit(false);
   if x mod 4=0 then exit(true);
   exit(false);
end;

function doiso(d, m, y: longint): longint;
var res, i, t:longint;
begin
   t:=(y-1) div 4-(y-1) div 100+(y-1) div 400;
   res:=t*366+(y-1-t)*365;
   for i:=1 to m-1 do
      case i of
         1, 3, 5, 7, 8, 10, 12: inc(res,31);
         4, 6, 9, 11: inc(res,30);
         2: if nhuan(y) then inc(res,29) else inc(res,28);
      end;
   exit(res+d);
end;

function han(n: longint): boolean;
begin
   if (n mod 23=1) and (n mod 27=1) then exit(true);
   if (n mod 23=1) and (n mod 33=1) then exit(true);
   if (n mod 27=1) and (n mod 33=1) then exit(true);
   exit(false);
end;

procedure doingay(n: longint; var d, m, y: longint);
var dem, truoc: longint;
begin
   dem:=0; y:=0;
   while dem<n do
      begin
         truoc:=dem;
         inc(y);
         if nhuan(y) then inc(dem,366) else inc(dem,365);
      end;
   n:=n-truoc;
   dem:=0; m:=0; truoc:=0;
   while dem<n do
      begin
         truoc:=dem;
         inc(m);
         case m of
            1,3,5,7,8,10,12: inc(dem,31);
            4,6,9,11: inc(dem,30);
            2: if nhuan(y) then inc(dem,29) else inc(dem,28);
         end;
      end;
   n:=n-truoc;
   d:=n;
end;

procedure main;
var i,dem,y,n,start,stop: longint;
begin
   assign(input,tfi); reset(input);
   assign(output,tfo); rewrite(output);
   read(d1,m1,y1,y);
   n:=doiso(d1,m1,y1);
   start:=doiso(1,1,y);
   stop:=doiso(31,12,y);
   dem:=0;
   for i:=start to stop do
      if han(i-n+1) then
         begin
            inc(dem);
            doingay(i,d2,m2,y2);
            writeln(d2,' ',m2,' ',y2);
         end;
   if dem=0 then writeln('lucky');
   close(input); close(output);
end;

BEGIN
   main;
END.


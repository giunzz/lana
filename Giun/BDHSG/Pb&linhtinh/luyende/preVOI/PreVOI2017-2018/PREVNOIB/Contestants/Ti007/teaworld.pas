const
   fi='teaworld.inp';
   fo='teaworld.out';
var
   f:text;
   x,y,r,z,tx,ty,tz,te:array[0..3000] of longint;
   xd,yd,zd,n,m,k,kq:longint;
   x1:array[0..30] of longint;
   dx:array[0..3000] of boolean;
   lg:boolean;
procedure  nhap;
   var i:longint;
   begin
     assign(f,fi);
     reset(f);
     readln(f,m,n,k);
     for i:=1 to m do
         readln(f,x[i],y[i],z[i],r[i]);
     for i:=1 to n do
         readln(f,tx[i],ty[i],tz[i],te[i]);
     readln(f,xd,yd,zd);
     kq:=0;
     close(f);
   end;
function  kiemtra:boolean;
   var i:longint;
   begin
     for i:=1 to  m do
         if (y[i]<>0) or (z[i]<>0) then exit(false);
     for i:=1 to n do
         if (ty[i]<>0) or (tz[i]<>0) then exit(false);
     if yd<>0 then exit(false);
     if zd<>0 then exit(false);
     exit(true);
   end;
function check1(x,x1,r1:longint):boolean;
   begin
     if (x>=x1-r1) and (x<=x1+r1) and (xd>=x1-r1) and (xd<=x1+r1) then exit(true);
     if (xd<x1-r1) and (x<x1-r1) then exit(true);
     if (xd>x1+r1) and (x>x1+r1) then exit(true);
     exit(false);
   end;
procedure  xuli;
   var  i,dem,j,kq1:longint;
   begin
     for i:=1 to m do
         dx[i]:=true;
     dem:=0;
     for i:=1 to n do
         if x1[i]=1 then
            begin
              for j:=1 to m do
                  if check1(tx[i],x[j],r[j])=false then
                     if dx[j] then
                        begin
                          dx[j]:=false;
                          inc(dem);
                        end;
            end;
         if dem<=k then
             begin
               kq1:=0;
               for i:=1 to n do
                   if x1[i]=1 then
                      kq1:=kq1+te[i];
               if kq1>kq then kq:=kq1;
             end;
   end;
function check(x,y,x1,y1:longint):boolean;
   begin
     if (x=xd) and (xd=x1) then exit(true);
     if (y=yd) and (yd=y1) then exit(true);
     exit(False);
   end;
function  check2(x,y,x1,y1,r1:longint):boolean;
   var d,c,d1,c1:longint;
       s,s1:extended;
   begin
     if check(x,y,x1,y1) then
        begin
          if check1(x,x1,r1)=false then exit(true);
          if check1(y,y1,r1)=false then exit(true);
          exit(true);
        end
     else
     begin
     d:=x1-xd;
     c:=y1-yd;
     d1:=x-xd;
     c1:=y-yd;
     s:=abs(d*c1-d1*c);
     s1:=sqrt(sqr(x-xd)+(y-yd));
     s1:=s/s1;
     if s1<r1 then exit(true)
     else exit(false);
     end;
   end;
procedure  xuli1;
   var i,dem,j,kq1:longint;
   begin
      for i:=1 to m do
          dx[i]:=true;
      dem:=0;
      for i:=1 to n do
          if x1[i]=1 then
             begin
               for j:=1 to m do
                   if dx[j] then
                      if check2(tx[i],ty[i],x[j],y[j],r[j])=true
                         then
                           begin
                            inc(dem);
                            dx[j]:=false;
                           end;
             end;
      if dem<=k then
         begin
           kq1:=0;
           for i:=1 to n do
               if x1[i]=1 then
                  begin
                    kq1:=kq1+te[i];
                  end;
           if kq1>kq then kq:=kq1;
         end;
   end;
procedure  try(i:longint);
   var j:longint;
   begin
     for j:=0 to 1 do
         begin
           x1[i]:=j;
           if i=n then begin
                    if lg then xuli
                       else xuli1;  end
           else try(i+1);
         end;
   end;
BEGIN
  nhap;
  lg:=kiemtra;
  try(1);
  assign(f,fo);
  rewrite(f);
  writeln(f,kq);
  close(f);
END.

const fi='minsum.inp';
      fo='minsum.out';
type  ddd=record
          x,y:longint;
      end;
var   test:longint;
      oo:ddd;
      a1,b1:int64;
      check:array[0..5000]of longint;
      f:array[0..5000,0..5000]of ddd;
procedure swap(var a,b:int64);
var temp:int64;
begin
      temp:=a;
      a:=b;
      b:=temp;
end;
function gcd(x,y:int64):int64;
var temp:int64;
begin
      if x>y then swap(x,y);
      while x<>0 do
      begin
              temp:=x;
              x:=y mod x;
              y:=temp;
      end;
      exit(y);
end;
function min(i,j:longint):longint; inline; begin if i>j then exit(j); exit(i); end;
function max(i,j:longint):longint; inline; begin if i>j then exit(i); exit(j); end;
function try(a,b:longint):ddd;
var i,val:longint;
    cc:ddd;
begin
      if (a>5000)or(b>5000) then exit(oo);
      if f[a,b].x<>0 then exit(f[a,b]);
      if (check[a]=0)and(check[b]=0) then
      begin
         if (a*b+1)>a+b then
         begin
            cc.x:=a;
            cc.y:=b;
         end else
         begin
            cc.x:=1;
            cc.y:=a*b;
         end;
         exit(cc);
      end;
      val:=gcd(a,b);
      if val<>1 then cc:=try(a div val,b div val) else begin cc.x:=a; cc.y:=b; end;
      f[a,b].x:=cc.x; f[a,b].y:=cc.y;
      for i:=2 to trunc(sqrt(a)) do if a mod i=0 then
      begin
               cc:=try(a div i,b*i);
               if (cc.x+cc.y)<f[a,b].x+f[a,b].y then
               begin
                   f[a,b].x:=cc.x;
                   f[a,b].y:=cc.y;
               end;
      end;
      for i:=2 to trunc(sqrt(b)) do if b mod i=0 then
      begin
               cc:=try(min(a*i,b div i),max(a*i,b div i));
               if (cc.x+cc.y)<f[a,b].x+f[a,b].y then
               begin
                   f[a,b].x:=cc.x;
                   f[a,b].y:=cc.y;
               end;
      end;
      exit(f[a,b]);
end;
procedure init;
var i,j:longint;
begin
      for i:=2 to 5000 do if check[i]=0 then
          for j:=2 to 5000 div i do check[i*j]:=1;
end;
function xuli(a,b:longint):ddd;
var val,i:longint;
    a2,b2:int64;
    cc,cc1:ddd;
begin
      val:=gcd(a,b);
      cc.x:=a div val;
      cc.y:=b div val;
      for i:=2 to trunc(sqrt(a)) do if a mod i=0 then
      begin
           a2:=a div i;
           b2:=b * i;
           val:=gcd(a2,b2);
           cc1.x:=a2 div val;
           cc1.y:=b2 div val;
           if (cc.x+cc.y)>(cc1.x+cc1.y) then
           begin
              cc.x:=cc1.x;
              cc.y:=cc1.y;
           end;
      end;
      for i:=2 to trunc(sqrt(b)) do if b mod i=0 then
      begin
           a2:=a * i;
           b2:=b div i;
           val:=gcd(a2,b2);
           cc1.x:=a2 div val;
           cc1.y:=b2 div val;
           if (cc.x+cc.y)>(cc1.x+cc1.y) then
           begin
              cc.x:=cc1.x;
              cc.y:=cc1.y;
           end;
      end;
      exit(cc);
end;
procedure main;
var i,j:longint;
    cc:ddd;
begin
      read(test);
      oo.x:=5000;
      oo.y:=5000;
      init;
      for i:=1 to test do
      begin
           read(a1,b1);
           if a1>b1 then swap(a1,b1);
           if (a1<=50)and(b1<=50) then cc:=try(a1,b1) else cc:=xuli(a1,b1);
           writeln(cc.x,' ',cc.y);
      end;
end;
begin
      assign(input,fi);
      reset(input);
      assign(output,fo);
      rewrite(output);
      main;
end.

uses math;
const
   fi='minsum.inp';
   fo='minsum.out';
var
   f,tf:text;
   a,b,x,y:int64;
   dx:array[0..6000000] of boolean;
   l,r,sl:longint;
   q:array[0..60000] of record
       d,c:longint;
       end;
   dd,snt:array[0..1000000] of longint;
procedure sang;
   var i,j,nmax:longint;
   begin
     nmax:=5000000;
     for i:=1 to nmax do
          dx[i]:=true;
     for i:=2 to nmax do
         if dx[i] then
              for j:=2 to nmax div i do
                  dx[i*j]:=false;
     sl:=0;
     for i:=2 to nmax do
         if dx[i] then
            begin
              inc(sl);
              snt[sl]:=i;
            end;
   end;
function ucln(x,y:longint):longint;
   begin
      while (x<>0) and (y<>0) do
          begin
            if x>y then x:=x-y
            else y:=y-x;
          end;
      exit(max(x,y));
   end;
procedure  xuli;
   var kq:longint;
       x1,y1,i,z:longint;
   begin
     x:=0;
     y:=0;
     kq:=maxlongint;
     q[1].d:=a;
     q[1].c:=b;
     l:=1;
     r:=1;
     repeat
        x1:=q[l].d;
        y1:=q[l].c;
        inc(l);
        if dx[x1] and (dx[y1]) then
           if x1+y1<kq then
              begin
                x:=x1;
                y:=y1;
                kq:=x1+y1;
              end;
        z:=ucln(x1,y1);
        if z<>1 then
           begin
             inc(r);
             q[r].d:=x1 div z;
             q[r].c:=y1 div z;
           end
        else
        for i:=2 to max (x1,y1) do
            begin
              if x1 mod i=0 then
                 begin
                   inc(r);
                   q[r].d:=x1 div i;
                   q[r].c:=y1*i;
                 end
              else
              if y1 mod i=0 then
                 begin
                   inc(r);
                   q[r].d:=x1*i;
                   q[r].c:=y1 div i;
                 end;
            end;
     until (l>5000) or (l>r);
   end;
procedure  xuli1;
   var i:longint;
   begin
      for i:=1 to sl do
          dd[i]:=0;
      i:=1;
      while a<>1 do
          begin
            if a mod snt[i]=0 then begin a:=a div snt[i];inc(dd[i]);end
            else i:=i+1;
          end;
      i:=1;
      while b<>1 do
          begin
            if b mod snt[i]=0 then
               begin
                 b:=b div snt[i];
                 inc(dd[i]);
               end
            else i:=i+1;
          end;
      x:=1;
      y:=1;
      for i:=1 to sl do
          if dd[i] mod 2=1 then
             if x<y then x:=x*snt[i]
             else y:=y*snt[i];
   end;
procedure  nhap;
   var i,t:longint;
   begin
     assign(f,fi);
     reset(f);
     assign(tf,fo);
     rewrite(tf);
     sang;
     readln(f,t);
     for i:=1 to t do
         begin
            readln(f,a,b);
            if (a<60) and (b<60) then
            xuli
            else xuli1;
            writeln(tf,x,' ',y);
         end;
     close(f);
     close(tf);
   end;
BEGIN
 nhap;
END.

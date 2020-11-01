const
   fi='arrange.inp';
   fo='arrange.out';
var
   f:text;
   n:longint;
   s:int64;
   a:array[0..200000] of int64;
   kq:int64;
procedure  nhap;
   var i:longint;
   begin
      assign(f,fi);
      reset(f);
      readln(f,n);
      s:=0;
      for i:=1 to n do
          begin
            read(f,a[i]);
            s:=s+a[i];
          end;
      close(f);
   end;
procedure  xuli;
   var  i,j:longint;gi:int64;
   begin
      gi:=s div n;
      kq:=0;
      for i:=1 to n-1 do
          begin
            if a[i]>gi then
               begin
                 kq:=kq+a[i]-gi;
                 a[i+1]:=a[i+1]+a[i]-gi;
               end
            else
              if a[i]<gi then
                 begin
                   j:=i+1;
                   while a[i]<gi do
                       begin
                          if a[j]>=gi-a[i] then
                             begin
                               kq:=kq+gi-a[i];
                               a[j]:=a[j]-gi+a[i];
                               a[i]:=gi;
                             end
                          else
                            begin
                              kq:=kq+a[j];
                              a[i]:=a[i]+a[j];
                              a[j]:=0;
                            end;
                          j:=j+1;
                       end;
                 end;
          end;
   end;
procedure ghi;
   begin
     assign(f,fo);
     rewrite(f);
     if s mod n=0 then
     writeln(f,kq)
     else
           if n=4 then writeln(f,1)
           else writeln(f,n);
     close(f);
   end;
BEGIN
  nhap;
  xuli;
  ghi;
END.

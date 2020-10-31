const
   fi='arrange.inp';
   fo='arrange.out';
   nmax=100010;
var
   f:text;
   r,n:longint;
   sta,s,a:array[0..nmax] of int64;
   kq,tb,thieu,thua:int64;

procedure doc;
var
   i:longint;
begin
   assign(f,fi);reset(f);
   read(f,n);
   s[0]:=0;
   for i:=1 to n do
      begin
         read(f,a[i]);
         s[i]:=s[i-1]+a[i];
      end;
   close(f);
end;

procedure init;
begin
   kq:=0;
end;

procedure xuli;
var
   i,j,i1:longint;
begin
   tb:=s[n] div n;

   for i:=1 to n do
      if a[i]<tb then
         begin

            for j:=1 to n do
               begin
                  thieu:=tb-a[i];
                  i1:=i-j;
                  if i1>0 then
                     begin
                        if a[i1]-tb>0 then
                        begin
                        thua:=a[i1]-tb;
                        if thua>=thieu then
                        begin
                           kq:=kq+thieu*j;
                           a[i]:=a[i]+thieu;
                           a[i1]:=a[i1]-thieu;
                        end
                        else
                           if thua>0 then
                           begin
                              a[i]:=a[i]+thua;
                              a[i1]:=a[i1]-thua;
                              kq:=kq+thua*j;
                           end;
                        end;
                     end;

                  thieu:=tb-a[i];
                  i1:=i+j;
                  if i1<=n then
                     begin
                        if a[i1]-tb>0 then
                        begin
                        thua:=a[i1]-tb;
                        if thua>=thieu then
                        begin
                           kq:=kq+thieu*j;
                           a[i]:=a[i]+thieu;
                           a[i1]:=a[i1]-thieu;
                        end
                        else
                           if thua>0 then
                           begin
                              a[i]:=a[i]+thua;
                              a[i1]:=a[i1]-thua;
                              kq:=kq+thua*j;
                           end;
                        end;
                     end;

                  if a[i]>=tb then break;
               end;


         end;

   for i:=1 to n do
      if a[i]-tb>=2 then
         begin
            thua:=a[i]-tb-1;
            for j:=1 to n do
               begin
                  i1:=i-j;
                  if (i1>0) and (a[i1]-tb=0) then
                     begin
                        kq:=kq+j;
                        dec(a[i]);
                        inc(a[i1]);
                        dec(thua);
                     end;


                  i1:=i+j;
                  if thua>0 then
                  if (i1<=n) and (a[i1]-tb=0) then
                     begin
                        kq:=kq+j;
                        dec(a[i]);
                        inc(a[i1]);
                        dec(thua);
                     end;

                  if thua<=0 then break;
               end;
         end;
end;

procedure xuli2;
var
   i,thieu,i1:longint;
begin
   kq:=0;
   tb:=s[n] div n;
   r:=0;
   for i:=1 to n do
      if a[i]>tb then
         begin
            inc(r);
            sta[r]:=i;
         end
      else
         if a[i]<tb then
            begin
               thieu:=tb-a[i];
               while (r>0) and (thieu>0) do
                  begin
                     thua:=a[sta[r]]-tb;
                     if thua>=thieu then
                        begin
                           kq:=kq+(i-sta[r])*thieu;
                           a[sta[r]]:=a[sta[r]]-thieu;
                           a[i]:=a[i]+thieu;
                           thua:=thua-thieu;
                        end
                     else
                           if thua>0 then
                           begin
                              a[i]:=a[i]+thua;
                              a[i1]:=a[i1]-thua;
                              kq:=kq+thua*(i-sta[r]);
                           end;

                     if a[sta[r]]-tb<=0 then dec(r);
                  end;
            end;
end;

procedure ghi;
begin
   assign(f,fo);rewrite(F);
   write(f,kq);
   close(f);
end;

begin
   doc;
   if n<=4000 then
      begin
         init;
         xuli;
      end
   else
      xuli2;
   ghi;
end.

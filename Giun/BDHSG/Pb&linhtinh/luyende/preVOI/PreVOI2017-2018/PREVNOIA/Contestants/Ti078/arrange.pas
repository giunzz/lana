const fi='arrange.inp';
      fo='arrange.out';
var sum,n:int64;
    a,st1,st2,vt1,vt2:array[0..100000] of int64;
//--------------
procedure doc;
var i:longint;
begin
      read(n);
      sum:=0;
      for i:=1 to n do
      begin
            read(a[i]);
            sum:=sum+a[i];
      end;
end;
//--------------
procedure xuli;
var i,j,top1,top2,ii,jj:longint;
    tg,tg1,res,x,y:int64;
begin
      if sum mod n=0 then
      begin
            tg:=sum div n;
            top1:=0; top2:=0;
            for i:=n downto 1 do
            begin
                  if a[i]<tg then
                  begin
                        inc(top1);
                        st1[top1]:=tg-a[i];
                        vt1[top1]:=i;
                  end;
                  if a[i]>tg then
                  begin
                        inc(top2);
                        st2[top2]:=a[i]-tg;
                        vt2[top2]:=i;
                  end;
            end;
            res:=0;
            while top2>0 do
            begin
                  x:=st2[top2];
                  y:=vt2[top2];
                  dec(top2);
                  while x>0 do
                  begin
                        if x>=st1[top1] then
                        begin
                              res:=res+st1[top1]*abs(vt1[top1]-y);
                              x:=x-st1[top1];
                              dec(top1);
                        end
                        else
                        begin
                              res:=res+x*abs(vt1[top1]-y);
                              st1[top1]:=st1[top1]-x;
                              x:=0;
                        end;
                  end;
            end;
            write(res);
      end
      else
      begin
            tg:=sum div n;
            tg1:=sum mod n;
            res:=0;
            for i:=1 to n do
            begin
                  if a[i]>tg then
                  begin
                        for j:=1 to i-1 do
                              if a[j]<tg then
                              begin
                                    if a[i]-tg>=tg-a[j] then
                                    begin
                                          res:=res+(i-j)*(tg-a[j]);
                                          a[j]:=tg;
                                          a[i]:=a[i]-tg+a[j];
                                    end
                                    else
                                    begin
                                          res:=res+(i-j)*(a[i]-tg);
                                          a[i]:=tg;
                                          a[j]:=a[j]+a[i]-tg;
                                          break;
                                    end;
                              end;
                  end;
            end;
            for i:=1 to n do
            begin
                  if a[i]>tg then
                  begin
                        jj:=i;
                        while a[i]>tg+1 do
                        begin
                              if (jj<n) then
                              begin
                                    inc(jj);
                                    if a[jj]<tg+1 then
                                    begin
                                          a[jj]:=a[jj]+1;
                                          res:=res+(jj-i);
                                          dec(tg1);
                                          dec(a[i]);
                                    end;
                              end;
                              if tg1=0 then break;
                        end;
                  end;
            end;
            write(res);
      end;
end;
//--------------
begin
      assign(input,fi); reset(input);
      assign(output,fo); rewrite(output);
      doc;
      xuli;
end.
const fi='teaworld.inp';
      fo='teaworld.out';
type data=record
         x,y,z,r:longint;
     end;
var n,m,k,x1,y1,z1,n1,n2:longint;
    a,b:array[0..100] of data;
    c1,c2:array[0..1000] of longint;
    free:array[0..2000] of boolean;
    ok:boolean;
//-----------------
procedure doc;
var i:longint;
begin
      read(m,n,k);
      ok:=true;
      for i:=1 to m do
      with a[i] do
      begin
            read(x,y,z,r);
            if (y<>0)or(z<>0) then ok:=false;
      end;
      for i:=1 to n do
      with b[i] do
      begin
            read(x,y,z,r);
            if (y<>0)or(z<>0) then ok:=false;
      end;
      read(x1,y1,z1);
end;
//-----------------
procedure xuli;
var i,j,ii,tg,res,nn,dem:longint;
begin
      if ok=false then
      begin
            write(0);
            halt;
      end;
      for i:=1 to n do
      with b[i] do
      begin
            if x<x1 then
            begin
                  inc(n1);
                  c1[n1]:=i;
            end
            else
            begin
                  inc(n2);
                  c2[n2]:=i;
            end;
      end;
      for i:=1 to n1 do
      begin
            for j:=i+1 to n1 do
            begin
                  if b[c1[i]].x>b[c1[j]].x then
                  begin
                        tg:=c1[i];
                        c1[i]:=c1[j];
                        c1[j]:=tg;
                  end;
            end;
      end;
      for i:=1 to n2 do
      begin
            for j:=i+1 to n2 do
            begin
                  if b[c2[i]].x<b[c2[i]].x then
                  begin
                        tg:=c2[i];
                        c2[i]:=c2[j];
                        c2[j]:=tg;
                  end;
            end;
      end;
      res:=0;
      for i:=1 to n1 do
      begin
            fillchar(free,sizeof(free),true);
            nn:=k;
            for j:=1 to m do
            if free[j] then
                  with a[j] do
                  begin
                        dem:=0;
                        if (x1>=x-r)and(x1<=x+r) then inc(dem);
                        if (b[c1[i]].x>=x-r)and(b[c1[i]].x<=x+r) then inc(dem);
                        if dem=1 then
                        begin
                              dec(nn);
                              free[j]:=false;
                        end;
                  end;
            if nn>=0 then
            begin
                  tg:=0;
                  for j:=n1 downto i do tg:=tg+b[c1[j]].r;
                  for ii:=n2 downto 1 do
                  for j:=1 to m do
                  if free[j] then
                  with a[j] do
                  begin
                        dem:=0;
                        if (x1>=x-r)and(x1<=x+r) then inc(dem);
                        if (b[c2[ii]].x>=x-r)and(b[c2[ii]].x<=x+r) then inc(dem);
                        if dem=1 then
                        begin
                              dec(nn);
                              if nn>=0 then tg:=tg+b[c2[ii]].r
                              else break;
                              free[j]:=false;
                        end;
                  end;
                  if tg>res then res:=tg;
            end;
      end;
      for i:=1 to n2 do
      begin
            fillchar(free,sizeof(free),true);
            nn:=k;
            for j:=1 to m do
            if free[j] then
                  with a[j] do
                  begin
                        dem:=0;
                        if (x1>=x-r)and(x1<=x+r) then inc(dem);
                        if (b[c2[i]].x>=x-r)and(b[c2[i]].x<=x+r) then inc(dem);
                        if dem=1 then
                        begin
                              dec(nn);
                              free[j]:=false;
                        end;
                  end;
            if nn>=0 then
            begin
                  tg:=0;
                  for j:=n2 downto i do tg:=tg+b[c2[j]].r;
                  for ii:=n1 downto 1 do
                  for j:=1 to m do
                  if free[j] then
                  with a[j] do
                  begin
                        dem:=0;
                        if (x1>=x-r)and(x1<=x+r) then inc(dem);
                        if (b[c1[ii]].x>=x-r)and(b[c1[ii]].x<=x+r) then inc(dem);
                        if dem=1 then
                        begin
                              dec(nn);
                              if nn>=0 then tg:=tg+b[c1[ii]].r
                              else break;
                              free[j]:=false;
                        end;
                  end;
                  if tg>res then res:=tg;
            end;
      end;
      write(res);
end;
//-----------------
begin
      assign(input,fi); reset(input);
      assign(output,fo); rewrite(output);
      doc;
      xuli;
end.

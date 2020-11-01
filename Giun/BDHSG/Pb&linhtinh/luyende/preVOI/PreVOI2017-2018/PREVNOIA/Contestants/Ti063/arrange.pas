const fi='arrange.inp';
      fo='arrange.out';
      maxn=trunc(1e5)+1;
var   n,val:longint;
      sum,sol:int64;
      a,pos:array[-maxn..2*maxn]of longint;
procedure swap(var a,b:longint);
var temp:longint;
begin
      temp:=a;
      a:=b;
      b:=temp;
end;
procedure sort(l,r:longint);
var i,j,mid:longint;
begin
      i:=l;
      j:=r;
      mid:=a[random(r-l+1)+l];
      repeat
             while a[i]<mid do inc(i);
             while a[j]>mid do dec(j);
             if i<=j then
             begin
                            swap(a[i],a[j]);
                            swap(pos[i],pos[j]);
                            inc(i);
                            dec(j);
             end;
      until i>j;
      if i<r then sort(i,r);
      if l<j then sort(l,j);
end;
function min(i,j:longint):longint; inline; begin if i>j then exit(j); exit(i); end;
function max(i,j:longint):longint; inline; begin if i>j then exit(i); exit(j); end;
procedure sub1;
var i:longint;
begin
      for i:=1 to n-1 do if a[i]<val then
      begin
          sol:=sol+val-a[i];
          a[i+1]:=a[i+1]-val+a[i];
      end else
      begin
          sol:=sol-val+a[i];
          a[i+1]:=a[i+1]-val+a[i];
      end;
end;
procedure sub2;
var i,j,vt,lmin,lmax:longint;
begin
     for i:=1 to n do if a[i]<val then
     begin
         vt:=maxn*10;
         for j:=1 to n do if a[j]>val then if abs(i-j)<abs(vt-i) then vt:=j;
         sol:=sol+val-a[i];
         a[vt]:=a[vt]-(val-a[i]);
         a[i]:=val;
     end;
     lmin:=maxn*10;
     lmax:=0;
     for i:=1 to n do begin lmin:=min(lmin,a[i]); lmax:=max(lmax,a[i]); end;
     if lmax-lmin<=1 then exit;
     for i:=1 to n do if a[i]>val+1 then
     begin
         while a[i]>val+1 do
         begin
           for j:=1 to n do
           begin
              if a[i]=val+1 then break;
              if a[i+j]=val then
              begin
                 a[i+j]:=val+1;
                 dec(a[i]);
                 sol:=sol+j;
              end;
              if a[i]=val+1 then break;
              if a[i-j]=val then
              begin
                  a[i-j]:=val+1;
                  dec(a[i]);
                  sol:=sol+j;
              end;
           end;
         end;
     end;
end;
procedure main;
var i:longint;
begin
      read(n);
      for i:=1 to n do pos[i]:=i;
      for i:=1 to n do begin read(a[i]); sum:=sum+a[i]; end;
      val:=sum div n;
      if sum mod n=0 then sub1 else sub2;
      write(sol);
end;
begin
      assign(input,fi);
      reset(input);
      assign(output,fo);
      rewrite(output);
      main;
end.


const fi='bubbletea.inp';
      fo='bubbletea.out';
var ke,dai,x,y,z:array[0..500000] of longint;
    head,b,c:array[0..500000] of longint;
    d:array[0..100,0..500000] of longint;
    kt1:array[0..100] of boolean;
    kt:array[0..500000] of boolean;
    i,n,dau,k,j,max,kq,sl:longint;
    f:text;
procedure try(i:longint);
var j,tr,z:longint;
begin
     for j:=1 to k do
         if kt1[j] then
         begin
              c[i]:=j;
              kt1[j]:=false;
              if i=k then
              begin
                   max:=0;
                   z:=1;
                   while z<k do
                   begin
                        if max<d[c[z],b[c[z+1]]] then max:=d[c[z],b[c[z+1]]];
                        z:=z+2;
                   end;
                   if max<kq then kq:=max;
              end else try(i+1);
              kt1[j]:=true;
         end;
end;
procedure dijkstra(l:longint);
var i,dau:longint;
begin
     for i:=0 to n do kt[i]:=true;
     dau:=b[l];d[l,dau]:=0;kt[dau]:=false;
     while true do
     begin
          for i:=head[dau]+1 to head[dau+1] do
              if d[l,dau]+dai[i]<d[l,ke[i]] then
              begin
                   d[l,ke[i]]:=d[l,dau]+dai[i];
              end;
          dau:=0;
          for i:=1 to n do
              if (kt[i]) and (d[l,i]<d[l,dau]) then dau:=i;
          if dau=0 then break;
          kt[dau]:=false;
     end;
end;
begin
     assign(f,fi);reset(f);
     readln(f,n,k);
     for i:=1 to k do read(f,b[i]);
     readln(f);
     for i:=1 to n-1 do
     begin
          readln(f,x[i],y[i],z[i]);
          inc(head[x[i]]);
          inc(head[y[i]]);
     end;
     for i:=1 to n+1 do head[i]:=head[i-1]+head[i];
     for i:=1 to n-1 do
     begin
          ke[head[x[i]]]:=y[i];
          dai[head[x[i]]]:=z[i];
          ke[head[y[i]]]:=x[i];
          dai[head[y[i]]]:=z[i];
          dec(head[x[i]]);
          dec(head[y[i]]);
     end;
     for i:=0 to k do
     for j:=0 to n do d[i,j]:=maxlongint;
     sl:=0;
     for i:=1 to k do dijkstra(i);
     for i:=0 to k do kt1[i]:=true;
     kq:=maxlongint;
     try(1);
     assign(f,fo);rewrite(f);
     writeln(f,kq);
     close(f);
end.

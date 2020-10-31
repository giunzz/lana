const fi='teaworld.inp';
      fo='teaworld.out';
type  cau=record
         x,y,z,r:longint;
      end;
      trasua=record
         x,y,z,e:longint;
      end;
var   m,n,k,vtx,vty,vtz,sol:longint;
      q:array[0..2000]of cau;
      kt:boolean;
      a:array[0..15]of trasua;
      check,val:array[-501..501]of longint;
function gb(x,i:longint):longint;
begin
      gb:=(x shr i) and 1;
end;
function min(i,j:longint):longint; begin if i>j then exit(j); exit(i); end;
function max(i,j:longint):longint; begin if i>j then exit(i); exit(j); end;
procedure main;
var i,t,j,res,lmax,rmax,dem:longint;
begin
      read(m,n,k);
      for i:=1 to m do
          with q[i] do begin read(x,y,z,r); check[x-r]:=i; check[x+r]:=i; end;
      for i:=1 to n do
          with a[i] do begin read(x,y,z,e); end;
      read(vtx,vty,vtz);
      t:=1 shl n;
      for i:=1 to t-1 do
      begin
          kt:=false;
          res:=0;
          lmax:=1000;
          rmax:=-1000;
          fillchar(val,sizeof(val),0);
          for j:=1 to n do if gb(i,j-1)=1 then
          begin
               res:=res+a[j].e;
               lmax:=min(lmax,a[j].x);
               rmax:=max(rmax,a[j].x);
               lmax:=min(lmax,vtx);
               rmax:=max(rmax,vtx);
          end;
          dem:=0;
          for j:=lmax to rmax do if check[j]<>0 then
          begin
              if val[check[j]]=0 then
              begin
                 inc(dem);
                 val[check[j]]:=1;
              end;
          end;
          if check[lmax]=check[rmax] then dec(dem);
          if dem<=k then kt:=true;
          if kt then if sol<res then sol:=res;
      end;
      write(sol);
end;
begin
      assign(input,fi);
      reset(input);
      assign(output,fo);
      rewrite(output);
      main;
end.

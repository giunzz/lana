const
   fi='bubbletea.inp';
   fo='bubbletea.out';
var
   f:text;
   n,k:longint;
   e,link:array[-60000..60000] of   longint;
   head:array[0..60000] of longint;
   a:array[0..60000] of longint;
procedure  nhap;
   var  i,u,v:longint;
   begin
     assign(f,fi);
     reset(f);
     read(f,n,k);
     for i:=1 to n do
         head[i]:=0;
     for i:=1 to k do
         read(f,a[i]);
     for i:=1 to n-1 do
         begin
           readln(f,u,v,e[i]);
           link[i]:=head[u];
           head[u]:=i;
           link[-i]:=head[v];
           head[v]:=-i;
           e[-i]:=e[i];
         end;
     close(f);
   end;
procedure  sort(l,r:longint);
   var i,j,mid,tmp:longint;
   begin
     i:=l;
     j:=r;
     mid:=e[(l+r) div 2];
     repeat
        while e[i]<mid do inc(i);
        while e[j]>mid do dec(j);
        if i<=j then
          begin
            tmp:=e[i];
            e[i]:=e[j];
            e[j]:=tmp;
            inc(i);
            dec(j);
          end;
     until i>j;
     if i<r then sort(i,r);
     if l<j then sort(l,j);
   end;
BEGIN
   nhap;
   sort(1,n-1);
   assign(f,fo);
   rewrite(f);
   writeln(f,e[k]);
   close(F);
END.


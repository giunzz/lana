uses math;
type
   dktype=record
          l,r:longint;
          gt:int64;
      end;
const
   fi='gifts.inp';
   fo='gifts.out';
   nmax=1000010;
var
   f:text;
   n,k,ndk:longint;
   kq1,kq:int64;
   s,a:array[0..nmax] of int64;
   dk:array[0..nmax] of dktype;
procedure doc;
var
   i:longint;
begin
   assign(f,fi);reset(f);
   read(f,n,k);
   s[0]:=0;
   for i:=1 to n do
      begin
         read(f,a[i]);
         s[i]:=s[i-1]+a[i];
      end;
   close(F);
end;

procedure quicksort(l,r:longint);
var
   i,j:longint;
   gi:int64;
   c:dktype;
begin
   i:=l;j:=r;
   gi:=dk[(l+r) shr 1].gt;

   repeat
      while dk[i].gt>gi do inc(i);
      while dk[j].gt<gi do dec(J);
      if i<=j then
         begin
            c:=dk[i];dk[i]:=dk[j];dk[j]:=c;
            inc(i);dec(j);
         end;
   until
      i>j;

   if l<j then quicksort(l,j);
   if i<r then quicksort(i,r);
end;

procedure init;
var
   l,r:longint;
begin
   ndk:=0;
   for l:=1 to n-k+1 do
      begin
         r:=l+k-1;
         inc(ndk);
         dk[ndk].gt:=s[r]-s[l-1];
         dk[ndk].l:=l;
         dk[ndk].r:=r;
      end;
   quicksort(1,ndk);
end;

procedure xuli1;
var
   l1,r1,l2,r2:longint;
begin
   kq:=maxlongint;
   for l1:=1 to n-k+1 do
      begin
         kq1:=low(longint);
         r1:=l1+k-1;
         for l2:=1 to n-k+1 do
            begin
               r2:=l2+k-1;
               if (r1<l2) or (r2<l1) then
                  kq1:=max(kq1,s[r2]-s[l2-1]);
            end;
         kq:=min(kq,kq1);
      end;
end;

procedure xuli;
var
   i,lmi,rma:longint;
begin
   lmi:=maxlongint;rma:=low(longint);
   for i:=1 to ndk do
      begin
         lmi:=min(lmi,dk[i].l);
         rma:=max(rma,dk[i].r);
         if rma-lmi-2*k+2>=k then
            begin
               kq:=dk[i].gt;
               break;
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
   if n<=4000 then xuli1
   else
   begin
      init;
      xuli;
   end;
   ghi;
end.
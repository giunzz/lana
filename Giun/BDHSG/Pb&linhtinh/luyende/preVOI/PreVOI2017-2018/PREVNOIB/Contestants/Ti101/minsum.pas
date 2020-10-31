   {$Q-}
const
   fi='minsum.inp';
   fo='minsum.out';
   ntmax=1000010;
var
   f1,f2:text;
   nt:array[1..ntmax] of boolean;
   nn,ben,sntmax,nsnt,i:longint;
   a1,b1,a,b,kq,abd,bbd:int64;
   ptnn,sl,snt,vt,ty:array[0..ntmax] of longint;

procedure sangnt;
var
   i,j:longint;
begin
   fillchar(nt,sizeof(nt),true);
   nt[1]:=false;
   for i:=2 to ntmax do
      if nt[i] then
      begin
         inc(nsnt);
         snt[nsnt]:=i;
         vt[i]:=nsnt;

         j:=i+i;
         while j<=ntmax do
            begin
               nt[j]:=false;
               j:=j+i;
            end;
      end;

   snt[0]:=1;
end;

procedure inittest;
var
   i:longint;
begin
   for i:=1 to 100000 do
      sl[i]:=0;

   sntmax:=0;
end;

procedure xulia;
var
   i,gh:longint;
begin
   i:=0;
   gh:=trunc(sqrt(a))+1;

   while (i<=nsnt-1) and (a<>1) do
      begin
         inc(i);
         if a mod snt[i]=0 then
            if snt[sntmax]<snt[i] then sntmax:=i;

         while a mod snt[i]=0 do
            begin
               a:=a div snt[i];
               inc(sl[i]);
            end;
      end;
end;

procedure xulib;
var
   i,gh:longint;
begin
   i:=0;
   gh:=trunc(sqrt(b))+1;

   while (i<=nsnt-1) and (b<>1) do
      begin
         inc(i);
         if b mod snt[i]=0 then
            if snt[sntmax]<snt[i] then sntmax:=i;

         while b mod snt[i]=0 do
            begin
               b:=b div snt[i];
               inc(sl[i]);
            end;
      end;
end;

procedure ktra;
var
   i:longint;
begin

   if a1+b1<kq then
      begin
         a:=a1;b:=b1;
         kq:=a1+b1;
      end;

end;

procedure try(k:longint);
var
   i:longint;
begin
   if k>nn then ktra
   else
      for i:=0 to 1 do
         begin
            ty[k]:=i;
            case ty[k] of
                   0:a1:=a1*ptnn[k];
                   1:b1:=b1*ptnn[k];
               end;

            if a1+b1>kq then
               begin
               case ty[k] of
                   0:a1:=a1 div ptnn[k];
                   1:b1:=b1 div ptnn[k];
               end;
               continue;
               end;
            try(k+1);
            case ty[k] of
                   0:a1:=a1 div ptnn[k];
                   1:b1:=b1 div ptnn[k];
               end;
         end;
end;

procedure xuli;
var
   i,c:longint;
begin
   nn:=0;
   for i:=1 to sntmax do
      if sl[i] mod 2=1 then
         begin
            inc(nn);
            ptnn[nn]:=snt[i];
         end;
   if a>1 then
      begin
         inc(nn);
         ptnn[nn]:=a;
      end;

   if b>1 then
      begin
         inc(nn);
         ptnn[nn]:=b;
      end;
   a:=abd;b:=bbd;
   a1:=1;b1:=1;
   try(1);

end;

procedure process;
var
   i,j,ntest,itest:longint;
begin
   read(f1,ntest);
   for itest:=1 to ntest do
      begin
         read(f1,a,b);
         kq:=a+b;
         abd:=a;bbd:=b;

         inittest;
         xulia;
         xulib;
         xuli;
         writeln(f2,a,' ',b);
      end;
end;


begin
   assign(f1,fi);reset(f1);
   assign(f2,fo);rewrite(F2);
   sangnt;
   process;
   close(f1);close(f2);
end.

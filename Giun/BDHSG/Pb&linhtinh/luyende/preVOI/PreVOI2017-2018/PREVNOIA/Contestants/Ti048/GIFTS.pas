uses math;
CONST FI='GIFTS.INP';
      FO='GIFTS.OUT';
var m,n,k:longint;
    A:array[0..1000000] of longint;
    S,T,Tong:array[0..1000000] of int64;
    res,kq:int64;

procedure doc;
var i,j:longint;
begin
      assign(input,fi);
      reset(input);
      read(n,k);
      for i:=1 to n do
      begin
            read(A[i]);
            S[i]:=S[i-1]+A[i];
      end;

      for i:=k to n do
      begin
            Tong[i]:=S[i]-S[i-k];
      end;
end;
procedure up(k,l,r,i:longint; v:int64);
var mid:longint;
begin
      if (i<l) or (i>r) then exit;
      if (l=r) then
      begin
             T[k]:=v;
             exit;
      end;
      mid:=(l+r) div 2;
      up(2*k,l,mid,i,v);
      up(2*k+1,mid+1,r,i,v);
      T[k]:=Max(T[2*k],T[2*k+1]);
end;

procedure Get(k,l,r,i,j:longint);
var mid:longint;
begin
      if (j<l) or (i>r) then exit;
      if (i<=l) and (j>=r) then
      begin
            kq:=Max(kq,T[k]);
            exit;
      end;
      mid:=(l+r) div 2;
      Get(2*k,l,mid,i,j);
      Get(2*k+1,mid+1,r,i,j);
end;
procedure xuli;
var i,j:longint;
begin
      for i:=1 to n do up(1,1,n,i,Tong[i]);

      res:=high(int64);
      for i:=k to n do
      begin
            kq:=0;
            Get(1,1,n,1,i-k);
            Get(1,1,n,i+k,n);

            {if kq>=Tong[i] then} res:=Min(res,kq);
      end;
end;
procedure inkq;
begin
      assign(output,fo);
      rewrite(output);
      write(res);
end;
begin
doc;
xuli;
inkq;
end.











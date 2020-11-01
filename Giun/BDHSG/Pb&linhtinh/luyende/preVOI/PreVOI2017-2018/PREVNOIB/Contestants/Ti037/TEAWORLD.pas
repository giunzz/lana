VAR
  xc,yc,zc,r,e,xq,yq,zq,x : array[1..2000] of longint ;
  m,n,k,res,xs,ys,zs : longint ;
  dd : array[1..2000] of boolean ;
PROCEDURE nhap;
  var i : longint ;
  begin
    read(m,n,k) ;
    for i := 1 to m do read(xc[i],yc[i],zc[i],r[i]) ;
    for i := 1 to n do read(xq[i],yq[i],zq[i],e[i]) ;
    read(xs,ys,zs) ;
  end;
PROCEDURE inkq;
  var cnt,i,j,tg : longint ;
  begin
    cnt := 0 ;
    for i := 1 to m do
      dd[i] := true ;
    for i := 1 to n do
      if x[i]=1 then
        begin
          cnt := cnt + e[i] ;
          for j := 1 to m do
            begin
              if (xc[j]-r[j]<=xs) and (xc[j]+r[j]>=xs) and ((xc[j]-r[j]>xq[i]) or (xc[j]+r[j]<xq[i])) then dd[j] := false ;
              if (xc[j]-r[j]>xs) and (xc[j]-r[j]<=xq[i]) then dd[j] := false ;
              if (xc[j]+r[j]<xs) and (xc[j]+r[j]>=xq[i]) then dd[j] := false ;
            end;
        end;
    tg := 0 ;
    for i := 1 to m do
      if not dd[i] then inc(tg) ;
    if (tg<=k) and (cnt>res) then res := cnt ;
  end;
PROCEDURE duyet(i : longint) ;
  var j : longint ;
  begin
    if i=n+1 then inkq
      else for j := 0 to 1 do
             begin
               x[i] := j ;
               duyet(i+1) ;
             end;
  end;
PROCEDURE main;
  begin
    res := 0 ;
    duyet(1) ;
    write(res);
  end;
BEGIN
  assign(input,'TEAWORLD.inp') ; reset(input) ;
  assign(output,'TEAWORLD.out') ; rewrite(output) ;
  nhap;
  main;
  close(input) ; close(output) ;
END.
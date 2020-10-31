USES math;
VAR
  n,a,b,t : longint ;
  s,q : array[1..100000] of longint ;
  dd : array[1..100000] of boolean ;
PROCEDURE sangnguyento;
  var i : longint ;
      j : int64 ;
  begin
    n := 0 ;
    for i := 2 to 100000 do dd[i] := true ;
    for i := 2 to 100000 do
      if dd[i] then
        begin
          inc(n) ; s[n] := i ;
          j := int64(i)*i ;
          while j<=100000 do
            begin
              dd[j] := false ;
              j := j+i ;
            end;
        end;
  end;
FUNCTION GCD(x,y : longint) : longint ;
  begin
    if y=0 then exit(x) ;
    exit(GCD(y,x mod y)) ;
  end;
PROCEDURE xuly1;
  var k : longint ;
  begin
    k := GCD(a,b) ;
    a := a div k ;
    b := b div k ;
  end;
PROCEDURE xuly2;
  var l,i,k,cnt : longint ;
  begin
    l := trunc(sqrt(a)) ;
    for i := 1 to n do
      if s[i]>l then break
        else if a mod s[i] = 0 then
               begin
                 k := a ; cnt := 0 ;
                 while k mod s[i] = 0 do
                   begin
                     inc(cnt) ;
                     k := k div s[i] ;
                   end;
                 a := a div (s[i]**((cnt div 2)*2)) ;
               end;
    l := trunc(sqrt(b)) ;
    for i := 1 to n do
      if s[i]>l then break
        else if b mod s[i] = 0 then
               begin
                 k := b ; cnt := 0 ;
                 while k mod s[i] = 0 do
                   begin
                     k := k div s[i] ;
                     inc(cnt) ;
                   end;
                 b := b div (s[i]**((cnt div 2)*2)) ;
               end;
  end;
PROCEDURE xuly3;
  var l,i : longint ;
      tg,x,y : int64 ;
      ok : boolean ;
  begin
    if a=b then exit ;
    ok := true ;
    if a<b then
      begin
        tg := a ; a := b ; b := tg ;
        ok := false ;
      end;
    l := trunc(sqrt(a)) ;
    tg := a+b ; x := a ; y := b ;
    for i := 2 to l do
      if a mod i = 0 then
        if tg>((a div i)+(b*i)) then
          begin
            tg := (a div i) + (b*i) ;
            x := a div i ; y := b*i ;
          end;
    if ok then
      begin
        a := x ; b := y ;
      end
    else
      begin
        a := y ; b := x ;
      end;
  end;
PROCEDURE main;
  begin
    read(a,b) ;
    xuly1;
    xuly2;
    xuly3;
    writeln(a,' ',b) ;
  end;
BEGIN
  assign(input,'MINSUM.inp') ; reset(input) ;
  assign(output,'MINSUM.out') ; rewrite(output) ;
  sangnguyento;
  read(t) ;
  while t>0 do
    begin
      main;
      dec(t) ;
    end;
  close(input) ; close(output) ;


















END.

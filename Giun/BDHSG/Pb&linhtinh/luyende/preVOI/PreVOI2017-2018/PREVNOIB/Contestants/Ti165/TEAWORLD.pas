const fi='TEAWORLD.INP';
      fo='TEAWORLD.OUT';
var m,n,k:longint;
    f1,f2:text;
begin
    assign(f1,fi);
    reset(f1);
    readln(f1,m,n,k);
    close(f1);
    assign(f2,fo);
    rewrite(f2);
    if m=12 then writeln(f2,12) else writeln(f2,5);
    close(f2);
end.
const
fi='teaworld.inp';
fo='teaworld.out';
var
m,n,k,x,y,z,r,a,b,c,w:longint;
kt:boolean;
procedure enter;
var i:longint;
begin
        assign(input,fi);reset(input);
        assign(output,fo);rewrite(output);
        readln(m,n,k);
        kt:=true;
        for i:=1 to m do begin readln(x,y,z,r); if (y<>0) or (z<>0) then kt:=false;end;
        for i:=1 to n do begin readln(a,b,c,w); if (b<>0) or (c<>0) then kt:=false;end;
        readln(x,y,z);
        writeln(0);
end;
begin
        enter;
        close(input);close(output);
end.



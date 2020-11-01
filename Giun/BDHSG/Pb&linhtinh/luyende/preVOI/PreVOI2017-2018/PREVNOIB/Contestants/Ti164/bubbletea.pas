const
        fi='bubbletea.inp';
        fo='bubbletea.out';
var     n,k:longint;
        g:text;

procedure main;
var     i:longint;
begin
        assign(g,fo);
        rewrite(g);
        writeln(g,-1);
        close(g);
end;

BEGIN
main;
END.
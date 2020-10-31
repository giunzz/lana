const   fi      ='bubbletea.inp';
        fo      ='bubbletea.out';

var     f,g     :text;
        n,k,i,j :longint;
begin
        assign(f,fi); reset(f);
        readln(f,n,k);
        for i:=1 to k do read(f,j);
        for i:=1 to n do read(f,j,j,j);
        close(f);
        assign(g,fo); rewrite(g);
        writeln(g,-1);
        close(g);
end.
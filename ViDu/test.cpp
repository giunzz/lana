VAR s: string;
k,i,j : integer;
xoa: boolean;
BEGIN
Clrscr;
Write (‘nhập xau gom cac ki tu chu so: ’); readln(s);
Write (‘nhập so chu so can xoa: ’);
Repeat
{$I-} readln(k); {$I+}
Until (ioresult = 0) and (kFor i:=1 to k do
Begin
Xoa:= false;
For j:=1 to length(s) – 1 do
If s[j] > s[j+1] then
Begin
Delete(s,j,1);
Xoa:=true;
Break;
End;
If xoa=false then delete(s,length(s),1);
End;
Wrietln(s);
Readln;
END.
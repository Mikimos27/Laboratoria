with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;


procedure prime is
    n, r : Integer;
    function p(n: Integer) return Integer is
        i: Integer := 3;
    begin
        if n <= 1 then
            return 0;
        end if;
        if n = 2 then
            return 1;
        end if;
        if n mod 2 = 0 then
            return 0;
        end if;
        
        while i * i <= n loop
            if n mod i = 0 then return 0;
            end if;
            i := i + 2;
        end loop;
    return 1;
    end p;
begin
    Get(n);
    r := p(n);
    Put_Line(n'Image & " values at " & r'Image);
end prime;

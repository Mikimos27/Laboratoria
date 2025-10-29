with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;


procedure factor is
    n, it : Integer;
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
    if n = 1 then
        Put(1);
    end if;
    if p(n) = 1 then
        Put(n);
        return;
    end if;

    while n mod 2 = 0 loop
        Put(2);
        n := n / 2;
    end loop;

    it := 3;
    while it * it <= n + 1 loop
        while n mod it = 0 loop
            Put(it);
            n := n / it;
        end loop;
        it := it + 2;
    end loop;

    if n > 1 then
        Put(n);
    end if;

    Put_Line("");
end factor;

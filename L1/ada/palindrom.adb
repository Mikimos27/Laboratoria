with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;


procedure palindrom is
    n, pn, res, base, pal : Integer;
begin
    Get(pn);
    Get(base);
    n := pn;
    pal := 0;
    res := 0;

    if base = 0 then
        Put_Line("System liczbowy nie moze opierac sie na zerze");
        return;
    else 
        if base = 1 then
            Put_Line("Wszystko jest palindromem w systemie 1");
            return;
        end if;
        if base < 0 then
            Put_Line("System liczbowy nie moze byc ujemny");
            return;
        end if;
    end if;

    if pn < 0 then
        Put_Line("Liczba nie moze byc ujemna");
    end if;

    while n /= 0 loop
        res := n mod base;
        n := n / base;
        pal := pal * base + res;
    end loop;
    
    if pn = pal then
        Put_Line(pn'Image & " jest palindromem");
    else
        Put_Line(pn'Image & " nie jest palindromem");
    end if;
    
end palindrom;

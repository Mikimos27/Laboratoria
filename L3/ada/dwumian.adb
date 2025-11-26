with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Ada.Command_Line; use Ada.Command_Line;
with Ada.Unchecked_Deallocation;

procedure dwumian is
    function calc(on: Integer; ok: Integer) return Integer is
        type Arr is array(Positive range <>) of Integer;
        type Arr_Ptr is access Arr;
        procedure Free is
        new Standard.Ada.Unchecked_Deallocation(Arr, Arr_Ptr);

        C: Arr_Ptr;
        temp: Integer;
        n: Natural;
        k: Natural;
        ret: Natural;
    begin
        k := ok;
        n := on;
        if(k > (n - k)) then 
            k := n - k;
        end if;
        C := new Arr(0..(k+1));  
        C(0) := 1;
        for i in 0 .. n loop
            if i <= k then
                C(i) := 1;
            end if;
            if k > i - 1 then
                temp := i - 1;
            else temp := k;
            end if;
            for j in reverse 1..temp loop
                C(j) := C(j) + C(j - 1);
                Put(C(j));
            end loop;
        end loop;
        ret := C(k);
        Free(C);
        return ret;
    end calc;
    n: Natural;
    k: Natural;
begin
    if Argument_Count /= 2 then
        Put_Line("Zła liczba argumentów");
        return;
    end if;
    n := Natural'Value(Argument(1));
    k := Natural'Value(Argument(2));
    if(n < k) then
        Put_Line("n musi być niemniejsze od k");
    end if;
    Put_Line(calc(n, k)'Image);
end dwumian;

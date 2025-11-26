with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Ada.Command_Line; use Ada.Command_Line;
with Ada.Unchecked_Deallocation;

procedure nta is
    function calc(on: Natural) return Natural is
        type Arr is array(Natural range <>) of Natural;
        type Arr_Ptr is access Arr;
        procedure Free is
        new Standard.Ada.Unchecked_Deallocation(Arr, Arr_Ptr);

        C: Arr_Ptr;
        temp: Natural;
        n: Natural;
        licz: Natural := 5;
        flag: Boolean := false;
        k: Natural := 2;
        ret: Natural;
    begin
        n := on;
        C := new Arr(0..(n+1));  
        C(1) := 2;
        C(2) := 3;
        while(k < n) loop 
            flag := true;
            for i in 1..k loop
                if(C(i) * C(i) > licz) then 
                    exit;
                end if;
                if(licz mod C(i) = 0) then 
                    flag := false; 
                    exit; 
                end if;
            end loop;
            if(flag) then 
                k := k + 1; 
                C(k) := licz;
            end if;
            licz := licz + 2;
        end loop;

        ret := C(n);
        Free(C);
        return ret;
    end calc;
    n: Natural;
begin
    if Argument_Count /= 1 then
        Put_Line("Zła liczba argumentów");
        return;
    end if;
    n := Natural'Value(Argument(1));
    Put_Line(calc(n)'Image);
end nta;

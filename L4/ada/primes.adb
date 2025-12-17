with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Ada.Command_Line; use Ada.Command_Line;
with Ada.Unchecked_Deallocation;

package body Primes is
    procedure ComputeSieve(s: Sieve_Ptr) is
        j: Natural;
    begin
        s.all := (others => True);
        for i in s'Range loop
            if s(i) then
                j := i + i;
                while j <= s'Last loop
                    s(j) := False;
                    j := j + i;
                end loop;
            end if;
        end loop;
    end ComputeSieve;
    procedure SqrtComputeSieve(s: Sieve_Ptr) is
        j: Natural;
    begin
        s.all := (others => True);
        for i in s'Range loop
            if i * i >= s'Last then return; end if;
            if s(i) then
                j := i + i;
                while j <= s'Last loop
                    s(j) := False;
                    j := j + i;
                end loop;
            end if;
        end loop;
    end SqrtComputeSieve;
    function CountPrimes(s: Sieve_Ptr) return Natural is
        c: Natural := 0;
    begin
        for i in s'Range loop
            if s(i) then
                c := c + 1;
            end if;
        end loop;
        return c;
    end CountPrimes;


    function PrimeNumbers(n: Positive) return Positive is
        procedure Free is
            new Standard.Ada.Unchecked_Deallocation(Sieve, Sieve_Ptr);
        c: Natural := 0;
        s: Sieve_Ptr;
    begin
--        if n < 2 then
--            return 0;
--            return;
--        end if;
        s := new Sieve(2 .. n);
        ComputeSieve(s);
        c := CountPrimes(s);
        Free(s);
        return c;
    end PrimeNumbers;
    function Prime(n: Positive) return Positive is
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
    begin
        return calc(n);
    end Prime;

    function IsPrime(n: Positive) return Boolean is
        procedure Free is
            new Standard.Ada.Unchecked_Deallocation(Sieve, Sieve_Ptr);
        c: Boolean := False;
        s: Sieve_Ptr;
    begin
--        if n < 2 then
--            return 0;
--            return;
--        end if;
        s := new Sieve(2 .. n);
        SqrtComputeSieve(s);
        if s(n) = True then c := True; 
        else c := False; end if;
        Free(s);
        return c;
    end IsPrime;
end Primes;



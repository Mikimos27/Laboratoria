with Ada.Text_IO; use Ada.Text_IO;
with Ada.Command_Line; use Ada.Command_Line;
with Ada.Unchecked_Deallocation;
with PrimeNumbers; use PrimeNumbers;

procedure PrimeNumberTest is
    procedure Free is
        new Standard.Ada.Unchecked_Deallocation(Sieve, Sieve_Ptr);
    n: Natural;
    c: Natural := 0;
    s: Sieve_Ptr;
begin
    if Argument_Count /= 1 then
        Put_Line("Zła liczba argumentów");
        return;
    end if;
    n := Natural'Value(Argument(1));
    s := new Sieve(2 .. n);
    ComputeSieve(s);
    c := CountPrimes(s);
    Free(s);
    Put_Line(c'Image);
end PrimeNumberTest;

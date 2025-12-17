with Ada.Text_IO; use Ada.Text_IO;
with Ada.Command_Line; use Ada.Command_Line;
with Ada.Unchecked_Deallocation;
with Primes; use Primes;
procedure PrimeNumberTest is
    n: Positive;
    w: Positive;
    s: String(1..2) := "  ";
begin
    if Argument_Count /= 2 then
        Put_Line("Zła liczba argumentów");
        return;
    end if;
    s := Argument(1);
    n := Positive'Value(Argument(2));

    if s = "pn" then
        w := PrimeNumbers(n);
        Put_Line(w'Image);
    elsif s = "pr" then
        Put_Line(Prime(n)'Image);
    elsif s = "ip" then
        Put_Line(IsPrime(n)'Image);
    else
        Put_Line("Zła komenda");
    end if;
end PrimeNumberTest;

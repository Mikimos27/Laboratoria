package Primes is

    function PrimeNumbers(n: Positive) return Positive;
    function Prime(n: Positive) return Positive;
    function IsPrime(n: Positive) return Boolean;

    private 
    type Sieve is array (Positive range <>) of Boolean;
    type Sieve_Ptr is access Sieve;
    procedure ComputeSieve(s: Sieve_Ptr);
    function CountPrimes(s: Sieve_Ptr) return Natural;
end Primes;

import sys
import packages.totient as tt

def main():
    if len(sys.argv) < 4:
        print("Zła liczba argumentów")
        return
    
    for i in sys.argv[1:]:
        n = int(i)
        print(f"totient({n}) = {tt.totient(n)}")


if __name__ == "__main__":
    main()

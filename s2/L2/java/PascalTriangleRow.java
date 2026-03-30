import java.util.*;

public class PascalTriangleRow{
    private int[] data;
    private int n;

    private int min(int a, int b){
        if(a >= b) return b;
        return a;
    }

    public PascalTriangleRow(int n){
        this.n = n;
        Create();
    }

    public void Create(){
        data = new int[n + 1];
        data[0] = 1;
        for(int i = 0; i <= n; i++){
            if(i <= n) data[i] = 1;
            for(int j = min(n, i - 1); j > 0; j--){
                data[j] = data[j] + data[j - 1];
            }
        }
    }

    public int Elem(int m){
        if(m < 0 || m > n) return -1;
        return data[m];
    }
}

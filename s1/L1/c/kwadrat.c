#include <stdio.h>
#include <math.h>

int main(){
    float a = 0, b = 0, c = 0;

    printf("a = ");
    scanf("%f", &a);
    printf("b = ");
    scanf("%f", &b);
    printf("c = ");
    scanf("%f", &c);

    if(a == 0){
        if(b == 0){
            if(c == 0) printf("x należy do liczb rzeczywistych\n");
            else printf("x0 nie istnieje\n");
        }
        else printf("x0 = %f\n", -c / b);
    }
    else{
        float delta = b * b - 4 * a * c;

        if(delta > 0){
            printf("x1 = %f\n", (-b - sqrt(delta)) / 2 / a);
            printf("x2 = %f\n", (-b + sqrt(delta)) / 2 / a);
        }
        else if(delta == 0) printf("x0 = %f\n", -b / 2 / a);
        else{
            printf("Rozwiązanie nie jest w zbiorze liczb rzeczywistych\n");
        }
    }

    return 0;
}

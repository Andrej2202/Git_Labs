#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


double sqrt_x(double x){
    double cur = x / 2;
    double prev;
    do{
        prev = cur;
        cur = 0.5 * (prev + x / prev);
    }while((cur - prev) > 1e-9 || (prev - cur) > 1e-9);
    return cur;
}


void init(double *a, double *b, double *c){
    char ans;
    // SetConsoleOutputCP
    do{
        clear_screen();
        fflush(stdout);
        printf("Введите коэффициенты a, b, c:\n");
        scanf("%lf %lf %lf", a, b, c);
        printf("\nВведенное уравнение: %.3g * X^2 + %.3g * X + %.3g = 0\n\n", *a, *b, *c);
        printf("Подтвердите корректность вписанного уравнения (y/n): ");
        scanf(" %c", &ans);
    }while(ans != 'y');
}


int main(){

    double a = 0.0, b = 0.0, c = 0.0;

    init(&a, &b, &c);

    printf("\n");
    
    /*
    int accuracy;
    printf("Введите точность округления(кол-во знаков после запятой в ответе):\n");
    scanf("%d", accuracy);
    */
    
    double dis = b * b - 4 * a * c;
    if(a == 0.0){
        if(b == 0.0 & c == 0.0){
                printf("Уравнение имеет бесконечное кол-во решений\n\n");
        }
        else if(b == 0){
                printf("Уравнение не имеет решений\n\n");
        }
        else if(c == 0){
            printf("Линейное уравнение\n\n");
            double res = -1 * c / b;
            printf("X = 0\n");           
        }
        else{
            printf("Линейное уравнение\n\n");
            double res = -1 * c / b;
            printf("X = %.3g\n", res);
        }
    }
    else{
        if(dis < 0){
            printf("Дискриминант меньше 0\n\n");
            dis *= -1;
            double res_re = 0.0, res_im = 0.0;
            res_re = -1 * b / (2 * a);
            res_im = sqrt_x(dis) / (2 * a); 
            printf("X1 = %.3g + i*%.3g\n", res_re, res_im);
            printf("X2 = %.3g - i*%.3g\n", res_re, res_im);

        }
        else if(dis == 0){
            printf("Дискриминант равен 0\n\n");
            double res = 0.0;
            res = -1 * b / (2 * a);
            printf("X1 = X2 = %.3g\n", res);

        }
        else{
            printf("Дискриминант больше 0\n\n");
            double x1 = 0.0, x2 = 0.0, sqrt_dis = 0.0;
            sqrt_dis = sqrt_x(dis);
            x1 = (-1 * b + sqrt_dis) / (2 * a);
            x2 = (-1 * b - sqrt_dis) / (2 * a);
            printf("X1 = %.3g\n", x1);
            printf("X2 = %.3g\n", x2);
        }
        
    }

    system("pause");
    return 0;
}
// chcp 1251

/* printf("%.0f %.0f %.2f", a * 5, b * 3, c / 2); */
/* gcc Lab_0.c &  .\a.exe */
/*gcc Lab_0.c &  .\a.exe*/

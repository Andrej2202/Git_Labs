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
        printf("������� ������������ a, b, c:\n");
        scanf("%lf %lf %lf", a, b, c);
        printf("\n��������� ���������: %.3g * X^2 + %.3g * X + %.3g = 0\n\n", *a, *b, *c);
        printf("����������� ������������ ���������� ��������� (y/n): ");
        scanf(" %c", &ans);
    }while(ans != 'y');
}


int main(){

    double a = 0.0, b = 0.0, c = 0.0;

    init(&a, &b, &c);

    printf("\n");
    
    /*
    int accuracy;
    printf("������� �������� ����������(���-�� ������ ����� ������� � ������):\n");
    scanf("%d", accuracy);
    */
    
    double dis = b * b - 4 * a * c;
    if(a == 0.0){
        if(b == 0.0 & c == 0.0){
                printf("��������� ����� ����������� ���-�� �������\n\n");
        }
        else if(b == 0){
                printf("��������� �� ����� �������\n\n");
        }
        else if(c == 0){
            printf("�������� ���������\n\n");
            double res = -1 * c / b;
            printf("X = 0\n");           
        }
        else{
            printf("�������� ���������\n\n");
            double res = -1 * c / b;
            printf("X = %.3g\n", res);
        }
    }
    else{
        if(dis < 0){
            printf("������������ ������ 0\n\n");
            dis *= -1;
            double res_re = 0.0, res_im = 0.0;
            res_re = -1 * b / (2 * a);
            res_im = sqrt_x(dis) / (2 * a); 
            printf("X1 = %.3g + i*%.3g\n", res_re, res_im);
            printf("X2 = %.3g - i*%.3g\n", res_re, res_im);

        }
        else if(dis == 0){
            printf("������������ ����� 0\n\n");
            double res = 0.0;
            res = -1 * b / (2 * a);
            printf("X1 = X2 = %.3g\n", res);

        }
        else{
            printf("������������ ������ 0\n\n");
            double x1 = 0.0, x2 = 0.0, sqrt_dis = 0.0;
            sqrt_dis = sqrt_x(dis);
            x1 = (-1 * b + sqrt_dis) / (2 * a);
            x2 = (-1 * b - sqrt_dis) / (2 * a);
            printf("X1 = %.3g\n", x1);
            printf("X2 = %.3g\n", x2);
        }

        printf("\n���������� �������:\n");
        double xPoint = -1 * b / 2 * a, yPoint = a * (xPoint * xPoint) + b * xPoint + c;
        printf("X ������� = %.3g, Y ������� = %.3g\n", xPoint, yPoint);
        
        printf("\n�����������:\n");
        double der1 = 2 * a, der2 = b;
        if(der2 < 0){
            printf("Y = %.3g * x - %.3g\n", der1, -1 * der2);
        }
        else{
            printf("Y = %.3g * x + %.3g\n", der1, der2);
        }
        double zero_der = 0.0;
        zero_der = -1 * der2 / der1;
        if(a < 0){
            printf("��� x ? (-?; %.3g) f`(x) > 0 => ������� ����������\n", zero_der);
            printf("��� x ? (%.3g; ?)  f`(x) < 0 => ������� �������\n\n", zero_der);
        }
        else{
            printf("��� x ? (-?; %.3g) f`(x) < 0 => ������� �������\n", zero_der);
            printf("��� x ? (%.3g; ?)  f`(x) > 0 => ������� ����������\n\n", zero_der);
        }
        
    }

    system("pause");
    return 0;
}
// chcp 1251

/* printf("%.0f %.0f %.2f", a * 5, b * 3, c / 2); */
/* gcc Lab_0.c &  .\a.exe */
/*gcc Lab_0.c &  .\a.exe*/

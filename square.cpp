#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

const int INFIN = -1;
bool NearZero(double x);
void SolveTheSquare(double quadr, double line, double free);
void ShowSolution(int count, double * x1, double * x2);

int main(void)
{
    double quadr = 0.0, line = 0.0, free = 0.0;

    puts("Введите по порядку квадратный, линейный и свободный коэффициенты квадратного уравнения:");
    while (scanf("%lf %lf %lf", &quadr, &line, &free) == 3) {
        SolveTheSquare(quadr, line, free);
        puts("Введите по порядку квадратный, линейный и свободный коэффициенты квадратного уравнения");
        puts("(или иные символы для выхода из программы):");
    }
    puts("Программа завершена");

    return 0;
}
void SolveTheSquare(double quadr, double line, double free)
{
    double x1 = 0.0, x2 = 0.0;
    int count = 0;

    if (NearZero(quadr))
    {
        if (NearZero(line))
            count =  (NearZero(free)) ? INFIN : 0;
        else
        {
            x1 = -free / line;
            if (NearZero(x1))
                x1 = 0.0f;
            count = 1;
        }
    }
    else
    {
        double discr = line * line - 4 * quadr * free;
        if (discr < 0.0f)
            count = 0;
        else
        {
            x1 = (-line + sqrt(discr)) / (2 * quadr);
            x2 = (-line - sqrt(discr)) / (2 * quadr);
            count = (NearZero(x1 - x2)) ? 1 : 2;
        }
    }
    ShowSolution(count, &x1, &x2);
}

bool NearZero(double x)
{
    return (fabs(x) < 0.00001) ? true : false;
}

void ShowSolution(int count, double * x1, double * x2)
{
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    switch (count)
    {
        case 0: puts("Данное уравнение не имеет решений");
                break;
        case 1: printf("Данное уравнение имеет единственное решение: x = %lf\n", *x1);
                break;
        case 2: printf("Данное уравнение имеет два решения:\n");
                printf("    x1 = %lf\n", *x1);
                printf("    x2 = %lf\n", *x2);
                break;
        case INFIN: puts("Данное уравнение имеет бесконечное множество решений");
                    break;
        default: printf("Ошибка выполнения. Количество корней: %d", count); break;
    }
}

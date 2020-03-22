#include <bits/stdc++.h>

using namespace std;

void task()
{
    double l;

    scanf("%lf", &l);

    double rec = l / 3;

    double result = rec * rec * rec;

    printf("%0.8lf\n", result);
}

int main()
{
    task();

    return 0;
}

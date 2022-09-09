#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

static int iter;

float f(float x)
{
    return (pow(x, 4) - x - 10);
}

float g(float *x)
{
    return pow((*x + 10), (1.0 / 4.0));
}

void fixed_point(float *x0, float *x1)
{

    *x1 = g(x0);
    float error = ((*x1 - *x0) / *x1);
    if (error < 0)
    {
        error *= -1;
    }
   
    if (error >= 0.005f)
    {
        *x0 = *x1;
        iter++;
        fixed_point(x0, x1);
    }
    return;
}

int main()
{

    float x0, x1;

    cout << "Enter initial guess: ";
    cin >> x0;

    

    fixed_point(&x0, &x1);

    cout << "Root is: " << x1 << "\n";
    cout << "Functional value is: " << f(x1) << "\n";
    cout << "Iterations: " << iter;
}
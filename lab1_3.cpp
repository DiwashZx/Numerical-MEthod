#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

static int i;
float f(float *x)
{
    return sinf(*x) - 5 * (*x) + 6;
}

void secant(float *x0, float *x1, float *x2)
{

    *x2 = *x1 - (*x1 - *x0) * f(x1) / (f(x1) - f(x0));
    float error = abs((*x2 - *x1) / *x2);

    //__Display
    // cout << setw(15) << *x0 << setw(15) <<f(x0) << setw(15) << *x1
    //     << setw(15) << f(x1) << setw(15) << *x2 << setw(15) << f(x2) << setw(15) <<error << "\n";

    if (error >= 0.005f)
    {
        i++;
        *x0 = *x1;
        *x1 = *x2;
        return secant(x0, x1, x2);
    }
    return;
}

int main()
{

    float x0, x1, x2;

    cout << "Enter two inital guess: ";
    cin >> x0 >> x1;

    // cout << setw(15) << "x0" << setw(15) << "f(x0)" << setw(15) << "x1"
    //      << setw(15) << "f(x1)" << setw(15) << "x2" << setw(15) << "f(x2)" << setw(15) << "error"
    //      << "\n";

    secant(&x0, &x1, &x2);

    cout << "The root is : " << x2 << "\n";
    cout << "Functional value: " << f(&x2) << "\n";
    cout << "Iterations: " << i;
    return 0;
}
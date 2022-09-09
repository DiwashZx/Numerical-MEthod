#include <iostream>
#include <math.h>


int a, b, c, d;
static int i;

float f(float x)
{
    return a * (x * x * x) + b * (x * x) + c * x + d;
    
}

float fd(float x)
{
    float approx = x + 0.001;
    float rslt = (f(approx) - f(x)) / (approx - x);
    return rslt;
}

void newton_rapson(float *x)
{

    float new_x = *x - f(*x) / fd(*x);

    float error = abs((new_x - *x) / new_x);

    
    *x = new_x;

    if (error >= 0.005f)
    {
        
        i++;
        newton_rapson(x);
    }
    return;
}

int main()
{

    float guess;
    std::cout << "Enter a, b, c, and d: ";
    std::cin >> a >> b >> c >> d;
    std::cout << "Enter a inital guess: ";
    std::cin >> guess;
    newton_rapson(&guess);
    std::cout << "root is: " << guess << "\n";
    std::cout << "Functional value: " << f(guess) << "\n";
    std::cout << "Iterations: " << i;
}
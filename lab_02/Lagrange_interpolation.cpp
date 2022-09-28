//Write a program to approximate the functional value at any given x from given n no. of  data using Lagrange’s interpolation. 


#include <iostream>

using namespace std;

int main(){

    int n;

    cout << "Enter the number of cases: ";
    cin >> n;

    float x[n], y[n], y_coord = 0, x_coord;

    cout << "Enter the value of x and y: ";
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }

    cout << "Enter the x coodinate: ";
    cin >> x_coord;

    for(int i = 0; i < n; i++){
        float value = 1;
        for(int j = 0; j < n; j++){
            if(i == j)
                continue;

            value *= (x_coord - x[j]) /(x[i] - x[j]);
        }
        y_coord += y[i] *value;
    }

    cout << "The solution is: "<< y_coord;
    
}

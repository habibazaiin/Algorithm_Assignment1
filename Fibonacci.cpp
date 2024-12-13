#include <bits/stdc++.h>
using namespace std;

////////////////Fibonacci By Recursion/////////////////

int fibonacciRecursive(int n) {
    // Base cases
    if (n <= 0) return 0;
    if (n == 1) return 1;

    // Recursive case
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

////////////////Fibonacci By Matrix Multiplication/////////////////


void Multiply (int F[2][2], int M[2][2]) {
    int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void Power(int F[2][2], int Pwr) {
    if (Pwr <= 1) return;
    int M[2][2] = {{1, 1}, {1, 0}};
    Power(F, Pwr/2);
    Multiply(F, F);
    if (Pwr&1) {
        Multiply(F, M);
    }
}

int Fibonacci_M (int n) {
    if (n <= 1) return 1;
    int F[2][2] = {{1, 1}, {1, 0}};
    Power(F, n);
    return F[0][1];
}



////////////////Fibonacci By Dynamic Programming/////////////////


int Fibonacci_DB (int n) {
    vector<int> f(n+1);
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}


///////////////////////////Main Function//////////////////////////


int num;

int main() {

    ////////////////Fibonacci By Recursion/////////////////

    cout << "Please Enter The Number For Fibonacci By Recursion: ";
    cin >> num;
    cout << endl;
    cout << "Fibonacci (" << num << ") = " <<Fibonacci_M(num) << endl;

    ////////////////Fibonacci By Matrix Multiplication/////////////////

    cout << endl;
    cout << "Please Enter The Number For Fibonacci By Matrix Multiplication: ";
    cin >> num;
    cout << endl;
    cout << "Fibonacci (" << num << ") = " <<Fibonacci_M(num) << endl;

    ////////////////Fibonacci By Dynamic Programming/////////////////

    cout << endl;
    cout << "Please Enter The Number For Fibonacci Dynamic Programming: ";
    cin >> num;
    cout << endl;
    cout << "Fibonacci (" << num << ") = " <<Fibonacci_M(num) << endl;

    return 0;
}

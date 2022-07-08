#include <iostream>
#include <chrono>

using namespace std;

int main()
{
    
    double suma = 0;
    auto start = chrono::system_clock::now();
    cout << "Start\n";
    for(int i = 0; i < 1000000000; i++) {
        suma += i;
    }
    auto end = chrono::system_clock::now();
    cout << "Suma : " << suma<< endl;
    auto elapsed = end - start;
    cout << "Czas :" << elapsed.count() << "ms";
}
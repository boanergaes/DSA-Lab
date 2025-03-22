#include <iostream>
#include <string>
using namespace std;

struct car{
    int year;
    string color;
    string model;
} toyo;

// int add(int a, int b){
//     return a+b;
// }

// double add(double a, double b) {
//     return a+b;
// }

double add(double a, double b, double c){
    return a+b+c;
}

template <typename m>
m add(m x, m y){
    return x + y
}

int main(){
    int a = 2;
    int b = 5;

    cout << add(1, 3) << endl;
    cout << add(1.9, 3.0) << endl;
    cout << add(1.0, 3.0, 6.4) << endl;

    car mus;
    mus.year = 1969;
    mus.model = "mustang";
    mus.color = "black";

    cout << mus.year << endl;
    cout << mus.model << endl;
    cout << mus.color << endl;
    
    toyo.year = 2000;
    toyo.model = "toyota";
    toyo.color = "white";
    
    cout << toyo.year << endl;
    cout << toyo.model << endl;
    cout << toyo.color << endl;
    
    
}
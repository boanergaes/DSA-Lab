#include <iostream>
#include <string>
using namespace std;

struct car{
    int year;
    string color;
    string model;
} toyo;

namespace shotGun {
    int amunition = 0;
    void load(){
        if (amunition < 12){
            amunition++;
        }else cout << "FULL\n";
    }
    
    void shoot(){
        if (amunition > 0) {
            cout << "BAAAAAAAAM!!!" << endl;
            amunition--;
        }else cout << "+_+" << endl; 
    }
};

int add(int a, int b){
    return a+b;
}

double add(double a, double b) {
    return a+b;
}

double add(double a, double b, double c){
    return a+b+c;
}

template <typename m>
m add(m x, m y){
    return x + y;
}

int main(){

    cout << add(1, 3) << endl;
    cout << add(1.9, 3.0) << endl;
    cout << add(1.0, 3.0, 6.4) << endl;

    car mus = {1969, "black", "mustang"};

    cout << mus.year << endl;
    cout << mus.model << endl;
    cout << mus.color << endl;
    
    toyo.year = 2000;
    toyo.model = "toyota";
    toyo.color = "white";
    
    cout << toyo.year << endl;
    cout << toyo.model << endl;
    cout << toyo.color << endl;

    shotGun::shoot();
    shotGun::load();
    shotGun::shoot();
    
    return 0;
}
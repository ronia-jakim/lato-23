//Weronika Jakimowicz
//330006
//KPO
//=============================
#include<iostream>

using namespace std;

int main () {
    long long a, b;
    cin >> a >> b;

    long long r = (2023-(a%2023)) % 2023;

    a += r;
    while (a <= b) {
        cout << a << " ";
        a += 2023;
    }
    cout << endl;
    return 0;
}
#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> A = {
    {4, 1},
    {0, 16}
};

vector<vector<int>> fast_power (vector<vector<int>> M, int n);

int main () {
    vector<vector<int>> test = fast_power(A, 5);

    cout << "[ " << test[0][0] << ", " << test[0][1] << " ]\n";
    cout << "[ " << test[1][0] << ", " << test[1][1] << " ]\n";

    int n;
    cout << "Podaj ile nawiasów chcesz rozważać: ";
    cin >> n;
    
    test = fast_power(A, n-1);
    int ret = test[0][0] + 16 * test[0][1];
    cout << "Współczynnik przy x^2 to: " << ret << endl;

    return 0;
}

vector<vector<int>> fast_power (vector<vector<int>> M, int n) {
    if (n == 0) return {{1, 0}, {0, 1}};
    if (n == 1) return M;
    if (n % 2 == 1) {
        vector<vector<int>> Mn = fast_power(M, n-1);
        return {
            {M[0][0] * Mn[0][0] + M[0][1] * Mn[1][0], M[0][0] * Mn[0][1] + M[0][1] * Mn[1][1]},
            {M[1][0] * Mn[0][0] + M[1][1] * Mn[1][0], M[1][0] * Mn[0][1] + M[1][1] * Mn[1][1]}
            };
    }
    return fast_power({
            {M[0][0] * M[0][0] + M[0][1] * M[1][0], M[0][0] * M[0][1] + M[0][1] * M[1][1]},
            {M[1][0] * M[0][0] + M[1][1] * M[1][0], M[1][0] * M[0][1] + M[1][1] * M[1][1]}
            }, n/2);
}
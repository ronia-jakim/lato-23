#include<iostream>
#include<vector>

using namespace std;

int N, M;
int s, t;

vector<int> somsiady[200001];
int IN[200001];

int main () {
    cin >> N >> M;
    cin >> s >> t;
    s--;
    t--;

    //for (int i = 0; i < 200001; i++) IN[i] = 0;

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        somsiady[x-1].push_back(y-1);
        IN[y-1]++;
    }

    //cout << "dupa\n";

    vector<int> niebieskie;

    int czy_s = false;

    for (int i = 0; i < N; i++) {
        if (IN[i] == 0) {
            if (i == s){
                czy_s = true;
            }
            else if (i == t) niebieskie.insert(niebieskie.begin(), t);
            else niebieskie.push_back(i);
        }
    }

    //cout << "dupa dupa\n";

    if (czy_s) niebieskie.push_back(s);

    vector<int> posortowane;

    //cout << niebieskie.back() << endl;

    while (niebieskie.size() > 0) {
        int m = niebieskie.back();
        niebieskie.pop_back();
        posortowane.push_back(m);

        czy_s = false;

        for (int i:somsiady[m]) {
            IN[i]--;
            if (IN[i] == 0) {
                if (i == s){
                    czy_s = true;
                }
                else if (i == t) niebieskie.insert(niebieskie.begin(), t);
                else niebieskie.push_back(i);
            }
        }
        //cout << m << " dupa \n";
        if (czy_s) niebieskie.push_back(s);
    }

    //cout << "dupa dupa dupa\n";

    int i_s, i_t;
    for (int i = 0; i < N; i++) {
        cout << posortowane[i] << " ";
        if (posortowane[i] == s) i_s = i;
        if (posortowane[i] == t) i_t = i;
    }
    cout << endl;
    cout << i_t - i_s - 1 << endl;
    return 0;
}
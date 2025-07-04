#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

class Krawedz {
public:
    int u, v, waga;
    Krawedz(int u, int v, int waga) : u(u), v(v), waga(waga) {}

    bool operator<(const Krawedz& other) const {
        return waga < other.waga;
    }
};

class ZbioryRozlaczne {
public:
    vector<int> rodzic, rangi;
    ZbioryRozlaczne(int n) {
        rodzic.resize(n);
        rangi.resize(n, 0);
        for (int i = 0; i < n; i++)
            rodzic[i] = i;
    }

    int znajdz(int u) {
        if (u != rodzic[u])
            rodzic[u] = znajdz(rodzic[u]);
        return rodzic[u];
    }

    void polacz(int u, int v) {
        int rootU = znajdz(u);
        int rootV = znajdz(v);
        if (rootU != rootV) {
            if (rangi[rootU] > rangi[rootV]) {
                rodzic[rootV] = rootU;
            }
            else if (rangi[rootU] < rangi[rootV]) {
                rodzic[rootU] = rootV;
            }
            else {
                rodzic[rootV] = rootU;
                rangi[rootU]++;
            }
        }
    }
};

int main() {
    int n = 10; 
    vector<Krawedz> krawedzie = { Krawedz(1, 2, 1), Krawedz(1, 4, 8), Krawedz(2, 5, 2), Krawedz(1, 5, 2), Krawedz(4, 5, 1), Krawedz(4, 7, 5), Krawedz(4, 8, 4), Krawedz(5, 7, 6), Krawedz(5, 9, 9), Krawedz(6, 9, 1), Krawedz(6, 8, 2), Krawedz(3, 6, 6), Krawedz(3, 5, 3), Krawedz(5, 8, 3) };

    cout << "Poczatkowa lista krawêezi:\n";
    for (const auto& krawedz : krawedzie) {
        cout << krawedz.u << " - " << krawedz.v << " : " << krawedz.waga << endl;
    }

    sort(krawedzie.begin(), krawedzie.end());

    cout << "\nPosortowana lista krawedzi:\n";
    for (const auto& krawedz : krawedzie) {
        cout << krawedz.u << " - " << krawedz.v << " : " << krawedz.waga << endl;
    }

    ZbioryRozlaczne zr(n);
    vector<Krawedz> mst;
    int wagaMST = 0;

    for (const auto& krawedz : krawedzie) {
        if (zr.znajdz(krawedz.u) != zr.znajdz(krawedz.v)) {
            zr.polacz(krawedz.u, krawedz.v);
            mst.push_back(krawedz);
            wagaMST += krawedz.waga;
        }
    }

    cout << "\nKrawedzie w minimalnym drzewie rozpinajacym:\n";
    for (const auto& krawedz : mst) {
        cout << krawedz.u << " - " << krawedz.v << " : " << krawedz.waga << endl;
    }

    cout << "\nlaczna waga MST: " << wagaMST << endl;

    return 0;
}

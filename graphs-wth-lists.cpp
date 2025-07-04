#include <iostream>
#include <list>
using namespace std;

class graf {
	int liczba;
	list <int>* l;
public:
	graf(int v) {
		this->liczba = v;
		l = new list<int>[v];
	
	}

	void dodaj(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void wyswietl(){
		for (int i = 0; i < liczba; i++) {
			cout << "Wierzcholek " << i << "->";
			for (int x : l[i]) {
				cout << x << ",";
			}
			cout << endl;
		}
	}
	void DFSU(int v, bool odwiedzony[]) {
		odwiedzony[v] = true;
		cout << v << " ";

		for (int i : l[v]) {
			if (!odwiedzony[i])
				DFSU(i, odwiedzony);
		}
	}

	void DFS(int start) {
		bool* odwiedzony = new bool[liczba];
		for (int i = 0; i < liczba; i++) 
			odwiedzony[i] = false;

			DFSU(start, odwiedzony);

			delete[]odwiedzony;
		
	}
};
int main() {
	graf g(5);
	g.dodaj(0, 1);
	g.dodaj(0, 2);
	g.dodaj(2, 3);
	g.dodaj(1, 2);
	g.dodaj(2, 2);
	g.wyswietl();
	g.DFS(0);
	return 0;
}
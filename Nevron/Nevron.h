#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class Nevron {
public:
	//konstruktor
	Nevron(size_t pod) {
		//spreminjannje velikosti tabele s st. podatkov
		podatki.resize(pod, 0);
		w.resize(pod + 1);
		//generiranje nakljucnih stevil od -0.99 do 0.99
		for (size_t i = 0; i < w.size(); i++) {
			w[i] = (rand() % 199 - 99) / 100.f;
		}
	}

	//izracun
	void racNaprej(vector<float> pod) {
		podatki = pod;

		float izracun = 0;
		for (size_t i = 0; i < podatki.size(); i++) {
			izracun += w[i] * podatki[i];
		}
		izracun += b;
		//ce je vec od 0 bo 1 drugace 0
		normaliziran = (izracun >= 0.f);
	}

	//izracun napake in spreminjanje nakljucnih st.
	void racNazaj(int res) {
		float napaka = res - normaliziran;
		//spreminjanje nak. st.
		for (size_t i = 0; i < podatki.size(); i++) {
			w[i] += podatki[i] * napaka * hu;
		}
		
		b += napaka * hu;
	}

	//treniranje enega ugibanja
	void treniraj(vector<float> pod, int res) {
		racNaprej(pod);
		racNazaj(res);
	}
	//treniranje vecih ugibanj nakljucno
	void treniraj(vector<vector<float>> pod, vector<int> res, int pon) {
		for (; pon > 0; pon--) {
			//treniranje nakljucnega ugiba
			size_t poz = rand() % res.size();
			treniraj(pod[poz], res[poz]);
		}
	}

	//izpis nazadnjega ugiba
	void izpis() {
		cout << "\t" << normaliziran << endl;
	}
	//izpis podatkov in ugiba
	void izpis(vector<float> pod) {
		for (auto p : pod)
			cout << p << " ";
		racNaprej(pod);
		izpis();
	}
	//izpis vecih podatkov in ugibanj
	void izpis(vector<vector<float>> pod) {
		for (vector<float> p : pod)
			izpis(p);
		cout << endl;
	}

	//destruktor
	~Nevron() {}
private:
	//privatna deklaracija spremenljivk
	const float hu = 0.03f; //hitrost ucenja
	int normaliziran = 0; //normaliziran izracun
	float b = 1.f; //x*w + b
	vector<float> podatki; //tabela z podatki
	vector<float> w; //nalkjucna stevila
};
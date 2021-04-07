#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class Nevron {
	typedef vector<float> tab;
	typedef vector<vector<float>> tab2d;
public:
	//konstruktor
	Nevron(size_t pod) {

		v.resize(pod, 0);
		w.resize(pod + 1);
		//nakljucna stevila od -0.99 do 0.99
		for (size_t i = 0; i < w.size(); i++) {
			w[i] = (rand() % 199 - 99) / 100.f;
		}
	}

	//izracun
	void racNaprej(tab pod) {
		v = pod;
		//izracun ugiba
		float izracun = 0;
		for (size_t i = 0; i < v.size(); i++) {
			izracun += w[i] * v[i];
		}
		izracun += b;

		//normalizacija izracuna
		normaliziran = izracun >= 0.f;
	}

	//popravljanje napak pri izracunu
	void racNazaj(int res) {
		//izracun napake
		float napaka = res - normaliziran;
		//popravljanje nakljucnih stevil
		for (size_t i = 0; i < v.size(); i++) {
			w[i] += v[i] * napaka * hu;
		}
		//popravljanje b-ja
		b += napaka * hu;
	}

	//treniranje vecih ugibanj nakljucno
	void treniraj(tab2d &pod, tab res, int pon) {
		for (; pon > 0; pon--) {
			//treniranje nakljucnega ugiba
			size_t poz = rand() % res.size();
			treniraj(pod[poz], res[poz]);
		}
	}
	//treniranje enega ugibanja
	void treniraj(tab &pod, int res) {
		racNaprej(pod);
		racNazaj(res);
	}

	//izpis vecih podatkov in ugibanj
	void izpis(tab2d &pod) {
		for (tab p : pod)
			izpis(p);
		cout << endl;
	}
	//izpis podatkov in ugiba
	void izpis(tab &pod) {
		for (float p : pod)
			cout << p << " ";
		racNaprej(pod);
		izpis();
	}
	//izpis nazadnjega ugiba
	void izpis() {
		cout << "\t" << normaliziran << endl;
	}

	//destruktor
	~Nevron() {}
private:
	//privatna deklaracija spremenljivk
	const float hu = 0.03f;	//hitrost ucenja
	int normaliziran = 0;	//normaliziran izracun
	float b = 1.f;			//x*w + b (bias)
	tab v;					//tabela z podatki
	tab w;					//nalkjucna stevila
};
#pragma once
#include "Matrika.h"

namespace po {
	const float e = 2.71828182846f;
	const float hu = 0.03f;
}

class Omrezje {
	typedef vector<float> tab;
	typedef vector<vector<float>> tab2d;
	typedef Matrika<float> mat;
	//typedef vector<Matrika<float>> tabmat;
private:
	class Plast {
	public:
		Plast(size_t podatki, size_t izracun) {
			pod.naredi(1, podatki);
			nap.naredi(1, podatki);
			b.naredi(1, podatki);
			b = 1.f;
			w.naredi(podatki, izracun);
			w.nakljucno();
		}

		void racNaprej(mat& izracun) {
			izracun = pod * w;
			izracun += b;
			izracun.funkcija([](float& x) { return 1 / (1 + pow(po::e, -x)); });
		}

		void racNazaj(mat& izracun, mat& napaka) {
			napaka = w.Prenesi() * nap;

			mat temp;
			for (size_t i = 0; i < nap.St(); i++) {
				for (size_t j = 0; j < nap.Vr(); j++) {
					temp(i, j) = nap(i, j) * (izracun(i, j) * (1 - izracun(i, j)));
				}
			}
			w += temp * pod * po::hu;
			b += temp * po::hu;
		}



		~Plast() {}

		mat nap;
		mat pod;
		mat w;
		mat b;
	};

public:
	Omrezje(tab podatki) {
		for (size_t i = 0; i < podatki.size() - 1; i++) {
			nomrezje.push_back(Plast(podatki[i], podatki[i + 1]));
		}
		izracun.naredi(1, podatki.back());
	}

	void racNaprej(tab podatki) {
		nomrezje.front().pod = podatki;
		for (size_t i = 0; i < nomrezje.size() - 1; i++) {
			nomrezje[i].racNaprej(nomrezje[i + 1].pod);
		}
		nomrezje.back().racNaprej(izracun);
	}

	void racNazaj(tab napake) {
		//2*[error]
		for (size_t i = 0; i < nomrezje.size(); i++) {
			nomrezje[i].racNazaj(nomrezje[i].pod, nomrezje[i - 1].nap);
		}
	}

	void izpis() {
		izracun.izpis();
	}

	~Omrezje() {}
private:

private:
	vector<Plast> nomrezje;
	mat izracun;
};
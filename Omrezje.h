#pragma once
#include "Matrika.h"

class Omrezje {
	typedef vector<float> vectorF;
	typedef vector<Matrika<float>> vectorM;
public:
	//konstruktor in inicializacija
	Omrezje(vector<size_t> podatki){
		for (size_t i = 0; i < podatki.size(); i++) {
			Matrika<float> temp(1, podatki[i]);
			a.push_back(temp);
			g.push_back(temp);
			n.push_back(temp);
			if (i > 0) {
				w.push_back(Matrika<float>(podatki[i - 1], podatki[i]));
				w.back().nakljucno();
				b.push_back(1.f);
			}
		}
	}

	//izracun ugiba
	void racNaprej(vectorF pod) {
		//pridobivanje podatkov
		a.front() = pod;

		//izracun
		for (size_t i = 1; i < a.size(); i++) {
			a[i] = a[i - 1] * w[i - 1];
			a[i] += b[i - 1];
			a[i].funkcija([](float x) {
				return 1 / (1 + exp(-x));
				});
		}
	}

	//ta funkcija ne dela pravilo
	void racNazaj(vectorF res) {
		//izracun prve napake
		for (size_t i = 0; i < res.size(); i++)
			n.back()(0, i) = pow(res[i] - a.back()(0, i), 2);

		//izracun vseh napak
		for (size_t i = a.size() - 1; i > 0; i--)
			n[i - 1] = n[i] * w[i - 1].Prenesi();

		//prvi izracun
		for (size_t i = 0; i < g.size(); i++) {
			for (size_t j = 0; j < g[i].St(); j++) {
				g[i](0, j) = n[i](0, j) * dsig(a[i](0, j)) * hu;
			}
		}

		//drugi izracun in prilagajanje
		for (size_t i = 1; i < a.size(); i++) {
			for (size_t S = 0; S < w[i - 1].St(); S++) {
				for (size_t V = 0; V < w[i - 1].Vr(); V++) {
					w[i - 1](V, S) += a[i - 1](0, V) * g[i](0, S);
				}
			}
		}

		//prilagajanje spremenljivke
		for (size_t i = 1; i < g.size(); i++) {
			float dg = 0;
			for (size_t S = 0; S < g[i].St(); S++) {
				dg += g[i](0, S);
			}
			b[i - 1] += dg / g[i].St();
		}
	}
	
	void treniraj(vectorF pod, vectorF res) {
		racNaprej(pod);
		racNazaj(res);
	}

	void izpis() {
		for (size_t i = 0; i < a.back().St(); i++) {
			cout << a.back()(0, i) << endl;
		}
	}
	void izpis(vectorF pod) {
		racNaprej(pod);
		izpis();
	}
	void izpis(vectorF pod, vectorF res) {
		racNaprej(pod);
		racNazaj(res);
		izpis();
	}


	~Omrezje() {}
private:
	float dsig(float x) { return x * (1 + x); }
private:
	const float hu = 0.03f; //hitrost ucenja
	vectorM a;
	vectorM g;
	vectorM n;
	vectorM w;
	vectorF b;
};
#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Nevron {
public:
	//konstruktor
	Nevron(size_t pod) {
		//spreminjannje velikosti tabele s st. podatkov
		podatki.resize(pod, 0);
		w.resize(pod + 1);
		//generiranje nakljucnih stevil od -.99 do .99
		for (size_t i = 0; i < w.size(); i++) {
			w[i] = (rand() % 199 - 99) / 100.f;
		}
	}

	//izracun poizkusa
	void racNaprej(vector<float> pod) {
		podatki = pod;

		float izracun = 0;
		for (size_t i = 0; i < podatki.size(); i++) {
			izracun += w[i] * podatki[i];
		}
		izracun += b;
		normaliziran = (izracun >= 0.f);
	}

	//izracun napake in prilagajanje nakljucnih st.
	void racNazaj(float res) {
		float napaka = res - normaliziran;
		float g = napaka * hu;
		for (size_t i = 0; i < podatki.size(); i++) {
			w[i] += podatki[i] * g;
		}
		b += g;
	}

	void treniraj(vector<float> pod, float res) {
		racNaprej(pod);
		racNazaj(res);
	}

	//izpis izracuna
	void izpis() {
		cout << normaliziran << endl;
	}
	void izpis(vector<float> pod) {
		racNaprej(pod);
		izpis();
	}

	~Nevron() {}
private:
private:
	float normaliziran = 0; //normaliziran izracun
	const float hu = 0.03f; //hitrost ucenja
	float b = 1.f; //x*w + b
	vector<float> podatki; //tabela z podatki
	vector<float> w; //nalkjucna stevila
};

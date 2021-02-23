#pragma once
#include "Matrika.h"


class Omrezje {
public:
	Omrezje() {}
	Omrezje(vector<size_t> pod)
		:podatki(pod)
	{
		for (size_t i = 0; i < pod.size(); i++) {
			Matrika<float> temp(1, pod[i]);
			v.push_back(temp);
			g.push_back(temp);
			e.push_back(temp);
			if (i > 0) {
				//b.push_back(1.f);
				w.push_back(Matrika<float>(pod[i - 1], pod[i]));
				w.back().nakljucno();
			}
		}
	}

	void racNaprej(vector<float> pod) {
		v.front() = pod;

		for (size_t i = 1; i < podatki.size(); i++) {
			v[i] = v[i - 1] * w[i - 1];
			v[i].funkcija([](float x) {
				return 1 / (1 + exp(-x));
				});
		}
	}

	void racNazaj(vector<float> res) { //ta funkcija ne dala kar bi mogla
		for (size_t i = 0; i < res.size(); i++) {
			//e.back()(0, i) = pow(res[i] - v.back()(0, i), 2);
			e.back()(0, i) = pow(res[i] - v.back()(0, i),2);
		}

		for (int i = podatki.size() - 1; i > 0; i--) {
			e[i - 1] = e[i] * w[i - 1].Prenesi();
		}

		for (size_t i = 0; i < podatki.size(); i++) {
			for (size_t S = 0; S < g[i].St(); S++) {
				g[i](0, S) = dsig(v[i](0, S)) * e[i](0, S) * hu;
			}
		}

		for (size_t i = 0; i < podatki.size() - 1; i++) {
			for (size_t V = 0; V < w[i].Vr(); V++) {
				for (size_t S = 0; S < w[i].St(); S++) {
					w[i](V, S) += v[i](0,V) * g[i + 1](0,S);
				}
			}
			//w[i - 1] += v[i - 1].Prenesi() * g[i];
		}
	}

	void treniraj(vector<float> pod, vector<float> res) {
		racNaprej(pod);
		racNazaj(res);
	}

	void izpis() {
		cout << endl;
		v.back().izpis();
		cout << endl;
	}
	void izpisW() {
		cout << endl;
		for (size_t i = 0; i < w.size(); i++) {
			w[i].izpis();
			cout << endl;
		}
		cout << endl;
	}
	void izpis(vector<float> pod) {
		cout << endl;
		racNaprej(pod);
		v.back().izpis();
		cout << endl;
	}

	float sig(float x) {
		return 1 / (1 + exp(-x));
	}
	float dsig(float x) {
		return x * (1 - x);
		//return exp(-x) * (1 - exp(-x));
	}

	~Omrezje() {}
private:
private:
	vector<Matrika<float>> v, e, g;
	vector<Matrika<float>> w;
	//vector<float> b;
	vector<size_t> podatki;
	float hu = 0.9f;
};

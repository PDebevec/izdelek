#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

template<typename T>
class Matrika {
public:
	Matrika() {};
	Matrika(size_t v, size_t s)
		:V(v), S(s)
	{
		srand((unsigned int)time(NULL));
		vector<T> temp;
		temp.resize(s, 0);
		data.resize(v, temp);
	}

	//vector<vector<T>>& operator()() { return data; }
	vector<T>& operator()(size_t i) { return data[i]; }
	T& operator()(size_t i, size_t j) { return data[i][j]; }

	Matrika<T>& operator=(Matrika<T> druga) {
		S = druga.St();
		V = druga.Vr();
		vector<T> temp;
		temp.resize(druga.St());
		data.resize(druga.Vr(), temp);
		for (size_t i = 0; i < V; i++) {
			for (size_t j = 0; j < S; j++) {
				data[i][j] = druga(i, j);
			}
		}
		return *this;
	}
	Matrika<T>& operator=(vector<vector<T>> tab) {
		for (size_t i = 0; i < V; i++) {
			for (size_t j = 0; j < S; j++) {
				data[i][j] = tab[i][j];
			}
		}
		return *this;
	}
	Matrika<T>& operator=(vector<T> tab) {
		int k = 0;
		for (size_t i = 0; i < V; i++) {
			for (size_t j = 0; j < S; j++) {
				data[i][j] = tab[k];
				k++;
			}
		}
		return *this;
	}
	Matrika<T>& operator=(T t) {
		for (size_t i = 0; i < V; i++) {
			for (size_t j = 0; j < S; j++) {
				data[i][j] = t;
			}
		}
		return *this;
	}

	Matrika<T> operator+(Matrika<T> druga) {
		Matrika temp(V, S);
		for (size_t i = 0; i < V; i++) {
			for (size_t j = 0; j < S; j++) {
				temp(i, j) = data[i][j] + druga(i, j);
			}
		}
		return temp;
	}
	Matrika<T> operator+(T t) {
		Matrika temp(V, S);
		for (size_t i = 0; i < V; i++) {
			for (size_t j = 0; j < S; j++) {
				temp(i, j) = data[i][j] + t;
			}
		}
		return temp;
	}
	Matrika<T> operator-(Matrika<T> druga) {
		Matrika temp(V, S);
		for (size_t i = 0; i < V; i++) {
			for (size_t j = 0; j < S; j++) {
				temp(i, j) = data[i][j] - druga(i, j);
			}
		}
		return temp;
	}
	Matrika<T> operator-(T t) {
		Matrika temp(V, S);
		for (size_t i = 0; i < V; i++) {
			for (size_t j = 0; j < S; j++) {
				temp(i, j) = data[i][j] - t;
			}
		}
		return temp;
	}
	Matrika<T> operator*(Matrika<T> druga) {
		Matrika temp(V, druga.St());
		for (size_t i = 0; i < V; i++) {
			for (size_t j = 0; j < druga.St(); j++) {
				for (size_t k = 0; k < S; k++) {
					temp(i, j) += data[i][k] * druga(k, j);
				}
			}
		}
		return temp;
	}
	Matrika<T> operator*(T t) {
		Matrika temp(V, S);
		for (size_t i = 0; i < V; i++) {
			for (size_t j = 0; j < S; j++) {
				temp(i, j) += data[i][j] * t;
			}
		}
		return temp;
	}
	Matrika<T> operator/(Matrika<T> druga) {
		Matrika temp(V, druga.St());
		for (size_t i = 0; i < V; i++) {
			for (size_t j = 0; j < druga.St(); j++) {
				for (size_t k = 0; k < S; k++) {
					temp(i, j) += data[i][k] * pow(druga(k, j), -1);
				}
			}
		}
		return temp;
	}
	Matrika<T> operator/(T t) {
		Matrika temp(V, S);
		for (size_t i = 0; i < V; i++) {
			for (size_t j = 0; j < S; j++) {
				temp(i, j) += data[i][j] * pow(t, -1);
			}
		}
		return temp;
	}

	Matrika<T>& operator+=(Matrika<T> druga) {
		for (size_t i = 0; i < druga.Vr(); i++) {
			for (size_t j = 0; j < druga.St(); j++) {
				data[i][j] += druga(i, j);
			}
		}
		return *this;
	}
	Matrika<T>& operator+=(T t) {
		for (size_t i = 0; i < V; i++) {
			for (size_t j = 0; j < S; j++) {
				data[i][j] += t;
			}
		}
		return *this;
	}
	Matrika<T>& operator-=(Matrika<T> druga) {
		for (size_t i = 0; i < druga.Vr(); i++) {
			for (size_t j = 0; j < druga.St(); j++) {
				data[i][j] -= druga(i, j);
			}
		}
		return *this;
	}
	Matrika<T>& operator-=(T t) {
		for (size_t i = 0; i < V; i++) {
			for (size_t j = 0; j < S; j++) {
				data[i][j] -= t;
			}
		}
		return *this;
	}
	Matrika<T>& operator*=(Matrika<T> druga) {
		//Matrika<T> temp = (*this) * druga;
		(*this) = (*this) * druga;
		return *this;
	}
	Matrika<T>& operator*=(T t) {
		//Matrika<T> temp = (*this) * druga;
		(*this) = (*this) * t;
		return *this;
	}
	Matrika<T>& operator/=(Matrika<T> druga) {
		//Matrika<T> temp = (*this) / druga;
		(*this) = (*this) / druga;
		return *this;
	}
	Matrika<T>& operator/=(T t) {
		//Matrika<T> temp = (*this) / druga;
		(*this) = (*this) / t;
		return *this;
	}

	Matrika<T> Prenesi() {
		Matrika<T> vrnitev(S, V);
		for (size_t i = 0; i < S; i++) {
			for (size_t j = 0; j < V; j++) {
				vrnitev(i, j) = data[j][i];
			}
		}
		return vrnitev;
	}

	size_t St() const { return S; }
	size_t Vr() const { return V; }
	size_t dolzina() const { return V * S; }

	void izpis() {
		for (size_t i = 0; i < V; i++) {
			for (size_t j = 0; j < S; j++) {
				cout << data[i][j] << ",\t";
			}
			cout << endl;
		}
	}
	void nakljucno() {
		for (size_t i = 0; i < V; i++) {
			for (size_t j = 0; j < S; j++) {
				data[i][j] = (rand() % 199 - 99) / 100.f;
			}
		}
	}
	void funkcija(T(fun)(T)) {
		for (size_t i = 0; i < V; i++) {
			for (size_t j = 0; j < S; j++) {
				data[i][j] = fun(data[i][j]);
			}
		}
	}
	/*Matrika<T> funkcijam(T(fun)(T)) {
		Matrika<T> temp(V, S);
		for (size_t i = 0; i < V; i++) {
			for (size_t j = 0; j < S; j++) {
				temp(i, j) = fun(data[i][j]);
			}
		}
		return temp;
	}*/
	~Matrika() {}
private:
private:
	vector<vector<T>> data;
	size_t S, V;
};
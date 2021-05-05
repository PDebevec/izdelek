#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

template<typename T>
class Matrika {
	typedef vector<T> tab;
	//class
	template<typename V>
	class Vrstica {
	public:
		Vrstica(size_t vel) {
			vrsta.resize(vel);
		}

		V& operator[] (size_t poz) { return vrsta[poz]; }

		size_t S() const { return vrsta.size(); }

	private:
		tab vrsta;
	};
public:
	Matrika(size_t sto, size_t vrs)
		:S(sto), V(vrs)
	{
		Vrstica<T> v(vrs);
		mat.resize(sto, v);
	}
	////operatorji
	//operator indeksa
	Vrstica<T>& operator[](size_t sto) { return mat[sto]; }
	////enacenje
	//enacenje
	Matrika<T> operator=(Matrika<T>& druga) {}
	Matrika<T> operator=(tab& druga) {}
	Matrika<T> operator=(T druga) {}

	//operatorji enacenje s drugimi tabelami
	Matrika<T>& operator+=(Matrika<T>& druga) {}
	Matrika<T>& operator-=(Matrika<T>& druga) {}
	Matrika<T>& operator*=(Matrika<T>& druga) {}
	Matrika<T>& operator/=(Matrika<T>& druga) {}
	//operatorji za enacenje s spremenljivko
	Matrika<T>& operator+=(T druga) {}
	Matrika<T>& operator-=(T druga) {}
	Matrika<T>& operator*=(T druga) {}
	Matrika<T>& operator/=(T druga) {}
	////operatorji za 
	//operatorji za druge tabele
	Matrika<T> operator+(Matrika<T>& druga) {}
	Matrika<T> operator-(Matrika<T>& druga) {}
	Matrika<T> operator*(Matrika<T>& druga) {}
	Matrika<T> operator/(Matrika<T>& druga) {}
	//operatorji za spremenljivko
	Matrika<T> operator+(T druga) {}
	Matrika<T> operator-(T druga) {}
	Matrika<T> operator*(T druga) {}
	Matrika<T> operator/(T druga) {}

	////druge funkcije
	//velikost
	size_t St() const { return mat[0].S(); }
	size_t Vr() const { return mat.size(); }
	//destruktor
	~Matrika(){}
private:

private:
	vector<Vrstica<T>> mat;
	size_t S, V;
};
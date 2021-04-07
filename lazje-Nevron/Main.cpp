#include "Nevron.h"

int main() {
	srand((unsigned int)time(NULL));

	vector<vector<float>> pod = {
		{1,1},
		{1,0},
		{0,1},
		{0,0}
	};
	vector<vector<float>> pod_xor = {
		{1,1},
		{1,0},
		{1,0},
		{0,0}
	};
	//deklaracija razredov
	Nevron IN(2);
	Nevron ALI(2);
	//xor uporabi izracune iz nevrona IN in ALI
	Nevron XOR(2);

	//zacetek progarama
	cout << "Izracun brez treniranja.\n\n";
	//v funkcijo vnesemo tabelo tabel s podatki
	cout << "IN\n";
	IN.izpis(pod);

	cout << "ALI\n";
	ALI.izpis(pod);

	cout << "XOR\n";
	XOR.izpis(pod_xor);

	cin.get();

	//treniranje
	//v funkcijo vnesemo podatke, resitve in st ponovitev treniranja
	IN.treniraj(
		pod,
		{1,0,0,0},
		600
	);

	ALI.treniraj(
		pod,
		{ 1,1,1,0 },
		600
	);

	XOR.treniraj(
		pod_xor,
		{ 0,1,1,0 },
		600
	);

	//izracun pravilnih resitev
	cout << "Izracuni po treniranju.\n\n";
	//v funkcijo vnesemo podatke za izpis
	cout << "IN\n";
	IN.izpis(pod);

	cout << "ALI\n";
	ALI.izpis(pod);

	cout << "XOR\n";
	XOR.izpis(pod_xor);

	cin.get();
}

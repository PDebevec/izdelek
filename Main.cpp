#include "Nevron.h"

int main() {
	srand((unsigned int)time(NULL));

	//deklaracija razredov
	Nevron IN(2);
	Nevron ALI(2);
	//xor uporabi izracune iz nevrona IN in ALI
	Nevron XOR(2);

	//zacetek progarama
	cout << "Izracun brez treniranja.\n\n";
	//v funkcijo vnesemo tabelo tabel s podatki
	cout << "IN\n";
	IN.izpis({
		{1,1},
		{1,0},
		{0,1},
		{0,0}
		});

	cout << "ALI\n";
	ALI.izpis({
		{1,1},
		{1,0},
		{0,1},
		{0,0}
		});

	cout << "XOR\n";
	XOR.izpis({
		{1,1},
		{0,1},
		{0,1},
		{0,0}
		});

	cin.get();

	//treniranje
	cout << "TRENIRANJE\n\n";
	//v funkcijo vnesemo podatke, resitve in st ponovitev treniranja
	IN.treniraj({
		{1,1},
		{1,0},
		{0,1},
		{0,0}},
		{1,0,0,0},
		600
	);

	ALI.treniraj({
		{1,1},
		{1,0},
		{0,1},
		{0,0}},
		{ 1,1,1,0 },
		600
	);

	XOR.treniraj({
		{1,1},
		{0,1},
		{0,1},
		{0,0}},
		{ 0,1,1,0 },
		600
	);

	cout << "Konec\n\n";

	cin.get();

	//izracun pravilnih resitev
	cout << "Izracuni po treniranju.\n\n";
	//v funkcijo vnesemo podatke za izpis
	cout << "IN\n";
	IN.izpis({
		{1,1},
		{1,0},
		{0,1},
		{0,0}
		});

	cout << "ALI\n";
	ALI.izpis({
		{1,1},
		{1,0},
		{0,1},
		{0,0}
		});

	cout << "XOR\n";
	XOR.izpis({
		{1,1},
		{0,1},
		{0,1},
		{0,0}
		});

	cin.get();
}

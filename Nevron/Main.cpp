#include "Nevron.h"

int main() {
	srand((unsigned int)time(NULL));

	Nevron n(2);
	for (int i = 0; i < 500; i++) {
		switch (rand() % 4)
		{
		case 0:
			n.treniraj({ 1.f,1.f }, 1.f);
			break;
		case 1:
			n.treniraj({ 1.f,0.f }, 0.f);
			break;
		case 2:
			n.treniraj({ 0.f,1.f }, 0.f);
			break;
		case 3:
			n.treniraj({ 0.f,0.f }, 0.f);
			break;
		}
	}
	cout << "IN\n";
	n.izpis({ 1.f,1.f });
	n.izpis({ 1.f,0.f });
	n.izpis({ 0.f,1.f });
	n.izpis({ 0.f,0.f });
	cout << endl;
	//-------------------------------------------------
	Nevron b(2);
	for (int i = 0; i < 500; i++) {
		switch (rand() % 4)
		{
		case 0:
			b.treniraj({ 1.f,1.f }, 1.f);
			break;
		case 1:
			b.treniraj({ 1.f,0.f }, 1.f);
			break;
		case 2:
			b.treniraj({ 0.f,1.f }, 1.f);
			break;
		case 3:
			b.treniraj({ 0.f,0.f }, 0.f);
			break;
		}
	}
	cout << "ALI\n";
	b.izpis({ 1.f,1.f });
	b.izpis({ 1.f,0.f });
	b.izpis({ 0.f,1.f });
	b.izpis({ 0.f,0.f });
}

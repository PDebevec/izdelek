#include "Omrezje.h"

int main() {
	Omrezje n({ 2,2,1 });
	for (int i = 0; i < 10000; i++) {
		switch (rand()%4)
		{
		case 0:
			n.treniraj({ 1.f,1.f }, { 0.f });
			break;
		case 1:
			n.treniraj({ 1.f,0.f }, { 1.f });
			break;
		case 2:
			n.treniraj({ 0.f,1.f }, { 1.f });
			break;
		case 3:
			n.treniraj({ 0.f,0.f }, { 0.f });
			break;
		}
	}
	n.izpis({ 1.f,1.f });
	n.izpis({ 0.f,0.f });
	n.izpis({ 0.f,1.f });
	n.izpis({ 1.f,0.f });
}

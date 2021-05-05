#include "Omrezje.h"

int main() {
	srand((unsigned int)time(NULL));
	Omrezje no({ 2, 2, 1 });

	no.racNaprej({ 1.f, 1.f });
	no.izpis();
}
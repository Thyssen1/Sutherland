#include "extern.h"

void IncrementGlobalCounters() {
	extern int globalVariable;
	++globalVariable;

	extern int fileVariable;
	++fileVariable;
}
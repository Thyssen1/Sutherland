#include <iostream>
#include <memory>

class Simple {
private:
	int variable{ 0 };

public:
	Simple() {
		std::cout << "Created Simple!\n";
	}

	~Simple() {
		std::cout << "Destroyed Simple!\n";
	}
};

struct MemoryAllocationHeader {
	void* pStart{ nullptr };
	void* pNextFree{ nullptr };
	size_t size{ 0 };
};

namespace {
	const unsigned int ONE_MEGABYTE = 1024 * 1024 * 1024;
	char pMemoryHeap[ONE_MEGABYTE];
	const size_t SIZE_OF_MEMORY_HEADER = sizeof(MemoryAllocationHeader);
}

void* operator new(size_t size) {
	MemoryAllocationHeader* pHeader = reinterpret_cast<MemoryAllocationHeader*>(pMemoryHeap);

	while (pHeader != nullptr && pHeader->pNextFree != nullptr) {
		pHeader = reinterpret_cast<MemoryAllocationHeader*>(pHeader->pNextFree);
	}

	pHeader->pStart = reinterpret_cast<char*>(pHeader) + SIZE_OF_MEMORY_HEADER;
	pHeader->pNextFree = reinterpret_cast<char*>(pHeader->pStart) + size;
	pHeader->size = size;

	return pHeader->pStart;
}

void operator delete(void* pMemory) {
	MemoryAllocationHeader* pLast = nullptr;
	MemoryAllocationHeader* pCurrent = reinterpret_cast<MemoryAllocationHeader*>(pMemoryHeap);

	while (pCurrent != nullptr && pCurrent->pStart != pMemory) {
		pLast = pCurrent;
		pCurrent = reinterpret_cast<MemoryAllocationHeader*>(pCurrent->pNextFree);
	}

	if (pLast != nullptr) {
		pLast->pNextFree = reinterpret_cast<char*>(pCurrent->pNextFree);
	}

	pCurrent->pStart = nullptr;
	pCurrent->pNextFree = nullptr;
	pCurrent->size = 0;
}

void PrintAllocations() {
	MemoryAllocationHeader* pHeader = reinterpret_cast<MemoryAllocationHeader*>(pMemoryHeap);

	while (pHeader != nullptr) {
		std::cout << pHeader << "\n";
		std::cout << pHeader->pStart << "\n";
		std::cout << pHeader->pNextFree << "\n";
		std::cout << pHeader->size << "\n";

		pHeader = reinterpret_cast<MemoryAllocationHeader*>(pHeader->pNextFree);

		std::cout << "\n\n";
	}
}

int main() {
	memset(pMemoryHeap, 0, SIZE_OF_MEMORY_HEADER);

	std::cout << "PrintAllocations 1\n";
	PrintAllocations();

	Simple* pSimple1 = new Simple();
	std::cout << "PrintAllocations 2\n";
	PrintAllocations();

	Simple* pSimple2 = new Simple();
	std::cout << "PrintAllocations 3\n";
	PrintAllocations();

	Simple* pSimple3 = new Simple();
	std::cout << "PrintAllocations 4\n";
	PrintAllocations();

	delete pSimple2;
	pSimple2 = nullptr;
	std::cout << "PrintAllocations 5\n";
	PrintAllocations();

	pSimple2 = new Simple();
	std::cout << "PrintAllocations 6\n";
	PrintAllocations();

	delete pSimple2;
	pSimple2 = nullptr;

	std::cout << "PrintAllocations 7\n";
	PrintAllocations();

	delete pSimple3;
	pSimple3 = nullptr;

	std::cout << "PrintAllocations 8\n";
	PrintAllocations();

	return 0;
}
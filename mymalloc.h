#ifndef __NEW_MALLOC_H_
#define __NEW_MALLOC_H_
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <algorithm>
#include "memoryNode.h"
//Finder functor
class memoryNodeFinder {
public:
    
	explicit memoryNodeFinder(unsigned long address) : m_address(address){}
    
	bool operator() (const instruments::memoryNode & memNode ) const {
		return (memNode.getAddress() == m_address); 
    }
private:
    unsigned long m_address;
};

std::vector <instruments::memoryNode> memoryAllocationList;
void memoryLeakDetector()
{
	if(	memoryAllocationList.empty())
	{
		std::cout<< "You are a Good Programmer: No Memory leak" <<std::endl;
	}
	else
	{
		std::cout<< "Memory is leaking" <<std::endl;
		for (std::vector<instruments::memoryNode>::iterator it = memoryAllocationList.begin() ; it != memoryAllocationList.end(); it++ )
		{
			it->printMemoryBlock();					
		}
	}
}

void * mymalloc( size_t _Size, size_t lineNo, char* fileName)
{
	void *ptr = malloc(_Size);
	//Insert this Allocated block info into Linked List
	unsigned long address = (unsigned long)ptr;
	using namespace instruments;
	memoryNode allocatedBlock(_Size,lineNo,address,std::string(fileName));
	memoryAllocationList.push_back(allocatedBlock);
	return ptr;
}

void myfree(void * ptr)
{
	//Freeing the memory
	unsigned long address = (unsigned long)ptr;
	//Find the memory node having this address and Remove it
	free(ptr);
	memoryNodeFinder compare(address);	
	std::vector<instruments::memoryNode>::iterator it = std::find_if(memoryAllocationList.begin(),memoryAllocationList.end(),compare);
	//std::cout << "Node found with Address "<< it->getAddress() << " erasing it" <<std::endl;
	memoryAllocationList.erase(it);
}

#endif
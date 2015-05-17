#include <vector>
#include <iostream>
#include "memoryNode.h"
#include "mymalloc.h"

#define malloc(p) mymalloc(p, __LINE__ , __FILE__)
#define free(p) myfree(p)

int main(int argc, char* argv[])
{
	
	/*
	memoryNode m(12,3,11542,"applocation.cpp");
	memoryNode m2(40,89,134518,"applocation.cpp");
	memoryNode m3(20,12,15216,"applocation.cpp");
	std::vector <memoryNode> memoryAllocationList;
	memoryAllocationList.push_back(m);
	memoryAllocationList.push_back(m2);
	memoryAllocationList.push_back(m3);
	
	std::vector<memoryNode>::iterator it ;
	for (it = memoryAllocationList.begin() ; it != memoryAllocationList.end(); it++ )
	{
		it->printMemoryBlock();		
	}

	//Remove the memory block having address 
	memoryNodeFinder compare(15216);
	it = std::find_if(memoryAllocationList.begin(),memoryAllocationList.end(),compare);
	std::cout << "Node found with Address "<< it->getAddress();
	memoryAllocationList.erase(it);
	for (it = memoryAllocationList.begin() ; it != memoryAllocationList.end(); it++ )
	{
		it->printMemoryBlock();					
	}
	*/
	
	int * ptr = (int *) malloc(sizeof(int));

	int * ptr2 = (int *) malloc(sizeof(int));
	int * ptr3 = (int *) malloc(sizeof(int));
	*ptr = 43, *ptr2=323; *ptr3= 473; 
	free(ptr2);
	free(ptr);
	char *ch = (char *)malloc(sizeof(char));
	free(ptr3);
	free(ch);
	memoryLeakDetector();
	return 0;

}


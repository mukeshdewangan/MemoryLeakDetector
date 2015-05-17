#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "mymalloc.h"


#define malloc(p) mymalloc(p,__LINE__, __FILE__)
#define free(p) myfree(p)
int main_memoryLeak (int argc, char * argv[])
{
	int arraySize = 10, i;
	int * ptr = (int *) malloc(sizeof(int)*arraySize);
	for ( i = 0; i < arraySize; i++ )
	{
		ptr[i] = rand();
	}
	for ( i = 0; i < arraySize; i++ )
	{
		printf(" %d ",ptr[i] );
	} 
	free(ptr);
	return 0;
}
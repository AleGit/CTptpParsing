
#include <stdio.h>
#include "CSources/prlc.h"
int main()
{
	printf("Hello World!\n");

	PrlcStoreRef store = prlcCreateStore(95000);

	prlcDestroyStore(&store);
	return (0);
}

#include <stdio.h>
#include <stdlib.h>

#include "ex1_7module1.h"

/* test power function */
int main(void)
{
	int i;

	for (i =0; i <10; i++)
		printf("%d %d %d\n", i, power(2,i), power(-3,i));

	return EXIT_SUCCESS;
	
}

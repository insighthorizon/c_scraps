#include <stdio.h>

#define SHOW_SIZE(TYPE) printf("%s size: %ld \n", #TYPE, sizeof(TYPE));

int main()
{

	SHOW_SIZE(char);
	SHOW_SIZE(short);

	SHOW_SIZE(unsigned int);
	SHOW_SIZE(long unsigned int);
	SHOW_SIZE(long long unsigned int);
	
	SHOW_SIZE(signed int);
	SHOW_SIZE(long signed int);
	SHOW_SIZE(long long signed int);
	
	SHOW_SIZE(float);
	SHOW_SIZE(double);
	
	
}

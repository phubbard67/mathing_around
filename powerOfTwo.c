#include "powerOfTwo.h"

long int recursTwoToTheN(long int n)
{
	long int retVal;

	if(n <= 0)
	{
		return 1;
	}
	
	retVal = recursTwoToTheN(n - 1) + recursTwoToTheN(n - 1);
	return retVal;
}

void computeTwoToTheN()
{
	printf("Enter in a value for n greater than or equal to 0: ");
	char *usrIn = (char *) malloc(sizeof(char *));
       	scanf("%s", usrIn);
	long int n = atoi(usrIn);
	long int retVal;

	if(n >= 30)
	{
		printf("Thinking...\n");
	}
	
	retVal = recursTwoToTheN(n);	

	printf("2^%ld: %ld\n", n, retVal);

	free(usrIn);
}

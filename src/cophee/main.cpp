#include "cophee.hpp"

int main ()
{
	int pd = init_port() ;
	unsigned* result 	;
	unsigned length = 64;
	unsigned argA[length], argB[length];
	for ( unsigned i=0 ; i<length; i++ )
	{
		argA[i] = 0;
		argB[i] = 0;
	}
	argA[63]=5;
	argB[63]=4;

	printf("Initializing the chip\n") ;
	initialize_chip (pd) ;
	printf("after\n");

	result = mod_mul(argA,argB,pd) ;
	printf("end of mul\n");
	for ( unsigned i=0; i<length; i++ ) printf("%08x ", result[i]);
	printf("\n");
	// result = mod_inv(argA,cleq_NSQ,pd) ;
	// result = mod_inv(argB,cleq_NSQ,pd) ;
	result = gfunc(argA,argB,pd) ;

	close(pd) ;
	return 0 ;
}

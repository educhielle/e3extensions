#include <iostream>
#include "../../src/e3extensions/secureint.h"
#include <papi.h>

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	long long s, e;

	s = PAPI_get_real_cyc();
	for (int i = 0; i < 1000000; i++) asm volatile("nop");
	e = PAPI_get_real_cyc();
	cout << "For loop: " << (e-s) << " cycles\n";

	s = PAPI_get_real_cyc();
	Cryptosystem cs("9096826660276715153","8","57361836314264029896524713110290999873","50692253130197694181455288239082047510","60240225594499655140763975775403674500", libgDir, gFunctionName);
	e = PAPI_get_real_cyc();
	cout << "Load Cryptosystem: " << (e-s) << " cycles\n";

	s = PAPI_get_real_cyc();
	SecureInt a("32899931610320744318320073924746822360",cs);
	e = PAPI_get_real_cyc();
	cout << "SecureInt a: " << (e-s) << " cycles\n";

	s = PAPI_get_real_cyc();
	SecureInt b("22920929804909968957156144117317044680",cs);
	e = PAPI_get_real_cyc();
	cout << "SecureInt b: " << (e-s) << " cycles\n";

	s = PAPI_get_real_cyc();
	SecureInt c;
	e = PAPI_get_real_cyc();
	cout << "SecureInt c: " << (e-s) << " cycles\n";

	s = PAPI_get_real_cyc();
	c = a + b;
	e = PAPI_get_real_cyc();
	cout << "c = a + b: " << (e-s) << " cycles\n";

	s = PAPI_get_real_cyc();
	c = a * b;
	e = PAPI_get_real_cyc();
	cout << "c = a * b: " << (e-s) << " cycles\n";

	s = PAPI_get_real_cyc();
	c = SecureInt::G(a,b);
	e = PAPI_get_real_cyc();
	cout << "c = G(a,b): " << (e-s) << " cycles\n";	

	return 0;
}


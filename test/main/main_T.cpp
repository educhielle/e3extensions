#ifndef SECUREINT_INCLUDED
	#define SECUREINT_INCLUDED
	#include "../../src/e3extensions/secureint.h"
#endif

#ifndef SENSITIVE_INFORMATION_INCLUDED
	#define SENSITIVE_INFORMATION_INCLUDED
	#include "../../src/preprocessor/sensitive_information.h"
#endif

#ifndef STDIO_INCLUDED
	#define STDIO_INCLUDED
	#include <stdio.h>
#endif

#ifndef IOSTREAM_INCLUDED
	#define IOSTREAM_INCLUDED
	#include <iostream>
#endif

using namespace std;

string libgDir = "../../lib/libg.so";

void printPair(const Unumber, const Unumber);

/*
 * P and Q must be different prime numbers
 * K and RND must not be multiple of P or Q
 */

int main()
{
	/* Using SensitiveInformation to test SecureInt */

	//SensitiveInformation (p,q,k,rnd);
	//SensitiveInformation si ("104947","105613","3","2");
	//SensitiveInformation si ("13","11","2","2");
	//si.setBeta(3);
	SensitiveInformation si ("13","11","2","2");
	
	Unumber udecA(11), udecB(3);

	Unumber uencA = si.encrypt(udecA);
	Unumber uencB = si.encrypt(udecB);

	cout << "Inputs:\n";

	printPair(udecA, uencA);
	printPair(udecB, uencB);

	/* SecureInt and Cryptosystem test area */

	//Cryptosystem cs(un,g,rndN);
	//SecureInt a(uencA,cs), b(uencB,cs), c[20];

	//Cryptosystem cs(__PQ(p)(q)(k)(rnd)__, 64, __2TOBETA__, __ENC0__, __ENC1__, "./libg.so", "g");	
	//Cryptosystem ms("143","3","10981","18918","5768", "./libg.so", "g");
	
	//Cryptosystem cs("104947","105613","2","2", "./libg.so", "g");
	//Cryptosystem cs(__PQ(13)(11)(2)(2)__, __BETA__, __2TOBETA__, __ENC0__, __ENC1__, "./libg.so", "g"), aaa;
	//Cryptosystem cs(__PQ(104947)(105613)(3)(2)__, 3, __2TOBETA__, __ENC0__, __ENC1__, "./libg.so", "g"), aaa;
	Cryptosystem cs("143","3","13347","19750","9694", libgDir, "g"), aaa;
	SecureInt a("16344",cs), b("2044",cs), c[20];

	aaa = Cryptosystem("169","5","25180","2198","17408", libgDir, "g");
	//a = SecureInt(__N(11)__,aaa); b = SecureInt(__N(3)__,aaa);
	
	c[0] = a+b;	cout << "0\n";
	c[1] = a-b;	cout << "1\n";
	c[2] = a==b;	cout << "2\n";
	c[3] = a!=b;	cout << "3\n";
	c[4] = -a;	cout << "4\n";
	c[5] = +a;	cout << "5\n";
	c[6] = a*b;	cout << "6\n";
	c[7] = a<<0;	cout << "7\n";
	c[8] = a<<1; 	cout << "8\n";// equivalent to a * a * ... the number of a's is (param+1).
	c[9] = a<<2;	cout << "9\n";
	c[10] = a<<3;	cout << "10\n";
	c[11] = a<<4;	cout << "11\n";
	c[12] = a<<5;	cout << "12\n";
	c[13] = a<<6;	cout << "13\n";
	c[14] = a<<7;	cout << "14\n";
	c[15] = a<<8;	cout << "15\n";
	c[16] = a>>1; 	cout << "16\n";// equivalent to subsequent div2's of a. The number of div2's is param.
	c[17] = a>>2;	cout << "17\n";
	c[18] = (a+b)*(a-b);	cout << "18\n";
	c[19] = a+b*b;	cout << "19\n";
	
	/* Checking SecureInt results with SensitiveInformation */
	
	cout << "\nOutputs:\n";

	Unumber R, udecC[20];
	
	udecA = si.decrypt(a.getX(), &R);
	udecB = si.decrypt(b.getX(), &R);
	cout << "a\t"; printPair(udecA, a.getX());
	cout << "b\t"; printPair(udecB, b.getX());

	cout << "\n";
	for (int i = 0; i <= 19; i++)
	{
		udecC[i] = si.decrypt(c[i].getX(), &R);
		cout << i << "\t";
		printPair(udecC[i], c[i].getX());
	}

	return 0;
}

void printPair(const Unumber dec, const Unumber enc)
{
	cout << "m: " << dec.str() << "\tx: " << enc << "\n";
}


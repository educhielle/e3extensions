#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 10
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("255143114427118716390135309016180310401",8,"17269296382761808889876612989562685510555551467307020677413816520662059406529",{"52186234083033442487142331882303510233739267285336625062229178671134930831213","27656294290713280219983715868974131956759222999263139724000599872845101269687","57440844539876911343596892132322945467860320293545107935675127334739811195109","62796227500641244282397264603593998030027319654288838617485434421507635599124","31828400040576911724594826067680609079097038859384100414740981512226701191515","3182347461930465536525396051502071165394971971274197148090197912236831682417","5919128624312793997620218941295243779085638644179820360466067126404878668032","65079160503964414395548161962353576197592774818166981059772223121771726643932","23839846088904429965357733398371857668883253555233069543345688289499624566"},"13537387029907059292665724524534505011171679298445231030622629500774181099427","7741215320763885622463700970399567175346592289585709867676950389065171095999", libgDir, gFunctionName);

	SecureInt num("45009707566334270794185962938164875445410642453360145840309338719716122112664",cs);
	SecureInt fact("4338361310601252018105412008778852923240919468402819267552961082259935265248",cs);
	SecureInt i("30768213344069759761265542534255391879340911872176997528421739277398096759035",cs);
	SecureInt result("22684296710890834730545335710205678250188502794707417236956013239922395839247",cs);
	
	int counter = 1;

	do {
		//cout << counter << "...\n";
		fact *= i;
		result += (i == num) * fact;
		++i;
	} while (++counter != MAX_NUM);

	cout << "fact( " << num.str() << " ) = " << result.str() << "\n";

	return 0;
}


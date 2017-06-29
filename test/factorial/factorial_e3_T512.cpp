#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 50
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("11659724797115294376683502272145134980629538728803276754883061872226968633096348659970417350751330691476738036081895821107228789402247716513117079635543673","16","130182198880499737059709016623564705987564621742416261571452848942312091309594206061825631611974696422937286430343922505371993375402451147111496396158107994826291741938631800771723124500228712354981452659923243181163763216730889160200115353409064303334492842314487886574961880240015655580561088457320767735299","95558971485833556978118881576711454247896282141077099061845526598101340630834106827475252296303464099474822059045970909421096540770410889764999577996923096001961749975500436313868730857815470136057465518944893517530316817321470876631042542301083538780367726632634354377625228255378150564521669577589423268952","10356147006190024847494222646243691611746748887949069739867755107091040414635598179862143531951779428577349526415440328987206216085372100896884273927961338560445685483003655295047030521547690402575862381679891835662717965649440352284099143259183676300675429857154689509109747501442997261493667668997360311331", libgDir, gFunctionName);

	SecureInt num("17044633265676025583716970768946090456226939161492214960901674984164681679436204047136207804288883875082744182171886254351716174463428814282934248871854502009405060463748392389746451371231779937403865692395675379141806969718548014542795391914129855648742522635186082793769811770496482112214248953689178598705",cs);
	SecureInt fact("133096591963320522470572108945773371672673102233056001535967079228824414646092479666706150194172904158165694638050935151491230162798071183002701213836912658341361807540454984848012549392490426552363481149942053877987750097916645676478575382979482822233990632365271651067468317830439950936360738616337825881300",cs);
	SecureInt i("38309750123441497381681533842982614247010659847002714561741283771905435135798236121131929552092484830225133359380696467841945471804287452950525726989037758327098761234962739835035867888859537454669038990229984390480952831555583365686856026491510023458317961147777173988165485897633036722103495803281401965325",cs);
	SecureInt result("115448699463788870349428790143154868073232945857266551052522267953033420920792996851762781717542599756261734376387513595728828815608485939104329530183169682349776706238301379555762614026557994097599365932854626810755121274428052635562920145960341857945246089783493759351155425632499072593714447046124354718815",cs);
	
	int counter = 1;

	do {
		cout << counter << "...\n";
		fact *= i;
		result += (i == num) * fact;
	} while (++counter != MAX_NUM);


	cout << "fact(" << fact.str() << ") = " << result.str() << "\n";

	return 0;
}


#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 10
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("15667332168837125993",32,"106047709663405929526465506802101449966",{"226251805968037515385912693225798339965","10787162752745975508871504403613603908","23285634439780707333139408317570909882","220935676603436060875053580507703047228","121486727432102075236681992533656348902","181780964842343922003474867327767512645","205802618167444594993735273464300808973","152417705687300097209245159877310626856","1094556718500015951120723806842102760","108344409519906959652125800025929864475","11669387256577704855127531390693913465","222422122204362791825642246649926730440","204991651543269208904636158055575537424","31985087740593216191285550457588954495","60066778242193486068803428175235300203","57884237585329461115973198166714279229","82862792748096211890763514347966603267","53856844797769941780109528972165415454","80888180548655851532959755198365760473","94863854776952614838482912974826134839","79637234982055564052847067603450994871","135664104084048592027653562386614119248","111291741298361524097950698588175373216","219201070619541135661640079140747421055","76662541919285548914558892400283871579","202503703706831720522841498007397012903","8091658127846574105058121711098680141","107628712067849901414868152749044756982","198223136306080835065991027408379155321","110343079831980321204645626361047394155","153639266472700107934333667135404365580","212846107637195419546442451481455252585","99780333386101635783340272464228409940"},"135861594179843232008766472148072705341","98902749413239893388674985358515658393", libgDir, gFunctionName);

	SecureInt num("237264638898950610010921669091480679218",cs);
	SecureInt fact("27482637562134998382467493562750356054",cs);
	SecureInt i("142453591752824298889460163687386107560",cs);
	SecureInt result("50111636447502785098107007610675693720",cs);
	
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


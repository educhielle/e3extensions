#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 10
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("50704674723019870081810292192832526847987274119108946089126609238300190847233",8,"1564100298666518609518339196995767504848294322388217068530640046431739945339809847717565030142208163928743624695945995093925758818327781631845681895402626",{"1698870064518880307284927653847546906498679485042613723521048257782696777192765044574409450455525895129928479785370742409298152581030763243599810089114676","647427091570733311414796787991934326898766905176634866769226048971452853357185473155803931136376443423432354160239187912957236760970947919847889681205014","2064255157555681019417564678749624258954431318894689017494119689581095315883882400509675874149469052566381998580742121311945520172241158445433883819906456","2414497325911980257232314935694196125542882491663506969280124307232605201991876435709179785713979690264062345309972001243866973394748164802042911617637533","575069019073313073717062868684131158501891590589244619818986449517209849999851254654084437205777084344456430043472880809754735712796901127018141416267939","1338225899055945694787851835693299638751848675453121549312786764555615230285326961305606799971883215905856898645975252013815717808636916032379671963936821","1250879640330521285944043718414239882477942022580480306252200425808137354833391882382714643357013459436653499680415493550404607928476088783918550982730519","355782517203602501123047213313225863396035036043934141375381482834878211970281881196686550338778002542433685254348734842137943578849436147283084476059066","1968958153603893061728049686343366500368623924700040005535295909731386929486765085364096847217537158867813989611340625719910734692931247922482313743109596"},"1289621882828947584476007983075029397444343808129004432338558398150566064676967474155948168182170110400661977982562795756309509145182785050367184599094065","325513870295720460123987196133488304691720855172735495717085061580499925769919760996060241030822684965502419446003038236212441570479491222904007712493347", libgDir, gFunctionName);

	SecureInt num("2281571665126691024111308249008755084065399681564946731893325170866248907022125609371434496374157976505531259867490417323559765606311069650953978844904129",cs);
	SecureInt fact("2455448398583217114302673708708089859414035980464701125811136280429280979285353935432028587515402397247864835584237752934839537713606500006877914553869686",cs);
	SecureInt i("210516774757011442951528536567996570561181504664267794724611483091113224981894912138509166713111269200804806587682024274039632120782751887358950821482838",cs);
	SecureInt result("1515264180140560505565229732446025318746927195927645209112877916527072908389611662300464531426294550912800765111913406805240592615050084735050342521528168",cs);
	
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


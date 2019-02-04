#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 10
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("7969754329260921494738550789124384773899930334265423881966997050031621132728759709916216421960798909753733218368731337864266788037371095990919111838939393",8,"49308415211153202678984681791910608153684587952354326823230943336287227850205624096615632309104650351060009662990764510287671292933530987520104751867817589709812313681551546172780458565006240935832453615573328791268697878657513008119510263812340105951809626501031218867788085195929532441310432775597913879236",{"26983563257303670467207892691522143005583354486968817710082125715043550211180347126186566194599771141704465923163694239422142259022642241600612830294115872042651491914152311437996798679631691567088367926629845565482564926725757740157581948628162180607828248705908394077057975494942932572994439183875617569027","15621622034718421603462636439006033036613270000256058184561111870895134912733458536095573602855592852597319039153582174175533180946681600865287661950302609916087888508374034929986049108291307004825333851999672060186559283328612615045424674440898854546501430786261550799026410766769041429201850858431222224915","3512193124553358863960059385327361140618506499002664248111582763278764932888107164788906277560544876612712546670222965026868800726892207941232109731831062440314642584578878012471318879274347569372648942574825756630040646295779949191690959221317555692781461718713837348258420426277135402161522190654188878691","36141893059605096828370928198715893552187980783988772436888846749423100823532389328828178439563570228489801762288567395179594757535863380697135638247687956642224014490198448360655873484043307415902596166980278000273476346379323467446453030679712419923614916668770868223303561643533150494957110455961822381026","37995891621946179404750795799470816640066985785522375488777783313135987366198662153234935607014618715728788991387651503288976387386760306963871564533025585797757659975138362688750679695076134220615280219369398281037368077095085517020189242091061068733678770753901627683921987007120616394312996339537257164377","21926322682316415908677782780651271296418143992951242140669333853524196651550791759115677585165315942238095248665202259926831322908196710172430614105119025214257335630503025437669999913983711706588136038899659445273828713246439700478040835159160340698561744705489870222813443828218064842397944923370052922216","5754457071175683544587489845293686907907043011201277117634586034823723102682481416797638644322678990437144722952014219524636116459532887102442574421711554710954160283941923917439104490086790524867732174965599201440855307278263881798876048160876899649767518659709719138564406692039388354580428134700945993562","12092211838028776241659589104171530871546682663162879021595040709441315533009281721531121074352267605367428220205833206356936780077937988432113432252482771715800972139778182538144595069038108335726093597695809369453323123004738245358575254752814728851324854994599570495132641986548734573847764529380514631161","3730925676362901388924135122876981838026296097275230780442783542125493558453725444179353220063045101499709562402501500666351305539519078820158709388961049127112021691533244687823881536093848987262114496789130078702352474419515278601942301935963833532592478657967876315725379352850349741007987882312369355349"},"27911461199975428317243713592805462664201105618595934025692295820445616176745290670019600892991520807536122138744645730600101333364443306825434077820716469336792681350211389643345788040599749896425574927039352087321237003099797132261191465557702691041256040037842732437386474557086794516689439604987081690865","2227632724034213655217007454583420472645991465287826368510751677594523326188228789465925806418395066461425647438723312382194705848570128420820524919296069267061908797930266716595359826988224435083747458910805319070564309556925491468290089004650329051226420947317623197291745613272180131379976671032468071740", libgDir, gFunctionName);

	SecureInt num("11797877055451618983423518305411010177911234546775098420928906792223091300322835340003368680676896643589340265996318858074441099160431084104919913259768577747936422823600722560546785921903733411595720111685530119572067731741510205276835416151538139259578325955908747475317944386854754077046560881261193534983",cs);
	SecureInt fact("27799061355820243940261661207627767437860300555670047639200453473244767802636739905023032348504483573651351915961012724124583912258632611493009825757840018157797741510764316634820693327500655093819084680331512167153070524536046484888654817676366311457023269859892086228545041352224929431108819212142434515724",cs);
	SecureInt i("329213418272164978282849753977329071514057233500030108779651641108087219675569704104745132656026896025521579970579835667129460957779107125931433229405052625066234275803292712578155590740287032690110900805206824056692865052513972664593907643444849721472337474100731993435028924821482193616955052830663253626",cs);
	SecureInt result("18252972936138958451017189591391909261281068100753523907327970172961898293822331542153809714129916185390943355593646903853099033550380969096464805658771513875167787292734809735002501645040623836526157730492077216598934961268695209576685007734156340204791490232647367561252661692345409064404447980963175447406",cs);
	
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

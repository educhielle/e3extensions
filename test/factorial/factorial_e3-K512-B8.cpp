#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 50
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("12038529750732532842944859393823752866044262067697078565955321819250405881994082150649804704399833546976680776868625248283781228225370320799051512943362397","8","42781323719159363372803657169527582827759360903050825885485221530981371716960042642683003907300343020638753659099749594343556827831770355675374798325443995951992068704333712240873828037494359042420728596476787870905391471102464782204778852420769100988377527382303475987131945490120662192599387580462992211352","65012572167616876602937712196088771949101500862229909677639720455346869353619677561478485303103483245609290361653377385928262581884377363789587955364828877343788103331881688409404413338333848232043798865348217497717041047640460226358956176697485632616951850018593581028364184100286952909002376031363275307800","116994320155073732981661574627360648323858754857396829435991387074611146247127450036520276994494538874180868715778102750215646939576032110308596242044338619764559012931202806319054921741555098879854003743182281863057834532888768415416195856309679563244400604747403495040111679382595024716630018633551627266367", libgDir, gFunctionName);

	SecureInt num("46762272965442602420050698675395603896842726473448710479479084927870029001473577599435754959791545326832132055576304265742081660228516359524371164646215873453246495309149589887399607007514480799018550248560710485914946807254231642345482772772779855289837329843689190114241360784555629135841510877652170216483",cs);
	SecureInt fact("124991914931682357883365918857616537151275462960091708284949829089277329013957225222273852294934977011747886656191196762076094656178465267985085967335667173034936715642987328715279534608706103897330064857953534701674432806355962895243561297674224903912782406359593834852323093179894750210174262934613498869317",cs);
	SecureInt i("129043078919359581902560993068352783404027112198773681176872844575243828269014319047529419476717428318073518597965948971866776014723315418621430072261313756004892816446781944609966685403604575402928859398402246201106331371272291638145366149521545573868021447874149276240829348264568299985276434127449221862385",cs);
	SecureInt result("16521433590431887901846076712283783902202589747498109662043790008395826528033733036032058643386693535729026500785781825489566448729592425248648038268208188895181166778027684874147548713952254635671730194669674735434721075225525050764164947154830151225631462816710199456824025867636323002102846302102983683168",cs);
	
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

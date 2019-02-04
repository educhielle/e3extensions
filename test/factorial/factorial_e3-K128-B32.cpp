#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 10
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("217295347376301507455588495315190723973",32,"9536401919020051611669666405687248520872630885787559041171304351597788337540",{"18858885092941053788368008209156336800997220427590378218231737889218257839954","4129175279159235702443832817098856334693384108812885204342671507186249659945","28474201886659879911676531976510930211906662256492835576113901344779387832495","27633969782140680851845516051552353908928040041864177286036212177770913453258","12751123103719530016566463241885880946822824122875417542077336082785115802861","46572623820866082594273901600682344699698827280814565593403887663847398841406","7823417358506880282753977168978871058443918014720536565856590464263745918133","8711461738191349828280409153810633822585981663453523047406509127893597491357","4332187214795821980012911094179146902453144279685245942005755381915566999658","892729862770065293399781089526678092040201660327762791549391729251326118777","36037773154178045941660592291038653890934032307987960532078791404956715978089","30543559716709875598929453242692555807873562906832178920112808146623953816283","30792864074618953881127188859742250762130669282361054634126207143681596016816","11879796187517158637670361729616289975583415787795193822307192426914262232659","17339276798678100210887431916272978235187898945547032412839809779710084644535","17607866182896241660652794151608495408262116866221905885164637439106535577142","38218235864864186670262950518237216638755901770627549409821827613845563593911","33657770838283675741677696169378186135540484982881755182514547294047198376693","37083995577462987337305814778574224322204127706111223376530869823636848928958","21827653075651273870951755469582677340221795179776113356301123330870332724206","25228237557033100234554775644780412646725936921353042946609248901122327142876","29116132473258894705790745051726171116647474603560692791038005916768008831487","39991675508474119161620643463615983815518602009578883955707578957816751062068","30873296791683991545339734168167872640989281635782252382653261973171703204142","14331482915645482956629462064214040786965007386620594730096498770333953042536","10760605667430257696535483158074418926164670500575363789625828484717705794105","24042375555785555529602524391594582729631488799165547484578371974396848746265","5865970818649526936972276222400066174282697219911005209175168502786634057192","6590348099334940052018826072821881232961759117948810677551082754649920780383","17942221495741481743085099098021535990451716102158933889841887013729122335079","9044446825904735063689869901934105709372586642212910893759346048127745233282","18749673186309065719410680470433025875629504108865940724719456483331614113765","10869774781428237629323327579733742257391814514536578200868602519392362300487"},"34085771339770668028419211501084373828757563101738789020400044375019908725344","6930402375520143949103288359674004608532391355575083338928082483337702217584", libgDir, gFunctionName);

	SecureInt num("19168550007673885739412651241310474622721724783622357088906720479633007633559",cs);
	SecureInt fact("22425763082381982331619385810161358771953546189417054753704995476677512007918",cs);
	SecureInt i("41288166640535459068761834766607116604308923730729448998079132275490007311719",cs);
	SecureInt result("20974714204671520828773014211047973985414286079998183731477074140454187748332",cs);
	
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

/* insertion sort ascending order */
#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

//#define LEN 10
#define LEN 4

int main(void)
{
    Cryptosystem cs("98929279505402282345638653661370621499448357914194646827695841374008983141586346369644986241367910235265849745445043356929868281180077497509459643273219654127691955755250286293625786137594903313890583996364980888208120981027976346754162905140137587364617191438597389571581160571461352500340003019195115296269",8,{"5089049802217813483389186853218457230121435227633548693883819173563880295620721870090988670040003786311841809088237892137860800219245863234483587342472483325781124487942140194379207164144507719594091230299028634882637559298467626826746778580625937099214745964990575463780350679153185071778305225095007764123265207939322858892745893127763219211415544519413878040258607669701902718927230197603880535483541019056374524662327147633680020146458850835926892687520889724269028975637649800298020903078550014194326871916025654040317585212040180717659296008797907718661104889284049603435594935986700086382435812849656316618687","2078542068737261341065845630020750502197544019562658641446620257037292065420835859891269160871602402591790880095919695573382835896735473713581538153402135170046503033037641980657228484813982974703365901625569547821614555143674475461773934471114772443113119913109269581116126143577532908492332768136618602926524220232448795089775466239086604191880317053736250025765269356892460867114427970645788878846860523839064800154118193422758586583091634911800478959170308419452378677953987070927857477887198030624216404714909761122105882678569970750383750965828868560192223969575894472235494077295016116820397199200028784001291","7920357710382317091957176741504889131383293021592159204346307640089386386472261711401980286458987469094550476080005600692002980921984495801114856285029851920335496400809592605594862606118779268361678103639415131007306035940072693894592796102936329458103251453169990697946331171546589672222844353348916470854686250151529589569362040572757101182051201649487121757505877346622642190737646883485015095417288789558614701559430953330646653961817085448462970146089305505598579829734385367137045411224440434053531806864033766281884244794499463465367250850979944577652316129649816967750883178432295364631642804083990182858659","2741923282594788408467118561179804870021271957149463434920996127675000254115359013772527199606263577072200885811436794967797957904322062445040054906083804285472001141228625033935904303618531436331891219965332925831452633613894140346387406361426917615500758972264556084298142107992954085242046986813575998420635867450407965540530586930904714085090343508910126496365779934123279831890209036474040500344282885184775665105533163427859612645018491784255197303804576108500929341666796302550941168879585952927370302031126052392146587860004508055510197568061877894762871896375107151746270993156936162079096301990745902263959","2891630236792087040130542365738620209420564944102193001367374238952545389460659121605225654144043345721048754777924332468185694556314601255985877273189838467190585622089040883071506915791859091474519153796121360279669109758902189152611827341582732378071084135827672474796802463087662754544973493353468535608093835871794880600859955694841125969973531068576448250652622071037423779127676458775699776209633088893797553541162225421058537520087019201756815556514413293461107440744510073782671238674758120021037275340590479434455458562151269485740676444901135296400957917309209645803274585213313302154449274812584199982721","462881439504625252417093678690235434241387630341939874811943044972387442640304406286629877102606055169813327074327903135974118983156304070885913590959112412163521245722338961243598346328343489426933710008459859377615658993072456078966028346905126143910534231468046322029545828262127398280413387514453677244738077547001551315615146661789213313763521591669763275246452148761895985525951147921007147991150586758083726218158634038770970269136431104068149721447803739490700647307345934870165473317410852683096265486000205244812371103313980092654397574561715948895940879656126382948615533714295063531238674225378980851802","556579813051029926705203871285642165364793391621341574281792637874610727869822165219084910799325652884617524861517914012167937023545198321082799850975971054965921460071129551892378203494084347584455694461544869844610780971083281225542580132934016525521373833998126300451511977860846895195624970032594416350780397531374243015393093619020977870926451723638873516220837601223030247051080816786368016927235805303129970500155504716694176622925377125189234369432817104157921364666566992448371151142706256710552483404244196176837002748425357249910925014695008504888169866743884946936044312121806863828623150108498651544897","806212194811783142083501874468774358733820234893395130686202619472754796791511296502486454596259564875207606985298476591569455558251770628266441032948981456764063396375746429037710994232601143680514045916396832248938868916678556193740920485660153067309871571748707583820663346213259807625241246153086148075177677552066255650331928863063445703250157276177125194960585446290312203954253122683330237897323702171428966908107632975440367893874330129680588903989412463603193236613025726340385858311072349903387756376436028349699194681699393431245107437725157341969598450941943079360706879771957181296643503296939776471486","589905022011327797667474044361501244495759048700847637633084982271746765838918173861461405926345585502438507893108700951451125199299953367003041529381727136641216639669527960604042363380073249100924929951696100837215572827718873803341821344741755696382150370607708516372577148912164616853693049488184858967136431823722592443205922406753983195389807713404125340710813450968181717570084809114093108190098513335357906017870658479112813029779030617704331068640379249033230309848286769689909503959527275059155470732131961231474946764024308126044364813051262575139956527413943195283235824743864818499444367491582115841"}, libgDir, gFunctionName);
    SecureInt array[LEN];
	int i, j;
    array[0] = SecureInt("6682438854109737270450466893542182625026616084815857182402181257986325329253667875880414140680030773106350992002550206813195061596076499078148897877914189729590727617927176627917039089940202407331150007218457303423612843710810739527836391102691758710206149905275336784114118495887081144519346293891773482491806478886967618606968889842734628477879732959760840303358485877397092818235304077271193474075809333274250181895057461762130244044933950040174816453357004816966596824794860251605072930565977440648207013252846675825313299562849779390392842930213722820070196698739203082835817670415923691496055700185697908873957",cs);
    array[1] = SecureInt("3425398365762538447920886017535242710401766803567317078264098594797608260078795206644239350167806304091886179880967371387027427428973778406567106060685109444632846658028379545455465343843873052969395015439681706891214290190712528711563299892890896588439917754992724087161283922276138588406320113370661123119054665822853878695352412534217398711726917651161322267966455813024909944444082781841829970716956532622780270849785774748682636625470716781368349903483440970701654608904691103657624503059044526502393580184131608778757383661407728652067495422298731248543412689453453956213588558603082330946537770962946478133780",cs);
    array[2] = SecureInt("7734420712220931317005849321340029177402914773655234698088236723001947108230402904909605136946509142438173191942953495239479045331655655541495904307862217300605693299397656824348973120439121752102360216309025234169753798626612846042610946219791125137208122769223627035358692124238491463906813731217375884876564089623737342230916880079895011456759111686632658468429956513537858658876761428082397254786932050791117483885660719274324985601981043994697795268256641863966382471865938485535262540540331989261896884181526147597263446993340250209558290582983482769873302813379926332886391552019724132760962067326161447666760",cs);
    array[3] = SecureInt("2595078180296768182422327065335942348857307797366093738808877754828930495146050718301497011132838107610528722114966794195105317091184859838946682733707436660208909959539602792918767248365010992642777030231675613274289125614532176952736764140498920723208161921917447695356968159234115504299606696191321673130417775263970819918562424676413440000748226531379114220049738075579429046827090567765216823718325368378414332756314836490732743559681130592342044096631604557354510330065954132902922597299705600039482706720675413995214516890759335669260286374003503319148349335384899692007803823391160053825564911041965705729586",cs);

    SecureInt x, y, cond1, cond2;
	for (i = 1 ; i < LEN; i++)
	{
		cout << i << ": ";
		j = i;
		while (j != 0)
		{
			cout << j << ' ' <<std::flush;
			x = array[j-1];
			y = array[j];

			cond1 = y <= x;
            cond2 = x < y;
			array[j-1] = cond1 * y + cond2 * x; //cond1.mux(y, x); // min
			array[j] = x + y - array[j-1]; //cond.mux(x, y); // max

			j--;
		}
		cout << std::endl;
	}
	cout << std::endl;

	for (i = 0; i < LEN; i++) cout << array[i].str() << " ";
	cout << std::endl;

	return 0;
}

#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 10
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("98958910092559363189975929637817855221955522936088611150366243513795096238694559475654703188139453138490026435619980139703078052974691706524214825228614092957505093632030413610979827279263406181154733041024836935939162097954927556575926011746245312470677913462678876167814658442671068731800515743476512968969",8,"2529868531738900516049488436340656783670104967604668174094122770652496985175757783893231662801775743796570038991474757313210834933804974880766985465300408643691335335140482707837582266718852997310363880101758611862940232120130818798504419661359814627713927388597459075998517478639407926480583431672929416247098794674130985181205159350203330355487406823907127308680698360240359898302889230726035190951323468870653046876941969802014699111527262815881038591495378490494760396781441456124317222843144582885145513593505020687666375884212686481500784498362215671098062364544155241213408308824435339572741913749530898380558",{"2036121611070714658415592860213653764819381013730569127848693190769495472454647149077179785432560198180286338713270998117939978770504750704739482565748157900883046892497928252067603929378424833090920140544590621011150738908067747398162158003051669908852421954790434295702233005330583644169561616919798626077504347772349609465705658783510835321280585156916309314602002919652743001599094955355651930728695244597121735219642929845705170098326215705896524617263721748068248764473896396732309457713352827489806280727425682891742980307092385892755235119466288880594391163384151579403826236629558961559653124688238900105653","5031092244394453419157878459263129242808945954814953309309667978694139850835611420387293308987356859823740121531071670341602365218851899434582173337489668455179923241373439076130400682487580523427290828966952342580118542005875432642499678614745791490639801829226085177098615559630228795678351328144077566242947397877469688564610615935362204536364878834518596022410543222545678536602173543288047012333772842288281515353117568563398733403250024640382890397711039395505433961620337511689172146261427151129364037693224419203141459399276775334387510882486107582405354445839828746558232351017599785756827861813239961188093","5790935949243282251943844142980563483870260026007195080290701949323935456407753511035148288132794791030645891365043634938252056409092193696166159342442452812248812266564831416764581541171109660545262981742502569671584110714820435090101125947499385131098652519306356183014621465922673846213861933694090115161824457288521077658846462772412293265410987470863030161582855712060447372894939804072140365325451701486809838508765022629743024477405817670107096910649898689550602165126980849969643544187946835476678682485434643904243879143448642522365937771747433488497690516346641560730560725343685513688637996124908416299603","818295469959343786612851043475079642535055860163667375771772129171317675861127032875120196480786098908880050029172243129073300792490047190961865204861942106251747339407190128009154563493373363098839155983053974306046517876982488895167178906643600142780696031039104805105393020036476574627886890331888621149725944593471361275045462489292664714863742134892871715726374933887194370516263247242407835027520218507596048244672448914397364091032557391751594833866919179576630554482458644686684837497147053746545340981218678801289033647728225890677595140817180840718048604654868909275302948217175935475285925898364471920608","3592756438020843352655875239515798889069383787796770558911565811010159526579470230907932381948520474799794626258187678894067533462330449701540626826720039227236904259380340844437841123214146816874495162675930541383562285975040413394614290674361156337480085685341380658420006425142918908812956707107335097621898832986058543446995163462101576561084844792019116718376353425818960707464491333709044376122006113496130260266835925176594022700620471482520494009911954992814528296253555582148496463609008735279291318852956903130617339208277262248170486545059854590746744004123631301256182429860855856223120422517737776547186","2225996843586180124008365922107521148062195191235179783508119399985897921434314861385789700321816805328458002382921099222406965673867954415158620737934817398959178797242101076205291549496418672945163590542073856306243188498454105492334612896871820883239903350766476511369460487159414764099271414119420002042968999320570172404923634166635365493688503862730235100470586919287853736218846079865257362535140522721302814941619506865707576712004169076057911516855313478825543003895095880065872111654741364113804444902302933382184758880683580516069244095245775448727610317815446498919294210116526430551461252694338869127296","9739059030287383718424446406340490158314318397969425796694410313515998393324831628065859080268138113726861453082478602336157698030161196375563939187166230259107946900134872174190639331020265454989408927896028196716171969061966117016696741731707484008462947362890848882257333424168769683686797838025946374295135863494688547931556252642085248655445530705625926395925093180021740299398993863525076234657811734745255745354607833566646867889559941072319148994176873541961813566990324284974039155666330645069450851279614553592183990980150520414922665597669809399397440088551748301385900153495085254179382538827729367766016","5417796089961854222439471913729195481059549234138842534189314901781026901804592577195277838629274247884105853417962143208914563802181201725117000343441386387646528213131777078220361273900549754271046347062934110608614954486905266849194580277344101873472854168272383983939291388471474694028772913955763405073668384446715778121427436178397964528359173623502849262117315639248138201677968847639758301049625780620144006320123645383909854587070252745839611942964969511070612556422315787600884173379294607528931477602582953595398391117715528119323594843064246902376114570864235517339666048048300929424325164579664225748207","7159907782016324465926732083313110994080521737671837858023542564833340590731117333545580315081440901551295454209576710562611880233480401903543273637127369164443971481970671204205025799804440857894708148697175581570667543844106828006625549841095991311879530530143409408012353751230854273288875874169108202087213775435786618435724344115870397223860463167578938278923928554374808231860149352602992611536495780241261509621027886094770736819884773338852842323768090138933922244105363145498381513921467506859962522071772821030941521489942366784761240821962738998590057125831062581871402853703457813132423629148406989961463"},"6716981051990447093390926571189349203473524664795490566695810096900669845806496439228435366422740813998272671021877837232642947622468557676682220662122569044959967183134594178781444794764716871477449771805254186716512902062329829559472976412004965127342053591482192517055120459774151259768377036112271196951470650718219572701683360762033536328708871939952489647202488974323376868776209572229821586080967921275044896877833679366804301584974570035298489079846314279452053179749249051912678414888088227895918790101908540545134546411790538705222345010314882721618199775632370718922357800035485395169717006734077074452620","8144686302561319193563161641516146428847813989448004818817071272122584430342262028444317220547826572192384743079141200728400300939721089003374300041708051548185262120817930241120459735977287957589300386096696945443844543046586290388302014252799097450059976784735021399458659106422001077432075982540079525550166259239041966870445904595979671158839361573427090528268269936349723396423307999924229082870410750763377743919094192525746126401881866060303023365781388304181707854105786390443920575896051140638723265942307292892627057638313980023080241232930444514418550815355880210163682254251924075680981048242562624655021", libgDir, gFunctionName);

	SecureInt num("899666839156429510584776232912363670341759355639821781064920166018525598070272442819433708402632815393705657696490899234433981552646131288005822840513824480901887561353850541131650994935173559382746798472252555358324230465739401030095667358417709326811007656310201060381001051930631598232459382821273723016277495463049923861615645299753592541634136027162850133049694939332332903158044118786388373773803242629690160103038533769376704911344654774425833916236043168815328477059979744860983567643964393598546841983710640139577728463058750575108662479435543179632041779140364287955049171782941183354382817206567539569021",cs);
	SecureInt fact("6589807353618873950493645902090295497026534354818997060000046575111678361032533232558162516344632356080016269848894361170679470012656329023206692980277977556493637127580101960018731919193605357781982246469850331739365016285260024298426311601805070382024521431261235388689119645450675837315285021392255101562784983254937256984975543413762143983328329720027305484582406700346424149664175878703878620340503263041038358859943972207643669949095150004357008920504262307209768727147865378130184772278649320513582772299555443079934282636657961173946744804210964082362962770874278810864316101655242011908469551473914009888875",cs);
	SecureInt i("3326774846451840164261474153874277516643987146094117114568671548757629201228023669787799313185188106971053120155672172248762579706765970009514185484117771317119910168880963795589046079361606693603744046592494376120504355025942731190359611186382814704739454904365167062813943877796546499797884607877447357645636797051608484005531764752308584134230444158640245395291779791840084954862305056364432889514262191915328454689300385028127812896384559373330825441881196135645823511215649510796742091762995649284344654361771717087244389926454744202281862898289452009002686464587037718684599637832444548237615722022800725907727",cs);
	SecureInt result("249689793867319496148075154727300633614523445353566765850711127679476257247653509425109469194720079711526468769377226768987756169245438781146688549230631263651411169442874679921088136025753492352588293168472732325930984925049714064089935392201179688689686905470776867472359036167771105036592722677197864918716625215213650922502548026091439649141560400725130693071539546157138581533782921619825621382327511603792124851306431418712917789649433334250979472177548137920420253096102308145126263432093211984284638212462413289776581006726834616194726235410156397046461735287916777110142865707590347373553261455862014006435",cs);
	
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


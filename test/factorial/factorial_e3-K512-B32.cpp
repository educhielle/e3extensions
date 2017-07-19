#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 10
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("6750731632692642095536100092238374986005861697330835020195356863003811903614507249945929148114123952759653076538067935699727196441700111169224409260891241",32,"18906669201680241112234098586338149819106044478505998852814952068870141573758306184639633282619499644354860049825101580233109865187910808857499305858340924583135831806082479575194013716167652097535509529113408252061290297462853194998341041987139038745043829887859940946898111323696948743740518270399897689284",{"12676300671340201229980884444638741578462313175855453903810660934141578293579566977628658700960595276133997199564357796861457759152222094374962082891792370883222014451557452825384705507709510444634436516608469183145626825674063420007923976243457513362982012242914039507898053732015016012413031533417966156851","32398761633804610432140171877252171415913416801546336656795709964252360806813932892364935864395141466803030069868385119317652347781856588070478106173311634539019717616363616489944658868181219833816052845058101359769421746999989785975474549466871145603281304588179202872614487039256815389398561691412143048800","8196719627496445740103727755864785306220655830666592101292730862792263157302102439784458743443890335458770266322252004651433605149726622322164160078820897494065818336069326990792252586610044787518168792065245246353662818159518840556552743001923502251780542434328208566290872609388033290406094423911360274080","28985918286599868885979152598562328495759932902408684720456005797863476905700271078627055847639290272711135765017796811429788815288508340043366310770668615293152557364580164109370451491320643800227448883230053405849551216470434399751551838671915660057898572395504813038731672862733400182653400933543434471812","33159649489767593256696008904701197675235098127178469502534271425363712296282773882407552715677136388903358831746017097621745906871439326760302256225886222418575200378543131411868673768931750171114082329645157174146660357725624691221910871619223205419406069291686050778541339410387853076948470983307962522996","18169307030016709058462933757675631859750018726978264866434484240146870226448998083181576031053405912746486156271235037872957242047989792026421621238500524917271723786093805054919541994907434493372227123513461342404465509089622639807031696272315084198736051167005445177859676704862172735576137219562876608431","26784148542972345689723543570692689243034015007125687324428248606697754104910775260232225875883851981244961266767121883356433481724531337865322786789955565889465634996525810593044167452413253830069266808687691949975666139685403548930714539286227912259323754970214153252452648041192541949218526657081684165356","11149818040730432402775280794156755460026157602743860561977854807301943716300401965856757256963426554999357884379101645721089872477130193346792281729480705413134733545583663119207599904432242410597468060015421175934617508971177034604694209657369445835413023463587968004402300832896480659539156581411019999255","11620257222381995269206131271920966851137553836763842718277113359896019212771368370797698923288165713084164388894189047710379247386038799731608824207771653267291666619898403441790808326878742052097253983353623504349789440602662262658062617171513780629988436253983495370884053727270700149447012156673857903566","36941483065340722446096385092786526701206595124721066702341542799330085786938958728300849331924044102271958241907489985322960556131270927359481588316030645150545155990082444053297530433975790447883475820340081629945816470967109528398192623047353208636721935213250610849689677823924152668982508222699838812872","38080596556676032778962049165082221734536866620281312046457535920586204354743944267849421158030211180444183153606525407418553094473568208019176075268199846884795456372736028413890783990612478692372435947362803966332433768874622507337546471200557702440778424086679541282106208056462588340409315443493028890339","6632003938848927975163628727504207868305002767507372915127059199354352270330149313294064252391961696810539931463269351681224567036069484450614973347913624383939368075575920562729248850390056735849165302414186058911767033856930217540751695542231117896288568166176411745734564315549662035744116880013021936000","3839395404210912849213731486204634675296826967787792804112197421103246775632759527270635765987436821036675536411834732701107278919512763121663305782729870814441767064559711190968176481914861126110798392863885054286822238563462119940360984629162525757371495413849172716287790225310632739139638500718416895715","40778343212409684031398023187332298085157557751190501375412128838043330410420814854872201886731746172142595666240471716512628524194599114116050494149271302347640110899015813954429710737367534886316162490947257634086875863976403536620939773489120223384049579110212036560745787379019600937241636636232284632072","5723856675867214450760726913229013977075102266528104098736012327782276789572348625626445894464861707772783758019208402169059277782345832849817973174056578347559022892336275222419599299926734878245648496709556019012963691068211282393889053457990400866763411184231118275371960126471913028117905882491419822424","43728158549494065482865568370183502153019092815061471689603741981908644961970410157022732227045523367767725520568998801996734248149096874179359014944081057314269309171142721431755532463854648505308768874859056576214283605717069134986109801493694279654423329224386944667290836201195557717109826934812840337650","39408994001371302748041696721394322046718270232820705080253510704679897558270752136960622124817119472787865224542115997625001609583022312513913925600986456370016151140972062907308896779595521780346025358475427385197586346948318048936400988036876385750883258687803750442420258478404037938559378975512231214956","37178816781887553741925626950494613861489919771337099835967870742303374960512573975724147507920194863043837448660267299602023550229341752993305557334472638623988392549043763942288682800261769510763798036247611159394221626105088937778641885312705700471420336341528920659275901784686476911407019894380414738372","3489900973516635727426275965078370650892784186215334451104519612929781431245743011978383393147462634763733730011774746539404435662446241926490318114380118590213892492951510255041034640014165217857236993449245809534981812216077988497246756859235387621078895481125225756367731273495492497114365194641845674365","18559757157318070334573405963392353901439467913661705048807772606716832210439970323435108727592718210820029556025001843837863128034672894537440844247902808659070766061333467354183343318574867051976307477625019169988920766142355517549726790300964301091743762575380089001057364505542751638759104048951086948795","14247667839606745678552580228837471089606496697709490091502024430263526781403982569061265648967855415479777853419969273643126872020153761805572720211105687064501746915353141897842205180716816297985541687190282890189082972385360428141859007619349636761558906037914179285756134940779575612288867434191822262780","45171289951887900727806520403147725630108050013111734797677130849045061876055194880981153474777329183317825232721535169317622225597824391895369650031234313763827545096781928732299986557137009500305451977485066527787811009935244679279270493614654340876286696104325737964870281169592471403832872136320398663065","21739180395033492089623384169581215313834224717782610694015012442519355743649495495760788278292112026178247273857140753309861756192580337938708542612900865654816985576468211665445289814478888921209534860846035707979975348164336832815084109468382544496858008646392106424449144768653281940438572266066752826045","41126833348985868600234957648676826902006895524763693686315024944577721358062083298980749792082029147614669823780107628912809725993955211954707717284126868313587037227151078861544342459463295655178259540607851337165342343611322286486017710926365587328259691452847314742788169246830325997669761435048805458044","29964094536915908602701537107382356197362594615790370311505752384139156393809283664064598375420110132737532858480833918700664575926036062835651276198475124950595244068499793042124803964944141706277833466156733394600030448336585581201415442488117641871001986306579538981991738647275127169060790402751356962316","34748688795767839219338533783338806303713768468791345294262836943770699078110829136350180127028547662636663785347626266327400963955632233143490373716794873339717556632080720743806468527679092929915701432251442060537054282907084520264425643898614569126743812834895503921680990837755728022952910388618901980175","28846991227170358884411806127817373491786350999676727120835500157287509199647347830570104170613972426520358548131826167138413601985203216788396676882687921327267514187162335991336172168231663745274029986238436663261705385461634153244886430672640205113932595163210894390866284129808946447089331416060139586990","4409269223034108761798218232933241766769427948479101477306844847928237368270186027613905921496312746629751879046685523356191364145319276964606966148934720028024321717917670981802351187342865344715457188693148531566554636022180627037829718396680062859410104262563196008276020533619422616562476970059744420557","711177270630871290276727573808631733192855297830624613558810519202548295276177548004899358644570760874594460926862929948649536318033134327756020989958921281991093870238017249511929863354376188541302755002602201481620394516558212171244554855491251967462211258496844126189323434703457822659800554507080204935","44391351174146236372709714681436266320658799324694656613689577247950644215362417937867852381669108010928706850565544987842290659610483785149153628883547914336687609834696413521943560840466622816491012211039710257464817745946785608279766907226700910829657062901948503833021599949552566045230155801604924989624","13172723430907113738734607192944184780343159849647613279276913129313410453238377337242297199728119951797332620254560975418040543164644269729510634904865094462302310878994875975370281402780102612584044570682792098529355878296317550176359922493967846482483171729607469283701753771463045203176267510050073200822","22643742999280330593494766715080490448244602592651859537280273624983933638302126979492870642743673513074957516606868334813868063613427864278161675289148381241616708206821933265851407385095125029005370134947015783106422481684602437493730838252035238526671275240781823160727409616383225482988865156364904187418","26222022244909291648259928366493328243258981430360906371621296296788055801435305071371826419283482291565954923813221124191750027842657312669450252787618789255891039212439792543607380260457722860560580710763860110924100195120398960980450082358435960703796238637095314863643134571638420089413278438046938490230"},"16141480681465012341766170373394911679172894895967005085893619999562651021511707432304029936573527616787076694002506012036572090765240715203268374284438224593602224212651400995727743650612811811551402202164568453208961754347948622865652678985498063039312741809684700288120916349971924433226991533046201407716","26018041605512890256619235358294533400787035507050361737425765238482227912058076473155493603481226091278690603477796487171413995733823560884279125503524017448051559488102634686446722330379752551051477928096552688313191854967494776065915489077220622943046327724927774473850772901622414888104123308154534713231", libgDir, gFunctionName);

	SecureInt num("25577463090556787238446060169976167148795797013931345751069515511670958346448658669009686357614206695497358841428731452903359529562371699706147453398489076186807272502682309888390115947898239483625192699658718752221350833852542269017385421024613968949606811525745624023783040109448007468256964125759431562571",cs);
	SecureInt fact("2267299112101995026135636325538038126243958632542524506045767295246830513462515966225444630442637087085537996855793583402638911868194213957436630097139205518194302773082420426957771487155273203095585291972807215092349479824621435510281104262678765472837431204385971643988602377919874594686397066794589044628",cs);
	SecureInt i("39515453307427146080633001667760812907427681066976889359180805735181509262517579259995501590045905581870048652838514184257933660687071293915795179009011812283385349568641458863194551204956893245690460635792762204912538305873975243560248739337378692283356576431327658930586526610420728288926496560811054622960",cs);
	SecureInt result("21176352393272665258910006754601623457874154055930350321155100791301176186285188987848377346211580367744061663263584248309692296179059665771773418188133301533551139065664852739627823211603627081104151160258822213389111281419461760434594201923855509678054949331311927913150201263692926213863139118855899503934",cs);
	
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


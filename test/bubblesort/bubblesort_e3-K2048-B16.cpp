#include <iostream>
#include "../../src/e3extensions/secureint.h"

#define LEN 6

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

void bubbleSort(SecureInt[], int);
void printArray(SecureInt[], int);
void swap(SecureInt*, SecureInt*);
 
// Driver program to test above functions
int main()
{
	Cryptosystem cs("12811873882630376020441514086066022510120616964605266214883971448311741272751160690115942627782679070662820964315373668684123894361380869093494057847880138645341224770908551987628598664677344042553562624034011380099195521857904525327436646368234884771266004879939626489447107448079644561078524362613051426571184416769006413665103603663738920836903217605433209229722871863102900525401316654097715769194530654012942853670933574718274490687622129447634946580218680532766944493671149986661640580640027361284517658315369131433068219303202905016116365149478385542934968460043693745447534931179960605210300836308147567138217",16,{"80543113996205144202342177055864486897093337799417471586238773493767632267031023901127414593944631401798806591936487435602566367615324340695943146415947607849187132749897357695168747340981636715821569282688397109500557775079753442491776324649050188339926202738844407111090907453898269286528862751575485609232093329169949667982622761336038644459424845508788918395727434135875898048350371014317477434976976733274749975616013460821961171214719189547571270203339742718965185574554605059265711890968690130260050769003430149851822862160281960237664759313398008947946004254930695971291884917118270475552601187480563087150589534042012118129096309453840067793740745777295942597944262256655882813615031320816478157271972859969239970944872822245649072755789969731983030250071750711769915305748176141622340373722044173416173526123130617357828979121116812139821153882419596615761313412986077552024550279921689213015640651193033912636746499953515706009648502216012322768743360113120674112785752244092837674461084307386988356052757650357251140769211784551081261253016683382566656637922743564776297439463563855026983865841711095719097758654376218330014936539470457186176254606723176256580518098163572902641973409926946843417744050415339437506487011","21284459065359693515853077836978306523881665865533149199251260102748096516085757271994120768166413774951233637629686224210071189183772613317108904216560130063858631916082487364878050278678440185180473578262810694097825844079343188039324127095912183862610002413977969782944107144666374839961801813231954860464414298224939353224268159678051190328622674642764798053774172022447287772204657816700584699588421741146074436597945842935896795187319584475537240992504495596656077735146181352998015758138279400923705231154555647287988552451020412504009648304563400816088550263434217619231154633022635071491636624255704018248536636496212383984397864928644842471459498685144320093942783674562384667641378144217846962883164383253200181022638189491671480641917900893881578082172930495373772368246317634759856900439859695722336555679201613514403938569279842365947003154302169458293826697129201031956616850350268657735665355639163409894291035836885742059031460078160170188806979984970355046305891191976968180153499874072616017323954166742800018720916294129752239679906754106074365912642771372889876065656371717282178364841876969716065544285424607035468954400933865880843851443767890463850366715812181085950081198347274379168407556263900651234111521","117082913443511320605398103231234349766553605347948344557339306853686477761779194891789680101100249812310704427351459155276340426483172095230447719798700935840467791500971685576431229383189265660785687214412632374078464714481637132394678760876412893301034775718280591511998772907382550784294902964107306768488862788971403812166579956353983502937306757053860937204287672783735508340459133137040997927807957946989055279168554099471466611350185610927434894799391207607583465415759422450289989909494575316281079672765208734750311356996694152875578490120036300625103676210501018278615107214805716717803476187743692622460435583221330418204052908734293462695696209838663871187897102569900814955515692235863371978878212264483133848449317865888544890774229156246339714888494214055030368237223872562388011615326572589813135484774208872662320298706461538058816327523839252633567507200136641925914792606252751549622679769865106194472521872736995868830389919421034781946941536317746727326543846055741813153266017106129386888657817156022816048136603709756647113624532569500069867099936316950371283860077941278529451043932357582613290647841288714507741917842917956343471607637802957617095593609502675974360622896492120420647751673779193364268792076","105574303996451645663001576424919716511855996650028552555056392859068733887173018778567685882013041538261395186540080356381393474252612864645535435800139806491556583886899820407089703106196004463396049066193190252642967741123058447762854442107783294286115625673844544972229334305786689074899703380236945542933309577851924457709135528875608916658723471515560453129923675073045576556880670066950990988117455189670585032094241101005164972449657793325645459663439780165448695474349505649774818399081158247303778726919948014230602640905769428324011488221905901243494538415459064067163048045734377120309790809228385976005856580211179128076449112796867553310458971247245235394730740797074649242324538125885367482182806171184267920620125964788415745479329123477392016439174461167291509886736557744501372944942885532327057423192704507671356842564374698274961473544044095251306537890721403794287198553400760108256469539102371239669089031696688390074858339126577053046552524578234754991599020413744529398608073968795149831224372658752822827917569192588942189786591213614249949299168338158665027530692602645988924451769505781772440517680277559913836441967729740515251212412158609422054328414278480824663443059932189668851077124187281693548553371","85367835302664482136343759676222210603148952251320398945328798457171639061831932423056666206871511121210503893484771526934334356424295260906620733001450610910984520313959894149491343912880432107191750485233731574112733694831640020978585008989692799786577067781038392199350669725854443337847432942599433598361583136500318245956308419148854074539254017787126316212344130673535674729886701276215579373269926032355112328808397076916481863915424375726174724243255230275878457494259755517622103252006172126308287263159285165117259447466789579672244250841788934431036287367638902028095433381871893846630737027258600523228161024215654048465003895655367713943800703284996351207486181154834289469447102912870278941826637475655661138197114023660866681559434409355196130377756994850566756635614653570177585239874171322654539639365078135932930158388667436753199737144065707372565699749164354002654449817226686744219239364878838658477227227799222954886165817670382228987001393473277910047162931127532462681707163959022751613290368128160267472331223086046937476332739698095275742132481720334100238815297158582248698928542574749364939164887847655078234854017341438353923918130662918611845015935439908015621951028420078118767470603093872074745201584","151911672845897428636539475046156117331149324123064342279436073779062056850784096426399056513626903824841151012237977327714262351813780993070930554578700308576193977847506159565082968510060769297466987092328058105377301016573758940669076580543363517504993218764017553791334838468197394592496968803995975855932937975742518958648771380665531521168014859494585563645599184065504875777301109042570936029332230514465568878819476619226490305353691753477155239990398091353782876385002208554574392220752475810867953300577915594286623830116832543771367346038462219754241687920497112595905810442749836057859009366197313022645708833741577248110408480095640228442550358821896962741205264584910244671740442587260630488491344663036733290398070086404624243070259310516150842624173884739461202861017117609561319875027971662227560126606644946294475590685798774535044905269379085578227145237414260882281168007304459856131605414037653298738775490137944642623485444197266124614322898711621735468750904605437804574422785676792508887852343675134396014229691337008272782830734768835171603978452007019067404230592841268175454499914581260167732966265201197493540398006053858881789833279043308201298364380300717365529570978457172012261366752183677397357845405","11626905003259084862028489549496290430818450509195167729943122740702033495089376449224854470418008423509406528269182954853691789918684752005202364457565712138557132744466342404227470315632563207780385528464139640096074418883634735577681392864528629863035778271782713567840681573846421767479378338548295651686874784387681983544597260685010238253686961239243656558499708106149587068492418375656558224470034977530915862250633939769578384299763240694274957412273562921102794102626960744382899203388757866371662190048403750268734553057837434029263660817623707513551567078437281081272669263459679071585791670901374744698439854556501907710437339342870777402189588810383902084105286373963482736875452935955958090735252119044832715395019731721233821476048802218893043868371071650884760750025730080742126684061909428659192799369030779361622784395442298764516773904296992180103659251264810166491403062926853366315753611936804320846383564371225698984676277246136729612366017452497215837072885044488878071616253618049213320621036502413373474437958481588430325821342096152014687861843750887169380960478715887126093187724738123584417855327050250900479661333752757694504771443968759625455745718105961571603338980416573101933814531469756619415579921","113745329195819121258120294747345063798305975239339463501797521950519679840419833053904372381167678405906296615109049219280953941245546550984450283472150509893041267755558522637393347841597040337578014602637430438145041723148821127954554041161976408173788631825719622682597328452702755727605645808423724986437824455917470382616908169782546455345683580538270292118892814879560515256035075277181032517185309089933982940091632420902382726194113899215724058623460518095521165592888966557006157895863020325458924153433345602345239937153714951037262706678819340943844945618593678710877737146789509539526186237902061920703254509540186466414046789615457354472495987622012486351266097206329029739120000496857334853598218640895304414694211367428648275472132559634277139265861111868841292160064924041648646920540475228674696408936307211906751542517215049270119982508257366420145845657386885467375395402414384087187837079167755122814982534048491829648027585810948627487636242766446480347354703095582799484100288872819055723183788754884080629328283094938227820764022648724691290341081774136619298320532079138921660914246577058090770359328436851136754553137505383917397586189161786384996665929482512207872386482426522290079020113785596936505018948","91683851191294105929111607511868996900245102128581609299800805213635989360646514740303430279640655017506162494432255058856909972230520007920733400513363245921906854470104621053585946870341181468182193660498932721521008999652988781613813138098725895618610891710227561736850435519807337417676274175565014148723473457723368959986450241564929095382162053338914455324875625838286266554290950119124089473006873699043163592113918353818065971236769488056836113053465610159109373124934428142239956053155828462590599660844060288448500838161575231007161599662522185617052335627909713266233011561019064614057493929304422230039689191618753203500682422557923399276419934443076516290492072607458160574682205884217945532232881439517413391111897271088137341036502696376551310444806199270808555776905232730284987025576897976705892670881229435506313017141413609822598795711617461301370490878116981229582628944614159339757682270116883522288085647027479915056745948480057134870831021092783141942790788107896066237389435860605204048418954670597158728758344148806258949878022275699452469061589115032636360404826908649333425046451262372471751728182855678133143177342157312569965554045019762136744189313007010966622179348039036039648808747180761628861613868","78871356241273409029940026250170446087532402121385773211162517502508794009114145757860905684073930910424223124452750140497709307953981770480064537419599152814865353927657931886255695340655580674526618689110494701327469355321203308333355676715112557731080384566828076169392357320564237381191511358088135105397634556624115869519418611223609363940238779271073055270709004830071115562631975791838128011698626432828929722544129681178708709545770935937318941450327959466088893980512117677959591910770531297787188830344151180901576398921541304222747393087385001055303944538769021431230394960544702912826875033871379550133973705445347858579037693118670504651293180470141960454420196703497550614358903597926225630335412551173965026100223754081715845535651006053990149382066706849064162106911294783987468716692185713118703141552461944091801928713630014705241668800881723859568985887390805429364270794292626422473520100859751945930866843381570992598511242370193222675008435282404497281890222013726360948610623842661561498048772239780327356911611335057560073894801110337223262562252688674463351451184522314356266613181379021253095354491908422560902547509538792331781161056587560848983132354090617656891143572720866802503013831983633258282126121","142600407860359920558973828080789551869303890355120779684697335317507688464223525519329484076149189749651744221137354410179521800209007422257669897018136957267286939780420763296588620543494219225262615188485216134065168893808108945986292522888154748301853452673761099719054342107754758211384715207484867631657018288917040137806332839871787325085549089581209657501934893270424097683078328118570661185828473307031883829761097645963795472805191106353905121940348935360460433191074036691906965769511030639155864000976410353042785481243187814854304350157904296578701415565871389555177772457379284026429685488705794797525519954925164031241155589215341711772003315621722570145477074170874859286673527704582938670891603962124798596216614679927817023309444071166301842720512171038736322733205437382818124567205868914634350691425860668532393723613314120653913945597700860215577017171277719908123619476277331658812459080911923096195880844287473836994440655543121070206250271855130331735175222749041726035394013252001106597949628588292624254215631442021041541070353266007046290582605032035608884721890637978275627445952936609527483882638243583552166358887837942401759365812783101324960166590299263758957984383700390946084202973144334319180050347","98404871265473610139560763072317734224147236344188285614155289757857039982102702958309632155470549557590952563974064095713718137616934554920513307932407821030257215420615783107069249095628218971328977302674078835117705995035315182043553401712255112405629455721279610234654837173200231822317735240932464621225490966282952312002779535104673989165267321438860519503836337191170791655254331929276535719279629479794742026449956924539140236704133603231005065956705354173930870550041320865136706174580441457479556560570353672319331720471695970362511856296684989219301155138694512780909781631959616678912576444831674514208989347509152791184544258916465133744693588951920723361503450619754930950964821899734261008735228352512057918443721593141488255757177198495822103617098759004518010754336396970072366516159770805364737312387579458032453383387122215435057755081368487008362281202658646370467544484057594361858183868803379554235563426968070523059054603173502057497670876248872925457692549245196209249982986456091834447501172045769903589965128068098980240835981684523028821481781303913094035377008595354837819081996867457948501137652303210109496386254730096417394352243202690203895723296597791279628145289157375451751871897037909265240477801","979261558245338239659656791664222816242857775123540199521981381756163104396155795236333507164950196614216023365119367911009663342694605010279355013648820672780747281196479130215900324774059872868118492516593053521451363548547077900178506388175716243478960547812221017408680891761701242526882085408872401505728111080659472140318149063094793914606850086651437255454395775653671417013114443159885332273253467042322441977774675191278733397185427879441507720660848402446420133850291643097950601643705134404509153097899256926627219225024890457190568234340559963627543637122409884177406749838422701369858469654617895504559995432418981844920458035636225052472066423686097588157797247621057688748275526049837320989034286991318120098258913701022101825483149457902075910361474811078565056109859303712565507594570984763878318142727401958217330611003118114798031997369346500121597166572371081932931379647552365618690923907175415184491048958166663075484628780124058850051262185002360865991881395802525078340333544128649874078154873739385156421951342717566755986592630317292928856536335999738726282825060364837574213691044247094916098956983172077021090413232723379703581260539636716626776885768343614759277512626487743731584373905912228867297741","64645978152562418805719663538787989427729911895820581709012352871779503493958119989525031247873624019193147367158609453232641737678493129465889121744196815436439955720387841267159657758929851215701902214010604177530836950546033648137780188758843201823521206274631298638108521282517974031060526993230276867228063877612276685307530844008034171997810835286240300550750055482619438655605450031888550290063840560023763050131383172429074410456399075106173999090742037299035652902616285481208622435044806594953572351296446058771803493855003462056070609722065043975951780029673004655267319607431408944697980890078115401873728248772445050975215075166907615878289493352753697399932110257286151552715942211032972050941546488239803661471888506077589816557822788083460316032109416237001146667454630906188889283145547155514403224892638223048484299368996335889663075453744966618697322509478826281048426010614987488677997953880867464614852729119582749807755286296459139652520865378030181901699450880876134353691118787530706955470477554632402797471272319346674855154795252580819497839785925364542496927137071815701993900283443675438019128092948716231627458505704378823349534720394963382166919626518745753383899514113166628556020841675248676260594105","116304846529689917731321463552069546229112398669841354397310295992607667324931991603634060948286032323321171569039367610694533943130399556454274368013281036756657082566104347684722314993090645594607214447765436738881530225720076773086992144504327627276213614614986653950103769671924073788175454605751139165141615623611960948493916869512489918585908700681463060999503290315184068320441275925789442608332058726075962272945454454990947705748414717379093963783347823068252495200538380418537462892145977304714837517190840929143462752901517766187080395459755261732346638774778922780949730429917963449310149759667064335052644306815051030473883290438513009691547670978244366941574033468893625800990042474716909698387090553975419860115670361797950707984436791500713099902146446981151731140803161708841917113423592638416223108360385575695221566164184624992732589078327331037804725167894203699736135935071844244322212995402761154459995094676753454545064849045025428865255717638898415355583411251909212604695324082078997964078857160363825886613022447146263132106490117841934413166410603020316077651977643035026626329531253002167978691631355638037099094148225345039154339745379439875321557365296796592725283776006815717805566620969655919282548439","159927153333512496517247927793733317287181716067695443454085473824281347960037130232391036017324281676073738352105414407836098526082706119634104393455229120877285026894066287573445084090931966578772113774612052792507241409384376054312620305212405301614699286762331781888006679112536299345461762863790247100880016802098257710326011505352477693376208676957995815748499058958744537880629148455619802042468804889134286969604337548706069714439589990371927277431149820013688845331332755925937722468301906398854340551622275305187337689367590881891974165310846295876120320214376337001807939455951290665934788161842601770333817039898925494091698328981982533479091637611562775007930005035210529274104712968630288072985013048978215134922877162357022907774980416220615003592225176087751643773981612764527725686490106138289204268245409271384293265852641285983667312928941822472164385202697738788946147130372829601994570640119896482106799247030127970102300595213655707517572851197373271583363937488003787569582615945352768075472156322733602663390765837837462492207271891583204600543882281788099004625799601482094124164628313930687191063618038223471222074894337586572346015692066237115579732059703507104951769898074319506389116966737893442247220930","121153194843268517487013698607571183882998657660131311682897030134804036544729300886707088494667977455284158543282607560972121973218277149127384763450206755617588942019923810302950625529823100800415437949291635478035949376933425968968487073392542849406159397312775162907154950207370169474538843364835334461400606353135776866593249101822551820650612461864426600586343904660792279303424814770996155226182838183694821283064937346973149972890838926738756616298117793264010269728095390248633272220323001116294085101754575453518465349177922347191757478307783115014062427658947668699997471682709448344608018382272797161005959673482447512372736896217275533719348939521836307677377666334617478095789475566590090428472410263778488339052906687799380142524987945192773493110912486351796131139935023720987574124815178208699325228977172056643110678130964572981078908400205964814480238247043313040334251198805992789410523500592411497053477611503617184642240487717654140923738144719125545974668212034395142094137113704393745443958661659410464705707989122094024645388313534925106604629181786729495078168285303636434349483166314460880745659146128362608778545745948999163688294940664084306641978176830447438568448749790848190477400323309202391956299662"}, libgDir, gFunctionName);
	SecureInt a[LEN];

	a[0] = SecureInt("141459404463997373860858081413470307114630564659794861624560780636441387515410204541855316504752010000829502389018403839601959716743727440925699913356969853718076758691664951254314134318401903891892087859068457854757546096828200987020920808439526811511841167162214741746922057784972773720648103844843293058307201110296516685239080862477480274199663935065653388813684874370954573409326903299367227364737028576591504431693822703594960182451466505938535753988565444139785149555414652599219918846973680271842503038951083156293409680597452475525022396181843287578067142745713658327249736193324306136267034884045083311206833380705960763962027588063354262155148715685994598329840506406456022108607268636428272886439225873135507092569211932272682034637438795218503673490291472751053088566632770003791027385080273154633706310050310571917189912105626261024596485794186444746874295518679110456570578808158910996121249587666503653014359584813308982655127339224630060787908562400145288757922536816214756449846422908342888577674058783601012224243336977152357869701199266641696406251265649423442465379183864565929972671489816621195460618130594693674597362715781135808215378616705302546786979358423698853342125599135780530203065830897735994272917708",cs);
	a[1] = SecureInt("14584336587463911034336542165177874913621311722036762758466132324406851981829577458301611167798973328814014013616610049009242186103675418955056645408142435450225882964610132773549565839738308311857797687154817099425041858778336088738910212408707812457222827823338053680298684704542110791721426326980577314439854552012414706538357833584811663482001221192336847600051118517747210814022909844327377046701120179128904245286992883996665974403104952032437309957340721294596892657269439026725319922792097039917215604709437615444557780440297427689335829274672601363150955267637454641058560007846381569202832770679272277577291591163100307515458413702358414836306429240825148997545304916223061923713696950835196421815616074095965285611897313503098764384286364022152328596368020850935666942920439173257560217760039361395398729095859775197204076336383348615640884117394203133769157434031641740491965841687012339392824133652553068935674594655837136691630571407232535753962359775162320717132209197805229942118288561869564412948599811664868041638456467507566139156236801450259912013969277978619519524614874154813975843475723304123319508951676979224881195770411049575954133209278005476008899654755642157277210140986030236365978306643578287186498680",cs);
	a[2] = SecureInt("83868092617111366077080869368927390215264286055826616109724217903821794535597884643838776424685619416727622734195814221826634122112600486673170157035437824646962942902225134628959885583256108741376228741727049858247020766979274006400646960222294406632661620957717349498560688654387587935069742088173664309040494837207926150925502640952669811469618386764061623510968054232895666494232205954512612959057868700614261394944014861662127946001796004666135519172577556657558066474737961858085571502106082016189754163669294252892226956141158624204185285372156190599991697631353138393470425224489879238976208009280148945942278349576194879413070233425780491129348134988504750092524844050559699860422372615122343064904784891263169890772047225452396553855282115161119241100559276665660863981710902429836618352658980433349745425754592312835359744512435994253102446195302045485375220289439210078290066189634661150200036502415196237229564128195537155413954794458828566945934940974445196911187813050643438043780453049310939404333299727393954809226950750195317304247462661119503661105351455384314462526054250161809752294229234019422843687094635343993853176743702110151346735899478444758973428023151505590481157253577102097973783347489049358391622770",cs);
	a[3] = SecureInt("73047748073533219959011616422816399295483984034791253617349752190734415872473818259004294616341390441644885758450577917116402118760522829803973337349306894422837487295949571439193499804845355417305017384353694250053239273165706152022642485463357949261672838048099875269770504362756929086337671350745688472342295494544685053411791391309228009933126793963831062787879238557071147383328757224388590798214012944510945499283108877917580779075653134310985678955258007856627000232129733612605459073642415747625667619188554143848510145879682693495803297067562061291440308688116536196932195113158421217500061726294636807249578385142866680748769381899859414013848277074604231819406674736907907454477722569924016745485117236440683369691019170881595812330232273246450651115890165032737014542135170450913895373052301636638655474332721854261972727344928519600495099870082500959761541064688712179670579979116970186304503497815489116159337104555480646200561188588325965074263855238093351562078783379931513284897754233941910950265950215902006400450449666091341029120138810056062828975597625553205505191479493882001364386592475430728482991430703818645203199141164361401522071017220773603953687101526837651089088416943137165797604565836445116033582980",cs);
	a[4] = SecureInt("54349495574096654973533060616935359844034398309539149735978696865751960689463560155728412511584654988155215290945895969681367781975302573113669489249402616628928495733108683042207179883595002708109380927799817903473247742265604336374805149560263521102407033609003365451436236201344586167955803466726846856854214480537207874675426504062232602862534324432587624125531684649471331663281033124822857057503947260950814329654825027957267835409491837556011316964316848124522330841369687093097398992518158494512643753674682165789900106575209355616580402460984639559101646973007195956391490641829735196803869159912177167336956903148820520352060112299781142001226745426222013193547746541259365487796805823882227164827797536606405564131288124148573163805648710552727041448164677411071817617812546938065815724964803268715987300376441126541232400670913390368874841022650557282955522907737190956143985953626137326277641321406746921265008009749350745272563328618069351558825893705850407913713632974798581222983207435675191012834778979390285279250322295053092745704086306650834300775897583006945138569095770308969351205878782485122666765482573202153635612790304776445123672028874660841606684733458872522151052922697463900664684929003942134404596971",cs);
	a[5] = SecureInt("146141877189722560308978447854803859308382219228639355398359070560973770134349567841310231211795654343713150659428772364330623004522762768688794381721288368286287813415031489002211450339315833265726570814710479481272786082986948425272423052119163758666490170290802518091028856820964397487929400538510902822798912369877810258735856953857597160589697443998166279846402028664064019445425921354408668892157854454485163675917041231674945718832080385344591077107001854871532973759970004371617330241475518002930791485137681763254257756075383780474618020696638709887867993838853208639994825763917468131258026726606768689672339553189131115895869347478752514412607203484866134650398653734706955751209573846514581150597357512791945322611511872672020895156483019049998092477078913922662276359763421085974146604776726103385455958032697551623271011010911427265666578780663531437759514839487428261628445992388836765137656355102065725722662852803223815889405780702487084724013350954112886067409057247808282658447398503480813325187803465419415471799637792406542432843333008095310098588043444558247677156029441390721094955655284596014755993799197290065856864636262267172099837332874509240098850095614541517890787793642085899089822297461755649016326082",cs);

	bubbleSort(a, LEN);

	cout << "Sorted array is:  ";
	printArray(a, LEN);

	return 0;
}

// A function to implement bubble sort
void bubbleSort(SecureInt arr[], int n)
{
	int i, j;
	SecureInt cond1, cond2, smaller, greater;

	for (i = 0; i < n-1; i++)
	{
		// Last i elements are already in place   
		for (j = 0; j < n-i-1; j++)
		{
			cond1 = arr[j] <= arr[j+1];
			cond2 = arr[j+1] < arr[j];
			smaller = cond1 * arr[j] + cond2 * arr[j+1];
			greater = arr[j+1] + arr[j] - smaller;
			arr[j] = smaller;
			arr[j+1] = greater;
		}
	}
}


/* Function to print an array */
void printArray(SecureInt arr[], int size)
{
	for (int i=0; i < size; i++) cout << arr[i].str() << " ";
	cout << "\n";
}


void swap(SecureInt *xp, SecureInt *yp)
{
	SecureInt temp = *xp;
	*xp = *yp;
	*yp = temp;
}

#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 10
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("16213971850895767870228648761982048475745075525083759155398179144990273930981224311080775656242433992374223947230939772508555583296914139512287484162586446897944629122271845579763375253158283289557110422143204951191973880881512765041106118692323705086582688279881831713630166371479242913939378528055205903919201964955873922621954046983383677322622008705768032522194105546180592790431503409306211424219202181378019851067119127751901765312121181214391478240650583980842970607894564519072250797255613843417003625119338432657716470386799518298301979178710205281889096751662630079093049440979605894894242947311747366659753",16,"10078212403259582629666899315651791800641060137220343431690822689748269081787215982410377016516928133410129638287212351978801099753512704909459294855448266479170817112440969087606491364655799264699436674862812711800222150862534699846820735378377446068885095619021962767414640389328154703268921335632702021579502605306708614144619318461062273207879137961027233145618076057435423375045298756861440599668605150119462632545142660436849271909398134807475515394614651856455284995852466006156153308504046580373677976553365397821231060113951138978685842206075831307416169458533416196470727051387447968911605992396902650097512898531506689904984004211114458802341669219317890284762091939498886468881288520558721616032281961495565739508079725914379152466916763636966729526863200994582375076333998806414154950314656053975191297076685208750014482985703950153389398266710376964732435274596133817920222760917598098489350668693673758614170315820289839376257585690061287682177632673554549868214771478529224415583975151264760034721323883642129327175228891416034203290708779791105630653450517911096764977779257958459591729373689093083166919499588203805176356895097538752952395884975533332262122005185983669498501664873944088000391769770129988482340074",{"145553417102954146564257476057731511990918968224239882726750146485424464305538462723383420843731499005107254082509547666562017325574115183081057844675580515812874399317521638630484522353618857294602497076107776680684601756266452416916302410841832276663503763251644574738118224316893589624643728842675984989682970597785598361326709548671731072206984317025331459380439114796494706897643734569556920879389450072517043490542660078183799864159243920547705089912467096014096358438342319798674825571639793195490110296120817923856320398201047810116804290372014294241379996109253836050670059031655252902487353988376783660012565878119713051524912534392849659576231492192167410178132061829599229145721029773858129744815887716307006323340959832650992535920186587132318573440865863292828441036470685931841403128920133117052482112321485305083238249039163793611044670085561798319638092155656973354337386359394762699447582280789738773411994418493779739415364940873154106846569877365182886183408943905713523893970716207197241561294249547105491796384408636812603893210918519846506846716352004143074767537942739277192983222690716094935198444657394444311477014486556145377049777093204106453081998914211282415383189983380351418527470565001181031104669620","172932511939734533165316894176732908911296326462386926171283185566468402120196522197945997884431960648078212318682418955005227873026194909397243027818368952832298101438066551594729310853502777677901520800313713463449261084014664435940152997636280981233935654163943926832894089364456530132422402409068998879208056667323406860363234351693721600797327542074613481414298916592515798786075132153768056078687920385411482689612405702753246196133701377070066267397486202977158111914952297326508765472768934892275310345425522648985742470254926469655408653805507431609123639101191205768838505736145726902157838663177995223471275367483359968077049581037759610060584113209893007725975194893246777384514875363908200240395921551196503346508076200771474549332702330403072059329431151582595482673283077159490588834893101927080805522379427114781284598239164473470386174705530125721296728849578672154498130450590699181176974599637982425709558378585492301671344343678804788808937150901587311041156568055786799353715604963807607120346322763972285125337566381857155201315815635379712816104550357209434548886104062820915316798512810646812297119652745317988051895872589308707643263264260561273689904591395053131412991938464778083158026841377151733061195782","255020669201781832881973278426329778413806592971770787381336761928252148427108397199967138353699737607353776134469894094936614150502449231479540392418016236211906083250708754179530241786518520830999212119768363373243083118346484726164086729565041140096452829117831137030930812705296181586104528368764050712945997932567864753231705426490471873745170504464469042452244143899580769061325261460587676093568827081458359446686627825526589038105644625747059931221372733148300135618097108206682489116769225045226245908694467596645806786130079961562868143215685694091710662961095417708272089000521523237768208361081890930411109135122490653562928626156477940156937408583311091160811354354627453983492968232309459128480630180861360216113601467374656040994531018908843306350133406541289919747585465187841283223262346556154691944392012320694310589788857291744193858024878278475932440428422350963368610903270294432962423367556504260102586076726210068144642894060335162335499713268093509271612394073930108441328456428782046627968188805660211785776678714486708150192572140981046244299408889565822131099653254144345943773768406582551215782607866636979912728865293324502006494870976747998316360257154631208930015963011347920955440673374649187420064424","126737245806953368225071755448868199878844577617278263819563152594875352179555130261197694732956638656551084759856386480698734269685732721161001789042419826137347183995666787588213396951676895316399328590448723866417473701677929950852931841137292944176986906610072420708192868502871466802009109644099220639399803007493158570261214569668388178266205170060524415875437806599262058095331385058059896877563073610388200421868886086079424522431631433452587790156367003301346829091709847829851202458496709252736612077648555819164298545752070404993595959985694715772210322555936630059984683400649273451435939950743771520819297386684299062229234584823025065811448793822431274664313439001538841334344616164610097294927363518857794432411996432558378467509799723872899162087135229544507978682885486076949239978927109159255348615913826376691291508363509311974785547899706185828295484271706801376869274882884421807258318969999684898235988560456930389829545103351048591871048307826320417835922292630937921652054272872975813907409633699326191328192877356370029514731910527151076130267207564035956845184134563674795118236496077902863973028087477745290254540846796341745259722885067721876315503027529790068710599808667892786055262382702489003693175416","225564180520688903442479703764179737051155976796805072134730571757889921264725100147757969214454891251780382525280408006671103430392079273772144791683929822122413639403010475399473396326740083297065998468175361875432968359172174192843865437420296516571403249805733787240083752386278430594473244288421995069210382689068531389573853037947023012434977282730326083542867596093397260849923456905269052729365146240419884102978773220067761284560621410509827060493157464426456090092143522696663150552970474100761209349515955921252525097524429775831032766499297638641293804956338746656751303041554225659998181384102979910942211114245024219979188027883171580881842991603717677432444677137947611962887791996540305348371860768544237125318535265903758464727805466994784853798556200078886623845591632410297664891440595460487414323817988272189909007154941070471483836056878519761495509338513213710986202921304706094794384107111959598675910574994396377094648040989733908515694511505204682458708762627591305386755029335024206969045420106842176918595902105935393474970377118409333815945678551479110147653012107022826148692050739168340757374063411762256905782107858923821720369325310703324485018959792846418416166579342003316474001752324080367300393101","188924852213939199673140478290089862841101092874841533314736348395211837837528270388821401674473992630043121567238960927399572121528470851385508350692390377711979922647315842228868994765588955541912380155232697576462957372216962012217511594905649624803988089622203741168938274991957277305273546801242206118497014982474937422835061582187443663841600777886778867019897959984808385422123031926616749097750455669216196839229156999224918178557135363660453795468235333798270136945045372141570679234143817403427044200487111322100608221273407878445198736944559447711037387783765315771833952509025612431822617672083601816617850966920204478263252910826544128934521695737041485870076762269608756461354819231639869711363341858365278506152094439964656294474510260963907121017398607972720652332266954445603750720677037144480176249560333497181554461139095134680155918674712524035645091403023406554779293674177057504850822946558669554124361765151405713051159828004572717268541693613301740765570313195681287120613878409653102052742550991677223510675698433452839888811971600283447905078060207708011764277467065681621866193234350126857356285357490010919255011466170175273745229107254031068164391693709808230570954113694704302768245900446617752965323366","96565250316198732336745169337341278072945343901900556531900358288635326480241054998779345977460229981365321514761443523706076307704201660187282927098007030597015217990607878932789283909001532834276489034107743189156894217690167128537589357666524726732185206644973216679571750126955355100731275937383957079313167464363643685824287023197742280488863349348913886858905042158209467735845899661716083312443784369354193635085456139217546281393470582612296448753407315258765195873716172388477956688699670915856666596267298878157670458691763798278822589800864657270220426488401699397903877098206918671658065068039300461487033719319246653171154391783324125761041637942626360560152104548182988575510614214440673607421492872128289671315270170764136603681866795151772134650316448052376049652294717809102717653294660696845088438631180306156210999706705776573595221267971049081145407069753157883505109675058863859222048940323150995893532712141376566709688843668114778110955947710180290245238266802352262413313610738997281685821086994521729785038652095159716814790248011914694954795157398364380748224098517372937077788107007233968460050208896451321054405654894820551572902138260733212763460773907415226032223005447081059147186848858309000776207346","242703491669618264583988156630898482932064521231140303112246414769713515103242008427423025379028987487454172194121954963163768266839109055691293773070502289353549670060989909358285061347398265979672803157499923465016872184053102853822279658833438675303799532758168362305781415790009706124462633990140208497252852372066974329022673556147616187578821803125699725832454268541550222519914192261469474361303524396498573940620309786414480951981187125436261062924275363780725824629319741597299091980056417744721272863513516608960779100032266085646537220516286982174222620678887878189012522592338435276607213856158819070174127523008912877798673160622679121198170318927296243452784541031262117851177578813884948544565914205474208390231051471243819262679115783994079224325736285338339637710951861928671176985533228347141203879025520845708608712759100088663209434683702530228225666972957054884013071947820198644187610163087885394513263814064530951542843203592694150336998427277568391673691197162617406220797787569325909407140400588121451971904278655825445789200779868091033953143480498717704121092340781863309584384735598819461462969646161216405943443107566322367581622785359163144217099692863840384413195927082328042082677120314069468027045736","218445718935099908206771224427399166899813588818011054356559633849700116453808328562300044076025580624173396250122489467968711657098532704596372526286791888788599080262471225626441603799228686934931675732653973906229764559996385787175390541625585355863310985939746283288851710890596622483005256060884418150900101435859923017205247721931691746260862875256504419411653523507231745058837305472896484139470537214826874092144075519601935035184890575066947738430935804337022785628224339724718007253185471670451020465130638727827029576641843328195150148725556534587864759217880163896202661497515548067005521168087099047614333009399355845874387142761574357130926273551853945208410917377715618536007775267067111532184907341102061991257097717174314660025953496013391852859497254917823612495067689875456495946457778160069192914569374626790393632550275443796155808506966809293677936535179948269993947042519747477090603253638386433325895399874377269048017848157731947386411620517918127980297375119084980550948663770316898100970709578232828371510157354929741964199818360052173069304934133074030362781917418326370654507843021461980285338802659411907895294218033525344931817408837692560102863777767544078568059033179501576887657014092730322213649610","165668639038238984240895644313476323785681124794753436180994317299550824374008656678496571169577022590793262201534710846950316837191743349254775814267220507728439824361982426229832049928824350525855448802564759877682834813739564232801097447453939319708046026750260532646655279355005679911951016783870004629844995035801018360301916370152185071065140525413956720440348521684124688570934338260968840689206608804545191249273824569559844532351706187563665917523216659566317496680745955070174806337641385283964250632479371299492509140992127380561888712631917388619686479296935406437250275370805247638553783000866181507439698548851061493699906953772910360252425214697028839378729456809353280459771282562828959103540918123870722058523925777349279933716911224279850459687973435083679332291683784432566193345675403889771466188264282477495663058533919184000332716629185263331067752114527488787644278152443553051614013448788041756573883457586742549928003847355707909311697734379190287939647005131073582886026590348457370825805714710655641738101599420233906491724926587469998833770767082466765330791031506205497100013226143727948503306065445768781748210627759998342624754693916024874121783378798617365544366433314443917425371631403360206013065007","223833088931192821431908185131070003374785296372522710590367035591429063002730600238313341610785132318598755770874176088301984841263678209742407922534703775012548179508287752404002933145428135871102812385919683668462613222958091839498168671081764361962128653520914471493658858367412943533114311998265733889898841759309701062366092481522708807649832860590960431408817007910152525935334545234682673178871842963296613929017745440228456849825085948877879670916119529523955467984009396010040688820450257751578319938310922929221520749263571545300422031414335329490965999420716148231809955924229842786232797115745672553627964066163035993714276258480825339496628932536021394349270102465041859376677945762524226505385347001573195876286476590762767789431820014830741223910101157296349712954719208034464472047183524868140612644358059766103693057151198400427429102254516142452517141107150681992554876487562843229273061833207801082539984312005727557861831747351130794573581105221847841370195588572682331526699460645005480566047726793559328219478182486012529608068928657001454303338588098715660812018383792045093354499057730896653414308550482335499406692394113889047859178280957940344914153051784602053112667716750053773451416374804718532632247228","42000313656275924982297104910064859868529008223414888353774867191036872732823966143008849604644371036986465208143673458956035195293760073774859062949857286012297487924536892766183356214180135312296145709408912209810491346927080113680606181099080981500492517624852430179110420692324610497072223177767385212451836490777919796250010658165099555895218498468741339927839938869214111302960924988640076719503697118368418602093701335327761773717733760370329029354079941798199341317864691848332206862443391923267335515288853903664550401108571339516014654671882139086629829358076639042043892574134366743499072609035939388086517419332839969514941345118772199188592261537172834113169802557070773940928609975813098848788063874681404856268022298155356050975014418487694872060030949638630378808842797155979716459494209501409683463836421637526209752109152770017375498538883596182423995769778660606647377482138430616802580673255392607438931053610292578994656838409943714483090305759371673216601424237164428390829655627397456509484617898814633086118657798367477323588007084065016506447875659510296066516073480547056861386964022845158725169586964378662756092765406278376823681643927970950197392809621766123590483638802275907839730486744937333425819250","244790951387713612386587882709361567893515236576864649113680811558465814260664427678284741372938103285349012456468270963635828011457177288987922474733996519476230164396631530917131592217572339789182703629670031787385372059154101815298334160581817831531441612669905909771604486289988844230026630240234972961283538118800961355782021487881312982026996784132007592918228280707368432333777541744607468502581898388890374954846966443305337170061083070707805309409883805752466459864909399796085256400136598411397035905564475798925399663330946539551391866948387056603937577868926790235921133696891236468955421569803105497425835941174532426382460899938480346447145238394081049976933951741400775684337203213490353460967584624051191461463333827534961701063418972439382602567772718725181116402172755835610857312700592606364755661386081220576534330613056852137944452424177827954712832956371796677190419887026652519630171327292246020291115806472714567384776253986047258825997450482072269383835024651538591346295728657550705139772357656614341422725150545306211955050065025163792961694624174983343334945451040342139902055957521710192611330454821194541392947541455547693462954722796592138986684800617578950948739026455222578630130091190823083076240142","153863187607142558631553220021586260278214578668528506193091010271064432012057391741230691585437700122933989068306455877103736046924929334716406790860228986410754316440072213319699929056396094150550596548688882638101294539855678782962451224662471849332390141785788626612729180865252213591409778567221800979817332312642519907596673298558041061654235581178153595711454984582811253273033864268417776240779114911136853121217964979887120218524526368818925734856181420018995626651702910768777294010859180495737192957244433034396201017692693266016739521622974265037526637335952666370157395476098403813004301789689304402543244620690801528173804646832051525669416546035482014419198732101030257557803228643642771533093223662656241130448105708999414028316950330647805789560204004054333972272295997360255138095111709738881554691852572154922595831737173574514144728319153970296112854038712269272221408339463903261251068705813027006523171750535568859461469056375850439259722933742819428803643374101441089675254251869839702510787635388839269746026370527015329579790656503332704405464068951231060087302753363403012862801028896402502204338583845350634762001842210068477132214077645780154988091088132338685048097671752488201606664210084540776400162728","185384537986365109746615646917457477189321216641146381062054780612143551565823130748319141092992670868497788183272302138684188262309915689585324892286383764822485619185389805565683266509331142808230025597243843898257859702610596068592694642708532596932935722969695980199541490630682321429604238739044407745651335730703743466869819375673210791383363099229809159221701207857382547242108856744585043294547823032057743332999306914370500978700580190194745102955578993861956918867471032143553988078220898066984224839389335549039731390826201370337564216209146325962462851593413167664879075658701404593468547673509190470001139034511054931714232701323360776469361921668603577449526453517451205714414524037836518246262327708626313935386826529078581743497011487863982582675720712425513166007570959748967073228269652774744424607049699197360998168161638690546206760845400943529392535662378540009765621979109803017869661802411746873253988821071126589815018183315084672277218401786076045987242000574338274276466568444540894091854373778540194163458925408573162854825855555251650186540160966827992182048108213895251159991034630458091386863203018447248001548982399414440528810821064944673356209156983808194812605762088341076207246452499610776412514528","31057588098011244719822595302603903088687922553724887797173188129131473297460282213512116015417092831217959323372593854484887827441276898158741079347909202713298896930224292605899055299183760616165490735806156554228041259107207153745139367320829584429082855376642266755931943168946392839795451038465463893191502429271506720995068816700505863457236060407757954571232081976117839001086750970521852530270034468282403100321885029167180112000113078520194594236937073069226128003564585920175341744623938593824041247348353013206348889901312779599781391395851170291338141454941359261727410614704139503499863898277374551267824135275828040030142045881097381140503626629809112128486837942093901803886186839459761400231225299975154903232717424767221483746733194077352604946411096500085899910029600634244544314963893484542040888622843335968243184876558411460262123647048700569558307260216288791031195090256580677255833168465927341769425253336223906604466351328963333110082652615620957992802899997914378903827009031935762811224361721852847081811654275416907297185167706946117782255356583352947882392063917054475455800689444523662410374933919122754020845060309440859316565461772855940875421574846372191458301244005516763793735574967615249283139208","37982216201042456392408210423551959310779680351576730147696226852864008534031827196439775621993609554543869669308109621677507156221336423813177154726913102999979594791164972936697187431335598715386511629519749191526963897130073107446994754508871763484785275353034996960040596521667402609313590629744567264822189708406511835608109660857819773261899252677735631995517500357781691157029630376592017790973007292961352204000461053272668894466330358932000480505729975095319919603961012964636144070501135584399754066319018200471143168370506759950218028723517135454558857331153438833357875477193213903085013591914352630801206760976071960366947215925100841030109256513817968462667907409498401494871535330425575516544620905507409683316980166230708967006607007599397852932728335944976517488392722181061057830196852350953280091360597877704688257570808153911672750970535833166428087817805161094865242386145732909104145324394662340379368387227479514272027388148662632854827641313595159884418376470982475422420429153659946569019246531839588899266165986956823147255003486446588807165902924777761584041103648752121699052593006037644289308188412487741157708229538482668099995030325256780419290892652135639608140468164504108436629933810808412298396001"},"238000878904231975267523746084342701083227584240460749843891900812719230484688955078006040942227589604145292856631229238361639673462720963570185957319276528328600150546754726490630383308229237682945567768756637286544922852332978836568030464549044774587516384345304397346283338064415564094875444288200994872088890567783827643638205503409039503553916914786815738311393254908819816653364773606323253979521755069062238249142423880584452711928056738872692082977751125036601182700831948499184273939519047420733408981521539749177342768530720105795810319852791594453148668517850498386717256114969750381103689755189006983406219270094989403246797156021512681395244764259715165077895029733058039715434040018959613772396039352688560447745617582190389654706552585090142375514428101794341678364082029229806931186446536192351487608686596343662765762193907141343812449657818823403717746388010182777814053607117349154719804023441976755728803311417728199981251274928347653518476318849872029460725641174755610980074520554009847053161723430779571079321517665213476350048735674761363545204728562456576097703704948115117566776833699244993515814579833932484270862463769076594651711190191447860317194337474199906152864159088587242431407336027894384960946372","262419160937707207952779435174763655248111506022789175151703572935862357130329392484284624370407444430704334230046984672935982073106676448161603453949415190574220261962265004206814850046215885158940793151048352555347443136326347823786652720583308031027608353777332282197934682697607807093056835975419944929303958754658978936413528161702244750363260726772999437902771725287218922283667431687648020643743335152684068623176521655676663786018071368516710009217440734853737720908042159438723276629995539935333470030770712897508668072179912728538544166551378089879106032533431802498963723397694453093609877800559243670373989112135021634147792693138750283788324770250006293938970935320749893592260212013621882934699467325786037182873409620527070747591859894792898958455805369281597318430597353941834443205039275314585757083445268129956215193885477090554134063310900474547776621482715261097055585584606577734622631310106933619128831165162707354681692998415271143418862073800639659843066560172873433591417504668297086372548841626955865836736586681843500386619209184972793321037296299104313335531111087724758811452113363694442495938897550352491113390737196705130828572298160241317622513598098677278117639592433754869065788352831363143818783223", libgDir, gFunctionName);

	SecureInt num("111050134003171136738911501594387395238966843285355606784715747528786256576080679332841809955110369154527573415481416882922919310527320859162104880194712655258914697315468075781114204781150838394490142563451086156251583041259743791668446312247186299330424609486093439276568589209891042630499756316620334455623136556320400502914634947327571708702747096094371487151675531994512457129931306497114137860249651487323832333570549929300560296875923425575487514618700260810908511110987552914643177521420899648942092274894563660683182058130055926565156485879270046705324609680992849430107169750466227598043923546750342839984664900843803954659913988537234267026170444798346604614966489055961685173546790770067862842162842224478109188405355390875273050446131093357173451391532849427833668743951388894761775805045942651230377154574284814664198217895722193635786706108921827646928581278620721793726366239747292566744129330363604850983608173107238580338486004113179489767534138123673094482772231513263358452257667423272444265935672532793352634387764408702042455883363581657170657477213993431222782988469673171606551518920495191053300970600126089042991117914869746505731973054189454345122622519803724584436556170443123790523416574980984787967987324",cs);
	SecureInt fact("81931814434975744180365523400572936569646762803389836306777905384999065851383934846403053586130704712950631880599403325921180034868669804117262887930078118907502658850536527206744845788401792541197098704674432111938740155170035171615129517876993429502462914051440668153334939039703320117502196843390708972924629226088364350668969650205633098282511617406612288808585956136037002343881562673695060391985530947776447306768403475635226344132232282609238156994445261388048692922082433662339030899476336451039519192173526716774140146521250463929175366662583452099250174991601950093168494051331092133708546812008216255637385780128074508864648701777010459747560334746511374373059350988016235369951348765770884489843024742231816163654105116648614034584880494540900870502932720878993285043788256460650092474438310573027645062532127616189952655212472384096522956804663254792174390836663131806575719310931689261653421875647669653940960936710279534687990680003112834253901083489902026128632749796034028530810259579639639891246880070317862883530497573666368769342773164924076243270107758066592561929299018565749180266684678261094261513234761908036153906016548831648964756053123018401967072875703374946706582456606675136048802267206150188072188599",cs);
	SecureInt i("210190976689230108962675330107621677936088283442547073090076513905935244648391640415601754740184990202202280250494340586035517207894641621016645092302371611528552576441402053243109557971898400219465215944578261274748665649821856477213619856290073586537335364317219028466565332750158135986212601595687905952429980012003656045207248488794783182021282030749335408833018320015617683523763979329126551596880212377274195828356851661402823333409123899751757746524395714944321114188062500669810439131091168911404007675060480911296529227630644366374057228923359081760323669849369652878454487612910023577216171503940782267290803537630770463819809881654740493823477630391511217901826300678345958893856170426446139646647699501242151881678568343147512067072763620559314402108517274574686903320856332031258155709947062747249743298793585094926436377646254731976505226145784806996500145213332809462973763852894163883025855739119100374690114490930160217925145615995204309115545860756340547510265055677487418555904799700079949435470590004991800742529881049662209599972799586030543781699237234615008292415571876476372076615554714971844662440308062405496198254250611492373464064330294781820884794391603477164493929868608764715001577157011094042954949111",cs);
	SecureInt result("176737512967774001201283863836669455691594283260373651094342752640997201495000189614959408158425613540813102540224006224768175171249149389934282867154432634548414421429623606434818378877436682024990910688201595369891358361568550241686658932131845101876194402409390478287713912144147714679693599439605433284647628011327730126435021533552378798378305451348891100091320403392822379016816661316763295564121392111167200290198895325490612608232536420714107588655876454124799792947143989676321934495134934667030504077422969070761221224223401431113513527323967529920448881917102149378505668095913266869271535778036543661237380181239379436472840002174354188292380497280281089373757344156716521808757927533580068404923436127936093203421427547490967011295025245001944636766237109778872320803968995542596269154170624800612978705405565211857633339887259449752870491847870344845472387120402354267671440226703554395289518938389803856254254022371146046965315479563773929234856593107252768135731656595046626678138502969887344615317226553451657169164567425143788999708982945267094676064169698222392061906912633450442722884544351539477400167456336702905070209471584187458725825530135226862570892433792094965997177139904177767166746363055098788019765459",cs);
	
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

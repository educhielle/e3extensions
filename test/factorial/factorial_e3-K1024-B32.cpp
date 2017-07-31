#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 10
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("158344477643913214960237226571140629350337052474521717789765129658038766766086124355424789235692030560721584025175562114182080324115360530329037617338823189952737605212777495535201322010648540337767310883990136008587497808960036697440093541231420069021482402029941429326905776874735661276766763293346084852857",32,"5110818727465077639620641593815663658677355255883099159175239740142620202083326684712871639782520075992048003780398009458142546713967870855752881676177212445610291651662386436019930875927477276296313103722318314657623273632844207586817142489916035428389497706839312614723347750481592362228026617057079648277648166192928443287448626927677301577273886962986386274349612504838768007692247356499302324239660673857445905317760180594983893503460263998577222685887768629380682825164792362226545396589892639518136954836481014193021429849763263222385672364260127501919586130365269185305679503884476446693729138546006872394601",{"6187340778363896324346798456297488458615893902775936509191477284513557168302382693856908952886829009514324265427974122509898376939322606346661733656389004981425090901040465447832558367469875902286256441270628589599362448124602078923671183795717589264940757549203322687272664504507108776657564502101628167283504866447588755403375014804639428896423018243121736226703012705338283861636670564043071168848987219512268506502412820775554551457086407927079228864874912100366828014806953927557375965744178370152370027244992969730025730095108517371442567582217377458047872341268850227195900032742203446059080822271419568237586","19129303723289283702649956261464495529025977369562426405929054349811241298874469704159554306198946007193290427474798617617921249402497480009051696560569287856907786066615835726543240210618655390766951332088606700428248832906814354407121537497044438664731755673727914661164550103564697119950679552283831574014527309136759482415393830898767648148919486795914093261295385328554712096150799259988572926688924664103103243515781497944945584618703391347481892411617049454668301703529923726067171117285449780751692845297964575425247321397563144798402960405855654820271923207897868732081476005679618596828573981218673743525536","24589109967261325518308204263636976291254913498945480398788063589770345906874247865020047662498274454236273253121994686758746289194038277394760920649010532860694023615150831708981178902495946530080290358678077653875105020112923700104079897674468066725533375568390301280261301501089877949684777974538357367392554786903606008022184124574018354455359911847239291396333234182342316788475034377248716997882081688632313275479711903471911332635855120040451880777719335627412239089654959682569620341596769256961878225015092866052445244320127879106511050993418531252552057498373534661704367040239212760598826663057557421599145","9097467033255177665403238209797991960849225653482857541490397002269235410679521065803463663667853273688108511409902148989397533304038194783444626411755268666965372926272088804001034040819719255880916296195165245744343770076354598794065914784094976317076778845499340164920475379176244430158744632124623508109608951188607088094795356091299733073409401088105175782204484729162633209165031355200955733394506167252043052680916286109996991368191822591450456626754469311336112284736045490448973615986123614239304711770009542807256222543434868698068932277354674700819334931949905903423373180520800323253929894483801381825114","9046644828607843614665715946920046301496058833759750802339477564773885148437159757152210557937592400167253670577939066350606660542177429543871154149520894219779174637566732825954522233054453684312073576262353327145751129147671008343886745290549135095561859034481528603026478179317537408798599491450937792341256868574925954219692453046802193821004754113357916086978807615735346205254240437664523484628490701658606585486629338116710035606295726121769017115407904225801100562474035242578301159715452119992210871844262424349026206533485975394117126279340211696411137735520352714583074292110926203676747246045971119116401","7739686282256228687951181001942778231119683421375773973518088841523015110542874162377323559162872784136812317154457601409988296435708726974937048654737566274468034301348759115407682006054875998132799224797342127435237363515145369367930213696118556897957030095336318210320499012441471826434747358834168705668666390428687932041500655308291912290906487970752803991804901911690686139434206477522959053465674971700400935088562558295031211009375576761935761425376912533829740775087924100301658121346172255750670011601431622830367600271310088202352004073441048310078883156856584641034219815552598836558475991201376170545178","18525153422614048111853047841018857233072707984824525079200212408644545986626617987914837260852911667790785329888492335448000929053806346234803248934615587358484893988684960779164929866504473452525020150608128106863534763025296293356322194240196448122295063928876166371832885574592482456426250700113194053039092367648947045309448332753591596550218449390039524589308579587316978536004733796064334127145196581567319046692715851376637033336448570285709115971262448148025954180364046892207139020405943482486263440813235590339692575201868379525388141695000695322760475760797340848998045836354598184136102142265732729103649","1461116589172228671101717320509839124869223761809719607689137417596542255775806774573082612104595750923121625173679225863270057332917817249848347470724324944566728898703559204794278072549152190582496922322092699788511090594154724656850094652367378459465440781143590741692602175393617392310917520839196996872512762332050114049932058246162620748217226463811143285397550678826180778600375972363297594986974797950671372228914689576867397852807782401086874420683947686676751836766769908882323086054316659314414452905954444731458870385034451786251611539900222290435540453603489920269954210309841385668103737597142163059319","2083700594313656698152819147642610740907033795675602118385307442646781818401560006890983823105034291675937376776273058835358332420673828306646798880316224862961679383834308136450790422848008203424507772035194272165932806897289640530362732393514819537059879522228810732456279175438742359311813683069251821200641938255632345997166423592908874013387377292315222698901354543757239847778165923948959792764259429021800424560052732949797114445398386603746202936251351911345274463189519988387626869593266657685437450468047468747936983137845207867967903125527702093693169750029933172501936503336790759196822864135009452167503","9995443526606181592395434755223171175054515667905051322323338209394765547419449825989544486624501481163515426715806449748703824867612003893705199272989104832402131275313127262601538532491064550316433841282432484665463065214701206758132569412093227376118213226787400289394042157316615030608078101720902474373665954514211418480722529218403493215537065514871388431270396373767104197807466850670909212953201351771112573583864511106329395317105053643249312895886419192458611463243187429244922460841141871365469252386047812976663385643797290421298444597300875146866843931864566147680864014386950418441983733039757271547921","17023619168798902055203215531141634685491587664092934415471808171141657922932469273154623063560689045035537602766595655599845251303286367723551163120546999228089855942257895928182861637245392562842466426433873916389126541276031519343351469909728682205752802016137363883025687373888737660176604025351454639561038707495937931239615857193702683738780959540741280060211764722902986293136507874072641926060293316057654793899548831492014645498673811333767012459416677434316181296391294823099467099792848049230940425212760082254929024734810155649839322212055795548474674461355746850761686967319016269024157691168118707961137","13797181960713090967443010193006497679622427252301062155207410744169084744651076028747308408034869799115827064800935125880678319277712972566242323577683522455663496477432145318616915487576086682738608678792251934303326233646340259112324700306642955942361838950645454760374612467267175169368758713174381180268165990687440153969024455825444299030066447663404292508019842333641967386353205327233945722465415518940211554670279864333847049831181418794740309047918783776656426875770664297402844184724181749910771551740628807262588270206985886235801008639759613627162390155705673112555765781565751543223417075710395753435472","8192115010571317559916840719087576592551603261579081131696670305635191809588901437153996182951454490631361108537276990064581590699461630226956301220710361258397385116227195875244488910145102608503414904266017598421162862549864333384543177742350689181073868241811468202654682964556956408406131178172357071805506108852274318252967644093230830335353404371439780088743387129924430226898520752442479618872991878733204321007848472354708135745308552730991021378587874091643040799388567958099816418066984836037564045824683079746759202098308671899165903024819423502413020514078430049073923968906412823059500643811125948194372","6899416679500108636080748925408000103634470066912392203426605400106085711070653406941299352297768130816317621523102409523876494072160294613124967242131028276581374156269419677913142066412046591093931465550955162170153983153581425825459754404525686817738667103746365056793620068616519646439705858726393232020023932331017013871720222126896733308197270385492545991683564980372779977970093520068996774314189831028172248003415819750405295097629776371291308212148473479292409815701132219493639873733291077363620642270178814212473913288691353743900491992047941887389450770232640299742242864212351459693975155706269894825130","17592631619763753607641622426112680390295153422363272557258271468713367015631294010711723860364036679736987546692297945853063249991869245178448493408830175344480249997703620246565332879957034966979732363485900958126527485525589580410909724015251301432776568319340286680731763056823636580914451776404885935546158971119532075356208595817655097085909060861618753549288054154724151897612850516928022860407828343474222931955527575014826974755934800098227180294436736575067224180226970553850160581509481999500223903622418719321703416607238748114503959112384967130636177678613693495742000378545527262589888375375855740244134","21835254102575446126852364663348416399970843740881155433262427407701464437261651046338896046676793997748872301732928139532102728879774346576528491432384052541768141855568935277824347509449885105796776474226431109780827945635165345141782039388416547200533215280606962597059836435408836031121310113710564651966981408746399058595921395879650357059510317322921818727909929144605680008741068907464543344083208750900936710659387351828488990949857276252784043065593471164268386388674689542367893941658164980427670089170717901113075969016648589854620149497728535635104839459351713218018937252579091618534133237650352292301774","16842415821902553174283912914177127371407654599521510165929768317069263312066287435078525624235465407805702938901130450458524312010913694093487572052563987673249152860731517652732757159605660722138259885671883522985261329428501828147640490440262153282254560713533397054781080164138524279647949240221529170944955247321253566348757300606675041936213071688958405098334915454209116987217516456489579563269048989578454442165268799475308933355602293134994968647744630154854808018344400184035287654453667535662061685269968309998341465501240585243609034429360244711392665910530426166678741568857768544142190567216177299417915","18179053781302672608005198812472033077592055516309735121458052440380135695399993547498468881282661567875312241502234930061610923259666457113128896882253059807795148661457650312187682254036432500270718050800999710830938463177463664740265929802583214557832290217646641577870567647398162572367063747666009057321786655150863428474483502147329045090423285843573699785578681793313558787550194630861207261543622935169377360149902789127633620608927821124936158188077853519517950460871988343640425145700990050643161070902427136305775968951779671440022743652932247024036169533793010501440052884756962600132072439558287478128320","13259190412526785195774931249485694345065484791614604101556019362415822457966561925230691839375424421109818712982856675626196784866012532256220277704050876703063922041035173637431919032863177635212180956683060832849026701938930993347964568149071448797324751102975296481577173164556866518726423314848509326508056718410639345442499282530460664148542910345537633879754494812795142807703981918592720770384208748080258268126102378156682844458659398283249322072245121501899419494140311402753119248039388522968303403811521652127815621670083961173896673666053942933864667975314133619017311492975700563472938542834339330097700","8384394096835508058881989796844518958386204459245833057203868871062907161383834684054838694491316194863678013960426035101952302575321055523096886263466556655404015178849588568284779680352876051903245598114940783311721068032219034326105018882710243545687833952304092225667465376254592486668892484025775723230129980881646205778818178429388986813382066372472829328703909502884173696332648891546020204335657181925855753111733968405942482728986492501306282675561286242103588425354810693395314627226333179314203538500970799292443958530916003689232710876596274299353798324426970159729867657851012486889656378331079136722228","11965820144479191958720997863033552757023523517332559754073955410564677241013342053339612544766133942840998419394144472741884366065289374298548678612952395322953305867696389571990850470363738480372176428716579681853333042184144395987579446710179304864014481761901266735461898240917411905466029445973266675841502924829042378475712601735330190452658305202937484686553972173133700130300798675535731830843026649452285452169482002727382456455734668096867622722407432132750919725141111352411797871222402543659168769295794451200904281297733328594450841882228974554392493230946920515831165588044193909298083292223161966015008","24865863765025456605458962599965512935448305551453838139685054856199714462953496431677789086241689409948023609093501406534962339342454830500358946448964857285107877932530379474216418275462416884315690335354347825502929751533437347473292781899791268487547699520318627038162919833427006400134441262476882407119509876369038735145766593127762423189220020665274313294536104365164853013931679149707221020679738990747675839447199612503945742544677911724586469098183175558155609634254680237999242645048913735619918903268849611582575047320059662543193202305499461617460588953093642707675884113858717387944204832185258938681336","13574135715398123224674248454598738351435906554063068406271441323638929384701134013088471152071834269154540960536267001840151599947716341024301256241876173429664824018945180743743129987195693818806712715950996090841135399924871733927327496987870546977557603643365260243149375321231591687883710998744418530036502966356903240500545518018267887004456863701601754863986322340191718968456395687843915636327365367195646081779108619136114893283132826749708779471351647832264502987993080289769436394667487279316408329531145144827009180701930102589874646092970008288909657655364851800897022318644634348392876472893221608580945","1026988479916775731862621939368686565454275745945172150230849515134403857920332435025365011911650233383324647115326407022200968592561860396803711697233263491859883286119911324033450881630746083926118846830872690081594121427699333138655001010850182264587260361360614658305880833231514811306123882245477909041593611528286415279830314875663803477825605757164130681191547191314722413585515404275834206665629861990017527929028494129700402546527559130239502527896012450215550899898315857966224277658407175350457406514477177168099040040782346333936993448197144994914157008078209115358435602462209223420204108331540968678668","5444662129170868812028115893864082088034372949181285825506900059515694173043399751445828237239915809821161243507021505001999505902052297904241509161762203539844370874964420497522276857839624007626333293413389028342817475979831483611246737075115130096028480075204448586352861178417629637856120433699171481159561946149628934018146575771344229811449022019616921907476037050613132236420207728393364068643190461202693401392400966820790977819855079198014315341853336629140656218197426288117185912589479872565770343100258692143327776732230557716185532042108198504333110554519442434842263262590714589804961875296540286598089","25062034670549709563476419760587095491886294916918613904528208372369443381750536579039835466696193550905084597435218632970630838574746286678068861271381652075027169354313357342976233184109858757669145103241831550704582793069540826011906520985293214363594814110407360617437154080127359277601998660784655872499007785163900140503228126138619121847814337962608163624625284255339325898199645073801190483194137445540212291936078101645336168588336009912007088204327277460188846865164385140597428002991137695192736631404978890044756648992914239426586313010492808553158061017555277882066449291148471447610604736203256211075043","2235314578421547732107059261912485296792112176705546640880464490228513330456751779365960580179317113492137690501911946947498369792809703064375176046802255662371527734035946788426573136202560731212367197337874012324296843250294391212158565707000075862966373724500862651242326501466589124715587736234683387214163215871177395870321414643204985309890447957556346894077135604032529483965948434590326549348738618738314581701930177323980297084726628413826703766821236877974156856794001637192673163878720198040489467744992504569775298145615208569526124553733977045628185517539744977257874580872389742636194804536097462840456","8723306892527985861456230459405636737928565011055786489882646196512820700685823588611931815050099943777522668367833468342482849088218732253103053054530334226031923439360576659065613356261195785470078312970782999778496373400942870342191873242878819965127562043106636490353445087047079553758676833932141787787132161855389808850975893970674053581581541575752798262858603385907124901708227455883419711001325889477586333378194903408832194122801928548612515972031298496867851815238879845799538940542700300096627246995421938744194412921194168616677100082814692277216832907557863802596390834716306503738043035710644672747035","10504570624166422021414708214396891050114036754477362000191504763891402559371567624184418797401801336393494939384972911360793210524227924497655205742729867341433854999120596377990460256070459603513964698079101733290475838792341295684861344791984175080986649729543456379310752470514391074580584529045562232853351703073542994406957530375986991442957327874763348304110715290663078236324018026660996758961800709411792317517255343768390732445293634179768712590968285995508821379698031294693544775522963695179843731934372190097785162250000112573501834571992469406867421211884898772171418592184538450269334397162219320645830","11624002620954283323716752098844271543740264943277723069077110410881622153210256675836082110070874818763857487133246911532886169547620835060750167551715998700202149634806497765786384219948675159230468251679878427213204872758040279399264924122795175472941012768283141262268381875812622421014041677313122545515075849146499103066985587307771677720370601669098461525687556232459571457512882637562876441822128123663905196228443369666506161623043066696675715922320900960670538716935399322676433629081555689235368325362566530545742638324740818402700396525837538730115497104707842822165052667924076641055835440188224263452385","16175084638782779120905557050033882336581668301619617730970543687564263493666489062338765141196598693729740723103319657306697053833206016249031131879663717015892015067401558077549383748446690647737827728555174877176206148802799860949073318801488324860710488945577706085133908841375629951168719470063389300336143983797677066391551976528338036001807045270620300048071961156518878394126929862165249866023004088254601747927983108733163661712542362797715305658145333502677516991894445971973451883246396966516320462252872533307922569521160716803286690368882787887489396593235479106280570918951403204383107947779125122260416","17409271212612135495868386064667997559474106968254251656014916472435481135638349882271754842284699272569823609208226550128643717969862174514541723807509248817673729508749517125663064221434906443426736124226738923652517449326502589239754518346558296662907158192141630286135058538108815993195788360214583716226466410607028939769859679507785540501341734621849500508685437226559047738137937632796206192175472702767659655073646419103443520112886517067722742807580884317969266019206687588030164253016542662586820907081206810021858384339109232271285520646320335174786322873131509652153504394773044454157872375400456674606984","22090346461772601480035217223325540181108353577884557212699705372169219828913742369687455955326799332969366290697277027030276783699271573793189871284999242092630513539291355789980900087730323056889465192171677781654247312186848397013535205830613358750887798291514990022873558593734431599928269380207851920455212424844915481415270035410603973688572464328279579303763194046980399920626536477617075727969586286348938122234542538116073553442623084408521814057982755690281142232351345081706021468720672186038476312613709784230728174203720982523931538265885197531640515996087321708321068581853586606775908819894461854965287"},"7789935582962230717717498658895019936171370205116566883797957387699869226665147915889158251020130701715743492871444681388668288341366422679186041818177442754138173242634187300410999233655497992056551971362420268382294363572565003456566141711479364128443721721488415425458397108367423310770677981609477672930519377131785968585548009869450146571026513149489468908453869271071380174204382465601231442434677043730860474207477806651645158323532651219683221902430864755850950056573839309309574125172452101155578675905607755893535233384707825049113329903336649785533650895573477377445878736874446698753165571108732950679928","3873997835992086507624397552372755754745339990679688713257888160512517662299624767476893668913873645738417667185322972196351138092763217906491145167090624437640253115328071657753429447359622597784731851304536393513375838221079249334008418094286497768740189659987824398270383778301890284517272890196314764387887018728975628332420889136361167487142497070496495159718660390018140238213044220498391536067800970854852230087854506770935257751442647443611297841698364927033458911172555426403079338010225303728285348419394682717116630622681649408537724091680036736387628654230416651418986542049060934570738990544929323271612", libgDir, gFunctionName);

	SecureInt num("11533932196001578309400669597860598633099970983800902436155379516243094314374446546363869208664589939808099955304635460026530107404735842138621270625362861216571277651299250645269646190853915893732911845079414376027619030023387236478692234398496846740014289891954707658512885311389654528738589437686399675032641832845194460636574920377935062370292463339494784937108331330604562415590798135269820337410689075517022723422936338763678332182174798088701010044376398251006162731232754525656328235853095422841454853736919269665949793207032961541963404189021641609956023826517642815962669338145410609758515616074127190959146",cs);
	SecureInt fact("24699531935741981125662040969244631484705304963883226547807700233563353668389590254290533720592913780865761886541128145030600843081496764324302344349820722197094856480349628258679821759256187984398875865183756787332455736906298345706098917917834726583070069269316749250868437558804288291823787418479531986558923276232584753100533348845007878111161426065123251078395418494630290639259805569177148346004209407990876336224505156944431411473234498915500074630635301533828989225122949826707120141153471578316144710975270414577107196578331779230968750323633330216127409155478569063172434753342970716573391063240159684179280",cs);
	SecureInt i("4328660476619084151172712384232497722775125128214521631093436882022132705615263254704111612067165500280403805321228790043989803323066331169395011317544473687176255952949907504507387736082535412392239998484469297648382112591142728721839632347697063493858272273425596707033827203719035634824161048486343384153304578747139322332591711715277380989083750633019061226136856158654460325399149648942892009033220846640681262831583099311764342281488713846133281745722050642379021777693703038948028645564096670206097123288626286805346367502633801416844942634591496540912297818487342193864808034289223202768907072138888572904327",cs);
	SecureInt result("13582814703683024953901645258734167331277605469321900317211010208500514675819160324627627013597799006166790725069828318130799382415038600902639193526104408343055108003459123295366348924324608640211015457937487158477413425777948566820011897611627679617532175557268815226726058941241327078178347039512534901588966456743856040060912818935489334331043101574455653773331521074354018001019652310118479334116487900922507196091585924093954111927733647461446856242963854029287350372253484153668312765275387725042919634873418843481095963031301595781465588657025788042264192834235045312350075731146393113639565967163106125226568",cs);
	
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

#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("118035509328689844302979285398099727158644755597062778081057067477144043123955688996196034372483202437571870547438158800031353074322030298489540952979715394262332282441527528041284977409429408594614352964399466695859427151286943414607984519498538107415938794570550481133711390883688395299353681275272716604473",8,"10066327883372126985101987840862173385221181514573906411231726691422207274937066439827567665923693199834440430792170391799373098835768952111551332378923639589682541799670598800260756226242602638727283029340148020747792796223590933214440691154745389499796616019204347798643603176940197484829865736016731500009467327410254077459527147050584963560304250387400073193525986111876107978281800317027851792976165448599133785989951007386820882315867814593822270633026927501123067087867896557691146310439023816284244108182240507773860193189430046269217522736797086825261778034496764834710223399514851169770296422682419455747281",{"9526574140099669327984931426374239036040877588552027734483693546888147820805741382854324429408655294948067483199335706751165040474378380036855251442964646704224406218431533123642220585853232131047907922255996049424246951603692935281145202457333921129368675770840123065627218354393514722312867686546928172604223975724716934085335158228538336035315235324892275969809060476831460401317587146223800025521570487638721001134847044758402107544884850301527350906053796677398295321365152317678127296049261939036051709731115770448676766624157631766865456434390861889233273280414493956156918786017098191803905003035290707295850","12242768537814674838967098360867753079762019944002886610535645635305629290377002820066153547238487937441733958960494451468226507767340915682641892302207065991208701030685315644975348984482480635863614641291083558953469774076707294617743068084447071538196854774848835614063688692249096430836861769997431441314662571396946334298747892329148247392042592781440307924753338263541325182349742970000418102524449893933722436813665157620362933263036145117367292089203218809446432943576900292863544719793682328793914588764889659047706139926439227951960257172999570678152599988779055544161310849472390172503474957224284202946575","2207641816581930263400659486133860782723102289294222047186993117658777511289190182651612813663103823424429181433949016838299281662267650666057815763042891834163888488321633086378619079565732386014190643983488813326220059130247991566950717668783713855540323431264835476600420091979170111586896210577795346720511026448291359639416546121927036508132551229186364856372496813029836587458054083943224245685481708618240491461260305307764283085214475235207752206910294508727410622896714773860834516446575065157483401528901832258322081656714153776393458193834384645954212290450734615960352017767816787359639234002157995314327","5043209380317005632626523242363887170402865299049247288464290065279988689258539897776829180063666853940117820313567467981970036849931062376870910670213294642825331219302066071191104237946015860368122533140913944922912006627880940568966411990685710784856814932538135702096975164113594900472782620150201224306146550037213843967758160914637034952902291626388636959603121592352921063426944639304148338011619331095348735092511113081935408408273403967830365660976298723024606280922495794944460022175015277378524236904763880411532864565668548872875885947725189346469131922873689024506699837766454102438057780531304973268622","1025851161682090376502170726587090215060226536279181879225038101175839510265465655267674007378949154112111830169450910757601131177497987676358758683802155494192662620703401456220069141858639562015333819563450687584546860124839106725055992128354468031861158396090360387276797803145540415370929831185920521656725344155030782685209096144690799033951791388628689751246795960555699860273004801189191251523245960035871531591312493620381516355218180394249135752033314504625306898076824138237000644560573131588541185252835441776973829738732567028002074579760552933617900531373047641921967767449425561614749675568563397095450","12977868146005209351556298483239111177898575065726372968727209100805909797131680155337642011199878984621631284020033038756477885436877540164856167336115949849061633438853980593623791620497204032007000497794388188790320710464959190113415830106871946294795403781634504977498028222381275292439234364737784475280130005640610656677384447935436715457637638495352694286781761994449672355282214739587668215371073381860618020167028226100376814283748927251196055711814094574864063753366780488432772723761090680431646813545806509041545791833159084566609656074591791259023856531562377061254099905806484724124027563580164003817384","12781145523742953678409101636112566832197210506483360572817782382114767992261305286592977934242526843355921335817650177328733247432656620943324446176725147002372956413955045898511617657520915292635782728076306429273802216624895676595108119541262284871203641896580399130636360631449439735228918951750698694288462897047587617204512242645189733529831831365646927871782063440650177059521083442000131883439558124870337993820046378045053214977393695121211435064098435685492260240239819760384811950737970991824172888524339635745833166775328586906025432903898023264199636748619619685316479786360422713693092574586053237935592","2190863549547878096134575777504084990648233115115317780450370810265920759212121549554735899461957629818960710025063305093430827001859203330168545506017041005250726498459243899772165086012639390690887986524885789805237460058840302243425197261625026295833135269293136342528657428652387312856138869268296152455761895494848410863763568784640300543544296247907881192200084577239669359556231073964351653287463402695585963857240840463958990640238278861631912480965989509681604500022923301258019277840591574990275104607324885427903459706519945910814383050844610652349196014564908961953154396429768008171805779068085248825252","1805092975338704433760250910612400276323725589811770383564894623892248072077285391449568102030310865059160261177623830223132048968919787220281247715000649646172225614192572207248204690389664447895946113359991052981971177764367227856950932630973212869775132540350749841535308037539722195999084279513363283512452752757213785489759533392432786798897102638298243908271196048953200820963430045118166505632910364510774497274976612434986762972315538502440005674438817495667727524811408840635870757577759757585242407057059462876790586369760210731878874854308254106066564108877066881005875588706298017398201502893814264210840"},"9003118047140204132217234806537506622458184877606343154840856099897203692702388063669586474448104908740671684510128727394334716597139348114936784564048135328123521729596206124373413424515947763452848580693268563358397879137548764767684813103316563606324443311347483671603485484209744341486229989740117019589926757372655720844032784901634763997443831216760824453509810114380148353475682177945086154682981030010770839264432393846443180528999878993644017688075731312201354911556828834347376246363481321003453429981198606970480294135126375399313622444807611301482890094073919475968899119569892823587129968337917201143","1484345489350472836373499245690449633592935688666711948520019804462049953977242901198009762907783783835431071405500447609502070353715842143402325918374660747054688982208974706757571921527643294492766070042685417774683913984814391460088801437755883474124705021120853020410295705149962621935578062342939164602421459815964464749371530354698319373046760296966697771659608867491746345841622379867384337573387473620505474366820458272606000270465426365521145578840868548286892055862202423538178093683661678756285387561348530717971407285151881740193130615179053014346351983666140300048313148448526665072899659140204816101723", libgDir, gFunctionName);
	SecureInt a[3][3], b[3][3], c[3][3];

	a[0][0] = SecureInt("9662394058784297123797271779180725851266355092104504956386475581021393135384269434920387696178568688265717423662167364738969386894670340919238759366140490874270254071052989966522565210640042875682470077384967694087309814909832218796733941992535106574245575777785955520482820765777847295767302509029864836038061293862449894882057676340561838635074293997517161531058189702944852710051087360932606463465483439527803257904892229451213450864254811622476049790430716859447038103786717566258878481245278519802618034851121732075115715329795642534083762293747012103448761629421517770491015987417921425224272276959201847667909",cs);
	a[0][1] = SecureInt("2504244704033054263850017878150546817020215426148997717336129933004709981755207216659078329014807544665091275114105588106053976673044616645375031915108373843518978242566064236153112471350690592299977498785767892817955814000445081645092609442498442274204945099208277441506338040794449473148152793683508078639112380576261027597927171037166299972700041013995781965510278843477011375754018362934680234747838810985249985464590257959854811838542825154534717892866766580546469737359061158841617585296812419128695935316948742141033837197294539927194121238975317692657060190814106824156147146812777771862274599607762885146198",cs);
	a[0][2] = SecureInt("1269088010952032672845158272374501231872421298808219106078043518957064268624582906966424230961605452282942643622643521557225057900595083613866385400203632952224637446835711151021559164725049500946338188247208410698708008916804622740434254212568533463647355839994784485615485745504031308609305505021181627715615105399935943496514196054200488462892080911744813864858431968821897835386974845806543678341379386864373016450158392102452241990956523992406107137798024804078933611844669265554587262411526759616520734336808901639812383796744058873649092607886525978202365019325855846928577677699412024097306043811380300617785",cs);
	a[1][0] = SecureInt("7732020453106226537224529373220198754825879694893649107155466432463836707083474447259238113970366209308692674543056114781009597704883593874355918016060156649541984136279287810696072147678711142630519032339060586838153001395807192582838079128933036887326770355971086497855135787412712054894955914077723570387382354876514744588452884323198614131525346656700083380430576763650467949523859256232941923744611675746600679769190925010951265768521056024976771139773889403595382380197094883376837836003523178224338497420055346977083878761829362193554030850508887760385655632534913759612314823605216514127556175760540381150853",cs);
	a[1][1] = SecureInt("6159333622867710486828291906361632300353878429841229310884120805882783162258698791876393467530880096093228249915591861285880713965264401112739722632373397513699880187557637977703469509799900507174609887191444283979383709716950057197994510279311114315587660464979575357648936939510798490864655165742376878620896621803825288330360888932622537377841476431737814044387635827268310070420495946148218145230707407719223185748525833065717503309403768104830830068088053066748197829076389345381601322191468596894698528820853934819090211479201811427505058557258660280016381536667377532745523879754761869234902705542232368052960",cs);
	a[1][2] = SecureInt("3200237368698193207605858812873752792713576276390173066554220338945549459579832915588221993131765624345070905813137265745321959977982535722669848398662824507600778936292612722270444855366225112440380168369934777505446839498533358791587204207583706158920700161906158174381552110731970890625103918541619805085763928452423907356424198696927562008795205460285237324832232555453966487406070253487117897379245492772846236312160709077881988141130497449764474869885433177204420351892853365796974178501824367646581678233087556463372059054268155899508681621119213280361135242089891903705414614778735582555747846761500038109901",cs);
	a[2][0] = SecureInt("5340051683304118844406647990332688405404339853967279274444707189802438674421197343328514966019115424061636820355811362803396026695185328827984052051982899756608465482042405456748870597500090447986897746371415702687178603931883085292120431558411882639895241230627630336957243825628338138915418566103125030566481129951560509024012525800309939546707022745399275669663029165549960079189364440772460248512241805346748523601534320050022220917066129233633367488404558454301943383923825501432010847779834187563796706911747358634078440616203459933571076637621644612886710790084357478284400896350547994010952184077714740194900",cs);
	a[2][1] = SecureInt("3831545690659782438183803955590069077306148762821140991137365623485743687282909789481367045848959887477446848699550233106857830492411982764699468192925287397756631160202584737180728480242749271388668178407081428246389951746601224276548969493122896002787219480941333610055862936418556904430734651601095352233766819435436048069836706584180405989426321314810982716016477633914536248985513208759812665801663709978051811412424857120352821196166617246622365053593094345076951522339178839585841721192008973020939212601916475226481953350002347906838669510945085336087710235873386988907420167469422126738968346203178194863027",cs);
	a[2][2] = SecureInt("2693723849222176078828430391318783644345561072891688862570353429007003453894217980920790970038302783385316154709844343245278416479978056790990870703421375078700508033795803634929980378541977470438765299044554569224917553913293504812164630512970572020223650630349849183522491654181874772637552568720855519450103422718474429297906415006405350608299337486453231774703707332428779877287702994293945167425264944833860637770985927455305195248325256717608005038044527474251653627826632594404205969469753090958130849497009250315189620673913135059876352467196534103906781607374587903869874756719811047903861346256724454445127",cs);

	b[0][0] = SecureInt("1013239088599775256560454981505422978459783618807297447411853502283308944763661083909041298676468756060175340029445012885416507003346821522363263101174280974473821776510937900424382080176655981587083541550662870758998929699145784598736525942617180868798766194129832694183616410207184488528056156976995948228405871226578536916315620301254483721744514850905804022385675718527985581177383593192278534062049042109426584466646443479482286916392339624421849203115315655193430727567344737314060043053667709824904161265627062673048113995031062073937308261886626772731361342859020708478862219820469295932096165111123307475531",cs);
	b[0][1] = SecureInt("340086706175864258741186666287309665352203871154813690293105720792988999568361238215321174292221357583768893416457833183336997362770995826196555295074164871328870376138253472533062057240891907169445651534495832020066062315645543050771922954458204519277727639617306954142005587873091469237318404492573303856543584246424099409928913832775215253140064931018117386932544168071824369053004974078326435906930998398426667890565573804470287266642586142256908587045600503492140988484158727057918648523300627213643548958322998365770863087546563979991314307344219419183947315918175822272006165326759099842066801076629025761575",cs);
	b[0][2] = SecureInt("8679956833631873221217014675380607305380938693761148262287492350471754603774187529979976854766648537181235290887234890070064131697281733719963977587438422927660550978581147862928042177194574111511260182520784160941537352506248214164741271945131467984249531124607713757678126784760709146402737513006724343950968513357987965047460104645726968911217245017716335100610343841550798632344048230755376875762393251350069545625552729674607287887971080282352705371782396767998584363721798459740529807338526256603700503413178833646388585078795314712660865915687466222088332183310669912308427111588287296058232215227196689528642",cs);
	b[1][0] = SecureInt("6043268635191256077187150500440258158443801502267282888451990230669448467603250219278219285329783683918806473341303148994337098251503703395907121304195479649669449691922733007371865379357252340672163455487534500003419671739052094906667932446870429841479859509077456500203967065376504068111501486644378668939095819799488064151605947915241004299452946425609317530199261784558408321225995806986657684987119619595810406297921393936364332891550646500678224664036727492409190157844113471240315061632102680284868814861888512347712042288584135984732167825325740075808108677712609469160515444260192557755575429924047752361009",cs);
	b[1][1] = SecureInt("3660767418299376317197681988390586760622058239101555385740191083907394953420589972952644195780143149820136159246325895827443157055839562554025214198962671827022179108721700248443230177620916396802263714244763407945558680629513096521643791932158222342081706364272161089777424372552350436772676338639354190377768639929321468906727274115023210117731164903582513131542964642339491732112957239907405873555423649672031727621227014659246329830612584737254802928283137052198810874669301064997563691844026775147287806611365252330563344486427021233762992493224119127697409349634627646054954409430434438230979132290457745538748",cs);
	b[1][2] = SecureInt("12128902524322712204594502692306829237368958323728464068936712795699258143389882023808537072754555414676479017001284981902680982505353671871984492269479749040539598924191532405257595912657942042304224494278262381244039431229231418924655861091418858936748675977882560813012818942236793544698803424246987567778040848388257859403275604074527566451817521518201008834161390420907072500421113115581021258706228128583831635821270357175353443257671088325103072001524006177652126066148136293187570508222557331414213191189042463662451910657340362545112888603810820003074718520445268860610480804038326263817562646826068872375508",cs);
	b[2][0] = SecureInt("13534935402710615510572079222365012606381578711399542845636973947389703788663871488495044800726183383779066419760129981747513823868501690925639265659630015703014788444599546785797785920029621621289359284590130430104674369555770665233940627242760000836259256315142695734050164157755321158150860790521575102046878927186430695547207934419599771332135522763901844298944566219393564898687961760594213236248562602606576741287482242890039645218868963923929144485003296558935884347556475611459495602098760285239943827292125286047171241472204923509884325728875593098779208234814259584235135555848174401639898816937640471459981",cs);
	b[2][1] = SecureInt("6556944594647953847263816586592373511159345760450450365013952357137581994975364986768413976526754854782882018550253693604332749216511833708069483032371989293180854021350127567853991980376059609315122656476763538313322555952333405486581752070935339450695948866228728946000334351704000650092708079291322527164631629586706233101349692857152590949756055252081899759785402193050277224087057414564831946045007752427008373056512566732448869087081025388051638978017264127243105135965915675198327152755439407507156243810107369251603133051531344982546068764199141539863009834796127333636391682002129566207443446296214805162640",cs);
	b[2][2] = SecureInt("5232955710319927503186891708116516915752890832293399988920012377430967638295989858770581912519361624709733554399563414618813417972319858584505801842061429372442863060810990891054003624151066529699176943401329254165208528495595415721547204400417053816401493532734683743796987299232236400227473172080065658497450667555315572267729927625103026009768800506491154440559203960186797474783616957797842801722521008412951748375555454879200459080529335776812959831897541945701217736231631318264620178472532570796520880010932895507203395691206448533996896109114184787529234826314318085661814823769578484672599440052447035615981",cs);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			c[i][j] = SecureInt("620682094369283800118901101240084566538469810197900491740870606062467433703689791917595665957761602579756765825286084463083504478807158672086300804767964477935189659933749920246843893998142664687430788282641680283337307099653000169315509463196822201048419337990499039790337745142558172754744690084938868276697815066228933934998377781188022204181237178636682996173834387306263192580803845612780515078356702792714845834148894785144969279478908938673148479362277093569665618607299316219719179491975245838190821902508789665072884290046275660041220564783064226032051586347310937497150216167900457067997785526436888065869",cs);
			for (int k = 0; k < 3; k++) c[i][j] += a[i][k] * b[k][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) cout << c[i][j].str() << " ";
		cout << "\n";
	}

	return 0;
}

#include <iostream>
#include "../../src/e3extensions/secureint.h"

#define IT 1000

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	for (int i = 0; i < IT; i++)
	{
		Cryptosystem cs("14140759180861134447476914746166505506317436060707756713147085103194268200763810778025004565586042444404615228138747200114733767953967941937827065616570179412795158706240056159205384291031156154285566138300568987536646311514818528410542410299138531415115898825882112384691000773742393004745240658344445737302906816743650680616102249442237943187881781851216194823721125641919371129444543911284129849096480549686237158061460675708934478305914351485962554683137348242190520805920023175526380227491898615023177910203841851932136669736898798074147240164514104714471534575688399646643618937235122503238021797432755720674689",8,{"53381757933377993092212422644965748956993656507064320343788573498283483416399874404073279041204121942221197512970354426199599624111059000660032061002584155744646028924284406911223260981365847566071180337708065317266488893165734039026587652574962421432817917304806587047608169396229314219783938533732490920750253565591945061596458754345519361770104004507413753773067320768099814338667934839184886787077997299714549472927710673717294072364906899352910077439026143184306305502095069607531102678636229023301920769058883769424372716335226657969047270752738835634339242725419288381567463202363798193404464438594831328364621303810116456849524505518591380460610270900377307098644425262770854447946650623588112946730731044668394777502841741779599287886013018546287776797481613373387479508699434357471751564616735204849901606231475670059850382087074028554927801867990407499465830495878473038751020874279057927629250316333370299218224335488590684937799365138657020573513688977523055073894874507294653109840655178646400288206092218866777830422995748866211696687296045525015038821555787543416360658407563899241314607410497812948391945323272098436754726883569413311958918501080166124067723090358043784772358236543360155746850545659456925573962987","150630888258367545306523113649690674574511198911251367370168776529442697461413578023469463428079154927005356246906642125121440771274380481713681621395281505098033919717413273849739823876328889874119762248281299681816805369769494608449735471404352218888533306130426292195324937491354273657059928933828332799444297388434052089672210766859025494799272188205827272933567721429544685215097271713953982073339739942060345659914445729737817641471944096292007643811533665002747879192512098474647866344246554603135228937236783968623245473596763684008508096712322742417611440004705186886961369069116277802724094972914157372135536223006171413114415906593462330110892639393194391435128505545885790204472162545174787664711215853024843265952574497206466916252090978411413493611996278377704938415633088333962555545588085382842641848342160481735855498244089821577869036230339711032188072974130999843193286775276652214824140716899123627504056224235794847122485342911031219998273168746713696591063664365186935045667441608257130797856626054834562986235013966950526605753414520990532370239624758001386103134436507320657927293500063162875980798750302120673129758284209826984714007665491349391476156892804706864299261626201918696193680567228179366798343559","170089484814245883458409146974233851011700607584692567129891153619287499147271536423978634745199365786637194475320013429084360128965979512491052265444693257853449471238546317825579385471455222777371934364242859823417426525493777890785758062432973539456617693698843838821815352867817679072150688914522723435685428628064957583669446611893877407104022357691182493880458910872817675692902512956270814524242369917351273902472162389678850752061308058254633313069078034488052428494412039521472630916559610348030531485618638581366162455257397974972106536264752554362618068009574063822012331215874842702941591196897443338419099377943517460298254155223832989147817655991084671825076014030025578660786885634635476676438531123937807291310282636454638337316618031915059801752193074752121090526165389438037325878568834796169085115628659531053977150176209445470239663405642205259011554992623698313590969432493664036113876433214775589843318475573964817440866110558064994117336601626755273266506477599427689057342286119288186033964310660321955557291796062480071033815565929611319525656090481861889917348524447871901664085713315475105811912789111001296048627457484755744670729560937088796049518467415149322104107839859879764756498576744011418610561163","5337047685442659223747807098059133975315168197549206511749459839422854946016991548221442452270655709426786193331103915859597237591812550178244613168897194682992524103812758916026291846228139117638116561758789950336606844302869571209978673850707140163121557434975893150050416822274649702552797427498912761726868999709649956046162609374983095576974349985280158778090242790490916035306944775259857711777002165225284367318762308871601139539234395214218092053840331010747916844541114368845396274139100923390989348539098574433753061506070381990265540278992645277229686361506027502201050003896888383852197874702377908959030727713109900137897162958365900459265289793317031186308474219758151712966792736888748127113326851111948201364733249497403134639179091050464261968000790410524587502717537591221966818538838184784941337435618448943014862002123794139207473539425479629748656621317614045066006957522205977044882840219225564022645693307633094311097272537258863586283672932545793297629829773900573446803545053268307245509824047786626629100737793184651832248758686451366815311328996439720441703368252940151793600192982214941312629726947721746769875701543450713265292504572858299444980594696147839888192744621149537864351064472299111748683536","139901976316620373220004742686517152408385860005823133239396145656425073264860011797739755700311248035567273280390089911086219531628921755049194154485993324354736660893230755350836264784447855924870561978807564475591532017275992919936551739334733160822227382679932841249523750974208824866701573018135597722165462959775033779553342443612881489021766381870050559488447955837187674930418247984257737880680711574434429201830670904241260996437455491155968019010222769042315688187571439064844557307441908955012413376761533762612459146746145182178816617976963482421497065452446467537955579235707245246669725833984588509626324970902805804391484550237065998862324607501686036621455106198540316343147267106546326870851007165409384714884958599846791930469948912150432636456536146531091325775757206385512383481068153421040605549026726502416277823446381316551499832195452484845418979682440184272152489951615545094877420513224102387513353740269608786751705627136344842715544050849119401152772012437694774089980344931411976903243901789029922124567404376507155527976271483752196148775216950995332108813893876996950243075434197886657917476517533974158314125202227574883613984820571970820459959487783056512683539351322692404664081045141394546526049037","9486721988506147742371079680327502107660982562994220278270982100055855488307946824026739720549230574952517611511032379194436848839451884601495695709861153214678466482579499183489827458995513956855308121142901548666962524138957048837151399851096678412221467702042366705640749087689283134499129231705809348291363690315081075425325315616912124322863573284380005181712802930888330259329158293001727321375165164731543075173499216738744681075154521764270755996826250699969077118620989837124751716378751476639472232415908081932076943921386504377398128707787666618215498209970136870029792106410945477033066992498611731748498793742454971027501555953575821124268078599265699802789424197255924766202739192253336110041750468389795469027910885044543873994165614088734292136910905741972853261828749942231357460557223396892075850988276006268139074292649113797615405661388645798101397541138252622043023920648102431308994023339078516100780107485447126771330988848752734299108805341774092002822009829391219409300890469892878882481137304264816011594188360154417055533928595059418125837689061255000602221497321048374928867207427992620171846829758268041941077755821493125976739880609526687866196199658759745337024057338223704602442458294787155234623574","171760194293347082868463569870050517352049634962451624960755741966450889625367755950373631635925398362390421280174995861631983142570446844052150515172845395710581318897325502024776343850980081877032326190238799575153808689529561270946641656756808044239728012333615422449170058682067825614804734018325076537507936300360168639179662227694118495047423749966271386677352104685577660267309656505845723746294651363184008757192550790272221091141098330024078876304798415741102451350986305218840834306129380582656656686694435977290761063888748453716950439492969881084160873383752231949648057244025005868932788005408387313910757521045879400817909496028667423946606551435847354787179367128743459623542272438516698141462997192442249521040460190044026974328423279252786409773628966147805350278419019070813836714076978978692799836084234027213005717051681881562242481249193931584368590313678749139955568668760694369181437177708617150861422058157480180731896155408242844153647350211714457449186428706856090234882916611034039271832798918214341561968950495939186911044107453119446887246181593629466782303873941889861134720537857743694407050451785500313262447876737990168366534868244028750676039715184593180181732549560406275687788930414718701389149649","129277219791286692850077771360692753035580717066057627512623985802231214782213141372399721096804257878386771168263169369004140655599243860183140804378232500981939648257115570080650387276251183804379279474774055676455596982338593131645303345782060791460595347727989968245805700176704250707349849641860576431555527967063462487908850710901851433526835582145877541351299705737033999293239282253478376285554874528162740170977063242689310626348007528210667020062317158519608308486987626115419219487715863252953353198878551821408089258981733261516449817900929915713729333905291520859717355437761652984115099308368309833651918615802069281744081324702256707144683961812178407303105736614381042516925258203204610677529196178208382454148980907033143384206434729298502899714493825972946403404126737841577098580162784275552246534417397380789182643178032427680785745676574853306313386114063882623818870792002028901307412633487168706213836123975859927225521403684976110744700562623852787538593980383814774119036435763298657508198868932223823301277816329825534260462150045850069381846520651826617142645209096097983396608079135875998233361135037660778688115110981844565165274638337710603246869308052222209565914615170299183704931340390999288494353411","80749161365917086871419572130078262961363764729258722877484366534435498380248330340853152338083373465509074349304910529384477358001397396000721619635548821741833913004087330510329257277254285207409213616615544837424058882064529861901925209993982747921662279771439878270160746607739858682994989527954906107576951695386179797715586370932870405754302970337082436006179664995761801741282918490163971771250283955471497466195583212578932217320309528275504599623433140419208799219316638101240955847840709343764350307880299831671608654041251230822385539628572064313583942865022474205382731895969017766070966598665676323027201035500691047577187603218009716118173473617753351584664543714439207014964699340171721677906915276559036594191637710773266050064593799709224231474533761006463010394942264998350987131626989101471234020163733307968642279205139722066606831874885215750671714077257556889234039123292142372070018465302118594413445049185058990067070331134974636556051005507047612085887659834636340596344500933079271886476803319277827967763560125465476231450153804171418343453435570386675272921375548014850739147594834739573925574721875416313176692508031942947025631732780418978968073697090529640212293453158038967973710939251463052285507847"}, libgDir, gFunctionName);
/*
		SecureInt a, b;
		a = SecureInt(__E(7),cs);
		b = SecureInt(__E(12),cs);
*/
	}

	return 0;
}


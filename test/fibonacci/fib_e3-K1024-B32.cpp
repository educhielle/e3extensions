#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

#define MAX_NUM 10
//#define NUM 7

int main()
{
	Cryptosystem cs("62999130099608846704073880684602146367401759152694956033939830105341909909909739909603260896898865629073857353643520918897462387354560867149983484077744556208509169527373954774126247334188667358836454949566499512816554952148667565776761949328885540122254685137315185399644584368585975354736383595694707089873",32,"3785349597666622473703364819029904768104059867889149921656064775268722181031787607510475372321059922806255332527407288015982104665174310489167553091565263937733874734311778231709968233583293965017278722493261904988308911324017021179241692066638080254893655240633015710196960810872931252341421900116044265681989735841597885831537202081051747368813457473998077010793740173017461136801817232061783921278244196209808267973913053656001975923265521316514470515595717445131223042187951122290221060682971381991964622954551785040659216757575291979242332477325674337189940143507269784588248921974484510633852093751206081554310",{"262753168356927010852927274473355399362355293826024353845784151635586448676971604269553403902979273349738937674060580518725407384860159049952412643428126877250102736047692752176984477011800094030066295837790188274753459784736077113884127891229304576691934371717440288864363371863952630668402869980890771172880748750353501580925467966397564953873740118897593158905250880108926004848327860878248093118762385688620271183456404532397544648968313694488200468472071150898911998450054055482541575762398568299301860507364433695851545828418397831175101244067048441856395550715765709753831350976381491467507036151840519169926","1494455948333747132239674556777670151607510346154331801479031650031186445630402836884077145183400822740426332556234707432614090089388689157943863849369781755984914085831962905709678296523328036122020605396158542679936374401320568899732941708166510336799898871291868456282142325229293910404762525024665163026755843282346621654035702212287226737003768493310380831846718854380963185953095413099615341522965943920143526240401883641104705068701625386183596383857835049275623599909514712812168553095678428491784878363163725363921992572706767724923074926909866175196823679471653658582034569488557610025032027692200626017649","941539308128028627859066544099483254551822181622140224056138099198666245795808484242195916417386187287625496363456489047754077910913770530400636022600982881477581900352574465287419517971263903285556730182123393029350770234373964155914263686617896202979923533626387451180758910237392672023353205525899539143857026332703592645429752227941666797500676076108411902302266785186999956293177502382758524489906724277961460279701039401091834867454893048927912089246253528794111069734160901725199328092486189552665395192661014960562758091433095932983700077779143392360384202394053750418087144497068302454683465756595720687154","2749329280757797274375569585355464361335265605963272500437613558000781427472568181901381522929633949617996560231414340373481647530176168173107527853903431419030467702737676350469783451171266560268693085646866833864340938767928837663663220920736237628818251100042204968382281038364619394793950239428291035435313840355828966301646594201010619442703652648571201226323469870616229727177726879424877619217785051754786255477933292768987293121941264853788534811405082994039839413534045770840730211909053269440764351057085036432276166367977770900131259236707791275492771946907598253523298681210357628739210923260565481046847","65890801675683793541618314872863870128171600550963895192243208799558346840257302082051127823790906862651217561248501583024748315404940605787723681254900131857022853131099737253933314494805998492813063640201019521715737318894696160284131876531090298791713266742148147809194145009376760781854977762273588777767229779523267326872924273264577326129283628504030431188017047420764580440676684427946189565503711162794113939279567483316199422979961347034276243153171211029014784024624686471231117481656680494493264343692555683976662981030020653873542867850279615319679169264361739090337105526843508867564609364418392231865","1458220920469927588547482073539404435840972698817626133623352657551061501725983871707808223553853784124297889207056870202731087140231290008381293270738082952324277148142423594571642628995220442073476935008983848653478767061444039596023815763676688938491990145724248349650209408978573031416758227300502123257807816204038566371157441840725157764383528455593057903303134249082949025777048186545491301023027110219044664843708583807151439728273920988176591759342463423662129490780090432481811796148592487473745744748549261905486347767504971654619482232762856710539579672928696428213014762136933557680215189824932471863172","28715312163878800920122831451862694086681124239258290374215830543166359705106300015352318845703909259570713664923221356530219290398521507738991081958845862673483926224710727762049722028514715717418460270603069182018959344453313615385518197871131484570287911770275348561077653623160777005663163224139956260640950597924489690904954231545032101379792443471935251515768933288072522685454116149551076524210784805503269374920072737801734150024137428937289816968996380717036390102969217016401939515616689786204000243551227127999349833919875921776224016835761664394561658114466311064154706846349110617840431740756796420348","2566821233786748848759370675902192084552415228591003242961360938090268467087316570593311635267905809546198938516778077913840164199989102841539264075151087120046806044553027249666157247470113981268331848932874757782119613941067292794992880909523333531093731097379696235692944827115868668681594541873855529958415654356441597581539770279327368317300845956467214383077673550769494922612768723388438696041788224943112267972527679540943717362609074926125267667653597529830334583495895514262904965518394285457194723843843698158271670409832876061451335332377596370374891148540101476989810663098686648006105399516184899163282","877180506618050632151629138105487923372308356686506195617026884341623691888322356747841610220656916308040697779516250185478562380829185515275955865464974158927449429153509991665035239098522868816978439143241686710007546800681237701531435621291229386980210203305613717695070623443768702698809260683218409367767983473706209475763568318119803335403475694913389952997464633463209749475651558989412755586941354938171464389849066936357794158715827338081331443170283750753076804485992479662549303724738077292023516328320448580285817747716243878710186672787462837368556149257815187368646462482172145888960381354254703266717","810997658489796054836845995593846553337347356686074597715807926182587815026918996078424630639041964682155482216892115649647273587488130485474341507995792623383632540707245332225830296093373522880129711353235193373548169829372661954410061124303831918120073127182219624323488422386363473361907637257051736076774777888669193212282451497289341132604126133063965295121256701699093476703174255168127182998163650382454786999111394644013105572396171774263815332839085913027267116748243056791140953966018730899780625799703855199888717639664268118227031426649759228984707919834593736272817766584907886446848943040236662648343","3603928597613012928042795895333594798870134262618170800185830785775228470434753798369048496766631214520403930680469018978905745478713851761911293797980706620435841497531668797277736315434688941360418866099911208311667412950361801870436148249109678986234028896709050415134783758656668774612244421613861176871588807176776669207888376509656304980545369133946264551020387726351694614537170055465522523349777731152478005454154112953118362723040344712305078808584110630339684043653353494748612121692383368790725573004193691252024773046807677183897373778429966309081578731365247848099658583680494205876470466556798904092951","3676610786259814588993734071768657887425202578168147237480355543620829202155094823257497668170998920543421615251893395589367283715077077080102008881419162308625900517280365713282655081223527273225923245788612942072072604372295002420641424716057387407235449928464544221378310431085657685205761543993784091711855729838068448921183749531337427748840787729446966743717537438246643343638467832630255181315936052488859473898014730758743978236283084354531270069609231566512227788932752967550990792158568272358695948198840891228741351985484913553910092265144593836395247607157309355927097380032542648925210807625640359171661","1483359093899812726925004711721321349154903271010689650216907845151745376433879485385475121826140181375846561061347733085699971360112976458438193230692625980420995856437337022764930100776016230254150230857868101693871746832984724483591868727351269775404660082534277077194262325677604626478263024816262302523048999949780722690206122903142302532351924694057535945954959151177790440209605281348240854777248357059395354020069470620054627323789923340993576381611384121331678452852833098333308917840290934842282082558494475447736399027515540044011907225605970826678779138988580132228727214690482393253229046468555267355844","3467431576382631476927952864217176106686092872935710179291748969732771089607716304363792523977744679633089161939765979973496057151668182669691072132350591204414461317250977571464052241702896674117842793207555165856927403419735620161219088985375482963203226751417469081326963105570356203770178145341660564221281618138976984851793360468218717399343296315480463214265545684846810189878950296380374660973864083190882985966361698490101185335627433540241386716661956596378854626232573936887113117085196908421904539737389754322380400857318915162304739355373706569497812395648818248148625347155742938635304562068088964677451","2172924525702480437717482926041487361430472312296640999073524389817054171292491806611353964415378442716982677186070662539584395917303240190575374519467394682580481030124996444065061258384661004032585718828962235529438650089557765070113558399105410863387157579832165781027356341745606289247594689830433935171692385565910704747672037350313516850157871445554370708693476407923766993401053128635935240602654295496294922359237692474336005793083764702728088216883163892825788952023806529640522703815008712606582545952964593418413276175114683060621749033366359131803534499404620596306717646747059851547188036822474621586027","164975854556388370905741204793975481232701883545266612886614299026665375119210758534987115211916941919611948339422192504190290686970170615378930231423213557890489489369515795284027745507837626060610081677360411939019314409099697796622915781504307605644000698459959514596057809562095878600851946076431888602601801292083527235738774447148589136788508190035588513566898149730782315472767036099101085174006516616145817337633567414434903059368835640325442965225827686107590455500648895356035188391167147498094552854400352644496683404502813456547157205782750287172033457931363762294769274276926643737820633018437943565301","3602994820989209500887873767534723953659351038183469881128881780040869741669878081869698137631736480645926288723006003832158100070286780124958627809301460643124271969769204944227662141246902555495581312427085525758419102877726514834954350154422675559205164354240488173203572854594292471424934697005762413955236803174417267903451633690593383974161800421219155098886950549664780452943976746185330407745254727490929391187418783840103227955804725949777573425533535457329803723921185089606229073207780774512174950352440832271719687232770175112954354385952284865649484728954664637489372259694592099301470821454441767017294","2806078318524029465816884375078677430501540136724322910019198336512064574787687581787565140170044476669509458410990503264515640954728309665146915120699351029529108881632369529403712134800611763957572547378917029275165537881906565764469057172855722767602495394091022512381394717572742796174107291136262328153958633111048770637424683021393177105601130929592686966760783521306011867385846823831897554003220322953776787936067799045372873465522280817665051269126641805161827570466904554673595457385892940428557151599423068235645231287294202179949946466669913392237138372264225259305865324694137413684091279399185339204919","1925991926094146222214148031079707172953464303197273950913428225628644782800181909248320242047829045217617687186388911668344037587049421213480617753944690874890963210945564562619155482193906078283496145148169908544893343583595914545670121138552347758845699185671620613835184473090846333915330320429828697580486161678546467109454404599360555089928149647959070018934853521326243356210985516612282246046407201543626010290938221278710348651988441932670910258764318461379948369470112865181797331587517088537704886768339684560234560736721313142431252795124432922038157661707582156187984926871980147156458733934007120579532","1576310834383139189453646798107504350015392775054256643848260748130885662445672853205498178074976619367547526853338981375278009302153684693626340672307159186612316426702415327699253062520128252034653162265156961322459755330762586879031641969845924737648319640849381590364136852331117420305725088022464298331647905741678969533408633160964931243727294643695396373121296024185684134019987042656471468213607444048353795741147019067289252473388533554964311774313801169375208061087786008058315980250960191926500828268863583771483364134240794008224601718092349157750549321903594605153815805760623541219017488011989611704508","2641248569667146316047921670884804892941559024276884851479412149006447314136891507741804831273226262792721428194903981041172001449901299044743794551789402453708068326085200350452084370821113639736416344407046584695020632235044327314836551866964669785649561498429086075923475153533179584873715638293664873344286143309958315453447651531598300123586158700765378099538673575989503439735266267927586203010636310742265636994540199304008253207780574807337275912548707413133524704221890716829718129220503109969571018716580470692650915626177886390911449617096179547821944755234597587311863482302543134581064262113149304242471","2444666582249344204009185510034933736167996798360090017754562683863532275512979726060364451954262564795172122431349851420390243209761884773876661372740033829240782833895109161877119250466121470574601001515140156322568032178132559115827321896948635038891773819697350702372705256416588237235903967877205828796919882694088172225177766313173856851578125928900652510741707811699860087631447005412839756238259743858618094599932751868769778639028593958095263531991362309058296923468415750179414802949363084554565026891986539561228366525250713460492249562516083956124869785796746431790662264684551300446773396272869161461712","434602703491476719509636999448110487142757795545550462633617543563741877635561121242145537371388032327417778718807264641659694651434127847718163209480697142531727772069476869474473941076299033842313840189910723640766947738813560558081699445763435508955287689476178299893089364310116049823762009776735184358628060811504204731281399086145009568360476269614797682597311133380650814318394398990243955411878436101805967031482837174324984630874638962774917430843104954210554285637786919318539946683562195132731278313209361654364825797594529809032138851368634389914657203625605379069506068449753887628876706061239232683540","222792178061775978375707118299455306800777527815882762394221808465791376096698532944391252072588143199529056378086212817841145795958441796887940951495782936680987572243380021532135732920143209165302066395513247884595131134963377865083018630050300086682270035578242129985638188683098650463275267518731891676530879348747466039447558585969406629737374746604188425283666550725132708403376488361008920480953305990473704528305424987774969082092559480003785234706797195261358230209488841101496415956758638614475558552624306960687834056946314261290931634616894012677807111736563150916209297247422377644419702889260417789682","775047212739388839010489570426866208853757552486241477057931017340992566150924251954467433580197491815514107112879884362991991735528225610821757688981852993075833640076900267090528310939642557506289846756183272091503438897633343079774497091779313854886824029763539365898117956034081353566974180654338080228509646066054413809745766243348346660573225460991345803007857186504411012115502537147202843797827832220557531410717737353153515044358318303316321232044994035635707031027997519707361652032691978515428445556764009903254901368374364529742744034425861738525662768241562860960149935697223254820773879181373420405535","605399742813877390158426038986062729575719398832702480075297581903898452777951651530681298716373077466022869211885783939810881456543264829512202393266246455049925486657772077081392882596421257107360783846378989641094973980990042407251753433674020260037796385153986181280688175082356598218958751495186662455408356923197679582518633583887906273810993242082804954849676064322314520887770550961236264759880611320518042915959092168861131049108340602190654175019812201723816015943534527348186533553608518312402988013565193924996870621078318184894156357822796800737165132070918525596226203099088496394118542090210700666212","606970118993462028879620431055197249059559993069669394055564154762525902870292403316536957377630211736428617312528341857282141098236756429785472705036545208795654169832938185945021879131220889818935754208169129337768841061012264069440899310716520093055082399225043215456855263336905989984816824587098747623690391304990702067527302841474969053660409352087389721682057352857414134254390855988109100175188121333217113019189561798296345121052684676826724718627007178450668818486110013709971163422966626061857985070196584190776230955430869771923179187811167296555685861310164902380215461593833152347541862650322327393917","3418461903444442084220766709196741936468099648909076674456742781937983715877160475189231568009495563405301011661288836070086585101952284730346907740741021198141664010192861231624736995024708663183399574798190225477250855299270271899208327649855587798266761742194148155535488782259499028926797163383509834858209901610384328665747546645620852310235055890075319182436492499307878036429969894228138588934972341403877567207087021153361423444048916667836037942576851244448851201690939032837950108353067686283945363553837181330713410497083073824202163949462656145615476194504134525196522217523707358586584240620601054396302","2479826388042178192802627561720696370975179775090396178695608107647434985303582085423643742930088073667249389166152912989015546886305011258212538518383860908926595814024469526612375566718909250580275382236845025132229625295939770965812217451075142200722983006960185331807588374506869857316453149772869972749375430692374428053846835875155197750221109111152576190834733899490725471250872872341555552382397882755860958361515693020771825678268211017674417645941270181719623927556464763839962691807437756105171947619902905419243419531576678455995662596945355962924282594355172612732706028871001633053050674910293927347710","1656814855930984337953308604322494579462338791133005590348051264888080233811879255120988242434358359617149199476422021855953527010489296532888548743389772019628476246482400347485982559121218114133774537874304250811575675627651044334484461107717180118275242361157365707189646015859289582769153083135880332007500305058517667298120181228068070050373002594286756975674694773340402077899944186687163268450729139073916069027361389748883997512092906592525237721364961924059628991929149249227159154187067343969546631428845887308592207186614757228898029353250396568017364354522228769644249917668977762549466550294081865761487","3936268931639649548280985595700716536869390815418687710909868966324066965434374415344847278927508011763823335300468707102487356119241803719312072014928806520908153806320672319367242323989223003667582800333155282289218163904854687725600746579433731466615667059516213085323749689583156357654869431211060768401775793121302173439054351055459977944133314258120280048397522543209768279636285115595581971045589367616379705161668867006644090342099661121538938489175069546883800214825365320457827383397578583356096322316496952457999453836389133435495237579614596596479731433360886413864944050731788451122283406643415016223329","3329861410255142430500088535215050012122920856007946291655710921462484338041843195217009063302147436697685067140057557693597651408060997144888140110202647616543929756368811766009668959037253022380611199189480750155303520411180249248605365672837303814969040931863627413461952110176212398376564527594442276786168976846005367466241069666230989541698223680126602635849682558715740588464124952828181915742759638140247130092524516580999139564856404296502248216653894246913925436503442193575497266487115284379364063389915748931375202332276073516104049996393938024316912139265740057747790039826309995973058625543309951689507","2070965666994303300059556259683291923725689392512020991969306044269223139529117850196110751919480191562482789212151722915389576855248827388145735547600879707006068721224307492497652359115753102250305135497013732740930213114934014009420626211715757364054966165567880021821721391619185426494856660133741819513050833833204839859217113363236449591543105276516828783755161027759913751299975137924211175328923798358419386764677683894572942461510732087973946588340185496727347677855818446670465611127117650189068553679810908797315837994247470838305585560380972400271795462656229778681788821331001658978911405203115178058377"},"3726115486142396667186587316435671666541226283272006749005449288342476008136000564148184585237613217168144049013089681517078856196262896462219646136081647525480656306835533307865776187480326649576347224227316672842937810403598589855836745658497027060506497113954425706503611240621749360862524473606991668672182110001661635713765957227337946029473896928309639514442643145912469530532914957249328439348025602352773797130733576440824747204210277377874581177883910865798502271991827450047894359339123867126953471377873068875950415619111401112617961273652476395105253054521183744632488921132883468799019617758665734345017","186238394360453930348842229877918837233017418904803202982935080389851710642483968132039673547716849389409063143512642756330645966566435858160938453453035386763731734202053359310554321094091567906055987247113700763972620833327055357364122353040505962248163430485064743430879773040339080937843302648637724715220464987899616706136263217537312159033998732912235283024528354711432742453083453767226215933472662079295500843326018257759559983132588034536358270727612827995528845017890627195471041868846357828372339795398285232288942844495365636584989996243760147478572019881503170493222181269772233985369895290147826478547", libgDir, gFunctionName);

	SecureInt num("2231128617863321575319304800988347742976291150831309273551929859390298575571404645492875324654695745577826267114406496503224814254992253208926113296114447246874155491880262364007467072583754294429016627324315699582303634775864944181344132612297948308142810754668014627406974352722275020357311508987907843241102674373706065894200099159138160612415760421009282646311854193680924787240121024454373499497347286770521656317670553916734174872433569383223599898772855053276952538378519567331374901302294241273024777595369806160964812289724116609783880930421841699532639812580597391544660071351774559376981744336179622249549",cs);
	SecureInt f1("282341524826673661274996156370077088985970959530523108188075584039587833202491050556004619962095619318910932473159622140928788213103971629115461366609695915967373260238978238549273519314900590467669302577745376213428746783020658878119795099468723511766999214672349663974756343084236618497095768152257039597269094962359914515133498327270068079181978525201293163209069818391417379463747064416456620462489437539491530677355331225938725913651124205878291949432337274761881216827593771637645701485650264095599822630824129412377452338544246652575944995772457095231127862646418681331830213438534437937911538142965081174699",cs);
	SecureInt f2("2345172070432698640654954121689575293535419940514774052106628793921847358573246158359824351102816099661784456778476024465251038731755075250210002642226232058184891552093501741080298841547777719145947012756236716603250693278231144647416356531985927406277049037812431671775948742312606010840959540358869303333128696250942575333977467793730582835439222554861627812708268423137194647101765834701641453815097068595198216845470635555688273626401710316111579529136189510147169347031841043760270217542895928113737863527095617401757882594093027121052577056493278517025253775773341374406312337589144474500266223918754950159674",cs);
	SecureInt fi("1524598369892939949221890187080728060345107786259869989492094787429321282939567264141666972581473093910830099687690354618329292592821983688649230350809088631092092116461550380377219228594840780040162352769535530381977855037060311329036323529457399337156324194055656486746272918276051598534178600246834309052807107290982002122932660337703498225329787201124626911396528411896937659432993929732611366145824503471997605167739491839041329128843201867718717596118222021111361651008381871997564193495501838973837461434954956807993726350102159069691260665959547673153460022856345425603581407037033948289689529907633931074795",cs);
	SecureInt i("1807338170423908736345979699080862481430974270181719106408536403406566636051958137874981121707884542692207897929780907287141725553622452283672516769790872281636621038062815632613213125494273612618976459976777126563770508157189310919804582067761315432609407141749225838161538610570886374042591975629436405500688223957367176632802286372619078231778676723391278838872878003214882610418647674591571716106269671601937737184696432214227523144485675934305464242862213638068909029751117500202178432000453272007516320752803037814533073137856087262336026198212712789300953254389691769028085777359894367054752729356113896314536",cs);
	SecureInt result("377145020685918409084885980016035805503546156833874687201457288787655719378536614480287833704157773353418824115773339457151052963834857752086376067172584926684855512821096931498126235646758660520645178131809727618663964630813707667493495871275382306960025591371698049879512525390699724333522787633271350454410248595214656978031632894221372487149059557197205458277158408673391933546808209269683175065842798836325836949602330204807705746741374768708834186971070026408912824364229893355431120130920696204008906990559044897986636388158491521883058602018961851809572204576223331454959484480530530703262437267834869994579",cs);

	int counter = 1;
	do {
		result += (i == num) * fi;
		fi = f1 + f2;
		f1 = f2;
		f2 = fi;
		++i;
	} while (++counter != MAX_NUM);	
	cout << "fib( " << num.str() << " ) = " << result.str() << "\n";

	return 0;
}

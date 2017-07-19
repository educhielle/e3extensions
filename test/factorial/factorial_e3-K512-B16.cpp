#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 10
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("6305822641011249831333350607582248882410513016887102467738691197785481851777028493343793644047659166404839730733368211558038540951172461518687759146178681",16,"22840257154829116388405486026940271859726195084157998205435986158709870689210868606658718455069833391436433722263386651252566119585839275639825934197031548447194125432141965802379497494755904668939144023621535204478104704240256512004259150728795378949512998507801345691442423367773994425770002671404970469283",{"33224699824149102371714273832303832499554067277282754856737496776142996365140634818156188228587157544248649704753820464999502924053019030840528207164805216651308276771021642465493996036157025776256670954679283807532080298340451202170713273168265298968161861230981183621859677626800525452284096344660054209899","7191380892196849682274724428621549362873153444267815637746676143505825924122790797416044347514682342215012320904647602166319323253709472660701906397573382476424760266672467010236170679967328377926104479216283851035640553204387901058443087003790394757187122622332522863816064374394969315892657158283511565141","20873432457430677669408765933145690220083434658362564253610665869756446941030239629972072719429831042705881032202451815936553088778964611055395152928659309579525844404384310418721481501733613362885810509710026551433590233115701445159799774041029223856781028539657235474411759085174057391424324327442965389740","16397268389227585640400896138994362868307545754218706765622531935948549543309751544760296797652423620527193281401937541901675388265504613836966556677990999423706179099106313141812459104493296307591405887527310583658040266256520642470825348419472003919995441805903980654625664363268540499254918280313271639974","19611409634061137974634857020455341562658956699411970973670898135744366051182415513453214827991381656122426523972620544716706329396570366722381667450725330032916091360198484405888739995649501478083299943268490097161392994643312108164499952196778042113581726428393921383448840529412372605639366961702189092333","17394658106832169287508612912044118818463640865649287295237799748587168813876535908838312342318122603849642911981518652352445622831725153164970650205787966864177676907773259432715618164426286418120774538096200158510708086289034700162568290761164161800264966988636488358513777828709535841943493400148991430899","32399123673709554801787150519643375179004461358217667578687103109610903691155090397476466277170729547252619692149712620845562134183094004923969076913756474856305306083588409458675675710337880321070665150880398985902418993769314579576432970712149835653243179234417749108558195457593879866080431555862882660795","986933309742783481496411408750171964046054874941254330458272485754298419129326134423932617566105794704302160615085702505507293241719707306190381503476046023068581235282511684333900670142511588894689981121458687072576774990452245604334111504269799899656618062077796891530579390090841889653464282364565245346","26647868705536988588827685145665584740037653002120411662718284377215740397623168592744484246159698430051170765719545760546144758336666322983286958555843216730672157973082154310135454020547741755098054162204159563259299169426694065428910324137302274568301668170442519598200787484943141401528809431284709361811","26572461782832313229714644637052157979734585731903733961852342887223517163469195487998508587758343835465324817763796030165972986826852981862709589405394650369782030528417677446795989007199955036928052223772974062197817210440515817749549985730945666488126587446952664840023971039763084528911365597198911315324","31313921517654358626219783893954811272990054864660276609897728410043655678377931007720052278204909697703695573119713196184476553300482900737457667271289934854989993971329770765414279656945800125296039316744120879113368175019058778248516469479810742184877236210687112459253056131697576886672542362412087157136","31819448333658955440435824086963533015240005949170453565342784469013463134315789339433160517403135198234497605039103972453476104546782088811957189337752158746949901570749035099864743070291767444439104067183674537187822481041728320044267683548972436748383950069690372780087708786826644306454058203891416334693","3839954980597948680475672354696561589118238900246666061202572991239564762513705897939658772545459441136782444461655409397786841908797253490860794838823516460901914153009688541597940325010934257219929407157889159352864457575689854997926046864051330831201893701032540008379702323662495575499809786232428718179","6143755683209883326805717060885833060582338736699162458591272330742169179546017048641443960646409247317079097088173176149650303016057017493935408607364145221854011595185237134445436979949220113539047843271291756275916749190897603300862536003960079038965875899548353753161740067300719965870009897928862519258","810832331987969628351418078504332392247131184391226342381809295833606429444336311948291108659380488893722862319912753896246389471094611303257167801120338575451771239674731893223825779197241894579580355288102815104406290939537760612145064275784417986376319025425366570306747850885253923067737589536003995906","28661271523396927448528593664881617664934603873450352614615078773966276533051044212592843541860975352807023751552565152900731451973162214392923052126422525165445663631679882220550060601855258804462767700604452190486032592877100063575529327306038453201644476577569264260193187415194076766745667847694285734888","39563165546543447616991835458584360447932158182707606827736371763822343490311148902608572389907662664722226477637689704318541819987960030937252895056703187093242571014186479095084682350532096212125733724620918652364880147235278160417524413214625710281604867066684840140973644482976979517196464659926169000184"},"25367748248637752665330361016817390467695903989452856031314467186943671674700613499853569740797020789306409417253368283294545238870635090881473336296499388009507486362929320593653324441598984523334727362474464624918078354783068789012420351783478784331293763177762519581917864156480083370074419227630584460218","9164300190077766154636975508383426908400769523038721379391015460896092277711923747022525313945691035124493297673121532181168664224614211179514881969268958520038996105535694293321072717120920902179497325313158248950533089526496472591146356811071684664669922931298665945792707380223628148931178173642799568857", libgDir, gFunctionName);

	SecureInt num("33895234720937968940292402579715202831460573975064184310671348998803012382874552887777632934713247175543293538952562713931575836254773591553341622632847421260059800677812946742286428813174177718815924935902145305159425444011491072390954861731935240455096325431481697237604285165210960999843940248899756032512",cs);
	SecureInt fact("20891834687574702466889051885252160471905502529145671772681092447518778538902708710092571783313752391123879756778773380296554867777927864103893206412793609266564724283051044512177484327961601629182419994375497251898242290416511665898946041272531401310562367858151794252564316673837339888549314794061660402083",cs);
	SecureInt i("1884638994289867776180585892092247264455185922564174083757285778737640415524921459962399439989877345322271441804218998535761857841532846919278486634482868379837619289008964430831808636097706900196889217848565524946716565966841816276760371330130495130475093981997318817006221233629304024926391486959308868676",cs);
	SecureInt result("36107910613439921756697207150511733735824342922662705880014636278220658978517609735138199406242964996097436886604263680084278173668464525527854963272508904700855178942514360021479819299319262872908263019307760922122777544982073891808464003053348761545630983564766175518288487279437844971746272682645623197664",cs);
	
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


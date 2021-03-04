#include "IAsteroid.hpp"
#include "IMiningLaser.hpp"
#include "MiningBarge.hpp"
#include "AsteroKreog.hpp"
#include "KoalaSteroid.hpp"
#include "StripMiner.hpp"
#include "DeepCoreMiner.hpp"

int     main(void){
    MiningBarge *barge = new MiningBarge();
    IAsteroid *astero = new AsteroKreog();
    IAsteroid *koala = new KoalaSteroid();
    IMiningLaser *deep = new DeepCoreMiner();
    IMiningLaser *strip = new StripMiner();

    barge->equip(deep);
    barge->equip(strip);
    barge->equip(deep);
    barge->equip(strip);
    barge->equip(strip);
    barge->mine(astero);
    barge->mine(koala);

    delete barge;
    delete astero;
    delete koala;
    delete deep;
    delete strip;

    return 0;
}
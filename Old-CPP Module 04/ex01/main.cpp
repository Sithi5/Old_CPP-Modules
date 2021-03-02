#include "Character.hpp"
#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

int main()
{
	Character* moi = new Character("moi");

	std::cout << *moi;

	Enemy* rs = new RadScorpion();
    std::cout << rs->getType() << " has now " << rs->getHP() << " HP" << std::endl;
	Enemy* sm = new SuperMutant();

	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();

    std::cout << sm->getType() << " has now " << sm->getHP() << " HP" << std::endl << std::endl;
	moi->equip(pr);
	std::cout << *moi;
	moi->equip(pf);

	moi->attack(rs);
	std::cout << *moi;
	moi->equip(pr);
	std::cout << *moi;
	moi->attack(rs);
    std::cout << rs->getType() << " has now " << rs->getHP() << " HP" << std::endl << std::endl;
	std::cout << *moi;
	moi->attack(sm);
    std::cout << sm->getType() << " has now " << sm->getHP() << " HP" << std::endl << std::endl;
    for (int i=0; sm->getHP() > 50; i++)
    {
        moi->attack(sm);
        std::cout << *moi;
        if (moi->getAP() < 10)
        {
            std::cout << std::endl << "I need some Nuka-Cola Quantum! *pssst*" << std::endl;
            moi->recoverAP();
            std::cout << *moi <<std::endl;
        }
    }
    std::cout << sm->getType() << " has now " << sm->getHP() << " HP" << std::endl;
    moi->equip(pf);
    moi->attack(sm);
    std::cout << *moi;



	return 0;
}
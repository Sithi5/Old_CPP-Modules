#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

int	main(void) {
	Sorcerer	albus("Albus Dumbledor", "Hogwarts Director");
	Victim		vic("Vicky");
	Peon		pepe("Pepe");
	Victim		*victimed_p = new Peon("Vipe");
	
	std::cout << albus << vic << pepe << *victimed_p;

	albus.polymorph(vic);
	albus.polymorph(pepe);
	albus.polymorph(*victimed_p);
	
	delete victimed_p;

	return (0);
}
#include "KoalaSteroid.hpp"

KoalaSteroid::KoalaSteroid(void): _name("Asteroid") {}

KoalaSteroid::KoalaSteroid(std::string const &name) : _name(name) {}

KoalaSteroid::KoalaSteroid(KoalaSteroid const &copy) {
	*this = copy;
}

KoalaSteroid::~KoalaSteroid(void) {}

KoalaSteroid &KoalaSteroid::operator=(KoalaSteroid const &rhs) {
	this->_name = rhs.getName();
	return (*this);
}

std::string KoalaSteroid::getName(void) const{
	return (this->_name);
}

std::string	KoalaSteroid::beMined(DeepCoreMiner *dcminer) const{
	(void)dcminer;
	return "Dragonite";
}
std::string	KoalaSteroid::beMined(StripMiner *sminer) const{
	(void)sminer;
	return "Flavium";
}
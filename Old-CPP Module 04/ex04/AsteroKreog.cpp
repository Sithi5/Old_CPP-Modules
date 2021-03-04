#include "AsteroKreog.hpp"

AsteroKreog::AsteroKreog(void) : _name("Comet") {}

AsteroKreog::AsteroKreog(std::string const &name) : _name(name) {}

AsteroKreog::AsteroKreog(AsteroKreog const &copy) {
	*this = copy;
}

AsteroKreog::~AsteroKreog(void) {}

AsteroKreog &AsteroKreog::operator=(AsteroKreog const &rhs) {
	this->_name = rhs.getName();
	return (*this);
}

std::string AsteroKreog::getName(void) const{
	return (this->_name);
}

std::string	AsteroKreog::beMined(DeepCoreMiner *dcminer) const{
	(void)dcminer;
	return "Mithril";
}
std::string	AsteroKreog::beMined(StripMiner *sminer) const{
	(void)sminer;
	return "Tartarite";
}
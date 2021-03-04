#ifndef EX04_ASTEROKREOG_HPP
# define EX04_ASTEROKREOG_HPP

# include "IAsteroid.hpp"

class AsteroKreog : public IAsteroid
{
	private:
		std::string _name;

	public:
		AsteroKreog(void);
		AsteroKreog(std::string const &name);
		AsteroKreog(AsteroKreog const &copy);
		virtual ~AsteroKreog(void);
		
		AsteroKreog &operator=(AsteroKreog const &rhs);

		std::string getName(void) const;

		virtual std::string beMined(DeepCoreMiner *dcminer) const;
		virtual std::string beMined(StripMiner *sminer) const;
};

#endif
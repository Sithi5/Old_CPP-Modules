#ifndef EX04_KOALASTEROID_HPP
# define EX04_KOALASTEROID_HPP

# include "IAsteroid.hpp"

class KoalaSteroid : public IAsteroid
{
	private:
		std::string _name;

	public:
		KoalaSteroid(void);
		KoalaSteroid(std::string const &name);
		KoalaSteroid(KoalaSteroid const &copy);
		virtual ~KoalaSteroid(void);
		
		KoalaSteroid &operator=(KoalaSteroid const &rhs);

		std::string getName(void) const;

		std::string beMined(DeepCoreMiner *dcminer) const;
		std::string beMined(StripMiner *sminer) const;
};

#endif
#ifndef OLD_CPP_MODULES_RADSCORPION_HPP
# define OLD_CPP_MODULES_RADSCORPION_HPP

# include "Enemy.hpp"

class RadScorpion: public Enemy
{
	public:
		RadScorpion(void);
		RadScorpion(RadScorpion const &copy);
		virtual ~RadScorpion();

		RadScorpion &	operator=(RadScorpion const &rhs);
};

#endif
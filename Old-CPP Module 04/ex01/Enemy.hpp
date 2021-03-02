#ifndef OLD_CPP_MODULES_ENEMY_HPP
# define OLD_CPP_MODULES_ENEMY_HPP

# include <iostream>

class Enemy
{
	public:
		Enemy(int hp, std::string const & type);
		Enemy(Enemy const &copy);
		virtual ~Enemy();

		Enemy &		operator=(Enemy const &rhs);

		std::string	getType() const;
		int 		getHP() const;
		void		setType(const std::string type);
		void		setHP(const int hp);
		virtual void takeDamage(int);
	
	protected:
		int			_hp;
		std::string	_type;

	private:
		Enemy(void);
};

#endif
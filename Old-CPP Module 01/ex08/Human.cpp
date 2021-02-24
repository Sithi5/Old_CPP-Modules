#include "Human.hpp"


void Human::meleeAttack(std::string const & target){
    std::cout << "functions " << __func__ << " of " << "human" << " has been called." << std::endl;
    std::cout << "human" << " melee attack " << target << "." << std::endl;

}
void Human::rangedAttack(std::string const & target){
    std::cout << "functions " << __func__ << " of " << "human" << " has been called." << std::endl;
    std::cout << "human" << " ranged attack " << target << "." << std::endl;
}
void Human::intimidatingShout(std::string const & target){
    std::cout << "functions " << __func__ << " of " << "human" << " has been called." << std::endl;
    std::cout << "human" << " intimidated " << target << "." << std::endl;
}

void Human::action(std::string const & action_name, std::string const & target){
    void (Human::*p[3])(std::string const & target);
    std::string key[3];
    p[0] = &Human::meleeAttack;
    key[0] = "meleeAttack";
    p[1] = &Human::rangedAttack;
    key[1] = "rangedAttack";
    p[2] = &Human::intimidatingShout;
    key[2] = "intimidatingShout";
    int key_size = sizeof(key) / sizeof(*key);

    for(int i = 0; i < key_size; i++){
        if (key[i] == action_name){
            (this->*p[i])(target);
            return;
        }
    }
    throw std::runtime_error("Action is not available.");
}
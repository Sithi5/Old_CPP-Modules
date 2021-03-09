
#include "Litteral.hpp"

Litteral::Litteral(std::string &input) : _input(input) {
    if (this->_input.length() == 1) {
        if (isdigit(this->_input[0])) {
            this->_litteral_type = std::string("int");
            this->_litteral_int = atoi(this->_input.c_str());
        } else {
            this->_litteral_type = std::string("char");
            this->_litteral_char = this->_input[0];
        }
    } else {
        bool flag_digit_before_dot = false;
        bool flag_dot = false;
        bool flag_digit_after_dot = false;
        for (unsigned int i = 0; i < this->_input.size(); i++) {

            if (i == 0 && (this->_input[i] == '-' || this->_input[i] == '+')) {
                continue;
            } else if (isdigit(this->_input[i]) && !flag_dot) {
                flag_digit_before_dot = true;
            } else if (isdigit(this->_input[i]) && flag_dot && !flag_digit_after_dot) {
                flag_digit_after_dot = true;
            } else if (this->_input[i] == '.') {
                if (!flag_digit_before_dot || flag_dot) {
                    throw std::runtime_error("Two dot in the input, it cannot be any of the available type.");
                }
                flag_dot = true;
            } else if (this->_input[i] == 'f' && flag_digit_before_dot && flag_dot && flag_digit_after_dot &&
                       i == this->_input.size() - 1) {
                this->_litteral_type = std::string("float");
                this->_litteral_float = atof(this->_input.c_str());
            } else if (!isdigit(this->_input[i])) {
                throw std::runtime_error(std::string("The character : ") + this->_input[i] + " is invalid.");
            }
            if (isdigit(this->_input[i]) && i == this->_input.size() - 1 && flag_dot) {
                this->_litteral_type = std::string("double");
                this->_litteral_double = atof(this->_input.c_str());
            }
            else if (isdigit(this->_input[i]) && i == this->_input.size() - 1){
                this->_litteral_type = std::string("int");
                this->_litteral_int = atoi(this->_input.c_str());
            }
        }
    }
    std::cout << "Litteral type is : " << this->_litteral_type << std::endl;
}

Litteral::Litteral() {}

Litteral::Litteral(const Litteral &cpy) {
    *this = cpy;
}

Litteral &Litteral::operator=(const Litteral &rhs) {
    if (this != &rhs) {
        this->_input = rhs._input;
    }
    return *this;
}


Litteral::~Litteral() {

}

Litteral::operator char() {
    if (!(this->_litteral_type.compare("char"))) {
        return this->_litteral_char;
    } else if (!(this->_litteral_type.compare("int"))) {
        return static_cast<char>(this->_litteral_int);
    } else if (!(this->_litteral_type.compare("float"))) {
        return static_cast<char>(this->_litteral_float);}
    else{
        return static_cast<char>(this->_litteral_double);}
}

Litteral::operator int() {
    if (!(this->_litteral_type.compare("char"))) {
        return static_cast<int>(this->_litteral_char);
    } else if (!(this->_litteral_type.compare("int"))) {
        return this->_litteral_int;
    } else if (!(this->_litteral_type.compare("float"))) {
        return static_cast<int>(this->_litteral_float);
    } else {
        return static_cast<int>(this->_litteral_double);
    }
}

Litteral::operator float() {
    if (!(this->_litteral_type.compare("char"))) {
        return static_cast<float>(this->_litteral_char);
    } else if (!(this->_litteral_type.compare("int"))) {
        return static_cast<float>(this->_litteral_int);
    } else if (!(this->_litteral_type.compare("float"))) {
        return this->_litteral_float;
    } else {
        return static_cast<float>(this->_litteral_double);
    }
}

Litteral::operator double() {
    if (!(this->_litteral_type.compare("char"))) {
        return static_cast<double>(this->_litteral_char);
    } else if (!(this->_litteral_type.compare("int"))) {
        return static_cast<double>(this->_litteral_int);
    } else if (!(this->_litteral_type.compare("float"))) {
        return static_cast<double>(this->_litteral_float);
    } else {
        return this->_litteral_double;
    }
}


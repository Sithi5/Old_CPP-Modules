
#include "Litteral.hpp"

Litteral::Litteral(std::string &input) : _input(input) {
    if (this->LitteralIsChar()) {
        this->setLitteralType(std::string("char"));
        this->setLitteralChar(this->getInput()[0]);
    } else if (this->LitteralIsInt()) {
        this->setLitteralType(std::string("int"));
        this->setLitteralInt(atoi(this->getInput().c_str()));
    } else if (this->LitteralIsFloat()) {
        this->setLitteralType(std::string("float"));
        this->setLitteralFloat(atof(this->getInput().c_str()));
    } else if (this->LitteralIsDouble()) {
        this->setLitteralType(std::string("double"));
        this->setLitteralDouble(atof(this->getInput().c_str()));
    } else {
        throw std::runtime_error("input is not any of accepted litteral type.");
    }
    std::cout << "Litteral type is : " << this->getLitteralType() << std::endl;
}

Litteral::Litteral() {}

Litteral::Litteral(const Litteral &cpy) {
    *this = cpy;
}

Litteral &Litteral::operator=(const Litteral &rhs) {
    if (this != &rhs) {
        this->setInput(rhs._input);
    }
    return *this;
}

Litteral::~Litteral() {
}

Litteral::operator char() const throw(ImpossibleConversion) {
    if (!(this->getLitteralType().compare("char"))) {
        return this->getLitteralChar();
    } else if (!(this->getLitteralType().compare("int"))) {
        return static_cast<char>(this->getLitteralInt());
    } else if (!(this->getLitteralType().compare("float"))) {
        if (this->getInput() == "+inff" || this->getInput() == "-inff" || this->getInput() == "nanf") {
            throw Litteral::ImpossibleConversion();
        } else {
            return static_cast<char>(this->getLitteralFloat());
        }
    } else {
        if (this->getInput() == "+inf" || this->getInput() == "-inf" || this->getInput() == "nan") {
            throw Litteral::ImpossibleConversion();
        } else {
            return static_cast<char>(this->getLitteralDouble());
        }
    }
}

Litteral::operator int() const throw(ImpossibleConversion) {
    if (!(this->getLitteralType().compare("char"))) {
        return static_cast<int>(this->getLitteralChar());
    } else if (!(this->getLitteralType().compare("int"))) {
        return this->getLitteralInt();
    } else if (!(this->getLitteralType().compare("float"))) {
        if (this->getInput() == "+inff" || this->getInput() == "-inff" || this->getInput() == "nanf") {
            throw Litteral::ImpossibleConversion();
        } else {
            return static_cast<int>(this->getLitteralFloat());
        }
    } else {
        if (this->getInput() == "+inf" || this->getInput() == "-inf" || this->getInput() == "nan") {
            throw Litteral::ImpossibleConversion();
        } else {
            return static_cast<int>(this->getLitteralDouble());
        }
    }
}

Litteral::operator float() const throw(ImpossibleConversion) {
    if (!(this->getLitteralType().compare("char"))) {
        return static_cast<float>(this->getLitteralChar());
    } else if (!(this->getLitteralType().compare("int"))) {
        return static_cast<float>(this->getLitteralInt());
    } else if (!(this->getLitteralType().compare("float"))) {
        return this->getLitteralFloat();
    } else {
        return static_cast<float>(this->getLitteralDouble());
    }
}

Litteral::operator double() const throw(ImpossibleConversion) {
    if (!(this->getLitteralType().compare("char"))) {
        return static_cast<double>(this->getLitteralChar());
    } else if (!(this->getLitteralType().compare("int"))) {
        return static_cast<double>(this->getLitteralInt());
    } else if (!(this->getLitteralType().compare("float"))) {
        return static_cast<double>(this->getLitteralFloat());
    } else {
        return this->getLitteralDouble();
    }
}

const std::string &Litteral::getLitteralType() const {
    return this->_litteral_type;
}

void Litteral::setLitteralType(const std::string &litteralType) {
    this->_litteral_type = litteralType;
}

const std::string &Litteral::getInput() const {
    return this->_input;
}

void Litteral::setInput(const std::string &input) {
    this->_input = input;
}

int Litteral::getLitteralInt() const {
    return this->_litteral_int;
}

void Litteral::setLitteralInt(int litteralInt) {
    this->_litteral_int = litteralInt;
}

char Litteral::getLitteralChar() const {
    return this->_litteral_char;
}

void Litteral::setLitteralChar(char litteralChar) {
    this->_litteral_char = litteralChar;
}

float Litteral::getLitteralFloat() const {
    return this->_litteral_float;
}

void Litteral::setLitteralFloat(float litteralFloat) {
    this->_litteral_float = litteralFloat;
}

double Litteral::getLitteralDouble() const {
    return this->_litteral_double;
}

void Litteral::setLitteralDouble(double litteralDouble) {
    this->_litteral_double = litteralDouble;
}

bool Litteral::LitteralIsChar() {
    if (this->getInput().length() == 1 && !isdigit(this->getInput()[0])) {
        return true;
    }
    return false;
}

bool Litteral::LitteralIsInt() {
    for (unsigned int i = 0; i < this->getInput().size(); i++) {
        if (i == 0 && this->getInput().size() > 1 && (this->getInput()[i] == '-' || this->getInput()[i] == '+')) {
            continue;
        }
        if (!isdigit(this->getInput()[i])) {
            return false;
        }
    }
    return true;
}

bool Litteral::LitteralIsFloat() {
    if (this->getInput() == "+inff" || this->getInput() == "-inff" || this->getInput() == "nanf") {
        return true;
    }

    bool flag_digit_before_dot = false;
    bool flag_dot = false;
    bool flag_digit_after_dot = false;
    for (unsigned int i = 0; i < this->getInput().size(); i++) {
        if (i == 0 && this->getInput().size() > 1 && (this->getInput()[i] == '-' || this->getInput()[i] == '+')) {
            continue;
        }
        if (!isdigit(this->getInput()[i])) {
            if (!flag_dot && flag_digit_before_dot && this->getInput()[i] == '.') {
                flag_dot = true;
            } else if (i == this->getInput().size() - 1 && flag_digit_after_dot && flag_digit_before_dot && flag_dot &&
                       this->getInput()[i] == 'f') {
                return true;
            } else {
                return false;
            }
        } else if (!flag_digit_before_dot) {
            flag_digit_before_dot = true;
        } else if (!flag_digit_after_dot && flag_digit_before_dot && flag_dot) {
            flag_digit_after_dot = true;
        }
    }
    return false;
}

bool Litteral::LitteralIsDouble() {
    if (this->getInput() == "+inf" || this->getInput() == "-inf" || this->getInput() == "nan") {
        return true;
    }

    bool flag_digit_before_dot = false;
    bool flag_dot = false;
    bool flag_digit_after_dot = false;
    for (unsigned int i = 0; i < this->getInput().size(); i++) {
        if (i == 0 && this->getInput().size() > 1 && (this->getInput()[i] == '-' || this->getInput()[i] == '+')) {
            continue;
        }
        if (!isdigit(this->getInput()[i])) {
            if (!flag_dot && flag_digit_before_dot && this->getInput()[i] == '.') {
                flag_dot = true;
            } else {
                return false;
            }
        } else if (!flag_digit_before_dot) {
            flag_digit_before_dot = true;
        } else if (!flag_digit_after_dot && flag_digit_before_dot && flag_dot) {
            flag_digit_after_dot = true;
        }
    }
    if (flag_digit_after_dot && flag_digit_before_dot && flag_dot) {
        return true;
    } else {
        return false;
    }
}

const char *Litteral::ImpossibleConversion::what() const throw() {
    return "This conversion is not possible.";
}
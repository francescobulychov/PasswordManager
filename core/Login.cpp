#include "Login.h"

Login::Login(const unsigned int ID) : AbstractItem(ID) {}

Login::Login(const unsigned int ID, const std::string name, const std::string username, const std::string password, const std::string site) : AbstractItem(ID, name), username(username), password(password), site(site) {}

const std::string& Login::getUsername() const {
    return username;
}

Login& Login::setUsername(const std::string username) {
    this->username = username;
    return *this;
}

const std::string& Login::getPassword() const {
    return password;
}

Login& Login::setPassword(const std::string password) {
    this->password = password;
    return *this;
}

const std::string& Login::getSite() const {
    return site;
}

Login& Login::setSite(const std::string site) {
    this->site = site;
    return *this;
}

void Login::accept(IVisitor& visitor) {
    visitor.visit(*this);
}

void Login::accept(IConstVisitor& visitor) const {
    visitor.visit(*this);
}

Login* Login::clone() const {
    return new Login(*this);
}

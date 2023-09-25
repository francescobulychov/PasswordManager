#ifndef LOGIN_H
#define LOGIN_H

#include "AbstractItem.h"

class Login : public AbstractItem {

private:
    std::string username;
    std::string password;
    std::string site;

public:
    Login(const unsigned int ID);
    Login(const unsigned int ID, const std::string name, const std::string username, const std::string password, const std::string site);
    const std::string& getUsername() const;
    Login& setUsername(const std::string username);
    const std::string& getPassword() const;
    Login& setPassword(const std::string password);
    const std::string& getSite() const;
    Login& setSite(const std::string site);
    virtual void accept(IVisitor& visitor);
    virtual void accept(IConstVisitor& visitor) const;
    virtual Login* clone() const;
};

#endif

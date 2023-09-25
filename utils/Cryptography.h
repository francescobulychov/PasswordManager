#ifndef CRYPTOGRAPHY_H
#define CRYPTOGRAPHY_H

#include <string>

class Cryptography {

private:
    static const std::string key;
    static const std::string iv;

public:
    static std::string encrypt(const std::string& text);
    static std::string decrypt(const std::string& text);
};

#endif

#include "Cryptography.h"
#include "base64.h"

#include <openssl/evp.h>

const std::string Cryptography::key = "a6e15cb3704086f9beaca3bbfcb1c18";
const std::string Cryptography::iv = "5b78358d55d1f68fb58459d0307dab9f";

std::string Cryptography::encrypt(const std::string& text) {
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, reinterpret_cast<const unsigned char*>(key.c_str()), reinterpret_cast<const unsigned char*>(iv.c_str()));

    std::string encryptedText;
    int len;
    int maxOutputLength = text.length() + EVP_MAX_BLOCK_LENGTH;
    encryptedText.resize(maxOutputLength);

    EVP_EncryptUpdate(ctx, reinterpret_cast<unsigned char*>(&encryptedText[0]), &len, reinterpret_cast<const unsigned char*>(text.c_str()), text.length());
    int encryptedLength = len;

    EVP_EncryptFinal_ex(ctx, reinterpret_cast<unsigned char*>(&encryptedText[encryptedLength]), &len);
    encryptedLength += len;

    EVP_CIPHER_CTX_free(ctx);

    encryptedText.resize(encryptedLength);
    return base64_encode(encryptedText);
}

std::string Cryptography::decrypt(const std::string& text) {
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, reinterpret_cast<const unsigned char*>(key.c_str()), reinterpret_cast<const unsigned char*>(iv.c_str()));

    std::string decodedText = base64_decode(text);

    std::string decryptedText;
    int len;
    int maxOutputLength = decodedText.length();
    decryptedText.resize(maxOutputLength);

    EVP_DecryptUpdate(ctx, reinterpret_cast<unsigned char*>(&decryptedText[0]), &len, reinterpret_cast<const unsigned char*>(decodedText.c_str()), decodedText.length());
    int decryptedLength = len;

    EVP_DecryptFinal_ex(ctx, reinterpret_cast<unsigned char*>(&decryptedText[decryptedLength]), &len);
    decryptedLength += len;

    EVP_CIPHER_CTX_free(ctx);

    decryptedText.resize(decryptedLength);
    return decryptedText;
}

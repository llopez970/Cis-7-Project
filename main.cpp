#include <iostream>

using namespace std;

class VCipher {
private:
    string text, key;

    string Key(){
        int size = text.length();

        for (int i = 0;; i++ ) {
            if (size == i)
                i = 0;
            if (key.length() == text.length())
                break;
            key.push_back(key[i]);
        }

        return key;
    }

public:

    void setString(string input){
        text = input;
    }

    void setKeyWord(string Key){
        key = Key;
    }


    string Encrypt(){

        string Encrypt;
        string Encrypt_Key = Key();

        for (int i = 0; i < text.size(); i++){
        char p = toupper(text[i]);
        char k = toupper(Encrypt_Key[i]);

        char c = 'A' + ((p - 'A') + (k - 'A')) % 26;
        Encrypt.push_back(c);

        }
        return Encrypt;
    }

    string Decrypt(){

        string Decrypt;
        string Decrypt_Key = Key();

        for (int i = 0; i < text.size(); i++){
            char e = toupper(text[i]);
            char k = toupper(Decrypt_Key[i]);

            char c = 'A' + ((e - 'A') - (k - 'A')+26) % 26;
            Decrypt.push_back(c);

        }
        return Decrypt;
    }
};


int main() {
   VCipher c;

   string plaintext, keyword;

   cout << "Enter Plaintext: ";
   cin >> plaintext;

   cout << "Enter Keyword: ";
   cin >> keyword;


   c.setString(plaintext);
   c.setKeyWord(keyword);

   string encrypt = c.Encrypt();

   cout << "Encrypted: " << encrypt << "\n";
   c.setString(encrypt);
   cout << "Decrypted: " << c.Decrypt() << "\n";
    return 0;
}

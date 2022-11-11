// Author: Sara Nessim 
// Project: Vigenere Cypher 
// 11/10/22

#include <iostream>
#include <ctype.h>
#include <string>

using namespace std;

int main () {
    string message;
    string messageKey;
    cout << "Welcome! Please enter a message below to encrypt" << endl;
    cin >> message;
    cout << "Please enter a key that you want to use" << endl;
    cin >> messageKey;
    
    int userInput = message.length(); 
    int key = messageKey.length();
    int e,d=0;
    
    for(e = 0; e < userInput; e++)
    if(message[e]==tolower(char(int(message[e])-32)))
    message[e]=toupper(message[e]);
    
    for(e = 0; e < key; e++)
    if(messageKey[e]==tolower(char(int(messageKey[e])-32)))
    messageKey[e]=toupper(messageKey[e]);
    
    string generatedKey=message;
    
    for(e = 0; e < userInput; e++){
        if(d == key)
        d = 0;
        
        generatedKey[e] = messageKey[d];
        d++;
    }
    
    string EncryptedMessage=message;
    string DecryptedMesssage=message;
    
    //this is for the encryption portion
    for(e = 0; e < userInput; ++e)
        EncryptedMessage[e] = ((message[e] + generatedKey[e]) % 26) + 'A';
        
    //this is for the decryption portion
    for(e = 0; e < userInput; ++e)
        DecryptedMesssage[e] = (((EncryptedMessage[e] - generatedKey[e])+26) % 26) + 'A';
        
    cout << "The original message you input was: " << message;
    cout << "\nThe key you input was " << messageKey;
    cout << "\nThe new key that was generated was: " << generatedKey;
    cout << "\nThe encrypted message is: " << EncryptedMessage;
    cout << "\nThe decrypted message is: " << DecryptedMesssage;
    
    return 0;
}
    
    
    
    
    
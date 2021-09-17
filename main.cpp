// This program is used to generator one OTP at a time
#include "sha256.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int, char**)
{
  string temp = "0";
  cout << "Please input 0 to get the new key" << endl;
  cin >> temp;
  while(temp == "0"){
    // create a new hashing object
    SHA256 sha256;
    string hashkey = "";
    int round = 0;

    //retrive old OTP and round from secret.txt
    ifstream inputSecretFile;
    inputSecretFile.open("secret.txt");
    inputSecretFile >>  hashkey;
    inputSecretFile >>  round;
    inputSecretFile.close();
  
    //write new key to secret.txt
    ofstream secretFile;
    secretFile.open("secret.txt");

    // secret.txt contain the trial of one-time password and the previous hashed key
    string newkey = sha256(hashkey);
    //cout << newkey << endl;
    cout << "OTP: " << newkey.substr(newkey.length()-6) << endl;
    round++;
    secretFile << sha256(hashkey) << endl << round << endl;

    cout << "Please input 0 to get the new key" << endl;
    cin >> temp;
  }
  cout << "end" << endl;
  return 0;
}
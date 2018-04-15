//
// Created by Dennis Furrer on 15/04/2018.
//

#include "Block.h" //include block header file
#include "sha256.h" //include sha256 header file
#include <ctime>
#include <sstream>

//block constructor
Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn) {
    _nNonce = -1;
    _tTime = time(nullptr); //set time to current time
}

//accessor to block hash
string Block::GetHash() {
    return _sHash; //return hash
}

//proof of work
void Block::MineBlock(uint32_t nDifficulty) {
    char cstr[nDifficulty + 1]; //create character array

    //fill array with zeros
    for (uint32_t i = 0; i < nDifficulty; ++i) {
        cstr[i] = '0';
    }

    cstr[nDifficulty] = '\0'; //final array element set to string terminator character
    string str(cstr); //convert character array to string

    //loop while work is not complete
    do {
        _nNonce++; //increment nonce
        _sHash = _CalculateHash(); //calculate hash
    } while (_sHash.substr(0, nDifficulty) != str);

    cout << "Block mined: " << _sHash << endl; //console feedback for mined block
}

//calculate hash
inline string Block::_CalculateHash() const { //inline keyword used for efficiency
    stringstream ss; //string stream to store block contents to be hashed
    ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash; //append block attributes to string stream

    return sha256(ss.str()); //convert string stream to string and hash
}
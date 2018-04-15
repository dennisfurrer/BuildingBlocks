//
// Created by Dennis Furrer on 15/04/2018.
//

#ifndef BB_BLOCK_H
#define BB_BLOCK_H

#include <cstdint>
#include <iostream>

class Block{
public:
    std::string sPrevHash; //previous block hash
    Block(uint32_t nIndexIn, const std::string &sDataIn); //constructor signature - const keyword and reference modifier (&) used so params are passed by reference but can't be changed. This improves efficiency and saves memory.
    std::string GetHash(); //method signature for getting hash of block
    void MineBlock(uint32_t nDifficulty); //method signature for mining of block
public:
    uint32_t _nIndex; //block index
    int64_t _nNonce; //nonce
    std::string _sData; //block data
    std::string _sHash; //block hash
    time_t _tTime; //block timestamp
    std::string _CalculateHash() const; //const keyword ensures the output can't be changed
};

#endif //BB_BLOCK_H

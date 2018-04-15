//
// Created by Dennis Furrer on 15/04/2018.
//

#ifndef BB_BLOCKCHAIN_H
#define BB_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Block.h" //include block header file

class Blockchain {
public:
    Blockchain(); //constructor signature
    void AddBlock(Block bNew); //method signature for adding a new block to the blockchain
    Block GetBlockByIndex(uint32_t index) const; //method signature for getting block - const keyword ensures the output can't be changed
private:
    uint32_t _nDifficulty; //difficulty of proof of work - number represents number of zeros at start of hash
    std::vector<Block> _vChain; //data structure for storing blockchain
    Block _GetLastBlock() const; //method signature for getting previous block - const keyword ensures the output can't be changed
};


#endif //BB_BLOCKCHAIN_H

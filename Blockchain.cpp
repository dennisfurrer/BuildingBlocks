//
// Created by Dennis Furrer on 15/04/2018.
//

#include "Blockchain.h" //include blockchain header file

//signature for blockchain constructor
Blockchain::Blockchain() {
    _vChain.emplace_back(Block(0, "Genesis Block")); //add genesis block to the blockchain
    _nDifficulty = 5; //difficulty of proof of work - number represents number of zeros at start of hash
}

//add block to blockchain
void Blockchain::AddBlock(Block bNew) {
    bNew.sPrevHash = _GetLastBlock().GetHash(); //set block's previous hash
    bNew.MineBlock(_nDifficulty); //mine the block
    _vChain.push_back(bNew); //add the block to the blockchain
}

//return previous block in the blockchain
Block Blockchain::_GetLastBlock() const {
    return _vChain.back(); //return previous block
}

//return block by index
Block Blockchain::GetBlockByIndex(uint32_t index) const {
    return _vChain[index]; //return block
}
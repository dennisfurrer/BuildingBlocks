//
// Created by Dennis Furrer on 15/04/2018.
//

#include "Blockchain.h" //include blockchain header file
#include <iostream>
#include <string>

int main() {
    Blockchain bChain = Blockchain(); //initialise blockchain
    std::string sResponse; //string to store user input
    uint32_t nBlockNumber = 2; //set to 2 because index starts at 0 and genesis block is #1
    std::string sBlockData; //string to store block data
    Block bCurrentBlock = bChain.GetBlockByIndex(0); //initialise current block object

    std::cout << "Mining block 1..." << std::endl; //console feedback for current block being mined
    bChain.AddBlock(Block(1, "Block 1 Data")); //add genesis block to the blockchain

    //loop while user responds is yes
    do {
        std::cout << "Mine next block? (y/n)" << std::endl; //request user response
        std::cin >> sResponse; //store response in string
        if (sResponse != "y") break; //if response is not "y" then terminate
        std::cout << "Mining block " << nBlockNumber << "..." << std::endl; //console feedback for current block being mined
        sBlockData = "Block " + std::to_string(nBlockNumber) + " Data"; //create block data and store in string variable
        bChain.AddBlock(Block(nBlockNumber, sBlockData)); //add block to the blockchain
        nBlockNumber++; //increment block number
    } while (sResponse == "y");

    //if user response is no
    if (sResponse == "n") {
        //for each block in the blockchain print block contents
        for (uint32_t i = 0; i <= nBlockNumber-2; i++) {
            bCurrentBlock = bChain.GetBlockByIndex(i); //set variable to block in the blockchain
            //console output to print block's attributes
            std::cout << "Block " + std::to_string(bCurrentBlock._nIndex) + "\n----------"
                 << "\nNonce: " << std::to_string(bCurrentBlock._nNonce)
                 << "\nData: " << bCurrentBlock._sData
                 << "\nHash: " << bCurrentBlock._sHash
                 << "\nTimestamp: " << bCurrentBlock._tTime
                 << "\n" << std::endl;
        }
    }

    return 0; //exit
}
#pragma once

#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"

class MerkelMain
{
    public:
        MerkelMain();
        void init();
    private:
        void printMenu();
        int getUserOption();
        void printHelp();
        void printMarketStats();
        void enterOffer();
        void enterBid();
        void printWallet();
        void goToNextTimeFrame();
        void processUserOption(int userOption);

        OrderBook orderBook{"20200317.csv"};
};
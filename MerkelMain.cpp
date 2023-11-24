#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"

MerkelMain::MerkelMain()
{

};

void MerkelMain::init()
{
    int input;

    currentTime = orderBook.getEarliestTime();

    while(true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
};

void MerkelMain::printMenu()
{
    std::cout << "1: Print help " << std::endl;

    std::cout << "2: Print exchange stats " << std::endl;

    std::cout << "3: Make an offer " << std::endl;

    std::cout << "4: Make a bid " << std::endl;

    std::cout << "5: Print a wallet " << std::endl;

    std::cout << "6: Continue " << std::endl;

    std::cout << "===================" << std::endl;

    std::cout << "Current time is: " << currentTime << std::endl;
};

int MerkelMain::getUserOption()
{
    int userOption;

    std::cout << "Type 1-6 : ";
    std::cin >> userOption;
    std::cout << "===================" << std::endl;
    std::cout << "You chose: " << userOption << std::endl;

    return userOption;
};

void MerkelMain::printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and amke bids and offers. " << std::endl;
};

void MerkelMain::printMarketStats()
{
    //std::cout << "OrderBook contains : " << orders.size() << " entries" << std::endl;

    for(std::string const& p : orderBook.getKnownProducts())
    {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
        std::cout << "Asks seen: " << entries.size() << std::endl;
        std::cout << "Max ask: " << OrderBook::getHightPrice(entries) << std::endl;
        std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;
    }
};

void MerkelMain::enterAsk()
{
    std::cout << "Make an ask - enter the amount: product, price, amount, eg. ETH/BTC,200,0.5 " << std::endl;
    std::string input;
    std::cin.ignore(1000, '\n');
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input,',');
    if(tokens.size() != 3)
    {
        std::cout << "Bad input! " << input << std::endl;
    }
    else
    {
        OrderBookEntry obe = CSVReader::stringToOorderBookEntry(tokens[1], tokens[2], currentTime, tokens[0], OrderBookType::ask);
    }
}

void MerkelMain::enterBid()
{
    std::cout << "Make a bid - enter the amount " << std::endl;
}
void MerkelMain::printWallet()
{
    std::cout << "Your wallet is empty " << std::endl;
}

void MerkelMain::goToNextTimeFrame()
{
    std::cout << "Going to next time frame " << std::endl;
    currentTime = orderBook.getNextTime(currentTime);
}

void MerkelMain::processUserOption(int userOption)
{
    std::cout << "===================" << std::endl;
    if (userOption == 0)
    {
        std::cout << "Invalid choice. Choose 1-6" << std::endl;
    }
    if (userOption == 1)
    {
        printHelp();
    }
    if (userOption == 2)
    {
        printMarketStats();
    }
    if (userOption == 3)
    {
        enterAsk();
    }
    if (userOption == 4)
    {
        enterBid();
    }
    if (userOption == 5)
    {
        printWallet();
    }
    if (userOption == 6)
    {
        goToNextTimeFrame();
    }
    std::cout << "===================" << std::endl;
}
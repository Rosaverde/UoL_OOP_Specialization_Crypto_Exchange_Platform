# pragma once

#include "OrderBookEntry.h"
#include <vector>
#include <string>

class CSVReader
{
    public:
        CSVReader();

        static std::vector<OrderBookEntry> readCSV(std::string csvFile);
        static std::vector<std::string> tokenise(std::string csvLine, char separator);
        static OrderBookEntry stringToOorderBookEntry(std::string price, std::string amount, std::string timestamp, std::string product, OrderBookType OrderBookType);

    private:
        static OrderBookEntry stringToOorderBookEntry(std::vector<std::string> strings);
};
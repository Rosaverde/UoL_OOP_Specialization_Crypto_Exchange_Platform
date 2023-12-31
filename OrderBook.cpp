#include "OrderBook.h"
#include "CSVReader.h"
#include <map> 

OrderBook::OrderBook(std::string filename)
{
    orders = CSVReader::readCSV(filename);
}
std::vector<std::string> OrderBook::getKnownProducts()
{
    std::vector<std::string> products;

    std::map<std::string, bool> prodMap;

    for(OrderBookEntry& e : orders)
    {
        prodMap[e.product] = true;
    }

    for(auto const& e : prodMap)
    {
        products.push_back(e.first);
    }

    return products;
}

std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, std::string product, std::string timestamp)
{
    std::vector<OrderBookEntry> orders_sub;
    for(OrderBookEntry& e : orders)
    {
        if (e.orderType == type && e.product == product && e.timeStamp == timestamp)
        {
            orders_sub.push_back(e);
        }
    }
    return orders_sub;
}

double OrderBook::getHightPrice(std::vector<OrderBookEntry>& orders)
{
    double max = orders[0].price;
    for(OrderBookEntry& e : orders)
    {
        if(e.price > max)
        {
            max = e.price;
        }
    }
    return max;
}

double OrderBook::getLowPrice(std::vector<OrderBookEntry>& orders)
{
    double min = orders[0].price;
    for(OrderBookEntry& e : orders)
    {
        if(e.price < min)
        {
            min = e.price;
        }
    }
    return min;
}

std::string OrderBook::getEarliestTime()
{
    return orders[0].timeStamp;
}

std::string OrderBook::getNextTime(std::string timeStamp)
{
    std::string next_timeStamp = "";
    for(OrderBookEntry& e : orders)
    {
        if(e.timeStamp > timeStamp)
        {
            next_timeStamp = e.timeStamp;
            break;
        }
    }
    if(next_timeStamp == "")
    {
        next_timeStamp = orders[0].timeStamp;
    }
    return next_timeStamp;
}


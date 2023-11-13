#include "OrderBookEntry.h"

OrderBookEntry::OrderBookEntry(double price,
               double amount,
               std::string timeStamp,
               std::string product,
               OrderBookType orderType)
    : price(price),
      amount(amount),
      timeStamp(timeStamp),
      product(product),
      orderType(orderType)
{
    
}

OrderBookType OrderBookEntry::stringToOrderBookType(std::string s)
{
  if(s == "ask")
  {
    return OrderBookType::ask;
  }
  if(s == "bid")
  {
    return OrderBookType::bid;
  }
  return OrderBookType::unknown;
}
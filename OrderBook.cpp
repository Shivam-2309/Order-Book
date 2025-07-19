#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <list>        
#include <cstdint>    

// Hr stock ki apni khudki orderbook exist kregi
// aur yeh fir actual companies mn aise store hoga ->
// unordered_map<string, OrderBook> mapp;
// string : Name of the Stock jiski OrderBook maintain krni h

// Yeh btaega ki hmara order behave kaise krega
// GoodTillCancel : sits in the bookuntil matched or canceled
// FillAndKill : gets matched and gets finished
enum class OrderType 
{
    GoodTillCancel,
    FillAndKill
};

// current order is a buy or a sell
enum class Side 
{
    Buy,
    Sull
};

// Aliasing Simple Types for simplicity
using Price = std :: int32_t;
using Quantity = std :: uint32_t;
using OrderId = std :: uint64_t;

// Represents a single price level in an order book
// price_ : price kya h uss level pr
// quanitity_ : how many units are available at that level
struct LevelInfo
{
    Price price_;
    Quantity quantity_; 
};

using LevelInfos = std :: vector<LevelInfo>;

// Yeh h ek snapshot hmari Orderbook ka
class OrderbookLeveInfos {
public :
    OrderbookLeveInfos(const LevelInfos& bids, const LevelInfos& asks)
    : bids_ { bids }
    , asks_ { asks }
    {}

    const LevelInfos& getBids() const { return bids_; }
    const LevelInfos& getAsks() const { return asks_; }

private:
    LevelInfos bids_;
    LevelInfos asks_;
};

int main() {
    std :: cout << "CHECK" << std :: endl;
    return 0;
}
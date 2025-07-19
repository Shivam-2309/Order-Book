#include<iostream>
#include<vector>
#include<list>
#include<memory>        // for std::shared_ptr
#include<sstream>       // for std::stringstream
#include<stdexcept>     // for std::logic_error
#include<cstdint>    
#include<sstream>   

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
// quantity_ : how many units are available at that level
struct LevelInfo
{
    Price price_;
    Quantity quantity_; 
};

using LevelInfos = std :: vector<LevelInfo>;

// Yeh h ek snapshot hmari Orderbook ka
class OrderbookLevelInfos {
public :
    OrderbookLevelInfos(const LevelInfos& bids, const LevelInfos& asks)
    : bids_ { bids }
    , asks_ { asks }
    {}

    const LevelInfos& getBids() const { return bids_; }
    const LevelInfos& getAsks() const { return asks_; }

private:
    LevelInfos bids_;
    LevelInfos asks_;
};

class Order 
{
public: 
    Order(OrderType orderType, OrderId orderId, Side side, Price price, Quantity quantity)
        : 
        orderType_ { orderType }
        , orderId_ { orderId }
        , side_ { side }
        , price_ { price }
        , initialQuantity_  { quantity }
        , remainingQuantity_ { quantity }
    {}
        
    OrderId GetOrderId() const { return orderId_; }
    Side GetSide() const { side_; }
    Price GetPrice() const { return price_; }
    OrderType GetOrderType() const { return orderType_; }
    Quantity GetInitialQuantity() const { return initialQuantity_; }
    Quantity GetRemainingQuantity() const { return remainingQuantity_; }
    Quantity GetFilledQuantity() const { return GetInitialQuantity() - GetRemainingQuantity(); }

    void Fill(Quantity quantity){
        if(quantity > GetRemainingQuantity()){
            std::stringstream ss;
            ss << "Order cannot be filled for more than its remaining quantity: ";
            throw std::logic_error(ss.str());
        }
        
        remainingQuantity_ -= quantity;
    }

private:
    OrderType orderType_;
    OrderId orderId_;
    Side side_;
    Price price_;
    Quantity initialQuantity_;
    Quantity remainingQuantity_;
};

// Kyuki mere individual order alg alg DS mn pass honge to it is better to have pointer to it 
// rather than making copy everytime
using OrderPointer = std :: shared_ptr<Order>;
using OrderPointers = std :: list<OrderPointer>;

int main() {
    std :: cout << "CHECK" << std :: endl;
    return 0;
}
#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>

enum class OrderType { LIMIT, MARKET, FOK, IOC };
enum class Side { BUY, SELL };

struct Order {
    int id;
    Side side;
    OrderType type;
    double price;
    int quantity;
    long long timestamp;

    Order(int id_, Side side_, OrderType type_, double price_, int quantity_, long long ts)
        : id(id_), side(side_), type(type_), price(price_), quantity(quantity_), timestamp(ts) {}
};

#endif

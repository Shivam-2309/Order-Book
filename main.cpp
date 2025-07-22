#include<thread>
#include<mutex>
#include "OrderBook.hpp"

void addOrders(OrderBook& ob) {
    ob.addOrder(Order{1, Side::Buy, 100.0, 10, OrderType::LIMIT});
    ob.addOrder(Order{2, Side::Sell, 99.0, 5, OrderType::LIMIT});
}

void cancelOrder(OrderBook& ob) {
    ob.cancelOrder(1);
}

void printOrders(const OrderBook& ob) {
    ob.printOrderBook();
}

int main() {
    OrderBook ob;
    
    // Example to check whether this supports multithreading or not 
    std::thread t1(addOrders, std::ref(ob));
    std::thread t2(cancelOrder, std::ref(ob));
    std::thread t3(printOrders, std::cref(ob));

    t1.join();
    t2.join();
    t3.join();

    return 0;
}

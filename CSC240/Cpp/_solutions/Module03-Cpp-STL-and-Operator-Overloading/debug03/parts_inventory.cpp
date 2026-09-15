/*
 * parts_inventory.cpp
 * Tracks stock levels for a small parts bin in a std::map and keeps a
 * list of pending order numbers in a std::vector. Cancelled orders are
 * recorded as 0 and dropped before the report is printed.
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

bool in_stock(const std::map<std::string, int>& stock, const std::string& part)
{
    auto it = stock.find(part);
    return it != stock.end() && it->second > 0;
}

void report_stock(const std::map<std::string, int>& stock)
{
    std::cout << "Distinct parts tracked: " << stock.size() << std::endl;
    for (const auto& entry : stock) {
        std::cout << "  " << entry.first << " " << entry.second << std::endl;
    }
}

void drop_cancelled(std::vector<int>& orders)
{
    orders.erase(std::remove(orders.begin(), orders.end(), 0), orders.end());
}

void report_orders(const std::vector<int>& orders)
{
    std::cout << "Pending orders (" << orders.size() << "):";
    for (int id : orders) {
        std::cout << " " << id;
    }
    std::cout << std::endl;
}

int main()
{
    std::map<std::string, int> stock;
    stock["bolt"] = 120;
    stock["nut"] = 300;
    stock["washer"] = 75;

    const std::string requests[] = { "bolt", "gasket", "nut" };
    for (const std::string& part : requests) {
        std::cout << part << ": " << (in_stock(stock, part) ? "in stock" : "not stocked") << std::endl;
    }

    report_stock(stock);

    std::vector<int> orders = { 102, 0, 117, 0, 130 };
    drop_cancelled(orders);
    report_orders(orders);

    return 0;
}

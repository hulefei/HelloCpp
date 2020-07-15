//
// Created by lefeihu on 2020/7/15.
//

#include <iostream>
#include "Sales_data.h"

Sales_data::Sales_data(std::istream& is)
{
    read(is, *this);
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

double Sales_data::avg_price() const
{
    return this->revenue / units_sold;
}

std::ostream& print(std::ostream &os, const Sales_data &item)
{
    //os 使用api
    os << "book_no:" << item.isbn() << ", units_sold:" << item.units_sold
        << ", revenue:" << item.revenue << ", avg_price:" << item.avg_price() << std::endl;
    return  os;
}

std::istream& read(std::istream &is, Sales_data &item)
{
    //is 使用api
    double price = 0;
    std::cout << "book_no, units_sold, price:" << std::endl;
    is >> item.book_no >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    auto sum = lhs;
    sum.combine(rhs);
    return sum;
}

void Sales_data::to_string() {
    print(std::cout, *this);
}


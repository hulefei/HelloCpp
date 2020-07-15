//
// Created by lefeihu on 2020/7/15.
//

#ifndef HELLOCPP_SALES_DATA_H
#define HELLOCPP_SALES_DATA_H

#include <string>

class Sales_data
{
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);
    friend Sales_data add(const Sales_data&, const Sales_data&);

public:
    Sales_data() = default;
    explicit Sales_data(const std::string &s) : book_no(s){
        std::cout << "Sales_data(const std::string &s)" << std::endl;
    }
    Sales_data(const std::string &s, unsigned n, double p) : book_no(s), units_sold(n), revenue(p*n){}
    Sales_data(std::istream &is);

    std::string isbn() const { return this->book_no; }
    Sales_data& combine(const Sales_data &);
    void to_string();

private:
    double avg_price() const;
    std::string book_no;
    unsigned units_sold = 0;
    double revenue = 0;
};


#endif //HELLOCPP_SALES_DATA_H

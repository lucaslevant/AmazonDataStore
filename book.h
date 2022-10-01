#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Book : public Product {
public:
    Book(const std::string category, std::string name_, double price, int qty, std::string isbn, std::string author);
    ~Book();
    std::set<std::string> keywords() const override;
    std::string displayString() const override;
    void dump(std::ostream& os) const override;
protected:
    std::string isbn_;
    std::string author_;
};

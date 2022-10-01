#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"


class Clothing : public Product {
public:
     Clothing(const std::string category, std::string name, double price, int qty, std::string size, std::string brand);
    ~Clothing();
     std::set<std::string> keywords() const override;
     std::string displayString() const override;
     void dump(std::ostream& os) const override;
protected:
    std::string size_;
    std::string brand_;
};

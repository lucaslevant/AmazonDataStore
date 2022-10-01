#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"


class Movie : public Product {
public:
	Movie(const std::string category, std::string name, double price, int qty, std::string genre, std::string rating);
        ~Movie();
	std::set<std::string> keywords() const override;
        std::string displayString() const override; 
        void dump(std::ostream& os) const override;
protected:
	std::string genre_;
        std::string rating_;
};

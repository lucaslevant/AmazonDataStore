#include <sstream>
#include <iomanip>
#include "clothing.h"
#include "product.h"
#include "util.h"


Clothing::Clothing(const std::string category, std::string name, double price, int qty, std::string size, std::string brand):
	Product(category, name, price, qty),
	size_(size),
	brand_(brand)

{

}

Clothing::~Clothing()
{

}

std::set<std::string> Clothing::keywords() const{
	std::set<std::string> c;
 	std::string key = convToLower(name_) + " " + convToLower(brand_);
	c = parseStringToWords(key);
	return c;
}
std::string Clothing::displayString() const{
	std::string final;
	std::stringstream stream;

	stream << price_;
	std::string price;
	stream>>price;
	stream.clear();

	stream << qty_;
	std::string qty;
	stream>>qty;
	stream.clear();


	final = name_ + '\n' + "Size: " + size_ + " Brand: " + brand_  + '\n' + price + " " + qty + " left";
	return final;

}

 void Clothing::dump(std::ostream& os) const{
	os << category_ << std::endl << name_ << std::endl << price_ << std::endl << qty_ << std::endl << size_ << std::endl << brand_ << std::endl;
}

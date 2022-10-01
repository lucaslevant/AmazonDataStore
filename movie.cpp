#include <sstream>
#include <iomanip>
#include "movie.h"
#include "product.h"
#include "util.h"

Movie::Movie(const std::string category, std::string name, double price, int qty, std::string genre, std::string rating):
		Product(category, name, price, qty),
    		genre_(genre),
		rating_(rating)
{

}

Movie::~Movie()
{

} 

std::set<std::string> Movie::keywords() const{
std::set<std::string> c;
std::string key = convToLower(name_);
	c = parseStringToWords(key);
	c.insert(convToLower(genre_));
	return c;
}
std::string Movie::displayString() const{
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


	final = name_ + '\n' + "Genre: " + genre_ +  " Rating: " + rating_ + '\n' +  price + " " + qty + " left";
	return final;
}

 void Movie::dump(std::ostream& os) const{
	os << category_ << std::endl << name_ << std::endl << price_ << std::endl << qty_ << std::endl << genre_ << std::endl << rating_ << std::endl;
}

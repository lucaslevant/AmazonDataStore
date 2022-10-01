#include <sstream>
#include <iomanip>
#include "book.h"
#include "product.h"
#include "util.h"



Book::Book(const std::string category, std::string name, double price, int qty, std::string isbn, std::string author):
		Product(category, name, price, qty),
    isbn_(isbn),
		author_(author)

{

}

Book::~Book()
{

}

  std::set<std::string> Book::keywords() const{
	std::set<std::string> c;
  std::string key = convToLower(name_) + " " + convToLower(author_);
	std::cout << key << std::endl;
	c = (parseStringToWords(key));
	c.insert(isbn_);
	return c;
}


  std::string Book::displayString() const{
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


	final =  name_ + '\n' + "Author: " + author_ + " ISBN: " + isbn_ + '\n' + price + " " + qty + " left";
	return final;
	
}

 void Book::dump(std::ostream& os) const{
	os << category_ << std::endl << name_ << std::endl << price_ << std::endl << qty_ << std::endl << isbn_ << std::endl << author_ << std::endl;
}
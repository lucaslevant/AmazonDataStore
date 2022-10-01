#include <sstream>
#include <iomanip>
#include <vector>
#include <set>
#include "book.h"
#include "util.h"
#include "datastore.h"
#include "mydatastore.h"



MyDataStore::MyDataStore()
{

}

MyDataStore::~MyDataStore()
{

}

void MyDataStore::addProduct(Product* thing){ //how do i get product name as string
	prod.push_back(thing);
  	std::set<std::string> words = thing->keywords();
	std::set<std::string>::iterator itr;
	for(itr = words.begin(); itr !=  words.end(); itr++){
		if(prodCart.find(*itr) == prodCart.end()){ 
			std::set<Product*> temp;
			temp.insert(thing);
			prodCart[*itr] = temp;
		}
		else if(prodCart.find(*itr) != prodCart.end()){
			prodCart.find(*itr)->second.insert(thing);
		}
	}

	}

void MyDataStore::addUser(User* person){ 
	std::vector<Product*> temp;
	users[person->getName()] = person; 
	usersCart[person->getName()] = temp;
	
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& words, int check){
	std::set<Product*> holder;
	int count = 0;
	int size = words.size();
for(int i = 0; i < size; i++){
		if(prodCart.find(words[i]) != prodCart.end()){ 
			if(count == 0){
			   holder = prodCart[words[i]];
			}
			if(check == 0){
			  holder = setIntersection(holder, prodCart[words[i]]);
			  count++;
			}
			else if (check == 1){
		           holder = setUnion(holder, prodCart[words[i]]);
			   count++;
			}		
		}
	}

	std::vector<Product*> final(holder.begin(), holder.end());
	return final;
}



 void MyDataStore::dump(std::ostream& ofile){

 ofile << "<product>" << std::endl;
	int size = prod.size();
	for(int i = 0; i < size; i++){
		prod[i]->dump(ofile);
	}
	ofile << "</product>" << std::endl;
	ofile << "<users>" << std::endl;
  	std::map<std::string, User*>::iterator it;
	for(it = users.begin(); it != users.end(); it++){
		it->second->dump(ofile);
	}
	ofile << "</users>" << std::endl;
 }

void MyDataStore::addCart(std::string username, Product* product){ //if username exists, add a cart
	if(users.find(username) == users.end()){
		std::cout << "Invalid request" << std::endl;
		return;
	}
	usersCart.find(username)->second.push_back(product);
}
void MyDataStore::viewCart(std::string username){
	if(users.find(username) == users.end()){
		std::cout << "Invalid username" << std::endl;
		return;
	}		  
  	std::map<std::string, std::vector<Product*>>::iterator itr = usersCart.find(username);
	int size = itr->second.size();
	for(int i = 0; i < size; i++){
		std::cout << itr->second[i]->displayString() << std::endl;
	}
}

void MyDataStore::buyCart(std::string username){
		if(users.find(username) == users.end()){
			std::cout << "Invalid username" << std::endl;
			return;
		}
	 	std::vector<Product*> holder;
		double balance = users.find(username)->second->getBalance();
	  	std::map<std::string, std::vector<Product*>>::iterator itr = usersCart.find(username);
		int size = itr->second.size();
		for(int i = size-1; i >= 0; i--){
			double price = itr->second[i]->getPrice();
			if(itr->second[i]->getQty() > 0 && balance >= price){ //if user can afford and it is in qty
				std::cout << "Thank you for purchasing " << itr->second[i]->getName() << std::endl;
				itr->second[i]->subtractQty(1);
				users.find(username)->second->deductAmount(price);
			}
			else{
				holder.push_back(itr->second[i]);
				if(balance < price){
					std::cout << "Insufficient funds for " << itr->second[i]->getName() << std::endl;
				}
				if(itr->second[i]->getQty() <= 0){
					std::cout << itr->second[i]->getName() << " is out of stock" << std::endl;
				}
			}
		}
		usersCart[username] = holder;
	}   


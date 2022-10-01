#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"
#include "datastore.h"
#include <map>


/**
 * DataStore Interface needed for parsing and instantiating products and users
 *
 * A derived version of the DataStore can provide other services as well but
 * must support those below
 *
 * DO NOT EDIT
 */


class MyDataStore : public DataStore {
public:
		 MyDataStore();
		 
    ~MyDataStore();

    /**
     * Adds a product to the data store
     */
    void addProduct(Product* p);

    /**
     * Adds a user to the data store
     */
    void addUser(User* u);

		

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    std::vector<Product*> search(std::vector<std::string>& terms, int type);
		void addCart(std::string username, Product* product);
		void buyCart(std::string username);
		void viewCart(std::string username);

    /**
     * Reproduce the database file from the current Products and User values
     */
    void dump(std::ostream& ofile);




private: //or protected?
		
		std::map<std::string, std::set<Product*>> prodCart; //map of keywords to corresponding set of products
    std::map<std::string, std::vector<Product*>> usersCart; //map of usernames to corresponding set of products
		std::vector<Product*> prod; 
		std::map<std::string,User*> users; //map of usernames to users



};


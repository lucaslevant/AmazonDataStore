# AmazonDataStore
This program emulates an online Amazon store.
-----------------------------------------------------------------------------------------------------------------------------------------
Products and Users are stored into a database.
Every product can be searched and retrieved from the database.
User can use commands to search database for products based on keywords, as well as to add products to a user cart.
User can also use commands to view products in cart and buy cart if items are in stock and user has sufficient funds.
-----------------------------------------------------------------------------------------------------------------------------------------
###  USAGE
Enter "AND" plus keywords: Returns all prodcuts that contain all searched keywords.
Enter "OR" <keywords>: Returns all prodcuts that contain at least one of searched keywords.
Enter "ADD" <username> <hit_number>: Adds product to user cart.
Enter "VIEWCART" <keywords>: Returns all prodcuts in user's cart.
Enter "BUYCART" <keywords>: Purchases products in user's cart in order that they were added.
-----------------------------------------------------------------------------------------------------------------------------------------
HOW TO COMPILE:
use command "make"
-----------------------------------------------------------------------------------------------------------------------------------------
HOW TO RUN:
use command "./amazon database.txt"
This will display a menu that prompts user for commands and inputs 
-----------------------------------------------------------------------------------------------------------------------------------------
IMPORTANT: database.txt can be edited to alter products and users, or database.txt can be replaced with other databse file.

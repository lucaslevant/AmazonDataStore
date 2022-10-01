# AmazonDataStore
This program emulates an online Amazon store.
 - Name: Lucas LeVant
 - Email: levant@usc.edu 

Products and Users are stored into a database
every product can be searched and retrieved from the database.
User can use commands to search database for products based on keywords.
User can use commands to add products to a user cart.
User can use commands to view products in cart.
User can use commands to buy cart if items are in stock and user has sufficient funds.

###  USAGE
Enter "AND" plus keywords: Returns all prodcuts that contain all searched keywords.
Enter "OR" plus keywords: Returns all prodcuts that contain at least one of searched keywords.
Enter "ADD" plus username plus hit_number: Adds product to user cart.
Enter "VIEWCART" plus keywords: Returns all prodcuts in user's cart.
Enter "BUYCART" plus keywords: Purchases products in user's cart in order that they were added.

 HOW TO COMPILE:
 use command "make"
 
 HOW TO RUN:
 use command "./amazon database.txt"
 
 IMPORTANT: database.txt can be edited to alter products and users, or database.txt can be replaced with other databse file.

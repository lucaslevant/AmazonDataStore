#ifndef UTIL_H
#define UTIL_H
#include <string>
#include <iostream>
#include <set>

template <typename T>
typename std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
typename std::set<T>::iterator itr;
typename std::set<T> c;
for (itr = s1.begin(); itr != s1.end(); itr++){
	if(s2.find(*itr) != s2.end()){
	    c.insert(*itr);
	}
}
return c;
}

template <typename T>
typename std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
typename std::set<T>::iterator itr;
  for (itr = s1.begin(); itr != s1.end(); itr++){
	if(s2.find(*itr) == s2.end()){
	    s2.insert(*itr);
	}
   }
	return s2;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif

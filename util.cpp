#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <set>
#include "util.h"


std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}
/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(std::string rawWords){
	std::set<std::string> final;
	std::string curr = "";
	int counter = 0;
	char holder = rawWords[0];
	int tsize = rawWords.size();
	int scounter = 0; //hown many words in rawwords
	int sizef = rawWords.size();
	for(int i = 1; i < tsize; i++){
			if(holder == ' '){
					scounter++;
			}
			holder = rawWords[i];
	}
	scounter++;
	for(int x = 0; x < scounter; x++){
			char holder = rawWords[counter];
	while(holder != ' ' && counter != sizef){ //put word into currr, maybe don't need null check
					curr = curr + holder;
					counter++;
					holder = rawWords[counter];
			}
	int size = curr.size();
	std::string word = "";
	char nholder;
			for(int i=0; i < size; i++){ //loop through curr
					word = word + curr[i];
					nholder = curr[i];
					if( ispunct(nholder)){
							word.pop_back();
							int sizel = word.size();
							if(sizel >= 2){
								// 	cout << "adding " << word << endl;
									final.insert(word);
							}
							word = "";
							}
					}
				// 	cout << "left " << word << endl;
					int sizef = word.size();
					if(sizef >= 2){
				// 	cout << "adding " << word << endl;
					final.insert(word);
					}
					word ="";
					curr ="";
					counter++;
	}

	return final;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

#include <iostream>
#include <string>
#include <bitset>
#include <vector>

bool isUnique(const std::string str){
    //Asuming 256 chars
    std::bitset<256> test(0);
    auto it = str.cbegin();
    while(it!=str.cend()){
        int val = *it;
        if(test.test(val))
            return false;
        else
            test.set(val);
        it++;
    }
    return true;
}
//We can reduce the time complexity by simply sorting the string and checking of i+1 == i 
int main(){
    std::vector<std::string> words = {"abcde", "hello", "apple", "kite", "padle"};
	for (auto word : words){
		std::cout << word << std::string(": ") <<std::boolalpha << isUnique(word) <<std::endl;
	}
}
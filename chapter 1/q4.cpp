#include <string>
#include <iostream>


bool isPali(std::string str){
    auto it = str.cbegin();
    auto itr = str.crbegin();
    while(it != str.end()){
        if(std::tolower(*it) != std::tolower(*itr))
            return false;
        it++;
        itr++;
    }
    return true;
}

int main(){
    std::string pali = "Rats live on no evil star";
    std::string isPermutation = isPali(pali) ? "yes" : "no";
    std::cout << isPermutation << std::endl;
}
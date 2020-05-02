#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;




bool arePermutation(string str1, string str2){
    if (str1.size() != str2.size()){
        return false;
    }
    else{
        sort(str1.begin(),str1.end());
        sort(str2.begin(),str2.end());
        for(int i = 0; i<str1.size();i++){
            if(str1.at(i) != str2.at(i))
                return false;
        }
        return true;
    }
}


int main(){

    cout << "Method 1 - Using sort" << endl;
    string str1 = "testest";
    string str2 = "estxest";
    if(arePermutation(str1, str2))
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;
    str1 = "hello";
    str2 = "oellh";
    if(arePermutation(str1, str2))
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;
}
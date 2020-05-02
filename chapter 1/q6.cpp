#include <string>
#include <iostream>

std::string compress(std::string str){
    if (str.length() < 2) {
		return str;
	}
    std::string out{""};
    int count = 1;
    for(int i =0; i<str.length();i++){
        if(str[i-1] == str[i]){
            count++;
        }
        else{
            out+=str[i-1];
            out += std::to_string(count);
			count = 1;
        }
    }
    out += str[str.length()-1];
	out += std::to_string(count);
    return out;
}

int main(){
    std::string str, out;
	std::cout << "Enter a string:\n";
	std::cin >> str;
	out = compress(str);
	if (str.compare(out)) {
		std::cout << str << " can be compressed to " << out << std::endl;
	} else {
		std::cout << str << " can not be compressed\n";
	}

    
	return 0;
}
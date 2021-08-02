#include <vector>
#include <iostream>
#include <string>

using std::vector;

int main(/*int argc, char *argv[]*/){
    std::string args = "";
    std::cout << "Initiating check\nEnter Password: ";
    std::cin >> args;
    // int arg_size = sizeof(argv[1])/sizeof(char);

    float length_mult = args.size() * 0.125;
    int chars_used = 0; // tracks all UNIQUE characters used except unique symbols, uses hashing below to track
    int symbols_used = 0; // tracks all symbols used, regardless if they are unique or not
    vector<bool> numbers(10, false); // this vector and the two below will be used like hash maps to evaluate the presence of certain symbols
    vector<bool> upper_alph(26, false);
    vector<bool> lower_alph(26, false);
    vector<bool> attr(4, false); // each attribute checks if a certain symbol is used: [0]: lower-case, [1]: upper-case, [2]: numbers, [3]: special symbols
    for(int i = 0; i < args.size(); i++){
        // std::cout << i << "\n";
        int val = args[i];
        // std::cout << val << "\n";
        if(val >= 48 && val < 58){
            if(!(numbers[val - 48])){
                numbers[val - 48] = true;
                chars_used++;
                attr[2] = true;
            }
        }else if(val >= 65 && val < 91){
            if(!(upper_alph[val - 65])){
                upper_alph[val - 65] = true;
                chars_used++;
                attr[1] = true;
            }
        }else if(val >= 97 && val < 123){
            if(!(lower_alph[val - 97])){
                lower_alph[val - 97] = true;
                chars_used++;
                attr[0] = true;
            }
        }else{
            symbols_used++;
            attr[3] = true;
        }
    }
    float attr_mult = 0;
    for(int i = 0; i < attr.size(); i++){
        if(attr[i]) attr_mult += 0.25;
    }
    float symbol_mult = 1 + (symbols_used * 0.2);
    float char_mult = 1 + (chars_used * 0.25 - 1);
    float password_score = 10 * symbol_mult * char_mult * length_mult * attr_mult;
    std::cout << password_score << "\n";
    return 0;
}
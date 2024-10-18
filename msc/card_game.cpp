#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

struct card {
    char n;
    char m;
};

card magic_trick(vector<card> deck){
    vector<card> upper(deck.begin(), deck.begin() + 25);
    vector<card> down(deck.begin() + 25, deck().end());
    
    
}

int value(card c){
    char n = c.n;
    if ((n - '0') < 9 && (n - 0) > 1){
        return int(n-'0');
    }
    else
        return 10;
}



int main(){
    string inputed_card;
    vector<card> deck;
    for (int i = 0; i < 52; i++){
        std::cin >> inputed_card;
        deck.push_back({inputed_card[0], inputed_card[1]});
    }
    std::cout << value(deck[8]) << std::endl;
    return 0;
}


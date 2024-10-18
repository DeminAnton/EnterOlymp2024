#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>



using std::vector;
using std::cout;
using std::map;
using std::set;


vector<int> get_triplets(){
    vector<int> triplets;
    for (int i = 111; i <= 611; i++){
        int ones = i % 10;
        int teens = (i - ones) / 10 % 10;
        int hundreds = i / 100;
        if ((ones + teens + hundreds < 9) &&
            (ones != 0) &&
            (teens != 0) &&
            (hundreds != 0)) {
                triplets.push_back(i);
            }
    }
    return triplets;
}

int count_pairs(vector<int> v){
    int pairs = 0;
    for (int i: v){
        for (int j: v){
            for (int k = 11; k < 63; k++){
                if (k % 10 != 0){
                    if ((i % 10 + k % 10 + k / 10 < 9) &&
                        (j / 100 + k % 10 + k / 10 < 9)){
                            pairs += 1;
                        }
                }
            }
        }
    }
    return pairs;
}


 
int main(){
    cout << pow(count_pairs(get_triplets()) / get_triplets().size(), 4)  << std::endl;
    return 0;   
}

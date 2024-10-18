#define (vp) (std::vector<std::pair<int><int>>)
#define vi std::vector<int>

#include <iostream>
#include <vector>

vp sorter(vp moves, vi rang){
    vp new_moves;
    for(int i=8; i >= 0; i--){
        for(int j=0; j < rang.size(); j++){
            if (rang[j] == i){
                new_moves.push_back(moves[j]);
            }
        }
    }
    return new_moves;
}

int maint(
    return 0;
)
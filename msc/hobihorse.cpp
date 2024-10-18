#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <numeric>
#include <string>
#include <cmath>
#include <fstream>

#define INF 10e100;

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::min;

bool isvalid(vector<vector<int>> desk, int line, int col){
    return (0<=line) && (line <= 7) && (0<=col) && (col <= 7) && (desk[line][col] == 0);
}

std::vector<std::pair<int,int>> sorter(std::vector<std::pair<int,int>> moves, std::vector<int> rang){
    std::vector<std::pair<int,int>> new_moves;
    for(int i=8; i>0; i--){
        for(int j=0; j<rang.size();j++){
            if(rang[j]==i){
                new_moves.push_back(moves[j]);
            }
        }
    }
    return new_moves;
}

int lehgtt(vector<vector<int>> desk, int line, int col){
    vector<std::pair<int,int>> knight_moves = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
    vector<std::pair<int,int>> possible_moves;
    for(std::pair<int,int> move : knight_moves){
        int new_x;
        int new_y;
        new_x = line + move.first;
        new_y = col + move.second;
        if(isvalid(desk, new_x, new_y)){
            possible_moves.push_back({new_x,new_y});
        }
    }
    return possible_moves.size();
}

vector<std::pair<int,int>> knightmoves(vector<vector<int>> desk, int line, int col){
    vector<std::pair<int,int>> knight_moves = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
    vector<std::pair<int,int>> possible_moves;
    vector<std::pair<int,int>> overall_possible_moves;
    for(std::pair<int,int> move : knight_moves){
        int new_x;
        int new_y;
        new_x = line + move.first;
        new_y = col + move.second;
        if(isvalid(desk, new_x, new_y)){
            possible_moves.push_back({new_x,new_y});
        }
    }
    std::vector<std::pair<int,int>> vp;
    vector<int> vi;
    for(std::pair<int,int> i : possible_moves){
        vi.push_back(lehgtt(desk,i.first,i.second));
        vp.push_back(i);
    }
    overall_possible_moves=sorter(vp,vi);
    return overall_possible_moves;
}

void printboard(vector<vector<int>> v){
    for(vector<int> i : v){
        for(int j : i){
            cout<<j<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool way(int x, int y, vector<vector<int>> &board, int count){
    if(count == 60){
        int q = 0;
        printboard(board);
    }
    if(count >= 64){
        return true;
    }
    vector<std::pair<int,int>> paths = knightmoves(board, x, y);
    for(std::pair<int,int> i : paths){
        int new_x = i.first;
        int new_y = i.second;
        board[new_x][new_y]=count;
        if(way(new_x,new_y, board,count+1)){
            return true;
        }
        board[new_x][new_y]=0;
    }
    return false;
}

int main(){
    vector<vector<int>> v = {
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0}
    };
    int line = 4; int col = 6;
    int count = 1;
    // for(std::pair<int,int> i : knightmoves(v,line,col)){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    v[4][6] = 1;
    way(line,col,v,count);
     for(vector<int> i : v){
         for(int j : i){
            cout<<j<<" ";
         }
         cout<<endl;
     }
}
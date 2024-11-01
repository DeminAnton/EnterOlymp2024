#include <list>
#include <iostream>

using std::list;
using std::cin;
using std::cout;

int getCutedSticks(list<int>& sticks, int tail = 3){
    int allSticks = *sticks.begin();
    if (tail == 3){
        auto iter = sticks.end();
        allSticks += *(--iter);
        allSticks += 2 * *(--iter);
        allSticks += *(--iter);
        sticks.pop_front();
        return allSticks;
    }

    auto iter = sticks.end();
    allSticks += 2 * *(--iter);
    allSticks += *(--iter);
    sticks.pop_front();
    return allSticks;
}

int main(){
    int l;
    cin >> l;
    list<int> sticks;
    int max_n, max_l;
    max_n = 0;
    max_l = l;
    int stick;
    cin >> stick;
    sticks.push_back(stick);
    for (int i = 2; i <= l; i+=1){
        cin >> stick;
        sticks.push_back(stick);
        if (i % 2 == 0)
            continue;
        int q = getCutedSticks(sticks, sticks.size() == 3 ? 2: 3);
        if (q > max_n){
            max_n = q;
            max_l = (i - 1)/2;
        }
    }
    if (l % 2 == 0){
        int q = getCutedSticks(sticks, 2);
        if (q > max_n){
            max_n = q;
            max_l = l/2;
        }
    }
    cout << "max_n = " << max_n << "\nmax_l = " 
         << max_l << std::endl;
    return 0;
}
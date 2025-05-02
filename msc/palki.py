

def getCutedSticks(sticks: list, tail = 3):
    allSticks = sticks[0]
    if (tail == 3):
        allSticks += sum(sticks[-3:]) + sticks[-2]
        sticks = sticks[1:]
        return allSticks
    

    allSticks += sum(sticks[-2:]) + sticks[-2]
    sticks = sticks[1:]
    return allSticks


def main():
    l = int(input())
    sticks = []
    max_n = 0
    max_l = l
    stick = int(input())
    sticks.append(stick)
    for i in range(2, l + 1):
        stick = int(input())
        sticks.append(stick)
        if (i % 2 == 0):
            continue
        q = getCutedSticks(sticks, 2 if len(sticks) == 3 else 2);
        if (q > max_n):
            max_n = q
            max_l = (i - 1) // 2
        
    
    if (l % 2 == 0):
        q = getCutedSticks(sticks, 2)
        if (q > max_n):
            max_n = q
            max_l = l // 2
    

    print("max_l =", max_l)
    print("max_n =", max_n)

main()
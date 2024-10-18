N = 8 #board size

def is_valid_move(x, y, board):
    return 0 <= x < N and 0 <= y < N and board[x][y] == -1

def knight_move(x, y, board):
    knight_moves = [
    (2, 1), (1, 2), (-1, 2), (-2, 1), 
    (-2, -1), (-1, -2), (1, -2), (2, -1)
]
    possible_moves = []
    for move in knight_moves:
        new_x, new_y = x + move[0], y + move[1]
        if is_valid_move(new_x, new_y, board):
            count = sum(1 for m in knight_moves if is_valid_move(new_x + m[0], new_y + m[1], board))
            possible_moves.append((new_x, new_y, count))
    possible_moves.sort(key=lambda move: move[2])
    return possible_moves

def knight_tour(x, y, board, move_count):
    if move_count == N * N:
        return True
    
    for move in knight_move(x, y, board):
        new_x, new_y = move[0], move[1]
        
        board[new_x][new_y] = move_count
        
        if knight_tour(new_x, new_y, board, move_count + 1):
            return True

        board[new_x][new_y] = -1

    
    return False

def find_knights_tour(start_x, start_y):

    board = [[-1 for _ in range(N)] for _ in range(N)]

    board[start_x][start_y] = 0
    
    if knight_tour(start_x, start_y, board, 1):
        return board 
    else:
        return None


start_position = (3, 3)
knight_path = find_knights_tour(start_position[0], start_position[1])


if knight_path:
    for row in knight_path:
        print(row)
else:
    print("No solution found.")
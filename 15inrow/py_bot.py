import random

BOARD_SIZE = 15
WIN_LENGTH = 5

EMPTY = '.'
PLAYER_HUMAN = 'X'
PLAYER_BOT = 'O'


def create_board(size):
    return [[EMPTY for _ in range(size)] for _ in range(size)]


def print_board(board):
    size = len(board)
    header = '   ' + ' '.join(f'{i:2}' for i in range(size))
    print(header)
    for i, row in enumerate(board):
        row_str = ' '.join(f'{cell:2}' for cell in row)
        print(f'{i:2} {row_str}')


def is_valid_move(board, x, y):
    return 0 <= x < len(board) and 0 <= y < len(board) and board[y][x] == EMPTY


def check_win(board, x, y, player):
    directions = [(1, 0), (0, 1), (1, 1), (1, -1)]
    for dx, dy in directions:
        count = 1
        for dir in [1, -1]:
            nx, ny = x, y
            while True:
                nx += dx * dir
                ny += dy * dir
                if 0 <= nx < len(board) and 0 <= ny < len(board):
                    if board[ny][nx] == player:
                        count += 1
                    else:
                        break
                else:
                    break
        if count >= WIN_LENGTH:
            return True
    return False


def bot(board, player):
    empty_cells = [(x, y) for y in range(len(board)) for x in range(len(board)) if board[y][x] == EMPTY]
    return random.choice(empty_cells) if empty_cells else None


def human_move(board):
    while True:
        try:
            coords = input("Введите ход (x y): ").strip().split()
            if len(coords) != 2:
                raise ValueError
            x, y = map(int, coords)
            if is_valid_move(board, x, y):
                return x, y
            else:
                print("Неверный ход! Клетка занята или вне границ.")
        except ValueError:
            print("Введите координаты в формате: x y")


def play_game():
    board = create_board(BOARD_SIZE)
    current_player = PLAYER_HUMAN

    while True:
        print_board(board)
        if current_player == PLAYER_HUMAN:
            print("Ход игрока (X)")
            x, y = human_move(board)
        else:
            print("Ход бота (O)")
            x, y = bot(board, PLAYER_BOT)
            print(f"Бот ходит: {x} {y}")

        board[y][x] = current_player

        if check_win(board, x, y, current_player):
            print_board(board)
            print(f"Победа {'человека' if current_player == PLAYER_HUMAN else 'бота'}!")
            break

        if all(cell != EMPTY for row in board for cell in row):
            print_board(board)
            print("Ничья!")
            break

        current_player = PLAYER_BOT if current_player == PLAYER_HUMAN else PLAYER_HUMAN


if __name__ == "__main__":
    play_game()

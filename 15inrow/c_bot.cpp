#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int BOARD_SIZE = 15;
const int WIN_LENGTH = 5;
const char EMPTY = '.';
const char PLAYER_HUMAN = 'X';
const char PLAYER_BOT = 'O';

using Board = vector<vector<char>>;

Board create_board(int size) {
    return Board(size, vector<char>(size, EMPTY));
}

void print_board(const Board& board) {
    int size = board.size();
    cout << "   ";
    for (int i = 0; i < size; ++i)
        cout << setw(2) << i << " ";
    cout << "\n";

    for (int y = 0; y < size; ++y) {
        cout << setw(2) << y << " ";
        for (int x = 0; x < size; ++x)
            cout << setw(2) << board[y][x] << " ";
        cout << "\n";
    }
}

bool is_valid_move(const Board& board, int x, int y) {
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[y][x] == EMPTY;
}

bool check_win(const Board& board, int x, int y, char player) {
    const int dirs[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };

    for (auto& [dx, dy] : dirs) {
        int count = 1;

        for (int dir = -1; dir <= 1; dir += 2) {
            int nx = x, ny = y;
            while (true) {
                nx += dx * dir;
                ny += dy * dir;
                if (nx < 0 || ny < 0 || nx >= BOARD_SIZE || ny >= BOARD_SIZE) break;
                if (board[ny][nx] != player) break;
                ++count;
            }
        }

        if (count >= WIN_LENGTH)
            return true;
    }

    return false;
}

pair<int, int> bot(const Board& board, char player) {
    vector<pair<int, int>> empty;
    for (int y = 0; y < BOARD_SIZE; ++y)
        for (int x = 0; x < BOARD_SIZE; ++x)
            if (board[y][x] == EMPTY)
                empty.emplace_back(x, y);

    if (empty.empty()) return {-1, -1};

    return empty[rand() % empty.size()];
}

pair<int, int> human_move(const Board& board) {
    while (true) {
        int x, y;
        cout << "Введите координаты (x y): ";
        cin >> x >> y;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Ошибка ввода\n";
            continue;
        }
        if (is_valid_move(board, x, y))
            return {x, y};
        else
            cout << "Неверный ход. Попробуйте снова.\n";
    }
}

bool is_draw(const Board& board) {
    for (auto& row : board)
        for (char cell : row)
            if (cell == EMPTY)
                return false;
    return true;
}

void play_game() {
    Board board = create_board(BOARD_SIZE);
    char current_player = PLAYER_HUMAN;
    srand(time(nullptr));

    while (true) {
        print_board(board);
        int x, y;

        if (current_player == PLAYER_HUMAN) {
            cout << "Ход игрока (X)\n";
            tie(x, y) = human_move(board);
        } else {
            cout << "Ход бота (O)\n";
            tie(x, y) = bot(board, PLAYER_BOT);
            cout << "Бот выбрал: " << x << " " << y << "\n";
        }

        board[y][x] = current_player;

        if (check_win(board, x, y, current_player)) {
            print_board(board);
            cout << (current_player == PLAYER_HUMAN ? "Игрок" : "Бот") << " победил!\n";
            break;
        }

        if (is_draw(board)) {
            print_board(board);
            cout << "Ничья!\n";
            break;
        }

        current_player = (current_player == PLAYER_HUMAN) ? PLAYER_BOT : PLAYER_HUMAN;
    }
}

int main() {
    play_game();
    return 0;
}

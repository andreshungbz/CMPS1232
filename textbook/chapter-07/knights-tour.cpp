#include <array>
#include <iomanip>
#include <iostream>
#include <random>

namespace Chess {
    struct Position {
        int row{};
        int col{};
    };

   namespace Knight {
       constexpr std::array<int, 8> horizontal{2, 1, -1, -2, -2, -1, 1, 2};
       constexpr std::array<int, 8> vertical{-1, -2, -2, -1, 1, 2, 2, 1};
       constexpr std::array<std::array<int, 8>, 8> accessibility{{
           {2, 3, 4, 4, 4, 4, 3, 2},
           {3, 4, 6, 6, 6, 6, 4, 3},
           {4, 6, 8, 8, 8, 8, 6, 4},
           {4, 6, 8, 8, 8, 8, 6, 4},
           {4, 6, 8, 8, 8, 8, 6, 4},
           {4, 6, 8, 8, 8, 8, 6, 4},
           {3, 4, 6, 6, 6, 6, 4, 3},
           {2, 3, 4, 4, 4, 4, 3, 2}
       }};
   }
}

int randomMove() {
    static std::random_device rd{};
    static std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(),};
    static std::mt19937 mt{ss};
    static std::uniform_int_distribution<> move{0, 7};

    return move(mt);
}

bool validMove(std::array<std::array<bool, 8>, 8>& board, int row, int col, int moveNumber) {
    int newRow = row + Chess::Knight::vertical[moveNumber];
    int newCol = col + Chess::Knight::horizontal[moveNumber];

    bool inBounds = newRow >= 0 && newRow <= 7 && newCol >= 0 && newCol <= 7;
    bool traversed = board[newRow][newCol];

    return inBounds && !traversed;
}

bool moveKnight(std::array<std::array<bool, 8>, 8>& board, Chess::Position& current, int moveNumber) {
    if (validMove(board, current.row, current.col, moveNumber)) {
        current.row += Chess::Knight::vertical[moveNumber];
        current.col += Chess::Knight::horizontal[moveNumber];

        board[current.row][current.col] = true;

        return true;
    }

    return false;
}

void printBoard(std::array<std::array<bool, 8>, 8>& board) {
    std::cout << "Chess Board State\n";
    for (auto row : board) {
        bool first{true};
        for (auto col : row) {
            if (first) {
                first = false;
            } else {
                std::cout << std::setw(3) << std::right;
            }
            std::cout << col;
        }
        std::cout << '\n';
    }
}

int main() {
    std::array<std::array<bool, 8>, 8> board{};
    Chess::Position current{};

    board[current.row][current.col] = true;
    bool game{true};
    int moves{1};

    while (game) {
        for (std::size_t i{0}; i < 8; ++i) {
            bool move = moveKnight(board, current, static_cast<int>(i));

            if (move) {
                ++moves;
                break;
            } else if (i == 7) {
                game = false;
            }
        }
    }

    printBoard(board);
    std::cout << "Moves Taken: " << moves << '\n';

    return 0;
}

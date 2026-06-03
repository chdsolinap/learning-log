#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <iomanip>  // for setw()
#include <cstring>  // for memcpy

using namespace std;

// Constants
const int BOARD_SIZE = 3;
const int WINNING_SCORE = 3;

// Game modes
enum GameMode {
    COMPUTER_VS_PLAYER = 1,
    PLAYER_VS_PLAYER = 2
};

char board[BOARD_SIZE][BOARD_SIZE];

// Function prototypes
void initialize_board();
void show_board();
void player_move(char symbol, const string& player_name);
void computer_move();
int count_board(char symbol);
char check_winner();
void computer_vs_player();
void player_vs_player();
int get_position(int pos);
void clear_screen();
void display_rules();
void wait_for_user_input();
bool play_again();
void reset_board();
void end_display_students_name();
void display_welcome_message();

int main() {
    bool playAgain = true;

    while (playAgain) {
        initialize_board();
        display_welcome_message();
        wait_for_user_input();

        display_rules();

        int mode;
        cout << "PRESS [1] for Computer Vs. Player" << endl;
        cout << "PRESS [2] for Player Vs. Player" << endl;
        cout << "Please Select Game Mode: ";

        while (!(cin >> mode) || (mode != COMPUTER_VS_PLAYER && mode != PLAYER_VS_PLAYER)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter 1 or 2: ";
        }
        cin.ignore(); // clear the input buffer

        switch (mode) {
        case COMPUTER_VS_PLAYER:
            computer_vs_player();
            break;
        case PLAYER_VS_PLAYER:
            player_vs_player();
            break;
        }

        playAgain = play_again();
    }

    end_display_students_name();
    return 0;
}

void initialize_board() {
    char init[BOARD_SIZE][BOARD_SIZE] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    memcpy(board, init, sizeof(board));
}

void display_welcome_message() {
    clear_screen();
    cout << "========== WELCOME TO TIC TAC TOE GAME! ==========\n" << endl;
    cout << " #########  ##  #########  ##    ######    \n";
    cout << " #########  ##  #########  ##   #########  \n";
    cout << "    ###     ##     ###     ##   ###        \n";
    cout << "    ###     ##     ###     ##   ###        \n";
    cout << "    ###     ##  #########  ##   #########  \n";
    cout << "    ###     ##  #########  ##    ######    \n";
    cout << "            ##             ##              \n";
    cout << "###########################################\n";
    cout << "            ##             ##              \n";
    cout << " #########  ##     ###     ##    ######    \n";
    cout << " #########  ##    #####    ##   #########  \n";
    cout << "    ###     ##   ### ###   ##   ###        \n";
    cout << "    ###     ##  ##     ##  ##   ###        \n";
    cout << "    ###     ##  #########  ##   #########  \n";
    cout << "    ###     ##  ###   ###  ##    ######    \n";
    cout << "            ##             ##              \n";
    cout << "###########################################\n";
    cout << "            ##             ##              \n";
    cout << " #########  ##     ###     ##  #########   \n";
    cout << " #########  ##  ###   ###  ##  #########   \n";
    cout << "    ###     ## ####   #### ##  ###         \n";
    cout << "    ###     ## ####   #### ##  #######     \n";
    cout << "    ###     ##  ###   ###  ##  ###         \n";
    cout << "    ###     ##     ###     ##  #########   \n";

    cout << "\nPress Enter to see the GAME RULES...\n";
}

void display_rules() {
    clear_screen();

    cout << "===================================== TIC TAC TOE RULES ==============================================\n";
    cout << "1. The game is played on a 3x3 grid.\n";
    cout << "2. Player 1 is 'X' and Player 2 is 'O'.\n";
    cout << "3. Players take turns to place their mark on the grid.\n";
    cout << "4. The first player to get 3 of their marks in a row (horizontally, vertically, or diagonally) wins.\n";
    cout << "5. If the grid is full and no player has 3 in a row, the game is a draw.\n";
    cout << "6. First player to score 3 Points, WINS!.\n\n";

    cout << "\nPress Enter to start the game...\n";
    wait_for_user_input();
}

void end_display_students_name() {
    clear_screen();

    cout << "   #######      ###    ###       ### #########      #####   ###   ### ######### ########   \n";
    cout << "  #########   #######  #####   ##### #########    ###   ### ###   ### ######### ###   ###  \n";
    cout << "  ###        ###   ### ### ##### ### ##           ##     ## ###   ### ##        ###   ###  \n";
    cout << "  ###  ##### ######### ###  ###  ### #########    ##     ## ###   ### ######### ### ####   \n";
    cout << "  ###   ###  ###   ### ###   #   ### ##           ###   ###   #####   ##        ###   ###  \n";
    cout << "    ######   ###   ### ###       ### #########      #####      ###    ######### ###   #### \n";
    cout << "\n================================= GAME CREATORS =========================================\n";
    cout << "                                 BOLOR, Angela C.\n";
    cout << "                             GONZALES, Trisha Ysabelle Q.\n";
    cout << "                             ESTRELLA, Dioslhyn Nicole S.\n";
    cout << "                               JACOBE, Jan Leander G.\n";
    cout << "                              PLACENTE, Nina Christel C.\n";
    cout << "                            SOLINAP, Charles Hendricks D.\n";

    cout << endl;
    cout << setw(22) << "All rights reserved.\n";

    // Date and Time
    time_t curr_time;
    curr_time = time(NULL);
    char* tm = ctime(&curr_time);
    cout << "\nCurrent Date and Time: " << tm << endl;
}

void wait_for_user_input() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

char check_winner() {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    // Check for draw
    if (count_board('X') + count_board('O') == BOARD_SIZE * BOARD_SIZE) {
        return 'D';
    }

    return 'C'; // Continue
}

void show_board() {
    clear_screen();
    cout << "\n";
    cout << "   " << "    |   " << "    |   " << endl;
    cout << "   " << board[0][0] << "   |   " << board[0][1] << "   |   " << board[0][2] << endl;
    cout << "   " << "    |   " << "    |   " << endl;
    cout << "----------------------" << endl;
    cout << "   " << "    |   " << "    |   " << endl;
    cout << "   " << board[1][0] << "   |   " << board[1][1] << "   |   " << board[1][2] << endl;
    cout << "   " << "    |   " << "    |   " << endl;
    cout << "----------------------" << endl;
    cout << "   " << "    |   " << "    |   " << endl;
    cout << "   " << board[2][0] << "   |   " << board[2][1] << "   |   " << board[2][2] << endl;
    cout << "   " << "    |   " << "    |   " << endl;
    cout << "\n";
}

void player_move(char symbol, const string& player_name) {
    int pos;
    while (true) {
        cout << player_name << ", select position for " << symbol << " (1-9): ";
        if (!(cin >> pos)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number between 1 and 9.\n";
            continue;
        }

        if (pos < 1 || pos > 9) {
            cout << "Please select a number between 1 and 9.\n";
        }
        else if (board[get_position(pos)][(pos - 1) % BOARD_SIZE] == 'X' ||
            board[get_position(pos)][(pos - 1) % BOARD_SIZE] == 'O') {
            cout << "That position is already taken. Please choose another.\n";
        }
        else {
            board[get_position(pos)][(pos - 1) % BOARD_SIZE] = symbol;
            break;
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void computer_move() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int pos;

    // Simple AI - first look for a winning move, then random
    // Check if computer can win
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        int row = get_position(i + 1);
        int col = (i) % BOARD_SIZE;
        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = 'O';
            if (check_winner() == 'O') {
                return;
            }
            board[row][col] = static_cast<char>('0' + i + 1);
        }
    }

    // Block player if they're about to win
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        int row = get_position(i + 1);
        int col = (i) % BOARD_SIZE;
        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = 'X';
            if (check_winner() == 'X') {
                board[row][col] = 'O';
                return;
            }
            board[row][col] = static_cast<char>('0' + i + 1);
        }
    }

    // Otherwise make a random move
    do {
        pos = rand() % (BOARD_SIZE * BOARD_SIZE) + 1;
    } while (board[get_position(pos)][(pos - 1) % BOARD_SIZE] == 'X' ||
        board[get_position(pos)][(pos - 1) % BOARD_SIZE] == 'O');

    board[get_position(pos)][(pos - 1) % BOARD_SIZE] = 'O';
}

int count_board(char symbol) {
    int total = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == symbol) {
                total++;
            }
        }
    }
    return total;
}

int get_position(int pos) {
    return (pos - 1) / BOARD_SIZE;
}

void clear_screen() {
#if defined(_WIN32)
    system("cls");
#else
    system("clear");
#endif
}

bool play_again() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return (choice == 'y' || choice == 'Y');
}

void reset_board() {
    initialize_board();
}

void computer_vs_player() {
    string name;
    clear_screen();

    cout << "Please Enter Player's Name: ";
    getline(cin, name);

    while (true) {
        show_board();

        if (count_board('X') == count_board('O')) {
            player_move('X', name);
        }
        else {
            cout << "Computer's Turn...\n";
            this_thread::sleep_for(chrono::seconds(1));
            computer_move();
        }

        char winner = check_winner();
        if (winner == 'X') {
            show_board();
            cout << name << " wins!\n";
            break;
        }
        else if (winner == 'O') {
            show_board();
            cout << "Computer wins!\n";
            break;
        }
        else if (winner == 'D') {
            show_board();
            cout << "It's a draw!\n";
            break;
        }
    }
}

void player_vs_player() {
    string player1_name, player2_name;
    clear_screen();

    cout << "Enter Player [X] Name: ";
    getline(cin, player1_name);
    cout << "Enter Player [O] Name: ";
    getline(cin, player2_name);

    while (true) {
        show_board();

        if (count_board('X') == count_board('O')) {
            player_move('X', player1_name);
        }
        else {
            player_move('O', player2_name);
        }

        char winner = check_winner();
        if (winner == 'X') {
            show_board();
            cout << player1_name << " wins!\n";
            break;
        }
        else if (winner == 'O') {
            show_board();
            cout << player2_name << " wins!\n";
            break;
        }
        else if (winner == 'D') {
            show_board();
            cout << "It's a draw!\n";
            break;
        }
    }
}
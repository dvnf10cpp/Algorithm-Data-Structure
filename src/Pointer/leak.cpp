#include <bits/stdc++.h>
#include <windows.h>

using namespace std;
/**
 * Demo memory leak using simple betting game
 * Player guess the position of queen
 * If he wins, he takes 3 * bet
 * Else he loose the bet
 * To monitor the memory leak, open task manager
*/

struct Player {
    string name;
    int cash;

    Player(string name) : name(name), cash(100) {}
    
    bool cantPlay() { return cash <=0; }
    void info() {
        cout << "====================\n";
        cout << "INFO\n";
        cout << "--------------------\n";
        cout << "Name: " << name << endl;
        cout << "Cash: " << cash << endl;
        cout << "--------------------\n";
    }
};

void play(Player *player, int *bet) {
    // char card[3] = {'J', 'Q', 'K'}; // goes to stack
    char *card = new char[3]; // goes to heap
    card[0] = 'J'; card[1] = 'Q'; card[2] = 'K';
    printf("Shuffling"); for(int i=0;i<5;i++) { Sleep(250); printf("."); }
    srand(time(NULL)); // seeding rng
    cout << endl;
    for(int i = 0; i<5; i++) {
        int x = rand() % 3;
        int y = rand() % 3;
        swap(card[x], card[y]);
    }
    int guess;
    printf("What's the position of queen? (1,2,3): ");
    scanf("%d", &guess);
    if (toupper(card[guess - 1]) == 'Q') {
        player->cash += 3 * *(bet);
        printf("You won cash!!!\n");
    }
    else {
        player->cash -= *bet;
        printf("You lose your cash!\n");
    }
    // since we use pointer, use arrow instead of dot to access member of class
    player->info();

    // try to comment bellow code and see the memory in task manager
    // look for leak in process (for windows)
    delete card;
}

int main() {
    struct Player *player = new Player("Dev");  // goes on heap memory since using new keyword
    int bet;
    while(!player->cantPlay()) {
        printf("What's your bet ? $");
        scanf("%d", &bet);  
        if (bet <= 0 || bet > player->cash) {
            printf("Cash is less than the bet\n");
            printf("--------------------------------------\n");
            continue;
        }
        play(player, &bet); //passing structs dont need & when the function retrieves pointer to struct
    }
    printf("Oh well you can't play anymore, try next time!\n");

    delete player; // deallocate the memory on heap, good practice,  
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#include "Card.h"
#include "Deck.h"
#include "Set.h"
#include "Warrior.h"
#include "Wizard.h"
#include "Archer.h"
#include "Enemy.h"
#include "Exceptions.h"

static const char* RANKS[] = {"2","3","4","5","6","7","8","9","T","J","Q","K","A"};
static const char* SUITS[]  = {"C","S","H","D"};

Deck buildShuffledDeck() {
    std::vector<std::string> all;
    for (auto r : RANKS)
        for (auto s : SUITS)
            all.push_back(std::string(r) + s);

    std::srand(static_cast<unsigned>(std::time(nullptr)));
    for (int i = static_cast<int>(all.size()) - 1; i > 0; i--) {
        int j = std::rand() % (i + 1);
        std::swap(all[i], all[j]);
    }

    Deck d;
    for (const auto& s : all)
        d += Card(s.c_str());
    return d;
}

Character* selectCharacter() {
    std::cout << "\nChoose your character:\n"
              << "  1. Warrior  (60 HP | 6-card hand | Club affinity +5)\n"
              << "  2. Wizard   (45 HP | 5-card hand | Heart affinity +8)\n"
              << "  3. Archer   (35 HP | 7-card hand | Spade affinity +3/card)\n"
              << "Choice: ";

    int choice = 0;
    std::cin >> choice;

    switch (choice) {
        case 1: return new Warrior();
        case 2: return new Wizard();
        case 3: return new Archer();
        default:
            std::cout << "Invalid choice. Defaulting to Warrior.\n";
            return new Warrior();
    }
}

void printHand(const Deck& hand) {
    std::cout << "Your hand: " << hand << "\n";
}

// Attempt to draw up to maxCards; stop when the supply deck runs out.
void refillHand(Deck& hand, Deck& supply, int maxHandSize) {
    while (hand.size() < maxHandSize && !supply.empty()) {
        hand += supply[0];
        supply -= 1;
    }
}

// Remove set cards from the player's hand (first occurrence of each).
void discardPlayedSet(Deck& hand, const Set& played, int setCardCount) {
    // Simple approach: rebuild hand minus the first N cards that matched.
    // For this demo we drop setCardCount cards from the top.
    hand -= setCardCount;
}

void runCombatLoop(Character* player, Enemy& enemy, Deck& supply) {
    Deck hand;
    refillHand(hand, supply, player->maxHandSize());

    while (player->isAlive() && enemy.isAlive()) {
        std::cout << "\n--- Your Turn ---\n";
        player->printStatus();
        enemy.printStatus();
        printHand(hand);

        std::cout << "Enter a set (e.g. QH-KH-AH-00): ";
        std::string input;
        std::cin >> input;

        try {
            Set played(input);
            if (!played.isValid()) {
                std::cout << "Invalid set. Cards must share the same rank or suit. Try again.\n";
                continue;
            }

            int dmg = player->calculateAttack(played);
            enemy.takeDamage(dmg);
            std::cout << "You played " << played << " for " << dmg << " damage!\n";

            discardPlayedSet(hand, played, played.cardCount());
            refillHand(hand, supply, player->maxHandSize());

            if (!enemy.isAlive()) break;

            int enmyDmg = enemy.attackPower();
            player->takeDamage(enmyDmg);
            std::cout << enemy.name() << " strikes back for " << enmyDmg << " damage!\n";

        } catch (const GameException& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    if (player->isAlive())
        std::cout << "\n*** Victory! You defeated the " << enemy.name() << "! ***\n";
    else
        std::cout << "\n*** Defeated. Better luck next time. ***\n";
}

int main() {
    std::cout << "=== Card Duel ===\n";

    Character* player = selectCharacter();
    std::cout << "\nWelcome, " << player->name() << "!\n";

    Deck supply = buildShuffledDeck();
    Enemy goblin("Goblin King", 50, 8);

    runCombatLoop(player, goblin, supply);

    delete player;
    return 0;
}
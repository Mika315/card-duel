# Card Duel

A turn-based card battle game written in C++. Players choose a character class,
draw cards from a shuffled deck, and form valid card sets to deal damage to enemies.
Each character has unique stats and a suit affinity that grants bonus damage.

## Features

- Three playable character classes: Warrior, Wizard, and Archer
- Rule-of-Three–compliant Card and Deck classes with full operator overloading
- Set validation logic (same-rank or same-suit groups)
- Turn-based combat loop with enemy AI
- Custom exception hierarchy

## Tech Stack

- **Language:** C++14
- **Build System:** CMake 3.28+
- **Standard Library:** STL (vector, string, ostream)

## Build & Run
```bash
git clone https://github.com/yourusername/card-duel.git
cd card-duel
mkdir build && cd build
cmake ..
make
./CardDuel
```

## Gameplay

1. Choose a character class at the start of the game.
2. You are dealt a hand of cards (size depends on your class).
3. Each turn, enter a set of cards from your hand to attack (e.g. `QH-KH-AH`).
   A valid set shares either the same rank or the same suit. End input with `00`.
4. Your set's total value (plus any suit-affinity bonus) is dealt as damage.
5. The enemy strikes back for a fixed amount each round.
6. First side to reach 0 HP loses.

## Project Structure
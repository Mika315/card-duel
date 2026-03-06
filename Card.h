#pragma once

#include <iosfwd>

// Rank point values used in combat calculations.
// Ten and Jack are both worth 10 (intentional game design).
enum CardRank { A = 1, T = 10, J = 10, Q = 15, K = 20 };

// Suit affinity values; higher means a stronger default affinity.
enum CardSuit { D = 1, H = 2, S = 3, C = 4 };

class Card {
public:
    explicit Card(const char* input);
    Card();
    Card(const char* rank, const char* suit);
    Card(const Card& other);
    Card& operator=(const Card& other);
    ~Card();

    bool operator==(const Card& other) const;
    bool operator!=(const Card& other) const;
    bool operator<(const Card& other)  const;
    bool operator<=(const Card& other) const;
    bool operator>(const Card& other)  const;
    bool operator>=(const Card& other) const;

    int rankValue() const;
    int suitValue() const;
    bool isValid() const;

    friend std::ostream& operator<<(std::ostream& out, const Card& c);

private:
    char* _rank;
    char* _suit;

    std::ostream& print(std::ostream& out) const;
};
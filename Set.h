#pragma once

#include <string>
#include <vector>
#include "Card.h"

// A Set is a collection of 1–N cards that are either all the same rank
// or all the same suit. Sets are the unit of attack in combat.
class Set {
public:
    Set();
    explicit Set(const std::string& input);
    Set(const Set& other) = default;
    Set& operator=(const Set& other) = default;
    ~Set() = default;

    bool isValid()    const;
    int  totalValue() const;
    int  cardCount()  const;
    char leadSuit()   const;

    friend std::ostream& operator<<(std::ostream& out, const Set& s);

private:
    std::vector<Card> _cards;

    bool allSameRank() const;
    bool allSameSuit() const;
};
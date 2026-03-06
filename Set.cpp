#include "Set.h"
#include "Exceptions.h"

#include <sstream>
#include <iostream>

Set::Set() {}

// Input format: "QH-KH-AH-00"  (cards separated by '-', terminated by "00")
Set::Set(const std::string& input) {
    std::istringstream stream(input);
    std::string token;

    while (std::getline(stream, token, '-')) {
        if (token == "00") break;
        if (token.length() == 2) {
            Card c(token.c_str());
            if (c.isValid())
                _cards.push_back(c);
        }
    }
}

bool Set::allSameRank() const {
    if (_cards.empty()) return false;
    int base = _cards[0].rankValue();
    for (size_t i = 1; i < _cards.size(); i++)
        if (_cards[i].rankValue() != base) return false;
    return true;
}

bool Set::allSameSuit() const {
    if (_cards.empty()) return false;
    int base = _cards[0].suitValue();
    for (size_t i = 1; i < _cards.size(); i++)
        if (_cards[i].suitValue() != base) return false;
    return true;
}

bool Set::isValid() const {
    if (_cards.empty()) return false;
    if (_cards.size() == 1) return true;
    return allSameRank() || allSameSuit();
}

int Set::totalValue() const {
    int total = 0;
    for (const auto& c : _cards)
        total += c.rankValue();
    return total;
}

int Set::cardCount() const {
    return static_cast<int>(_cards.size());
}

char Set::leadSuit() const {
    if (_cards.empty()) return '\0';
    // Return the first character of the suit string by re-printing
    // (suitValue maps back to char for affinity checks)
    int sv = _cards[0].suitValue();
    if (sv == C) return 'C';
    if (sv == S) return 'S';
    if (sv == H) return 'H';
    if (sv == D) return 'D';
    return '\0';
}

std::ostream& operator<<(std::ostream& out, const Set& s) {
    for (size_t i = 0; i < static_cast<size_t>(s.cardCount()); i++) {
        out << s._cards[i];
        if (i + 1 < static_cast<size_t>(s.cardCount())) out << "-";
    }
    return out;
}
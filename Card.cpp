#include "Card.h"

#include <cstdlib>
#include <cstring>
#include <iostream>

Card::Card(const char* input) : _rank(nullptr), _suit(nullptr) {
    if (!input || strlen(input) != 2) return;

    _rank = new char[2];
    _rank[0] = input[0];
    _rank[1] = '\0';

    _suit = new char[2];
    _suit[0] = input[1];
    _suit[1] = '\0';
}

Card::Card() : _rank(nullptr), _suit(nullptr) {}

Card::Card(const char* rank, const char* suit) : _rank(nullptr), _suit(nullptr) {
    if (!rank || !suit) return;

    _rank = new char[strlen(rank) + 1];
    strcpy(_rank, rank);

    _suit = new char[strlen(suit) + 1];
    strcpy(_suit, suit);
}

Card::Card(const Card& other) : _rank(nullptr), _suit(nullptr) {
    if (other._rank) {
        _rank = new char[strlen(other._rank) + 1];
        strcpy(_rank, other._rank);
    }
    if (other._suit) {
        _suit = new char[strlen(other._suit) + 1];
        strcpy(_suit, other._suit);
    }
}

Card& Card::operator=(const Card& other) {
    if (this == &other) return *this;

    delete[] _rank;
    delete[] _suit;
    _rank = _suit = nullptr;

    if (other._rank) {
        _rank = new char[strlen(other._rank) + 1];
        strcpy(_rank, other._rank);
    }
    if (other._suit) {
        _suit = new char[strlen(other._suit) + 1];
        strcpy(_suit, other._suit);
    }
    return *this;
}

Card::~Card() {
    delete[] _rank;
    delete[] _suit;
}

bool Card::isValid() const {
    return _rank != nullptr && _suit != nullptr;
}

bool Card::operator==(const Card& other) const {
    return rankValue() == other.rankValue() && suitValue() == other.suitValue();
}
bool Card::operator!=(const Card& other) const { return !(*this == other); }
bool Card::operator<(const Card& other) const {
    if (rankValue() != other.rankValue()) return rankValue() < other.rankValue();
    return suitValue() < other.suitValue();
}
bool Card::operator<=(const Card& other) const { return !(other < *this); }
bool Card::operator>(const Card& other) const  { return other < *this; }
bool Card::operator>=(const Card& other) const { return !(*this < other); }

std::ostream& Card::print(std::ostream& out) const {
    if (_rank && _suit)
        out << _rank << _suit;
    else
        out << "??";
    return out;
}

std::ostream& operator<<(std::ostream& out, const Card& c) {
    return c.print(out);
}

int Card::rankValue() const {
    if (!_rank) return 0;
    if (strcmp(_rank, "A") == 0) return A;
    if (strcmp(_rank, "T") == 0) return T;
    if (strcmp(_rank, "J") == 0) return J;
    if (strcmp(_rank, "Q") == 0) return Q;
    if (strcmp(_rank, "K") == 0) return K;
    return static_cast<int>(strtol(_rank, nullptr, 10));
}

int Card::suitValue() const {
    if (!_suit) return 0;
    if (strcmp(_suit, "C") == 0) return C;
    if (strcmp(_suit, "S") == 0) return S;
    if (strcmp(_suit, "H") == 0) return H;
    if (strcmp(_suit, "D") == 0) return D;
    return 0;
}
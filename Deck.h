#pragma once

#include <iosfwd>
#include "Card.h"

class Deck {
public:
    Deck();
    Deck(const Deck& other);
    Deck& operator=(const Deck& other);
    ~Deck();

    Deck& operator+=(const Card& c);
    Deck& operator-=(int count);

    const Card& operator[](int index) const;
    Card& operator[](int index);

    int  size() const;
    bool empty() const;
    void peek(int count) const;

    friend std::ostream& operator<<(std::ostream& out, const Deck& d);

private:
    Card* _cards;
    int   _size;

    std::ostream& print(std::ostream& out) const;
};
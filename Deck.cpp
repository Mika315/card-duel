#include "Deck.h"
#include "Exceptions.h"

#include <iostream>

Deck::Deck() : _cards(nullptr), _size(0) {}

Deck::Deck(const Deck& other) : _cards(nullptr), _size(other._size) {
    if (_size > 0) {
        _cards = new Card[_size];
        for (int i = 0; i < _size; i++)
            _cards[i] = other._cards[i];
    }
}

Deck& Deck::operator=(const Deck& other) {
    if (this == &other) return *this;

    delete[] _cards;
    _size  = other._size;
    _cards = nullptr;

    if (_size > 0) {
        _cards = new Card[_size];
        for (int i = 0; i < _size; i++)
            _cards[i] = other._cards[i];
    }
    return *this;
}

Deck::~Deck() {
    delete[] _cards;
}

Deck& Deck::operator+=(const Card& c) {
    Card* tmp = new Card[_size + 1];
    tmp[0] = c;
    for (int i = 0; i < _size; i++)
        tmp[i + 1] = _cards[i];
    delete[] _cards;
    _cards = tmp;
    _size++;
    return *this;
}

Deck& Deck::operator-=(int count) {
    if (count <= 0) return *this;
    if (count >= _size) {
        delete[] _cards;
        _cards = nullptr;
        _size  = 0;
        return *this;
    }
    int newSize = _size - count;
    Card* tmp   = new Card[newSize];
    for (int i = 0; i < newSize; i++)
        tmp[i] = _cards[i];
    delete[] _cards;
    _cards = tmp;
    _size  = newSize;
    return *this;
}

const Card& Deck::operator[](int index) const {
    if (index < 0 || index >= _size) throw InvalidIndexException();
    return _cards[_size - 1 - index];
}

Card& Deck::operator[](int index) {
    if (index < 0 || index >= _size) throw InvalidIndexException();
    return _cards[_size - 1 - index];
}

int  Deck::size()  const { return _size; }
bool Deck::empty() const { return _size == 0; }

void Deck::peek(int count) const {
    int limit = (count > _size) ? _size : count;
    for (int i = 0; i < limit; i++)
        std::cout << _cards[_size - 1 - i] << "\n";
}

std::ostream& Deck::print(std::ostream& out) const {
    out << "[";
    for (int i = 0; i < _size; i++) {
        out << _cards[i];
        if (i != _size - 1) out << ", ";
    }
    out << "]";
    return out;
}

std::ostream& operator<<(std::ostream& out, const Deck& d) {
    return d.print(out);
}
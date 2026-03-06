

#pragma once

#include <exception>
#include <string>

class GameException : public std::exception {
public:
    explicit GameException(const char* msg) : _msg(msg) {}
    const char* what() const noexcept override { return _msg; }
private:
    const char* _msg;
};

class MemoryAllocationException : public GameException {
public:
    MemoryAllocationException() : GameException("Memory allocation failed.") {}
};

class InvalidCardException : public GameException {
public:
    InvalidCardException() : GameException("Invalid card format.") {}
};

class InvalidSetException : public GameException {
public:
    InvalidSetException() : GameException("The provided card set is not valid.") {}
};

class InvalidIndexException : public GameException {
public:
    InvalidIndexException() : GameException("Index is out of range.") {}
};
#ifndef MAP_H
#define MAP_H

#include <cstddef>
#include <ostream>

template<typename T1, typename T2>
struct pair {
    T1 key;
    T2 value;
};

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const pair<T1, T2>& pair) {
    os << "(" << pair.key << ", " << pair.value << ")";
    return os;
}

template<typename Key, class T>
class Map {
public:
    Map() : pairs(nullptr), size(0) {
    }

    Map(const Map& other) : size(other.size) {
        pairs = new pair<Key, T>[size];
        for (size_t i = 0; i < size; ++i) {
            pairs[i] = other.pairs[i];
        }
    }

    Map& operator=(const Map& other) {
        if (this != &other) {
            delete[] pairs;
            size = other.size;
            pairs = new pair<Key, T>[size];
            for (size_t i = 0; i < size; i++) {
                pairs[i] = other.pairs[i];
            }
        }
        return *this;
    }

    ~Map() {
        delete[] pairs;
    }

    void add(Key key, T value) {
        T* existing = find(key);
        if (existing) {
            *existing = value;
            return;
        }

        size++;
        auto* newPairs = new pair<Key, T>[size];

        for (size_t i = 0; i < size - 1; i++) {
            newPairs[i] = pairs[i];
        }
        newPairs[size - 1] = pair<Key, T>(key, value);

        delete[] pairs;
        pairs = newPairs;
    }

    T* find(Key ID) {
        for (size_t i = 0; i < size; ++i) {
            if (pairs[i].key == ID) {
                return &pairs[i].value;
            }
        }
        return nullptr;
    }

    friend std::ostream& operator<<(std::ostream& os, const Map<Key, T>& map) {
        os << "[";
        for (size_t i = 0; i < map.size; i++) {
            os << map.pairs[i];
            if (i != map.size - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

private:
    pair<Key, T>* pairs;
    size_t size;
};

#endif

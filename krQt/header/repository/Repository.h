#pragma once

#include <vector>
#include <algorithm>
#include <functional>
#include <ranges>

template<typename T>
class Repository {
public:
    using Iterator = typename std::vector<T>::iterator;
    using ConstIterator = typename std::vector<T>::const_iterator;

    Repository() = default;
    virtual ~Repository() = default;

    void add(const T& item) {
        items.push_back(item);
    }

    void remove(std::function<bool(const T&)> predicate) {
        auto [first, last] = std::ranges::remove_if(items, predicate);
        items.erase(first, last);
    }

    void update(std::function<bool(const T&)> predicate, const T& newItem) {
        auto it = std::ranges::find_if(items, predicate);
        if (it != items.end()) {
            *it = newItem;
        }
    }

    void clear() {
        items.clear();
    }

    T* find(std::function<bool(const T&)> predicate) {
        auto it = std::ranges::find_if(items, predicate);
        return it != items.end() ? &(*it) : nullptr;
    }

    const T* find(std::function<bool(const T&)> predicate) const {
        auto it = std::ranges::find_if(items, predicate);
        return it != items.end() ? &(*it) : nullptr;
    }

    std::vector<T> filter(std::function<bool(const T&)> predicate) const {
        std::vector<T> result;
        std::ranges::copy_if(items, std::back_inserter(result), predicate);
        return result;
    }

    std::vector<T> getAll() const {
        return items;
    }

    void setAll(const std::vector<T>& newItems) {
        items = newItems;
    }

    size_t size() const {
        return items.size();
    }

    bool empty() const {
        return items.empty();
    }

    Iterator begin() {
        return items.begin();
    }

    Iterator end() {
        return items.end();
    }

    ConstIterator begin() const {
        return items.begin();
    }

    ConstIterator end() const {
        return items.end();
    }

    ConstIterator cbegin() const {
        return items.cbegin();
    }

    ConstIterator cend() const {
        return items.cend();
    }

private:
    std::vector<T> items;
};
#pragma once

#include <vector>
#include <algorithm>
#include <functional>

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
        items.erase(
            std::remove_if(items.begin(), items.end(), predicate),
            items.end()
        );
    }

    void update(std::function<bool(const T&)> predicate, const T& newItem) {
        auto it = std::find_if(items.begin(), items.end(), predicate);
        if (it != items.end()) {
            *it = newItem;
        }
    }

    void clear() {
        items.clear();
    }

    T* find(std::function<bool(const T&)> predicate) {
        auto it = std::find_if(items.begin(), items.end(), predicate);
        return it != items.end() ? &(*it) : nullptr;
    }

    const T* find(std::function<bool(const T&)> predicate) const {
        auto it = std::find_if(items.begin(), items.end(), predicate);
        return it != items.end() ? &(*it) : nullptr;
    }

    std::vector<T> filter(std::function<bool(const T&)> predicate) const {
        std::vector<T> result;
        std::copy_if(items.begin(), items.end(), std::back_inserter(result), predicate);
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

protected:
    std::vector<T> items;
};


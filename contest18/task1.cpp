#include <iostream>
#include <unordered_map>
#include <string>

template <typename Key, typename Value>
class KeyValueStorage {
private:
    std::unordered_map<Key, Value> data;

public:
    void Insert(const Key& key, const Value& value) {
        data[key] = value;
    }

    void Remove(const Key& key) {
        data.erase(key);
    }

    bool Find(const Key& key, Value* const value = nullptr) const;
};

template <typename Key, typename Value>
bool KeyValueStorage<Key, Value>::Find(const Key& key, Value* const value) const {
    auto it = data.find(key);

    if (it != data.end()) {
        if (value != nullptr) {
            *value = it->second;
        }
        return true;
    }

    return false;
}

int main() {
    KeyValueStorage<std::string, int> kv;
    kv.Insert("hello", 42);
    kv.Insert("bye", -13);

    int value = 123;
    auto res = kv.Find("wrong", &value);  // должно вернуться false, а value не должен меняться
    std::cout << "Result: " << res << ", Value: " << value << std::endl;

    res = kv.Find("bye", &value);  // должно вернуться true, в value должно быть -13
    std::cout << "Result: " << res << ", Value: " << value << std::endl;

    res = kv.Find("hello", nullptr);  // должно вернуться true
    std::cout << "Result: " << res << std::endl;

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <map>

class Item {
public:
    Item(const std::string& name, unsigned weight, unsigned price)
        : name(name), weight(weight), price(price) {}

    const std::string& get_name() const {
        return name;
    }

    unsigned get_weight() const {
        return weight;
    }

    unsigned get_price() const {
        return price;
    }

    void print(std::ostream& os) const {
        os << ": " << name << " " << weight << " " << price;
    }

private:
    std::string name;
    unsigned weight;
    unsigned price;
};

class Inventory {
public:
    explicit Inventory(unsigned size) : max_size(size), current_size(0) {}

    bool put(const Item& item) {
        if (current_size + item.get_weight() <= max_size) {
            items.push_back(item);
            current_size += item.get_weight();
            return true;
        }
        return false;
    }

    void print(std::ostream& os) const {
        for (const Item& item : items) {
            item.print(os);
            os << std::endl;
        }
    }

private:
    unsigned max_size;
    unsigned current_size;
    std::vector<Item> items;
};

class Player {
public:
    Player() = default;
    Player(const std::string& name, unsigned strength)
        : name(name), strength(strength) {}

    const std::string& get_name() const {
        return name;
    }

    bool take(const Item& item) {
        return inventory.put(item);
    }

    void print(std::ostream& os) const {
        os << name << std::endl;
        inventory.print(os);
    }

private:
    std::string name;
    unsigned strength;
    Inventory inventory{strength};
};

class Party {
public:
    bool add(const Player& player) {
        if (players.find(player.get_name()) == players.end()) {
            players[player.get_name()] = player;
            return true;
        }
        return false;
    }

    bool give(const std::string& player_name, const Item& item) {
        auto it = players.find(player_name);
        if (it != players.end()) {
            return it->second.take(item);
        }
        return false;
    }

    void print(std::ostream& os) const {
        for (const auto& pair : players) {
            pair.second.print(os);
        }
    }

private:
    std::map<std::string, Player> players;
};

int main() {
    Party p;
    p.add(Player("Anti-Mage", 15));
    p.add(Player("Razor", 18));
    p.give("Razor", Item("Necronomicon", 1, 5));
    p.give("Anti-Mage", Item("Refresher_Orb", 2, 2));
    p.print(std::cout);
    return 0;
}

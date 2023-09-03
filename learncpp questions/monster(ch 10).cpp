#include <iostream>
#include <string_view>

enum class MonsterType {
    ogre,
    dragon,
    orc,
    spider,
    slime,
};

struct Monster {
    MonsterType type{ };
    std::string_view name{ };
    int health{ };
};

constexpr std::string_view getType(const Monster& monster) {
    switch(monster.type) {
        case MonsterType::ogre:
            return "Ogre";
        case MonsterType::dragon:
            return "dragon";
        case MonsterType::orc:
            return "Orc";
        case MonsterType::spider:
            return "Spider";
        case MonsterType::slime:
            return "Slime";
        default:
            return "???";
    }
}

void printMonster(const Monster& monster) {
    std::cout << "This " << getType(monster) << " is named " << monster.name 
    << " and has " << monster.health << " health.\n";
}

int main() {
    Monster ogre{ MonsterType::ogre, "Torg", 145 };
    Monster slime{ MonsterType::slime, "Blurp", 23};

    printMonster(ogre);
    printMonster(slime);

    return 0;
}
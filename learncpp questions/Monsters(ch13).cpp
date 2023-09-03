#include "random.h"
#include <array>
#include <iostream>
#include <string>

constexpr int max_hit_count{100};

class Monster
{
public:
    enum class Type
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        max_monster_types,
    };

private:
    Type m_type{};
    std::string m_name{};
    std::string m_roar{};
    int m_hitPoints{};

public:
    Monster(Type type, const std::string &name, const std::string &roar, int hitPoints)
        : m_type{type}, m_name{name}, m_roar{roar}, m_hitPoints{hitPoints} {};

    std::string getTypeString() const
    {
        switch (m_type)
        {
        case Type::dragon:
            return "dragon";
        case Type::goblin:
            return "goblin";
        case Type::ogre:
            return "ogre";
        case Type::orc:
            return "orc";
        case Type::skeleton:
            return "skeleton";
        case Type::troll:
            return "troll";
        case Type::vampire:
            return "vampire";
        case Type::zombie:
            return "zombie";
        default:
            return "???";
        }
    }

    void print() const
    {
        std::cout << m_name << " the " << getTypeString() << " has "
                  << m_hitPoints << " points and says " << m_roar;
    }
};

class MonsterGenerator
{
public:
    static Monster generateMonster()
    {
        int randomType{static_cast<int>(Monster::Type::max_monster_types) - 1};
        static constexpr std::array s_names{"Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans"};
        static constexpr std::array s_roars{"*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*"};
        return {
            static_cast<Monster::Type>(Random::get(0, randomType)),
            s_names[static_cast<std::size_t>(Random::get(0, s_names.size() - 1))],
            s_roars[static_cast<std::size_t>(Random::get(0, s_roars.size() - 1))],
            Random::get(0, max_hit_count)};
    }
};

int main()
{
    Monster m{MonsterGenerator::generateMonster()};
    m.print();

    return 0;
}
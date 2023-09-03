#include "random.h"
#include <array>
#include <iostream>
#include <string>
#include <string_view>

class Creature
{
protected:
  std::string m_name{};
  char m_symbol{};
  int m_health{};
  int m_damage{};
  int m_gold{};

public:
  Creature(
      std::string_view name,
      char symbol,
      int health,
      int damage,
      int gold) : m_name{name}, m_symbol{symbol}, m_health{health},
                  m_damage{damage}, m_gold{gold} {}
  std::string_view getName() { return m_name; }
  char getSymbol() const { return m_symbol; }
  int getHealth() const { return m_health; }
  int getDamage() const { return m_damage; }
  int getGold() const { return m_gold; }

  void reduceHealth(int reducedHealth) { m_health -= reducedHealth; }
  bool isDead() const { return m_health <= 0; }
  void addGold(int gold)
  {
    m_gold += gold;
  }
};

class Monster;

class Player : public Creature
{
private:
  int m_level{1};

public:
  explicit Player(std::string_view name) : Creature{name, '@', 10, 1, 0}
  {
  }
  void levelUp()
  {
    std::cout << "You are now level " << ++m_level << ".\n";
    ++m_damage;
  }
  int getLevel() const { return m_level; }
  bool hasWon() const { return m_level > 20; }
  void attackMonster(Monster &monster);
  bool fightMonster(Monster &Monster);
};

class Monster : public Creature
{
public:
  enum class Type
  {
    dragon,
    orc,
    slime,
    max_types,
  };

private:
  static const Creature &getDefaultCreature(Type type)
  {
    static const std::array<Creature, static_cast<std::size_t>(Type::max_types)> MonsterData{
        {{"dragon", 'D', 20, 4, 100},
         {"orc", 'o', 4, 2, 25},
         {"slime", 's', 1, 1, 10}}};
    return MonsterData.at(static_cast<std::size_t>(type));
  }

public:
  explicit Monster(Type type) : Creature(getDefaultCreature(type))
  {
  }
  static Monster getRandomMonster()
  {
    return Monster{
        static_cast<Type>(Random::get(0, static_cast<int>(Type::max_types) - 1))};
  }
  void attackPlayer(Player &player)
  {
    player.reduceHealth(m_damage);
    std::cout << "The " << m_name << " hit you for " << m_damage << " damage\n";
  }
};

void Player::attackMonster(Monster &monster)
{
  monster.reduceHealth(m_damage);
  std::cout << "You hit the " << monster.getName()
            << " for " << m_damage << " damage.\n";
}

bool Player::fightMonster(Monster &monster)
{
  std::cout << "You've encountered a " << monster.getName() << ".\n";
  while (true)
  {
    std::cout << "(R)un or (F)ight: ";
    char nextMove{};
    std::cin >> nextMove;

    if (nextMove == 'r')
    {
      const int rand{Random::get(0, 1)};
      if (rand == 0)
      {
        std::cout << "You failed to flee.\n";
      }
      else
      {
        std::cout << "You succesfully fled.\n";
        return true;
      }
    }
    else if (nextMove == 'f')
    {
      attackMonster(monster);
    }

    if (monster.isDead())
    {
      std::cout << "You killed the " << monster.getName() << ".\n";
      levelUp();
      std::cout << "You found " << monster.getGold() << " gold.\n";
      addGold(monster.getGold());
      return true;
    }
    monster.attackPlayer(*this);

    if (isDead())
    {
      std::cout << "You died at level " << m_level << " and with "
                << m_gold << " gold.\n";
      std::cout << "Too bad you can't take it with you!\n";
      return false;
    }
  }
}

int main()
{
  std::string playerName{};
  std::cout << "Please enter your name: ";
  std::cin >> playerName;

  Player player{playerName};
  std::cout << "Welcome, " << player.getName() << ".\n";

  while (true)
  {
    Monster monster{Monster::getRandomMonster()};
    if (!player.fightMonster(monster))
    {
      break;
    }
  }

  return 0;
}
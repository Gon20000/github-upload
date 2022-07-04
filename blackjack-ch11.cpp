#include "random.cpp"
#include <array>
#include <algorithm>
#include <iostream>

// Minimum score that the dealer has to have.
constexpr int minimumDealerScore{ 17 };

// Maximum score before losing.
constexpr int bustValue{ 21 }; 

enum class CardRank {
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    king,
    queen,
    ace,

    maxRanks,
};

enum class CardSuit {
    clubs, 
    diamonds, 
    hearts, 
    spades,

    maxSuits,
};

struct Card {
    CardRank rank{};
    CardSuit suit{};
};

using deckType = std::array<Card, 52>;

void printCard(const Card& card) {
    switch(card.rank) {
        case CardRank::two:
            std::cout << '2';
            break;
        case CardRank::three:
            std::cout << '3';
            break;
        case CardRank::four:
            std::cout << '4';
            break;
        case CardRank::five:
            std::cout << '5';
            break;
        case CardRank::six:
            std::cout << '6';
            break;
        case CardRank::seven:
            std::cout << '7';
            break;
        case CardRank::eight:
            std::cout << '8';
            break;
        case CardRank::nine:
            std::cout << '9';
            break;
        case CardRank::ten:
            std::cout << 'T';
            break;
        case CardRank::jack:
            std::cout << 'J';
            break;
        case CardRank::king:
            std::cout << 'K';
            break;
        case CardRank::queen:
            std::cout << 'Q';
            break;
        case CardRank::ace:
            std::cout << 'A';
            break;
        default:
            std::cout << '?';
            break;
    }

    switch (card.suit) {
    case CardSuit::clubs:
        std::cout << 'C';
        break;
    case CardSuit::diamonds:
        std::cout << 'D';
        break;
    case CardSuit::hearts:
        std::cout << 'H';
        break;
    case CardSuit::spades:
        std::cout << 'S';
        break;
    default:
        std::cout << '?';
        break;
    }
}

deckType createDeck() {
    deckType deck{};
    for(deckType::size_type i{ 0 }; i < 52; ++i) {
        deck[i].rank = static_cast<CardRank>(i % 13);
        deck[i].suit = static_cast<CardSuit>(i / 13);
    }

    return deck;
}

void printDeck(const deckType& deck) {
    for(const Card& card : deck) {
        printCard(card);
        std::cout << ' ';
    }
    std::cout << '\n';
}

void shuffleDeck(deckType& deck) {
    std::shuffle(deck.begin(), deck.end(), Random::systemMt);
}

int getCardValue(const Card& card) {
    switch (card.rank) {
        case CardRank::two:     return 2;
        case CardRank::three:   return 3;
        case CardRank::four:    return 4;
        case CardRank::five:    return 5;
        case CardRank::six:     return 6;
        case CardRank::seven:   return 7;
        case CardRank::eight:   return 8;
        case CardRank::nine:    return 9;
        case CardRank::ten:     return 10;
        case CardRank::jack:    return 10;
        case CardRank::king:    return 10;  
        case CardRank::queen:   return 10;
        case CardRank::ace:     return 11;
        default:                return 0;
    }
}

struct Player {
    int score{ 0 };
};

enum class blackjackResult {
    win,
    lose,
    draw,
};

bool playerTurn(Player& player, deckType &deck, std::size_t& index) {
    char move{};
    do {
        std::cout << "Your score is " << player.score << ". Type 'h' to hit or 's' to stand: ";
        std::cin >> move;
        if(move == 's')
            return false; // player doesn't lose
        player.score += getCardValue(deck[index++]);
    } while (player.score <= bustValue);

    std::cout << "You drew " << getCardValue(deck[index - 1]) << " and busted!\n";
    return true; //player loses
}

bool dealerTurn(Player& dealer, deckType &deck, std::size_t index) {
    while(dealer.score < minimumDealerScore) {
        int drew{ getCardValue(deck[index++]) };
        dealer.score += drew;
        std::cout << "The dealer drew " << drew << " and now has " 
        << dealer.score << '\n';

    }
    if (dealer.score > bustValue) {
        std::cout << "The dealer busted!\n";
        return true;
    }
    return false;
}

blackjackResult playBlackjack(deckType& deck) {
    std::size_t index { 0 };
    Player dealer{ getCardValue(deck[index++]) };
    Player player{ getCardValue(deck[index++]) + getCardValue(deck[index++])};
    if(playerTurn(player, deck, index))
        return blackjackResult::lose;
    else if (dealerTurn(dealer, deck, index))
        return blackjackResult::win;
    else
        return player.score == dealer.score ? blackjackResult::draw : 
        static_cast<blackjackResult>(player.score < dealer.score);
}

int main() {
    deckType deck{ createDeck() };
    shuffleDeck(deck);
    //printDeck(deck);
    switch (playBlackjack(deck)) {
        case blackjackResult::win:
            std::cout << "You won!\n";
            break;
        case blackjackResult::draw:
            std::cout << "It's a draw!\n";
            break;
        case blackjackResult::lose:
            std::cout << "You lose!\n";
            break;
    }

    return 0;
}
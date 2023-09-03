#include <array>
#include <iostream>
#include <string>

constexpr int alphabets_size{26};

class TrieNode
{
public:
    bool endOfWord{};
    std::array<TrieNode *, alphabets_size> children{};
    ~TrieNode()
    {
        for (TrieNode *child : children)
        {
            delete child;
        }
    }
};

class Trie
{
private:
    TrieNode *m_trie{new TrieNode()};

public:
    Trie()
    {
    }

    ~Trie()
    {
        delete m_trie;
    }

    Trie(const Trie &) = delete;
    const Trie &operator=(const Trie &) = delete;

    void add(std::string_view word)
    {
        TrieNode *curr{m_trie};
        for (std::size_t i{0}; i < word.size(); ++i)
        {
            std::size_t child{static_cast<std::size_t>(word[i] - 'a')};

            // check if the child doesn't exist then add a new letter
            if (curr->children[child] == nullptr)
            {
                curr->children[child] = new TrieNode();
            }
            curr = curr->children[child];
        }
        // should be marked as the last letter
        curr->endOfWord = true;
    }

    bool exists(std::string_view word)
    {
        TrieNode *curr{m_trie};
        for (std::size_t i{0}; i < word.size(); ++i)
        {
            curr = curr->children[static_cast<std::size_t>(word[i] - 'a')];

            // check if the child doesn't exist then exit the function
            if (curr == nullptr)
            {
                return false;
            }
        }
        return curr->endOfWord;
    }

    bool startswith(std::string_view word)
    {
        TrieNode *curr{m_trie};
        for (std::size_t i{0}; i < word.size(); ++i)
        {
            curr = curr->children[static_cast<std::size_t>(word[i] - 'a')];

            // check if the child doesn't exist then exit the function
            if (curr == nullptr)
            {
                return false;
            }
        }
        return true;
    }
};

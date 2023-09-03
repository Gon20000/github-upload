#include <exception>
#include <iostream>
#include <stdexcept>
#include <utility>

template <typename T>
class LLNode
{
private:
    T m_val{};
    LLNode<T> *m_next{nullptr};

public:
    LLNode() = default;
    explicit LLNode(T val) : m_val{val}
    {
    }
    LLNode(const LLNode &node)
    {
        m_val = node.val;
        m_next = node.m_next;
        node.m_next = nullptr;
    }
    T &val()
    {
        return m_val;
    }
    LLNode<T> *&next()
    {
        return m_next;
    }
};

template <typename T>
class LinkedList
{
    using node_t = LLNode<T>;

private:
    node_t *m_head;
    node_t *m_last;
    int m_size{1};

public:
    explicit LinkedList(T val) : m_head{new LLNode(val)}, m_last{m_head}
    {
    }

    LinkedList(const LinkedList<T> &llist) = delete;

    LinkedList(LinkedList<T> &&llist) noexcept = delete;

    LinkedList &operator=(const LinkedList<T> &llist) noexcept
    {
        if (this == &llist)
        {
            return *this;
        }
        clear();

        m_head = new node_t(llist.m_head->val());
        m_last = m_head;

        node_t *dummy{llist.m_head->next()};

        while (dummy)
        {
            insert(dummy->val());
            dummy = dummy->next();
        }

        return *this;
    }

    LinkedList &operator=(LinkedList<T> &&llist) noexcept
    {
        clear();
        m_head = new node_t(llist.m_head->val());
        m_last = m_head;

        return *this;
    }

    ~LinkedList()
    {
        clear();
    }

    friend std::ostream &operator<<(std::ostream &out, const LinkedList &llist)
    {
        node_t *dummy{llist.m_head};
        try
        {
            while (dummy)
            {
                out << dummy->val();
                dummy = dummy->next();
                if (dummy)
                {
                    std::cout << " -> ";
                }
            }
        }
        catch (const std::exception &)
        {
            throw std::runtime_error("LinkedList: Couldn't print the values of this Linked list.");
        }

        return out;
    }

    void clear()
    {
        while (m_head)
        {
            node_t *temp{m_head};
            m_head = m_head->next();
            delete temp;
        }
        m_last = nullptr;
        m_size = 0;
    }

    bool empty()
    {
        return size() == 0;
    }

    bool has(T val)
    {
        return search(val) != nullptr;
    }

    void insert(T val)
    {
        m_last->next() = new node_t(val);
        m_last = m_last->next();
        ++m_size;
    }

    void merge(const LinkedList &llist)
    {
        node_t *dummy{llist.m_head};
        while (dummy)
        {
            insert(dummy->val());
            dummy = dummy->next();
        }
    }

    bool remove(T val)
    {
        if (m_head->val() == val)
        {
            node_t *temp{m_head};
            m_head = m_head->next();
            if (!m_head)
            {
                m_last = nullptr;
            }
            delete temp;

            return true;
        }

        node_t *dummy{m_head};
        while (dummy->next())
        {
            node_t *temp{dummy->next()};
            if (temp->val() == val)
            {
                dummy->next() = temp->next();
                temp->next() = nullptr;
                delete temp;
                return true;
            }
            dummy = dummy->next();
        }

        return false;
    }

    node_t *search(T val)
    {
        node_t *dummy{m_head};
        while (dummy)
        {
            if (dummy->val() == val)
            {
                return dummy;
            }
            dummy = dummy->next();
        }
        return nullptr;
    }

    void shift()
    {
        if (empty())
        {
            return;
        }

        if (size() == 1)
        {
            m_last = nullptr;
        }

        node_t *temp{m_head};
        m_head = m_head->next();
        if (!m_head)
        {
            m_last = nullptr;
        }
        delete temp;
    }

    int size() { return m_size; }
};

#ifndef GENERICPROGRAMMINGASSIGNMENT1_LIST_HPP
#define GENERICPROGRAMMINGASSIGNMENT1_LIST_HPP

#include <string>


namespace DM852{
    /*
     * List header declared as required
     */
    class List {
    public:
        /*
         * Node header declared as required
         */
        class Node {
        public:
            std::string data;
            Node *prev;
            Node *next;
            friend class List;
            Node(std::string data, Node *prev, Node *next);
            ~Node();
        };
        int size() const;
        bool empty() const;
        void push_back(const std::string &elem);
        Node *insert(Node *node, const std::string &elem);
        void clear();
        void pop_back();
        void erase(Node *node);
        std::string &front();
        const std::string &front() const;
        std::string &back();
        const std::string &back() const;
        Node *begin();
        const Node *begin() const;
        Node *end();
        const Node *end() const;
        List();
        ~List();
        bool operator==(const List& other);
        List(const List &other);
        List& operator=(const List &other);
    private:
        int length;
        Node *head;
        Node *last;
    };
}
#endif //GENERICPROGRAMMINGASSIGNMENT1_LIST_HPP

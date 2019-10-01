//Noah Krill

#ifndef CHARLIST//.//HPP//defining the hpp file
#define CHARLIST
class CharList
{
    private:
            struct Node//defining a structure for the Node
            {
                char value;
                Node* next;
            };
            Node* head;
    public:
    CharList()//defining a constructor and setting head = null
    {
        head=nullptr;
    }
    virtual ~CharList();
    void displayList() const;//declaring functions for later use
    bool appendNode(char a);
    bool insertNode(char a);
    bool deleteNode(char a);
};
#endif // CHARLIST

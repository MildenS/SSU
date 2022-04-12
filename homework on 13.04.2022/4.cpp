//4 задание (дополнение к List)
#include <iostream>

using namespace std;

template <typename T>
class List
{
    struct Node
    {
        T inf;
        Node* next;
        Node(T x, Node* ref = nullptr) : inf(x), next(ref) {}
    } *first = nullptr, * last = nullptr;
private:
    int size;
public:
    List();
    void add(T x)
    {
        Node* item = new Node(x);
        if (last != nullptr)
            last->next = item;
        last = item;
        if (first == nullptr)
            first = last;
        size++;
    }
    void print()
    {
        for (Node* tmp = first; tmp != nullptr; tmp = tmp->next)
        {
            cout << tmp->inf << " ";
        }
        cout << '\n';
    }

    void doubleX(T x)
    {
        for (Node* tmp = first; tmp != nullptr; tmp = tmp->next)
        {
            if (tmp->inf == x)
            {
                Node* newItem = new Node(x, tmp->next);
                tmp->next = newItem;
                if (tmp == last)
                    last = tmp->next;
                tmp = tmp->next;
                size++;
            }
        }

    }
    //функция для 4 задания
    List deleteAfter(T a);
};

int main() {
    List<int> lst;
    lst.add(4);
    lst.add(5);
    lst.add(0);
    //lst.print();
    lst.add(5);
    lst.add(7);
    lst.add(0);
    lst.add(10);
    lst.print();
    lst = lst.deleteAfter(0);
    lst.print();
    return 0;
}

template<typename T>
List<T>::List()
{
    size = 0;
}

template<typename T>
List<T> List<T>::deleteAfter(T a)
{
    List<T> ans = *this;
    Node* temp = ans.first;
    while (temp!=nullptr){
        if (temp->inf == a) {
            Node* deleted = temp->next;
            temp->next = deleted->next;
            delete deleted;
        }
        temp = temp->next;
    }
    return ans;
}

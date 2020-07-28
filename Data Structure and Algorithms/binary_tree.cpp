#include <iostream>
using namespace std;

class binary_tree
{
    private:
    struct Node
    {
        int data;
        Node * left;
        Node * right;
        Node(Node * l,int d,Node * r):left(l),data(d),right(r){}
        ~Node()
        {
            if(right)
                delete right;
            if(left)
                delete left;
        }
    };
    Node * root;
    public:
    void add(int d)
    {
        Node * temp_node =root;
        cout<<"start add"<<endl;
        while (temp_node)
        {
            if(d > temp_node->data)
            {
                cout<<"go to right "<<temp_node->data<<endl;
                temp_node = temp_node->right;
            }
            else if(d < temp_node->data)
            {
                cout<<"go to left "<<temp_node->data<<endl;
                temp_node = temp_node->left;
            }    
        }
        cout<<"insert now "<<d<<endl;
        temp_node = new Node(nullptr,d,nullptr);
    }
    bool search(int d)
    {
        Node * temp_node =root;
        cout<<"search started"<<endl;
        if(temp_node)
        {
            while (temp_node)
            {
                if(d > temp_node->data)
                {
                    temp_node = temp_node->right;
                    cout<<"right"<<endl;
                }
                else if(d < temp_node->data)
                {
                    temp_node = temp_node->left;
                    cout<<"left"<<endl;
                }
                else if(d == temp_node->data)
                {
                    cout<<"equal"<<endl;
                    return true;
                }
            }
            cout<<"end search"<<endl;
            return false;
        }
        else
        {
           return false;
        }
    }
    binary_tree(int d)
    {
        root=new Node(nullptr,d,nullptr);
    }
    ~binary_tree()
    {
        delete root;        
    }
};
int main()
{
    binary_tree tree(2);
    tree.add(10);
    tree.add(1);
    tree.add(20);
    tree.add(0);

    std::cout<<tree.search(0)<<std::endl;
    std::cout<<tree.search(9)<<std::endl;
    tree.add(11);
    std::cout<<tree.search(11)<<std::endl;
    return 0;
}
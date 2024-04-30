#include "LinkedList.hpp"
#include "Node.hpp"


int main(void)
{
    int jan = 10;
    int ra = 20;
    LinkedList head;
    head.append(&jan);
    head.append(&ra);

    if (head.head == NULL)
        std::cout << "here" << std::endl;
    Node* temp = head.head; 
    while (temp)
    {
        std::cout << *(int*)(temp->content) << std::endl;
        temp = temp->next;
    }
    // std::cout << *(int *)(head.head->content) << *(int *)(head.head->next->content) << std::endl;
    // std::cout << *(int *)(head.head->content) << *(int *)(head.head->next->content) << std::endl;
    return 0;
}
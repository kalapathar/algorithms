#include "LinkedList.h"


LinkedList::LinkedList(){
	head=new Item;
	head->next=NULL;
	length=0;
}


void LinkedList:: insertItem(Item* newItem){
	
	if(!head->next){
		head->next=newItem;
		length++;
		return;
	}
	Item* previous=head;
	Item* later=head;
	while (later){
		previous=later;
		later=previous->next;
	}
	previous->next=newItem;
	newItem->next=NULL;
	length++;
}

/*

void LinkedList::printList()
{
    if (length == 0)
    {
        cout << "\n{ }\n";
        return;
    }
    Item * p = head;
    Item * q = head;
    cout << "\n{ ";
    while (q)
    {
        p = q;
        if (p != head)
        {
            cout << p -> key;
            if (p -> next) cout << ", ";
            else cout << " ";
        }
        q = p -> next;
    }
    cout << "}\n";
}
*/


#include <iostream> 
using namespace std; 
struct Node {
	int data; 
	Node *next; 
	Node()
	{
		data = 0; 
		next = NULL; 
	}
   Node(int data)
   {
   	this->data = data; 
   	next = NULL;
   }
}; 

class LinkedList{
private: 
	Node *header; 
	Node *tail; 
	int size;  //size == no of nodes in the list. 
public: 
	LinkedList()
	{
		header = NULL; 
		tail = NULL; 
		size = 0; 
	}
	int getSize(); 
	void insertToTail(int data);
	void insertToHead(int data); 
	void insertAtPos(int pos, int data);
	void deleteHead();  
	void deleteTail(); 
	void deleteAtPos(int pos); 
	void printList();
	void insertAfter(int toInsert, int afterWhat); 
	int searchFor(int item);
	~LinkedList(){
    	Node *next; 
    	while (header != NULL)
    	{
    		next = header -> next; //points to node#2. 
    		delete header; //delete node#1. 
    		header = next; //move header to node#1
    	}
    } 
}; 
 int LinkedList::searchFor(int item)
{
 	   Node *ptrItem = new Node(item); 
    bool value_search = false; 
    Node *temp = header; 
    if (header == NULL){
    	return NULL; 
    }
    else 
    {
    while (value_search == false)
       	{
           if (temp -> value ==  ptrItem -> value){
           	value_search == true;  //reach the position where the value is.
           	cout << "Found!\n"; 
           	return ptrItem;  
           }
           else{
           	temp = temp-> next; 
           }
           if (temp -> next == NULL){ 
           	value_search == false; 
           	break;}
       	}

       	if (value_search == false)
       	{
       		cout << "Not Found!\n"; 
       		return NULL; 
       	}
       
    }

}
void LinkedList::insertAfter(int toInsert, int afterWhat)
{ 
	   Node *ptrItem = new Node(toInsert); 
       bool value_search = false; 
      int temp = searchFor(afterWhat); 

       if (header == NULL || temp == NULL)
          {
          	return; 
          }	
       else if (afterWhat == tail -> value)
         {
       	   insertAtTail(toInsert);
         } 
       else
       {
       	while true 
       	{
       		if (temp == afterWhat)
          {
       		 ptrItem-> next = temp -> next; 
       		 (temp -> next) -> prev = ptrItem; 
        	 temp -> next = ptrItem; 
         	 ptrItem -> prev = temp; 
         	 true; 		
          }
          else 
          {
          	temp = temp -> next;
          }
       	}
         
       	
       }
}
  int LinkedList::getSize()  //to find length of the list. 
	{
		return size; 
	}

 void LinkedList::insertToHead(int data){ //add data to the head of the list.  
		Node *n = new Node(data); 
		if (header == NULL)
		{
			header = n; 
			tail = n; 
		}
		else
		{
			Node *temp = header;  //basically add header to new value without losing sight of where it is. 
			header = n; 
			n -> next = temp; 
		}
		size++; 
	}
 void LinkedList::insertToTail(int data){  //insert value to the tail of the list. 
     Node *n = new Node (data); 
     if (header == NULL) //thelist is previously empty.
     {
     	header = n; 
     	tail = n; 
     }
     else if (header != NULL)
     {
     	tail->next = n; 
     	tail = n; 
     }
     size++; 
	}

  void LinkedList::insertAtPos(int pos, int data){
		if (pos > size+1 || pos < 1)
		{
			return;  //trys to add after an empty position. 
		}
		else if (pos == 1)
		{
			insertToHead(data); 
		}
		else if (pos == size + 1)
		{
			insertToTail(data); 
		}
		else if (header != NULL)
		{
			Node *n = new Node(data); 
			Node *prev; 
			Node *cur = header;  
			for (int i = 1; i < pos; i++){ //move to desired pos. 
               prev = cur;
               cur = cur -> next;  
			}
			prev -> next = n; 
			n -> next = cur; 
			size++;
		}
	}

	void LinkedList::deleteHead(){
		if (header != NULL) 
		{
           Node *temp = header; 
           header = header -> next; 
           delete temp; 
           size--; 
		}
	}

	void LinkedList::deleteTail(){
		if (header -> next == NULL)
		{
			deleteHead(); 
		}
		else if (header != NULL)
		{
			Node *cur = header; 
			Node *prev = cur; 
			while (cur ->next != NULL)
			{
				prev = cur; 
				cur = cur -> next; //points to the next node in the list. 
			}
			tail = prev; 
			prev -> next = NULL; 
			delete cur;
			size--  ;  


		}
	} 

 void LinkedList::deleteAtPos(int pos){
 	if (pos > size || pos < 1){
 		return; 
 	}
 	else if (pos == 1)
 	{
 		deleteHead(); 
 	}
 	else if (pos == size)
 	{
 		deleteTail(); 
 	}
 	else {
 		Node *prev;
 		Node *cur = header; 
 		for (int i = 1; i < pos; i++){
 			prev = cur; 
 			cur = cur -> next; 
 		}
 		prev -> next = cur->next; //store address of node at pos+1. 
 		delete cur; 
 		size--; 
 	}
 }

 void LinkedList::printList(){
 	Node *temp = header; 
 	while (temp != NULL){
 		cout << temp -> data << " "; 
 		temp = temp -> next; 
 	}
 	cout << endl; 
 }



int main()
{
   LinkedList list; 
   list.insertToHead(1); 
   list.insertToTail(2); 
   list.insertToTail(3); 
   list.insertToTail(4);
   list.insertToTail(5);
   list.insertAfter(6, 3);
   cout << "List after insertion: "; 
   list.printList(); 
   list.insertToHead(0);
   cout << "List after insertion at head: "; 
   list.printList(); 
   list.insertToTail(6); 
   cout << "List after insertion at tail: "; 
   list.printList(); 
   list.insertAtPos(2, 2); 
   cout << "List after insertion at pos = 2: "; 
   list.printList();
   list.deleteTail(); 
   cout << "List after deleting tail: "; 
   list.printList();
   list.deleteHead();
   cout << "List after deleting head: ";  
   list.printList();
   list.deleteAtPos(3); 
   cout << "List after deleting at pos = 3: "; 
   list.printList();
  return 0; 
} 
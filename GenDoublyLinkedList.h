#pragma once
#include "DoublyNode.h"
#include <iostream>

template <class any_type>

	class GenDoublyLinkedList
	{
	public:
		GenDoublyLinkedList()
		{
			head_sentinel = nullptr;
			tail_sentinel = nullptr;
			size = 0;

			DoublyNode <any_type>* node = new DoublyNode <any_type> ();
			node->previous_node = head_sentinel;
			node->next_node = tail_sentinel;
			head_sentinel = node;
			tail_sentinel = node;
		};
		GenDoublyLinkedList(any_type d)
		{
			head_sentinel = nullptr;
			tail_sentinel = nullptr;
			size = 0;
			
			DoublyNode <any_type>* node = new DoublyNode <any_type> (d);
			node->previous_node = head_sentinel;
			node->next_node = tail_sentinel;
			head_sentinel = node;
			tail_sentinel = node;
			size++;
		};

		GenDoublyLinkedList(any_type d, any_type d2)
		{
			head_sentinel = nullptr;
			tail_sentinel = nullptr;
			size = 0;
			
			DoublyNode <any_type>* node = new DoublyNode <any_type> (d, d2);
			node->previous_node = head_sentinel;
			node->next_node = tail_sentinel;
			head_sentinel = node;
			tail_sentinel = node;
			size++;
		};

		GenDoublyLinkedList(any_type d, any_type d2, any_type d3)
		{
			head_sentinel = nullptr;
			tail_sentinel = nullptr;
			size = 0;
			
			DoublyNode <any_type>* node = new DoublyNode <any_type> (d, d2, d3);
			node->previous_node = head_sentinel;
			node->next_node = tail_sentinel;
			head_sentinel = node;
			tail_sentinel = node;
			size++;
		};
		~GenDoublyLinkedList()
		{
			DoublyNode <any_type>* probe = head_sentinel;

			while(probe->next_node != NULL)
			{
				probe = probe->next_node;
				probe->previous_node->~DoublyNode();
			}

			probe->~DoublyNode();

			head_sentinel = NULL;
			tail_sentinel = NULL;
			delete head_sentinel;
			delete tail_sentinel;
			//cout << "\nLinked List Deleted\n";
		};

	public:
		DoublyNode<any_type>* head_sentinel;
		DoublyNode<any_type>* tail_sentinel;
		int size;

	public:

		//ADD DE LINKED LIST MEMBER METHODS
		void insertFront(any_type d)
		{
			DoublyNode <any_type>* node = new DoublyNode <any_type> (d);
			if(size == 0) //if empty
			{
				tail_sentinel = node; //tail will be pointing to the same thing
			}
			else //(not empty)
			{
				node -> next_node = head_sentinel; //this node is the front (assuming there is already a head) IS THIS RIGHT? SHOULDNT IT BE NODE-NEXT-PREV = NEXT?
				head_sentinel -> previous_node = node; //this node is also the prev (DO I NEED TO SET) AND THIS BENODE-PREV = NODE
			}

			head_sentinel = node;//these happen no matter what (remember back is inside the node class not the list class, back = node from the beginning of this funtion which is how things will access)
			size++;
		};

		void insertFront(any_type d, any_type d2)
		{
			DoublyNode <any_type>* node = new DoublyNode <any_type> (d, d2);
			if(size == 0) //if empty
			{
				tail_sentinel = node; //tail will be pointing to the same thing
			}
			else //(not empty)
			{
				node -> next_node = head_sentinel; //this node is the front (assuming there is already a head) IS THIS RIGHT? SHOULDNT IT BE NODE-NEXT-PREV = NEXT?
				head_sentinel -> previous_node = node; //this node is also the prev (DO I NEED TO SET) AND THIS BENODE-PREV = NODE
			}

			head_sentinel = node;//these happen no matter what (remember back is inside the node class not the list class, back = node from the beginning of this funtion which is how things will access)
			size++;
		};

		any_type front()
		{
			DoublyNode <any_type>* probe = head_sentinel;
			return probe->data;
		};

		any_type front2()
		{
			DoublyNode <any_type>* probe = head_sentinel;
			return probe->data2;
		};

		any_type front3()
		{
			DoublyNode <any_type>* probe = head_sentinel;
			return probe->data3;
		};

		any_type removeFront()
		{	
			any_type temp = head_sentinel -> data;
			DoublyNode <any_type>* temp_probe = head_sentinel;

			if(head_sentinel ->next_node == NULL) //only one element in list
			{
				tail_sentinel = NULL;
			}

			else
			{
				head_sentinel->next_node->previous_node = NULL; //nulls out connection to the head node
			}

			head_sentinel = head_sentinel -> next_node; //makes new connection
			

			temp_probe->next_node = NULL; //nulls out front nodes next value so it can disconnect from list
			delete temp_probe;
			size--;
			return temp;
		};

		/*void insertBack(any_type d)
		{
			DoublyNode <any_type>* node = new DoublyNode <any_type> (d);

			if(size == 0) //if empty is empty function?
			{
				head_sentinel = node; //both will be pointing to the same thing
			}

			else //not empty
			{
				node-> previous_node= tail_sentinel; //OLD
				//node -> next = tail;
				//tail -> previous = node;
				tail_sentinel -> next_node = node; //Old
				
			}

			tail_sentinel = node; //these happen no matter what (remember back is inside the node class not the list class, back = node from the beginning of this funtion which is how things will access
			size++;
		};*/

		void insertBack(any_type d, any_type d2)
		{
			DoublyNode <any_type>* node = new DoublyNode <any_type> (d, d2);

			if(size == 0) //if empty is empty function?
			{
				head_sentinel = node; //both will be pointing to the same thing
			}

			else //not empty
			{
				node-> previous_node= tail_sentinel; //OLD
				//node -> next = tail;
				//tail -> previous = node;
				tail_sentinel -> next_node = node; //Old
				
			}

			tail_sentinel = node; //these happen no matter what (remember back is inside the node class not the list class, back = node from the beginning of this funtion which is how things will access
			size++;
		};

		void insertBack(any_type d, any_type d2, any_type d3)
		{
			DoublyNode <any_type>* node = new DoublyNode <any_type> (d, d2, d3);

			if(size == 0) //if empty is empty function?
			{
				head_sentinel = node; //both will be pointing to the same thing
			}

			else //not empty
			{
				node-> previous_node= tail_sentinel; //OLD
				//node -> next = tail;
				//tail -> previous = node;
				tail_sentinel -> next_node = node; //Old
				
			}

			tail_sentinel = node; //these happen no matter what (remember back is inside the node class not the list class, back = node from the beginning of this funtion which is how things will access
			size++;
		};


		any_type rear()
		{
			DoublyNode <any_type>* probe = tail_sentinel;
			return probe->data;
		}

		any_type removeBack()
		{
			any_type temp = tail_sentinel->data;
			DoublyNode <any_type>* temp_probe = tail_sentinel;

			if(tail_sentinel ->previous_node == NULL) //only one element in list
			{
				head_sentinel = NULL;
			}

			else
			{
				tail_sentinel->previous_node->next_node = NULL;
			}

			tail_sentinel = tail_sentinel->previous_node;//makes new connection 


			temp_probe->next_node = nullptr;
			delete temp_probe;
			size--;
			return temp;
		};

		any_type findd2data(int target)
		{
			any_type temp = 0;
			DoublyNode <any_type>* temp_probe = head_sentinel;
			while(temp_probe->data2!=target)
			{
				temp_probe = temp_probe->next_node;
			}

			if(temp_probe == NULL)
				{
					cout << "\nItem Does Not Exist in List!\n";
					return -1;
				}

			return temp_probe->data3;
		}

		any_type remove(any_type key)
		{
			any_type temp = 0;
			DoublyNode <any_type>* temp_probe = head_sentinel;

			cout << "\nSearching For " << key << "\n";
			while(temp_probe->data!=key)
			{
				//cout << "\nprobe data is: \n" << temp_probe->data << "\n";
				temp_probe = temp_probe->next_node;	
				
				if(temp_probe == NULL)
				{
					cout << "\nItem Does Not Exist in List!\n";
					return -1;
				}
			}
			cout << "\nFound: " << key << "\n";

			if(temp_probe == head_sentinel)
			{
				//cout << "\nItem Being Removed is Head!\n";
				head_sentinel->next_node->previous_node = NULL; //prepares consecutive node to become the head
				head_sentinel = head_sentinel ->next_node; //makes the head point to the consecutive node
			}
			else if(temp_probe == tail_sentinel)
			{
				//cout << "\nItem Being Removed is Tail!\n";
				tail_sentinel->previous_node->next_node = NULL; //prepares prior node to become the tail
				tail_sentinel = tail_sentinel->previous_node;//makes the tail point to the prior node 
			}

			else
			{
				//cout << "\nItem Being Removed is a Cental Node!\n";
				temp_probe->previous_node->next_node = temp_probe->next_node; //previous-next refers to the location of the previous node and next is the consecutive node
				temp_probe->next_node->previous_node = temp_probe->previous_node; //next-previous refers to the loacation of the consecutive node and previous is the prior node
			}

			temp = temp_probe->data;

			cout << "\nDestroying...\n";
			temp_probe->~DoublyNode();
			size --;

			return temp;
		};

		void printList() //only prints 1 data member
		{
			cout << "\nPrinting From Start of List\n";
			DoublyNode <any_type>* temp_probe = head_sentinel;
			while (temp_probe)
			{
				cout << temp_probe->data << "\n";
				temp_probe = temp_probe->next_node;
			}
		};

		bool isEmpty()
		{
			if(size > 0)
			{
				return false;
			}

			else
			{
				return true;
			}	
		};

		unsigned int getSize()
		{
			return size;
		};

		int Sum3() // sum of data member 3
		{
			int sum = 0;
			DoublyNode <any_type>* probe = head_sentinel;

			while(probe != NULL)
			{
				sum += probe->data3;
				probe = probe->next_node;
			}

			return sum;
		}

		void AddToAll() // adds to data member 3
		{
			int one_minute = 1;

			DoublyNode <any_type>* probe = head_sentinel; //same thing as current

			while(probe != NULL)
			{
				probe->data3 = probe->data3 + one_minute;
				probe = probe->next_node;
			}
		}

		void SubAll()
		{
			int one_minute = 1;

			DoublyNode <any_type>* probe = head_sentinel; //same thing as current

			while(probe != NULL)
			{
				probe->data2 = probe->data2 + one_minute;
				probe = probe->next_node;
			}
		}

		bool d2NotEmptyy()
		{
			DoublyNode <any_type>* probe = tail_sentinel;

			if(probe->data2 > 0)
			{
				return true;
			}

			return false;
		}

		bool d2Emptyy()
		{
			DoublyNode <any_type>* probe = head_sentinel;

			if(probe->data2 <= 0)
			{
				return true;
			}

			else
			{
				return false;
			}
		}

		void Subtract(any_type count, any_type time)
		{
			DoublyNode <any_type>* probe = head_sentinel;
			int i = count;

			while(i > 0)
			{

				cout << "counti: " << i << "\n";
				cout << "\ndata2 " << probe->data2 << "\n";
				probe = probe->next_node;

				if(probe->data <= time)
				{
					probe->data2 --;
					i--;;
				}

				if (i == 0)
				{
					break;
				}
			}
		}



	};
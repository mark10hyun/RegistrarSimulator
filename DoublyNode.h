#pragma once

using namespace std;

template <class any_type>

	class DoublyNode
	{

	public:
		any_type data;
		any_type data2;
		any_type data3;
		DoublyNode* next_node;
		DoublyNode* previous_node;

	public:
		DoublyNode()
		{
			data = 0;
			data2 = 0;
			data3 = 0;
			next_node = nullptr;
			previous_node = nullptr;
		};

		DoublyNode(any_type d)
		{
			data = d;
			data2 = 0;
			data3 = 0;
			next_node = nullptr;
			previous_node = nullptr;
		};

		DoublyNode(any_type d, any_type d2)
		{
			data = d; //et
			data2 = d2; //mn
			data3 = 0; // it
			next_node = nullptr;
			previous_node = nullptr;
		};

		DoublyNode(any_type d, any_type d2, any_type d3)
		{
			data = d; //et
			data2 = d2; //mn
			data3 = d3; // it
			next_node = nullptr;
			previous_node = nullptr;
		};

		~DoublyNode()
		{
			next_node = nullptr;
			previous_node = nullptr;
			delete next_node;
			delete previous_node;
		};
	};


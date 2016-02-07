/*
	beaj2031
	merj2607
	
	Class Liste used as a dynamic and generic 1D table (list)
*/
#pragma once

class Liste {
	private:
		ListeItem *_first;
		ListeItem *_last;
		
		int _len;
	
	public:
		Liste();
		~Liste();
		
		int length();
		
		ListeItem* begin();
		ListeItem* end();
		
		ListeItem* getItem(int index);
		
		void add(void *obj, int index);
		void remove(void *obj);
		
		void pushLast(void *obj);
		void pushFront(void *obj);
		void removeLast();
		void removeFront();
};

class ListeItem {
	friend class Liste
	private:
		ListeItem *_back;
		ListeItem *_front;
		
		void *_obj;
	public:
		ListeItem();
		~ListeItem();
		void* getOjb();
};
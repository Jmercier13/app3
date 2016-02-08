/*
	beaj2031
	merj2607
	
	Class Liste used as a dynamic and generic 1D table (list)
*/
#pragma once

#include <cstddef>
#include <iostream>
#include <iomanip>
#include <sstream>

#include "plat_choisi.h"
#include "utilities.h"

using namespace std;

class ListeItem {
	friend class Liste;
	private:
	// public:
		ListeItem *_back;
		ListeItem *_front;
		
		void *_obj;
	public:
		ListeItem();
		ListeItem(ListeItem *back, ListeItem *front, void *obj);
		~ListeItem();
		void* getObj();
};

class Liste {
	private:
	// public:
		ListeItem *_first;
		ListeItem *_last;
		
		int _len;
		
		ListeItem* _getItem(int index);
	
	public:
		Liste();
		~Liste();
		
		int length();
		
		ListeItem* begin();
		ListeItem* end();
		
		PlatChoisi* getObj(int index);
		
		void add(void *obj, int index=-1);
		void pushLast(void *obj);
		void pushFirst(void *obj);
		
		void empty();
		
		void remove(int index=-1);
		void removeLast();
		void removeFirst();
		
		string toString();
};
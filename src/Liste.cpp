#include "../headers/liste.h"

Liste::Liste(){
	_first = NULL;
	_last = NULL;
	_len = 0;
}

Liste::~Liste(){
	//TODO
}

ListeItem* Liste::begin(){
	return _first;
}

ListeItem* Liste::end(){
	return _last;
}

ListeItem* Liste::_getItem(int index){
	if(index < 0 || index >= _len){
		//TODO TROW ERR
	}
	
	ListeItem *l = _first;
	
	for(int i=0; i<=index; i++){
		l = l->front;
	}
	
	return l;
}

PlatAuMenu* Liste::_getItem(int index){	
	return (PlatAuMenu *) _getItem(index);
}

void Liste::add(void *obj, int index){
	if(index < 0 || index > _len){
		//TODO TROW ERR
	}
	
	if(index == 0{
		//if its the first item
		pushFirst(obj);
	} else if(index == _len) {
		//if its the last item
		pushLast(obj);		
	} else {
		//if its not first or last
		ListeItem *f;
		f = _getItem(index);
		ListeItem *b;
		b = f->_back;
		
		ListeItem *newL = new ListeItem(b, f, obj);
		if(b != NULL){
			b->_front = newL;
		}
		if(l != NULL){
			f->_back = newL;
		}
		
		_len++;
	}
}

void Liste::remove(int index){
	if(index < 0 || index >= _len){
		//TODO TROW ERR
	}
	
	if(index == 0){
		removeFirst();
	} else if(index == _len) {
		removeLast();
	} else {
		ListeItem *l;
		l = _getItem(index);
		
		ListeItem *b;
		b = l->_back;
		
		ListeItem *f;
		f = l->_front;
		
		b->_front = f;
		f->_back = b;
		
		delete l;
	}
}

void Liste::pushLast(void *obj){
	ListeItem *newL;
	newL = new ListeItem(_last, NULL, obj);
	_last->_front = newL;
	_last = newL;
	
	_len++;
}

void Liste::pushFirst(void *obj){
	if(_first == NULL){
		//if there is no first
		_first = new ListeItem(NULL, NULL, obj);
		_last = new ListeItem(_first, NULL, obj);
		_first->_front = _last;
	} else {
		//if there is a first
		ListeItem newL = new ListeItem(NULL, _first, obj);
		_first->_back = newL;
		_first = newL;
	}
	
	_len++;
}

void Liste::removeLast(){
	if(_len == 0){
		return;
	} else if(_len == 1) {
		delete _first;
		delete _last;
		
		_first = NULL;
		_last = NULL;
	} else {
		ListeItem *b;
		b = _last->_back;
		
		b->_front = NULL;
		delete _last;
		_last = b;
	}
	
	len--;
}

void Liste::removeFirst(){
	if(_len == 0){
		return;
	} else if(_len == 1) {
		delete _first;
		delete _last;
		
		_first = NULL;
		_last = NULL;	
	} else {
		ListeItem *f;
		f = _first->_front;
		
		f->_back = NULL;
		delete _first;
		_first = f;		
	}
	
	_len--;
}

ListeItem::ListeItem(ListeItem back, ListeItem front, void* obj){
	_back = back;
	_front = front;
	_obj = obj;
}

ListeItem::~ListeItem(){
	delete _obj;
}

void* getObj(){
	return _obj;
}
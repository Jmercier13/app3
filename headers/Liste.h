/*
	beaj2031
	merj2607
	
	Class Liste used as a dynamic and generic 1D table (list)
*/
#pragma once

template <class T>
class Liste {
	private :
			
	
	public :
		Liste();
		~Liste();
		
		void begin();
		void end();
		
		void add();
		void remove();
		
		void push();
		T pop();
};
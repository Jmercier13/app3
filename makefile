h = headers/
s = src/

# menufact01 : menufact01.o menu.o plats.o test_menu_fact.o facture.o
# 	g++ -o menufact01.exe menufact01.o menu.o plats.o test_menu_fact.o facture.o

# menufact01.o : $(h)test_menu_fact.h $(h)menu.h $(h)facture.h
# 	g++ $(s)menufact01.cpp -g -c
	
# menu.o : $(h)menu.h $(h)plats.h
# 	g++ $(s)menu.cpp -g -c

# plats.o : $(h)plats.h
# 	g++ $(s)plats.cpp -g -c

# facture.o : $(h)facture.h
# 	g++ $(s)facture.cpp -g -c

# test_menu_fact.o : $(h)test_menu_fact.h $(h)menu.h $(h)facture.h
# 	g++ $(s)test_menu_fact.cpp -g -c

#test_liste

all : test clean

test : test_liste.o plat_choisi.o liste.o utilities.o
	g++ -o test.exe test_liste.o liste.o plat_choisi.o utilities.o

liste.o : $(h)liste.h $(h)plat_choisi.h $(h)utilities.h
	g++ $(s)liste.cpp -g -c

plat_choisi.o : $(h)plat_choisi.h
	g++ $(s)plat_choisi.cpp -g -c

utilities.o : $(h)utilities.h
	g++ $(s)utilities.cpp -g -c

test_liste.o : $(h)liste.h $(h)plat_choisi.h $(h)utilities.h
	g++ $(s)test_liste.cpp -g -c

clean:
	rm -f *.o
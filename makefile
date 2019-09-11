Final_Project: main.o army.o country.o flag.o food.o gold.o h2o.o item.o menu.o mountain.o space.o userValidation.o water.o wood.o
	g++ -std=c++11 main.o army.o country.o flag.o food.o gold.o h2o.o item.o menu.o mountain.o space.o userValidation.o water.o wood.o -o Final_Project
main.o: main.cpp
	g++ -c main.cpp
army.o: army.cpp army.hpp
	g++ -c -std=c++11 army.cpp
country.o: country.cpp country.hpp
	g++ -c -std=c++11 country.cpp
flag.o: flag.cpp flag.hpp
	g++ -c -std=c++11 flag.cpp
food.o: food.cpp food.hpp
	g++ -c -std=c++11 food.cpp
gold.o: gold.cpp gold.hpp
	g++ -c -std=c++11 gold.cpp
h2o.o: h2o.cpp h2o.hpp
	g++ -c -std=c++11 h2o.cpp
item.o: item.cpp item.hpp
	g++ -c -std=c++11 item.cpp
menu.o: menu.cpp menu.hpp
	g++ -c -std=c++11 menu.cpp
mountain.o: mountain.cpp mountain.hpp
	g++ -c -std=c++11 mountain.cpp
space.o: space.cpp space.hpp
	g++ -c -std=c++11 space.cpp
userValidation.o: userValidation.cpp userValidation.hpp
	g++ -c -std=c++11 userValidation.cpp
water.o: water.cpp water.hpp
	g++ -c -std=c++11 water.cpp
wood.o: wood.cpp wood.hpp
	g++ -c -std=c++11 wood.cpp
clean: 
	rm *.o Final_Project
	

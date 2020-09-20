CLIENT = TestClient
ADT = List
SRC = .cpp
OBJ = .o
HEADER = .h
COMPILE = g++ -Wall -std=c++11 -c
LINK = g++ -std=c++11 -o
MEMCHECK = valgrind --leak-check=full

$(CLIENT) : $(CLIENT)$(OBJ) $(ADT)$(OBJ)
	$(LINK) $(CLIENT) $(CLIENT)$(OBJ) $(ADT)$(OBJ)

$(CLIENT)$(OBJ) : $(CLIENT)$(SRC) $(ADT)$(HEADER)
	$(COMPILE) $(CLIENT)$(SRC)

$(ADT)$(OBJ) : $(ADT)$(SRC) $(ADT)$(HEADER)
	$(COMPILE) $(ADT)$(SRC)

clean : 
	rm -f $(CLIENT) *.o

check : $(CLIENT)
	$(MEMCHECK) ./$(CLIENT)

CXX = g++

ROOT = ..
SRC_DIR = $(ROOT)/src/ 
INC_DIR = $(ROOT)/inc 
OBJ_DIR = $(ROOT)/obj/ 
BIN_DIR = $(ROOT)/bin 

INC = -I$(INC_DIR)
CXX_FLAGS = -c $(INC) -g

DEPENDENCIES =

$(OBJ_DIR)BC.o: $(SRC_DIR)BC.cpp
	$(CXX) $(CXX_FLAGS) $(SRC_DIR)BC.cpp -o ../obj/BC.o
DEPENDENCIES += $(OBJ_DIR)BC.o 

$(OBJ_DIR)Domain.o: $(SRC_DIR)Domain.cpp
	$(CXX) $(CXX_FLAGS) $(SRC_DIR)Domain.cpp -o ../obj/Domain.o
DEPENDENCIES += $(OBJ_DIR)Domain.o 

$(OBJ_DIR)GenerationManager.o: $(SRC_DIR)GenerationManager.cpp
	$(CXX) $(CXX_FLAGS) -fopenmp $(SRC_DIR)GenerationManager.cpp -o ../obj/GenerationManager.o
DEPENDENCIES += $(OBJ_DIR)GenerationManager.o 

$(OBJ_DIR)Generator.o: $(SRC_DIR)Generator.cpp
	$(CXX) $(CXX_FLAGS) $(SRC_DIR)Generator.cpp -o ../obj/Generator.o
DEPENDENCIES += $(OBJ_DIR)Generator.o 

$(OBJ_DIR)Nucleator.o: $(SRC_DIR)Nucleator.cpp
	$(CXX) $(CXX_FLAGS) $(SRC_DIR)Nucleator.cpp -o ../obj/Nucleator.o
DEPENDENCIES += $(OBJ_DIR)Nucleator.o 

$(OBJ_DIR)Rules.o: $(SRC_DIR)Rules.cpp
	$(CXX) $(CXX_FLAGS) $(SRC_DIR)Rules.cpp -o ../obj/Rules.o
DEPENDENCIES += $(OBJ_DIR)Rules.o 

$(OBJ_DIR)postproc.o: $(SRC_DIR)postproc.cpp $(SRC_DIR)BMP/EasyBMP.cpp $(SRC_DIR)BMP/libbmp.cpp
	$(CXX) $(CXX_FLAGS) $(SRC_DIR)postproc.cpp -o ../obj/postproc.o
DEPENDENCIES += $(OBJ_DIR)postproc.o

$(OBJ_DIR)bmp.o: $(SRC_DIR)BMP/EasyBMP.cpp
	$(CXX) $(CXX_FLAGS) -I../inc/BMP $(SRC_DIR)BMP/EasyBMP.cpp -o ../obj/bmp.o
DEPENDENCIES += $(OBJ_DIR)bmp.o

$(OBJ_DIR)random.o: $(SRC_DIR)Random.cpp
	$(CXX) $(CXX_FLAGS) $(SRC_DIR)Random.cpp -o ../obj/random.o
DEPENDENCIES += $(OBJ_DIR)random.o

$(OBJ_DIR)main.o: $(SRC_DIR)main.cpp
	$(CXX) $(CXX_FLAGS) $(SRC_DIR)main.cpp -o ../obj/main.o
DEPENDENCIES += $(OBJ_DIR)main.o 

build: $(DEPENDENCIES)
	$(CXX) -fopenmp ../obj/*.o -o ../bin/mwca

clean:
	rm ../obj/*.o
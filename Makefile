CCOPTION = Wall std=gnu++11 D__USE_MINGW_ANSI_STDIO=1
FLAGS = $(addprefix -,$(CCOPTION))
CC = g++
OBJ = example.o perceptron.o 
SRC_DIR = /mnt/GYAHU/Stuff/FCFM/Semestres/10o_Semestre/Redes_Neuronales/Tareas/T2

output.out: $(OBJ) 
	 $(CC) $(FLAGS) $(OBJ) -o output.out 

example.o: $(SRC_DIR)/example.cpp 
	 $(CC) $(FLAGS) -c $(SRC_DIR)/example.cpp -o example.o 

perceptron.o: $(SRC_DIR)/perceptron.cpp 
	 $(CC) $(FLAGS) -c $(SRC_DIR)/perceptron.cpp -o perceptron.o 


clean: 
	rm $(OBJ_DIR)/*.o
	rm $(BUILD_DIR)/*.out

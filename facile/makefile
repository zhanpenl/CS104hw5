CC = g++
CPPFLAGS = -g -Wall
VALGRIND = valgrind --tool=memcheck --leak-check=yes
BIN_DIR = bin
TARGETS = $(BIN_DIR)/ProgramState.o $(BIN_DIR)/LetStatement.o $(BIN_DIR)/EndStatement.o\
 		  $(BIN_DIR)/PrintStatement.o $(BIN_DIR)/PrintallStatement.o $(BIN_DIR)/AddStatement.o\
  		  $(BIN_DIR)/SubStatement.o $(BIN_DIR)/MultStatement.o $(BIN_DIR)/DivStatement.o\
  		  $(BIN_DIR)/GotoStatement.o $(BIN_DIR)/IfStatement.o $(BIN_DIR)/GosubStatement.o\
  		  $(BIN_DIR)/ReturnStatement.o $(BIN_DIR)/llistint.o $(BIN_DIR)/stackint.o


all: $(TARGETS) $(BIN_DIR)/Facile
	-@echo "--All built--"

$(BIN_DIR)/%.o: %.cpp %.h $(BIN_DIR)/.dirstamp 
	$(CC) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR)/Facile: Facile.cpp $(TARGETS)
	$(CC) $(CPPFLAGS) $^ -o $@

$(BIN_DIR)/.dirstamp:
	-@mkdir -p $(BIN_DIR)
	-@touch $@

.PHONY: clean test

test: $(BIN_DIR)/Facile
	-@$(VALGRIND) $(BIN_DIR)/Facile

clean:
	-@rm -rf $(BIN_DIR)
	-@echo "--- All Clean!---"
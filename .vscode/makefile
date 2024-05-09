# BIBLIOGRAFIA:
#    https://makefiletutorial.com/
#    mingw32-make -C .vscodemake

# Define el origen de los datos
SESION  = 0101
SRC_DIR = ../Parcial_03/Proyecto/

# Crea una lista con los archivos fuente
TGT_DIR   = ../.build
TARGET    = $(TGT_DIR)\Salida.exe
OBJ_DIR   = $(TGT_DIR)\object
SOURCE   := $(wildcard $(SRC_DIR)$(SESION)*.cpp)
OBJECT    = $(subst $(SRC_DIR),$(OBJ_DIR)\,$(SOURCE:.cpp=.o))
CLEAN_AUX = $(subst /,\,$(wildcard $(OBJ_DIR)/*.o))
CLEAN_LST = \
  $(wildcard $(subst \,/,$(TARGET))) \
  $(wildcard $(OBJ_DIR)/$(SESION)*.o)

# Configuracion del compilador de recursos
_WINDRES = --preprocessor=x86_64-w64-mingw32-g++.exe \
	--preprocessor-arg=-E \
	--preprocessor-arg=-xc-header \
	--preprocessor-arg=-DRC_INVOKED \
	--codepage=65001


# Crea ejecutable enlazando archivos objeto
all: $(OBJECT) $(OBJ_DIR)\\Resourse.o
	g++ -g -mwindows $^ -o $(TARGET)
# g++ -g $^ -o $(TARGET)

# Compilar archivo de recursos
$(OBJ_DIR)\\Resourse.o: $(wildcard $(SRC_DIR)$(SESION)*.rc)
	windres $(_WINDRES)  -i $< -o $@

# Crea archivos objeto
$(OBJ_DIR)\\%.o: $(SRC_DIR)%.cpp
	g++ -DUNICODE -g -c $^ -o $@

# Borra archivos auxilares y el archivo fuente
clean: $(subst /,\,$(CLEAN_LST))
	del $^

# Borra archivos auxiliares
cleanAux: 
	del $(CLEAN_AUX)
  
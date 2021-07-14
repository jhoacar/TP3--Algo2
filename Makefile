# Project: TP3
# Makefile creado por Jhoan Carrero

#########################################################
### MACRO DE COMPILACION
# $(1) : Compilador
# $(2) : Archivo .o a generar
# $(3) : Archivo .cpp a compilar
# $(4) : Dependencias
# $(5) : Flags del compilador
define COMPILACION
$(2) : $(3) $(4)
	$(1) -c -o $(2) $(3) $(5)
endef

#########################################################
#########################################################
### MACRO DE TRANSFORMACION ./src(...).cpp -> ./obj(...).o
# $(1) : Archivo .cpp a transformar
define TO_OBJ
$(subst .cpp,.o,$(subst $(SRC),$(OBJ),$(1)))
endef
#########################################################


##########################################################
### CONFIGURACION 
APP 		:= TP3
CPP     	:= g++
VALGRIND	:= valgrind
FLAGS 		:= -ggdb -std=c++11 -Wconversion -O0 -limits -Wall -Werror -pedantic
SRC 		:= src
OBJ 		:= obj
TESTSDIR	:= tests
TESTOBJDIRS	:= tests_obj
NAME_TEST 	:= test_
#Los headers seran aquellos ficheros que si se llegasen a modificar, se compilara de nuevo todo el proyecto para detectar fallas
HEADERS		:= Lista.h Nodo.h Constantes.h Floyd.h Grafo.h Diccionario.h
TEST 		:= no_hay_test_todavia

###########################################################

ifeq ($(OS),Windows_NT) #WINDOWS ...
##########################################################
### SHELL SCRIPT WINDOWS
SEARCH_FILES := dir /s/b
SEARCH_DIRS  := dir $(SRC) /ad /b /s
DELETE_FILES := rmdir /Q /S 
MKDIR 		 := mkdir
##########################################################
else #LINUX ...
##########################################################
### SHELL SCRIPT LINUX
SEARCH_FILES := find $(SRC)/ -type f -iname
SEARCH_DIRS  := find $(SRC)/ -type d
DELETE_FILES := rm -f -r ./
MKDIR 		 := mkdir -p
##########################################################
endif

#########################################################
### EXTRACCION FICHEROS DEL PROYECTO
MAIN 			:= $(shell $(SEARCH_FILES) main.cpp)
ALLTESTS		:= $(shell $(subst $(SRC),$(TESTSDIR),$(SEARCH_FILES)) $(NAME_TEST)*.cpp)
ALLCPPS 		:= $(subst $(ALLTESTS),,$(shell $(SEARCH_FILES) *.cpp))
ALLOBJECTS 		:= $(subst .cpp,.o,$(subst $(SRC),$(OBJ),$(ALLCPPS)))#sustituimos la carpeta SRC por OBJ y la extencion .cpp por .o
ALLOBJECTS_TEST := $(subst $(call TO_OBJ,$(MAIN)),,$(ALLOBJECTS))

SUBDIRS 		:= $(shell $(SEARCH_DIRS))
OBJSUBDIRS		:= $(subst $(SRC),$(OBJ),$(SUBDIRS))#sustituimos la carpeta SRC por OBJ

DIR_HEADERS 	:= $(shell $(SEARCH_FILES) $(HEADERS))
#########################################################


########################################################
### PROCESO DE LINKAR
#Al ejecutar make, arrancara a realizar esta operacion
$(APP): $(OBJSUBDIRS) $(ALLOBJECTS)
	$(CPP) -o $(APP) $(ALLOBJECTS)
#La cual se ejecutara cuando tengo resuelto todos los OBJETOS que son todos los *.o y cree todas las carpetas
########################################################

########################################################
### GENERADOR DE REGLAS PARA CADA .o
$(foreach FICHERO,$(ALLCPPS),$(eval $(call COMPILACION,$(CPP),$(call TO_OBJ,$(FICHERO)),$(FICHERO),$(DIR_HEADERS),$(FLAGS))))
########################################################


########################################################
### CREANDO LOS SUBDIRECTORIOS ./obj t ./test_obj
$(OBJSUBDIRS):
	$(MKDIR) $(OBJSUBDIRS)

$(TESTOBJDIRS):
	$(MKDIR) $(TESTOBJDIRS)

########################################################

########################################################
### ELIMINANDO TODA LA CARPETA ./obj y ./tests_obj
clean:
	$(DELETE_FILES)$(OBJ)
	$(DELETE_FILES)$(TESTOBJDIRS)

########################################################

########################################################
### USO DE LA API VALGRIND PARA EJECUTAR PROYECTO
valgrind:
	$(VALGRIND) ./$(APP)
########################################################

test: $(OBJSUBDIRS) $(ALLOBJECTS_TEST) $(TESTOBJDIRS)
	$(CPP) -c -o $(TESTOBJDIRS)/$(TEST).o $(TESTSDIR)/$(TEST).cpp $(FLAGS)
	$(CPP) -o $(TEST) $(ALLOBJECTS_TEST) $(TESTOBJDIRS)/$(TEST).o


#PHONY es Util para que no sea dependiente y ejecute solo con instruccion. Ejemplo: make info
.PHONY: info
info:
	$(info $(ALLTESTS))

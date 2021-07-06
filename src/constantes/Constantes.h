#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <string>
using std::string;

const string CAZADOR = "CV";

//Convencion usada para este proyecto en los nombre,cardinales,colores,etc... 

//Con las variables enumeradas obtengo una equivalencia (int) en char y string del nombre del objeto que se desea
const size_t MAX_NOMBRES = 12;
const string NOMBRES_STRING[MAX_NOMBRES]=	{"agua","bala","cruz","estaca","escopeta","humano","humano CV","Vanesa","vampiro","Vampirella","Nosferatu","zombi"};
const char NOMBRES_CHAR[MAX_NOMBRES]=	{'a',	'b',	'c',	'e',	'E',		'h',		'H',	'W',		'v',		'V',		'N',	'z'};
enum {AGUA=0,BALA,CRUZ,ESTACA,ESCOPETA,HUMANO,HUMANO_CAZADOR,VANESA,VAMPIRO,VAMPIRELLA,NOSFERATU,ZOMBIE};

//Con las variables enumeradas obtengo una equivalencia (int) en char y string del nombre del mapa que se desea
const size_t MAX_TIPOS_MAPA = 6;
const string TIPO_MAPA_STRING[MAX_TIPOS_MAPA]=	{"montana","precipicio","lago","volcan","camino","vacio"};
const char TIPO_MAPA_CHAR[MAX_TIPOS_MAPA]=	{'m',	'p',	'l',	'v',	'c',		'V'};
enum {MONTANA=0,PRECIPICIO,LAGO,VOLCAN,CAMINO,VACIO};


const size_t MAX_TIPO_PERSONAJE = 4;
enum {TIPO_CAZADOR=0,TIPO_HUMANO,TIPO_VAMPIRO,TIPO_ZOMBIE};

//Con las variables enumeradas obtengo una equivalencia (int) en energia de cada tipo de objeto en la matriz de energias
const int ENERGIAS[MAX_TIPO_PERSONAJE][MAX_TIPOS_MAPA] =   {
                                                  //{ MONTANA, PRECIPICIO, LAGO , VOLCAN, CAMINO, VACIO }
                                                    { 0 , 2 , 0 , 1 , 1 , 15 },//TIPO CAZADOR
                                                    { 2 , 2 , 0 , 1 , 1 , 15 },//TIPO HUMANO
                                                    { 1 , 0 , 1 , 2 , 1 , 15 },//TIPO VAMPIRO
                                                    { 1 , 1 , 2 , 0 , 1 , 15 }//TIPO ZOMBIE
                                                    };

//Constantes de uso para convencion de los cardinales
const string CARDINALES[4] = {"NOROESTE","SUROESTE","NORESTE","SURESTE"};
enum {NOROESTE=0,SUROESTE,NORESTE,SURESTE};

//Lista de colores
const size_t CANTIDAD_COLORES = 8; 
enum {ROJO=0,VERDE,AMARILLO,AZUL,VIOLETA,CYAN,BLANCO,RESET};
const string ANSI_COLOR[CANTIDAD_COLORES] = {"\x1b[31m","\x1b[32m","\x1b[33m","\x1b[34m","\x1b[35m","\x1b[36m","\x1b[37m","\x1b[0m"};

//Constantes de uso para convencion de no encontrar un dato
const int NO_ENCONTRADO = -1;
const string NO_NUMERO = "-1";

//Constantes de uso para convencion entre mayor menor o igualdad de dos datos
const int PEQUENO = -1;
const int GRANDE = 1;
const int IGUAL = 0;

#endif


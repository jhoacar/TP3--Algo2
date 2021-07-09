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
/*
Name            FG  BG
Black           30  40
Red             31  41
Green           32  42
Yellow          33  43
Blue            34  44
Magenta         35  45
Cyan            36  46
White           37  47
Bright Black    90  100
Bright Red      91  101
Bright Green    92  102
Bright Yellow   93  103
Bright Blue     94  104
Bright Magenta  95  105
Bright Cyan     96  106
Bright White    97  107
*/
const size_t CANTIDAD_COLORES = 31; 
enum {RESET=0,
      NEGRO,ROJO,VERDE,AMARILLO,AZUL,MAGENTA,CYAN,BLANCO,
      GRIS,ROJO_CLARO,VERDE_CLARO,AMARILLO_CLARO,AZUL_CLARO,MAGENTA_CLARO,CYAN_CLARO,
      BG_NEGRO,BG_ROJO,BG_VERDE,BG_AMARILLO,BG_AZUL,BG_MAGENTA,BG_CYAN,BG_BLANCO,
      BG_GRIS,BG_ROJO_CLARO,BG_VERDE_CLARO,BG_AMARILLO_CLARO,BG_AZUL_CLARO,BG_MAGENTA_CLARO,BG_CYAN_CLARO
      };

const string ANSI_COLOR[CANTIDAD_COLORES] ={"\x1b[0m",
                                            "\x1b[30m","\x1b[31m","\x1b[32m","\x1b[33m","\x1b[34m","\x1b[35m","\x1b[36m","\x1b[37m",
                                            "\x1b[90m","\x1b[91m","\x1b[92m","\x1b[93m","\x1b[94m","\x1b[95m","\x1b[96m",
                                            "\x1b[40m","\x1b[41m","\x1b[42m","\x1b[43m","\x1b[44m","\x1b[45m","\x1b[46m","\x1b[47m",
                                            "\x1b[100m","\x1b[101m","\x1b[102m","\x1b[103m","\x1b[104m","\x1b[105m","\x1b[106m"
                                            };

const int TOPE_INFERIOR = 0;

const int TOPE_SUPERIOR = 1;

const int VALORES = 2;

const int VALORES_VIDA[VALORES] = {20, 100};

const int VALORES_ARMADURA[VALORES] = {0, 2};

const int VALORES_FUERZA[VALORES] = {10, 40};

const int VALORES_ENERGIA[VALORES] = {0, 20};


//Constantes de uso para convencion de no encontrar un dato
const int NO_ENCONTRADO = -1;
const string NO_NUMERO = "-1";

const int INFINITO = 99999999; //Tomara una valor grande

//Constantes de uso para convencion entre mayor menor o igualdad de dos datos
const int PEQUENO = -1;
const int GRANDE = 1;
const int IGUAL = 0;

#endif


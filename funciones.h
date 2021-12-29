#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

using namespace std;


//Determina el valor del dado mayor del inicio.
int quien_empieza(int d1,int d2);


//Muestra alternadamente los nombres de los jugadores,que estan jugando.
void mostrar_jugador(int &arranque,int d1,int d2,string j1,string j2);


//Guarda los valores de los dados seleccionados en un vector.
void  dados_seleccionados(int v[],int c,int vstock[]);


//Suma el valor de los elementos de un vector que reciba.
int suma_dado(int v[],int cant);


//Funcion para tirar x cantidad de dados y x cantidad de caras.
void tirar_dados(int v[],int cant, int caras);


//Muestra x cantidad de elementos de un vector segun corresponda.
void mostrar_dados(int v[],int cant);


//Muestra el puntaje del jugador actual.
void mostrar_puntos_acumulados(int v[], int cant);


//Guarda el puntaje mayor y el nombre del jugador que gana la primera partida.
void guardahistorial(bool &bandera,int vpuntaje_total[],int &puntaje_historico,string &jugador_historico,string &posicion1,string &posicion2);


//Muestra el tablero con el ganador historico y pubtaje historico.
void estadisticas(int vt[],string p1,string p2,int &puntaje_historico,string &jugador_historico);


//Define el orden de los jugadores (nos identifica el indice donde acumular luego sus puntajes)
void orden_jugadores(string &p1,string &p2,string j1,string j2,int d1,int d2);


//Indica el indice por jugador del vector total de puntos.
int tablero1(string p1,string p2,string j1,string j2,int v[]);

int tablero2(string p1,string p2,string j1,string j2, int v[]);


//Muestra el jugador ganador de la ronda actual (LOG final de partida)
void ganador_juego_actual(string &posicion1,string &posicion2,string &jugador1,string &jugador2,int vpuntaje_total[],int &puntaje_historico,string &jugador_historico);


//Suma 1 al indice del vector de dados stock de quien esta jugando.
void recibir_dados(int turnos, int vdados_stock[]);


//Pasa la cantidad de dados selecionados si jugada es exitosa al contrincante.
void pasar_dados_al_contrincante(int turnos,int dselect, int vdados_stock[]);


//Corrobora que el usuario quiera salir.
void confirmacion_de_salida(int &menu);


//Recibe los nombres de los jugadores y tira un dado por cada uno hasta que alguno sea mayor e inicie el juego.
void primera_tirada(string &jugador1,string &jugador2,int &dado_inicial_1,int &dado_inicial_2,int &arranque);

bool dados_impares(int v[],int cant);

void  tirar_dados_manualmente(int v[],int c);


#endif // FUNCIONES_H_INCLUDED

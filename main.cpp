#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
//#include <windows.h>
#include <unistd.h>
#include "funciones.h"


using namespace std;


int main()
{
///--------------DECLARACIONES---------------///

    //constante
    const int dcompartidos = 2;

    //Variables simples
    int menu;
    int turnos = 0;
    int ronda = 0;
    int dstock = 6;
    int num_objetivo;
    int dado_inicial_1;
    int dado_inicial_2;
    int dselect=0;
    int arranque = 0;
    int turnos_totales = 0;
    int puntaje_historico;

    //VECTORES
    int vdados_stock[2]= {6,6};
    int vdados[dstock];
    int vdados_elegidos[dselect];
    int vpuntaje_total[2]= {};

    //Jugadores
    string jugador1;
    string jugador2;

    //Auxiliares para Jugadores(ordenados)
    string posicion1;
    string posicion2;

    //Auxiliar para estadisticas.
    string jugador_historico;

    //Banderas
    bool finalizar = false;
    bool seleccionar = false;
    bool jugada_exitosa = false;
    bool b=0;
    bool bandera=0;
    bool todos_impares = false;

    //semilla para la funcion random
    srand(time(NULL));
///----------------------------------------------///

///---------------------MENU---------------------///
    do
    {
        cout << "\n REVENGE" << endl;
        cout << "----------------" << endl;
        cout << "1- JUGAR \n";
        cout << "2- ESTADISTICAS \n";
        cout << "3- CREDITOS \n";
        cout << "----------------" << endl;
        cout << "0- SALIR \n"<<endl;
        cin >> menu;

        system("clear");

        // Salir
        if (menu == 0)
        {
            confirmacion_de_salida(menu);

        }

        // Jugar
        if (menu == 1)
        {

            /// PASO 1

            //Inicializacion para un nuevo Juego

            b=0;
            vpuntaje_total[0]=0;
            vpuntaje_total[1]=0;
            dstock=6;
            vdados_stock[0]=dstock;
            vdados_stock[1]=dstock;
            ronda=0;
            turnos=0;
            turnos_totales=0;
            finalizar = false;

            //---------------------------------

            /// Pedir nombres Jugadores y calcular Inicio.

            primera_tirada(jugador1,jugador2,dado_inicial_1,dado_inicial_2,arranque);


            ///Paso 2

            do
            {
                if(!b)
                {
                    //Define posicion de los jugadores.
                    orden_jugadores(posicion1,posicion2,jugador1,jugador2,dado_inicial_1,dado_inicial_2);
                    b=1;
                }

                turnos++;

                turnos_totales++;

                if(turnos == 1)
                {
                    ronda++;

                }

                /// TABLERO INFORMATIVO

                usleep(2000);

                cout<<"-------------------------------------------------------------------"<<endl;
                cout<<"         ######## - RONDA - "<<ronda<< " ######## \n"<<endl;
                cout<<"                  - TURNO "<<turnos<< " -      \n";
                cout<<"-------------------------------------------------------------------"<<endl;
                cout<<"                    MARCADOR \n";
                cout<<"-------------------------------------------------------------------"<<endl;
                cout<<" Jugador : "<<posicion1<<" - Dados stock actuales: |"<<vdados_stock[0]<<"| - Puntaje : "<<vpuntaje_total[0]<<endl;
                cout<<" \n";
                cout<<" Jugador : "<<posicion2<<" - Dados stock actuales: |"<<vdados_stock[1]<<"| - Puntaje : "<<vpuntaje_total[1]<<endl;
                cout<<"-------------------------------------------------------------------\n"<<endl;

                /// Nombre de jugador del turno actual

                mostrar_jugador(arranque,dado_inicial_1,dado_inicial_2,jugador1,jugador2);

                ///Paso 3

                /// (Jugador ganador - Inicia)

                cout<<" Su tirada de dados objetivos es: "<<endl;
                cout<<"\n";

                /// Lanzar 2 dados de 12 caras

                tirar_dados(vdados,dcompartidos,12);

                /// Mostrar dados de 12 caras

                mostrar_dados(vdados,dcompartidos);

                /// Sumar ambos dados = (Numero Objetivo)

                num_objetivo = suma_dado(vdados,dcompartidos);

                /// Mostrar numero objetivo

                cout<<" El numero objetivo es: "<<num_objetivo<<endl;
                cout<<" \n";

                /// Lanzar dados STOCK de 6 caras

                cout<<" Su tirada de dados stock es: "<<endl;
                cout<<"\n";

                dstock = vdados_stock[turnos-1];

                /// Lanzar dados de 6 caras
                bool tirada_manual = false;

                cout << " Tirar dados manualmente? Si(1) , No(0)  " << endl << endl;
                cin >> tirada_manual;
                cout << endl;

                if (tirada_manual ==  true)
                {
                    tirar_dados_manualmente(vdados, vdados_stock[turnos-1]);
                }
                else
                {
                    tirar_dados(vdados,dstock, 6);
                }


                /// Mostrar dados STOCK de 6 caras

                mostrar_dados(vdados,dstock);

                /// Preguntar si quiere seleccionar dados

                cout << " (1) para seleccionar dados - (0) para pasar de turno: ";
                cin >> seleccionar;

                cout<<" \n";

                if (seleccionar == true)
                {
                    /// Selecionar dados STOCK para alcanzar numero objetivo (Dados elegidos)

                    cout << " Ingrese cuantos dados escojera: ";
                    cin >> dselect;
                    cout<<" \n";

                    dados_seleccionados(vdados_elegidos,dselect,vdados);

                    /// Suma dados selecionados (Suma seleccionada)

                    cout<<" La suma de los dados elegidos es: "<<suma_dado(vdados_elegidos,dselect)<<" \n"<<endl;

                    /// Verifica que suma selecionada sea == dados objetivos

                    if (suma_dado(vdados_elegidos,dselect) == num_objetivo)
                    {
                        jugada_exitosa = true;
                    }

                }



                if (jugada_exitosa == true)
                {

                    vpuntaje_total[turnos-1]+=num_objetivo*dselect;

                    todos_impares = dados_impares(vdados_elegidos, dselect);

                    if (todos_impares == true)
                    {

                        vpuntaje_total[turnos-1] = vpuntaje_total[turnos-1] * 1.5;

                        cout << "Los dados seleccionados fueron todos impares, tu puntaje aumenta un %50 " << endl << endl;
                    }

                    pasar_dados_al_contrincante(turnos, dselect, vdados_stock);

                    ///Mostrar LOG de resultados antes de pasar al sig. jugador.

                    cout<< " ***Jugada existosa***  \n"<<endl;
                    cout<< " ***sumas puntos*** y pasas " << dselect << " dados a tu contrincante." << endl << endl;

                    /// si quien juega, se queda sin dados, Gana

                    if (vdados_stock[turnos-1] <= 0)
                    {
                        cout << " no tienes mas dados " << endl << endl;
                        cout << " ******GANASTE******" << endl<< endl;

                        vpuntaje_total[turnos-1]+= 10000;
                        finalizar = true;
                    }

                }
                else
                {
                    /// se recibe un dado del contrincante siempre que aquel tenga mas de un dado
                    recibir_dados(turnos, vdados_stock);

                }

                mostrar_puntos_acumulados(vpuntaje_total,turnos);

                jugada_exitosa = false;
                seleccionar = false;

                if(turnos==2)
                {
                    turnos=0;
                }

                usleep(2000);
            }
            while(finalizar == false && turnos_totales < 10);

            /// MOSTRARA EL GANADOR DEL JUEGO ACTUAL

            ganador_juego_actual(posicion1,posicion2,jugador1,jugador2,vpuntaje_total,puntaje_historico,jugador_historico);

        }

        ///Guarda el primer ganador

        guardahistorial(bandera,vpuntaje_total,puntaje_historico,jugador_historico,posicion1,posicion2);

        /// Estadisticas
        if (menu == 2)
        {
            //Verificacion inicial

            if (puntaje_historico == 0)
            {
                cout << " Todavia no hay ganadorxs" << endl;
                cout << " Presiona (1) para jugar " << endl << endl;
            }
            else
            {
                estadisticas(vpuntaje_total,posicion1,posicion2,puntaje_historico,jugador_historico);
            }

        }

        /// Creditos
        if (menu == 3)
        {
            cout << "\n CREDITOS: \n\n";
            cout << "\t Gabriel Vargas - Legajo: 25621\n";
            cout << "\t Estefania Delgado Acedo - Legajo: 25467\n\n";
        }

    }
    while(menu != 0);

    return 0;
}

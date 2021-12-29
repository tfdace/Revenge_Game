#include <iostream>
#include <cstdlib>
#include <stdlib.h>
//#include <windows.h>
#include <unistd.h>

#include "funciones.h"

using namespace std;

int quien_empieza(int d1,int d2)
{

    if(d1>d2)
    {

        return d1;
    }
    else
    {
        if(d2>d1)
        {

            return d2;
        }
        else
        {

            return 0;
        }
    }

}


void mostrar_jugador(int &arranque,int d1,int d2,string j1,string j2)
{

    if(arranque==d1)
    {
        cout<<"*****************"<<endl;;
        cout<<" Jugando: "<<j1<<endl;
        cout<<"*****************";
        cout<<"\n"<<endl;
        arranque = d2;
    }
    else
    {
        if(arranque==d2)
        {
            cout<<"*****************"<<endl;
            cout<<" Jugando: "<<j2<<endl;
            cout<<"*****************";
            cout<<"\n"<<endl;
            arranque = d1;
        }
    }
}


void  dados_seleccionados(int v[],int c,int vstock[])
{

    int n;

    cout << " Ahora ingrese la posicion de los dados que desea : "<< endl;
    for(int i = 0; i <c; i++)
    {
        cin >> n;
        v[i] = vstock[n-1];
    }
    cout<<"\n";

}

void  tirar_dados_manualmente(int v[],int c)
{

    int n;
    cout << " Tenes " << c << " dados " << endl << endl;
    cout << " Ingrese el valor de los dados lanzados (del 1 al 6): "<< endl;
    for(int i = 0; i <c; i++)
    {
        cin >> n;
        v[i] = n;
    }


}


int suma_dado(int v[],int cant)
{

    int objetivo=0;

    for(int i=0; i<cant; i++)
    {

        objetivo+=v[i];
    }

    return objetivo;
}

///Funcion para tirar dados de x caras
void tirar_dados(int v[],int cant, int caras)
{

    for(int i=0; i<cant; i++)
    {

        v[i] = 1 + rand()% caras;
    }

}


void mostrar_dados(int v[],int cant)
{

    for(int i=0; i<cant; i++)
    {
        cout<<" | "<<v[i]<<" | ";
    }
    cout<<" \n"<<endl;
}

bool dados_impares(int v[],int cant)
{
    bool impar = true;
    for(int i=0; i<cant; i++)
    {
        if (v[i] % 2 == 0){
            impar = false;
        }
    }


    return impar;
}


// Muestra el valor del indice "cant"
void mostrar_puntos_acumulados(int v[], int cant)
{
    cout << " Tu puntaje hasta ahora es "<< v[cant-1]<<endl << endl;
}


void guardahistorial(bool &bandera,int vpuntaje_total[],int &puntaje_historico,string &jugador_historico,string &posicion1,string &posicion2)
{

    if(!bandera)
    {

        if(vpuntaje_total[0]>vpuntaje_total[1])
        {
            puntaje_historico=vpuntaje_total[0];
            jugador_historico=posicion1;
        }
        else
        {
            if(vpuntaje_total[1]>vpuntaje_total[0])
            {
                puntaje_historico=vpuntaje_total[1];
                jugador_historico=posicion2;
            }
            else
            {
                puntaje_historico=vpuntaje_total[0];
                jugador_historico=posicion1;
            }
        }

        bandera=1;
    }

}


void estadisticas(int vt[],string p1,string p2,int &puntaje_historico,string &jugador_historico)
{

    //Muestra y evalua contra el Puntaje historico

    if(vt[0]>puntaje_historico)
    {
        cout<<" -------------------ESTADISTICAS--------------------------"<<endl;
        cout<<" \t El ganador(a) es: "<<p1<<endl;
        cout<<" \t Puntaje final: "<<vt[0]<<" Pts "<<endl;
        cout<<" ---------------------------------------------------------"<<endl;
        cout<<"\n";
        puntaje_historico=vt[0];
        jugador_historico=p1;
    }
    else
    {
        if(vt[1]>puntaje_historico)
        {
            cout<<" -------------------ESTADISTICAS--------------------------"<<endl;
            cout<<" \t El ganador(a) es: "<<p2<<endl;
            cout<<" \t Puntaje final: "<<vt[1]<<" Pts "<<endl;
            cout<<" ---------------------------------------------------------"<<endl;
            cout<<"\n";
            puntaje_historico=vt[1];
            jugador_historico=p2;

        }
        else    //Si la partida no lograra ser mayor, muestra el historico ganador.
        {
            cout<<" -------------------ESTADISTICAS--------------------------"<<endl;
            cout<<"\n"<<endl;
            cout<<" \t Jugador(a) Historico: "<<jugador_historico<<endl;
            cout<<" \t Puntaje final Historico: "<<puntaje_historico<<" Pts "<<endl;
            cout<<" ---------------------------------------------------------"<<endl;
            cout<<"\n";

        }

    }

}


void orden_jugadores(string &p1,string &p2,string j1,string j2,int d1,int d2)
{

    bool b=0;

    if(!b)
    {
        if(quien_empieza(d1,d2)==d1)
        {
            p1 = j1;
            p2 = j2;
            b = 1;
        }
        else
        {
            if(quien_empieza(d1,d2)==d2)
            {
                p1=j2;
                p2=j1;
                b=1;
            }
        }
    }

}

int tablero1(string p1,string p2,string j1,string j2,int v[])
{

    int result;

    if(p1==j1)
    {
       return result=v[0];
    }
    else
    {

        if(p1==j2)
        {
           return result=v[0];
        }
    }

}


int tablero2(string p1,string p2,string j1,string j2, int v[])
{

    int result;

    if(p2==j1)
    {
        return result=v[1];
    }
    else
    {
        if(p2==j2)
        {
           return result=v[1];
        }
    }

}


void ganador_juego_actual(string &posicion1,string &posicion2,string &jugador1,string &jugador2,int vpuntaje_total[],int &puntaje_historico,string &jugador_historico)
{
    //Para no usar la funcion en el if, guardo el valor en variable.
    int auxiliar_tablero1=tablero1(posicion1,posicion2,jugador1,jugador2,vpuntaje_total);
    int auxiliar_tablero2=tablero2(posicion1,posicion2,jugador1,jugador2,vpuntaje_total);

    if(auxiliar_tablero1 > auxiliar_tablero2)
    {

        cout<<"-------------------------------------------------------------------"<<endl;
        cout<<"                     LOG DE RESULTADOS DE ESTE JUEGO               "<<endl;
        cout<<"\t \t Gana este juego: "<<posicion1<<" con: "<<auxiliar_tablero1<<" PTS "<<endl;
        cout<<"-------------------------------------------------------------------"<<endl;

        //Si menu es =!(2) se verifique el maximo puntaje y almacene el nuevo puntaje historico

        if(vpuntaje_total[0]>puntaje_historico)
        {
            puntaje_historico=vpuntaje_total[0];
            jugador_historico=posicion1;
        }
    }
    else
    {
        if(auxiliar_tablero1 < auxiliar_tablero2)
        {

            cout<<"-------------------------------------------------------------------"<<endl;
            cout<<"                     LOG DE RESULTADOS DE ESTE JUEGO               "<<endl;
            cout<<"\t \t Gana este juego: "<<posicion2<<" con: "<<auxiliar_tablero2<<" PTS "<<endl;
            cout<<"-------------------------------------------------------------------"<<endl;

            //Si menu es =!(2) se verifique el maximo puntaje y almacene el nuevo puntaje historico

            if(vpuntaje_total[1]>puntaje_historico)
            {
                puntaje_historico=vpuntaje_total[1];
                jugador_historico=posicion2;
            }
        }
        else
        {       //En caso de empate muestra por defecto el ganador con dado mas alto.
            cout<<"-------------------------------------------------------------------"<<endl;
            cout<<"                     LOG DE RESULTADOS DE ESTE JUEGO               "<<endl;
            cout<<"\t \t EMPATE Gana este juego por defecto: "<<posicion1<<" con: "<<auxiliar_tablero1<<" PTS "<<endl;
            cout<<"-------------------------------------------------------------------"<<endl;

        }

    }


}


void recibir_dados(int turnos, int vdados_stock[])
{
    int contrincante = 0;

    if (turnos == 1) // Si el turno es 1, el index es 0
    {
        contrincante = 1; // El contrincante es el index 1
    }
    if (vdados_stock[contrincante]>1)
    {
        vdados_stock[turnos-1]++;
        vdados_stock[contrincante]--;

        cout<< " -!Jugada no exitosa!- \n"<<endl;
        cout<<" Recibiras (1) un dado de tu contrincante." <<endl << endl;
    }
    else
    {
        cout << " A tu oponente solo le queda un dado, no te puede pasar uno (aunque te lo merezcas jeje)" << endl;
    }

}

void pasar_dados_al_contrincante(int turnos,int dselect, int vdados_stock[])
{
    int contrincante = 0;

    if(turnos == 1)   //primer turno index 0
    {
        contrincante = 1; // El contrincante es el index 1
    }

    // restarse los dados seleccionados
    vdados_stock[turnos-1]-=dselect;

    // sumar los dados seleccionados al contrincante
    vdados_stock[contrincante]+=dselect;

}

void confirmacion_de_salida(int &menu)
{

    char cancelar;

    cout << endl << "---------------- \n" << endl;
    cout << " Segurx que desea salir? " << endl;
    cout << " Presione 'S' para confirmar o 'N' para cancelar " << endl;
    cout << endl << "----------------" << endl;
    cin >> cancelar;

    switch(cancelar)
    {
    case 'N':
        menu = 9;
    }
}


void primera_tirada(string &jugador1,string &jugador2,int &dado_inicial_1,int &dado_inicial_2,int &arranque){

            cout<<" Ingrese el nombre del 1er Jugador: ";
            cin>>jugador1;

            cout<<" Ingrese el nombre del 2do Jugador: ";
            cin>>jugador2;

            cout<<"\n";

            system("clear");


///ARRANQUE DE PARTIDA

            /// Tirar un dado por persona para sacar.

            do
            {
                dado_inicial_1 = 1 + rand()% 6;
                cout<<" Saque Jugador 1: "<<jugador1<<" su dado fue: "<<dado_inicial_1<<endl<< endl;

                dado_inicial_2 = 1 + rand()% 6;
                cout<<" Saque Jugador 2: "<<jugador2<<" su dado fue: "<<dado_inicial_2<<endl<< endl;

                cout<<"\n";

                /// Cacular el dado mayor
                /// Mostrar quien empieza

                arranque=quien_empieza(dado_inicial_1,dado_inicial_2);

                if(arranque==dado_inicial_1)
                {
                    cout<<" Inicia el jugador: "<<jugador1<<endl;
                }
                else
                {
                    if(arranque==dado_inicial_2)
                    {
                        cout<<" Inicia el jugador: "<<jugador2<<endl;
                    }
                    else
                    {
                        cout<<" Empate se tira de nuevo "<<endl;
                    }
                }

                cout<<"\n";

            }
            while(dado_inicial_1 == dado_inicial_2);
}

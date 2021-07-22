using namespace std;
#include <bits/stdc++.h>
#include <windows.h>
#include "Loading.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "Estado.h"
#include "DatosPersonales.h"
#include "usuarios.h"
#include "administradores.h"
#include <fstream>
#include <ctime>
#include <iomanip>
#include "nodo.h"
#include "reloj.h"
#include "lista.h"
#include "persona.h"
#include "patrimonio.h"
#include "historial.h"
#include "fichero.h"
#include "transaccion.h"
#include "w.h"
#include "Credito.h"
void menuADMINISTRADOR();
void Administrar_Todo();
void RegistrarUsuario(Usuarios *n);
void UsuarioInterfas(string tarjeta);
///////////////////////////////////////////////////////////////////////////////////////////////////////////
int main ()
{
    leer();
    srand (time(NULL));
    bool fin=false;
    string tarjeta, codigo, password;
    do{
        xy(45,5);cout<<"Bienvenido al Banco Tu Dinero Es Mi Dinero  V 9.876.56577.1"<<endl;
        xy(50,10);cout<<"Inicio de Sesion"<<endl;
        xy(35,15);cout<<"No De Tarjeta :"<<endl;
        xy(44,17);cout<<"Code :"<<endl;
        xy(40,19);cout<<"Password :"<<endl;
        xy(40,25);cout<<"Para Salir , escriba - salir -"<<endl;
        xy(51,15);cin>>tarjeta;
        if(tarjeta=="salir"){
            fin=true;
        }else{
            if(tarjeta=="admin"){
                        menuADMINISTRADOR();
                        fin=false;
            }else{
                xy(51,17);cin>>codigo;
                xy(51,19);cin>>password;
                Usuarios *todos=new Usuarios;
                todos->CargarDatos();
                bool existe=todos->BuscarUsuario(tarjeta,codigo,password);
                if(existe==true){
                    cout<<"si existe"<<endl;
                    UsuarioInterfas(tarjeta);
                }
                else{
                    system("cls");
                    xy(45,15);cout<<"Datos Ingresados No Existen"<<endl<<endl<<endl<<endl;
                }
                system("pause");
            }
            system("cls");
        }

    }while(fin==false);
    system("cls");
    xy(45,10);cout<<"GRACIAS POR USAR  ---   BANK TU DINERO ES MI DINERO   ---\n\n\n\n\n\n\n\n";
    return 0;
}

string dni(string cuenta)
{
    persona aux;
    aux.cuenta=cuenta;
    lista<persona> *dumm;
    dumm=Datos_personales.retornarse();
    return dumm->encontrar(new nodo<persona>(aux))->elemento.dni;
}
string RETDNI(string tarjeta){
    Usuarios *n;
    n= new Usuarios;
    n->CargarDatos();
    Nodo *temp=new Nodo;
    temp=n->RetUsuario(tarjeta);
    string DNI=temp->RetDNI();
    delete n;
    return DNI;
}
void VerEstado(string tarjeta)
{
    ver(RETDNI(tarjeta));
    system("pause");

}
void DepositarOtraCuenta(string tarjeta){
    system("cls");
    string dni2;
    double cantidad;
    xy(10,5);cout<<"ingrese cantidad a depositar : ";
    xy(42,5);cin>>cantidad;
    xy(10,7);cout<<"Ingrese DNI a depositar :";
    xy(42,7);cin>>dni2;
    depositar(RETDNI(tarjeta),cantidad,dni2);
    cout<<endl;
    system("pause");
}

void RetirarDinero(string tarjeta){
    system("cls");
    double cant;
    xy(10,5);cout<<"Monto a Retirar :";
    xy(29,5);cin>>cant;
    transaccion(0,RETDNI(tarjeta),cant);
    system("pause");
}
void DepositarMiCuenta(string tarjeta){
    system("cls");
    double cant;
    xy(10,5);cout<<"Monto a Depositar :";
    xy(29,5);cin>>cant;
    transaccion(1,RETDNI(tarjeta),cant);
    system("pause");
}
void PagarPrestamo(string tarjeta){
    system("cls");
    double cant;
    xy(10,5);cout<<"Ingrese cuota a pagar :";
    xy(29,5);cin>>cant;
    pagar(RETDNI(tarjeta),cant);
    cout<<endl;system("pause");

}
void UsuarioInterfas(string tarjeta)
{
    system("color 6f");
    int cont =1 , y=10;
    bool fin=false;
    system("cls");
    while(fin==false)
    {
        //system("cls");
        xy(45,5);cout<<"USUARIO"<<endl;
        xy(25,10);cout<<"Ver Estado";
        xy(25,14);cout<<"Depositar a otra cuenta";
        xy(25,18);cout<<"Retirar Dinero";
        xy(25,22);cout<<"Depositar a mi cuenta";
        xy(25,26);cout<<"Pagar Prestamos";
        xy(25,30);cout<<"Solicitar Prestamo";
        xy(25,34);cout<<"Historial de mi cuenta";
        xy(25,38);cout<<"SALIR";
        cuadro(22,y);
        char x;
        xy(1,1);cout<<cont;
        x=getch();
        if(x==char(80)){
            borrarCuadro(22,y);
            y=y+4;
            if(cont<8){cuadro(22,y);}
            cont++;
            if(cont==9){cont=1;y=10;}
        }
        if(x==char(72)){
            borrarCuadro(22,y);
            y=y-4;
            if(cont>1){cuadro(22,y);}
            cont--;
            if(cont==0){ cont=8;y=38; }
        }
        if(x==char(13)){
                if(cont==8){
                    system("cls");
                    fin=true;
                }
                else{
                    system("cls");
                    switch (cont)
                    {
                    case 1:
                        VerEstado(tarjeta);
                        system("cls");
                        break;
                    case 2:
                        DepositarOtraCuenta(tarjeta);
                        system("pause");
                        system("cls");
                        break;
                    case 3:
                        RetirarDinero(tarjeta);
                        system("cls");
                        break;
                    case 4:
                        DepositarMiCuenta(tarjeta);
                        system("cls");
                        break;
                    case 5:
                        PagarPrestamo(tarjeta);
                        system("cls");
                        break;
                    case 6:
                        double x;
                        xy(10,5);cout<<"cuanto quieres?: ";
                        xy(28,5);cin>>x;
                        solicitar(RETDNI(tarjeta),x);
                        cout<<"\n\n";system("pause");
                        system("cls");
                        break;
                    case 7:
                        movimientos(RETDNI(tarjeta));
                        cout<<"\n\n";system("pause");
                        system("cls");
                        break;
                    }
                }
        }
    }
}


void menuADMINISTRADOR()
{
    string user , pass;
    bool fin=false;
    while(fin==false){
        system("cls");
        xy(45,5);cout<<"ADMINISTRADOR"<<endl;
        xy(35,10);cout<<"Usuario :";
        xy(34,13);cout<<"Password :";
        xy(20,20);cout<<"Para Salir Escriba - salir -";
        xy(45,10);cin>>user;
        if(user=="salir"){
            fin=true;
        }else{
            xy(45,13);cin>>pass;
            admin *x;
            x=new admin;
            bool verificar;
            verificar=x->VerificarExiste(user,pass);
            if(verificar==true)
            {
                Administrar_Todo();
            }else{
                system("cls");
                xy(45,10);cout<<"El Administrador No Existe";
                xy(20,15);system("pause");
            }
            delete x;
        }

    }
}

void Administrar_Todo()
{
    system("color 8f");
    Usuarios *TodosUsuarios=new Usuarios;
    TodosUsuarios->CargarDatos();
    admin *TodosAdmin=new admin;
    int cont =1 , y=10;
    bool fin=false;
    system("cls");
    while(fin==false)
    {
        //system("cls");
        xy(45,5);cout<<"ADMINISTRADOR"<<endl;
        xy(25,10);cout<<"Ver Usuarios";
        xy(25,14);cout<<"Ver Administradores";
        xy(25,18);cout<<"Registrar Usuario";
        xy(25,22);cout<<"Creditos";
        xy(25,26);cout<<"Busqueda";
        xy(25,30);cout<<"Reportes";
        xy(25,34);cout<<"Analisis Creditos";
        xy(25,38);cout<<"SALIR";
        cuadro(22,y);
        char x;
        xy(1,1);cout<<cont;
        x=getch();
        if(x==char(80)){
            borrarCuadro(22,y);
            y=y+4;
            if(cont<8){cuadro(22,y);}
            cont++;
            if(cont==9){cont=1;y=10;}
        }
        if(x==char(72)){
            borrarCuadro(22,y);
            y=y-4;
            if(cont>1){cuadro(22,y);}
            cont--;
            if(cont==0){ cont=8;y=38; }
        }
        if(x==char(13)){
                if(cont==8){
                    //TodosUsuarios->GuardarDatos();
                    fin=true;
                }
                else{
                    system("cls");
                    switch (cont)
                    {
                    case 1:
                        TodosUsuarios->MostrarTodo();
                        cout<<endl;system("pause");
                        system("cls");
                        break;
                    case 2:
                        TodosAdmin->MostrarAdmins();
                        cout<<endl;system("pause");
                        system("cls");
                        break;
                    case 3:
                        RegistrarUsuario(TodosUsuarios);
                        system("pause");
                        system("cls");
                        break;
                    case 4:
                        char aprobar;
                        Credito *solicitudes;
                        solicitudes=new Credito;
                        solicitudes->CargarDatos();
                        system("cls");
                        solicitudes->MostrarDatos();
                        cout<<"\n\n\nDesea Aprobar un prestamo? [s/] :";
                        cin>>aprobar;
                        if(aprobar=='s' || aprobar == 'S'){

                            string dni;
                            cout<<"Ingrese su DNI -para aprobar su solicitud :";
                            cin>>dni;
                            bool existe=solicitudes->existe(dni);
                            if(existe==true){
                                bool aprobar = solicitudes->Aprobar(dni);
                                if(aprobar==true){
                                    cout<<"\nSolicitud Aprobado Exitosamente"<<endl;
                                    solicitudes->MostrarDatos();
                                    solicitudes->GuardarDatos();
                                }else{
                                    cout<<"\nSolicitus ya esta aprobada"<<endl;
                                }
                            }
                            else{
                                cout<<"Esa Persona no Existe"<<endl;
                            }
                        }
                        system("pause");
                        delete solicitudes;
                        system("cls");
                        break;
                    case 5:
                        xy(1,2);cout<<"vbuscando"<<endl;
                        system("cls");
                        system("pause");
                        break;
                    case 6:
                        xy(1,2);cout<<"haciedno reportes"<<endl;
                        system("cls");
                        system("pause");
                        break;
                    case 7:
                        xy(1,2);cout<<"vanbalisis de creditos"<<endl;
                        system("cls");
                        system("pause");
                        break;
                    }
                }

        }
    }
    delete TodosAdmin;
    delete TodosUsuarios;
}

void RegistrarUsuario(Usuarios *n)
{
    system("cls");
    bool fin=false;
    string tarjeta, codigo, DNI, password, password2;
    string nombre , paterno, materno ,email;
    bool existe=false;
    while(fin==false)
    {
        system("cls");
        xy(20,5);cout<<"FORMULARIO";
        xy(14,8);cout<<"Nombre :";
        xy(10,10);cout<<"A. Paterno :";
        xy(10,12);cout<<"A. Materno :";
        xy(14,14);cout<<"E-mail :";
        xy(17,16);cout<<"DNI :";
        xy(13,18);cout<<"Tarjeta :";
        xy(14,20);cout<<"codigo :";
        xy(12,23);cout<<"Password :";
        xy(4,25);cout<<"Repetir Password :\n";
        xy(23,8);cin>>nombre;
        xy(23,10);cin>>paterno;
        xy(23,12);cin>>materno;
        xy(23,14);cin>>email;
        do
        {
            xy(23,16);cin>>DNI;
            xy(5,30);Espacios_En_Blanco(120);
            existe=n->VerificarDNI(DNI);
            if(existe==true){
                xy(23,16);cout<<"EXISTE             ";
                //system("pause");
                Sleep(1000);
                xy(23,16);cout<<"                  ";
            }
        }while(existe==true);
        do
        {
            existe=false;
            xy(23,18);cin>>tarjeta;
            xy(5,30);Espacios_En_Blanco(120);
            existe=n->VerificarTarjeta(tarjeta);
            if(existe==true){
                xy(23,18);cout<<"EXISTE             ";
                //system("pause");
                Sleep(1000);
                xy(23,18);cout<<"                  ";
            }
        }while(existe==true);
        xy(23,20);cin>>codigo;
        xy(23,23);cin>>password;
        xy(23,25);cin>>password2;
        if(password==password2){
            Nodo *nuevo;
            nuevo=new Nodo;
            nuevo->InsertarDatosTarjeta(tarjeta);
            nuevo->InsertarDatosCodigo(codigo);
            nuevo->InsertarDatosDNI(DNI);
            nuevo->InsertarDatos(nombre,email,paterno,materno,password);
            n->InsertarNuevoUsuario(nuevo);
            Loading_Registro(20,30);
            cout<<endl;
        }
        else{
            system("cls");
            xy(20,5);cout<<"LAS CONTRASE"<<char(165)<<"AS NO SON IGUALES\n";
            system("pause");
        }
        if(fin==false){
            bool fin2=false;
            while(fin2==false){
                system("cls");

                xy(10,8);cout<<"Desea Agregar OtroUsuario? [s/?] :";
                xy(45,8);char tecla=getch();
                if(tecla=='s' || tecla=='S'){
                    fin2=true;
                    system("cls");
                }else{
                    fin2=true;fin=true;
                }
            }

        }
    }
}















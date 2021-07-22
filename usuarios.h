//#include "DatosPersonales.h"
class Usuarios
{
private:
    Nodo *cabeza;
public:
    Usuarios(){
        cabeza=NULL;
        //CargarDatos();
    }
    void CargarDatos(){
        FILE *p;
        //fstream p;
        p=fopen("DatosPersonales.txt","r");
        //p.open("DatosPersonales.txt");
        if(p==NULL){
            cout<<"Error Al Abrir fichero"<<endl;
        }else{
            char nom[20] , pat[20] , mat[20] , dni[8] , email[40] , contra[25];
            char Ntarjeta[16], cod[3];
            do{
                Nodo *n;
                n=new Nodo;
                //p>>Ntarjeta>>codigo>>dni>>pat>>mat>>nom>>email>>contra;
                fscanf(p,"%s",Ntarjeta);
                n->InsertarDatosTarjeta(Ntarjeta);
                //cout<<Ntarjeta<<endl;
                fscanf(p,"%s",cod);
                n->InsertarDatosCodigo(cod);
                //cout<<cod<<endl;
                fscanf(p,"%s",dni);
                n->InsertarDatosDNI(dni);
                //cout<<dni<<endl;
                fscanf(p,"%s",pat);
                fscanf(p,"%s",mat);
                fscanf(p,"%s",nom);
                fscanf(p,"%s",email);
                fscanf(p,"%s",contra);
                n->InsertarDatos(nom ,email,pat,mat,contra);
                this->Insertar(n);
            }while (!feof(p));
            //p.close();
            fclose(p);
        }
        EliminarUltimo();
    }

    void Insertar(Nodo *n){
        if(cabeza==NULL){
            cabeza=n;
        }else{
            Nodo *aux=cabeza;
            while (aux->RetEnlace()!=NULL){
                aux=aux->RetEnlace();
            }
            aux->AsignarEnlace(n);
        }
    }
    void InsertarNuevoUsuario(Nodo *n){
        if(cabeza==NULL){
            cabeza=n;
        }else{
            Nodo *aux=cabeza;
            while (aux->RetEnlace()!=NULL){
                aux=aux->RetEnlace();
            }
            aux->AsignarEnlace(n);
        }
        Estado *n2=new Estado;
        n2->CargarDatos();
        Nodox *temp=new Nodox;
        temp->InsertarDatos(n->RetTarjeta(),n->RetDNI(),0,0,0,0,0,0);
        n2->Insertar(temp);
//        system("cls");
//        n2->MostrarDatos();
//        system("pause");

        n2->GuadarDatos();
        this->GuardarDatos();
//        ofstream p;
//        p.open("estado.txt");
//        p<<n->RetDNI()<<" "<<n->RetTarjeta()<<" "<<"0 0 0 0 0 0"<<endl;
//        p.close();
//        FILE *p;
//        p=fopen("estado.txt","a");
//        fprintf(p,n->RetDNI());
//        fprintf(p,n->RetTarjeta());
//        fprintf(p,"%s %s %s %s %s %s\n","0","0","0","0","0","0");
//        fclose(p);
    }
    void MostrarTodo(){
        Nodo *aux=cabeza;
        int x=4 , y=5;
        xy(x,y-2);cout<<"nombre";
        xy(x+10,y-2);cout<<"A. paterno";
        xy(x+25,y-2);cout<<"A. materno";
        xy(x+40,y-2);cout<<"e-mail";
        xy(x+70,y-2);cout<<"tarjeta";
        xy(x+100,y-2);cout<<"codigo";
        xy(x+109,y-2);cout<<"DNI";

        while (aux!=NULL){
            aux->MostrarDatos(x,y);
            aux=aux->RetEnlace();
            y++;
        }
    }
    bool VerificarDNI(string dni){
        Nodo *aux=cabeza;
        while(aux->RetEnlace()!=NULL){
            if(dni==aux->RetDNI()){
                aux->MostrarDatos(5,30);
                return true;
            }
            aux=aux->RetEnlace();
        }
        return false;
    }
    bool VerificarTarjeta(string tarjeta){
        Nodo *aux=cabeza;
        while(aux->RetEnlace()!=NULL){
            if(tarjeta==aux->RetTarjeta()){
                    aux->MostrarDatos(5,30);
                return true;
            }
            aux=aux->RetEnlace();
        }
        return false;
    }
    void EliminarUltimo(){
        Nodo *aux=cabeza;
        while(aux->RetEnlace()->RetEnlace()!=NULL){ aux=aux->RetEnlace(); }
        aux->AsignarEnlace(NULL);
    }
    Nodo *RetUsuario(string tarjeta){
        Nodo *aux=cabeza;
        while(aux->RetEnlace()!=NULL){
            if(aux->RetTarjeta()==tarjeta){
                return aux;
            }
            aux=aux->RetEnlace();
        }
    }

    void GuardarDatos()
    {
        //ifstream temporal("DatosPersonales.txt");
        //const string temp("temporal.txt");
        ofstream p;
        p.open("temp.txt");
        Nodo *aux=cabeza;
        while(aux!=NULL){
            p<<aux->RetTarjeta()<<" "<<aux->RetCodigo()
            <<" "<<aux->RetDNI()<<" "<<aux->RetPaterno()
            <<" "<<aux->RetMaterno()<<" "<<aux->RetNombre()
            <<" "<<aux->RetEmail()<<" "<<aux->RetPassword();
            p<<endl;
            aux=aux->RetEnlace();
            //if(aux==NULL)break;

        }
        //temporal.close();
        p.close();
        remove ("DatosPersonales.txt");
        rename("temp.txt","DatosPersonales.txt");
    }
    bool BuscarUsuario(string tar,string cod,string pass)
    {
        Nodo *aux=cabeza;
        while(aux->RetEnlace()!=NULL){
            if(aux->RetTarjeta()==tar && aux->RetCodigo()==cod && aux->RetPassword()==pass){
                return true;
            }
            aux=aux->RetEnlace();
        }
        return false;
    }
};








class Nodo
{
private:
    Nodo * sig;
    //char nombre[20] , paterno[20] , materno[20] , email[40];
    string tarjeta;
    string DNI;
    string Codigo;
    string nombre, email , paterno , materno;
    string password;
public:
    Nodo(){ sig=NULL; }
    void InsertarDatos(string nom , string correo , string pater , string mater , string contra){
        nombre=nom;
        email=correo;
        paterno=pater;
        materno=mater;
        //DNI=dni;
        password=contra;
        //strcpy(tarjeta,Ntarjeta);
        //strcpy(DNI,dni);
        //strcpy(Codigo,codigo);
        //strcpy(nombre,nom);
        //strcpy(paterno,pater);
        //strcpy(materno,mater);
        //strcpy(email,correo);
        //strcpy(password,contra);
        sig=NULL;
    }
    void InsertarDatosCodigo(string cod){
        Codigo=cod;
    }
    void InsertarDatosTarjeta(string tarj){
        tarjeta=tarj;
    }
    void InsertarDatosDNI (string dni){
        DNI=dni;
    }
    void CambiarContra(string n){
        password=n;
    }
    void AsignarEnlace(Nodo *n){ sig=n; }
    Nodo * RetEnlace(){ return sig; }
    void MostrarDatos(int a , int b){
        xy(a,b);cout<<nombre;
        xy(a+10,b);cout<<paterno;
        xy(a+25,b);cout<<materno;
        xy(a+40,b);cout<<email;
        xy(a+70,b);cout<<tarjeta;
        xy(a+100,b);cout<<Codigo;
        xy(a+105,b);cout<<DNI;
        //cout<<nombre<<"\t"<<paterno<<"\t"<<materno<<"\t"<<email<<"\t"<<tarjeta<<"\t"<<Codigo<<"\t"<<DNI<<endl;
    }
    string RetDNI(){ return DNI; }
    string RetTarjeta(){ return tarjeta; }
    string RetCodigo(){ return Codigo; }
    string RetNombre(){ return nombre; }
    string RetPaterno(){ return paterno; }
    string RetMaterno(){ return materno; }
    string RetEmail(){ return email; }
    string RetPassword(){ return password; }
};

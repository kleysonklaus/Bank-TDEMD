class Nodox
{
private:
    string tarjeta;
    string DNI;
    int saldo , hora , minuto;
    int dia,mes,anyo;
    Nodox *sig;
public:
    Nodox (){
        sig=NULL;
    }
    void AsignarEnlace(Nodox *n){sig=n;}
    void InsertarDatos(string dni , string tarjeta , int saldo,int hora,int minuto,int dia,int mes,int anyo){
        this->tarjeta=tarjeta;  this->DNI=dni;          this->saldo=saldo;
        this->hora=hora;        this->minuto=minuto;    this->dia=dia;
        this->mes=mes;          this->anyo=anyo;
    }
    Nodox *RetEnlace(){return sig;}
    string RetTarjeta(){return tarjeta;}
    string RetDNI(){return DNI;}
    int RetSaldo(){return saldo;}
    int RetHora(){return hora;}
    int RetMinuto(){return minuto;}
    int RetDia(){return dia;}
    int RetMes(){return mes;}
    int RetAnyo(){return anyo;}
};

class Estado
{
private:
    Nodox *cabeza;
public:
    Estado(){cabeza=NULL;}
    Nodox *RetCabeza(){return cabeza;}
    void MostrarDatos(){
        Nodox *aux=cabeza;
        while(aux->RetEnlace()!=NULL){
            cout<<aux->RetTarjeta()<<" "<<aux->RetDNI()<<" "<<aux->RetSaldo()<<" "<<aux->RetHora()<<" "<<
            aux->RetMinuto()<<" "<<aux->RetDia()<<" "<<aux->RetMes()<<" "<<aux->RetAnyo()<<endl;
            aux=aux->RetEnlace();
        }
    }
    void CargarDatos(){
        FILE *p;
        p=fopen("estado.txt","r");
        if(p==NULL){
            cout<<"Error Al Abrir fichero"<<endl;
        }else{
            char tarjeta[17] , dni[9];
            int saldo, hora, minuto,dia, mes,anyo;
            do{
                Nodox *n;
                n=new Nodox;
                fscanf(p,"%s",tarjeta);
                fscanf(p,"%s",dni);
                fscanf(p,"%d",&saldo);
                fscanf(p,"%d",&hora);
                fscanf(p,"%d",&minuto);
                fscanf(p,"%d",&dia);
                fscanf(p,"%d",&mes);
                fscanf(p,"%d",&anyo);
                n->InsertarDatos(dni,tarjeta,saldo,hora,minuto,dia,mes,anyo);
                this->Insertar(n);
            }while (!feof(p));
            fclose(p);
        }
        this->EliminarUltimo();
    }
    void EliminarUltimo(){
        Nodox *aux=cabeza;
        while(aux->RetEnlace()->RetEnlace()!=NULL){ aux=aux->RetEnlace(); }
        aux->AsignarEnlace(NULL);
    }
    void Insertar(Nodox *n){
        if(cabeza==NULL){
            cabeza=n;
        }else{
            Nodox *aux=cabeza;
            while (aux->RetEnlace()!=NULL){
                aux=aux->RetEnlace();
            }
            aux->AsignarEnlace(n);
        }
    }
    void GuadarDatos(){
        ofstream p;
        p.open("temp.txt");
        Nodox *aux=cabeza;
        while(aux!=NULL){
            p<<aux->RetDNI()<<" "<<aux->RetTarjeta()
            <<" "<<aux->RetSaldo()<<" "<<aux->RetHora()
            <<" "<<aux->RetMinuto()<<" "<<aux->RetDia()
            <<" "<<aux->RetMes()<<" "<<aux->RetAnyo();
            p<<endl;
            aux=aux->RetEnlace();
            //if(aux==NULL)break;

        }
        //temporal.close();
        p.close();
        remove ("estado.txt");
        rename("temp.txt","estado.txt");
    }
};
















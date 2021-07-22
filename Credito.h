class NODO
{
private:
    string tarjeta;
    string DNI;
    int saldo , hora , minuto;
    int dia,mes,anyo;
    NODO *sig;
    //estado =0  pendiente
    //estado =1 aprobado
    int estado;
public:
    NODO (){
        sig=NULL;
    }
    void AsignarEnlace(NODO *n){sig=n;}
    void InsertarDatos(string dni , string tarjeta , int saldo,int hora,int minuto,int dia,int mes,int anyo,int estado){
        this->tarjeta=tarjeta;  this->DNI=dni;          this->saldo=saldo;
        this->hora=hora;        this->minuto=minuto;    this->dia=dia;
        this->mes=mes;          this->anyo=anyo;        this->estado=estado;
    }
    void CambiarEstado(int n){estado=n;}
    NODO *RetEnlace(){return sig;}
    string RetTarjeta(){return tarjeta;}
    string RetDNI(){return DNI;}
    int RetSaldo(){return saldo;}
    int RetHora(){return hora;}
    int RetMinuto(){return minuto;}
    int RetDia(){return dia;}
    int RetMes(){return mes;}
    int RetAnyo(){return anyo;}
    int RetEstado(){return estado;}
};

class Credito
{
private:
    NODO *cabeza;
public:
    Credito (){cabeza=NULL;}
    NODO *RetCabeza(){return cabeza;}
    void MostrarDatos(){
        NODO *aux=cabeza;
        cout<<"Tarjeta\t\t\tDNI\t\tSALDO\t\tHORA\tFECHA"<<endl<<endl;
        while(aux->RetEnlace()!=NULL){
            cout<<aux->RetTarjeta()<<"\t"<<aux->RetDNI()<<"\t"<<aux->RetSaldo()<<"\t\t"<<aux->RetHora()<<" "<<
            aux->RetMinuto()<<"\t"<<aux->RetDia()<<" "<<aux->RetMes()<<" "<<aux->RetAnyo()<<"\t";
            if(aux->RetEstado()==0){cout<<"PENDIENTE"<<endl;}
            else{cout<<"APROBADO"<<endl;}
            aux=aux->RetEnlace();
        }
    }
    bool Aprobar(string dni){
        NODO *aux=cabeza;
        while(aux->RetEnlace()!=NULL){
            if(aux->RetDNI()==dni){
                transaccion(1,dni,aux->RetSaldo());
                if(aux->RetEstado()==0){
                    aux->CambiarEstado(1);
                    return true;
                }
                else{
                    return false;
                }
            }
            aux=aux->RetEnlace();
        }
    }
    bool existe(string dni){
        NODO *aux=cabeza;
        while(aux->RetEnlace()!=NULL){
            if(aux->RetDNI()==dni){
                return true;
            }
            aux=aux->RetEnlace();
        }
        return false;
    }
    void CargarDatos(){
        FILE *p;
        p=fopen("solicitudes.txt","r");
        if(p==NULL){
            cout<<"Error Al Abrir fichero"<<endl;
        }else{
            char tarjeta[17] , dni[9];
            int estado,saldo, hora, minuto,dia, mes,anyo;
            do{
                NODO *n;
                n=new NODO ;
                fscanf(p,"%s",dni);
                fscanf(p,"%s",tarjeta);
                fscanf(p,"%d",&saldo);
                fscanf(p,"%d",&hora);
                fscanf(p,"%d",&minuto);
                fscanf(p,"%d",&dia);
                fscanf(p,"%d",&mes);
                fscanf(p,"%d",&anyo);
                fscanf(p,"%d",&estado);
                n->InsertarDatos(dni,tarjeta,saldo,hora,minuto,dia,mes,anyo,estado);
                this->Insertar(n);
            }while (!feof(p));
            fclose(p);
        }
        //this->EliminarUltimo();
    }
    void EliminarUltimo(){
        NODO *aux=cabeza;
        while(aux->RetEnlace()->RetEnlace()!=NULL){ aux=aux->RetEnlace(); }
        aux->AsignarEnlace(NULL);
    }
    void Insertar(NODO *n){
        if(cabeza==NULL){
            cabeza=n;
        }else{
            NODO *aux=cabeza;
            while (aux->RetEnlace()!=NULL){
                aux=aux->RetEnlace();
            }
            aux->AsignarEnlace(n);
        }
    }
    void GuardarDatos(){
        ofstream p;
        p.open("temp.txt");
        NODO *aux=cabeza;
        while(aux->RetEnlace()!=NULL){
            p<<aux->RetDNI()<<" "<<aux->RetTarjeta()
            <<" "<<aux->RetSaldo()<<" "<<aux->RetHora()
            <<" "<<aux->RetMinuto()<<" "<<aux->RetDia()
            <<" "<<aux->RetMes()<<" "<<aux->RetAnyo()<<" "<<aux->RetEstado();
            p<<endl;
            aux=aux->RetEnlace();
        }
        //temporal.close();
        p.close();
        remove ("solicitudes.txt");
        rename("temp.txt","solicitudes.txt");
    }
};




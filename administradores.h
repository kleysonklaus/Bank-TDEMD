class DatosAdmin
{
private:
    string usuario , password;
    DatosAdmin *sig;
public:
    DatosAdmin(){ sig=NULL; }
    void InsertarAdmin(string user , string pass){
        usuario=user; password=pass;
    }
    void CambiarAdmin(string user , string pass ){
        usuario=user ; password=pass;
    }
    void MostrarDatos(int x , int y){
        xy(x,y);cout<<"Usuario : "<<usuario;
        xy(x+30,y);cout<<"Password : "<<password<<endl;
    }
    string RetUser(){ return usuario; }
    string RetPass(){ return password; }
    void AsignarEnlace(DatosAdmin *n){ sig=n; }
    DatosAdmin *RetEnlace(){ return sig; }
};

class admin
{
private:
    DatosAdmin *cabeza;
    void CargarDatos(){
        FILE *p;
        p=fopen("Administradores.txt","r");
        if(p==NULL){
            cout<<"Error Al Abrir fichero"<<endl;
        }else{
            char user[30] , pass[30];
            do{
                DatosAdmin *n;
                n=new DatosAdmin;
                fscanf(p,"%s",user);
                fscanf(p,"%s",pass);
                n->InsertarAdmin(user,pass);
                Insertar(n);
            }while (!feof(p));
        fclose(p);
        }
    }
public:
    admin(){
        cabeza=NULL;
        CargarDatos();
    }
    bool VerificarExiste (string user , string pass){
        DatosAdmin *aux=cabeza;
        while(aux->RetEnlace()!=NULL){
            if( user == aux->RetUser() ){
                if( pass == aux->RetPass() )
                    return true;
            }
            aux=aux->RetEnlace();
        }
        return false;
    }
    void Insertar(DatosAdmin *n){
        if(cabeza==NULL){
            cabeza=n;
        }else{
            DatosAdmin *aux=cabeza;
            while(aux->RetEnlace()!=NULL){ aux=aux->RetEnlace(); }
            aux->AsignarEnlace(n);
        }
    }
    void MostrarAdmins(){
        DatosAdmin *aux=cabeza;
        int x=10 , y=5;
        while(aux->RetEnlace()!=NULL){
            aux->MostrarDatos(x,y);
            aux=aux->RetEnlace();
            y++;
        }
    }
};

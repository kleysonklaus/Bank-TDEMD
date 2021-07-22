template<typename T>
class  cargar_Datos
{
public:
    const string files;
    T auxiliar;
    lista<T> *datos;
    cargar_Datos(string nombre):files(nombre)
    {
        datos=new lista<T>;
    }
   void cambios(lista<T> *temporal)
   {
       datos=temporal;
   }
   void  leer()
    {
        ifstream archivo;
        archivo.open(files.c_str());
        while(!archivo.eof())
        {
            archivo>>auxiliar;
            datos->insertar(new nodo<T>(auxiliar));
            //cout<<auxiliar<<endl;
        }
        archivo.close();
    }
    void escribir()
    {
        ifstream temporal(files.c_str());
        const string temp("joder.txt");
        ofstream archivo;
        archivo.open(temp.c_str());
        nodo<T> *inicio = datos->Rinicio();
        while(inicio!=NULL && !temporal.eof())
        {
            //cout<<inicio->elemento<<endl;
            archivo<<inicio->elemento;
            inicio=inicio->sig;
            if(inicio==NULL) break;
            archivo<<endl;
        }
        temporal.close();
        archivo.close();
        remove(files.c_str());
        rename(temp.c_str(),files.c_str());
    }
    lista<T> *retornarse()
    {
         return datos;
    }
};

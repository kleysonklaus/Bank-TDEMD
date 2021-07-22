template <typename dato>
class nodo
{
    public:
    nodo<dato> *sig;
    nodo<dato> *ant;
    dato elemento;
    nodo(dato entrada)
    {
        elemento=entrada;
        sig=NULL;
        ant=NULL;
    }
};

template <class T , class U>
class mover
{
    public:
    lista<T> *datos;
    lista<U> *registro;
    T inter;
    U onter;
    mover(){ registro=new lista<T>;}
    mover( lista<T> *data, string dni, string cuenta)
    {
        inter.dni=onter.dni=dni;
        inter.cuenta=onter.cuenta=cuenta;
        datos=data;
        registro=new lista<U>;
    }
    void  deposito(double monto)
    {
        inter.saldo= datos->encontrar(new nodo<T>(inter))->elemento.saldo + monto;
        onter.saldo=inter.saldo; onter.estado=1;
        if( datos->encontrar(new nodo<T>(inter))->elemento == inter)
        {
            datos->modificar(datos->encontrar(new nodo<T>(inter)),new nodo<T>(inter));
            registro->insertar(new nodo<U>(onter));
        }
    }
    void  retiro(double monto)
    {
        inter.saldo=datos->encontrar(new nodo<T>(inter))->elemento.saldo - monto;
        onter.saldo=inter.saldo; onter.estado=0;
        if( datos->encontrar(new nodo<T>(inter))->elemento == inter)
        {
               datos->modificar(datos->encontrar(new nodo<T>(inter)),new nodo<patrimonio>(inter));
            registro->insertar(new nodo<U>(onter));
        }

    }
};


    cargar_Datos<persona> Datos_personales("DatosPersonales.txt");
    cargar_Datos<patrimonio> Estado_Actual("estado.txt");
    cargar_Datos<patrimonio> deudores("prestamos.txt");
    cargar_Datos<historial> Registro_actividad("historial.txt");
    cargar_Datos<historial> Solicitud_Prestamo("solicitudes.txt");


void leer()
{
    Datos_personales.leer();
    Estado_Actual.leer();
    deudores.leer();
    Registro_actividad.leer();
    Solicitud_Prestamo.leer();
}

void ver(string dni)
{
    lista<persona> *yo;
    yo=Datos_personales.retornarse(); lista<patrimonio> *midinero;
    midinero=Estado_Actual.retornarse();
    persona aux; aux.dni=dni;
    if(yo->buscar(new nodo<persona>(aux)))
    {
        patrimonio auxi; auxi.dni=dni;
        if(yo->encontrar(new nodo<persona>(aux))->elemento == aux)
        {
            xy(20,3);cout<<"[N DE CUENTA] "<<yo->encontrar(new nodo<persona>(aux))->elemento.cuenta<<endl<<endl;
            xy(20,5);cout<<"[NOMBRE] "<<yo->encontrar(new nodo<persona>(aux))->elemento.nombre<<" "<<yo->encontrar(new nodo<persona>(aux))->elemento.paterno<<" "<<yo->encontrar(new nodo<persona>(aux))->elemento.materno<<endl;
            xy(20,7);cout<<"[DNI] "<<yo->encontrar(new nodo<persona>(aux))->elemento.dni;

        }
        if(midinero->encontrar(new nodo<patrimonio>(auxi))->elemento == auxi);
        {
             xy(20,9);cout<<"[SALDO] "<<midinero->encontrar(new nodo<patrimonio>(auxi))->elemento.saldo<<endl;
        }
    }
    else cout<<"NO ESTA REGISTRADO";

}


void transaccion(bool MOS, string  dni, double monto )
{
    lista<patrimonio> *midinero;
    midinero=Estado_Actual.retornarse();
    patrimonio aux;
    aux.dni=dni;  aux.saldo=monto;
    patrimonio destino;
    destino.dni=dni; destino.saldo=monto;
    if(midinero->buscar(new nodo<patrimonio>(aux))){
        aux.cuenta=midinero->encontrar(new nodo<patrimonio>(aux))->elemento.cuenta;
        mover<patrimonio,historial>  dinero(midinero,dni,aux.cuenta);
        if(MOS) dinero.deposito(monto);
        if(!MOS) dinero.retiro(monto);
        Estado_Actual.cambios(dinero.datos);
        Estado_Actual.escribir();
        Registro_actividad.datos->insertar(dinero.registro->Rinicio());
        Registro_actividad.escribir();
        xy(40,10); cout<<"TRANSACCION EXITOSA";
    }
    else cout<<"error";
}
void pagar(string dni , double monto )
{
    lista<patrimonio> *deudas;
    lista<patrimonio> *midinero;
    deudas=deudores.retornarse();
    midinero=Estado_Actual.retornarse();
    patrimonio aux;
    aux.dni=dni; aux.saldo=monto;
    if(midinero->buscar(new nodo<patrimonio>(aux)) && deudas->buscar(new nodo<patrimonio>(aux))) {
    aux.cuenta=deudas->encontrar(new nodo<patrimonio>(aux))->elemento.cuenta;
    mover<patrimonio,historial>  cobro(deudas,dni,aux.cuenta);
    mover<patrimonio,historial>  dinero(midinero,dni,aux.cuenta);
    cobro.retiro(monto);
    dinero.retiro(monto);
    Estado_Actual.cambios(dinero.datos);
    Estado_Actual.escribir();
    deudores.cambios(cobro.datos);
    deudores.escribir();
    Registro_actividad.datos->insertar(dinero.registro->Rinicio());
    Registro_actividad.escribir();
    }
    else cout<<"NO TIENE DEUDAS";
}


void depositar(string dni ,double monto, string destino)
{
    transaccion(0,dni,monto);
    transaccion(1,destino,monto);
}

void movimientos(string dni)
{
   lista<historial> *acciones ;
   acciones=Registro_actividad.retornarse();
   historial aux; aux.dni=dni;
   if(acciones->buscar(new nodo<historial>(aux))){
    nodo<historial> *temp=acciones->finall();
    int cont=2;
    while(temp!=NULL){
        if(temp->elemento==aux)
        {
            xy(10,1);cout <<"[SALDO]"; xy(20,1);cout<<"[HH] "<<"[MM] "<<"[DD] "<<"[MS] "<<"[AN] "<<endl<<endl;
            xy(12,cont);cout<<temp->elemento.saldo;
            xy(21,cont);cout<<temp->elemento.h.hh;
            xy(26,cont);cout<<temp->elemento.h.mm;
            xy(31,cont);cout<<temp->elemento.d.dia;
            xy(36,cont);cout<<temp->elemento.d.mes;
            xy(40,cont);cout<<temp->elemento.d.anio;
            cont++;
        }
        temp=temp->ant;
    }
   }
   else cout<<"NO EXISTEN REGISTROS";
}

void solicitar(string dni ,double monto)
{
    historial aux;
    patrimonio temporal;
    temporal.dni=dni;
    aux.dni=dni;
    aux.saldo=monto;
    aux.estado=0;
    lista<historial> *agregar;
    lista<patrimonio> *cuenta;
    cuenta=Estado_Actual.retornarse();
    agregar=Solicitud_Prestamo.retornarse();
    if(cuenta->buscar(new nodo<patrimonio>(temporal))){
        if( !agregar->buscar(new nodo<historial>(aux))){
            aux.cuenta=cuenta->encontrar(new nodo<patrimonio>(temporal))->elemento.cuenta;
            Solicitud_Prestamo.datos->insertar(new nodo<historial>(aux));
            Solicitud_Prestamo.escribir();
        }
        else cout<<"TIENE UN PRESTAMO PENDIENTE";
    }
}

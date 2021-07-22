class historial:public patrimonio
{
public:
    bool estado;
    historial(){;}
    historial(string dni , string cuenta , double saldo , bool estado=0):patrimonio(dni,cuenta, saldo)
    {
        this->dni=dni;
        this->cuenta=cuenta;
        this->saldo=saldo;
        this->estado=estado;
    }
    historial(const historial &dato)
    {
        dni=dato.dni;
        cuenta=dato.cuenta;
        saldo=dato.saldo;
        d.dia=dato.d.dia;
        d.mes=dato.d.mes;
        d.anio=dato.d.anio;
        h.hh=dato.h.hh;
        h.mm=dato.h.mm;
        estado=dato.estado;
    }
   const historial &operator = (const historial & dat);
   bool operator == (const historial & dat) const
   {
       if(this->dni==dat.dni)
        return  true;
       else return false;
   }
   bool operator != (const historial & dat) const
   {
       return !( *this == dat);
   }
};
   const historial &historial::operator = (const historial & dat)
   {
       if( this != &dat)
        {
            this ->dni=dat.dni;
            this->dni=dat.dni;
            this->cuenta=dat.cuenta;
            this->saldo=dat.saldo;
            this->d.dia=dat.d.dia;
            this->d.mes=dat.d.mes;
            this->d.anio=dat.d.anio;
            this->h.hh=dat.h.hh;
            this->h.mm=dat.h.mm;
            this->estado=dat.estado;
        }
        return *this;
   }


    istream &operator >>(istream &entrada, historial &dato)
    {
        entrada>>dato.dni;
        entrada.ignore();
        entrada>>dato.cuenta;
        entrada.ignore();
        entrada>>dato.saldo;
        entrada.ignore();
        entrada>>dato.h.hh;
        entrada.ignore();
        entrada>>dato.h.mm;
        entrada.ignore();
        entrada>>dato.d.dia;
        entrada.ignore();
        entrada>>dato.d.mes;
        entrada.ignore();
        entrada>>dato.d.anio;
        entrada.ignore();
        entrada>>dato.estado;

        return entrada;
    }
    ostream &operator << (ostream &salida, historial & dato)
    {
        salida<<dato.dni
        <<" "<<dato.cuenta
        <<" "<<dato.saldo
        <<" "<<dato.h.hh
        <<" "<<dato.h.mm
        <<" "<<dato.d.dia
        <<" "<<dato.d.mes
        <<" "<<dato.d.anio
        <<" "<<dato.estado;
        return salida;
    }


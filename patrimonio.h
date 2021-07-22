class  patrimonio{
private:
     Reloj p;
public:
    string dni ,cuenta;
    double saldo;
    Fecha d;
    hora  h;
    patrimonio()
    {
        H();
    }
    patrimonio(string   dni , string  cuenta , double saldo)
    {
        H();
        this->dni=dni;
        this->cuenta=cuenta;
        this->saldo=saldo;
    }
    void H()
    {
        d.dia=p.AsignarDia();
        d.mes=p.AsignarMes();
        d.anio=p.AsignarAnio();
        h.hh=p.AsignarHora();
        h.mm=p.AsignarMinuto();
    }
    patrimonio(const patrimonio &dato)
    {
        dni=dato.dni;
        cuenta=dato.cuenta;
        saldo=dato.saldo;
        d.dia=dato.d.dia;
        d.mes=dato.d.mes;
        d.anio=dato.d.anio;
        h.hh=dato.h.hh;
        h.mm=dato.h.mm;
    }

    const patrimonio &operator=(const patrimonio &dat);
    bool operator == (const patrimonio &dat) const ;
    bool operator != (const patrimonio &dat) const
    {
        return !(*this==dat);
    }
};


   bool patrimonio::operator ==(const patrimonio &dat)const
   {
       if( this->dni== dat.dni || this ->cuenta== dat.cuenta)
        return true;
       else return false;
   }
   const  patrimonio &patrimonio::operator=(const patrimonio &dat)
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
        }
        return *this;
    }

ostream &operator << (ostream &salida ,  patrimonio &dato)
{
        salida<<dato.dni
        <<" "<<dato.cuenta
        <<" "<<dato.saldo
        <<" "<<dato.h.hh
        <<" "<<dato.h.mm
        <<" "<<dato.d.dia
        <<" "<<dato.d.mes
        <<" "<<dato.d.anio;
        return salida;
}
istream &operator>>(istream &entrada, patrimonio &dato)
{
        entrada>>setw(8)>>dato.dni;
        entrada.ignore();
        entrada>>setw(16)>>dato.cuenta;
        entrada.ignore();
        entrada>>setw(20)>>dato.saldo;
        entrada.ignore();
        entrada>>setw(2)>>dato.h.hh;
        entrada.ignore();
        entrada>>setw(2)>>dato.h.mm;
        entrada.ignore();
        entrada>>setw(2)>>dato.d.dia;
        entrada.ignore();
        entrada>>setw(2)>>dato.d.mes;
        entrada.ignore();
        entrada>>setw(4)>>dato.d.anio;
        return entrada;
}

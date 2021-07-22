class persona
{
    public:
    string  dni , cuenta , paterno,materno,nombre , email, contrasena, codigo;
    persona(){  ; }
    persona(string cuenta , string codigo ,string dni,  string paterno , string materno , string nombre , string email , string contrasena)
    {
        this->cuenta=cuenta;
        this->codigo=codigo;
        this->dni=dni;
        this->paterno=paterno;
        this->materno=materno;
        this->nombre=nombre;
        this->email=email;
        this->contrasena=contrasena;
    }

    persona(const persona &dato)
    {
        dni=dato.dni;
        cuenta=dato.cuenta;
        paterno=dato.paterno;
        materno=dato.materno;
        nombre=dato.nombre;
        email=dato.email;
        contrasena=dato.contrasena;
        codigo=dato.codigo;
    }

    const persona &operator = (const persona &dato)
    {
        if(this != &dato)
        {
            this->dni=dato.dni;
            this->cuenta=dato.cuenta;
            this->paterno=dato.paterno;
            this->materno=dato.materno;
            this->nombre=dato.nombre;
            this->email=dato.email;
            this->contrasena=dato.contrasena;
            this->codigo=dato.codigo;
        }
        return *this;
    }

    bool operator == (const persona &dato) const
    {
        if( this->dni == dato.dni)
        return true;
        else return false;
    }

    bool operator !=( const persona &dato)
    {
        return !(*this == dato);
    }

};
    istream &operator >>(istream &entrada , persona &dato)
    {
        entrada>>setw(0)>>dato.cuenta;
        entrada.ignore();
        entrada>>setw(0)>>dato.codigo;
        entrada.ignore();
        entrada>>setw(0)>>dato.dni;
        entrada.ignore();
        entrada>>setw(0)>>dato.paterno;
        entrada.ignore();
        entrada>>setw(0)>>dato.materno;
        entrada.ignore();
        entrada>>setw(0)>>dato.nombre;
        entrada.ignore();
        entrada>>setw(0)>>dato.email;
        entrada.ignore();
        entrada>>setw(0)>>dato.contrasena;
        return entrada;
    }
    ostream &operator << (ostream &salida , persona &dato)
    {
        salida<<setw(16)<<dato.cuenta
        <<setw(5)<<dato.codigo
        <<setw(10)<<dato.dni
        <<setw(10)<<dato.paterno<<
        setw(12)<<dato.materno<<
        setw(12)<<dato.nombre<<
        setw(20)<<dato.email<<
        setw(15)<<dato.contrasena;
        return salida;
    }

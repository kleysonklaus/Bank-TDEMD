struct Fecha
{
    int dia;
    int mes;
    int anio;
};
struct hora
{
    int hh;
    int mm;
    int ss;
};
class Reloj
{
public:
int  AsignarHora();
int  AsignarMinuto();
int  AsignarSec();
int  AsignarAnio();
int  AsignarMes();
int  AsignarDia();
};

int  Reloj::AsignarHora()
{
    struct tm *tptr;
    time_t t = time(NULL);
    tptr = localtime(&t);
    return tptr->tm_hour;
}
int  Reloj::AsignarMinuto()
{
    struct tm *tptr;
    time_t t = time(NULL);
    tptr = localtime(&t);
    return tptr->tm_min;
}
int  Reloj::AsignarSec()
{
    struct tm *tptr;
    time_t t = time(NULL);
    tptr = localtime(&t);
    return tptr->tm_sec;
}
int  Reloj::AsignarDia()
    {
    struct tm *tptr;
    time_t t = time(NULL);
    tptr = localtime(&t);
    return tptr->tm_mday;
}
int  Reloj::AsignarMes()
{
    struct tm *tptr;
    time_t t = time(NULL);
    tptr = localtime(&t);
    return tptr->tm_mon+1;
}
int  Reloj::AsignarAnio()
{
    struct tm *tptr;
    time_t t = time(NULL);
    tptr = localtime(&t);
    return tptr->tm_year + 1900;
}


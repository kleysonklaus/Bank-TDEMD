void xy (int x , int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void borrarCuadro(int x , int y)
{
    xy(x-1,y);cout<<" ";  xy(x+25,y);cout<<" ";
    xy(x-1,y-1);cout<<" ";  xy(x-1,y+1);cout<<" ";
    xy(x+25,y-1);cout<<" "; xy(x+25,y+1);cout<<" ";
    xy(x,y-1);for(int i=0 ;i<25 ; i++)cout<<" ";
    xy(x,y+1);for(int i=0 ;i<25 ; i++)cout<<" ";
}
void cuadro(int x , int y)
{
    xy(x-1,y);cout<<char(179);  xy(x+25,y);cout<<char(179);
    xy(x-1,y-1);cout<<char(218);  xy(x-1,y+1);cout<<char(192);
    xy(x+25,y-1);cout<<char(191); xy(x+25,y+1);cout<<char(217);
    xy(x,y-1);for(int i=0 ;i<25 ; i++)cout<<char(196);
    xy(x,y+1);for(int i=0 ;i<25 ; i++)cout<<char(196);
}
void Espacios_En_Blanco (int i)
{
    for (int j=0 ; j<i ; j++) { cout<<" "; }
}

void Loading_Normal (int x , int y)
{
        xy (x,y-1);cout<<"Guardando Datos";
        xy (x,y);
            for (int i=0 ; i<30 ; i++)
            {
                    cout<< char (223);
                    Sleep(20);
            }
        xy(x,y-1);Espacios_En_Blanco(40);
        xy(x,y);cout<<"Datos Guardados Exitosamente    ";
        Sleep(1000);
}

void Loading_Busqueda(int x, int y)
{
        xy(x,y-1);cout<<"Buscando";

        for(int i=0 ; i<3 ; i++)
        {
                xy(x,y);Espacios_En_Blanco(50);
                xy(x,y);
                for (int j=0 ; j<30 ; j++)
                {
                        xy(x+j,y);cout<<char (254);
                        Sleep(20);
                }
                xy(x+10+i,y-1);cout<<".";
        }
        xy(x,y-1);Espacios_En_Blanco(20);
        xy(x,y);Espacios_En_Blanco(31);


}


void Loading_Simple()
{
    for (int i=0 ; i<30 ; i++)
    {
        cout<< char (254);
        Sleep(75);
    }
}

void Loading_Registro( int x ,  int y)
{
        int tiempo = 500;
        xy(x,y-1);cout<<"Creando Usuario";
        xy(x,y);
        for (int i=0 ; i<35 ; i++)
        {
                cout<<char (219);
                Sleep(tiempo);
                    if(i==3)
                    {
                        tiempo=200;
                    }
                    else if(i==10)
                    {
                        xy(x,y-1);cout<<"Guardando Usuario";
                        tiempo=50;
                        xy(x+10,y);
                    }
        }
        xy(x,y);cout<<"                                     ";
        xy(x,y-1);cout<<"                          ";
        xy(x,y);cout<<"Registro Completo";
        Sleep(1000);
}

template <class dato>
class lista
{
private:
    nodo<dato> *inicio;
    nodo<dato> *iterador;
public:
    int tamano;
    lista()
    {   inicio=NULL;
        tamano=0;
    }
     nodo<dato> *finall()
    { nodo<dato> *temp=inicio;
        while(temp->sig!=NULL)
        {
            temp=temp->sig;
        }
        return temp;
    }
    nodo<dato> *Rinicio()
    { return inicio;
    }
    void insertar(nodo<dato> *entrada)
    { if(inicio==NULL)
        {
            inicio=entrada;
            iterador=inicio;
            tamano++;
        }
        else
        {
            nodo<dato> *temp=finall();
            temp->sig=entrada;
            entrada->ant=temp;
            tamano ++;
        }
    }
    nodo<dato> *avanzar(bool flag)
     { if(iterador->sig!=NULL && flag)
         {
            iterador=iterador->sig;
            return iterador;
         }
         else
           return iterador;
     }
     nodo<dato> *retro(bool flag)
     { if(iterador->ant!=NULL && flag)
          {
          iterador=iterador->ant;
          return iterador;
          }
          else
            return iterador;
     }

    bool buscar(nodo<dato> *extraviado)
    {
        nodo<dato> *buscador=inicio;
         while(buscador->elemento!= extraviado->elemento && buscador->sig!=NULL)
         {
             buscador=buscador->sig;
         }
        if(buscador->elemento==extraviado->elemento)return true;
        else return false;
    }
    nodo<dato> *encontrar(nodo<dato> *extraviado)
    {
        nodo<dato> *buscador=inicio;
         while(buscador->elemento!= extraviado->elemento && buscador->sig!=NULL)
         {
             buscador=buscador->sig;
         }
        if(buscador->elemento==extraviado->elemento)return buscador;
        else return NULL;
    }

    bool modificar(nodo<dato> *herido , nodo<dato> *curado)
    {   nodo<dato> *temp;
        temp = this->encontrar(herido);
         if(temp != NULL)
         {
            temp->elemento=curado->elemento;
            return true;
         }
         else return false;
    }
};


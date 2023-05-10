#include <iostream>
#include <string>
using namespace std;
class Alumno {
    private:
        string Nombre;
        string Carrera;
        int Materias;
        float Promedio;
    public:
        Alumno() {}
        friend ostream& operator<<(ostream& O, Alumno& x) {
            O << "\nNombre del alumno: " << x.Nombre;
            O << "\nNombre de la Carrera: " << x.Carrera;
            O << "\nMaterias Aprobadas: " << x.Materias;
            O << "\nPromedio: " << x.Promedio;
            return O;
            }
        friend istream& operator>>(istream& I, Alumno& x) {
            cout << "\nNombre: ";
            I >> x.Nombre;
            cout << "Carrera: ";
            I >> x.Carrera;
            cout << "Materias Aprobadas: ";
            I >> x.Materias;
            cout << "Promedio: ";
            I >> x.Promedio;
            return I;
            }
    };
template<class T>
class Cola;

template<class T>
class node {
    private:
        T data;
        node<T>* sig;
    public:
        node():sig(nullptr) {};
        friend class Cola<T>;
    };

template<class T>
class Cola {
    private:
        node<T>* lista;
        node<T>* ultimo()const;
        node<T>* primero()const;
        node<T>* anterior(node<T>* pos)const;
        void insertar(node<T>* pos, T elem);
        bool eliminar(node<T>* pos);
    public:
        Cola():lista(nullptr) {};
        bool vacia()const;
        void imprimir()const;
        void Enqueue(T elem);
        void Dequeue();
        T Front();
    };

template<class T>
T Cola<T>::Front() {
    if(!vacia()) {
        return primero()->data;
        }
    }

template<class T>
void Cola<T>::Dequeue() {
    eliminar(primero());
    }

template<class T>
void Cola<T>::Enqueue(T elem) {
    insertar(ultimo(),elem);
    }

template<class T>
void Cola<T>::imprimir()const{
    node<T>* aux=lista;
    while(aux!=nullptr){
        std::cout<<aux->data<<"-> ";
        aux=aux->sig;
    }
}

template<class T>
bool Cola<T>::eliminar(node<T>* pos) {
    if(vacia() || pos==nullptr) {
        return false;
        }
    if(pos==lista) {
        lista=lista->sig;
        }
    else {
        anterior(pos)->sig=pos->sig;
        }
    delete pos;
    return true;
    }

template<class T>
void Cola<T>::insertar(node<T>* pos, T elem) {
    node<T>* aux= new node<T>;
    aux->data=elem;
    if(pos==nullptr) {
        aux->sig=lista;
        lista=aux;
        }
    else {
        aux->sig=pos->sig;
        pos->sig=aux;
        }
    }

template<class T>
node<T>* Cola<T>::anterior(node<T>* pos)const {
    if(vacia() || pos==nullptr) {
        return nullptr;
        }
    node<T>* aux=lista;
    while(aux!=nullptr && aux->sig!=pos) {
        aux=aux->sig;
        }
    return aux;
    }

template<class T>
node<T>* Cola<T>::primero()const {
    if(vacia()) {
        return nullptr;
        }
    return lista;
    }


template<class T>
node<T>* Cola<T>::ultimo()const {
    if(vacia()) {
        return nullptr;
        }
    node<T>* aux=lista;
    while(aux->sig!=nullptr) {
        aux=aux->sig;
        }
    return aux;
    }

template<class T>
bool Cola<T>::vacia()const {
    if(lista==nullptr) {
        return true;
        }
    return false;
    }

int menu();

int main() {
    Cola<Alumno> Constancia;
    Alumno obj;
    int pos,opc;
    string z;
    do {
        opc=menu();
        switch(opc) {
            case 1:
                cin>>obj;
                Constancia.Enqueue(obj);
                break;
            case 2:
                if(!Constancia.vacia()) {
                    obj=Constancia.Front();
                    Constancia.Dequeue();
                    cout<<"\n\nConstancia del alumno:\n";
                    cout<<obj<<endl;
                    }
                else {
                    cout<<"\nLa cola esta vacia\n";
                    }
                break;
            case 3:
                break;
            }
        cout<<"\n\n\n";
        }
    while(opc!=3);
    return 0;
    }

int menu() {
    int opc;
    cout<<"MENU\n"
        <<"1-Dar de Alta un alumno: \n"
        <<"2-Crear una constancia: \n"
        <<"3-Salir: \n"
        <<"Elige una opcion: \t";
    cin>>opc;
    return opc;
    }

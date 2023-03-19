#include <iostream>
#include "Student.h"

#define TAM 50

using namespace std;

template<class T>
class Cola{
private:
    T datos[TAM];
    int ult;
    bool inserta(T , int);
    bool elimina(int);
    T recupera(int)const;
    int primero()const;
    int ultimo()const;
public:
    Cola();
    bool vacia()const;
    bool llena()const;
    bool  Queue( T );
    bool Dequeue();
    T Front()const;
};
template< class T>
Cola<T>::Cola() : ult( -1 ){};

template<class T>
T Cola<T>::Front()const{
    T x=datos[primero()];
    return x;
}

template<class T>
bool Cola<T>::Dequeue(){
    if(vacia()){
        return false;
    }
    else{
        elimina(primero());
    }
    return true;
}

template<class T>
bool Cola<T>::Queue(T elem){
    if(llena()){
        return false;
    }
    if(vacia()){
        inserta(elem,0);
    }
    else{
        inserta(elem, ultimo()+1);
    }
    return true;
}


template<class T>
bool Cola<T>::vacia()const{
    return ult==-1;
}

template<class T>
bool Cola<T>::llena()const{
    return ult==TAM-1;
}

template<class T>
bool Cola<T>::inserta(T elem, int pos){
    if(llena() || pos<0 || pos>ult+1){
        std::cout<<"\n No se pudo insertar";
        return false;
    }
    int i=ult+1;
    while(i>pos){
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return true;
}

template<class T>
bool Cola<T>::elimina(int pos){
    if(vacia() || pos<0 || pos>ult){
        std::cout<<"\n No se pudo eliminar";
        return false;
    }
    int i=pos;
    while(i<ult){
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return true;
}

template<class T>
T Cola<T>::recupera(int pos)const{
    if(vacia() || pos<0 || pos>ult-1){
        std::cout<<"\n Insuficiencia de datos";

        //Manejar exceptions
    }
    else{
       return datos[pos];
    }
}

template<class T>
int Cola<T>::primero()const{
    if(vacia()){
       return -1;
    }
    return 0;
}

template<class T>
int Cola<T>::ultimo()const{
    if(vacia()){
       return -1;
    }
    return ult;
}

int main(){
    Student myStudent;
    Name myName;
    Date myDate;
    string myStr;
    char opc;
    Cola<Student>myCola;


    do{
        cout << "codigo: ";
        getline(cin, myStr);
        myStudent.setCode(myStr);

        cout << "Apellido: ";
        getline(cin, myStr);
        myName.setLast(myStr);

        cout << "Nombre: ";
        getline(cin, myStr);
        myName.setFirst(myStr);

        myStudent.setName(myName);

        cout << "Fecha de nacimiento (AAAA/MM/DD):";
        getline(cin, myStr, '/');
        myDate.setYear(atoi(myStr.c_str()));
        getline(cin, myStr, '/');
        myDate.setMonth(atoi(myStr.c_str()));
        getline(cin, myStr, '/');
        myDate.setDay(atoi(myStr.c_str()));

        myStudent.setBirthDate(myDate);

        cout << "carrera:";
        getline(cin, myStr);
        myStudent.setCareer(myStr);

        cout << "Fecha de ingreso (AAAA/MM/DD):";
        getline(cin, myStr, '/');
        myDate.setYear(atoi(myStr.c_str()));
        getline(cin, myStr, '/');
        myDate.setMonth(atoi(myStr.c_str()));
        getline(cin, myStr, '/');
        myDate.setDay(atoi(myStr.c_str()));

        myStudent.setStartDate(myDate);

        cout << "promedio:";
        getline(cin, myStr);
        myStudent.setGrade(atof(myStr.c_str()));

        myCola().Queue(myStudent);

        cout << "insertar otro? (s/n):";
        cin >> opc;
        cin.ignore();
    }
    while(opc == 's');

    cout << endl << endl;

    if(!myCola().vacia()){
        cout << "siguiente en la Cola: " << endl;
        cout << myCola().Front() << endl;
    }

    cout << endl << endl;
}

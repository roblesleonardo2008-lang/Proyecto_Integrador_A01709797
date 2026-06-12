

#ifndef PROYECTO_INTEGRADOR_A01709797_SISTEMA-VEHICULOS_H
#define PROYECTO_INTEGRADOR_A01709797_SISTEMA-VEHICULOS_H
//Leonardo Robles Bueckmann
//A01709797
//TC1030.301
    
#include "iostream"
using namespace std;

class Vehiculos{ //Declarando la lase abstracta vehiculos
protected:
    string modelo,placas;
    int anio,tanque,eficienciaL; //los atributos que las clases hijas tendran
public:
    Vehiculos(string modelo,string placas,int anio,int tanque, int efficienciaL);

    //Metodos abstracto y virtuales que seran sobrescritos en las hijas, se usa la palabre clave virtual para dejar saber
    //al programa que las clases hijas van asobrescibir dichos metodos
    virtual void MostrarInfo(int desechable);
    virtual float CalcularImpuesto() = 0;
    virtual float CalcularMantenimiento(int AnioA) = 0;
    bool operator==(Vehiculos& otro); //metodo para sobrecargar el operador == cuando se datos tipo vehiculos
    string getPlacas(); //getters
    string getModelo();
    int getAnio();
};
Vehiculos:: Vehiculos(string modelo,string placas,int anio,int tanque, int eficienciaL){
    this->modelo = modelo;
    this->placas = placas;
    this->anio = anio;
    this->tanque = tanque;
    this->eficienciaL = eficienciaL;
}; //aunque vehiculos sea abstracta tiene un constructor para incializar los atributos de las clases hijas

void Vehiculos::MostrarInfo(int desechable){
    if (desechable == 1){
        cout<< " es un ";
    }
    if (desechable ==2){
        cout<< " es una ";
    }
    cout<<modelo<<" con las placas "<<placas<<" del año "<<anio;
}; //Definiendo la función que luego sera sobrescrita y adaptada

bool Vehiculos :: operator==(Vehiculos& otro){
    if (this->modelo==otro.modelo and this->anio == otro.anio){
        return true;
    }
    else{
        return false;
    }
} //Esta función esta sobrecargando el operador == para que sea capaz de comparar el año y modelo de un vehiculo

string Vehiculos::getPlacas(){
    return placas;
}
string Vehiculos::getModelo(){
    return modelo;
}
int Vehiculos :: getAnio(){
    return anio;
}


class Carro: public Vehiculos{ //Declarando la clase hija Carro que hereda de vehiculos
private:
    string carroceria; //Atributos particulares de la clase hija
    int puertas;
    bool tieneAire;
public:
    Carro(string modelo, string placas, int anio, int tanque, int efficienciaL,string carroceria, int puertas,bool tieneAire);

    void MostrarInfo (int desechable) ;
    float CalcularImpuesto() ;
    float CalcularMantenimiento(int AnioA) ;
    //metodos heredado del padre que seran sobrescritos
};

Carro::Carro(string modelo, string placas, int anio, int tanque, int eficienciaL,string carroceria, int puertas,bool tieneAire)
        : Vehiculos(modelo,placas,anio,tanque,eficienciaL){
    this->carroceria=carroceria;
    this->puertas=puertas;
    this->tieneAire=tieneAire;
}//El constructor de la clase hija invoca en su lista de inicialización al constructor
//de la clase padre para inicializar los atributos heredados y luego los propios.

float Carro:: CalcularImpuesto(){
    float impuesto = 1000;
    float AnioI = anio;
    if (AnioI >= 2020){
        impuesto += (AnioI - 2026) * 100;
    }
    return impuesto;
}//polimorfismo, el metodo del padre es sobrescrito y sera llamado con punteros

float Carro:: CalcularMantenimiento(int AnioA){
    float costo = 1000;
    float puertasM = puertas;
    if (0<= anio - AnioA or anio - AnioA  < 5 ){
        costo += 200 * puertasM;
    }
    if (5<= anio - AnioA or anio - AnioA  < 10 ){
        costo += 300 * puertasM;
    }
    if (10<= anio - AnioA){
        costo += 500 * puertasM;
    }
    if (tieneAire == true){
        costo += 200;
    }
    return costo;
} //polimorfismo, el metodo del padre es sobrescrito y sera llamado con punteros

void Carro:: MostrarInfo(int desechable){
    cout<<"El carro ";
    Vehiculos::MostrarInfo(desechable);
    cout <<" ,tiene una carroceria tipo "<<carroceria<<" con "<<puertas<<" puertas y "<<endl;
} //polimorfismo, primero se llama al codigo en el metodo del padre y luego se
// ejecuta el codgio de la hija


class Moto: public Vehiculos{ //Declarando la clase hija moto que hereda de vehiculos
private:
    string tipoCadena,manubrio,modalidad; //Atributos particulares de la clase hija
    bool sidecar;
public:
    Moto(string modelo, string placas, int anio, int tanque, int efficienciaL,string tipoCadena,string manubrio,string modalidad,bool sidecar);

    //metodos heredado del padre que seran sobrescritos
    void MostrarInfo (int desechable) ;
    float CalcularImpuesto() ;
    float CalcularMantenimiento(int AnioA) ;

};
Moto::Moto(string modelo, string placas, int anio, int tanque, int efficienciaL,string tipoCadena,string manubrio,string modalidad,bool sidecar)
        : Vehiculos(modelo,placas,anio,tanque,eficienciaL){
    this->tipoCadena=tipoCadena;
    this->manubrio=manubrio;
    this->modalidad=modalidad;
    this->sidecar=sidecar;
}//Instanciando la clase moto, primero se iniciliza la lista de atributos de vehiculos y luego los de la clase hija

void Moto:: MostrarInfo(int desechable){
    cout<<"La moto ";
    Vehiculos::MostrarInfo(desechable);
    cout <<" , de tipo "<<modalidad<<" tiene una cadena "<<tipoCadena<<" con un manubrio "<<manubrio;
    if (sidecar == true){
        cout<<" y tiene un sidecar"<<endl;
    }
    else{
        cout<<" y no tiene un sidecar"<<endl;
    }
} //polimorfismo, llama al codigo escrito en la clase padre antes de sobrescribir la funcion con su propio codigo

float Moto:: CalcularImpuesto(){
    float impuesto = 600;
    float AnioI = anio;
    if (AnioI >= 2015){
        impuesto += (AnioI - 2026) * 75;
    }
    if (sidecar == true){
        impuesto += 400;
    }
    return impuesto;
} //polimorfismo, el metodo del padre es sobrescrito
float Moto:: CalcularMantenimiento(int AnioA){
    float costo = 1000;
    if (tipoCadena == "Reforzada" or tipoCadena == "O-Ring"){
        costo += 300;
    }
    if (tipoCadena == "Racing" or tipoCadena == "Directa"){
        costo += 600;
    }
    if (sidecar == true){
        costo += 800;
    }
    return costo;
} //polimorfismo, el metodo del padre es sobrescrito


class Persona{//inicia la clase persona que se usara como un tipo de dato en la clase Vender
protected:
    string nombre,RFC,domicilio; //atributos que tendran los objetos de la clase persona
    int ID;
public:
    Persona(string nombre,string RFC,string domicilio,int ID); //constructor
    string getNombre(); //getters
    string getRFC();
    string getDomicilio();
    int getID();
};
Persona::Persona(string nombre,string RFC,string domicilio,int ID) {
    this->nombre = nombre;
    this->RFC = RFC;
    this->domicilio = domicilio;
    this->ID = ID;
}//se crea el objeto de la clase Persona como un objeto regular
string Persona:: getNombre(){
    return nombre;
}
string Persona :: getRFC(){
    return RFC;
}
string Persona::getDomicilio(){
    return domicilio;
}
int Persona::getID(){
    return ID;
}

class Vender{//Inicializando la clase vender 
private:
    string placas,modelo,duenio; //atributos de la clase
    float precio;

    //Los siguientes atributos son punteros de objetos de la clase persona,
    // se usan punteros para no tener que copiar los bjetos persona cada vez que se usen
    Persona* vendedor;
    Persona* cliente;
public:
    Vender(float precio,string duenio,string placas,Persona* vendedor,Persona* cliente); //constructor
    void Facturar(); //metodos y getters
    int getPrecio();
    string getPlacas_();
};

Vender::Vender(float precio,string duenio,string placas,Persona* vendedor,Persona* cliente){
    this->precio = precio;
    this->duenio = duenio;
    this->placas = placas;
    this->vendedor = vendedor;
    this->cliente = cliente;
}//constructor, especifica que vendedor y cliente seran pasados a traves de punteros

void Vender::Facturar(){
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"-------------------    FACTURA     ------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"Monto pagado : "<<precio<<endl;
    cout<<"Placas del vehiculo : "<<placas<<endl;
    cout<<"Dueño actual : "<<duenio<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"Datos del vendedor"<<endl;
    cout<<"Nombre : "<<vendedor->getNombre()<<endl;
    cout<<"ID : "<<vendedor->getID()<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"Datos del comprador"<<endl;
    cout<<"Nombre : "<<cliente->getNombre()<<"  RFC : "<<cliente->getRFC()<<endl;
    cout<<"Domicilio : "<<cliente->getDomicilio()<<endl;
}//metodo para crear la factura, como pase vendedor y cliente como punteros accedo a sus datos usando"->" y los getters
int Vender:: getPrecio(){
    return precio;
}
string Vender::getPlacas_(){
    return placas;
}
#endif //PROYECTO_INTEGRADOR_A01709797_SISTEMA-VEHICULOS_H



#ifndef PROYECTO_INTEGRADOR_A01709797_AVANCE4_H
#define PROYECTO_INTEGRADOR_A01709797_AVANCE4_H

#include "iostream"
using namespace std;

class Vehiculos{
protected:
    string modelo,placas;
    int anio,tanque,eficienciaL;
public:
    Vehiculos(string modelo,string placas,int anio,int tanque, int efficienciaL);
    virtual void MostrarInfo(int desechable);
    virtual float CalcularImpuesto() = 0;
    virtual float CalcularMantenimiento(int anioA) = 0;
    bool operator==(const Vehiculos& otro);
    string getPlacas();
    string getModelo();
    virtual ~Vehiculos(){};
};

Vehiculos:: Vehiculos(string modelo,string placas,int anio,int tanque, int eficienciaL){
    this->Modelo = modelo;
    this->Placas = placas;
    this->Anio = anio;
    this->Tanque = tanque;
    this->EficienciaL = eficienciaL;
};

void Vehiculos::MostrarInfo(int desechable){
    if (desechable == 1){
        cout<< " es un ";
    }
    if (desechable ==2){
        cout<< " es una ";
    }
    cout<<Modelo<<" con las placas "<<Placas<<" del año "<<Anio;
};

bool Vehiculos :: operator==(const Vehiculos& otro){
    if (this->anio == otro.anio && this->modelo == otro.modelo){
        return true;
    }
    else{
        return false;
    }
}

string Vehiculos::getPlacas(){
    return placas;
}
string Vehiculos::getModelo(){
    return modelo;
}

//incia carro
class Carro: public Vehiculos{
private:
    string carroceria;
    int puertas;
    bool tieneAire;
public:
    Carro(string modelo, string placas, int anio, int tanque, int efficienciaL,string carroceria, int puertas,bool tieneAire);
    void MostrarInfo (int desechable) ;
    float CalcularImpuesto() ;
    float CalcularMantenimiento(int anioA) ;
};

Carro::Carro(string modelo, string placas, int anio, int tanque, int efficienciaL,string carroceria, int puertas,bool tieneAire)
        : Vehiculos(modelo,placas,anio,tanque,eficienciaL){
    this->carroceria=carroceria;
    this->puertas=puertas;
    this->tieneAire=tieneAire;
}

float Carro:: CalcularImpuesto(){
    float impuesto = 1000;
    float anioI = anio;
    if (anioI >= 2020){
        impuesto += (anioI - 2026) * 100;
    }
    return impuesto;
}
float Carro:: CalcularMantenimiento(int anioA){
    float costo = 1000;
    float puertasM = puertas;
    if (0<= anio - anioA ||anio - anioA  < 5 ){
        costo += 200 * puertasM;
    }
    if (5<= anio - anioA ||anio - anioA  < 10 ){
        costo += 300 * puertasM;
    }
    if (10<= anio - anioA){
        costo += 500 * puertasM;
    }
    if (tieneAire == true){
        costo += 200;
    }
    return costo;
}

void Carro:: MostrarInfo(int desechable){
    cout<<"El carro";
    Vehiculos::MostrarInfo(desechable);
    cout <<" ,tiene una carroceria tipo "<<carroceria<<" con "<<puertas<<" puertas y "<<endl;
}

//inicia moto
class Moto: public Vehiculos{
private:
    string tipoCadena,manubrio,modalidad;
    bool sidecar;
public:
    Moto(string modelo, string placas, int anio, int tanque, int efficienciaL,string tipoCadena,string manubrio,string modalidad,bool sidecar);
    void MostrarInfo (int desechable) ;
    float CalcularImpuesto() ;
    float CalcularMantenimiento(int anioA) ;

};
Moto::Moto(string modelo, string placas, int anio, int tanque, int efficienciaL,string tipoCadena,string manubrio,string modalidad,bool sidecar)
        : Vehiculos(modelo,placas,anio,tanque,eficienciaL){
    this->TipoCadena=tipoCadena;
    this->Manubrio=manubrio;
    this->Modalidad=modalidad;
    this->Sidecar=sidecar;
};

void Moto:: MostrarInfo(int desechable){
    cout<<"La moto";
    Vehiculos::MostrarInfo(desechable);
    cout <<" , de tipo "<<modalidad<<" tiene una cadena "<<tipoCadena<<" con un manubrio "<<manubrio;
    if (sidecar == true){
        cout<<" y tiene un sidecar"<<endl;
    }
    else{
        cout<<" y no tiene un sidecar"<<endl;
    }
}

float Moto:: CalcularImpuesto(){
    float impuesto = 600;
    float anioI = anio;
    if (anioI >= 2015){
        impuesto += (anioI - 2026) * 75;
    }
    if (sidecar == true){
        impuesto += 400;
    }
    return impuesto;
}
float Moto:: CalcularMantenimiento(int anioA){
    float costo = 1000;
    if (tipoCadena == "Reforzada" || tipoCadena == "O-Ring"){
        costo += 300;
    }
    if (tipoCadena == "Racing" || tipoCadena == "Directa"){
        costo += 600;
    }
    if (sidecar == true){
        costo += 800;
    }
    return costo;
}

//inicia Personas
class Persona{
protected:
    string nombre,RFC,domicilio;
    int ID;
public:
    Persona(string nombre,string RFC,string domicilio,int ID);
    string getNombre();
    string getRFC();
    string getDomicilio();
    int getID();
};
Persona::Persona(string nombre,string RFC,string domicilio,int ID) {
    this->Nombre = nombre;
    this->RFC = RFC;
    this->Domicilio = domicilio;
    this->ID = ID;
}
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

class Vender : public Persona{
private:
    string placas,modelo,duenio;
    Persona* vendedor;
    Persona* cliente;
    float precio;
public:
    Vender(float precio,string duenio,string placas,Persona* vendedor,Persona* cliente);
    void Facturar();
    void TransferirDuenio();
};

Vender::Vender(float precio,string duenio,string placas,Persona* vendedor,Persona* cliente): Persona(Nombre,RFC,Domicilio,ID){
    this->precio = precio;
    this->duenio = duenio;
    this->placas = placas;
    this->vendedor = vendedor;
    this->cliente = cliente;
};
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
    cout<<"Nombre : "<<cliente->getNombre()<<"RFC : "<<cliente->getRFC()<<endl;
    cout<<"Domicilio : "<<cliente->getDomicilio()<<endl;
}
void Vender::TransferirDuenio(){
    duenio = cliente->getNombre();
}

#endif //PROYECTO_INTEGRADOR_A01709797_AVANCE4_H



#ifndef PROYECTO_INTEGRADOR_A01709797_AVANCE4_H
#define PROYECTO_INTEGRADOR_A01709797_AVANCE4_H

#include "iostream"
using namespace std;

class Vehiculos{
protected:
    string Modelo,Placas;
    int Anio,Tanque,EficienciaL;
public:
    Vehiculos(string Modelo,string Placas,int Anio,int Tanque, int EfficienciaL);
    virtual void MostrarInfo(int desechable);
    virtual float CalcularImpuesto() = 0;
    virtual float CalcularMantenimiento(int AnioA) = 0;
    bool operator==(const Vehiculos& otro);
    string getPlacas();
    string getModelo();
    virtual ~Vehiculos(){};
};

Vehiculos:: Vehiculos(string Modelo,string Placas,int Anio,int Tanque, int EficienciaL){
    this->Modelo = Modelo;
    this->Placas = Placas;
    this->Anio = Anio;
    this->Tanque = Tanque;
    this->EficienciaL = EficienciaL;
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
    if (this->Anio == otro.Anio && this->Modelo == otro.Modelo){
        return true;
    }
    else{
        return false;
    }
}

string Vehiculos::getPlacas(){
    return Placas;
}
string Vehiculos::getModelo(){
    return Modelo;
}

//incia carro
class Carro: public Vehiculos{
private:
    string carroceria;
    int puertas;
    bool tieneAire;
public:
    Carro(string Modelo, string Placas, int Anio, int Tanque, int EfficienciaL,string carroceria, int puertas,bool tieneAire);
    void MostrarInfo (int desechable) ;
    float CalcularImpuesto() ;
    float CalcularMantenimiento(int AnioA) ;
};

Carro::Carro(string Modelo, string Placas, int Anio, int Tanque, int EfficienciaL,string carroceria, int puertas,bool tieneAire)
        : Vehiculos(Modelo,Placas,Anio,Tanque,EficienciaL){
    this->carroceria=carroceria;
    this->puertas=puertas;
    this->tieneAire=tieneAire;
}

float Carro:: CalcularImpuesto(){
    float impuesto = 1000;
    float AnioI = Anio;
    if (AnioI >= 2020){
        impuesto += (AnioI - 2026) * 100;
    }
    return impuesto;
}
float Carro:: CalcularMantenimiento(int AnioA){
    float costo = 1000;
    float puertasM = puertas;
    if (0<= Anio - AnioA ||Anio - AnioA  < 5 ){
        costo += 200 * puertasM;
    }
    if (5<= Anio - AnioA ||Anio - AnioA  < 10 ){
        costo += 300 * puertasM;
    }
    if (10<= Anio - AnioA){
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
    string TipoCadena,Manubrio,Modalidad;
    bool Sidecar;
public:
    Moto(string Modelo, string Placas, int Anio, int Tanque, int EfficienciaL,string TipoCadena,string Manubrio,string Modalidad,bool Sidecar);
    void MostrarInfo (int desechable) ;
    float CalcularImpuesto() ;
    float CalcularMantenimiento(int AnioA) ;

};
Moto::Moto(string Modelo, string Placas, int Anio, int Tanque, int EfficienciaL,string TipoCadena,string Manubrio,string Modalidad,bool Sidecar)
        : Vehiculos(Modelo,Placas,Anio,Tanque,EficienciaL){
    this->TipoCadena=TipoCadena;
    this->Manubrio=Manubrio;
    this->Modalidad=Modalidad;
    this->Sidecar=Sidecar;
};

void Moto:: MostrarInfo(int desechable){
    cout<<"La moto";
    Vehiculos::MostrarInfo(desechable);
    cout <<" , de tipo "<<Modalidad<<" tiene una cadena "<<TipoCadena<<" con un manubrio "<<Manubrio;
    if (Sidecar == true){
        cout<<" y tiene un sidecar"<<endl;
    }
    else{
        cout<<" y no tiene un sidecar"<<endl;
    }
}

float Moto:: CalcularImpuesto(){
    float impuesto = 600;
    float AnioI = Anio;
    if (AnioI >= 2015){
        impuesto += (AnioI - 2026) * 75;
    }
    if (Sidecar == true){
        impuesto += 400;
    }
    return impuesto;
}
float Moto:: CalcularMantenimiento(int AnioA){
    float costo = 1000;
    if (TipoCadena == "Reforzada" || TipoCadena == "O-Ring"){
        costo += 300;
    }
    if (TipoCadena == "Racing" || TipoCadena == "Directa"){
        costo += 600;
    }
    if (Sidecar == true){
        costo += 800;
    }
    return costo;
}

//inicia Personas
class Persona{
protected:
    string Nombre,RFC,Domicilio;
    int ID;
public:
    Persona(string Nombre,string RFC,string Domicilio,int ID);
    string getNombre();
    string getRFC();
    string getDomicilio();
    int getID();
};
Persona::Persona(string Nombre,string RFC,string Domicilio,int ID) {
    this->Nombre = Nombre;
    this->RFC = RFC;
    this->Domicilio = Domicilio;
    this->ID = ID;
}
string Persona:: getNombre(){
    return Nombre;
}
string Persona :: getRFC(){
    return RFC;
}
string Persona::getDomicilio(){
    return Domicilio;
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

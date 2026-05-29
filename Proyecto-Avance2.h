

#ifndef PROYECTO_AVANCE2_H
#define PROYECTO_AVANCE2_H

#include "iostream"
using namespace std;

class Vehiculos{
protected:
    string Modelo,Placas;
    int Anio,Tanque,EficienciaL;
public:
    Vehiculos(string Mo,string Pl,int An,int Ta, int Ef);
    virtual void MostrarInfo() = 0;
    string getPlacas();
    string getModelo();
    int getAnio();
};

Vehiculos:: Vehiculos(string Mo,string Pl,int An,int Ta, int Ef){
    Modelo = Mo;
    Placas = Pl;
    Anio = An;
    Tanque = Ta;
    EficienciaL = Ef;
};

void Vehiculos::MostrarInfo(){
    cout<< "Es un "<<Modelo<<" con las placas "<<Placas<<" del año "<<Anio<<endl;
};
string Vehiculos::getPlacas(){
    return Placas;
}
string Vehiculos::getModelo(){
    return Modelo;
}
int Vehiculos::getAnio(){
    return Anio;
}

class Moto: public Vehiculos{
private:
    string TipoCadena,Manubrio,Modalidad;
    bool Sidecar;
public:
    Moto();
    Moto(string TC,string MA,string MD,bool SD, Vehiculos &m);
    int CalcDistanciaK(int EficieciaL,int Tanque,string TipoCadena);
    void SetSidecar(bool NewSidecar);
    void MostrarInfo () override;

};

Moto::Moto(string TC,string MA,string MD,bool SD,Vehiculos &m )
: Vehiculos(m){
    TipoCadena=TC;
    Manubrio=MA;
    Modalidad=MD;
    Sidecar=SD;
};

void Moto:: MostrarInfo(){
    cout<<"La moto"<<endl;
    Vehiculos::MostrarInfo();
    cout <<"Es "<<Modalidad<<" tiene una cadena "<<TipoCadena<<" con un manubrio ";
    if (Sidecar == true){
        cout<<" y tiene un sidecar"<<endl;
    }
    else{
        cout<<" y no tiene un sidecar"<<endl;
    }
}

int Moto::CalcDistanciaK(int EficieciaL, int Tanque, string TipoCadena) {
    if (TipoCadena == "Reforzada" || TipoCadena == "O-Ring") {
        cout <<"La moto recorrera una distancia máxima de "<< Tanque*EficienciaL*0.95<<"Km"<<endl;
    } else if (TipoCadena == "Racing" || TipoCadena == "Directa") {
        cout <<"La moto recorrera una distancia máxima de "<< Tanque*EficienciaL*1.05<<"Km"<<endl;
    }
}

void Moto::SetSidecar(bool NewSidecar) {
    Sidecar = NewSidecar;
}

class Carro: public Vehiculos{
private:
    string Carroceria;
    int BolsasAire,Puertas;
    bool AireAcondicionado;
public:
    Carro();
    Carro(string CA,int BA,int PU,bool AA,Vehiculos &c);
    int CalcDistanciaK(int EficienciaL, int Tanque, bool AireAcondicionado);
    void BloquearPuertas();
    void SetAire(bool EstadoAire);
    void MostrarInfo () override;
};

Carro:: Carro(string CA,int BA,int PU,bool AA,Vehiculos &c)
:Vehiculos(c){
    Carroceria=CA;
    BolsasAire=BA;
    Puertas=PU;
    AireAcondicionado=AA;
}

int Carro::CalcDistanciaK(int EficieciaL, int Tanque, bool AireAcondicionado){
    if (AireAcondicionado == true) {
        cout <<"El carro recorrera una distancia máxima de "<< Tanque*EficienciaL*0.88<<"Km"<<endl;
    }
    else{
        cout <<"El carro recorrera una distancia máxima de "<< Tanque*EficienciaL*1<<"Km"<<endl;
    }
}

void Carro::BloquearPuertas() {
    cout <<"Se bloquearon las puertas"<<endl;
}

void Carro ::SetAire(bool EstadoAire){
    AireAcondicionado = EstadoAire;
}

void Carro:: MostrarInfo(){
    cout<<"El carro"<<endl;
    Vehiculos::MostrarInfo();
    cout <<"Tiene una carroceria tipo "<<Carroceria<<" con "<<Puertas<<" puertas y "<<BolsasAire<<" bolsas de aire"<<endl;
}

class Persona{
protected:
    string Nombre,RFC,Domicilio;
    int ID;
public:
    Persona();
    Persona(string Nombre,string RFC,string Domicilio,int ID);
    string getNombre();
    string getRFC();
    string getDomicilio();
    int getID();
};
Persona::Persona(string NO,string RF,string DO,int ID) {
    Nombre = NO;
    RFC = RF;
    Domicilio = DO;
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
    string placas,modelo,Duenio;
    Persona Cliente,Vendedor;
    float Precio;
public:
    Vender(float Precio,string Duenio,string placas,Persona cliente, Persona vendedor);
    void Facturar(Persona Cliente,Persona Vendedor,float Precio,string placas,string Duenio);
    void TransferirDuenio(Persona Cliente);
};

Vender::Vender(float PR,string DU,string pL, Persona CL, Persona VE){
    Precio = PR;
    Duenio = DU;
    placas = pL;
    Cliente = CL;
    Vendedor = VE;
};
void Vender::Facturar(Persona Cliente,Persona Vendedor,float Precio,string placas,string Duenio){
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"-------------------    FACTURA     ------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"Monto pagado : "<<Precio<<endl;
    cout<<"Placas del vehiculo : "<<placas<<endl;
    cout<<"Dueño actual : "<<Duenio<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"Datos del vendedor"<<endl;
    cout<<"Nombre : "<<Vendedor.getNombre()<<endl;
    cout<<"ID : "<<Vendedor.getID()<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"Datos del comprador"<<endl;
    cout<<"Nombre : "<<Cliente.getNombre()<<"RFC : "<<Cliente.getRFC()<<endl;
    cout<<"Domicilio : "<<Cliente.getDomicilio()<<endl;
}
void Vender::TransferirDuenio(Persona Cliente){
    Duenio = Cliente.getNombre();
}



#endif //PROYECTO_AVANCE2_H

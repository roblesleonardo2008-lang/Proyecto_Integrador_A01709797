

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

class Moto: public Vehiculos{
private:
    string TipoCadena,Manubrio,Modalidad;
    bool Sidecar;
public:
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

#endif //PROYECTO_AVANCE2_H

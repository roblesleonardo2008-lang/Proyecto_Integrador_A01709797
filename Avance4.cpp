#include<iostream>
#include<vector>
#include"Avance4.h"
using namespace std;

string mejorVerdadero(bool v){
    if (v == 1){return "verdadero";}
    else{ return "falso";}
}

int main(){
    int AnioA = 2026;
    Vehiculos* carro1 = new Carro("onix","UPU-987-G",2023,50,15,"sedan",4,true);
    Vehiculos* carro2 = new Carro("cr-v", "GHI-456-A", 2024, 55, 12, "suv", 5, true);
    Vehiculos* carro3 = new Carro("march", "XYZ-123-B", 2021, 41, 18, "hatchback", 3, false);
    Vehiculos* carro4 = new Carro("hilux", "JKL-890-C", 2023, 80, 10, "pickup", 4, true);
    Vehiculos* carro5 = new Carro("mustang", "ABC-789-D", 2025, 60, 8, "deportivo", 2, true);
    Vehiculos* carro6 = new Carro("onix", "WER-654-F", 2023, 45, 17, "hatchback", 5, false);

    Vehiculos* moto1 = new Moto("ninja-400", "MTR-123-A", 2024, 14, 25, "o-ring", "deportivo", "pista", false);
    Vehiculos* moto2 = new Moto("italika-ft150", "BCX-456-B", 2022, 12, 32, "estandar", "recto", "trabajo", false);
    Vehiculos* moto3 = new Moto("sportster-883", "HD-789-C", 2020, 17, 18, "correa", "colgante", "chopper", false);
    Vehiculos* moto4 = new Moto("ural-gear-up", "RUS-012-D", 2025, 19, 14, "cardan", "scrambler", "aventura", true);

    cout<<mejorVerdadero(*carro1==*carro2)<<endl;
    cout<<mejorVerdadero(*carro1==*carro6)<<endl;
    carro3->MostrarInfo(1);
    cout<<"el "<<carro4->getModelo()<<" con la placa "<<carro4->getPlacas()<<" pagara "<<carro4->CalcularImpuesto()<<"$ de impuesto"<<endl;
    cout<<"el mantenimiento del "<<carro5->getModelo()<<" con la placa "<<carro5->getPlacas()<< " será de "<<carro5->CalcularMantenimiento(AnioA)<<"$"<<endl;

    moto1->MostrarInfo(2);
    cout<<"El impuesto de la "<<moto2->getModelo()<<" sera de "<<moto2->CalcularImpuesto()<<"$"<<endl;
    cout<<"el mantenimiento de la "<<moto3->getModelo()<<" con la placa "<<moto3->getPlacas()<< " será de "<<moto3->CalcularMantenimiento(AnioA)<<"$"<<endl;

    Persona cliente ("Carlos Mendoza", "MEDC950315HDF", "Av. Reforma 123, QRO", 4501);
    Persona vendedor ("Sofia Rodriguez", "RODS881122TY7", "Calle Tercera 45, QRO", 1022);
    cout<<endl;
    Vender venta_moto4(385000,"Agencia",moto4->getPlacas(),&vendedor,&cliente);
    venta_moto4.Facturar();
    venta_moto4.TransferirDuenio();

    delete carro1;
    delete carro2;
    delete carro3;
    delete carro4;
    delete carro5;
    delete carro6;
    delete moto1;
    delete moto2;
    delete moto3;
    delete moto4;
    return 0;

}


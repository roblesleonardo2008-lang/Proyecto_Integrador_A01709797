#include<iostream>
#include<vector>
#include"Avance4.h"
using namespace std;


void BaseCarros(vector<Vehiculos*>& CarrosV){
    Vehiculos* carro1 = new Carro("onix","UPU-987-G",2023,50,15,"sedan",4,true);
    Vehiculos* carro2 = new Carro("cr-v", "GHI-456-A", 2024, 55, 12, "suv", 5, true);
    Vehiculos* carro3 = new Carro("march", "XYZ-123-B", 2021, 41, 18, "hatchback", 3, false);
    Vehiculos* carro4 = new Carro("hilux", "JKL-890-C", 2023, 80, 10, "pickup", 4, true);
    Vehiculos* carro5 = new Carro("mustang", "ABC-789-D", 2025, 60, 8, "deportivo", 2, true);
    Vehiculos* carro6 = new Carro("onix", "WER-654-F", 2023, 45, 17, "hatchback", 5, false);
    Vehiculos* carrosA[] = {carro1,carro2,carro3,carro4,carro5,carro6};
    CarrosV.reserve(6);
    for (int i=0; i<6; i++){
        CarrosV.push_back(carrosA[i]);
    }
}
void BaseMotos(vector<Vehiculos*>& MotosV){
    Vehiculos* moto1 = new Moto("ninja-400", "MTR-123-A", 2024, 14, 25, "o-ring", "deportivo", "pista", false);
    Vehiculos* moto2 = new Moto("italika-ft150", "BCX-456-B", 2022, 12, 32, "estandar", "recto", "trabajo", false);
    Vehiculos* moto3 = new Moto("sportster-883", "HD-789-C", 2020, 17, 18, "correa", "colgante", "chopper", false);
    Vehiculos* moto4 = new Moto("ural-gear-up", "RUS-012-D", 2025, 19, 14, "cardan", "scrambler", "aventura", true);
    Vehiculos* moto5 = new Moto("ninja-400", "KWA-440-Z", 2024, 14, 25, "o-ring", "deportivo", "pista", false);
    Vehiculos* moto6 = new Moto("italika-ft150", "MEX-550-Y", 2021, 12, 32, "estandar", "recto", "trabajo", false);
    Vehiculos* carrosA[] = {moto1,moto2,moto3,moto4,moto5,moto6};
    MotosV.reserve(6);
    for (int i=0; i<6; i++){
        MotosV.push_back(carrosA[i]);
    }
}
void BaseVendedor(vector<Persona*>& VendedorV){
    Persona* vendedor1= new Persona("Sofia Rodriguez", "RODS881122TY7", "", 1022);
    Persona* vendedor2 = new Persona("Alejandro Gomez", "GOMA910415H82", "", 1023);
    Persona* vendedor3 = new Persona("Mariana Fuentes", "FUMM950830DL1", "", 1024);
    Persona* vendedor4 = new Persona("Carlos Mendoza", "MECC8401026V4", "", 1025);
    Persona* vendedor5= new Persona("Elena Villarreal", "VIRE991211RE3", "", 1026);
    Persona* vendedoresA[] = {vendedor1,vendedor2,vendedor3,vendedor4,vendedor5};
    VendedorV.reserve(5);
    for(int i=0;i<5;i++){
        VendedorV.push_back(vendedoresA[i]);}
}
void BaseComprador(vector<Persona*>& CompradorV){
    Persona* cliente1 = new Persona ("Carlos Mendoza", "MEDC950315HDF", "Av. Reforma 123, QRO",0);
    Persona* cliente2 = new Persona  ("Lucia Hernandez", "HERL921005MDF", "Calle Corregidora 45, QRO",0);
    Persona* cliente3 = new Persona ("Fernando Ortiz", "ORTF890420HDF", "Blvd. Bernardo Quintana 802, QRO",0);
    Persona* cliente4 = new Persona ("Gabriela Silva", "SILG960711MDF", "Av. 5 de Febrero 1100, QRO",0);
    Persona* cliente5 = new Persona ("Ricardo Anaya", "ANAR940125HDF", "Alamos 3ra Seccion 215, QRO",0);
    Persona* compradorA[] = {cliente1,cliente2,cliente3,cliente4,cliente5};
    CompradorV.reserve(5);
    for(int i=0;i<5;i++){
        CompradorV.push_back(compradorA[i]);}
}
void BaseVentas(vector<Vender*>& VentasV,vector<Persona*>& CompradorV,vector<Persona*>& VendedorV){
    Vender* venta1 = new Vender(135000.00, "Carlos Mendoza", "KWA-440-Z", VendedorV[0], CompradorV[0]);
    Vender* venta2 = new Vender(24500.00, "Alejandro Gomez", "MEX-550-Y", VendedorV[1], CompradorV[3]);
    Vender* venta3 = new Vender(185000.00, "Sofia Rodriguez", "MTR-123-A", VendedorV[4], CompradorV[2]);
    Vender* VenderA[] = {venta1,venta2,venta3};
    VentasV.reserve(3);
    for(int i=0;i<3;i++){
        VentasV.push_back(VenderA[i]);}
}

void CrearCarros(vector<Vehiculos*>& CarrosV){
    string modelo,placas,carroceria;
    int anio,tanque,eficienciaL,puertas;
    bool aire;
    cout<<"Modelo: ";
    cin>>modelo;
    cout<<"Placas: ";
    cin>>placas;
    cout<<"Carroceria: ";
    cin>>carroceria;
    cout<<"Anio: ";
    cin>>anio;
    cout<<"Tanque: ";
    cin>>tanque;
    cout<<"EfficienciaL: ";
    cin>>eficienciaL;
    cout<<"Aire (si(1)/no(0)): ";
    cin>>aire;
    cout<<"puertas: ";
    cin>>puertas;
    Vehiculos* carro = new Carro(modelo,placas,anio,tanque,eficienciaL,carroceria,puertas,aire);
    CarrosV.push_back(carro);
    cout<<"carro anadido"<<endl;
}
void CrearMotos(vector<Vehiculos*>& MotosV){
    string modelo,placas,tipoCadena,modalidad,manubrio;
    int anio,tanque,eficienciaL;
    bool sidecar;
    cout<<"Modelo: ";
    cin>>modelo;
    cout<<"Placas: ";
    cin>>placas;
    cout<<"Tipo de Cadena: ";
    cin>>tipoCadena;
    cout<<"Modalidad: ";
    cin>>modalidad;
    cout<<"Manubrio: ";
    cin>>manubrio;
    cout<<"Anio: ";
    cin>>anio;
    cout<<"Tanque: ";
    cin>>tanque;
    cout<<"EfficienciaL: ";
    cin>>eficienciaL;
    cout<<"Sidecar (si(1)/no(0)): ";
    cin>>sidecar;
    Vehiculos* moto = new Moto(modelo,placas,anio,tanque,eficienciaL,tipoCadena,manubrio,modalidad,sidecar);
    MotosV.push_back(moto);
    cout<<"moto anadida"<<endl;
}

void EleccionVenta1(vector<Persona*>& CompradorV,vector<Persona*>& VendedorV,vector<Vender*>& VentasV){
    int precio,x1,x2,xi,xe;
    string duenio,placas,nombre_comprador,nombre_vendedor;
    cout<<"Precio del vehiculo: ";
    cin>>precio;
    cout<<"Dueño del vehiculo: ";
    cin>>duenio;
    cout<<"Placas del vehiculo: ";
    cin>>placas;
    while(true){
        cout<<"Nombre del comprador: ";
        cin>>ws;
        getline(cin,nombre_comprador);
        for(int i=0;i<CompradorV.size();i++){
            if(CompradorV[i]->getNombre()==nombre_comprador){
                x1 = 1;
                xi = i;
                break;}}
        if(x1==1){ break;}
        cout<<"No hay ningun comprador con ese nombre"<<endl;
    }
    while(true){
        cout<<"Nombre del vendedor: ";
        cin>>ws;
        getline(cin,nombre_vendedor);
        for(int i=0;i<VendedorV.size();i++){
            if(VendedorV[i]->getNombre()==nombre_vendedor){
                x2 = 1;
                xe = i;
                break;}}
        if(x2==1){ break;}
        cout<<"No hay ningun vendedor con ese nombre"<<endl;
    }
    Vender* venta=new Vender(precio,duenio,placas,VendedorV[xi],CompradorV[xi]);
    cout<<"Venta registrada"<<endl;
    VentasV.push_back(venta);
}
void EleccionVenta2(vector<Persona*>& CompradorV,vector<Persona*>& VendedorV){
    string eleccionPersona,nombre,RFC,domicilio;
    int ID;
    cout<<"¿Quieres anadir un nuevo vendedor(V) o comprador(C)?"<<endl;
    cin>>eleccionPersona;
    if(eleccionPersona=="V"){
        cout<<"Nombre del vendedor: ";
        cin >> ws;
        getline(cin,nombre);
        cout<<"RFC del vendedor: ";
        cin>>RFC;
        domicilio = "";
        cout<<"ID del vendedor: ";
        cin>>ID;
        Persona* vendedor = new Persona(nombre,RFC,domicilio,ID);
        VendedorV.push_back(vendedor);
        cout<<"Se ha anadido al vendedor"<<endl;
    }
    else if(eleccionPersona=="C") {
        cout << "Nombre del comprador: ";
        cin >> ws;
        getline(cin,nombre);
        cout << "RFC del comprador: ";
        cin >> RFC;
        cout << "Domicilio del comprador: ";
        cin >> ws;
        getline(cin,domicilio);
        Persona* comprador= new Persona(nombre, RFC, domicilio,0);
        CompradorV.push_back(comprador);
        cout<<"Se ha anadido al comprador"<<endl;
    }
}
void EleccionVenta3(vector<Vender*>& VentasV){
    string placasD;
    cout<<"Coloca las placas del vehiculo que quieres facturar"<<endl;
    cin>>placasD;
    for(int i=0;i<VentasV.size();i++){
        if(VentasV[i]->getPlacas_()==placasD){
            VentasV[i]->Facturar();
            break;}
        else{
            cout<<"no se encontro ningun vehiculo vendido con esas placas"<<endl;}
    }
}
void EleccionVenta4(vector<Persona*>& CompradorV,vector<Persona*>& VendedorV){
    string elegir;
    cout<<"Compradores(C) o Vendedores(V)"<<endl;
    cin>>elegir;
    if (elegir=="C"){
        cout<<"Imprimiendo nombres de los compradores"<<endl;
        for(int i=0;i<CompradorV.size();i++){
            cout<<CompradorV[i]->getNombre()<<endl;}
    }
    else if (elegir=="V"){
        cout<<"Imprimiendo nombres de los vendedores"<<endl;
        for(int i=0;i<VendedorV.size();i++){
            cout<<VendedorV[i]->getNombre()<<endl;}
    }
    else{
        cout<<"Opcion invalida"<<endl;}
}
void EleccionVenta5(vector<Vender*>& VentasV){
    cout<<"Imprimiendo las placas y el precio de los vehiculos vendidos"<<endl;
        for(int i =0;i<VentasV.size();i++){
            cout<<"Placas del vehiculo: "<<VentasV[i]->getPlacas_()<<" Vendido por: "<<VentasV[i]->getPrecio()<<endl;}
}


void Eleccion1(vector<Vehiculos*>& CarrosV,vector<Vehiculos*>& MotosV){
    string placaD;
    cout<<"Escriba la placa del vehiculo para ver su informacion, o C/M para ver la informacion de todos las carros/motos"<<endl;
    cin>>placaD;
    int completo = 0;
    if (placaD =="C"){
        for (int e=0;e<CarrosV.size();e++){
            CarrosV[e]->MostrarInfo(2026);}
        completo =1;}
    if(placaD == "M"){
        for (int e=0;e<MotosV.size();e++){
            MotosV[e]->MostrarInfo(2026);}
        completo =1;}
    else {
        for (int e = 0; e < CarrosV.size(); e++) {
            if (CarrosV[e]->getPlacas() == placaD) {
                CarrosV[e]->MostrarInfo(2026);
                completo = 1;}}
        if (completo == 0){
            for (int e = 0; e < MotosV.size(); e++) {
                if (MotosV[e]->getPlacas() == placaD) {
                    MotosV[e]->MostrarInfo(2026);
                    completo = 1;}}}
    }
    if (completo == 0){
        cout<<"No hay ningun vehiculo con esa placa"<<endl;}
}
void Eleccion2(vector<Vehiculos*>& CarrosV,vector<Vehiculos*>& MotosV){
    string placaD;
    cout<<"Escriba la placa del vehiculo para ver de cuanto es su impuesto"<<endl;
    cin>>placaD;
    int completo = 0;
    for (int e = 0; e < CarrosV.size(); e++) {
        if (CarrosV[e]->getPlacas() == placaD) {
            cout<<"Su impuesto sera de "<<CarrosV[e]->CalcularImpuesto()<<"$"<<endl;
            completo = 1;}}
    if (completo == 0){
        for (int e = 0; e < MotosV.size(); e++) {
            if (MotosV[e]->getPlacas() == placaD) {
                cout<<"Su impuesto sera de "<<MotosV[e]->CalcularImpuesto()<<"$"<<endl;
                completo = 1;}}}
    if (completo == 0){
        cout<<"No hay ningun vehiculo con esa placa"<<endl;}
}
void Eleccion3(vector<Vehiculos*>& CarrosV,vector<Vehiculos*>& MotosV){
    string placaD;
    cout<<"Escriba la placa del vehiculo para ver de cuanto es su mantenimiento"<<endl;
    cin>>placaD;
    int completo = 0;
    for (int e = 0; e < CarrosV.size(); e++) {
        if (CarrosV[e]->getPlacas() == placaD) {
            cout<<"Su mantenimiento es de "<<CarrosV[e]->CalcularMantenimiento(2026)<<"$"<<endl;
            completo = 1;}}
    if (completo == 0){
        for (int e = 0; e < MotosV.size(); e++) {
            if (MotosV[e]->getPlacas() == placaD) {
                cout<<"Su mantenimiento es de "<<MotosV[e]->CalcularMantenimiento(2026)<<"$"<<endl;
                completo = 1;}}}
    if (completo == 0){
        cout<<"No hay ningun vehiculo con esa placa"<<endl;}
}
void Eleccion4(vector<Persona*>& CompradorV,vector<Persona*>& VendedorV,vector<Vender*>& VentasV) {
    while(true){
        int eleccionVenta;
        cout << "------------Menu ventas-------------" << endl;
        cout << "1.- Vender un vehiculo" << endl;
        cout << "2.- Añadir una nueva persona" << endl;
        cout << "3.- Generar factura" << endl;
        cout << "4.- Ver nombres de personas" << endl;
        cout <<"5.- Ver lista de vehiculos vendidos"<<endl;
        cout << "6.- Salir" << endl;
        cin>>eleccionVenta;
        if(eleccionVenta==1){
            EleccionVenta1(CompradorV,VendedorV,VentasV);}
        if (eleccionVenta==2){
            EleccionVenta2(CompradorV,VendedorV);}
        if (eleccionVenta==3) {
            EleccionVenta3(VentasV);}
        if (eleccionVenta==4) {
            EleccionVenta4(CompradorV,VendedorV);}
        if (eleccionVenta==5) {
            EleccionVenta5(VentasV);}
        if(eleccionVenta==6){
            cout<<"Regresando al menu principal"<<endl;
            break;}
    }
}
void Eleccion5(vector<Vehiculos*>& CarrosV,vector<Vehiculos*>& MotosV){
    string opcion;
    cout<<"Quieres agregar una moto(M) o carro(C)?"<<endl;
    cin>>opcion;
    if(opcion == "C"){
        CrearCarros(CarrosV);}
    if(opcion == "M"){
        CrearMotos(MotosV);}
    else{
        cout<<"opcion invalida regresando al menú"<<endl;}
}
void Eleccion6(vector<Vehiculos*>& CarrosV,vector<Vehiculos*>& MotosV){
    string placaElegidas;
    cout<<"Escribe la placa del vehiculo que quiere comparar: ";
    cin>>placaElegidas;
    for(int i=0;i<CarrosV.size();i++){
        if (placaElegidas == CarrosV[i]->getPlacas()) {
            cout<<"Los carros con las siguientes placas comparten el mismo modelo ("<<CarrosV[i]->getModelo()<<") y anio ("<<CarrosV[i]->getAnio()<<")"<<endl;
            for(int i1=0;i1<CarrosV.size();i1++){
                if(*CarrosV[i]==*CarrosV[i1]){
                    cout<<CarrosV[i1]->getPlacas()<<endl;}}
            return;
        }
    }
    for(int e=0;e<MotosV.size();e++){
        if (placaElegidas == MotosV[e]->getPlacas()) {
            cout<<"Las motos con las siguientes placas comparten el mismo modelo ("<<MotosV[e]->getModelo()<<") y anio ("<<MotosV[e]->getAnio()<<")"<<endl;
            for(int e1=0;e1<MotosV.size();e1++){
                if(*MotosV[e]==*MotosV[e1]){
                    cout<<MotosV[e1]->getPlacas()<<endl;}}
            return;
        }
    }

    cout<<"No hay ningun vehiculo con esas placas"<<endl;
}

void menu(vector<Vehiculos*>& CarrosV,vector<Vehiculos*>& MotosV,vector<Persona*>& CompradorV,vector<Persona*>& VendedorV,vector<Vender*>& VentasV) {
    while(true){
        int eleccion;
        cout << "------------Menu principal-------------" << endl;
        cout << "1.- Ver informacion" << endl;
        cout << "2.- Calcular impuesto" << endl;
        cout << "3.- Calcular mantenimiento" << endl;
        cout << "4.- Abrir menu de ventas" << endl;
        cout << "5.- Anadir un nuevo vehiculo"<<endl;
        cout << "6.- Comparar vehiculo"<<endl;
        cout << "7.- Salir"<<endl;
        cin >> eleccion;
        if (eleccion == 1) {
            Eleccion1(CarrosV,MotosV);}
        else if(eleccion==2){
            Eleccion2(CarrosV,MotosV);}
        else if(eleccion==3){
            Eleccion3(CarrosV,MotosV);}
        else if(eleccion==4){
            Eleccion4(CompradorV,VendedorV,VentasV);}
        else if(eleccion==5){
            Eleccion5(CarrosV,MotosV);}
        else if(eleccion==6){
            Eleccion6(CarrosV,MotosV);}
        else if(eleccion ==7){
            break;}
        else{
            cout<<"Elige una opcion valida"<<endl;}
    }
}


int main(){
    vector<Vehiculos*> CarrosV;
    vector<Vehiculos*> MotosV;
    vector<Persona*> CompradorV;
    vector<Persona*> VendedorV;
    vector<Vender*> VentasV;
    BaseCarros(CarrosV);
    BaseMotos(MotosV);
    BaseComprador(CompradorV);
    BaseVendedor(VendedorV);
    BaseVentas(VentasV,CompradorV,VendedorV);
    menu(CarrosV,MotosV,CompradorV,VendedorV,VentasV);
    return 0;
}


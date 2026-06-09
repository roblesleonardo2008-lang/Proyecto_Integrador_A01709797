#include<iostream>
#include<vector>
#include"Avance4.h"
using namespace std;

string mejorVerdadero(bool v){
    if (v == 1){return "verdadero";}
    else{ return "falso";}
}

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
    Vehiculos* carrosA[] = {moto1,moto2,moto3,moto4};
    MotosV.reserve(4);
    for (int i=0; i<4; i++){
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

void CrearCarros(vector<Vehiculos*>& CarrosV){
    string modelo,placas,carroceria;
    int anio,tanque,eficienciaL,puertas;
    bool aire;
    cout<<"Modelo: ";
    cin>>modelo;
    cout<<"placas: ";
    cin>>placas;
    cout<<"carroceria: ";
    cin>>carroceria;
    cout<<"año: ";
    cin>>anio;
    cout<<"tanque: ";
    cin>>tanque;
    cout<<"efficienciaL: ";
    cin>>eficienciaL;
    cout<<"aire (true(1)/false(0)): ";
    cin>>aire;
    cout<<"puertas: ";
    cin>>puertas;
    Vehiculos* carro = new Carro(modelo,placas,anio,tanque,eficienciaL,carroceria,puertas,aire);
    CarrosV.push_back(carro);
    cout<<"carro añadido"<<endl;
}
void CrearMotos(vector<Vehiculos*>& MotosV){
    string modelo,placas,tipoCadena,modalidad,manubrio;
    int anio,tanque,eficienciaL;
    bool sidecar;
    cout<<"Modelo: ";
    cin>>modelo;
    cout<<"placas: ";
    cin>>placas;
    cout<<"Tipo de Cadena: ";
    cin>>tipoCadena;
    cout<<"Modalidad: ";
    cin>>modalidad;
    cout<<"Manubrio: ";
    cin>>manubrio;
    cout<<"año: ";
    cin>>anio;
    cout<<"tanque: ";
    cin>>tanque;
    cout<<"efficienciaL: ";
    cin>>eficienciaL;
    cout<<"Sidecar (true(1)/false(0)): ";
    cin>>sidecar;
    Vehiculos* moto = new Moto(modelo,placas,anio,tanque,eficienciaL,tipoCadena,manubrio,modalidad,sidecar);
    MotosV.push_back(moto);
    cout<<"moto añadida"<<endl;
}

void EleccionVenta1(vector<Persona*>& CompradorV,vector<Persona*>& VendedorV,vector<Vender*>& VentasV){
    int precio,x1,x2,xi,xe;
    string duenio,placas,nombre_comprador,nombre_vendedor;
    cout<<"Precio del vehículo: ";
    cin>>precio;
    cout<<"Dueño del vehículo: ";
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
        if(x1==1){ break;}}
    while(true){
        cout<<"Nombre del vendedor: ";
        cin>>ws;
        getline(cin,nombre_vendedor);
        for(int i=0;i<VendedorV.size();i++){
            if(VendedorV[i]->getNombre()==nombre_vendedor){
                x2 = 1;
                xe = i;
                break;}}
        if(x2==1){ break;}}
    Vender* venta=new Vender(precio,duenio,placas,VendedorV[xi],CompradorV[xi]);
    VentasV.push_back(venta);
}
void EleccionVenta2(vector<Persona*>& CompradorV,vector<Persona*>& VendedorV){
    string eleccionPersona,nombre,RFC,Domicilio;
    int ID;
    cout<<"¿Quieres añadir un nuevo vendedor(V) o comprador(C)?"<<endl;
    if(eleccionPersona=="V"){
        cout<<"Nombre del vendor: ";
        cin>>nombre;
        cout<<"RFC del vendor: ";
        cin>>RFC;
        Domicilio = "";
        cout<<"ID del vendor: ";
        cin>>ID;
        Persona* vendedor = new Persona(nombre,RFC,Domicilio,ID);
        VendedorV.push_back(vendedor);
        cout<<"Se ha añadido al vendedor"<<endl;
    }
    else if(eleccionPersona=="C") {
        cout << "Nombre del comprador: ";
        cin >> nombre;
        cout << "RFC del comprador: ";
        cin >> RFC;
        ID = 0;
        cout << "Domicilio del comprador: ";
        cin >> Domicilio;
        Persona* comprador= new Persona(nombre, RFC, Domicilio, ID);
        CompradorV.push_back(comprador);
        cout<<"Se ha añadido al comprador"<<endl;
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
            cout<<"no se encontro ningun vehículo vendido con esas placas"<<endl;}
    }
}
void EleccionVenta4(vector<Persona*>& CompradorV,vector<Persona*>& VendedorV){
    string elegir;
    cout<<"Compradores(C) o Vendedores(V)"<<endl;
    if (elegir=="C"){
        for(int i=0;i<CompradorV.size();i++){
            cout<<"Imprimiendo nombres de los compradores"<<endl;
            cout<<CompradorV[i]->getNombre()<<endl;}
    }
    else if (elegir=="V"){
        for(int i=0;i<CompradorV.size();i++){
            cout<<"Imprimiendo nombres de los vendedores"<<endl;
            cout<<VendedorV[i]->getNombre()<<endl;}
    }
    else{
        cout<<"Opción invalida"<<endl;}
}


void Eleccion1(vector<Vehiculos*>& CarrosV,vector<Vehiculos*>& MotosV){
    string placaD;
    cout<<"Escriba la placa del vehículo para ver su información o C/M para ver la infromación de todos las carros/motos"<<endl;
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
        cout<<"No hay ningun vehículo con esa placa"<<endl;}
}
void Eleccion2(vector<Vehiculos*>& CarrosV,vector<Vehiculos*>& MotosV){
    string placaD;
    cout<<"Escriba la placa del vehículo para ver de cuanto es su impuesto"<<endl;
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
        cout<<"No hay ningun vehículo con esa placa"<<endl;}
}
void Eleccion3(vector<Vehiculos*>& CarrosV,vector<Vehiculos*>& MotosV){
    string placaD;
    cout<<"Escriba la placa del vehículo para ver de cuanto es su mantenimiento"<<endl;
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
        cout<<"No hay ningun vehículo con esa placa"<<endl;}
}
void Eleccion4(vector<Persona*>& CompradorV,vector<Persona*>& VendedorV,vector<Vender*>& VentasV) {
    while(true){
        int eleccionVenta;
        cout << "------------Menú ventas-------------" << endl;
        cout << "1.- Vender un vehículo" << endl;
        cout << "2.- Añadir una nueva persona" << endl;
        cout << "3.- Generar factura" << endl;
        cout << "4.- Ver nombres de personas" << endl;
        cout << "5.- Salir" << endl;
        cin>>eleccionVenta;
        if(eleccionVenta==1){
            EleccionVenta1(CompradorV,VendedorV,VentasV);}
        if (eleccionVenta==2){
            EleccionVenta2(CompradorV,VendedorV);}
        if (eleccionVenta==3) {
            EleccionVenta3(VentasV);}
        if (eleccionVenta==3) {
            EleccionVenta4(CompradorV,VendedorV);}
        if(eleccionVenta==5){
            cout<<"Regresando al menú principal"<<endl;
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

void menu(vector<Vehiculos*>& CarrosV,vector<Vehiculos*>& MotosV,vector<Persona*>& CompradorV,vector<Persona*>& VendedorV,vector<Vender*>& VentasV) {
    while(true){
        int eleccion;
        cout << "Qué quieres hacer?" << endl;
        cout << "1.- Ver información" << endl;
        cout << "2.- Calcular impuesto" << endl;
        cout << "3.- Calcular mantenimiento" << endl;
        cout << "4.- abrir menú de ventas" << endl;
        cout << "5.- añadir un nuevo vehículo"<<endl;
        cout << "6.- salir"<<endl;
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
        else if(eleccion ==6){
            break;}
        else{
            cout<<"Elige una opción valida"<<endl;}
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
    menu(CarrosV,MotosV,CompradorV,VendedorV,VentasV);

    for (int e=0;e<CarrosV.size();e++){
        delete CarrosV[e];
    }
    CarrosV.clear();
    for (int e=0;e<MotosV.size();e++){
        delete MotosV[e];
    }
    MotosV.clear();
    for (int e=0;e<VendedorV.size();e++) {
        delete VendedorV[e];
    }
    VendedorV.clear();
    for (int e=0;e<CarrosV.size();e++) {
        delete CompradorV[e];
    }
    CompradorV.clear();
    for (int e=0;e<VentasV.size();e++) {
        delete VentasV[e];
    }
    VentasV.clear();
    return 0;
}


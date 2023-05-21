#include "db_local.h"
#include "medicion.h"
#include "sensor.h"
#include <iostream>
#include <chrono>
#include <thread>

void delay( unsigned int millisec ){
    std::this_thread::sleep_for(std::chrono::milliseconds(millisec));
}

using namespace std;

int main(int argc, char** argv){
    Medicion med, prom;
    DB_Local db("dblocal.als");
    Sensor   sensor;
    
    while( true ){
        delay( 5000 );
        sensor.actualizar( med );
        db.Abrir_DB();
        db.Ingresar( med );
        db.Recuperar( prom );
        cout << "Promedio: "  << prom << endl;
        db.Cerar_DB();
     }
    return 0;
}

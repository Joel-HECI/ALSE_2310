#include "db_local.h"

#include "medicion.h"
#include <string>

using namespace std;

DB_Local::DB_Local( string url ){

}

bool DB_Local::Abrir_DB(){
  return true;
}

bool DB_Local::Ingresar( const Medicion &med ){
  return true;

}

bool DB_Local::Recuperar( Medicion &prom ){
  return true;

}

bool DB_Local::Cerar_DB(){
  return true;

}


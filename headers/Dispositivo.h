#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

#include<iostream>
#include<cstring>
#include<string>


using std::left;
using std::right;
using std::fixed;
using std::cout;
using std::endl;

#include<iomanip>
using std::setw;
using std::setprecision;

using std::string;
using std::clog;
using std::showpoint;

class Dispositivo{
    
    
    public:
        Dispositivo();
        ~Dispositivo();
        
        int getId() const;
        char *getHn() const;
        char *getIp() const;
        bool setHn(string);
        bool setIp(string);
        int _Size() const;
        void printDispositivo() const;
        friend std::ostream& operator<<(std::ostream& os, const Dispositivo& dt);


    private:

        int id;
        char *hn;
        char *ip;
        static int cont;
};

int Dispositivo::cont = 0;

Dispositivo::Dispositivo(){
    /**
     * @brief inicializa la instancia. 
    */
    cont++;
    id = cont;
    hn = ip = 0;
}
Dispositivo::~Dispositivo(){

    /**
     * @brief muestra por pantalla,
     * los datos del tispositivo que se
     * esta eliminando luego de finalizar el
     * programa o utilizar la funcion delete
     * @author Leonardo Febres
     *
    */
    //cout << "D{ ID: " <<id << " HostName: " << hn << " IP: " << ip << " }";
    --cont;
}

int Dispositivo::getId() const{

    /** @brief retorna el id del dispositivo. 
     * (ID) numero autoincremetal deacuerdo a
     * la cantidad de dispositivos creados.*/
    return this->id;
}

char *Dispositivo::getHn() const{
    /**
     * @brief retorna el hostname del dispositivo. 
    */
    return this->hn;
}

char *Dispositivo::getIp() const{
    /**
     * @brief retorna la ip del dispositivo
    */
    return this->ip;
}

bool Dispositivo::setHn(std::string hn){

    /**
     * @brief valida antes de insertar el
     * hostname al objeto.
    */
    if (hn.empty()){
        clog << "\nHostName es vacio, inserte MIN 3 caracteres o MAX 48 caracteres.\n";
        return false;
    }else {
        if (hn.size() < 3){
            clog << "\nHostName "<< hn << " debe ser mayor a 3 caracteres\n";
            return false;
        }else if ( hn.size() > 48){
            clog << "\nHostName "<< hn << " debe ser menor a 48 caracteres\n";
            return false;
        }else{
            /**
             * linea 1 reserva el espacio en memoria basandose
             * en el tamaño del string.
             * combina el string en el array de caracteres de hostName.
            */

            if(hn.back() == ','){
                hn.erase(hn.length()-1);
            }
            this-> hn = new char[hn.length()+1];
            std::strcpy(this->hn, hn.c_str());
            return true;
        }
    }
}

bool Dispositivo::setIp(string ip){
    /**
     * @brief
     * se asume que el formato de la ip
     * siempre va a ser valido, ya que no se especifica
     * que version. ipv6 o ipv4.
     * 
    */
    if(ip.empty()){
        return false;

    }else{
        this->ip = new char[ip.length()+1];
        std:strcpy(this->ip, ip.c_str());
        return true;
    }
}

int Dispositivo::_Size() const {
    /**
     * @brief se utiliza para identificar cuantos dispositivos
     * estan creados en el programa.
     * @author Leonardo Febres
    */
    return cont;
}



void Dispositivo::printDispositivo() const{        
        cout << left << "ID: "<<setw(5)<< id\
        << setw(5) << " Hostname: "<< setw(5)\
        << hn << setw(5) << " IP: "<< setw(5)\
        << ip << setw(5) <<right <<"\n";
}

std::ostream& operator<<(std::ostream& os, const Dispositivo& dt){

    /**
     * @brief modifica el operador << para crear un descriptor
     * de la clase, asi se podra imprimir utilizando el cout.
     * @param os
     * @param dt
     * @author Leonardo Febres
    */

        os << left <<dt.id << setw(5)<<" "<<dt.hn<<setw(10)<<" "<<dt.ip<<endl;
        /*
        os << left << "ID: "<<setw(5)<< dt.id\
        << setw(5) << " Hostname: "<< setw(5)\
        << dt.hn << setw(5) << " IP: "<< setw(5)\
        << dt.ip << setw(5) <<right <<" \n";
        */
        return os;
}
#endif
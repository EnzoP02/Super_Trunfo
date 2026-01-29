#include "carta.hpp"

namespace trabalho{

    Carta::Carta(){}
 
 
    Carta::Carta(std::string name, int strenght, int velocity, int superpower, int intelligence){
        nome = name;
        forca = strenght;
        velocidade = velocity;
        superpoder = superpower;
        inteligencia = intelligence;
    }
 
 
    void Carta::set_nome(std::string name){
        nome = name;
    }
 
 
    void Carta::set_forca(int valor){
        forca = valor;
    }
 
 
    void Carta::set_velocidade(int valor){
        velocidade = valor;
    }
 
 
    void Carta::set_superpoder(int valor){
        superpoder = valor;
    }
 
 
    void Carta::set_inteligencia(int valor){
        inteligencia = valor;
    }
 
 
    void Carta::set_supertrunfo(){
        supertrunfo = true;
    }
 
 
    std::string Carta::get_nome(){
        return nome;
    }
 
 
    int Carta::get_forca(){
        return forca;
    }
 
 
    int Carta::get_velocidade(){
        return velocidade;
    }
 
 
    int Carta::get_superpoder(){
        return superpoder;
    }
 
 
    int Carta::get_inteligencia(){
        return inteligencia;
    }
   
 
    bool Carta::get_supertrunfo(){
        return supertrunfo;
    }
    
}
#ifndef CARTA_HPP
#define CARTA_HPP

#include <iostream>
#include <string>
#include <memory>


namespace trabalho{

    class Carta{
 
        private:
            std::string nome;
            int forca;
            int velocidade;
            int superpoder;
            int inteligencia;
            bool supertrunfo = false;
 
        public:
            explicit Carta();
            Carta(std::string name, int strenght, int velocity, int superpower, int intelligence);

            void set_nome(std::string name);
            void set_forca(int valor);
            void set_velocidade(int valor);
            void set_superpoder(int valor);
            void set_inteligencia(int valor);
            void set_supertrunfo();
            
            std::string get_nome();
            int get_forca();
            int get_velocidade();
            int get_superpoder();
            int get_inteligencia();
            bool get_supertrunfo();
            
    }; 

}

#endif
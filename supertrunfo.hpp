#ifndef SUPERTRUNFO_HPP
#define SUPERTRUNFO_HPP 

#include "carta.hpp"

namespace trabalho{

    class SuperTrunfo: public Carta{
        
        public:
            SuperTrunfo(std::string name, int strenght, int velocity, int superpower, int intelligence);
            
    };

}

#endif
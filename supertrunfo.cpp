#include "supertrunfo.hpp"

namespace trabalho{

    SuperTrunfo::SuperTrunfo(std::string name, int strenght, int velocity, int superpower, int intelligence){
        set_nome(name);
        set_forca(strenght);
        set_velocidade(velocity);
        set_superpoder(superpower);
        set_inteligencia(intelligence);
        set_supertrunfo();
    }

}
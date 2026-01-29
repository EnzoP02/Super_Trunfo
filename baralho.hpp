#ifndef BARALHO_HPP
#define BARALHO_HPP

#include "carta.hpp"
#include "supertrunfo.hpp"

#include <vector>
#include <random>
#include <memory>

namespace trabalho{

    class Baralho{

        private:
            std::vector<std::shared_ptr<Carta>> cartas;

        public:
            Baralho();

            std::shared_ptr<Carta> cria_carta(std::string name, int strenght, int velocity, int superpower, int intelligence);

            std::shared_ptr<SuperTrunfo> cria_supertrunfo(std::string name, int strenght, int velocity, int superpower, int intelligence);

            void insere_no_vetor(std::shared_ptr<Carta> card);

            void inicializa_baralho();

            std::vector<std::shared_ptr<Carta>> get_vetor();

            void embaralhar();
            
    };

}

#endif
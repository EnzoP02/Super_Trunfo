#ifndef JOGO_HPP
#define JOGO_HPP

#include "baralho.hpp"

#include <queue>

namespace trabalho{

    class Jogo{

        private:
            Baralho main_deck;

        public:
            Jogo(Baralho baralho);

            void set_baralho(Baralho main_deck);

            int media_atributo(int atributo);

            int escolha_de_atributo_cpu(std::shared_ptr<Carta> card);

            int get_resultado(std::shared_ptr<Carta> player_card, std::shared_ptr<Carta> cpu_card, int indice, int atributo);

            void compara_cartas(std::shared_ptr<Carta> player_card, std::shared_ptr<Carta> cpu_card, int indice, int atributo);

            bool checa_atributo(int atributo);

            void inicializa_filas(std::queue<std::shared_ptr<Carta>> mao_jogador, std::queue<std::shared_ptr<Carta>> mao_cpu);

            int acha_supertrunfo();

            void printa_carta(std::shared_ptr<Carta> card);

            void muda_a_fila(std::queue<std::shared_ptr<Carta>> mao_jogador, std::queue<std::shared_ptr<Carta>> mao_cpu, int indice, int resultado);

            void rodada(std::shared_ptr<Carta> player_card, std::shared_ptr<Carta> cpu_card, int indice, int atributo);//

            void mostra_vetor();

            friend std::ostream &operator<<(std::ostream &out, Jogo &game){
                std::cout << "Mao do jogador:" << std::endl;
                for(unsigned int i=0; i<14; i++){
                    game.printa_carta(game.main_deck.get_vetor()[i]);
                }
                return out;
            }
            
    };

}

#endif
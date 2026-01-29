#include "jogo.hpp"

namespace trabalho{

    Jogo::Jogo(Baralho baralho){
        set_baralho(baralho);
    }


    void Jogo::set_baralho(Baralho baralho){
        main_deck = baralho;
    }

    int Jogo::media_atributo(int atributo){
        std::vector<std::shared_ptr<Carta>> vet = main_deck.get_vetor();
        int media = 0;
        if(atributo == 1){
            for(unsigned int i=0; i<28; i++){
                media += vet[i]->get_forca();
            }
        }
        if(atributo == 2){
            for(unsigned int i=0; i<28; i++){
                media += vet[i]->get_velocidade();
            }
        }
        if(atributo == 3){
            for(unsigned int i=0; i<28; i++){
                media += vet[i]->get_superpoder();
            }
        }
        if(atributo == 4){
            for(unsigned int i=0; i<28; i++){
                media += vet[i]->get_inteligencia();
            }
        }
        media = media/28;
        return media;
    }


    int Jogo::escolha_de_atributo_cpu(std::shared_ptr<Carta> card){
        int f = card->get_forca() - (media_atributo(1));
        int v = card->get_velocidade() - (media_atributo(2));
        int sp = card->get_superpoder() - (media_atributo(3));
        int i = card->get_inteligencia() - (media_atributo(4));
        int var = f;
        int melhor_atributo = 1;
        if(var < v){
            var = v;
            melhor_atributo = 2;
        }
        if(var < sp){
            var = sp;
            melhor_atributo = 3;
        }
        if(var < i){
            var = i;
            melhor_atributo = 4;
        }
        return melhor_atributo;
    }


    int Jogo::get_resultado(std::shared_ptr<Carta> player_card, std::shared_ptr<Carta> cpu_card, int indice, int atributo){
        int resultado;
        if(indice == 1){
            if(atributo == 1){
                resultado = player_card->get_forca() - cpu_card->get_forca();
            }
            if(atributo == 2){
                resultado = player_card->get_velocidade() - cpu_card->get_velocidade();
            }
            if(atributo == 3){
                resultado = player_card->get_superpoder() - cpu_card->get_superpoder();
            }
            if(atributo == 4){
                resultado = player_card->get_inteligencia() - cpu_card->get_inteligencia();
            }
        } else{
            if(atributo == 1){
                resultado = cpu_card->get_forca() - player_card->get_forca();
            } else if(atributo == 2){
                resultado = cpu_card->get_velocidade() - player_card->get_velocidade();
            } else if(atributo == 3){
                resultado = cpu_card->get_superpoder() - player_card->get_superpoder();
            } else{
                resultado = cpu_card->get_inteligencia() - player_card->get_inteligencia();
            }
        }
        return resultado;
    }


    void Jogo::compara_cartas(std::shared_ptr<Carta> player_card, std::shared_ptr<Carta> cpu_card, int indice, int atributo){
        if(indice == 1){
            if(atributo == 1){
                std::cout << "O atributo escolhido por você foi: Forca." << std::endl;
                std::cout << "Forca da sua carta: " << player_card->get_forca() << std::endl;
                std::cout << "Forca da carta da CPU: " << cpu_card->get_forca() << std::endl;
            }
            if(atributo == 2){
                std::cout << "O atributo escolhido por você foi: Velocidade." << std::endl;
                std::cout << "Velocidade da sua carta: " << player_card->get_velocidade() << std::endl;
                std::cout << "Velocidade da carta da CPU: " << cpu_card->get_velocidade() << std::endl;
            }
            if(atributo == 3){
                std::cout << "O atributo escolhido por você foi: SuperPoder." << std::endl;
                std::cout << "SuperPoder da sua carta: " << player_card->get_superpoder() << std::endl;
                std::cout << "SuperPoder da carta da CPU: " << cpu_card->get_superpoder() << std::endl;
            }
            if(atributo == 4){
                std::cout << "O atributo escolhido por você foi: Inteligencia." << std::endl;
                std::cout << "Inteligencia da sua carta: " << player_card->get_inteligencia() << std::endl;
                std::cout << "Inteligencia da carta da CPU: " << cpu_card->get_inteligencia() << std::endl;
            }
        } else{
            if(atributo == 1){
                std::cout << "O atributo escolhido pela CPU foi: Forca." << std:: endl;
                std::cout << "Forca da sua carta: " << player_card->get_forca() << std::endl;
                std::cout << "Forca da carta da CPU: " << cpu_card->get_forca() << std::endl;
            }
            if(atributo == 2){
                std::cout << "O atributo escolhido pela CPU foi: Velocidade." << std:: endl;
                std::cout << "Velocidade da sua carta: " << player_card->get_velocidade() << std::endl;
                std::cout << "Velocidade da carta da CPU: " << cpu_card->get_velocidade() << std::endl;
            }
            if(atributo == 3){
                std::cout << "O atributo escolhido pela CPU foi: SuperPoder." << std:: endl;
                std::cout << "SuperPoder da sua carta: " << player_card->get_superpoder() << std::endl;
                std::cout << "SuperPoder da carta da CPU: " << cpu_card->get_superpoder() << std::endl;
            }
            if(atributo == 4){
                std::cout << "O atributo escolhido pela CPU foi: Inteligencia." << std:: endl;
                std::cout << "Inteligencia da sua carta: " << player_card->get_inteligencia() << std::endl;
                std::cout << "Inteligencia da carta da CPU: " << cpu_card->get_inteligencia() << std::endl;
            }
        }
    }


    bool Jogo::checa_atributo(int atributo){
        if(atributo == 1 || atributo == 2 || atributo == 3 || atributo == 4){
            return true;
        } else{
            std::cout << "[ATRIBUTO INVALIDO]" << std::endl;
            std::cout << "Digite um numero inteiro, entre 1 e 4, que corresponda ao seu respectivo atributo" << std::endl;
            return false;
        }
    }


    void Jogo::inicializa_filas(std::queue<std::shared_ptr<Carta>> mao_jogador, std::queue<std::shared_ptr<Carta>> mao_cpu){
        std::vector<std::shared_ptr<Carta>> vet = main_deck.get_vetor();
        for(unsigned int i=0; i<14; i++){
            mao_jogador.push(vet[i]);
        }
        for(unsigned int i=14; i<28; i++){
            mao_cpu.push(vet[i]);
        }
    }


    int Jogo::acha_supertrunfo(){
        std::vector<std::shared_ptr<Carta>> vet = main_deck.get_vetor();
        int indice = 2;
        for(unsigned int i=0; i<14; i++){
            if(vet[i]->get_nome() == "Aquaman"){
                indice = 1;
                break;
            }
        }
        return indice;
    }

    void Jogo::printa_carta(std::shared_ptr<Carta> card){
        std::cout << card->get_nome() << "\nForca : " << card->get_forca() << "\nVelocidade : " << card->get_velocidade() << std::endl;
        std::cout << "Super Poder : " << card->get_superpoder() << "\nInteligencia : " << card->get_inteligencia() << std::endl;
        if(card->get_nome() != "Aquaman"){
            std::cout << "\n";
        }
        if(card->get_nome() == "Aquaman"){
            std::cout << "SUPERTRUNFO\n" << std::endl;
        }
    }


    void Jogo::muda_a_fila(std::queue<std::shared_ptr<Carta>> mao_jogador, std::queue<std::shared_ptr<Carta>> mao_cpu, int indice, int resultado){
        if(indice == 1){
            if(resultado > 0){
                std::cout << "Boa! Voce ganhou a rodada." << std::endl;
                mao_jogador.push(mao_jogador.front());
                mao_jogador.pop();
                mao_jogador.push(mao_cpu.front());
                mao_cpu.pop();
            }
            else if(resultado < 0){
                std::cout << "Que pena, voce perdeu a rodada.\n" << "A CPU escolhera o próximo atributo." << std::endl;
                mao_cpu.push(mao_cpu.front());
                mao_cpu.pop();
                mao_cpu.push(mao_jogador.front());
                mao_jogador.pop();
            }
            else if(resultado == 0){
                std::cout << "EMPATE! Sua carta foi retornada para o final da sua mao." << std::endl;
                mao_jogador.push(mao_jogador.front());
                mao_jogador.pop();
                mao_cpu.push(mao_cpu.front());
                mao_cpu.pop();
            }
        } 
        else{
            if(resultado > 0){
                    std::cout << "Que pena, voce perdeu a rodada.\n" << "A CPU escolhera o próximo atributo." << std::endl;
                mao_cpu.push(mao_cpu.front());
                mao_cpu.pop();
                mao_cpu.push(mao_jogador.front());
                mao_jogador.pop();
            }
            else if(resultado < 0){
                std::cout << "Boa! Voce ganhou a rodada." << std::endl;
                mao_jogador.push(mao_jogador.front());
                mao_jogador.pop();
                mao_jogador.push(mao_cpu.front());
                mao_cpu.pop();
            }
            else if(resultado == 0){
                std::cout << "EMPATE! Sua carta foi retornada para o final da sua mao." << std::endl;
                mao_jogador.push(mao_jogador.front());
                mao_jogador.pop();
                mao_cpu.push(mao_cpu.front());
                mao_cpu.pop();
            }
        }
    }


    void Jogo::rodada(std::shared_ptr<Carta> player_card, std::shared_ptr<Carta> cpu_card, int indice, int atributo){
        //int resultado;
        if(indice == 1){
        /*std::cout << "Escolha um atributo - [Digite o numero inteiro, entre 1 e 4, correspondente ao atributo escolhido]" << std::endl;
        std::cout << "1 - Forca \n2 - Velocidade \n3 - SuperPoder \n4 - Inteligencia" << std::endl;
        std::cin >> atributo;
        while((atributo != 1) && (atributo != 2) && (atributo != 3) && (atributo != 4)){
            std::cout << "NUMERO INVALIDO! Digite um numero inteiro entre 1 e 4, referente ao atributo desejado." << std::endl;
            std::cin >> atributo;  
        }*/
            std::cout << "A carta da cpu era:" << std::endl;
            printa_carta(cpu_card);
            //resultado = get_resultado(player_card, cpu_card, 1, atributo);
            compara_cartas(player_card, cpu_card, 1, atributo);
        //muda_a_fila(mao_jogador, mao_cpu, 1, resultado);
        } 
        else{
        //std::cout << "A CPU escolhera um atributo para a batalha." << std::endl;
        //atributo = escolha_de_atributo_cpu(main_deck, mao_cpu.front());
            //resultado = get_resultado(player_card, cpu_card, 2, atributo);
            std::cout << "A carta da cpu era:" << std::endl;
            printa_carta(cpu_card);
            compara_cartas(player_card, cpu_card, 2, atributo);
            //muda_a_fila(mao_jogador, mao_cpu, 2, resultado);
        }
    }

    void Jogo::mostra_vetor(){
        std::vector<std::shared_ptr<Carta>> cartas = main_deck.get_vetor();
        for(unsigned int i=0; i<28; i++){
            printa_carta(cartas[i]);
        }
    }

}
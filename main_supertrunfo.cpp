#include "jogo.hpp"

#include <ctime>
#include <iostream>
#include <random>

int main(){
    std::cout << "Ola, bem vindo ao SuperTrunfo DC Characters, voce vai querer jogar? Se sim, digite 1, caso queira sair, digite 2" << std::endl;
    int var_de_jogo;
    std::cin >> var_de_jogo;
    
    while((var_de_jogo != 1) && (var_de_jogo != 2)){

        std::cout << "NUMERO INVALIDO! Digite 1 para jogar ou 2 para sair." << std::endl;
        std::cin >> var_de_jogo;

    }

    while(var_de_jogo == 1){
        trabalho::Baralho main_deck;
        trabalho::Jogo game(main_deck);
        game.mostra_vetor();
        std::cout << "\n" << game << std::endl;
        std::queue<std::shared_ptr<trabalho::Carta>> mao_jogador;
        std::queue<std::shared_ptr<trabalho::Carta>> mao_cpu;
        std::vector<std::shared_ptr<trabalho::Carta>> vet = main_deck.get_vetor();
        int indice = game.acha_supertrunfo();
        int atributo, resultado, rnd;

        for(unsigned int i=0; i<14; i++){
            mao_jogador.push(vet[i]);
        }
        for(unsigned int i=14; i<28; i++){
            mao_cpu.push(vet[i]);
        }
        
        if(indice == 1){
            std::cout << "Sua carta e:" << std::endl;
            game.printa_carta(mao_jogador.front());
            std::cout << "Escolha um atributo - [Digite o numero inteiro, entre 1 e 4, correspondente ao atributo escolhido]" << std::endl;
            std::cout << "1 - Forca \n2 - Velocidade \n3 - SuperPoder \n4 - Inteligencia" << std::endl;
            std::cin >> atributo;
            while((atributo != 1) && (atributo != 2) && (atributo != 3) && (atributo != 4)){
                std::cout << "NUMERO INVALIDO! Digite um numero inteiro entre 1 e 4, referente ao atributo desejado." << std::endl;
                std::cin >> atributo;  
            }
        } 
        else{
            std::cout << "Sua carta e:" << std::endl;
            game.printa_carta(mao_jogador.front());
            std::cout << "A CPU escolhera um atributo para a batalha.\n" << std::endl;
            atributo = game.escolha_de_atributo_cpu(mao_cpu.front());
            std::cout << "Esta pronto? Se sim, digite um numero inteiro qualquer" << std::endl;
            std::cin >> rnd;
        }
        
        
        game.rodada(mao_jogador.front(), mao_cpu.front(), indice, atributo);
    
        resultado = game.get_resultado(mao_jogador.front(), mao_cpu.front(), indice, atributo);
        
        
        if(((indice == 1) && (resultado > 0)) || ((indice == 2) && (resultado < 0))){
                indice = 1;
            
                std::cout << "Boa! Voce ganhou a rodada." << std::endl;
                mao_jogador.push(mao_jogador.front());
                mao_jogador.pop();
                mao_jogador.push(mao_cpu.front());
                mao_cpu.pop();
            } 
            else if(((indice == 1) && (resultado < 0)) || ((indice == 2) && (resultado > 0))){
                indice = 2;
                
                std::cout << "Que pena, voce perdeu a rodada.\n" << "A CPU escolhera o próximo atributo.\n" << std::endl;
                mao_cpu.push(mao_cpu.front());
                mao_cpu.pop();
                mao_cpu.push(mao_jogador.front());
                mao_jogador.pop();
            }
            else{
                std::cout << "EMPATE! Sua carta foi retornada para o final da sua mao.\n" << std::endl;
                mao_jogador.push(mao_jogador.front());
                mao_jogador.pop();
                mao_cpu.push(mao_cpu.front());
                mao_cpu.pop();
            }
        
        

        while((!mao_jogador.empty()) && (!mao_cpu.empty())){
            
            if(indice == 1){
                std::cout << "Sua carta e:" << std::endl;
                game.printa_carta(mao_jogador.front());
                std::cout << "Escolha um atributo - [Digite o numero inteiro, entre 1 e 4, correspondente ao atributo escolhido]" << std::endl;
                std::cout << "1 - Forca \n2 - Velocidade \n3 - SuperPoder \n4 - Inteligencia" << std::endl;
                std::cin >> atributo;
                while((atributo != 1) && (atributo != 2) && (atributo != 3) && (atributo != 4)){
                    std::cout << "NUMERO INVALIDO! Digite um numero inteiro entre 1 e 4, referente ao atributo desejado." << std::endl;
                    std::cin >> atributo;  
                }
            } 
            else{
                std::cout << "Sua carta e:" << std::endl;
                game.printa_carta(mao_jogador.front());
                std::cout << "A CPU escolhera um atributo para a batalha.\n" << std::endl;
                atributo = game.escolha_de_atributo_cpu(mao_cpu.front());
                std::cout << "Esta pronto? Se sim, digite um numero inteiro qualquer" << std::endl;
                std::cin >> rnd;
            }
            
            game.rodada(mao_jogador.front(), mao_cpu.front(), indice, atributo);
            
            resultado = game.get_resultado(mao_jogador.front(), mao_cpu.front(), indice, atributo);
            
            if(((indice == 1) && (resultado > 0)) || ((indice == 2) && (resultado < 0))){
                indice = 1;
            
                std::cout << "Boa! Voce ganhou a rodada.\n" << std::endl;
                mao_jogador.push(mao_jogador.front());
                mao_jogador.pop();
                mao_jogador.push(mao_cpu.front());
                mao_cpu.pop();
            } 
            else if(((indice == 1) && (resultado < 0)) || ((indice == 2) && (resultado > 0))){
                indice = 2;
                
                std::cout << "Que pena, voce perdeu a rodada.\n" << "A CPU escolhera o próximo atributo.\n" << std::endl;
                mao_cpu.push(mao_cpu.front());
                mao_cpu.pop();
                mao_cpu.push(mao_jogador.front());
                mao_jogador.pop();
            }
            else{
                std::cout << "EMPATE! Sua carta foi retornada para o final da sua mao.\n" << std::endl;
                mao_jogador.push(mao_jogador.front());
                mao_jogador.pop();
                mao_cpu.push(mao_cpu.front());
                mao_cpu.pop();
            }
            
            
        }

        if(mao_jogador.empty()){
            std::cout << "Que pena! Nao foi dessa vez! Se quiser jogar de novo, digite 1, caso queira sair, digite 2" << std::endl;
        }

        if(mao_cpu.empty()){
            std::cout << "Parabens, voce venceu a partida!! Se quiser jogar de novo, digite 1, caso queira sair, digite 2" << std::endl;
        }

        std::cin >> var_de_jogo;
        while((var_de_jogo != 1) && (var_de_jogo != 2)){

        std::cout << "NUMERO INVALIDO! Digite 1 para jogar ou 2 para sair." << std::endl;
        std::cin >> var_de_jogo;

        }
    }

    std::cout << "Muito obrigado por ter jogado o SuperTrunfo DC Characters, espero que voce tenha se divertido ";
    std::cout << "e espero te ver aqui novamente, ate a proxima!" << std::endl;

    return 0;
}
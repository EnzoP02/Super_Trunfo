#include "baralho.hpp"
#include "jogo.hpp"
#include "supertrunfo.hpp"

#include <algorithm>

namespace  trabalho{

    Baralho::Baralho(){
        inicializa_baralho();
        embaralhar();
    }


    std::shared_ptr<Carta> Baralho::cria_carta(std::string name, int strenght, int velocity, int superpower, int intelligence){
        auto card = std::make_shared<Carta>(name, strenght, velocity, superpower, intelligence);
        if(!card){
            return nullptr;
        }
        card->set_nome(name);
        card->set_forca(strenght);
        card->set_velocidade(velocity);
        card->set_superpoder(superpower);
        card->set_inteligencia(intelligence);
        return card;
    }


    std::shared_ptr<SuperTrunfo> Baralho::cria_supertrunfo(std::string name, int strenght, int velocity, int superpower, int intelligence){
        auto card = std::make_shared<SuperTrunfo>(name, strenght, velocity, superpower, intelligence);
        if(!card){
            return nullptr;
        }
        card->set_nome(name);
        card->set_forca(strenght);
        card->set_velocidade(velocity);
        card->set_superpoder(superpower);
        card->set_inteligencia(intelligence);
        card->set_supertrunfo();
        return card;
    }


    void Baralho::insere_no_vetor(std::shared_ptr<Carta> card){
        cartas.push_back(card);
    }


    void Baralho::inicializa_baralho(){
        //Carta batman("The Batman", 70, 70, 65, 100);
        std::shared_ptr<Carta> batman = cria_carta("The Batman", 70, 70, 65, 100);
        insere_no_vetor(batman);

      //  Carta mulher_maravilha("Wonder Woman", 90, 80, 87, 70);
        std::shared_ptr<Carta> mulher_maravilha = cria_carta("Wonder Woman", 90, 80, 87, 70);
        insere_no_vetor(mulher_maravilha);

      //  Carta super_homem("Superman", 100, 94, 100, 70);
        std::shared_ptr<Carta> super_homem = cria_carta("Superman", 100, 94, 100, 70);
        insere_no_vetor(super_homem);

     //   Carta flash("The Flash", 60, 100, 85, 80);
        std::shared_ptr<Carta> flash = cria_carta("The Flash", 60, 100, 85, 80);
        insere_no_vetor(flash);

      //  Carta lanterna_verde("Green Lantern", 72, 70, 90, 75);
        std::shared_ptr<Carta> lanterna_verde = cria_carta("Green Lantern", 72, 70, 90, 75);
        insere_no_vetor(lanterna_verde);

      //  Carta cacador_de_marte("Martian Manhunter", 90, 80, 100, 90);
        std::shared_ptr<Carta> cacador_de_marte = cria_carta("Martian Manhunter", 90, 80, 100, 90);
        insere_no_vetor(cacador_de_marte);

       // Carta zatanna("Zatanna", 50, 65, 100, 90);
        std::shared_ptr<Carta> zatanna = cria_carta("Zatanna", 50, 65, 100, 90);
        insere_no_vetor(zatanna);

      //  SuperTrunfo aquaman("Aquaman", 80, 75, 78, 73);
        std::shared_ptr<SuperTrunfo> aquaman = cria_supertrunfo("Aquaman", 80, 75, 78, 73);
        insere_no_vetor(aquaman);

       // Carta canario_negro("Black Canary", 60, 60, 80, 70);
        std::shared_ptr<Carta> canario_negro = cria_carta("Black Canary", 60, 60, 80, 70);
        insere_no_vetor(canario_negro);

      //  Carta ravena("Raven", 54, 80, 100, 90);
        std::shared_ptr<Carta> ravena = cria_carta("Raven", 54, 80, 100, 90);
        insere_no_vetor(ravena);

       // Carta ciborgue("Cyborg", 75, 75, 80, 100);
        std::shared_ptr<Carta> ciborgue = cria_carta("Cyborg", 75, 75, 80, 100);
        insere_no_vetor(ciborgue);

        //Carta asa_noturna("Nightwing", 65, 65, 60, 80);
        std::shared_ptr<Carta> asa_noturna = cria_carta("Nightwing", 65, 65, 60, 80);
        insere_no_vetor(asa_noturna);

       // Carta estelar("Starfire", 80, 74, 82, 80);
        std::shared_ptr<Carta> estelar = cria_carta("Starfire", 80, 74, 82, 80);
        insere_no_vetor(estelar);

       // Carta super_choque("Static", 60, 78, 85, 76);
        std::shared_ptr<Carta> super_choque = cria_carta("Static", 60, 78, 85, 76);
        insere_no_vetor(super_choque);

       // Carta stargirl("Stargirl", 50, 80, 81, 50);
        std::shared_ptr<Carta> stargirl = cria_carta("Stargirl", 50, 80, 81, 50);
        insere_no_vetor(stargirl);

      //  Carta nevasca("KillerFrost", 50, 50, 80, 90);
        std::shared_ptr<Carta> nevasca = cria_carta("KillerFrost", 50, 50, 80, 90);
        insere_no_vetor(nevasca);

       // Carta darkseid("Darkseid", 100, 80, 100, 90);
        std::shared_ptr<Carta> darkseid = cria_carta("Darkseid", 100, 80, 100, 90);
        insere_no_vetor(darkseid);

        //Carta lex_luthor("Lex Luthor", 60, 60, 60, 100);
        std::shared_ptr<Carta> lex_luthor = cria_carta("Lex Luthor", 60, 60, 60, 100);
        insere_no_vetor(lex_luthor);

        //Carta coringa("The Joker", 62, 62, 59, 93);
        std::shared_ptr<Carta> coringa = cria_carta("The Joker", 62, 62, 59, 93);
        insere_no_vetor(coringa);

       // Carta besouro_azul("Blue Beetle", 80, 76, 80, 82);
        std::shared_ptr<Carta> besouro_azul = cria_carta("Blue Beetle", 80, 76, 80, 82);
        insere_no_vetor(besouro_azul);

       // Carta sinestro("Sinestro", 70, 73, 89, 77);
        std::shared_ptr<Carta> sinestro = cria_carta("Sinestro", 70, 73, 89, 77);
        insere_no_vetor(sinestro);

       // Carta supergirl("SuperGirl", 90, 90, 100, 67);
        std::shared_ptr<Carta> supergirl = cria_carta("SuperGirl", 90, 90, 100, 67);
        insere_no_vetor(supergirl);

        //Carta brainiac("Brainiac", 88, 77, 87, 100);
        std::shared_ptr<Carta> brainiac = cria_carta("Brainiac", 88, 77, 87, 100);
        insere_no_vetor(brainiac);

        //Carta cacadora("The Huntress", 60, 60, 15, 80);
        std::shared_ptr<Carta> cacadora = cria_carta("The Huntress", 60, 60, 15, 80);
        insere_no_vetor(cacadora);

       // Carta fogo("Fire", 57, 77, 82, 64);
        std::shared_ptr<Carta> fogo = cria_carta("Fire", 57, 77, 82, 64);
        insere_no_vetor(fogo);

        //Carta arqueiro_verde("Green Arrow", 68, 68, 65, 83);
        std::shared_ptr<Carta> arqueiro_verde = cria_carta("Green Arrow", 68, 68, 65, 83);
        insere_no_vetor(arqueiro_verde);

        //Carta mulher_gaviao("HawkWoman", 75, 75, 75, 75);
        std::shared_ptr<Carta> mulher_gaviao = cria_carta("HawkWoman", 75, 75, 75, 75);
        insere_no_vetor(mulher_gaviao);

        //Carta krypto("Krypto", 82, 80, 90, 23); 
        std::shared_ptr<Carta> krypto = cria_carta("Krypto", 82, 80, 90, 23); 
        insere_no_vetor(krypto);     
    }


    std::vector<std::shared_ptr<Carta>> Baralho::get_vetor(){
        return cartas;
    }


    void Baralho::embaralhar(){  
        std::random_device rd;
        std::mt19937 gerador(rd());
        std::shuffle(cartas.begin(), cartas.end(), gerador);
    }

}
# Caso de uso Jogo da Velha

## Objetivo

Permitir que seja feita a melhor interpretação da jogabilidade do Jogo da Velha assim possibilitando e facilitando o desenvolvimento do mesmo na linguagem C++ sendo usado o paradigma de orientação a objeto.

## Introdução ao jogo da velha

O jogo da velha ou jogo do galo como é conhecido em Portugal, é um jogo de regras extremamente simples, que não traz grandes dificuldades para seus jogadores e é facilmente aprendido. O objectivo é conseguir três círculos ou três xis em linha, quer horizontal, vertical ou diagonal, e, ao mesmo tempo, quando possível, impedir o adversário de ganhar na próxima jogada.

## Requisitos

* O jogo deve ter no mínimo um jogador humano.
* Deve se ter 2 modos de jogo sendo eles um modo de 1 jogador e outro modo de dois jogadores.
* O jogo da velha deve ter um tabuleiro  de 3 linhas e 3 colunas possíveis de serem marcadas com o símbolo 'X' ou 'O'.
* As jogadas serão alternadas entre os jogadores realizando uma marcação por vez, numa lacuna que esteja vazia.
* O jogo tem sua conclusão assim que um dos jogadores conseguir formar primeiro uma linha com três símbolos iguais, seja ela na horizontal, vertical ou diagonal assim sendo o vitorioso ou quando todos os espaços são ocupados assim gerando um empate.

## Atores

Os atores desse caso de uso serão o jogador 1 e jogador 2 ou a maquina.

## Pré-Condições

O jogo deve ser desenvolvido em C++ e todo o software deve ser orientado a objetos.

## Fluxo principal

1. Selecionar o modo de jogo(1 jogador ou 2 jogadores)
2. O jogador 1 inicia o jogo selecionando a primeira lacuna desejada, assim as jogadas devem ser intercaladas até a conclusão do mesmo.
3. Conclusão do jogo mostrando qual foi o resultado do jogo sendo vitoria ou empate e indicando, qual o jogador vencedor.

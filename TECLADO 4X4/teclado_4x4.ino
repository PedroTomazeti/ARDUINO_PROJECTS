#include <Keypad.h>
//Biblioteca para ler os cliques dos botões do teclado

const byte LINHAS = 4; // Quantidade de Linhas do teclado
const byte COLUNAS = 4; // Quantidade de Colunas do teclado

byte PINOS_LINHAS[LINHAS] = {9, 8, 7, 6};//Pinos das linhas
byte PINOS_COLUNAS[COLUNAS] = {5, 4, 3, 2};//Pinos dos teclados


char TECLAS_MATRIZ[LINHAS][COLUNAS] = {//Mapeamento de valores do teclado 4x4
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};



Keypad teclado_personalizado = Keypad(makeKeymap(TECLAS_MATRIZ), PINOS_LINHAS, PINOS_COLUNAS, LINHAS, COLUNAS); // Inicia teclado
//Configuração do teclado e seus valores
void setup() {
  Serial.begin(9600); //Inicialização do monitor serial
}

void loop() {

  char leitura_teclas = teclado_personalizado.getKey();
  //Atribuindo variável para receber os valores pressionaods	
  if (leitura_teclas) {
  	//Analisa se existe algum valor dentro da variável  
    Serial.print("Tecla Pressionada: ");
    Serial.print(leitura_teclas);
    Serial.println("");
    delay(300);
    //Delay para processamento
  }
  
}
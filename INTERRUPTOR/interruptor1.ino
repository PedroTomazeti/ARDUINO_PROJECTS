
#define BUTTON 3
//Definindo o Pino do Push Button
#define powerCtrl 2 
//Definindo o Pino do transistor

int pressionado = 0;//Variável para analisar o nível lógico do Push Button
int ligada = 0;//Variável para analisar o nível lógico do Pino 2

void setup()
{

  	pinMode(powerCtrl, OUTPUT);
  	pinMode(BUTTON, INPUT);
  	//Configuração de todos os pinos
  	//O transistor funcionará como uma "chave"
}

void loop()
{
 	pressionado = digitalRead(BUTTON);
  	//Atribuindo o nível lógico do botão para a variável
  	if( pressionado == HIGH ){//Se o botão for pressionado, entrará na análise de Switch
		delay(200);//Delay para processamento da informação
      switch(ligada){
        case 0:
        	digitalWrite(powerCtrl, HIGH);
        //Arduino emitindo corrente para ativar a "chave" no transistor
        	ligada = 1;
        //Como o valor inicial de "ligada" já é zero, neste instante
        //Vai ser fechada a "chave" e permitirá a passagem de corrente para a lâmpada
        	break;
        
        case 1:
        //No Case passado "ligada" assumirá o valor 1 para vim neste
        //Case e poder ser feito o desligamento da lâmpada
         	digitalWrite(powerCtrl, LOW);
        //Arduino desligando a corrente transmitida para o transitor
        	ligada = 0;
        	break;
      }
  }
}
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int ctrlc_counter=0; //variavel que armazena os CTRL+C

void SIGTSTP_handler(){
  printf("\nCTRL_C = %d\n",ctrlc_counter); //Printa o numero de CTRL+C apertados
}

void SIGINT_handler(){
  printf("\n");
  ctrlc_counter++; //Incrementa o numero de CTRL+C
}

int main() {
  pid_t PID=getpid();
  char x;
  //printf("PID = %ld\n",(long)PID); //informa o PID atual
  
  signal(SIGINT,SIGINT_handler);
  signal(SIGTSTP,SIGTSTP_handler);
  
  for(;;){ 
    if(ctrlc_counter>=10){
      alarm(5); //5seg depois o programa finaliza
      printf("\nReally Exit? (Y/N)\n");
      x = getchar(); //recebe Y/N
      if(x=='y'||x=='Y'){
        kill(PID,SIGKILL); //Y termina o programa
      }
      else if(x=='n'||x=='N'){
        ctrlc_counter=0; //N reseta o contador
        alarm(0); //reseta o alarme
      }
    }
  }
  return 0;
}
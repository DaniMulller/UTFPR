public class simulador{
  public static void main(String args[]){
    int qtd=0;
    Veiculo[] veiculos = new Veiculos[20];
    public void menu(){

    }
    public void incluirVeiculo(String a){
      if(qtd<20){
        if(a.equals("B")||a.equals("b")){
          veiculos[qtd]=new Veiculo(qtd,2);
          qtd++;
        }
        else if(a == M){
          veiculos[qtd]=new Veiculo(qtd,2);
          qtd++;
        }
        else if(a == C){
          veiculos[qtd]=new Veiculo(qtd,4);
          qtd++;
        }
        else if(a == F){
          veiculos[qtd]=new Veiculo(qtd,4);
          qtd++;
        }
        else{
          println("\nInsira um veiculo VALIDO!\n");
        }
    }
    else{
      println("\nNumero Max de Veiculos Atingido!\n");
    }
   }
  }
}

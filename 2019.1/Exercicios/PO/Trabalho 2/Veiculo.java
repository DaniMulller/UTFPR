public abstract class Veiculo{
  private int id;
  private int distanciaPercorrida;
  private Roda[] rodas;
  private int quantidadeRodas;

  public Veiculo(int x,int qtd){
    this.id = x;
    this.distanciaPercorrida = 0;
    this.quantidadeRodas = qtd;
    rodas = new Roda[qtd];
    for(int i=0;i<qtd;i++){
      rodas[i]=new Roda(true);
    }
  }
  abstract void mover();
  abstract void desenhar();
  public void calibrarPneu(int x){

  }
  public String toString(){
    return "Id: "+id+"\nDistancia Percorrida: "+distanciaPercorrida+"\nQTD de Rodas: "+quantidadeRodas;
  }
}

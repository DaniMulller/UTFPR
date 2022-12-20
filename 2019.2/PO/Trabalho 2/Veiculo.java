public abstract class Veiculo{
  private int id;
  private int distanciaPercorrida;
  private Roda[] rodas;
  private int quantidadeRodas;
  public Veiculo(int id,int quantidadeRodas){
    this.quantidadeRodas=quantidadeRodas;
    rodas = new Roda[quantidadeRodas];
    for(int i=0;i<quantidadeRodas;i++)
      rodas[i]=new Roda();
    distanciaPercorrida=0;
    this.id=id;
  }
  public abstract void mover();
  public String toString(){
    String s="";
    s+="+ Rodas nao calibradas (x)   ";
    for(int i=0;i<quantidadeRodas;i++)
      s+=(i+1)+" ";
    s+="  \n+                            ";
    for(int i=0;i<quantidadeRodas;i++)
    {
      if(!rodas[i].getCalibragem())//se não está calibrado
        s+="x ";
      else//se está
        s+="  ";
    }
    s+="  \n";
    return "+ ID: "+(id+1)+"\n+ Distancia Percorrida: "+distanciaPercorrida+"\n"+s;
  }
  public abstract void desenhar();
  public void calibrarPneu(int pneu){
    rodas[pneu].setCalibragem(true);
  }
  public void esvaziarPneu(int pneu){
    rodas[pneu].setCalibragem(false);
  }
  public String retornaEspacos(){
    String s="";
    for(int i=0;i<distanciaPercorrida;i++)
      s=s+" ";
    return s;
  }
  public void deslocar(int unidades){
    distanciaPercorrida+=unidades;
  }
  public int estaCalibrado(){//retorna -1 se os pneus estão calibrados ou o indice do primeiro pneu nao calibrado
    for(int i=0;i<quantidadeRodas;i++)
      if(!rodas[i].getCalibragem())
        return i;
    return -1;
  }
  public void mostraCalibragem(){
    System.out.print("Rodas não calibradas (x) : ");
    for(int i=0;i<quantidadeRodas;i++)
      System.out.print((i+1)+" ");
    System.out.print(" :\n                         : ");
    for(int i=0;i<quantidadeRodas;i++)
    {
      if(!rodas[i].getCalibragem())//se não está calibrado
        System.out.print("x ");
      else//se está
        System.out.print("  ");
    }
    System.out.print(" :\n");
  }
  public int getID(){
    return id;
  }
}

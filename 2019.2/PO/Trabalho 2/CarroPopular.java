public class CarroPopular extends VeiculoMotorizado implements IPVA{
  public CarroPopular(int id){
    super(id,4);
  }
  public String toString(){
    return "(carro popular)\n"+super.toString();
  }
  public void mover(){
    int aux=estaCalibrado();
    if(super.getIPVA()==true){
      if(aux!=-1){
        System.out.println("[!] Erro: o pneu de numero "+(aux+1)+" nao esta calibrado! (ID veiculo: "+(getID()+1)+")");
        return;
      }
      if(getCombustivel()<(float)3.75){
        System.out.println("[!] Erro: veiculo sem combustivel suficiente! (ID veiculo: "+(getID()+1)+")");
        return;
      }
      abastecer((float)-3.75);
      deslocar(5);
      System.out.println("[!] O veiculo foi movido com sucesso! (ID veiculo: "+(getID()+1)+")");
    }
    else{
      System.out.println("[!] Erro: IPVA nao esta pago! (ID veiculo: "+(getID()+1)+")");
    }
  }
  public void desenhar(){
    String s=retornaEspacos();
    System.out.print(s+"    ____\n");
    System.out.print(s+" __/  |_ \\_\n"); // \_\n");
    System.out.print(s+"|  _     _``-.\n");
    System.out.print(s+"'-(_)---(_)--'\n\n");
  }
  public double calcularIPVA(){
    return valor_base*cte_CarroPopular;
  }
}

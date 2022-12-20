public class Motocicleta extends VeiculoMotorizado implements IPVA{
  public Motocicleta(int id){
    super(id,2);
  }
  public String toString(){
    return "(motocicleta)\n"+super.toString();
  }
  public void desenhar(){
    String s=retornaEspacos();
    System.out.print(s+"   ,_oo\n");
    System.out.print(s+".-/c-//::\n");
    System.out.print(s+"(_)'==(_)\n\n");
  }
  public void mover(){
    int aux=estaCalibrado();
    if(super.getIPVA()==true){
      if(aux!=-1){
        System.out.println("[!] Erro: o pneu de numero "+(aux+1)+" nao esta calibrado! (ID veiculo: "+(getID()+1)+")");
        return;
      }
      if(getCombustivel()<(float)0.75){
        System.out.println("[!] Erro: veiculo sem combustivel suficiente! (ID veiculo: "+(getID()+1)+")");
        return;
      }
      abastecer((float)-0.75);
      deslocar(3);
      System.out.println("[!] O veiculo foi movido com sucesso! (ID veiculo: "+(getID()+1)+")");
    }
    else{
      System.out.println("[!] Erro: IPVA nao esta pago! (ID veiculo: "+(getID()+1)+")");
    }
  }
  public double calcularIPVA(){
    return valor_base*cte_Motocicleta;
  }
}

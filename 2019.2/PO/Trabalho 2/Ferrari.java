public class Ferrari extends VeiculoMotorizado implements IPVA{
  public Ferrari(int id){
    super(id,4);
  }
  public String toString(){
    return "(ferrari)\n"+super.toString();
  }
  public void desenhar(){
    String s=retornaEspacos();
    System.out.print(s+"        __         \n");
    System.out.print(s+"      ~( @\\ \\   \n");
    System.out.print(s+"   _____]_[_/_>__   \n");
    System.out.print(s+"  / __ \\<> |  __ \\      \n");
    System.out.print(s+"=\\_/__\\_\\__|_/__\\_D\n");
    System.out.print(s+"   (__)      (__)    \n\n");
  }
  public void mover(){
    if(super.getIPVA()==true){
      int aux=estaCalibrado();
      if(aux!=-1){
        System.out.println("[!] Erro: o pneu de numero "+(aux+1)+" nao esta calibrado! (ID veiculo: "+(getID()+1)+")");
        return;
      }
      if(getCombustivel()<(float)23){
        System.out.println("[!] Erro: veiculo sem combustivel suficiente! (ID veiculo: "+(getID()+1)+")");
        return;
      }
      abastecer((float)-23);//removendo 2.3 litros de gasolina (consumidos)
      deslocar(10);//movendo o veiculo 10 blocos
      System.out.println("[!] O veiculo foi movido com sucesso! (ID veiculo: "+(getID()+1)+")");
   }
   else{
     System.out.println("[!] Erro: IPVA nao esta pago! (ID veiculo: "+(getID()+1)+")");
   }
  }

  public double calcularIPVA(){
    return valor_base*cte_Ferrari;
  }
}

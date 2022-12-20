public class Bicicleta extends Veiculo{
  public Bicicleta(int id){
    super(id,2);
  }
  public void mover(){
    int aux=estaCalibrado();
    if(aux!=-1){
      System.out.println("[!] Erro: o pneu de numero "+(aux+1)+" nao esta calibrado! (ID veiculo: "+(getID()+1)+")");
      return;
    }
    deslocar(2);
    System.out.println("[!] O veiculo foi movido com sucesso! (ID veiculo: "+(getID()+1)+")");
  }
  public String toString(){
    return "(bicicleta)\n"+super.toString();
  }
  public void desenhar(){
    String s=retornaEspacos();
    System.out.print(s+"   __o\n");
    System.out.print(s+" _`\\<,_\n");
    System.out.print(s+"(*)/ (*)\n\n");
  }
}

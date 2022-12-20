public class Carro{
  private String marca;
  private Motor propulsor;

  public Carro(String n,Motor mo){
    marca = n;
    propulsor = mo;
  }

  public void acelerar(int v){
    propulsor.acelerar(v);
  }

  public String toString(){
    return "Sou um carro da marca "+marca+".\nEu tenho um motor com a seguinte conf.:"+propulsor;
  }
}

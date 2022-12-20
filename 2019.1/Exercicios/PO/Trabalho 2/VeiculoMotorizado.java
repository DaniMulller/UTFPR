public abstract class VeiculoMotorizado extends Veiculo{
  private static float gastoMotocicleta = (float)0.25;
  private static float gastoCarro = (float)0.75;
  private static float gastoFerrari= (float)2.3;
  private float combustivel;

  public VeiculoMotorizado(){
    this.combustivel = (float)3.5;
  }
  public void abastecer(float comb){
    this.combustivel += comb;
  }
  public String toString(){
    return "Combustivel: "+combustivel;
  }
}

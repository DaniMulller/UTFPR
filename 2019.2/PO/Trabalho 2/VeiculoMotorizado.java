import java.util.Random;
public class VeiculoMotorizado extends Veiculo{
  private static float gastoMotocicleta= (float) 0.25;
  private static float gastoCarro=(float)0.75;
  private static float gastoFerrari=(float)2.3;
  private boolean IPVApago;
  private float combustivel;
  public VeiculoMotorizado(int id,int quantidadeRodas){
    super(id,quantidadeRodas);
    combustivel=(float)3.5;
    Random gerador = new Random();
    if(gerador.nextInt(101)%2==0)
      IPVApago=false;
    else
      IPVApago=true;
  }
  public void abastecer(float combustivel){
    this.combustivel+=combustivel;
  }
  public String toString(){
    if(IPVApago==true){
      return "+ Combustivel restante: "+combustivel+"\n+ IPVA: PAGO\n"+super.toString();
    }
    return "+ Combustivel restante: "+combustivel+"\n+ IPVA: NAO PAGO\n"+super.toString();
  }
  public float getCombustivel(){ return combustivel;}
  public boolean getIPVA(){return IPVApago;}
  public void desenhar(){}
  public void mover(){}
}

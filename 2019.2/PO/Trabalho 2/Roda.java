import java.util.Random;
public class Roda{
  private boolean calibragemPneu;
  public Roda(){
    Random gerador = new Random();
    if(gerador.nextInt(101)%2==0)
      calibragemPneu=false;
    else
      calibragemPneu=true;
  }
  public void setCalibragem(boolean calibragemPneu){
    this.calibragemPneu=calibragemPneu;
  }
  public boolean getCalibragem(){
    return calibragemPneu;
  }
}

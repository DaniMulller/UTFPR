import java.util.Random;//CABO
public class Dado{//ok
  private int sideUp;//ok
  public Dado(){
    sideUp=0;
  }
  public void roll(){//OK
    Random gerador = new Random();
    sideUp = gerador.nextInt(6)+1;
  }
  public int getSideUp(){//ok
    return sideUp;
  }
  public String toString(){//ok
    return "Numero do dado: "+sideUp;
  }
}

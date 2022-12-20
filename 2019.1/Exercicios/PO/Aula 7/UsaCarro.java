public class UsaCarro{
  public static void main(String[] argumentos){
    Carro myCar = new Carro("Mini Cooper",new Motor(10,15));

    System.out.println(myCar);
    myCar.acelerar(50);
  }
}

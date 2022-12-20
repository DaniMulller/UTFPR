public class Motor{
  private int[] parafusetas;
  private float[] rebimbocas;

  public Motor(int q1,int q2){
    parafusetas = new int[q1];
    rebimbocas = new float[q2];
  }

  public void acelerar(int i){
    System.out.println("Estou acelerando a "+i+" de intensidade");
  }
  public String toString(){
    return "Sou motor com "+parafusetas.length+" parafusetas e "+rebimbocas.length+" rebimbocas";
  }
}

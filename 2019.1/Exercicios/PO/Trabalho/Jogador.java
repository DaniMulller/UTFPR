import java.util.Scanner;
public class Jogador{
  private String nome;
  private JogoGeneral jogoG;
  //...
  public Jogador(String name){
    nome=name;
    jogoG = new JogoGeneral();
  }
  public void jogarDados(){
    jogoG.rolarDados();
  }
  public String toString(){
    return nome;
  }
  public void mostraJogadasExecutadas(){
    jogoG.mostrarJogadas();//como não podemos acessar o vetor de jogadas, criei uma função que faz isso dentro da classe JogoGeneral
  }
  public void escolherJogada(){
    int jogada;
    Scanner teclado = new Scanner(System.in);//usada para ler as entradas
    System.out.println("para qual jogada deseja marcar: [1 - 13] "+nome+"?");
    mostraJogadasExecutadas();
    System.out.print(">");
    jogada=teclado.nextInt();
    while(!jogoG.validarJogada(jogada)){
      System.out.print("\nInforme uma jogada válida [1-13] ainda não utilizada!\n>");
      jogada=teclado.nextInt();
    }
  }
}

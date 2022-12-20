import java.util.Scanner;
import java.io.Serializable;
public class Jogador implements Serializable{
  private String nome;
  private JogoGeneral jogoG;
  private int indice;
  public Jogador(int indice, String name){//correto!
    nome=name;
    jogoG = new JogoGeneral();
    this.indice = indice;
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
  public int[] escolherJogada(){
    Scanner teclado = new Scanner(System.in);//usada para ler as entradas
    System.out.println("para qual jogada deseja marcar: [1 - 13] "+nome+"?");
    mostraJogadasExecutadas();
    System.out.print("\n>");
    int jogada=teclado.nextInt();
    while(!jogoG.validarJogada(jogada)){
      System.out.print("\ninforme uma jogada valida [1-13] ainda nao utilizada!\n>");
      jogada=teclado.nextInt();
    }
	jogoG.pontuarJogada(jogada);
  return jogoG.retornaJogadas();
  }
  public void zerarJogadas(){
	 jogoG.zerarArraydeJogadas();
  }
  public int retornaIndice(){
    return indice;
  }
  public int retornaPontuacaoTotal(){
    return jogoG.retornaSoma();
  }
  public String retornaDados(){
    return jogoG.toString();
  }
}

import java.io.Serializable;
import java.io.File;
import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.io.FileInputStream;
import java.io.ObjectInputStream;
import java.util.Scanner;
public class Campeonato implements Serializable{
  private static Jogador[] jogadores;
  private static int[][] cartela;//FAZER
  //...
  public static void main(String[] args){
    jogadores = new Jogador[5];//criando o array de jogadores
    cartela = new int[5][13];

    char opcao;//usado para saber a função
    Scanner teclado = new Scanner(System.in);//usada para ler as entradas
    System.out.println("-------------------- JogoGeneral -----------------------");
    System.out.println("Opções:");
    System.out.println("(a) Incluir jogador\n(b) Remover jogador (pelo nome)\n(c) Iniciar/reiniciar o campeonato\n(d) Mostrar a cartela de resultados\n(e) Gravar os dados do campeonato em arquivo\n(f) Ler os dados do campeonato em arquivo\n(g) Sair da aplicação\n");
    System.out.println("Selecione uma opção válida:\n");
    do{//enquanto não pedir para sair da função
      opcao = teclado.next().charAt(0);
      switch(opcao){
        case 'a':
          System.out.println(opcao);
          System.out.println("(a) -> Insira o nome do jogador:\n");
          incluirJogador();
          break;
        case 'b':
          System.out.println(opcao);
          System.out.println("(b) -> Insira o nome do jogador:\n");
          removerJogador();
          break;
        case 'c':
          break;
        case 'd':
          break;
        case 'e':
          System.out.println(opcao);
          System.out.println("Gravando em arquivo...");
          gravarEmArquivo();
          break;
        case 'f':
          System.out.println(opcao);
          System.out.println("Lendo do arquivo...");
          lerDoArquivo();
          break;
        case 'g':
          System.out.println("Saindo...");
          break;
        default:
          System.out.println("Função inexistente, tente novamente!");
      }
    }while(opcao!='g');
  }
  public static void incluirJogador()
  {
    Scanner teclado = new Scanner("System.in");
    for(Jogador j: jogadores){
      if(j==null){
        System.out.print(">Nome d@ jogador@: ");
        j=new Jogador(teclado.nextLine());
      }
    }
    System.out.println("O número máximo de jogadores já foi alcançado!");
  }
  public static void removerJogador()
  {
    Scanner teclado = new Scanner("System.in");
    System.out.print(">Nome d@ jogador@ a ser removid@: ");
    String player = teclado.nextLine();
    for(Jogador j:jogadores)
      if(player.toString().equalsIgnoreCase(j.toString()))
        j=null;
  }
  public static void gravarEmArquivo(){
    File arquivo = new File("jogadores.dat");
    try{
      FileOutputStream fout = new FileOutputStream(arquivo);
      ObjectOutputStream oos = new ObjectOutputStream(fout);
      oos.writeObject(jogadores);
      oos.flush();
      oos.close();
    }catch(Exception ex){
      System.err.println("erro: "+ex.toString());
    }
    File arquivo2 = new File("cartela.dat");
    try{
      FileOutputStream fout = new FileOutputStream(arquivo2);
      ObjectOutputStream oos = new ObjectOutputStream(fout);
      oos.writeObject(cartela);
      oos.flush();
      oos.close();
    }catch(Exception ex){
      System.err.println("erro: "+ex.toString());
    }
  }
  public static void lerDoArquivo(){
    File arquivo = new File("jogadores.dat");
    try{
      FileInputStream fin = new FileInputStream(arquivo);
      ObjectInputStream oin = new ObjectInputStream(fin);
      Jogador[] jogadoresArq = (Jogador[])oin.readObject();
      oin.close();
      fin.close();
    }catch(Exception ex){
      System.err.println("erro: "+ex.toString());
    }
    File arquivo2 = new File("cartela.dat");
    try{
      FileInputStream fin = new FileInputStream(arquivo2);
      ObjectInputStream oin = new ObjectInputStream(fin);
      int[] cartelaArq = (int[])oin.readObject();
      oin.close();
      fin.close();
    }catch(Exception ex){
      System.err.println("erro: "+ex.toString());
    }
  }
  /*
  public static void iniciarCampeonato()//FAZER
  public static void mostrarCartela(){
    int i;

  }
  */
}

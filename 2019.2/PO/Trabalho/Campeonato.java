import java.io.File;
import java.io.FileInputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.FileOutputStream;
import java.util.Scanner;
public class Campeonato{
  private static Jogador[] jogadores;
  private static int[][] cartela;//FAZER
  public static void main(String[] args){
    jogadores = new Jogador[5];//criando o array de jogadores
    cartela = new int[5][13];
    char opcao;//usado para saber a função
    Scanner teclado = new Scanner(System.in);//usada para ler as entradas

    System.out.println("-------------------- JogoGeneral -----------------------");
    System.out.println("Opcoes:");
    System.out.println("(a) Incluir jogador\n(b) Remover jogador (pelo nome)\n(c) Iniciar/reiniciar o campeonato\n(d) Mostrar a cartela de resultados\n(e) Gravar os dados do campeonato em arquivo\n(f) Ler os dados do campeonato em arquivo\n(g) Sair da aplicacao\n");
    System.out.println("Selecione uma opcao valida:\n");
    do{//enquanto não pedir para sair da função
      System.out.print("entre com a opcao do menu: ");
      opcao = teclado.nextLine().charAt(0);
      switch(opcao){
        case 'a'://CHECK
          incluirJogador();
          break;
        case 'b'://CHECK (dúvida: devemos comparar considerando case ou não? ("nome"=="noME"?))
          removerJogador();
          break;
        case 'c'://CHECK
          iniciarCampeonato();
          break;
        case 'd'://CHECK
          mostrarCartela();
          break;
        case 'e'://CHECK
          System.out.println("Gravando em arquivo...");
          gravarEmArquivo();
          break;
        case 'f'://CHECK
          System.out.println("Lendo do arquivo...");
          lerDoArquivo();
          break;
        case 'g'://CHECK
          System.out.println("Saindo...");
          break;
        default://CHECK
          System.out.println("Função inexistente, tente novamente!");
      }
    }while(opcao!='g');//enquanto não pedir para sair

  }
  public static void incluirJogador()//PRONTO!
  {
    Scanner teclado = new Scanner(System.in);
    String nome;
    for(int i=0;i<5;i++)
    {
      if(jogadores[i]==null){
        System.out.print(">Nome d@ jogador@: ");
        nome=teclado.nextLine();
        jogadores[i]=new Jogador(i,nome);//instanciando o novo jogador com o nome desejado
        for(int j=0;j<13;j++)
          cartela[i][j]=-1;
        return;//saindo do método
      }
    }
    System.out.println("O numero maximo de jogadores ja foi alcancado!");//caso não consiga achar espaço para o novo jogador, apenas esta mensagem é mostrada
  }
  public static void removerJogador()//PRONTA !
  {
    Scanner teclado = new Scanner(System.in);
    System.out.print(">Nome d@ jogador@ a ser removid@: ");
    String player = teclado.nextLine();
    //usar for(Jogador j:jogadores) não funciona nesse caso, por queremos ALTERAR diretamente o vetor 'jogadores'
    for(int i=0;i<5;i++)
    {
      if(jogadores[i]!=null&&player.equalsIgnoreCase(jogadores[i].toString()))//se a String lida (player) corresponder ao nome salvo (j.toString()), remove-se o jogador.
      {
        jogadores[i]=null;
        return;
      }
    }
    System.out.println("O jogador "+player+" nao pode ser encontrado!");
  }
  public static void iniciarCampeonato(){
    zerarCartela();//zerando a cartela de pontuação
    for(Jogador j:jogadores)//zerando os arrays de jogadas e variavel soma
      if(j!=null)
        j.zerarJogadas();
    for(int i=0;i<13;i++)//repetindo por 13 rodadas
    {
      for(int j=0;j<5;j++)//emulando a vez de cada jogador
      {
        if(jogadores[j]!=null)//se for um jogador válido
        {
          System.out.println("rolando os dados para "+jogadores[j].toString()+"...");
          jogadores[j].jogarDados();//rolando os dados
          System.out.println("Valores obtidos: "+jogadores[j].retornaDados());
          cartela[jogadores[j].retornaIndice()]=jogadores[j].escolherJogada();//atualizando a cartela de pontuação
        }
      }
    }
  }//PARECE OK
  public static void mostrarCartela(){//ACHO QUE ESTA OK

    System.out.print("-- Cartela de Resultados --\n\t");
    for(Jogador j:jogadores)//printando o nome dos jogadores
      if(j!=null)
        System.out.print(j.toString()+"\t");
    System.out.println();

    for(int i=0;i<13;i++){
      System.out.print(i+1);//as primeiras 6 jogadas necessitam apenas do número
      if(i==6)//jogada 7
        System.out.print("(T)");
      else if(i==7)//jogada 8
        System.out.print("(Q)");
      else if(i==8)//jogada 9
        System.out.print("(F)");
      else if(i==9)//jogada 10
        System.out.print("(S+)");
      else if(i==10)//jogada 11
        System.out.print("(S-)");
      else if(i==11)//jogada 12
        System.out.print("(G)");
      else if(i==12)//jogada 13
        System.out.print("(X)");
      System.out.print("\t");//para qualquer jogada, a tabulação é usada
      for(Jogador j:jogadores){
        if(j!=null){
          if(cartela[j.retornaIndice()][i]!=-1)//se é uma jogada já utilizada
            System.out.print(cartela[j.retornaIndice()][i]);
          System.out.print("\t");
        }
      }
      System.out.println();//quebrando a linha no fim do for exterior
    }
    //printando pontuação total de cada jogador
    System.out.print("----------------------------\nTotal\t");
    for(Jogador j:jogadores){
      if(j!=null){
        System.out.print(j.retornaPontuacaoTotal()+"\t");
      }
    }
    System.out.println();
  }
  public static void gravarEmArquivo(){

    //GRAVANDO O ARRAY DE JOGADORES EM ARQUIVO
    File players = new File("jogadores.dat");
    try{
      FileOutputStream fout= new FileOutputStream(players);
      ObjectOutputStream oos = new ObjectOutputStream(fout);

      oos.writeObject(jogadores);
      oos.flush();
      oos.close();
      fout.close();
    }
    catch (Exception ex) {
      System.err.println("erro: "+ex.toString());
    }

    //GRAVANDO O ARRAY DAS CARTELAS COM AS PONTUAÇÕES DOS JOGADORES
    File cart = new File("cartela.dat");
    try{
      FileOutputStream fout= new FileOutputStream(cart);
      ObjectOutputStream oos = new ObjectOutputStream(fout);

      oos.writeObject(cartela);
      oos.flush();
      oos.close();
      fout.close();
    }
    catch (Exception ex) {
      System.err.println("erro: "+ex.toString());
    }

  }
  public static void lerDoArquivo(){
    try{
      File arquivo = new File("jogadores.dat");
      FileInputStream fin= new FileInputStream(arquivo);
      ObjectInputStream oin = new ObjectInputStream(fin);
      jogadores = (Jogador[]) oin.readObject();
      oin.close();
      fin.close();
    }
    catch (Exception ex){
      System.err.println("erro: "+ex.toString());
    }
    try{
      File arquivo = new File("cartela.dat");
      FileInputStream fin= new FileInputStream(arquivo);
      ObjectInputStream oin = new ObjectInputStream(fin);
      cartela = (int[][]) oin.readObject();
      oin.close();
      fin.close();
    }
    catch (Exception ex){
      System.err.println("erro: "+ex.toString());
    }
  }
  public static void zerarCartela(){
    for(int i=0;i<5;i++)
      for(int j=0;j<13;j++)
        cartela[i][j]=-1;
  }//OK

}

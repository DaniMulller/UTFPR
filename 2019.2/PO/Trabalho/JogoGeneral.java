import java.io.Serializable;
public class JogoGeneral implements Serializable{//CABO
  private Dado[] dados;
  private int[] jogadas;
  private int soma;//usado para salvar a soma das jogadas
  public JogoGeneral(){
    dados= new Dado[5];
    for(int i=0;i<5;i++)
      dados[i]= new Dado();
    jogadas = new int[13];
    for(int i=0;i<13;i++)
      jogadas[i]=-1;//quando a jogada ainda não foi utilizada, guardará -1 pontos (número de controle).
    soma=0;//a pontuação total de cada jogador inicia-se zerada
  }//método CONSTRUTOR
  public void rolarDados(){
    for(int i=0;i<5;i++)
      dados[i].roll();
  }//executa a randomização dos dados
  public String toString(){// retorna uma string com os números obtidos
    return dados[0].getSideUp()+"-"+dados[1].getSideUp()+"-"+dados[2].getSideUp()+"-"+dados[3].getSideUp()+"-"+dados[4].getSideUp();
  }
  public int somaDados(){
    return dados[0].getSideUp()+dados[1].getSideUp()+dados[2].getSideUp()+dados[3].getSideUp()+dados[4].getSideUp();
  }//retorna a soma das faces superiores dos dados
  public boolean validarJogada(int jogada){
    if(0<jogada&&jogada<=13)
      if(jogadas[jogada-1]==-1)
        return true;
    return false;
  }//retorna se a jogada é valida ou não
  public int[] retornaJogadas(){
    return jogadas;
  }//retorna o vetor de jogadas (para ser copiado na cartela)
  public String printarJogada(int i){
      if(jogadas[i-1]==-1)
        return "-";
      return "x";
  }//printa//usada na função 'mostrarJogadas()' para facilitar
  public void mostrarJogadas(){
    System.out.println("1 2 3 4 5 6 7(T) 8(Q) 9(F) 10(S+) 11(S-) 12(G) 13(X)");
    System.out.print(printarJogada(1)+" "+printarJogada(2)+" "+printarJogada(3));
    System.out.print(" "+printarJogada(4)+" "+printarJogada(5)+" "+printarJogada(6));
    System.out.print("  "+printarJogada(7)+"    "+printarJogada(8)+"    ");
    System.out.print(printarJogada(9)+"     "+printarJogada(10)+"      ");
    System.out.print(printarJogada(11)+"      "+printarJogada(12)+"     "+printarJogada(13));
  }//mostra as jogadas utilizadas e ainda não utilizadas
  public void pontuarJogada(int m)//pontua a jogada de acordo com as regras
  {
    int k=0;
    int j=0;
    int aux[]=new int[6];
    switch(m)
    {
      case 1:
        k=0;
        for(Dado dado:dados)
          if(dado.getSideUp()==1)
            k++;
        jogadas[0]=k;
        soma+=jogadas[0];
        if(jogadas[0]==0)
          System.out.println("seus valores nao cumprem o requisito para esta jogada!");
        break;
      case 2:
        k=0;
        for(Dado dado:dados)
          if(dado.getSideUp()==2)
            k++;
        jogadas[1]=2*k;
        soma+=jogadas[1];
        if(jogadas[1]==0)
          System.out.println("seus valores nao cumprem o requisito para esta jogada!");
        break;
      case 3:
        k=0;
        for(Dado dado:dados)
          if(dado.getSideUp()==3)
            k++;
        jogadas[2]=3*k;
        soma+=jogadas[2];
        if(jogadas[2]==0)
          System.out.println("seus valores nao cumprem o requisito para esta jogada!");
        break;
      case 4:
        k=0;
        for(Dado dado:dados)
          if(dado.getSideUp()==4)
            k++;
        jogadas[3]=4*k;
        soma+=jogadas[3];
        if(jogadas[3]==0)
          System.out.println("seus valores nao cumprem o requisito para esta jogada!");
        break;
      case 5:
        k=0;
        for(Dado dado:dados)
          if(dado.getSideUp()==5)
            k++;
        jogadas[4]=5*k;
        soma+=jogadas[4];
        if(jogadas[4]==0)
          System.out.println("seus valores nao cumprem o requisito para esta jogada!");
        break;
      case 6://Jogada de 6
        k=0;
        for(Dado dado:dados)
          if(dado.getSideUp()==6)
            k++;
        jogadas[5]=6*k;
        soma+=jogadas[5];
        if(jogadas[5]==0)
          System.out.println("seus valores nao cumprem o requisito para esta jogada!");
        break;
      case 7://conferir / Trinca (T)
        for(int i=0;i<3;i++){
          k=0;
          for(j=i+1;j<5;j++)
          {
            if(dados[j].getSideUp()==dados[i].getSideUp())
              k++;
          }
          if(k>=2)
          {
            i=3;
            jogadas[6]=somaDados();
          }
        }
        if(k<2)
        {
          jogadas[6]=0;
          System.out.println("seus valores nao cumprem o requisito para esta jogada!");
        }
        soma+=jogadas[7];
        break;
      case 8://Quadra(Q)
        for(int i=0;i<2;i++){
          k=0;
          for(j=i+1;j<5;j++)
          {
            if(dados[j].getSideUp()==dados[i].getSideUp())
              k++;
          }
          if(k>=3)
          {
            i=2;
            jogadas[7]=somaDados();
          }
        }
        if(k<3)
        {
          jogadas[7]=0;
          System.out.println("seus valores nao cumprem o requisito para esta jogada!");
        }
        soma+=jogadas[7];
        break;
        case 9://Full house (F)
          jogadas[8]=0;
          for(int i=0;i<6;i++)//declarando posições como zero
            aux[i]=0;
          for(Dado dado:dados){
            aux[dado.getSideUp()-1]++;
          }
          for(int i=0;i<5;i++){
            if(aux[i]==2){
              for(j=i+1;j<6;j++){
                if(aux[j]==3){
                  jogadas[8]=25;
                  i=10;
                  j=10;
                }
              }
            }
            else if(aux[i]==3){
              for(j=i+1;j<6;j++){
                if(aux[j]==2){
                  jogadas[8]=25;
                  i=10;
                  j=10;
                }
              }
            }
          }
          if(jogadas[8]==0)
            System.out.println("seus valores nao cumprem o requisito para esta jogada!");
          soma+=jogadas[8];
          break;
      case 10://Sequência alta (S+)
        for(int i=0;i<6;i++)
          aux[i]=0;//declarando todos os elementos como zero, pois aux é vetor CONTADOR
        for(Dado dado:dados)
          aux[dado.getSideUp()-1]++;//o indice [i-1] representam o numero de vezes que o número i aparece.
        jogadas[9]=30;
        for(int i=0;i<6;i++)
          if(aux[i]!=1&&i!=0)
            jogadas[9]=0;
        if(jogadas[9]==0)
          System.out.println("seus valores nao cumprem o requisito para esta jogada!");
        soma+=jogadas[9];
        break;
      case 11://Sequência baixa (S-)
        jogadas[10]=40;
        for(int i=0;i<6;i++)
          aux[i]=0;//declarando todos os elementos como zero, pois aux é vetor CONTADOR
        for(Dado dado:dados)
          aux[dado.getSideUp()-1]++;//o indice [i-1] representam o numero de vezes que o número i aparece.
        for(int i=0;i<6;i++)
          if(aux[i]!=1&&i!=5)//o único indice que pode ser diferente de 1 é o indice 5 (número 6)
            jogadas[10]=0;
        if(jogadas[10]==0)
          System.out.println("seus valores nao cumprem o requisito para esta jogada!");
        soma+=jogadas[10];
        break;
      case 12://General (G)
        jogadas[11]=0;
        if(dados[0].getSideUp()==dados[1].getSideUp()&&dados[1].getSideUp()==dados[2].getSideUp()&&dados[2].getSideUp()==dados[3].getSideUp()&&dados[3].getSideUp()==dados[4].getSideUp())
          jogadas[11]=50;
        if(jogadas[11]==0)
          System.out.println("seus valores nao cumprem o requisito para esta jogada!");
        soma+=jogadas[11];
        break;
      case 13://Jogada aleatória (X)
        jogadas[12]=somaDados();
        soma+=jogadas[12];
        break;
    }
  }
  public void zerarArraydeJogadas(){
	  for(int i=0;i<13;i++)//usada ao iniciar/reiniciar o Campeonato
		  jogadas[i]=-1;
    soma=0;
  }//usado para "zerar" o array de jogadas e a soma//usada para resetar os arrays e a variavel soma
  public int retornaSoma(){
    return soma;//a soma é usada ao mostrar a cartela de pontuação
  }//retorna a Soma das Pontuações//retorna a soma total das pontuações
}

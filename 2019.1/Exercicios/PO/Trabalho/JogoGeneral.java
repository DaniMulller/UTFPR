public class JogoGeneral{//CABO
  private Dado[] dados;
  private int[] jogadas;
  private int aux[]=new int[6];
  public JogoGeneral(){
    dados= new Dado[5];
    jogadas = new int[13];
    for(int i=0;i<13;i++)
      jogadas[i]=-1;//quando a jogada ainda não foi utilizada, guardará -1 pontos (número de controle).
  }
  public void rolarDados(){
    for(int i=0;i<5;i++)
      dados[i].roll();
  }
  public String toString(){
    return dados[0].getSideUp()+" "+dados[1].getSideUp()+" "+dados[2].getSideUp()+" "+dados[3].getSideUp()+" "+dados[4].getSideUp();
  }
  public int somaDados(){
    return dados[0].getSideUp()+dados[1].getSideUp()+dados[2].getSideUp()+dados[3].getSideUp()+dados[4].getSideUp();
  }
  public boolean validarJogada(int jogada){
    if(0<jogada&&jogada<=13)
      if(jogadas[jogada-1]==-1)
        return true;
    return false;
  }
  public String printarjogada(int i){
      if(jogadas[i-1]==-1)
        return "-";
      return "x";
  }
  public void mostrarJogadas(){
    System.out.println("1 2 3 4 5 6 7(T) 8(Q) 9(F) 10(S+) 11(S-) 12(G) 13(X)");
    System.out.print(printarjogada(1)+" "+printarjogada(2)+" "+printarjogada(3)+" "+printarjogada(4)+" "+printarjogada(5)+" "+printarjogada(6)+"  "+printarjogada(7)+"    "+printarjogada(8)+"    "+printarjogada(9)+"     "+printarjogada(10)+"      ");
    System.out.print(printarjogada(11)+"      "+printarjogada(12)+"     "+printarjogada(12));
  }
  public void pontuarJogada(int m)
  {
    int k;
    int j=0;
    switch(m)
    {
      case 1:
        k=0;
        for(Dado dado:dados)
          if(dado.getSideUp()==1)
            k++;
        jogadas[0]=k;
        break;
      case 2:
        k=0;
        for(Dado dado:dados)
          if(dado.getSideUp()==2)
            k++;
        jogadas[1]=2*k;
        break;
      case 3:
        k=0;
        for(Dado dado:dados)
          if(dado.getSideUp()==3)
            k++;
        jogadas[2]=3*k;
        break;
      case 4:
        k=0;
        for(Dado dado:dados)
          if(dado.getSideUp()==4)
            k++;
        jogadas[3]=4*k;
        break;
      case 5:
        k=0;
        for(Dado dado:dados)
          if(dado.getSideUp()==5)
            k++;
        jogadas[4]=5*k;
        break;
      case 6://Jogada de 6
        k=0;
        for(Dado dado:dados)
          if(dado.getSideUp()==6)
            k++;
        jogadas[5]=6*k;
        break;
      case 7://conferir / Trinca (T)
        k=0;
        for(int i=0;i<3;i++){
          j=0;
          while(j<5&&dados[j].getSideUp()==dados[i].getSideUp()){
            j++;
            if(j>=2){
              jogadas[6]=somaDados();
              j=5;
              i=3;
            }
          }
        }
        if(j!=5)
          jogadas[6]=0;
        break;
      case 8://Quadra(Q)
        k=0;
        for(int i=0;i<2;i++){
          j=0;
          while(j<5&&dados[j].getSideUp()==dados[i].getSideUp()){
            j++;
            if(j>=3){
              jogadas[7]=somaDados();
              j=6;
              i=3;
            }
          }
        }
        if(j!=5)
          jogadas[7]=0;
        break;
      case 9://Full house (F)
        jogadas[8]=0;
        for(int i:aux)//declarando posições como zero
          i=0;
        for(Dado dado:dados)
          aux[dado.getSideUp()-1]++;
        for(int i=0;i<5;i++){
          if(aux[i]==2){
            for(j=i+1;j<6;j++)
              if(aux[j]==3)
                jogadas[8]=25;i=10;j=10;
          }
          else if(aux[i]==3){
            for(j=i+1;j<6;j++)
              if(aux[j]==2)
                jogadas[8]=25;i=10;j=10;
          }
        }
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
        break;
      case 11://Sequência baixa (S-)

        for(int i=0;i<6;i++)
          aux[i]=0;//declarando todos os elementos como zero, pois aux é vetor CONTADOR
        for(Dado dado:dados)
          aux[dado.getSideUp()-1]++;//o indice [i-1] representam o numero de vezes que o número i aparece.
        for(int i=0;i<6;i++)
          if(aux[i]!=1&&i!=5)//o único indice que pode ser diferente de 1 é o indice 5 (número 6)
            jogadas[9]=0;
        jogadas[10]=40;
        break;
      case 12://General (G)
        jogadas[11]=0;
        if(dados[0].getSideUp()==dados[1].getSideUp()&&dados[1].getSideUp()==dados[2].getSideUp()&&dados[2].getSideUp()==dados[3].getSideUp()&&dados[3].getSideUp()==dados[4].getSideUp())
          jogadas[11]=50;
        break;
      case 13://Jogada aleatória (X)
        jogadas[12]=somaDados();
        break;
    }
  }
}

import java.util.Scanner;
public class Simulador{
  private static Veiculo[] veiculos;
  public static void main(String[] args){
    veiculos = new Veiculo[20];
    Scanner teclado = new Scanner(System.in);
    char opcao;
    int id,aux,aux2=0;
    System.out.println("-------------------- Simulador de Corrida -------------------");
    System.out.println("Opcoes:");
    System.out.println("(a) Incluir veiculo\n(b) Remover veiculo (pelo id)\n(c) Abastecer Veiculo (pelo id)\n(d) Movimentar um veiculo (pelo id)\n(e) Movimentar veiculos por tipo\n(f) Imprimir todos os dados de todos os veiculos\n(g) Imprimir dados de veiculos por tipo\n(h) Esvaziar um pneu especifico (selecionar id e pneu)\n(i) Calibrar um pneu especifico\n(j) Calibrar todos os pneus por tipo do veiculo\n(k) Imprimir pista de corrida\n(l) Sair da aplicacao");
    do{
      System.out.print("\n~ Selecione uma opcao de menu: ");
      opcao = teclado.next().charAt(0);
      switch(opcao){
        case 'A'://PRATICAMENTE PRONTA
        case 'a'://Opção 'a' do menu
          incluirVeiculo();
          break;
        case 'B'://Opção 'b' do menu
        case 'b'://PRATICAMENTE PRONTA
          removerVeiculo();
          break;
        case 'C'://PRATICAMENTE PRONTA
        case 'c'://Opção 'c' do menu
          abastecerVeiculo();
          break;
        case 'D'://EM ANDAMENTO (falta verificar se o IPVA foi pago ou n)
        case 'd'://Opção 'd' do menu
          moverVeiculo();
          break;
        case 'E'://PRATICAMENTE PRONTA (mesma coisa da d)
        case 'e'://Opção 'e' do menu
          System.out.print("- informe o tipo dos veiculos que deseja mover (b,c,m,f): ");
          opcao=teclado.next().charAt(0);
          switch(opcao){
            case 'c':
            case 'C':
              for(int i=0;i<20;i++)
                if(veiculos[i]!=null&&veiculos[i] instanceof CarroPopular)
                  veiculos[i].mover();
              break;
            case 'm':
            case 'M':
              for(int i=0;i<20;i++)
                if(veiculos[i]!=null&&veiculos[i] instanceof Motocicleta)
                  veiculos[i].mover();
              break;
            case 'f':
            case 'F':
              for(int i=0;i<20;i++)
                if(veiculos[i]!=null&&veiculos[i] instanceof Ferrari)
                  veiculos[i].mover();
              break;
            case 'b':
            case 'B':
              for(int i=0;i<20;i++)
                if(veiculos[i]!=null&&veiculos[i] instanceof Bicicleta)
                  veiculos[i].mover();
              break;
            default:
              System.out.println("[!] Erro: tipo de veiculo invalido!");
          }
          break;
        case 'F'://PRATICAMENTE PRONTA (falta calcular e exibir o IPVA, e dizer se foi pago)
        case 'f'://Opção 'f' do menu
          for(int i=0;i<20;i++)
            if(veiculos[i]!=null)
              System.out.println(veiculos[i].toString());
          break;
        case 'G'://PRATICAMENTE PRONTA (mesma coisa da g)
        case 'g'://Opção 'g' do menu
          System.out.print("- informe o tipo do veiculo que imprimir os dados (b,c,m,f): ");
          opcao=teclado.next().charAt(0);
          switch(opcao){
            case 'c':
            case 'C':
              for(int i=0;i<20;i++)
                if(veiculos[i]!=null&&veiculos[i] instanceof CarroPopular)
                  System.out.println(veiculos[i].toString());
              break;
            case 'm':
            case 'M':
              for(int i=0;i<20;i++)
                if(veiculos[i]!=null&&veiculos[i] instanceof Motocicleta)
                  System.out.println(veiculos[i].toString());
              break;
            case 'f':
            case 'F':
              for(int i=0;i<20;i++)
                if(veiculos[i]!=null&&veiculos[i] instanceof Ferrari)
                  System.out.println(veiculos[i].toString());
              break;
            case 'b':
            case 'B':
              for(int i=0;i<20;i++)
                if(veiculos[i]!=null&&veiculos[i] instanceof Bicicleta)
                  System.out.println(veiculos[i].toString());
              break;
            default:
              System.out.println("[!] Erro: tipo de veiculo invalido!");
          }
          break;
        case 'H'://PRATICAMENTE PRONTA
        case 'h'://Opção 'h' do menu (Esvaziar um pneu especifico)

          do{//repetindo a leitura ate receber um id valido (e ocupado)
            System.out.print("- informe o id do veiculo [1-20]: ");
            id = teclado.nextInt();
          }while((id>20||id<=0)||(veiculos[id-1]==null));

          aux2=4;//se for um Carro ou Ferrari, o numero de rodas é 4
          if(veiculos[id-1] instanceof Bicicleta || veiculos[id-1] instanceof Motocicleta)
            aux2=2;//caso contrario é 2

          do{//repetindo a leitura ate receber um pneu valido
            System.out.print("- informe o numero do pneu a esvaziar [1-"+aux2+"]: ");
            aux = teclado.nextInt();
          }while(aux>aux2||aux<=0);

          veiculos[id-1].esvaziarPneu(aux-1);
          System.out.println("[!] pneu esvaziado com sucesso!");
          break;
        case 'I'://PRATICAMENTE PRONTA
        case 'i'://Opção 'i' do menu (Calibrar um pneu específico)
          System.out.print("- informe o id do veiculo [1-20]: ");
          id = teclado.nextInt();
          if(id>20||id<=0){
            System.out.println("[!] Erro: id invalido!");
            return;//AQUI
          }
          if(veiculos[id-1]==null){
            System.out.println("[!] Erro: o id informado nao esta atribuido a nenhum veiculo");
            return;
          }

          aux2=4;//se for um Carro ou Ferrari, o numero de rodas é 4
          if(veiculos[id-1] instanceof Bicicleta || veiculos[id-1] instanceof Motocicleta)
            aux2=2;//caso contrario é 2

          System.out.print("- informe o numero do pneu a calibrar [1-"+aux2+"]: ");
          aux = teclado.nextInt();
          if(aux>aux2||aux<=0);
            System.out.println("[!] Erro: o pneu informado nao e valido!");
          veiculos[id-1].calibrarPneu(aux-1);
          System.out.println("pneu calibrado com sucesso!");
          break;
        case 'J'://PRATICAMENTE PRONTA
        case 'j'://Opção 'j' do menu
          System.out.println("- informe o tipo do veiculo que deseja calibrar os pneus (b,c,m,f): ");
          opcao=teclado.next().charAt(0);
          switch(opcao){
            case 'c':
            case 'C':
              for(int i=0;i<20;i++)
                if(veiculos[i]!=null&& veiculos[i] instanceof CarroPopular)
                  for(int j=0;j<4;j++)
                    veiculos[i].calibrarPneu(j);
              System.out.println("[!] pneus dos Carros calibrados com sucesso!");
              break;
            case 'm':
            case 'M':
              for(int i=0;i<20;i++)
                if(veiculos[i]!=null&& veiculos[i] instanceof Motocicleta)
                  for(int j=0;j<2;j++)
                    veiculos[i].calibrarPneu(j);
              System.out.println("[!] pneus das Motocicletas calibrados com sucesso!");
              break;
            case 'f':
            case 'F':
              for(int i=0;i<20;i++)
                if(veiculos[i]!=null&& veiculos[i] instanceof Ferrari)
                  for(int j=0;j<4;j++)
                    veiculos[i].calibrarPneu(j);
              System.out.println("[!] pneus das Ferraris calibrados com sucesso!");
              break;
            case 'b':
            case 'B':
              for(int i=0;i<20;i++)
                if(veiculos[i]!=null&& veiculos[i] instanceof Bicicleta)
                  for(int j=0;j<2;j++)
                    veiculos[i].calibrarPneu(j);
              System.out.println("[!] pneus das Bicicletas calibrados com sucesso!");
              break;
            default:
              System.out.println("[!] Erro: tipo de veiculo invalido!");
          }
          break;
        case 'K'://PRATICAMENTE PRONTA
        case 'k'://Opção 'k' do menu
          imprimirPistaCorrida();
          break;
        case 'L'://PRONTA!
        case 'l'://Opção 'l' do menu
          System.out.println("Saindo...");
          break;
        default://caso não exista a opção no menu
          System.out.println("Função inexistente, tente novamente!");
      }
    }while(opcao!='l'&&opcao!='L');
  }
  public static void incluirVeiculo(){//PRATICAMENTE PRONTA
    Scanner teclado = new Scanner(System.in);
    char c;
    System.out.print("- informe o tipo do veiculo (b, m, c ou f): ");
    c = teclado.nextLine().charAt(0);
    switch(c)
    {
      case 'b':
      case 'B':
        for(int i=0;i<20;i++){
          if(veiculos[i]==null){
            veiculos[i]= new Bicicleta(i);
            System.out.println("[!] veiculo incluido com sucesso!");
            //mostraVeiculos();
            return;
          }
        }
        System.out.println("[!] Erro: O numero maximo de veiculos ja foi atingido!");
        break;
      case 'm':
      case 'M':
        for(int i=0;i<20;i++){
          if(veiculos[i]==null){
            veiculos[i]= new Motocicleta(i);
            System.out.println("[!] veiculo incluido com sucesso!");
            //mostraVeiculos();
            return;
          }
        }
        System.out.println("[!] Erro: O numero maximo de veiculos ja foi atingido!");
        break;
      case 'c':
      case 'C':
        for(int i=0;i<20;i++){
          if(veiculos[i]==null){
            veiculos[i]= new CarroPopular(i);
            System.out.println("[!] veiculo incluido com sucesso!");
            //mostraVeiculos();
            return;
          }
        }
        System.out.println("[!] Erro: O numero maximo de veiculos ja foi atingido!");
        break;
      case 'f':
      case 'F':
        for(int i=0;i<20;i++){
          if(veiculos[i]==null){
            veiculos[i]= new Ferrari(i);
            System.out.println("[!] veiculo incluido com sucesso!");
            //mostraVeiculos();
            return;
          }
        }
        System.out.println("[!] Erro: O numero maximo de veiculos ja foi atingido!");
        break;
      default:
        System.out.println("[!] Erro: Este tipo de veiculo nao existe!");
    }
  }
  public static void removerVeiculo(){
    Scanner teclado = new Scanner(System.in);
    int idRemover;
      System.out.print("- informe o id do veiculo a ser removido [1-20]: ");
    idRemover=teclado.nextInt();
    if(idRemover>20||idRemover<=0)
      System.out.println("[!] Erro: O id informado nao esta entre [1-20]!");
    else if(veiculos[idRemover-1]==null)
      System.out.println("[!] Erro: Nao existe veiculo alocado com o id informado");
    else{
      veiculos[idRemover-1]=null;
      System.out.println("[!] o veiculo foi removido com sucesso!");
      //mostraVeiculos();
    }

  }
  public static void imprimirPistaCorrida(){
    for(int i=0;i<20;i++){
      if(veiculos[i]!=null)
        veiculos[i].desenhar();
    }
  }
  public static void abastecerVeiculo(){//PRATICAMENTE PRONTA
    Scanner teclado=new Scanner(System.in);
    System.out.print("- informe o id do veiculo que deseja-se abastecer [1-20]: ");
    int id=teclado.nextInt();
    if(id>20||id<=0){
      System.out.println("[!] Erro: o id informado nao e valido!");
      return;
    }
    else if(veiculos[id-1]==null){
      System.out.println("[!] Erro: nao ha nenhum veiculo alocado neste id!");
      return;
    }
    else if(veiculos[id-1] instanceof Bicicleta){
      System.out.println("[!] Erro: o veiculo selecionado e uma bicicleta.");
      return;
    }
    System.out.print("- informe a quantidade de combustivel a abastecer: ");
    float combustivel=teclado.nextFloat();
    if(combustivel<(float)0){
      System.out.println("[!] Erro: quantidade de combustivel nao pode ser negativa!");
      return;
    }
    ((VeiculoMotorizado)veiculos[id-1]).abastecer(combustivel);
  }
  public static void moverVeiculo(){
    Scanner teclado = new Scanner(System.in);
    int id;
    System.out.print("- informe o id do veiculo que deseja movimentar [1-20]: ");
    id = teclado.nextInt();
    if(id>20||id<=0){
      System.out.println("[!] Erro: o id informado nao e valido!");
      return;
    }
    else if(veiculos[id-1]==null){
      System.out.println("[!] Erro: nao ha nenhum veiculo alocado neste id!");
      return;
    }
    veiculos[id-1].mover();
  }
  public static void mostraVeiculos(){
    System.out.print("+ id's ocupados (inicial do tipo de veiculo)\n+ ");
    for(int i=1;i<=20;i++)
      System.out.print(i+" ");
    System.out.print("\n+ ");//Quebrando a linha

    for(int i=0;i<20;i++){
      if(veiculos[i]==null)
        System.out.print("  ");
      else{
        if(veiculos[i] instanceof Motocicleta)
          System.out.print("m ");
        else if(veiculos[i] instanceof Bicicleta)
          System.out.print("b ");
        else if(veiculos[i] instanceof CarroPopular)
          System.out.print("c ");
        else
          System.out.print("f ");
      }
      if(i>8)
        System.out.print(" ");
    }
    System.out.println("");
  }
}

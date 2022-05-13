import image.*;

import java.util.Random;

public class RandomWalk {
    public static void main (String args[]) throws Exception{

        int MAX_IT = 1700000; //quantidade maxima de iteracoes - default: 120000
        int pixels = 1024; //default: 256
        int QTD = 1; //quantidade de imagens geradas - default: 1

        long start = System.currentTimeMillis(); //inicia o cronometro
        for (int i = 0; i < QTD; i++){
            Random r = new Random(); //geracao de numeros randomicos

            Image map = new Image(pixels, pixels, 1); //instanciando uma nova imagem

            int posX = r.nextInt(pixels), posY = r.nextInt(pixels); //gerando numeros randomicos de 0 a 255

            int it = 0;
            while (it < MAX_IT) { //fazendo as iteracoes
                //verificando se o pixel saiu fora do limite da imagem, e se sim, reposicionando em outro local randomico da imagem
                while (posX < 0 || posX >= map.getWidth() || posY < 0 || posY >= map.getHeight()) {
                    posX = r.nextInt(pixels);
                    posY = r.nextInt(pixels);
                }

                //setando o pixel escolhido como branco (faz parte do movimento)
                map.setPixel(posX, posY, 255);

                //alterando o x e y;
                int randomPos = r.nextInt(4); //numero randomico de 0 ate 3
                if (randomPos == 0) {//direita
                    posX += 1;
                } else if (randomPos == 1) {//esquerda
                    posX -= 1;
                } else if (randomPos == 2) {//cima
                    posY -= 1;
                } else if (randomPos == 3) {//baixo
                    posY += 1;
                }
                it++;
            }
            //mostrando a imagem final
            map.showImage();
        }
        long elapsed = System.currentTimeMillis() - start; //finaliza o cronometro
        System.out.println("Executed in: " + elapsed + "ms"); //printa o tempo de execucao
    }
}

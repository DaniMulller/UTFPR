package compgrafica;

import image.Image;

import java.util.Random;

public class RandomWalk {

    public static void main (String args[]) throws Exception {
        int MAX_IT = 100200; //quantidade máxima de iterações

        Random r = new Random(); //geração de números randômicos

        Image image = new Image(256, 256, 1); //instanciando uma nova imagem

        int posX = r.nextInt(256), posY = r.nextInt(256); //gerando números randômicos de 0 a 255

        int it = 0;
        while(it < MAX_IT){ //fazendo as iterações

            //verificando se o pixel saiu fora do limite da imagem, e se sim, reposicionando em outro local randômico da imagem
            while (posX < 0 || posX >= image.getWidth() || posY < 0 || posY >= image.getHeight()){
                posX = r.nextInt(256);
                posY = r.nextInt(256);
            }

            //setando o pixel escolhido como branco (faz parte do movimento)
            image.setPixel(posX, posY, 255);


            //alterando o x e y;
            int randomPos = r.nextInt(4); //número randômico de 0 até 3
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
        image.showImage();

    }
}

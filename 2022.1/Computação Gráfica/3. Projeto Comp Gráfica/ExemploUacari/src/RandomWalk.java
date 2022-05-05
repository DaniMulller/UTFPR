import image.Image;

import java.util.Random;

public class RandomWalk {
    public static void main (String args[]) throws Exception{

        int MAX_IT = 100000; //quantidade m�xima de itera��es
        int pixels = 256; //recomendado: 256

        long start = System.currentTimeMillis();
        for (int i = 0; i < 1; i++){
            Random r = new Random(); //gera��o de n�meros rand�micos

            Image image = new Image(pixels, pixels, 1); //instanciando uma nova imagem

            int posX = r.nextInt(pixels), posY = r.nextInt(pixels); //gerando n�meros rand�micos de 0 a 255

            int it = 0;
            while (it < MAX_IT) { //fazendo as itera��es
                //verificando se o pixel saiu fora do limite da imagem, e se sim, reposicionando em outro local rand�mico da imagem
                while (posX < 0 || posX >= image.getWidth() || posY < 0 || posY >= image.getHeight()) {
                    posX = r.nextInt(pixels);
                    posY = r.nextInt(pixels);
                }

                //setando o pixel escolhido como branco (faz parte do movimento)
                image.setPixel(posX, posY, 255);

                //alterando o x e y;
                int randomPos = r.nextInt(4); //n�mero rand�mico de 0 at� 3
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
        }

        long elapsed = System.currentTimeMillis() - start;

        System.out.println("Executed in: " + elapsed + "ms");
        //mostrando a imagem final
        image.showImage();
    }
}

import image.*;

import java.util.Random;
import java.awt.Color;

public class RandomWalk {
    public static void main(String args[]) throws Exception {
        int MAX_IT = 2000000; //quantidade maxima de iteracoes - default: 120000
        int pixels = 1024; //default: 256
        int QTD = 1; //quantidade de imagens geradas - default: 1

        long start = System.currentTimeMillis(); //inicia o cronometro
        for (int i = 0; i < QTD; i++) {
            RandomWalkFunction(MAX_IT,pixels);
        }
        long elapsed = System.currentTimeMillis() - start; //finaliza o cronometro
        System.out.println("Executed in: " + elapsed + "ms"); //printa o tempo de execucao
    }
    static void RandomWalkFunction(double MAX_IT,int pixels) throws Exception {
        Random r = new Random(); //geracao de numeros randomicos

        Image map = new Image(pixels, pixels, 4); //instanciando uma nova imagem

        for(int i=0;i<pixels;i++){
            for(int y=0;y<pixels;y++){
                map.setPixel(i, y, dark_blue); //Pintando o Oceano
            }
        }

        int posX = r.nextInt(pixels), posY = r.nextInt(pixels); //gerando numeros randomicos de 0 a 255

        int it = 0;
        while (it < MAX_IT) { //fazendo as iteracoes
            //verificando se o pixel saiu fora do limite da imagem, e se sim, reposicionando em outro local randomico da imagem
            while (posX < 0 || posX >= map.getWidth() || posY < 0 || posY >= map.getHeight()) {
                posX = r.nextInt(pixels);
                posY = r.nextInt(pixels);
            }

            //setando o pixel escolhido como branco (faz parte do movimento)
            map.setPixel(posX, posY, dark_green);

            //alterando o x e y;
            int randomPos = r.nextInt(4); //numero randomico de 0 ate 3
            if (randomPos == 0) {//direita
                posX += 1;
            } else if (randomPos == 1) {//esquerda
                posX -= 1;
            } else if (randomPos == 2) {//cima
                posY -= 1;
            } else {//baixo
                posY += 1;
            }
            it++;
        }

        for(int i=0;i<pixels;i++){
            for(int y=0;y<pixels;y++){
                posX = i;
                posY = y;
                map.getPixel(posX,posY);
            }
        }

        erode_map(map,3); //tirando os pixels perdidos no mapa a imagem
        //dilate_map(map,10);
        //mostrando a imagem final
        map.setTitle("Map");
        map.antiAlias(); //aplicando AntiAlias "suavizando"
        map.showImage();
    }

    static Image dilate_map(Image map,int dilatation_size) throws Exception {
        Image dilate = new Image(dilatation_size, dilatation_size, 4);
        for(int i=0;i<dilatation_size;i++){
            for(int y=0;y<dilatation_size;y++){
                dilate.setPixel(i, y, dark_green);
            }
        }
        map.dilate(dilate,1,false);
        return map;
    }

    static Image erode_map(Image map,int erosion_size) throws Exception {
        Image erosion = new Image(erosion_size, erosion_size, 1);
        for(int i=0;i<erosion_size;i++){
            for(int y=0;y<erosion_size;y++){
                erosion.setPixel(i, y, Color.white);
            }
        }
        map.dilate(erosion,1,false);
        return map;
    }

    public static final Color dark_green = new Color(0, 153, 0); //grass
    public static final Color DARK_GREEN = dark_green;
    public static final Color dark_blue = new Color(0, 0, 204); //deep ocean
    public static final Color DARK_BLUE = dark_blue;
    public static final Color dark_yellow = new Color(204, 204, 0); //sand
    public static final Color DARK_YELLOW = dark_yellow;
}
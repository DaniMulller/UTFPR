import image.Image;

import java.util.Random;

public class CellularAutomata {
    public static void main(String[] args) throws Exception {
        //variaveis iniciais
        //paredes finas
        //final float NOISE_PERC = 0.4f;
        //final int STICK_THRES = 4;
        //final int NUM_IT = 15;

        //paredes medias
        //final float NOISE_PERC = 0.4f;
        //final int STICK_THRES = 4;
        //final int NUM_IT = 10;

        //paredes grossas
        //final float NOISE_PERC = 0.1f;
        //final int STICK_THRES = 3;
        //final int NUM_IT = 30;

        //testes
        final float NOISE_PERC = 0.4f;
        final int STICK_THRES = 4;
        final int NUM_IT = 12;

        final short P = 1;

        Random r = new Random(); //gerar mapa randomico com base em uma seed //Random() sem argumentos -> seed aleatoria
        Image terrainRead = new Image(512, 512, 1); //0=preto ate 255=branco (imagem de 8 bits)

        //imagem com ruido
        for (int i=P; i<terrainRead.getHeight() - P; i++){
            for (int j=P; j<terrainRead.getWidth() - P; j++){
                terrainRead.setPixel(j, i, (r.nextFloat() < NOISE_PERC) ? 255 : 0);
            }
        }
        //terrainRead.showImage(); //mostrando a imagem inicial com ruido

        //copiando a imagem com ruido e gerando um mapa aleatorio
        Image terrainWrite = terrainRead.clone();
        int it = 0;
        while (it < NUM_IT){
            terrainRead = terrainWrite.clone();

            //segundo passo
            for (int i = P; i < terrainRead.getHeight() - P; i++) {
                for (int j = P; j < terrainRead.getWidth() - P; j++) {
                        //8bits = 0 a 255
                        //contabilizar a vizinhanca
                        //cross
                        int count = (terrainRead.getPixel(j + 1, i) == 255) ? 1 : 0;
                        count += (terrainRead.getPixel(j - 1, i) == 255) ? 1 : 0;
                        count += (terrainRead.getPixel(j, i + 1) == 255) ? 1 : 0;
                        count += (terrainRead.getPixel(j, i - 1) == 255) ? 1 : 0;
                        //diagonal
                        count += (terrainRead.getPixel(j + 1, i + 1) == 255) ? 1 : 0;
                        count += (terrainRead.getPixel(j - 1, i + 1) == 255) ? 1 : 0;
                        count += (terrainRead.getPixel(j + 1, i - 1) == 255) ? 1 : 0;
                        count += (terrainRead.getPixel(j - 1, i - 1) == 255) ? 1 : 0;

                        if (count < STICK_THRES){
                            terrainWrite.setPixel(j, i, 0); //pinta de preto
                        }else{
                            terrainWrite.setPixel(j, i, 255); //pinta de branco
                        }
                }
            }
            it++;
        }
        //mostrando na tela o resultado final
        terrainRead.clone().showImage();
    }
}

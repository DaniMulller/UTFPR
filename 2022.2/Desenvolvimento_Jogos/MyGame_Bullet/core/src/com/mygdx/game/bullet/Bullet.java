package com.mygdx.game.bullet;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.Sprite;

public class Bullet extends Sprite {
    final private static String path = "bullet.png";
    private static Texture img;

    static void init(){
        if (img == null){
            img = new Texture(path);
        }
    }

    Bullet() {
        super(img);
    }


    public boolean isOutOfScreen(){
        return (this.getX() > Gdx.graphics.getWidth());
    }

}

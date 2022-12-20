package com.mygdx.game.chest;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.Sprite;

public class Chest extends Sprite {
    final private static String path = "chest.png";
    private static Texture img;
    private ChestInputProcessor chestInputProcessor;
    private String name;

    static void init(){
        if (img == null){
            img = new Texture(path);
        }
    }

    Chest(){
        super(img);
        chestInputProcessor = new ChestInputProcessor(this);
    }

    public boolean isWithin(float x, float y){
        y = Gdx.graphics.getHeight() - y;
        return (x > this.getX()) && (y > this.getY())
                && (x < this.getX() + this.getWidth())
                && (y < this.getY() + this.getHeight());
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }
}

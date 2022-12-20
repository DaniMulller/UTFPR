package com.mygdx.game.chest;

import com.badlogic.gdx.graphics.g2d.SpriteBatch;

public class ChestController {
    public static ChestController ref;
    private Chest chest1, chest2;

    public ChestController(){
        init();
    }

    public void init(){
        if (ref == null){
            ref = this;
        }
        //inicializar a textura da chest
        Chest.init();
        chest1 = new Chest();
        chest1.setName("Primeira chest");
        chest1.setPosition(220,220);
        chest2 = new Chest();
        chest2.setName("Segunda chest");
    }

    public void draw(SpriteBatch batch){
        chest1.draw(batch);
        chest2.draw(batch);
    }

}

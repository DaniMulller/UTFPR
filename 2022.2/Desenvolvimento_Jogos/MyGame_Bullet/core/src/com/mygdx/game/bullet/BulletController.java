package com.mygdx.game.bullet;

import com.badlogic.gdx.graphics.g2d.SpriteBatch;

import java.util.ArrayList;

public class BulletController {
    public static BulletController ref;
    private ArrayList<Bullet> activeBullets, deadBullets;

    public BulletController(){
        init();
    }

    public void init(){
        if (ref == null) {
            ref = this;
            Bullet.init();
            activeBullets = new ArrayList<Bullet>(100);
            deadBullets = new ArrayList<Bullet>(100);
        }
    }

    public void render(SpriteBatch batch){
        for (int k=0; k<activeBullets.size(); k++){
            activeBullets.get(k).draw(batch);
        }
        update();
    }

    public void update(){
        for (int k=0; k<activeBullets.size(); k++){
            Bullet b = activeBullets.get(k);
            b.setX(b.getX() + 1f);

            if (b.isOutOfScreen()){
                deadBullets.add(activeBullets.remove(k));
            }
        }
        System.out.println(activeBullets.size() + "," + deadBullets.size());
    }

    public Bullet newBullet(float x, float y){
        Bullet b;
        if (deadBullets.size() > 0){
            b = deadBullets.remove(0);
        }else{
            b = new Bullet();
        }
        activeBullets.add(b);
        b.setPosition(x, y);
        return b;
    }


}

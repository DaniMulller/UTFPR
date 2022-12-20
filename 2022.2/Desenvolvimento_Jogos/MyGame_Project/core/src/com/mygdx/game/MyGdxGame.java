package com.mygdx.game;

import com.badlogic.gdx.ApplicationAdapter;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.InputProcessor;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.utils.ScreenUtils;

public class MyGdxGame extends ApplicationAdapter {
	SpriteBatch batch;
	Texture img;
	MeuInputProcessor meuInput;

	@Override
	public void create () {
		batch = new SpriteBatch();
		img = new Texture("badlogic.jpg");
		meuInput = new MeuInputProcessor();
		Gdx.input.setInputProcessor(meuInput);
	}

	final float QTD_PIXELS = 1;
	float destinoX, destinoY, x, y, dX=0, dY=0, fX=1;
	@Override
	public void render () {
		ScreenUtils.clear(1, 0, 0, 1);
		batch.begin();

		if (Gdx.input.isTouched()) {
			destinoX = Gdx.input.getX();
			destinoY = Gdx.graphics.getHeight() - Gdx.input.getY();

			dX = destinoX - x;
			dY = destinoY - y;
		}

		if((int)x != (int)destinoX || (int)y != (int)destinoY){
			fX = Math.abs(dX/dY);

			x += (QTD_PIXELS*fX)*(dX/Math.abs(dX));
			y += QTD_PIXELS*(dY/Math.abs(dY));
		}

		batch.draw(img, x, y);
		batch.end();

		//System.out.println(x + "," + y);
		Gdx.graphics.setTitle(Gdx.graphics.getFramesPerSecond() + "");
	}

	@Override
	public void dispose () {
		batch.dispose();
		img.dispose();
	}
}
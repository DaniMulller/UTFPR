package com.mygdx.game;

import com.badlogic.gdx.InputMultiplexer;
import com.mygdx.game.chest.Chest;
import com.mygdx.game.chest.ChestController;
import com.badlogic.gdx.ApplicationAdapter;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.utils.ScreenUtils;
import com.mygdx.game.chest.ChestInputProcessor;

public class MyGdxGame extends ApplicationAdapter {
	SpriteBatch batch;
	ChestController chestController;
	static MyMultiplexer multiplexer;


	@Override
	public void create () {
		multiplexer = new MyMultiplexer();
		batch = new SpriteBatch();
		chestController = new ChestController();
	}

	@Override
	public void render () {
		ScreenUtils.clear(1, 0, 0, 1);
		batch.begin();

		chestController.draw(batch);
		//ChestController.ref.draw(batch);


		batch.end();

	}
	
	@Override
	public void dispose () {
		batch.dispose();
	}
}

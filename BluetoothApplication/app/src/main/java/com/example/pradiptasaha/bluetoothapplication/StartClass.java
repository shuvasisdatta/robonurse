package com.example.pradiptasaha.bluetoothapplication;

import android.content.Intent;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;

/**
 * Created by pradiptaSaha on 27-05-2016.
 */
public class StartClass  extends AppCompatActivity {
   // MediaPlayer ourSong;
    /**
     * ATTENTION: This was auto-generated to implement the App Indexing API.
     * See https://g.co/AppIndexing/AndroidStudio for more information.
     */

//    private GoogleApiClient client;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.startclass);
//        ourSong = MediaPlayer.create(StartClass.this,R.raw.ggg);
//        ourSong.start();

        Thread timer = new Thread(){
            public void run()
            {
                try {
                    sleep(4000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                finally {
                    Intent openMainActiviity=new Intent("com.example.pradiptasaha.bluetoothapplication.MENU");
                    startActivities(new Intent[]{openMainActiviity});
                }


            }

        };

        timer.start();
        // ATTENTION: This was auto-generated to implement the App Indexing API.
        // See https://g.co/AppIndexing/AndroidStudio for more information.
//        client = new GoogleApiClient.Builder(this).addApi(AppIndex.API).build();

    }


    @Override
    public void onStop() {
        super.onStop();
        //ourSong.release();
        finish();

    }
}

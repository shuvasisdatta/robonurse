package com.example.pradiptasaha.bluetoothapplication;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Set;
import java.util.UUID;

/**
 * Created by pradiptaSaha on 26-05-2016.
 */
public class Control extends Activity {

    Button tOn,tOff,Cnt, discnt,frnt;
    final UUID PORT_UUID = UUID.fromString("00001101-0000-1000-8000-00805f9b34fb");
    BluetoothDevice device;
    public BluetoothAdapter BA;
    BluetoothSocket socket;
    public Set<BluetoothDevice> pairedDevices;
    boolean gotYou,Connected,stopThread;
    OutputStream outputStream;
    InputStream inputStream;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.control);
        tOn = (Button) findViewById(R.id.onButton1);
        tOff = (Button) findViewById(R.id.off1);
        Cnt = (Button) findViewById(R.id.connectButton1);
        discnt = (Button) findViewById(R.id.disconnectButton1);
       frnt = (Button) findViewById(R.id.frontButton);
        Connected=gotYou=false;
        BA = BluetoothAdapter.getDefaultAdapter();

connect();
    }
    public void on1(View v) {
        if (!BA.isEnabled()) {
            Intent turnOn = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
            startActivityForResult(turnOn, 0);
            Toast.makeText(getApplicationContext(), "Turning on", Toast.LENGTH_LONG).show();
        }
        else
        {
            Toast.makeText(getApplicationContext(),"Already on", Toast.LENGTH_LONG).show();
        }
    }

    public void off1(View view) {

        BA.disable();
        Toast.makeText(getApplicationContext(),"Turning off" ,Toast.LENGTH_LONG).show();


    }


    public void conectBtn(View view) {
        connect();
    }
void connect()
{
    if (!BA.isEnabled()) {
        Toast.makeText(getApplicationContext(),"Blutooth off plz turn on first",Toast.LENGTH_LONG).show();
    }
    else {
        pairedDevices = BA.getBondedDevices();

        for (BluetoothDevice iterator : pairedDevices) {
            if (iterator.getName().equals("H-C-2010-06-01")) {
                Toast.makeText(getApplicationContext(), "GOT YOU", Toast.LENGTH_SHORT).show();
                gotYou = true;
                device = iterator;
                break;
            }
        }

        if (gotYou) {

            Toast.makeText(getApplicationContext(), "GOT YOU TRUE", Toast.LENGTH_SHORT).show();
            Connected = true;
            try {
                socket = device.createRfcommSocketToServiceRecord(PORT_UUID);
                socket.connect();

            } catch (IOException e) {
                Toast.makeText(getApplicationContext(), "YOU ARE NOT CONNECTED", Toast.LENGTH_SHORT).show();
                Connected = false;
            }
            if (Connected) {

                cnt();
//                    beginListenForData();
            }
        }

    }

}
    public void disconnectBtn(View view) {
        if (!stopThread) {
            stopThread = true;
            disconnect();
        }
    }

    void disconnect()
    {


            // thread.stop();
            try {
                socket.close();
            } catch (IOException e) {
                Toast.makeText(getApplicationContext(), "YOU ARE NOT CONNECTED", Toast.LENGTH_SHORT).show();
                Connected = false;
            }



    }

    public void list(View v){


    }
    void cnt()
    {
        Toast.makeText(getApplicationContext(), "YOU ARE CONNECTED", Toast.LENGTH_SHORT).show();
        try {
            outputStream=socket.getOutputStream();
        } catch (IOException e) {
            Toast.makeText(getApplicationContext(),"Cant get inp",Toast.LENGTH_SHORT).show();
            e.printStackTrace();
        }
        try {
            inputStream=socket.getInputStream();
        } catch (IOException e) {
            Toast.makeText(getApplicationContext(),"Cant get opt",Toast.LENGTH_SHORT).show();
            e.printStackTrace();
        }
    }
    public void front(View v) {


        try {
            outputStream.write('f');
        } catch (IOException e) {
            e.printStackTrace();
            Toast.makeText(getApplicationContext(),"Cant send",Toast.LENGTH_SHORT).show();
        }

    }
    public void left(View v) {


        try {
            outputStream.write('l');
        } catch (IOException e) {
            e.printStackTrace();
            Toast.makeText(getApplicationContext(),"Cant send",Toast.LENGTH_SHORT).show();
        }

    }
    public void right(View v) {


        try {
            outputStream.write('r');
        } catch (IOException e) {
            e.printStackTrace();
            Toast.makeText(getApplicationContext(),"Cant send",Toast.LENGTH_SHORT).show();
        }

    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();
        if(Connected) {
            disconnect();
        }
    }

    public void back(View v) {


        try {
            outputStream.write('b');
        } catch (IOException e) {
            e.printStackTrace();
            Toast.makeText(getApplicationContext(),"Cant send",Toast.LENGTH_SHORT).show();
        }

    }
    public void stopBot(View v) {


        try {
            outputStream.write('s');
        } catch (IOException e) {
            e.printStackTrace();
            Toast.makeText(getApplicationContext(),"Cant send",Toast.LENGTH_SHORT).show();
        }

    }
}

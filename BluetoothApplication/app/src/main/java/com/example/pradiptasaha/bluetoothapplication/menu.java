package com.example.pradiptasaha.bluetoothapplication;

import android.app.ListActivity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

import java.io.InputStream;
import java.io.OutputStream;
import java.util.Set;
import java.util.UUID;


/**
 * Created by pradiptaSaha on 25-04-2016.
 */
public class menu extends ListActivity {
    final UUID PORT_UUID = UUID.fromString("00001101-0000-1000-8000-00805f9b34fb");
    BluetoothDevice device;
    public BluetoothAdapter BA;
    BluetoothSocket socket;
    public Set<BluetoothDevice> pairedDevices;
    boolean gotYou,Connected,stopThread;
    OutputStream outputStream;
    InputStream inputStream;
    String classes[]={"ECG","Control"};
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setListAdapter(new ArrayAdapter<String>(menu.this,R.layout.support_simple_spinner_dropdown_item,classes));
        Connected=gotYou=false;
        BA = BluetoothAdapter.getDefaultAdapter();
        on();
    }
    void on()
    {

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
    void off()
    {

        BA.disable();
        Toast.makeText(getApplicationContext(),"Turning off" ,Toast.LENGTH_LONG).show();

    }
    @Override
    public void onBackPressed() {
        super.onBackPressed();
        if(BA.isEnabled()) {
            off();
        }
    }
    @Override
    protected void onListItemClick(ListView l, View v, int position, long id) {
        super.onListItemClick(l, v, position, id);
        String className=classes[position];
        try {
            Class ourClass;
            if(className=="ECG"){
                 ourClass  = Class.forName("com.example.pradiptasaha.bluetoothapplication."+"MainActivity");
            }
            else {
                 ourClass = Class.forName("com.example.pradiptasaha.bluetoothapplication." + className);
            }
            Intent ourIntent= new Intent(menu.this,ourClass);
            startActivity(ourIntent);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }

    }






}

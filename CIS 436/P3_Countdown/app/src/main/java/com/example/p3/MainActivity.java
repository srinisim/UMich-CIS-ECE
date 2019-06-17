package com.example.p3;

import android.app.Activity;
import android.app.Notification;
import android.app.NotificationManager;
import android.content.Context;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;
import android.app.PendingIntent;
import android.content.Intent;



import org.w3c.dom.Text;

import java.util.ArrayList;
import java.util.List;

import static android.R.id.list;

public class MainActivity extends Activity implements View.OnClickListener {

    private Spinner spinner;
    private String countDownTime;

    @Override
    protected void onCreate(Bundle savedInstanceState)  {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button btnSetCount = (Button)findViewById(R.id.setCountBtn);
        Button btnStartCount = (Button)findViewById(R.id.countDownBtn);

        btnSetCount.setOnClickListener(this);
        btnStartCount.setOnClickListener(this);

        spinner = (Spinner) findViewById(R.id.notifSpinner);

        spinner.setEnabled(false);

    }

    @Override
    public void onClick(View v){
        if(v.getId() == R.id.setCountBtn){
            EditText timeInput = (EditText) findViewById(R.id.inputTime);
            String time = timeInput.getText().toString();

            int timeNum = Integer.parseInt(time);

            if(timeNum > 5 && timeNum <= 120 && timeNum % 5 == 0){
                countDownTime = time;

                String[] arraySpinner;

                arraySpinner = getHighNotif(timeNum);

                // Create an ArrayAdapter using the string array and a default spinner layout
                ArrayAdapter<String> adapter = new ArrayAdapter<String>(this,
                        android.R.layout.simple_spinner_item, arraySpinner);
                // Specify the layout to use when the list of choices appears
                adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
                // Apply the adapter to the spinner
                spinner.setAdapter(adapter);

                spinner.setEnabled(true);
            }else{
                spinner.setEnabled(false);
            }
        }else if(v.getId() == R.id.countDownBtn){
            String spinnerItem = spinner.getSelectedItem().toString();

            EditText messageInput = (EditText) findViewById(R.id.messageText);
            String message = messageInput.getText().toString();

            Intent serviceIntent = new Intent(this, CountdownService.class);
            serviceIntent.putExtra("countDownTime", countDownTime);
            serviceIntent.putExtra("startNotifTime", spinnerItem);
            serviceIntent.putExtra("message", message);

            startService(serviceIntent);

        }

    }

    public String[] getHighNotif(int time){
        ArrayList<String> allValues = new ArrayList<String>();
        allValues.add("90");
        allValues.add("60");
        allValues.add("30");
        allValues.add("20");
        allValues.add("10");
        allValues.add("5");
        allValues.add("1");

        List<String> sub = new ArrayList<String>();

        int limit = allValues.size();

        for(int i = 0; i < limit; i++){
            if(time > Integer.parseInt(allValues.get(i))){
                sub = allValues.subList(i, limit);
                i = limit;
            }
        }
        return sub.toArray(new String[0]);
    }

}

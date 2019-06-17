package com.example.p3;

import android.content.Context;
import android.os.AsyncTask;
import android.widget.Toast;

import java.util.Timer;
import java.util.TimerTask;

public class CountdownTask extends AsyncTask<String, Void, String> {
    private Context mContext;
    private int timeNum;
    private int highNotif;

    public CountdownTask(Context context){
        mContext = context;
    }

    @Override
    protected String doInBackground(String... params){
        timeNum = Integer.parseInt(params[0]);
        highNotif = Integer.parseInt(params[1]);

        final Timer timer = new Timer();

        TimerTask task = new TimerTask(){
            public void run(){
                timeNum = timeNum - 1;
                if(timeNum == 1){
                    timer.cancel();
                }
                else if(timeNum <= highNotif){
                    // send notification. don't need to update uithread
                    Toast.makeText(mContext, "Time left: " + timeNum, Toast.LENGTH_LONG).show();
                }
            }
        };

        timer.schedule(task,0,1000);

        return "hello";
    }

    @Override
    protected void onPostExecute(String result){
        //update ui thread with message
        Toast.makeText(mContext, result, Toast.LENGTH_LONG).show();
    }
}

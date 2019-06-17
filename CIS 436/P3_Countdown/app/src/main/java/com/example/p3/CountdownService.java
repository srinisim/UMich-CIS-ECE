package com.example.p3;

import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.os.AsyncTask;
import android.os.IBinder;
import android.util.Log;
import android.widget.Toast;

import java.util.Timer;
import java.util.TimerTask;
import java.util.concurrent.TimeUnit;

public class CountdownService extends Service{
    private NewYearApp app;
    private Timer timer;

    private String message;

    public CountdownService() {
    }

    @Override
    public void onCreate() {
        Log.d("News reader", "Service created");
        app = (NewYearApp) getApplication();

        //startTimer();
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        Log.d("News reader", "Service started");

        String countDownTime = intent.getStringExtra("countDownTime");
        String startNotifTime = intent.getStringExtra("startNotifTime");
        message = intent.getStringExtra("message");
        new CountdownTask(getApplicationContext()).execute(countDownTime, startNotifTime);

        //stop service
        stopSelf();

        return START_STICKY;
    }


    @Override
    public IBinder onBind(Intent intent) {
        Log.d("News reader","Service bound - not used!");
        return null;

    }

    @Override
    public void onDestroy() {
        Log.d("News reader", "Service destroyed");
        //stopTimer();
    }

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
                    if(timeNum == 0){
                        sendNotification("Countdown App", "Time for: " + message);
                        timer.cancel();
                    }
                    else if(timeNum <= highNotif && containsNotif(timeNum)){
                        // send notification. don't need to update uithread
                        sendNotification("Countdown App",timeNum + " seconds left until Happy New Year");
                    }
                }
            };

            timer.schedule(task,0,1000);

            return "Countdown has been started";
        }

        public boolean containsNotif(int value){
            if(value == 1 || value == 5 ||value == 10 ||value == 20 ||value == 30 ||value == 60 ||value == 90)
                return true;
            else
                return false;
        }

        @Override
        protected void onPostExecute(String result){
            //update ui thread with message
            Toast.makeText(mContext, result, Toast.LENGTH_LONG).show();
        }


    }

    public void sendNotification(String title, String content){
        Notification.Builder mBuilder =
                new Notification.Builder(this)
                        .setSmallIcon(R.mipmap.ic_launcher)
                        .setContentTitle(title)
                        .setContentText(content);

        Intent resultIntent = new Intent(this, MainActivity.class);

        // Because clicking the notification opens a new ("special") activity, there's
        // no need to create an artificial back stack.
        PendingIntent resultPendingIntent =
                PendingIntent.getActivity(
                        this,
                        0,
                        resultIntent,
                        PendingIntent.FLAG_UPDATE_CURRENT
                );

        // Sets an ID for the notification
        int mNotificationId = 001;
        // Gets an instance of the NotificationManager service
        NotificationManager mNotifyMgr =
                (NotificationManager) getSystemService(NOTIFICATION_SERVICE);

        //add pending intent
        mBuilder.setContentIntent(resultPendingIntent);

        // Builds the notification and issues it.
        mNotifyMgr.notify(mNotificationId, mBuilder.build());
    }
}

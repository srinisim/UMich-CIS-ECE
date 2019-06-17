package com.example.p3;

import android.app.Application;
import android.content.Intent;
import android.util.Log;

public class NewYearApp extends Application{
    @Override
    public void onCreate(){
        super.onCreate();
        Log.d("New Year Countdown", "App Started");
    }
}

package com.example.p1;

public class Bank{
    private static int amount;

    public static void setAmount(int amt){
        amount = amt;
    }
    public static int getAmount(){
        return amount;
    }

    public static void add(int amt){
        amount += amt;
    }

    public static void subtract(int amt){
        amount -= amt;
    }

    public static String getStrAmount(){

        return "$" + Integer.toString(Bank.getAmount());
    }
}

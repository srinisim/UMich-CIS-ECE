package com.example.p1;

import java.util.Random;

public class SlotMachine {

    private static int Slot1;
    private static int Slot2;
    private static int Slot3;

    public static int getSlot1() {
        return Slot1;
    }

    private static void setSlot1(int slot1) {
        Slot1 = slot1;
    }

    public static int getSlot2() {
        return Slot2;
    }

    private static void setSlot2(int slot2) {
        Slot2 = slot2;
    }

    public static int getSlot3() {
        return Slot3;
    }

    private static void setSlot3(int slot3) {
        Slot3 = slot3;
    }

    public static void pullLever(){
        Random rnd = new Random();
        SlotMachine.setSlot1(rnd.nextInt(9) + 1);
        SlotMachine.setSlot2(rnd.nextInt(9) + 1);
        SlotMachine.setSlot3(rnd.nextInt(9) + 1);
    }
}

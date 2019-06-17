package com.example.p1;

//import android.support.v7.app.AppCompatActivity;
import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity implements View.OnClickListener{

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //Get Buttons for listeners
        Button btnSetValue = (Button)findViewById(R.id.btn_setVal);
        Button btnNewGame = (Button)findViewById(R.id.btnNewGame);
        Button btnRunSlot = (Button)findViewById(R.id.btnRunSlot);

        btnRunSlot.setEnabled(false);

        btnSetValue.setOnClickListener(this);
        btnNewGame.setOnClickListener(this);
        btnRunSlot.setOnClickListener(this);
    }

    @Override
    public void onClick(View v){
        if(v.getId() == R.id.btn_setVal){
            //Set Value Functionality
            try{
                EditText inputAmt = (EditText) findViewById(R.id.input_amount);
                String tempAmt = inputAmt.getText().toString();


                if( tempAmt.trim().length() == 0 ){

                }else{
                    int amt = Integer.parseInt(tempAmt);

                    if( amt < 100 || amt > 500){
                        Toast.makeText(getApplicationContext(), "Amount must be between 100 and 500, inclusive.",
                                Toast.LENGTH_SHORT).show();
                    }else{

                        Bank.setAmount(amt);

                        //update
                        TextView displayAmt = (TextView)findViewById(R.id.displayBankAmount);
                        displayAmt.setText(Bank.getStrAmount());

                        Button btnRunSlot = (Button)findViewById(R.id.btnRunSlot);
                        btnRunSlot.setEnabled(true);

                        //disable buttons and text
                        inputAmt.clearFocus();
                        inputAmt.setEnabled(false);
                        //we are in setVal button event so v should be the Set Value button
                        v.setEnabled(false);

                    }
                }
            }catch(Exception ex){

            }

        }else if(v.getId() ==R.id.btnNewGame){

            Button btnSetValue = (Button)findViewById(R.id.btn_setVal);

            btnSetValue.setEnabled(true);

            Button btnRunSlot = (Button)findViewById(R.id.btnRunSlot);
            btnRunSlot.setEnabled(false);

            EditText inputAmt = (EditText) findViewById(R.id.input_amount);
            inputAmt.setText("");
            inputAmt.setEnabled(true);

            Bank.setAmount(0);
            TextView displayAmt = (TextView)findViewById(R.id.displayBankAmount);
            displayAmt.setText(Bank.getStrAmount());

        }else if(v.getId() ==R.id.btnRunSlot){
            //Pull the lever, run the slot, watch the tears

            Boolean reset = false;
            TextView displayAmt = (TextView)findViewById(R.id.displayBankAmount);
            TextView dispSlot1 = (TextView)findViewById(R.id.slot1);
            TextView dispSlot2 = (TextView)findViewById(R.id.slot2);
            TextView dispSlot3 = (TextView)findViewById(R.id.slot3);

            Bank.subtract(5);

            //display amount after entry amount for a brief milisecond
            displayAmt.setText(Bank.getStrAmount());

            SlotMachine.pullLever();

            int slot1Val = SlotMachine.getSlot1();
            int slot2Val = SlotMachine.getSlot2();
            int slot3Val = SlotMachine.getSlot3();

            dispSlot1.setText(Integer.toString(slot1Val));
            dispSlot2.setText(Integer.toString(slot2Val));
            dispSlot3.setText(Integer.toString(slot3Val));

            //check reward. if else short circuit
            if(slot1Val == slot2Val && slot1Val == slot3Val && slot2Val == slot3Val){
                if(slot1Val == 9){
                    //all 9s, net gain 995
                    Bank.add(1000);
                }else if(slot1Val >= 5){
                    //8-5 get 100, net gain 95
                    Bank.add(100);
                }else{
                    // <5 get 40, net gain 35
                    Bank.add(40);
                }
            }else if (slot1Val == slot2Val || slot1Val == slot3Val || slot2Val == slot3Val){
                //get $10, net gain 5
                Bank.add(10);
            }else{
                //net lost $5
            }

            //display amount after reward
            displayAmt.setText(Bank.getStrAmount());

            if(Bank.getAmount() >= 1000){
                //win. new game
                Toast.makeText(getApplicationContext(), "You made at or over a $1000. You Win!",
                        Toast.LENGTH_SHORT).show();
                reset = true;
            }else if(Bank.getAmount() <= 0){
                //lose. new game

                Toast.makeText(getApplicationContext(), "You ran out of money. You lose.",
                        Toast.LENGTH_SHORT).show();

                reset = true;

            }else{
                //let the game continue
            }

            if(reset){
                //new game/reset should be a function not sure how to implement that

                Button btnSetValue = (Button)findViewById(R.id.btn_setVal);

                btnSetValue.setEnabled(true);

                //disable slot button
                v.setEnabled(false);

                EditText inputAmt = (EditText) findViewById(R.id.input_amount);
                inputAmt.setText("");
                inputAmt.setEnabled(true);

                Bank.setAmount(0);
                displayAmt.setText(Bank.getStrAmount());
            }

        }
    }
}
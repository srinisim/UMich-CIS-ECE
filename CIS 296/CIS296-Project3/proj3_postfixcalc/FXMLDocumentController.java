/*
 * @Author: Srinivas Simhan
 * @Date: 11/20/18
 * @CIS296_Project3
 */

package proj3_postfixcalc;

import java.net.URL;
import java.util.ArrayList;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;
import java.util.Stack;

public class FXMLDocumentController implements Initializable {
    @FXML
    private TextArea display;
    
    @FXML
    private Label label;
    
    @FXML
    private Button Button1;
    private Button Button2;
    private Button Button3;
    private Button Button4;
    private Button Button5;
    private Button Button6;
    private Button Button7;
    private Button Button8;
    private Button Button9;
    private Button Button0;
    private Button ButtonClear;
    private Button BtnCalc;
    private Button ButtonPlus;
    private Button ButtonSub;
    private Button ButtonMult;
    private Button ButtonDiv;
    private Button ButtonSpace;
    
    @FXML
    
    String message="";
    
    Stack<Double> list = new Stack<Double>();
    
    //Add numbers
    public void numOne(ActionEvent event){
        message = message + "1";
        display.setText(message);
    }
    
    public void numTwo(ActionEvent event){
        message = message + "2";
        display.setText(message);
    }
    
    public void numThree(ActionEvent event){
        message = message + "3";
        display.setText(message);
    }
    
    public void numFour(ActionEvent event){
        message = message + "4";
        display.setText(message);
    }
    
    public void numFive(ActionEvent event){
        message = message + "5";
        display.setText(message);
    }
    
    public void numSix(ActionEvent event){
        message = message + "6";
        display.setText(message);
    }
    
    public void numSeven(ActionEvent event){
        message = message + "7";
        display.setText(message);
    }
    
    public void numEight(ActionEvent event){
        message = message + "8";
        display.setText(message);
    }
    
    public void numNine(ActionEvent event){
        message = message + "9";
        display.setText(message);
    }
    
    public void numZero(ActionEvent event){
        message = message + "0";
        display.setText(message);
    }
    
    //Operations
    public void opPlus(ActionEvent event){
        message = message + "+";
        display.setText(message);
    }
    
    public void opSub(ActionEvent event){
        message = message + "-";
        display.setText(message);
    }
    
    public void opMult(ActionEvent event){
        message = message + "*";
        display.setText(message);
    }
    
    public void opDiv(ActionEvent event){
        message = message + "/";
        display.setText(message);
    }
    
    public void opClear(ActionEvent event){
        message = "";
        display.setText(message);
    }
    
    public void opCalculate(ActionEvent event){
       String array[]= message.split(" ");
       System.out.print(array.length);
       for(int i=0; i<array.length; i++){
           try{
                if("+".equals(array[i])){
                    double x = list.pop();
                    double y = list.pop();
                    list.push(x+y);
                }
                else if("*".equals(array[i])){
                   double x = list.pop();
                   double y = list.pop();
                   list.push(x*y);
                }
                else if("-".equals(array[i])){
                    double x = list.pop();
                    double y = list.pop();
                    list.push(y-x);
                }
                else if("/".equals(array[i])){
                    double x = list.pop();
                    double y = list.pop();
                    list.push(y/x);
                }
                else {
                    double d = Double.parseDouble(array[i]);
                    list.push(d);
                }
           }
           catch(Exception e){
               display.setText("Error in input");
           }
       }
       double d = list.pop();
       message = Double.toString(d);
       display.setText(message);
       
    }
    
    public void opSpace(ActionEvent event){
        message = message + " ";
        display.setText(message);
    }
    
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }    
}
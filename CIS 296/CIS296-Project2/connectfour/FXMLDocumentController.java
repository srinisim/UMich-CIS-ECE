/*
 * @Author: Srinivas Simhan
 * @Date: 11/12/18
 * @CIS296_Project2
 */

package connectFour;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.geometry.HPos;
import javafx.geometry.Pos;
import javafx.scene.control.Label;
import javafx.scene.control.Button;
import javafx.scene.layout.GridPane;
import javafx.scene.shape.Circle;
import javafx.scene.shape.*;
import javafx.scene.paint.Color;
import javafx.scene.control.TextArea;

public class FXMLDocumentController implements Initializable {

    @FXML
    private Label label;
    private Button Button1;
    private Button Button2;
    private Button Button3;
    private Button Button4;
    private Button Button5;
    private Button Button6;
    private Button Button7;
    @FXML
    private GridPane grid;
    @FXML
    private TextArea message;

    private String[][] board = new String[][]{
        {"empty", "empty","empty","empty","empty","empty"},
        {"empty", "empty","empty","empty","empty","empty"},
        {"empty", "empty","empty","empty","empty","empty"},
        {"empty", "empty","empty","empty","empty","empty"},
        {"empty", "empty","empty","empty","empty","empty"},
        {"empty", "empty","empty","empty","empty","empty"},
        {"empty", "empty","empty","empty","empty","empty"}
    };

    private String turn = "red";
    private boolean winner = false;


    public void swapTurn(int c, int r){
       checkWinner(c,r);
       if(winner==false){
        if(turn == "red"){
             turn = "black";
             message.setText("It's " + turn + "'s turn!");

         }
         else{
             turn = "red";
             message.setText("It's " + turn + "'s turn!");
         }
       }
    }
    
    public void checkWinner(int c, int r){
        boolean hwin = checkHori(c,r);
        boolean vwin = checkVert(c,r);
        boolean mdwin = checkDiagnolM();
        boolean cdwin = checkDiagnolC();
        if(hwin==true || vwin == true|| mdwin==true || cdwin==true){
            winner = true;
            message.setText("Congratulations, " + turn + " won!");
        }
    }
    
    public void inputChip1(ActionEvent click1){
        for(int i=5; i>-1; i--){
           if(turn=="red"){
                if(board[0][i]== "empty"){
                    Circle circle = new Circle();
                    circle.setCenterX(50.0f);
                    circle.setCenterY(50.0f);
                    circle.setRadius(25.0f);
                    circle.setFill(Color.RED);
                    grid.add(circle,0,i);
                    grid.setHalignment(circle, HPos.CENTER);
                    board[0][i]= "red";
                    swapTurn(0,i);
                    i=-1;
                }
           }
           else{
               if(board[0][i]== "empty"){
                    Circle circle = new Circle();
                    circle.setCenterX(50.0f);
                    circle.setCenterY(50.0f);
                    circle.setRadius(25.0f);
                    circle.setFill(Color.BLACK);
                    grid.add(circle,0,i);
                    grid.setHalignment(circle, HPos.CENTER);
                    board[0][i]= "black";
                    swapTurn(0,i);
                    i=-1;
                }
           }
        }
    }
    public void inputChip2(ActionEvent add){
        for(int i=5; i>-1; i--){
            if(turn=="red"){
                if(board[1][i]== "empty"){
                    Circle circle = new Circle();
                    circle.setCenterX(50.0f);
                    circle.setCenterY(50.0f);
                    circle.setRadius(25.0f);
                    circle.setFill(Color.RED);
                    grid.add(circle,1,i);
                    grid.setHalignment(circle, HPos.CENTER);
                    board[1][i]= "red";
                    swapTurn(1,i);
                    i=-1;
                }
            }
            else{
                if(board[1][i]== "empty"){
                    Circle circle = new Circle();
                    circle.setCenterX(50.0f);
                    circle.setCenterY(50.0f);
                    circle.setRadius(25.0f);
                    circle.setFill(Color.BLACK);
                    grid.add(circle,1,i);
                    grid.setHalignment(circle, HPos.CENTER);
                    board[1][i]= "black";
                    swapTurn(1,i);
                    i=-1;
                }
            }
        }
    }
    
    public void inputChip3(ActionEvent add){
        for(int i=5; i>-1; i--){
            if(turn=="red"){
                if(board[2][i]== "empty"){
                    Circle circle = new Circle();
                    circle.setCenterX(50.0f);
                    circle.setCenterY(50.0f);
                    circle.setRadius(25.0f);
                    circle.setFill(Color.RED);
                    grid.add(circle,2,i);
                    grid.setHalignment(circle, HPos.CENTER);
                    board[2][i]= "red";
                    swapTurn(2,i);
                    i=-1;
                }
            }
            else{
               if(board[2][i]== "empty"){
                    Circle circle = new Circle();
                    circle.setCenterX(50.0f);
                    circle.setCenterY(50.0f);
                    circle.setRadius(25.0f);
                    circle.setFill(Color.BLACK);
                    grid.add(circle,2,i);
                    grid.setHalignment(circle, HPos.CENTER);
                    board[2][i]= "black";
                    swapTurn(2,i);
                    i=-1;
                }
            }
        }
    }
    public void inputChip4(ActionEvent add){
        for(int i=5; i>-1; i--){
            if(turn=="red"){
                if(board[3][i]== "empty"){
                    Circle circle = new Circle();
                    circle.setCenterX(50.0f);
                    circle.setCenterY(50.0f);
                    circle.setRadius(25.0f);
                    circle.setFill(Color.RED);
                    grid.add(circle,3,i);
                    grid.setHalignment(circle, HPos.CENTER);
                    board[3][i]= "red";
                    swapTurn(3,i);
                    i=-1;
                }
            }
            else{
                if(board[3][i]== "empty"){
                    Circle circle = new Circle();
                    circle.setCenterX(50.0f);
                    circle.setCenterY(50.0f);
                    circle.setRadius(25.0f);
                    circle.setFill(Color.BLACK);
                    grid.add(circle,3,i);
                    grid.setHalignment(circle, HPos.CENTER);
                    board[3][i]= "black";
                    swapTurn(3,i);
                    i=-1;
                }
            }
        }
    }
    
    public void inputChip5(ActionEvent add){
        for(int i=5; i>-1; i--){
            if(turn=="red"){
                if(board[4][i]== "empty"){
                    Circle circle = new Circle();
                    circle.setCenterX(50.0f);
                    circle.setCenterY(50.0f);
                    circle.setRadius(25.0f);
                    circle.setFill(Color.RED);
                    grid.add(circle,4,i);
                    grid.setHalignment(circle, HPos.CENTER);
                    board[4][i]= "red";
                    swapTurn(4,i);
                    i=-1;

                }
            }
            else{
                if(board[4][i]== "empty"){
                    Circle circle = new Circle();
                    circle.setCenterX(50.0f);
                    circle.setCenterY(50.0f);
                    circle.setRadius(25.0f);
                    circle.setFill(Color.BLACK);
                    grid.add(circle,4,i);
                    grid.setHalignment(circle, HPos.CENTER);
                    board[4][i]= "black";
                    swapTurn(4,i);
                    i=-1;

                }
            }
        }
    }
    
    public void inputChip6(ActionEvent add){
        for(int i=5; i>-1; i--){
            if(turn=="red"){
                if(board[5][i]== "empty"){
                    Circle circle = new Circle();
                    circle.setCenterX(50.0f);
                    circle.setCenterY(50.0f);
                    circle.setRadius(25.0f);
                    circle.setFill(Color.RED);
                    grid.add(circle,5,i);
                    grid.setHalignment(circle, HPos.CENTER);
                    board[5][i]= "red";
                    swapTurn(5,i);
                    i=-1;
                }
            }
            else{
                if(board[5][i]== "empty"){
                    Circle circle = new Circle();
                    circle.setCenterX(50.0f);
                    circle.setCenterY(50.0f);
                    circle.setRadius(25.0f);
                    circle.setFill(Color.BLACK);
                    grid.add(circle,5,i);
                    grid.setHalignment(circle, HPos.CENTER);
                    board[5][i]= "black";
                    swapTurn(5,i);
                    i=-1;
                }
            }
        }
    }
    
    public void inputChip7(ActionEvent click1){
        //grid.add(c1,0,5);
        for(int i=5; i>-1; i--){
            if(turn=="red"){
                if(board[6][i]== "empty"){
                Circle circle = new Circle();
                circle.setCenterX(50.0f);
                    circle.setCenterY(50.0f);
                    circle.setRadius(25.0f);
                circle.setFill(Color.RED);
                grid.add(circle,6,i);
                grid.setHalignment(circle, HPos.CENTER);
                board[6][i]= "red";
                swapTurn(6,i);
                i=-1;
                }
            }
            else{
                if(board[6][i]== "empty"){
                    Circle circle = new Circle();
                    circle.setCenterX(50.0f);
                    circle.setCenterY(50.0f);
                    circle.setRadius(25.0f);
                    circle.setFill(Color.BLACK);
                    grid.add(circle,6,i);
                    grid.setHalignment(circle, HPos.CENTER);
                    board[6][i]= "black";
                    swapTurn(6,i);
                    i=-1;
                }
            }
        }
    }
    
    public boolean checkVert(int c, int r){
        boolean result = false;
            if(r==0){
                if(board[c][r]==board[c][r+1]&&board[c][r]==board[c][r+3]&&board[c][r]==board[c][r+2]){
                    result = true;
                }
            }
            if(r==1){
                if(board[c][r]==board[c][r+1]&&board[c][r]==board[c][r+3]&&board[c][r]==board[c][r+2]
                ||board[c][r]==board[c][r+1]&&board[c][r]==board[c][r-1]&&board[c][r]==board[c][r+2]){
                    result = true;
                }
            }
            if(r==2){
                if(board[c][r]==board[c][r+1]&&board[c][r]==board[c][r+3]&&board[c][r]==board[c][r+2]
                ||board[c][r]==board[c][r+1]&&board[c][r]==board[c][r-1]&&board[c][r]==board[c][r+2]
                ||board[c][r]==board[c][r-2]&&board[c][r]==board[c][r-1]&&board[c][r]==board[c][r+1]){
                    result = true;
                }
            }
            if(r==3){
                if(board[c][r]==board[c][r-1]&&board[c][r]==board[c][r-3]&&board[c][r]==board[c][r-2]
                ||board[c][r]==board[c][r+1]&&board[c][r]==board[c][r-1]&&board[c][r]==board[c][r+2]
                ||board[c][r]==board[c][r-2]&&board[c][r]==board[c][r-1]&&board[c][r]==board[c][r+1]){
                    result = true;
                }
            }
            if(r==4){
                if(board[c][r]==board[c][r-1]&&board[c][r]==board[c][r-3]&&board[c][r]==board[c][r-2]
                ||board[c][r]==board[c][r-2]&&board[c][r]==board[c][r-1]&&board[c][r]==board[c][r+1]){
                    result = true;
                }
            }
            if(r==5){
                if(board[c][r]==board[c][r-1]&&board[c][r]==board[c][r-3]&&board[c][r]==board[c][r-2]){
                    result = true;
                }
            }
        return result;
    }
    
    public boolean checkHori(int c, int r){
        boolean result = false;
            if(c==0){
                if(board[c][r] == board[c+1][r] &&board[c][r] == board[c+2][r] && board[c][r] == board[c+3][r]){
                    result = true;
                }
            }
            if(c==1){
                if((board[c][r] == board[c-1][r] && board[c][r] == board[c+1][r]&& board[c][r] == board[c+2][r])
                ||(board[c][r] == board[c+3][r] && board[c][r] == board[c+1][r]&& board[c][r] == board[c+2][r])){
                   result = true;
                }
            }
            if(c==2){
                if((board[c][r]==board[c-2][r] && board[c][r]==board[c-1][r] && board[c][r]==board[c+1][r])
                || (board[c][r]==board[c-1][r] && board[c][r]==board[c+2][r] && board[c][r]==board[c+1][r])
                || (board[c][r]==board[c+3][r] && board[c][r]==board[c+2][r] && board[c][r]==board[c+1][r])){
                    result = true;
                }
            }
            if(c==3){
                if((board[c][r]==board[c-2][r] && board[c][r]==board[c-1][r] && board[c][r]==board[c+1][r])
                ||(board[c][r]==board[c-1][r] && board[c][r]==board[c+2][r] && board[c][r]==board[c+1][r])
                ||(board[c][r]==board[c-2][r] && board[c][r]==board[c-1][r] && board[c][r]==board[c-3][r])
                ||(board[c][r]==board[c+3][r] && board[c][r]==board[c+2][r] && board[c][r]==board[c+1][r])){
                    result = true;
                }
            }
            if(c==4){
                if((board[c][r]==board[c-1][r] && board[c][r]==board[c-2][r] && board[c][r]==board[c-3][r])
                ||(board[c][r]==board[c-2][r] && board[c][r]==board[c-1][r] && board[c][r]==board[c+1][r])
                || (board[c][r]==board[c-1][r] && board[c][r]==board[c+2][r] && board[c][r]==board[c+1][r])){
                    result = true;
                }
            }
            if(c==5){
                if((board[c][r]==board[c-2][r] && board[c][r]==board[c-1][r] && board[c][r]==board[c+1][r])
                || (board[c][r]==board[c-1][r] && board[c][r]==board[c-2][r] && board[c][r]==board[c+1][r])){
                    result = true;
                }
            }
            if(c==6){
                if(board[c][r] == board[c-1][r] &&board[c][r] == board[c-2][r] && board[c][r] == board[c-3][r]){
                    result = true;
                }
            }
        return result;
    }
    
    public boolean checkDiagnolC(){
        for(int row = 0; row<board.length-3; row++){
            for(int col=3;col<board[row].length;col++){
                if(board[row][col]!= "empty" &&board[row][col]==board[row+1][col-1]&&board[row][col]==board[row+2][col-2]&&board[row][col]==board[row+3][col-3]){
                    return true;
                }
            }
        }
        return false;
    }
 
    public boolean checkDiagnolM(){
        for(int row = 0; row< board.length-3; row++){
            for(int col = 0; col < board[row].length-3; col++){
                if(board[row][col]!= "empty" && board[row][col]==board[row+1][col+1]&&board[row][col]==board[row+2][col+2]&&board[row][col]==board[row+3][col+3]){
                    return true;
                }
            }
        }
        return false;
    }
    
    @FXML

    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }
}

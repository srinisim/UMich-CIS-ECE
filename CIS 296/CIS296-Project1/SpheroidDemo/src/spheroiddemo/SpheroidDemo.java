package spheroiddemo;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.ArrayList;

public class SpheroidDemo {
    public static void main(String[] args) {
        ArrayList<Spheroid> mySpheroid = 
                new ArrayList<>();
        
        loadData(mySpheroid);
        printData(mySpheroid);
    }//end main
    
    public static void loadData(ArrayList<Spheroid> spheroids){
        Scanner infile;
        File file = new File("input.txt");
        String tempString;
        String[] components;
        
        try {
            infile = new Scanner(file);
            
            while(infile.hasNext()){
                tempString = infile.nextLine();
                components = tempString.split(" ");
                
                //create Spheroid object
                Spheroid s;
                s = new Spheroid(Double.parseDouble(components[0]), Double.parseDouble(components[1]));
                //component[0] is the Equatorial_Radius
                //component[1] is the Polar_Radius
                
                spheroids.add(s);
            }//end while
            infile.close();
        }
        catch(FileNotFoundException ex){
            System.out.println("File was not found.");
        }
    }//end loadData
    
    public static void printData(ArrayList<Spheroid> spheroids){
        for (int i = 0; i<spheroids.size();i++){
            Spheroid s = spheroids.get(i);
            
            System.out.printf("%-10s", s.getVolume());
            System.out.printf(" ");
            System.out.printf("%-10s", s.getClassification());
            System.out.println();
        }
    }
}

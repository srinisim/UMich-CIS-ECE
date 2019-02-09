package spheroiddemo;

import static java.lang.Math.*;

public class Spheroid{
    private double equatorial;
    private double polar;
    private double volume;
    private String classification;
    
    public Spheroid(double equatorial, double polar){
        this.equatorial = equatorial;
        this.polar = polar;
    }//end constuctor
    
    //get_set equatorial
    public double getEquatorial(){
        return equatorial;
    }
    public void setEquatorial(double equatorial){
        this.equatorial = equatorial;
    }
        
    //get_set polar
    public double getPolar(){
        return polar;
    }    
    public void setPolar(double polar){
        this.polar = polar;
    }
    
    //get_set volume
    public double getVolume(){
        double a = this.equatorial; // a represents Equatorial_Radius
        double c = this.polar; // c represents Polar_Radius
        
        volume = ( 4.0 / 3.0 ) * PI * pow(a,2) * c;
        volume = Math.round(volume*100.0)/100.0;
        return volume;
    }
    
    //get_set classification
    public String getClassification(){
        double a = this.equatorial;
        double c = this.polar;
        
        if (c < a){
            classification = "Oblate";
        }
        else if (c > a){
            classification = "Prolate";
        }
        else if(c == a){
            classification = "Sphere";
        }
        else{
            classification = "Existence Is Pain";
        }   
        return classification;
    }
}